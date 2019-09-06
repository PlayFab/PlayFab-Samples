#include "pch.h"
#include "SampleUI.h"

#include "Layout.h"
#include "SimpleMath.h"
using namespace DirectX;

//extern void ExitSample();

SampleUI::SampleUI()
{
    // Set up UI using default fonts and colors
    ATG::UIConfig uiconfig;
    
    uiconfig.colorNormal = uiconfig.colorDictionary[ATG::UIConfig::WHITE];

    m_ui = std::make_unique<ATG::UIManager>(uiconfig);
}

void SampleUI::Initialize()
{
    m_ui->LoadLayout(L".\\Assets\\Layout.csv", L".\\Assets");

    // Show the HUD
    ShowUnlinkOption(false);

    // Attach button callbacks to methods
    m_ui->FindControl<ATG::Button>(UiConstants::c_xboxLiveSignInOverlay, UiConstants::c_xboxLiveSignInButton)->SetCallback(
        [this](ATG::IPanel*, ATG::IControl*)
    {
        Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(nullptr, Windows::Xbox::UI::AccountPickerOptions::None);
    });

    m_ui->FindControl<ATG::Button>(UiConstants::c_acquirePlayFabAccountChoicesOverlay, UiConstants::c_acquireChoicesFacebookButton)->SetCallback(
        [this](ATG::IPanel*, ATG::IControl*)
    {
        m_facebookLoginCommand();
    });

    m_ui->FindControl<ATG::Button>(UiConstants::c_acquirePlayFabAccountChoicesOverlay, UiConstants::c_acquireChoicesXboxLiveButton)->SetCallback(
        [this](ATG::IPanel*, ATG::IControl*)
    {
        m_createDefaultPlayFabAccountCommand();
    });

    m_ui->FindControl<ATG::Button>(UiConstants::c_signInFailureOverlay, UiConstants::c_backToAcquireAccountButton)->SetCallback(
        [this](ATG::IPanel*, ATG::IControl*)
    {
        ShowPlayFabAccountChoices();
    });

    m_ui->FindControl<ATG::Button>(UiConstants::c_signInWithXboxFailureOverlay, UiConstants::c_signInDifferentUserButton)->SetCallback(
        [this](ATG::IPanel*, ATG::IControl*)
    {
        m_retryLoginToPlayFabWithXboxCommand();
    });

    m_ui->FindControl<ATG::Button>(UiConstants::c_unlinkPlayFabAccountPopUp, UiConstants::c_unlinkPlayFabAccountButton)->SetCallback(
        [this](ATG::IPanel*, ATG::IControl*)
    {
        m_unlinkPlayFabAccountCommand();
    });
}

bool SampleUI::Update(float elapsedTime, const DirectX::GamePad::State & pad)
{
    return m_ui->Update(elapsedTime, pad);
}

void SampleUI::Render(ID3D11DeviceContext *context)
{
    // **************************************************************************************
    // **************************************************************************************

    // Draw quads to break up the UI elements
    context->OMSetBlendState(m_states->Opaque(), nullptr, 0xFFFFFFFF);
    context->OMSetDepthStencilState(m_states->DepthNone(), 0);
    context->RSSetState(m_states->CullNone());

    m_drawEffect->Apply(context);
    context->IASetInputLayout(m_drawInputLayout.Get());
    m_drawBatch->Begin();

    static DirectX::XMFLOAT4A white = { 1.f, 1.f, 1.f, 0.f };
    static DirectX::XMFLOAT4A black = { 0.f, 0.f, 0.f, 0.f };
    {
        // Account Summary Border
        static DirectX::VertexPositionColor upperLeft = { { 96.f, 192.f, -0.1f }, white };
        static DirectX::VertexPositionColor upperRight = { { 652.f, 192.f, -0.1f }, white };
        static DirectX::VertexPositionColor lowerRight = { { 652.f, 888.f, -0.1f}, white };
        static DirectX::VertexPositionColor lowerLeft = { { 96.f, 888.f, -0.1f }, white };
        m_drawBatch->DrawLine(upperLeft, upperRight);
        m_drawBatch->DrawLine(upperRight, lowerRight);
        m_drawBatch->DrawLine(lowerRight, lowerLeft);
        m_drawBatch->DrawLine(lowerLeft, upperLeft);
    }

    {
        // UI Flow Pane Rectangle
        static DirectX::VertexPositionColor upperLeft = { {684.f, 192.f,-0.1f}, black };
        static DirectX::VertexPositionColor upperRight = { {1852.f, 192.f,-0.1f}, black };
        static DirectX::VertexPositionColor lowerRight = { {1852.f, 888.f,-0.1f}, black };
        static DirectX::VertexPositionColor lowerLeft = { {684.f, 888.f,-0.1f}, black };
        m_drawBatch->DrawQuad(upperLeft, upperRight, lowerRight, lowerLeft);
    }

    {
        // UI Flow Pane Separator
        static DirectX::VertexPositionColor top = { {1268.f, 224.f, -0.1f}, white };
        static DirectX::VertexPositionColor bottom = { {1268.f, 856.f, -0.1f}, white };
        m_drawBatch->DrawLine(top, bottom);
    }

    m_drawBatch->End();

    // **************************************************************************************
    // **************************************************************************************

    // Render UI last
    m_ui->Render();
}

void SampleUI::OnSuspending()
{
}

void SampleUI::OnResuming()
{
    m_ui->Reset();
}

