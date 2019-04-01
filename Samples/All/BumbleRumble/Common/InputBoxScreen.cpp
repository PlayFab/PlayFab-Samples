//--------------------------------------------------------------------------------------
// InputBoxScreen.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "ScreenManager.h"
#include "InputBoxScreen.h"
#include "Game.h"
#include "PlayerState.h"

using namespace BumbleRumble;
using namespace DirectX;

InputBoxScreen::InputBoxScreen() : GameScreen()
{
    m_isPopup = true;
    m_background = Managers::Get<ContentManager>()->LoadTexture("Assets\\Textures\\blank.png");
    m_keyboardState.Reset();
}

InputBoxScreen::~InputBoxScreen()
{
}

std::string InputBoxScreen::CharacterFromKey(DirectX::Keyboard::Keys key, bool shifted)
{
    switch (key)
    {
    case Keyboard::Keys::A: return shifted ? "A" : "a";
    case Keyboard::Keys::B: return shifted ? "B" : "b";
    case Keyboard::Keys::C: return shifted ? "C" : "c";
    case Keyboard::Keys::D: return shifted ? "D" : "d";
    case Keyboard::Keys::E: return shifted ? "E" : "e";
    case Keyboard::Keys::F: return shifted ? "F" : "f";
    case Keyboard::Keys::G: return shifted ? "G" : "g";
    case Keyboard::Keys::H: return shifted ? "H" : "h";
    case Keyboard::Keys::I: return shifted ? "I" : "i";
    case Keyboard::Keys::J: return shifted ? "J" : "j";
    case Keyboard::Keys::K: return shifted ? "K" : "k";
    case Keyboard::Keys::L: return shifted ? "L" : "l";
    case Keyboard::Keys::M: return shifted ? "M" : "m";
    case Keyboard::Keys::N: return shifted ? "N" : "n";
    case Keyboard::Keys::O: return shifted ? "O" : "o";
    case Keyboard::Keys::P: return shifted ? "P" : "p";
    case Keyboard::Keys::Q: return shifted ? "Q" : "q";
    case Keyboard::Keys::R: return shifted ? "R" : "r";
    case Keyboard::Keys::S: return shifted ? "S" : "s";
    case Keyboard::Keys::T: return shifted ? "T" : "t";
    case Keyboard::Keys::U: return shifted ? "U" : "u";
    case Keyboard::Keys::V: return shifted ? "V" : "v";
    case Keyboard::Keys::W: return shifted ? "W" : "w";
    case Keyboard::Keys::X: return shifted ? "X" : "x";
    case Keyboard::Keys::Y: return shifted ? "Y" : "y";
    case Keyboard::Keys::Z: return shifted ? "Z" : "z";
    case Keyboard::Keys::D0: return shifted ? ")" : "0";
    case Keyboard::Keys::D1: return shifted ? "!" : "1";
    case Keyboard::Keys::D2: return shifted ? "@" : "2";
    case Keyboard::Keys::D3: return shifted ? "#" : "3";
    case Keyboard::Keys::D4: return shifted ? "$" : "4";
    case Keyboard::Keys::D5: return shifted ? "%" : "5";
    case Keyboard::Keys::D6: return shifted ? "^" : "6";
    case Keyboard::Keys::D7: return shifted ? "&" : "7";
    case Keyboard::Keys::D8: return shifted ? "*" : "8";
    case Keyboard::Keys::D9: return shifted ? "(" : "9";
    case Keyboard::Keys::OemCloseBrackets: return shifted ? "}" : "]";
    case Keyboard::Keys::OemOpenBrackets: return shifted ? "{" : "[";
    case Keyboard::Keys::OemSemicolon: return shifted ? ":" : ";";
    case Keyboard::Keys::OemQuestion: return shifted ? "?" : "/";
    case Keyboard::Keys::OemPeriod: return shifted ? ">" : ".";
    case Keyboard::Keys::OemComma: return shifted ? "<" : ",";
    case Keyboard::Keys::OemPipe: return shifted ? "|" : "\"";
    case Keyboard::Keys::OemPlus: return shifted ? "+" : "=";
    case Keyboard::Keys::OemMinus: return shifted ? "_" : "-";
    }
    return "";
}

