#pragma once

#include "SampleGUI.h"
#include "PrimitiveBatch.h"
#include "VertexTypes.h"
#include "CommonStates.h"
#include "Effects.h"

class SampleUI
{
public:
    SampleUI();
    void Initialize();
    bool Update(float elapsedTime, const DirectX::GamePad::State &pad);
    void Render(ID3D11DeviceContext *context);
    void OnSuspending();
    void OnResuming();
    void CreateDeviceDependentResources(ID3D11DeviceContext *context, ID3D11Device *device);
    void CreateWindowSizeDependentResources(const RECT fullScreen, const D3D11_VIEWPORT &vp);

    // Xbox Live sign-in/sing-out events
    void OnUserChanged();
    void OnUserSignedOut();

    // UI Flow
    void PromptForXboxLiveSignIn();
    void ShowPlayFabAccountChoices();
    void ShowUnlinkPlayFabUI();
    void ShowFacebookAuthFailureUI();
    
    void ShowNewPlayFabAccountUI();    // Default acccount acquired via Xbox
    void ShowAccountAlreadyLinkedUI(); // Account acquired via Xbox
    void ShowSignInFlowCompleteUI();   // Account acquired via Facebook

    void ShowCreatePlayFabAccountFailureUI();
    void ShowAcquirePlayFabXboxLinkedAccountFailureUI();
    void ShowAcquirePlayFabFacebookLinkedAccountFailureUI();
    void ShowLinkPlayFabWithXboxFailureUI();

    void ShowUnlinkOption(bool show);
    bool GetShowUnlinkOption() const { return m_showUnlinkOption; }

    // Commands
    using Command = std::function<void()>;

    void SetCreateDefaultPlayFabAccountCommand(Command cmd) { m_createDefaultPlayFabAccountCommand = cmd; }
    void SetFacebookLoginCommand(Command cmd) { m_facebookLoginCommand = cmd; }
    void SetUnlinkPlayFabAccountCommand(Command cmd) { m_unlinkPlayFabAccountCommand = cmd; }
    void SetRetryLoginToPlayFabWithXboxCommand(Command cmd) { m_retryLoginToPlayFabWithXboxCommand = cmd; }

private:
    Command m_createDefaultPlayFabAccountCommand;
    Command m_facebookLoginCommand;
    Command m_unlinkPlayFabAccountCommand;
    Command m_retryLoginToPlayFabWithXboxCommand;


    // For controls and UI elements
    std::unique_ptr<ATG::UIManager>                                         m_ui;

    // For basic shape rendering
    std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>  m_drawBatch;
    std::unique_ptr<DirectX::BasicEffect>                                   m_drawEffect;
    Microsoft::WRL::ComPtr<ID3D11InputLayout>                               m_drawInputLayout;
    std::unique_ptr<DirectX::CommonStates>                                  m_states;
    bool                                                                    m_showUnlinkOption;
};