void SampleUI::CreateDeviceDependentResources(ID3D11DeviceContext *context, ID3D11Device *device)
{
    // Let UI create Direct3D resources.
    m_ui->RestoreDevice(context);

    // Set up drawing effect and batch
    m_states = std::make_unique<CommonStates>(device);
    m_drawEffect = std::make_unique<BasicEffect>(device);
    m_drawEffect->SetVertexColorEnabled(true);

    void const* shaderByteCode;
    size_t byteCodeLength;

    m_drawEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);

    DX::ThrowIfFailed(
        device->CreateInputLayout(VertexPositionColor::InputElements,
            VertexPositionColor::InputElementCount,
            shaderByteCode, byteCodeLength,
            m_drawInputLayout.ReleaseAndGetAddressOf()));

    m_drawBatch = std::make_unique<PrimitiveBatch<VertexPositionColor>>(context);
}

void SampleUI::CreateWindowSizeDependentResources(const RECT fullScreen, const D3D11_VIEWPORT &vp)
{
    // Let UI know the size of our rendering viewport.
    m_ui->SetWindow(fullScreen);


    // Scaled input coordinates for effect
    SimpleMath::Matrix proj = SimpleMath::Matrix::CreateOrthographicOffCenter(0.f, float(vp.Width), float(vp.Height), 0.f, 0.f, 1.f);
    m_drawEffect->SetProjection(proj);
}

void SampleUI::OnUserChanged()
{
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_xboxLiveSignInOverlay)->Close();
}

void SampleUI::OnUserSignedOut()
{
    m_ui->CloseAll();
    ShowUnlinkOption(false);
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_xboxLiveSignInOverlay)->Show();
}

void SampleUI::PromptForXboxLiveSignIn()
{
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_xboxLiveSignInOverlay)->Show();
}

void SampleUI::ShowPlayFabAccountChoices()
{
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_acquirePlayFabAccountChoicesOverlay)->Show();
}

void SampleUI::ShowUnlinkPlayFabUI()
{
    m_ui->FindPanel<ATG::Popup>(UiConstants::c_unlinkPlayFabAccountPopUp)->Show();
}

void SampleUI::ShowFacebookAuthFailureUI()
{
    m_ui->FindControl<ATG::TextLabel>(UiConstants::c_signInFailureOverlay, UiConstants::c_signInFailureMessage)->SetText(
        L"Facebook authentication failed."
    );
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInFailureOverlay)->Show();
}

void SampleUI::ShowNewPlayFabAccountUI()
{
    m_ui->FindControl<ATG::TextLabel>(UiConstants::c_signInCompleteOverlay, UiConstants::c_signInCompleteMessage)->SetText(
        L"A default PlayFab account was created and\n"
        L"linked with the current user's Xbox Live\n"
        L"account."
    );
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInCompleteOverlay)->Show();
}

void SampleUI::ShowAccountAlreadyLinkedUI()
{
    m_ui->FindControl<ATG::TextLabel>(UiConstants::c_signInCompleteOverlay, UiConstants::c_signInCompleteMessage)->SetText(
        L"The current user's Xbox Live account was\n"
        L"already linked with a PlayFab account."
    );
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInCompleteOverlay)->Show();
}

void SampleUI::ShowSignInFlowCompleteUI()
{
    m_ui->FindControl<ATG::TextLabel>(UiConstants::c_signInCompleteOverlay, UiConstants::c_signInCompleteMessage)->SetText(
        L"You have successfully acquired a PlayFab\n"
        L"account and linked it with the current user's\n"
        L"Xbox Live account.");
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInCompleteOverlay)->Show();
}

void SampleUI::ShowCreatePlayFabAccountFailureUI()
{
    m_ui->FindControl<ATG::TextLabel>(UiConstants::c_signInFailureOverlay, UiConstants::c_signInFailureMessage)->SetText(
        L"There was an error creating a default PlayFab\naccount"
    );
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInFailureOverlay)->Show();
}

void SampleUI::ShowAcquirePlayFabXboxLinkedAccountFailureUI()
{
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInWithXboxFailureOverlay)->Show();
}

void SampleUI::ShowAcquirePlayFabFacebookLinkedAccountFailureUI()
{
    m_ui->FindControl<ATG::TextLabel>(UiConstants::c_signInFailureOverlay, UiConstants::c_signInFailureMessage)->SetText(
        L"There was an error signing into PlayFab with\nFacebook"
    );
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInFailureOverlay)->Show();
}

void SampleUI::ShowLinkPlayFabWithXboxFailureUI()
{
    m_ui->FindControl<ATG::TextLabel>(UiConstants::c_signInFailureOverlay, UiConstants::c_signInFailureMessage)->SetText(
        L"Failed to link the PlayFab account with the\ncurrent Xbox Live user."
    );
    m_ui->FindPanel<ATG::Overlay>(UiConstants::c_signInFailureOverlay)->Show();
}

void SampleUI::ShowUnlinkOption(bool show)
{
    m_showUnlinkOption = show;
    if (m_showUnlinkOption)
    {
        m_ui->FindPanel<ATG::HUD>(UiConstants::c_simpleLegendHUD)->Close();
        m_ui->FindPanel<ATG::HUD>(UiConstants::c_unlinkLegendHUD)->Show();
    }
    else
    {
        m_ui->FindPanel<ATG::HUD>(UiConstants::c_unlinkLegendHUD)->Close();
        m_ui->FindPanel<ATG::HUD>(UiConstants::c_simpleLegendHUD)->Show();
    }
}