void InputBoxScreen::HandleInput()
{
    auto inputManager = Managers::Get<InputManager>();
    auto keyboardState = inputManager->CurrentKeyboardState();

    m_keyboardState.Update(keyboardState);

    auto shifted = keyboardState.IsKeyDown(Keyboard::Keys::LeftShift) || keyboardState.IsKeyDown(Keyboard::Keys::RightShift);

    for (auto k = 0; k <= 255; k++)
    {
        if (m_keyboardState.pressed.IsKeyDown((Keyboard::Keys)(k)))
        {
            m_inputString += CharacterFromKey((Keyboard::Keys)(k), shifted);
        }
    }

    if (m_keyboardState.pressed.Space)
    {
        m_inputString += " ";
    }

    if (m_keyboardState.pressed.Enter)
    {
        Managers::Get<NetworkManager>()->SendTextAsVoice(m_inputString);
        ExitScreen();
    }

    if (m_keyboardState.pressed.Back)
    {
        if (m_inputString.size() > 0)
        {
            m_inputString.erase(m_inputString.end() - 1);
        }
    }

    if (m_keyboardState.pressed.Escape)
    {
        ExitScreen();
    }
}

void InputBoxScreen::Draw(float totalTime, float elapsedTime)
{
    auto renderManager = Managers::Get<RenderManager>();
    auto renderContext = renderManager->GetRenderContext(BlendMode::NonPremultiplied);
    auto spriteFont = Managers::Get<ContentManager>()->LoadFont("Assets\\Fonts\\SegoeUI_64.spritefont");
    auto viewportWidth = static_cast<float>(renderManager->GetOutputSize().right);
    float viewportHeight = static_cast<float>(renderManager->GetOutputSize().bottom);
    float scale = 0.5f * GetScaleMultiplierForViewport(viewportWidth, viewportHeight);

    // calculate position and size of input box
    XMFLOAT2 msgPosition = XMFLOAT2(0, viewportHeight / 2.0f);
    XMVECTORF32 msgColor = Colors::Yellow;
    XMFLOAT2 origin = XMFLOAT2(0, spriteFont->GetLineSpacing() / 2.0f);
    XMVECTOR size = spriteFont->MeasureString(m_inputString.c_str());
    msgPosition.x = viewportWidth / 2.0f - XMVectorGetX(size) / 2.0f * scale;

    long rectangleWidth = long(std::min(std::max((XMVectorGetX(size) * scale) + 100.0f, 900.0f), viewportWidth));
    long rectangleHeight = long(spriteFont->GetLineSpacing() * scale * 3.0f);
    long rectangleLeft = long(viewportWidth / 2.0f) - (rectangleWidth / 2);
    long rectangleTop = long(msgPosition.y + spriteFont->GetLineSpacing() * scale) - (rectangleHeight);
    RECT backgroundRectangle = { rectangleLeft, rectangleTop, rectangleLeft + rectangleWidth, rectangleTop + rectangleHeight };

    renderContext->Begin();

    // draw a background color for the rectangle
    XMVECTOR bgColor = Colors::DarkSlateGray;
    bgColor = XMVectorSetW(bgColor, 0.8f);
    renderContext->Draw(m_background, backgroundRectangle, bgColor);

    // draw message in the middle of the screen
    renderContext->DrawString(spriteFont, m_inputString, msgPosition, msgColor, 0, origin, scale);

    // draw help text
    auto helpText = "Type text for Speech-To-Text and press Enter";
    msgColor = Colors::White;
    size = spriteFont->MeasureString(helpText);
    msgPosition.x = viewportWidth / 2.0f - XMVectorGetX(size) / 2.0f * scale;
    msgPosition.y -= XMVectorGetY(size) * 1.5f * scale;

    renderContext->DrawString(spriteFont, helpText, msgPosition, msgColor, 0, origin, scale);

    renderContext->End();

    GameScreen::Draw(totalTime, elapsedTime);
}