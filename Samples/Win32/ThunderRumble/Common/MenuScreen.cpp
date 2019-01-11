//--------------------------------------------------------------------------------------
// MenuScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "Managers.h"
#include "ScreenManager.h"
#include "MenuScreen.h"
#include "InputManager.h"
#include "Game.h"
#include <playfab\PlayFabMultiplayerDataModels.h>

using namespace ThunderRumble;
using namespace DirectX;
using namespace PlayFab::MultiplayerModels;

//
// MenuEntry
//
MenuEntry::MenuEntry(std::wstring label, MenuEntrySelectFn onSelect, MenuEntryAdjustFn onAdjust, std::wstring initialValue) :
    OnAdjust(onAdjust),
    OnSelect(onSelect),
    m_active(true),
    m_hasValue(onAdjust != nullptr),
    m_label(label),
    m_value(initialValue)
{
}

MenuEntry::~MenuEntry()
{
}

//
// MenuScreen
//
MenuScreen::MenuScreen() : GameScreen(),
m_animateSelected(true),
m_menuBounds(XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f)),
m_menuOffset(SimpleMath::Vector2(0, 0)),
m_menuTextScale(0.5f),
m_showCurrentUser(true),
m_selectedEntry(0),
m_transitionOnMultiplier(1),
m_transitionOffMultiplier(1)
{
    SetCenterJustified(true);
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::HandleInput()
{
    auto input = Managers::Get<InputManager>();

    if (input->IsMenuUp())
    {
        // size_t doesn't go negative; it rolls over
        m_selectedEntry--;
        if (m_selectedEntry >= m_menuEntries.size())
            m_selectedEntry = m_menuEntries.size() - 1;

        Managers::Get<AudioManager>()->PlaySound(L"menu_scroll");
    }
    else if (input->IsMenuDown())
    {
        m_selectedEntry++;
        if (m_selectedEntry >= m_menuEntries.size())
            m_selectedEntry = 0;

        Managers::Get<AudioManager>()->PlaySound(L"menu_scroll");
    }
    else if (input->IsMenuSelect())
    {
        if (m_selectedEntry < m_menuEntries.size()
            && m_menuEntries[m_selectedEntry].OnSelect != nullptr
            && m_menuEntries[m_selectedEntry].m_active)
        {
            Managers::Get<AudioManager>()->PlaySound(L"menu_select");
            m_menuEntries[m_selectedEntry].OnSelect();
        }
    }
    else if (input->IsMenuLeft())
    {
        if (m_selectedEntry < m_menuEntries.size()
            && m_menuEntries[m_selectedEntry].OnAdjust != nullptr
            && m_menuEntries[m_selectedEntry].m_active)
        {
            Managers::Get<AudioManager>()->PlaySound(L"menu_scroll");
            m_menuEntries[m_selectedEntry].OnAdjust(true);
        }
    }
    else if (input->IsMenuRight())
    {
        if (m_selectedEntry < m_menuEntries.size()
            && m_menuEntries[m_selectedEntry].OnAdjust != nullptr
            && m_menuEntries[m_selectedEntry].m_active)
        {
            Managers::Get<AudioManager>()->PlaySound(L"menu_scroll");
            m_menuEntries[m_selectedEntry].OnAdjust(false);
        }
    }
    else if (input->IsMenuCancel())
    {
        OnCancel();
    }

    GameScreen::HandleInput();
}

void MenuScreen::LoadContent()
{
}

void MenuScreen::Draw(float totalTime, float elapsedTime)
{
    UNREFERENCED_PARAMETER(elapsedTime);

    float viewportWidth = static_cast<float>(TheGame->GetWindowWidth());
    float viewportHeight = static_cast<float>(TheGame->GetWindowHeight());

    SimpleMath::Vector2 position = ComputeDrawStartPosition(viewportWidth, viewportHeight);
    float menuTextScale = m_menuTextScale * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    // Make the menu slide into place during transitions, using a
    // power curve to make things look more interesting (this makes
    // the movement slow down as it nears the end).
    float transitionOffset = pow(TransitionPosition(), 2);

    if (State() == ScreenStateType::TransitionOn)
        position.y += transitionOffset * (256 * m_transitionOnMultiplier);
    else
        position.y += transitionOffset * (512 * m_transitionOffMultiplier);

    // Draw each menu entry in turn.
    auto renderContext = Managers::Get<RenderManager>()->GetRenderContext(BlendMode::NonPremultiplied);
    auto font = Managers::Get<ContentManager>()->LoadFont(L"Assets\\Fonts\\SegoeUI_64.spritefont");

    renderContext->Begin();

    // Advance starting position halfway down the height of the first line, since this is where the draw origin is.
    position.y += font->GetLineSpacing() / 2.0f * menuTextScale;

    for (size_t i = 0; i < m_menuEntries.size(); i++)
    {
        if (m_menuEntries[i].m_label.empty())
            continue;

        XMVECTORF32 color = m_menuEntries[i].m_active ? Colors::White : Colors::Gray;
        float adjustedScale = menuTextScale;

        if (IsActive() && (i == m_selectedEntry))
        {
            // The selected entry is orange (or gray), and has an animating size (if enabled).
            if (m_menuEntries[i].m_active)
            {
                color = Colors::Orange;

                if (m_animateSelected)
                {
                    float pulsate = sin(totalTime * 6.0f) + 1.0f;
                    adjustedScale += pulsate * 0.05f;
                }
            }
            else
            {
                color = Colors::DarkGray;
            }
        }

        // Modify the alpha to fade text out during transitions.
        color.f[3] = TransitionAlpha();

        // Draw text, centered on the middle of each line.
        std::wstring menuLabel = m_menuEntries[i].m_label;
        if (m_menuEntries[i].m_hasValue)
        {
            menuLabel.append(L" ");
            menuLabel += m_menuEntries[i].m_value;
        }
        XMVECTOR size = font->MeasureString(menuLabel.data());
        SimpleMath::Vector2 origin = SimpleMath::Vector2(m_drawCentered ? XMVectorGetX(size) / 2.0f : 0, font->GetLineSpacing() / 2.0f);
        renderContext->DrawString(font, menuLabel.data(), position, color, 0, origin, adjustedScale);

        position.y += font->GetLineSpacing() * menuTextScale;
    }

    // Draw current user at bottom right.
    auto scale = GetScaleMultiplierForViewport(viewportWidth, viewportHeight);
    auto displayName = Managers::Get<GameStateManager>()->GetLocalPlayerName();
    auto userNameWidth = XMVectorGetX(font->MeasureString(displayName.c_str()));
    position = SimpleMath::Vector2(viewportWidth - 100 * scale, viewportHeight - 100 * scale);
    auto origin = SimpleMath::Vector2(userNameWidth, font->GetLineSpacing() / 2.0f);

    renderContext->DrawString(
        font,
        displayName.c_str(),
        position,
        Colors::White,
        0,
        origin,
        scale * 0.35f
    );

    // Draw current region on bottom left
    if (Managers::Get<GameServiceManager>()->HasDeterminedPreferredRegion())
    {
        // TODO: Replace this with GetRegionName or similar (requested from PF team)
        AzureRegion preferredRegion = Managers::Get<GameServiceManager>()->GetPreferredRegion();
        Json::Value regionNameJson;
        ToJsonEnum(preferredRegion, regionNameJson);
        const char* szRegionName = regionNameJson.asCString();

        if (szRegionName != nullptr)
        {
            wchar_t wcharRegion[32] = { 0 };
            MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szRegionName, (int)strlen(szRegionName), wcharRegion, MAX_PATH);
            auto regionWidth = XMVectorGetX(font->MeasureString(wcharRegion));
            origin = SimpleMath::Vector2(regionWidth, font->GetLineSpacing() / 2.0f);
            position = SimpleMath::Vector2(viewportWidth - 100 * scale, viewportHeight - 150 * scale);

            renderContext->DrawString(
                font,
                wcharRegion,
                position,
                Colors::White,
                0,
                origin,
                scale * 0.35f
            );
        }
    }


    //    auto currentUser = Game->GetCurrentUser();
    //
    //#ifdef _XBOX_ONE
    //    if (currentUser && currentUser->IsSignedIn && m_showCurrentUser)
    //#else
    //    if (currentUser && currentUser->is_signed_in() && m_showCurrentUser)
    //#endif
    //    {
    //        auto displayName = FormatUserName(currentUser, false, true);
    //        position = SimpleMath::Vector2((m_menuBounds.Left + m_menuBounds.Width * 0.95f), m_menuBounds.Top + m_menuBounds.Height * 0.85f);
    //        float userNameWidth = XMVectorGetX(font->MeasureString(displayName.c_str()));
    //        SimpleMath::Vector2 origin = SimpleMath::Vector2(userNameWidth, font->GetLineSpacing() / 2.0f);
    //        font->DrawString(spriteBatch.get(), displayName.c_str(), position, Colors::White, 0, origin, menuTextScale);
    //
    //#ifdef _XBOX_ONE
    //        auto pic = Managers::Get()->Content->GetImage(currentUser->XboxUserId->Data());
    //#else
    //        auto pic = Managers::Get()->Content->GetImage(currentUser->xbox_user_id().c_str());
    //#endif
    //        if (!pic)
    //        {
    //            pic = Managers::Get()->Content->GetImage(L"DefaultGamerPic");
    //        }
    //
    //        origin = SimpleMath::Vector2(63.0f, 32.0f);
    //        position = SimpleMath::Vector2((m_menuBounds.Left + m_menuBounds.Width * 0.775f), m_menuBounds.Top + m_menuBounds.Height * 0.85f);
    //
    //        if (pic)
    //        {
    //            spriteBatch->Draw(pic, position, nullptr, Colors::White, 0, origin, menuTextScale + 0.5f);
    //        }
    //    }

    renderContext->End();
}

void MenuScreen::ComputeMenuBounds(float viewportWidth, float viewportHeight)
{
    m_menuBounds = XMFLOAT4(0, viewportHeight * 0.55f, viewportWidth, viewportHeight * 0.45f);
}

void MenuScreen::ConfigureAsPopUpMenu()
{
    m_isPopup = true;
    SetCenterJustified(false);
    m_animateSelected = false;
    m_showCurrentUser = false;
}

SimpleMath::Vector2 MenuScreen::ComputeDrawStartPosition(float viewportWidth, float viewportHeight)
{
    ComputeMenuBounds(viewportWidth, viewportHeight);

    if (m_drawCentered)
    {
        return SimpleMath::Vector2(m_menuOffset.x + m_menuBounds.z / 2.0f, m_menuOffset.y + m_menuBounds.y);
    }
    else
    {
        return SimpleMath::Vector2(m_menuOffset.x + m_menuBounds.x, m_menuOffset.y + m_menuBounds.y);
    }
}
