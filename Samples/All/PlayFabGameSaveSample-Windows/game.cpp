// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "Game.h"
#include "GameSaveIntegration.h"
#include "GameSaveIntegrationUI.h"

// Global game state instance
GameState g_gameState;

// Global function to add log messages
void AddLog(const std::string& message)
{
    g_gameState.logMessages.push_back(message);
    
    // Keep only the last 20 messages to prevent memory issues
    if (g_gameState.logMessages.size() > 20)
    {
        g_gameState.logMessages.erase(g_gameState.logMessages.begin());
    }
}

// Overloaded AddLog function with printf-style formatting
void AddLog(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    
    // Get the required buffer size
    int size = vsnprintf(nullptr, 0, format, args);
    va_end(args);
    
    if (size > 0)
    {
        // Create buffer and format the string
        std::vector<char> buffer(size + 1);
        va_start(args, format);
        vsnprintf(buffer.data(), buffer.size(), format, args);
        va_end(args);
        
        // Add the formatted message
        AddLog(std::string(buffer.data()));
    }
}

static bool g_verboseLogs = true;

void MyDebugTrace(
    _In_z_ const char* /*areaName*/,
    _In_ HCTraceLevel /*level*/,
    _In_ uint64_t /*threadId*/,
    _In_ uint64_t /*timestamp*/,
    _In_z_ const char* message)
{
    if (!message)
    {
        return;
    }
    
    if (g_verboseLogs)
    {
        // Mirror to debugger
        OutputDebugStringA(message);
        OutputDebugStringA("\n");
    }
}

class SimpleGame
{
private:
    SDL_Window* m_window{ nullptr };
    SDL_GLContext m_glContext;
    bool m_running{ true };
    ImFont* m_font{ nullptr };
    SDL_GameController* m_gameController{ nullptr };
    bool m_controllerConnected{ false };
    
public:
    SimpleGame();
    ~SimpleGame();
    bool Initialize();
    void InitializeController();
    void UpdateControllerInput();
    void HandleEvents();
    void Update();
    void Render();
    void Run();
    void Cleanup();
    bool IsRunning() const;
};

SimpleGame::SimpleGame()
{
    AddLog("Game initialized successfully!");
}

SimpleGame::~SimpleGame()
{
    Cleanup();
}

bool SimpleGame::Initialize()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    m_window = SDL_CreateWindow("PFGameSaves Sample (SDL2 + Dear ImGui)",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 850, window_flags);

    if (!m_window)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_glContext = SDL_GL_CreateContext(m_window);
    SDL_GL_MakeCurrent(m_window, m_glContext);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable gamepad navigation

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(m_window, m_glContext);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load a larger font for better visibility
    m_font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\arial.ttf", 16.0f);
    if (!m_font)
    {
        // Fallback to default font if Arial is not available
        m_font = io.Fonts->AddFontDefault();
    }

    // Initialize game controller
    InitializeController();

    // Initialize game save integration
    HRESULT hr = GameSaveIntegration::Initialize();
    if (FAILED(hr))
    {
        AddLog("GameSaveIntegration::Initialize() failed (HRESULT: 0x%08X)", hr);
    }
    else
    {
        AddLog("GameSaveIntegration::Initialize() succeeded");
    }

    return true;
}

void SimpleGame::InitializeController()
{
    // Check for available game controllers
    int numJoysticks = SDL_NumJoysticks();

    for (int i = 0; i < numJoysticks; ++i)
    {
        if (SDL_IsGameController(i))
        {
            m_gameController = SDL_GameControllerOpen(i);
            if (m_gameController)
            {
                m_controllerConnected = true;
                const char* name = SDL_GameControllerName(m_gameController);
                AddLog("Controller connected: " + std::string(name ? name : "Unknown"));
                break;
            }
        }
    }

    if (!m_controllerConnected)
    {
        AddLog("No Xbox controller detected. You can still use keyboard/mouse.");
    }
}

void SimpleGame::UpdateControllerInput()
{
    if (!m_controllerConnected || !m_gameController)
    {
        return;
    }

    ImGuiIO& io = ImGui::GetIO();

    // Map controller inputs to ImGui navigation
    // D-pad navigation
    io.NavInputs[ImGuiNavInput_DpadLeft] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_DPAD_LEFT) ? 1.0f : 0.0f;
    io.NavInputs[ImGuiNavInput_DpadRight] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) ? 1.0f : 0.0f;
    io.NavInputs[ImGuiNavInput_DpadUp] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_DPAD_UP) ? 1.0f : 0.0f;
    io.NavInputs[ImGuiNavInput_DpadDown] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_DPAD_DOWN) ? 1.0f : 0.0f;

    // Left stick navigation
    float leftStickX = SDL_GameControllerGetAxis(m_gameController, SDL_CONTROLLER_AXIS_LEFTX) / 32767.0f;
    float leftStickY = SDL_GameControllerGetAxis(m_gameController, SDL_CONTROLLER_AXIS_LEFTY) / 32767.0f;

    // Apply deadzone
    const float deadzone = 0.15f;
    if (abs(leftStickX) > deadzone)
    {
        io.NavInputs[leftStickX > 0 ? ImGuiNavInput_DpadRight : ImGuiNavInput_DpadLeft] = abs(leftStickX);
    }
    if (abs(leftStickY) > deadzone)
    {
        io.NavInputs[leftStickY > 0 ? ImGuiNavInput_DpadDown : ImGuiNavInput_DpadUp] = abs(leftStickY);
    }

    // Face buttons
    io.NavInputs[ImGuiNavInput_Activate] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_A) ? 1.0f : 0.0f;  // A button
    io.NavInputs[ImGuiNavInput_Cancel] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_B) ? 1.0f : 0.0f;    // B button
    io.NavInputs[ImGuiNavInput_Menu] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_X) ? 1.0f : 0.0f;      // X button
    io.NavInputs[ImGuiNavInput_Input] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_Y) ? 1.0f : 0.0f;     // Y button

    // Shoulder buttons for scrolling
    io.NavInputs[ImGuiNavInput_FocusPrev] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_LEFTSHOULDER) ? 1.0f : 0.0f;
    io.NavInputs[ImGuiNavInput_FocusNext] = SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) ? 1.0f : 0.0f;

    // Start/Back buttons
    if (SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_START))
    {
        // Start button could open a menu or perform some action
    }
    if (SDL_GameControllerGetButton(m_gameController, SDL_CONTROLLER_BUTTON_BACK))
    {
        // Back button could go back or cancel
    }
}

void SimpleGame::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);

        if (event.type == SDL_QUIT)
        {
            m_running = false;
            PostQuitMessage(0);
        }

        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE)
        {
            m_running = false;
            PostQuitMessage(0);
        }

        // Handle controller connection/disconnection
        if (event.type == SDL_CONTROLLERDEVICEADDED)
        {
            if (!m_controllerConnected)
            {
                m_gameController = SDL_GameControllerOpen(event.cdevice.which);
                if (m_gameController)
                {
                    m_controllerConnected = true;
                    const char* name = SDL_GameControllerName(m_gameController);
                    AddLog("Controller connected: " + std::string(name ? name : "Unknown"));
                }
            }
        }
        else if (event.type == SDL_CONTROLLERDEVICEREMOVED)
        {
            if (m_gameController && event.cdevice.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(m_gameController)))
            {
                SDL_GameControllerClose(m_gameController);
                m_gameController = nullptr;
                m_controllerConnected = false;
                AddLog("Controller disconnected");
            }
        }
    }

    // Update controller input for ImGui navigation
    UpdateControllerInput();
}

void SimpleGame::Update()
{
    if (g_gameState.steamAvailable)
    {
        // Run Steam client callbacks
        SteamAPI_RunCallbacks();
    }

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Create main window
    ImGui::SetNextWindowPos(ImVec2(30, 30), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(1000, 700), ImGuiCond_FirstUseEver);

    if (ImGui::Begin("Control Panel"))
    {
        // Game Save Integration buttons
        ImGui::Text("Game Save Operations:");
        
        // Disable sign-in buttons if user is already signed in
        ImGui::BeginDisabled(g_gameState.userSignedIn || !g_gameState.steamAvailable);
        if (ImGui::Button("Sign In (Steam)", ImVec2(150, 30)))
        {
            HRESULT hr = GameSaveIntegration::SignInViaSteam();
            if (FAILED(hr))
            {
                AddLog("GameSaveIntegration::SignInViaSteam() failed (HRESULT: 0x%08X)", hr);
            }
            else
            {
                g_gameState.userSignedIn = true;
                AddLog("GameSaveIntegration::SignInViaSteam() succeeded");
            }
        }
        ImGui::EndDisabled();

        ImGui::SameLine();

        ImGui::BeginDisabled(g_gameState.userSignedIn);
        if (ImGui::Button("Sign In (Xbox)", ImVec2(150, 30)))
        {
            HRESULT hr = GameSaveIntegration::SignInViaXbox();
            if (FAILED(hr))
            {
                AddLog("GameSaveIntegration::SignInViaXbox() failed (HRESULT: 0x%08X)", hr);
            }
            else
            {
                AddLog("GameSaveIntegration::SignInViaXbox() succeeded");
            }
        }
        ImGui::EndDisabled();

        ImGui::SameLine();

        // Only enable Xbox sign-out if we're on Steam Deck and signed in via Xbox
        ImGui::BeginDisabled(!g_gameState.isSteamDeck || !g_gameState.userSignedInViaXbox);
        if (ImGui::Button("Sign Out (Xbox) Steam Deck only", ImVec2(250, 30)))
        {
            HRESULT hr = GameSaveIntegration::SignOutViaXbox();
            if (FAILED(hr))
            {
                AddLog("GameSaveIntegration::SignOutViaXbox() failed (HRESULT: 0x%08X)", hr);
            }
            else
            {
                g_gameState.userSignedIn = false;
                AddLog("GameSaveIntegration::SignOutViaXbox() succeeded");
            }
        }
        ImGui::EndDisabled();

        
        // PlayFab Game Save setup buttons
        ImGui::BeginDisabled(!g_gameState.userSignedIn || g_gameState.userAddedToGameSavePending || g_gameState.userAddedToGameSave);
        if (ImGui::Button("Add User to PF Game Save", ImVec2(200, 30)))
        {
            HRESULT hr = GameSaveIntegration::AddUserToPFGameSave();
            if (FAILED(hr))
            {
                AddLog("GameSaveIntegration::AddUserToPFGameSave() failed (HRESULT: 0x%08X)", hr);
            }
            else
            {
                AddLog("GameSaveIntegration::AddUserToPFGameSave() succeeded");
            }
        }
        ImGui::EndDisabled();

        ImGui::SameLine();

        ImGui::BeginDisabled(!g_gameState.userAddedToGameSave);
        if (ImGui::Button("Cleanup PF Game Save", ImVec2(200, 30)))
        {
            HRESULT hr = GameSaveIntegration::CleanupPFGameSave();
            if (FAILED(hr))
            {
                AddLog("GameSaveIntegration::CleanupPFGameSave() failed (HRESULT: 0x%08X)", hr);
            }
            else
            {
                AddLog("PlayFab Game Save cleaned up");
            }

            g_gameState.userAddedToGameSave = false;
        }
        ImGui::EndDisabled();

        // Save operation buttons - only show if PF Game Save is ready
        if (g_gameState.userAddedToGameSave)
        {
            ImGui::Text("Save Operations (PF Game Save Ready):");
            
            if (ImGui::Button("Save Game", ImVec2(150, 30)))
            {
                GameSaveIntegration::SaveGame();
            }

            ImGui::SameLine();

            if (ImGui::Button("Load Game", ImVec2(150, 30)))
            {
                GameSaveIntegration::LoadGame();
            }

            ImGui::SameLine();

            if (ImGui::Button("Delete Save", ImVec2(150, 30)))
            {
                GameSaveIntegration::DeleteSave();
            }

            ImGui::SameLine();

            if (ImGui::Button("Upload Save to Cloud", ImVec2(150, 30)))
            {
                HRESULT hr = GameSaveIntegration::UploadSaveToCloud(true);
                if (FAILED(hr))
                {
                    AddLog("GameSaveIntegration::UploadSaveToCloud() failed (HRESULT: 0x%08X)", hr);
                }
                else
                {
                    AddLog("PlayFab Game Save uploaded");
                }
            }
        }
        else
        {
            ImGui::Text("Save Operations: Add User to PF Game Save first");
        }

        ImGui::Separator();

        // Log display area
        ImGui::Text("Game Log:");
        ImGui::BeginChild("LogArea", ImVec2(0, 300), true, ImGuiWindowFlags_HorizontalScrollbar);

        // Use the custom font for log text
        if (m_font)
        {
            ImGui::PushFont(m_font);
        }

        for (size_t i = 0; i < g_gameState.logMessages.size(); ++i)
        {
            ImGui::Text("[%02d] %s", (int)i + 1, g_gameState.logMessages[i].c_str());
        }

        if (m_font)
        {
            ImGui::PopFont();
        }

        // Auto-scroll to bottom
        if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
        {
            ImGui::SetScrollHereY(1.0f);
        }

        ImGui::EndChild();

        // Status bar
        ImGui::Separator();

        // Controller status
        const char* controllerStatus = m_controllerConnected ? "Connected" : "Disconnected";
        ImVec4 statusColor = m_controllerConnected ? ImVec4(0.0f, 1.0f, 0.0f, 1.0f) : ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

        ImGui::Text("Status: Running | Log entries: %d | FPS: %.1f",
            (int)g_gameState.logMessages.size(), ImGui::GetIO().Framerate);
        ImGui::SameLine();
        ImGui::TextColored(statusColor, "| Controller: %s", controllerStatus);
        
        // Display save folder and remaining quota
        if (!g_gameState.saveFolder.empty())
        {
            ImGui::Text("Save Folder: %s", g_gameState.saveFolder.c_str());
        }
        else
        {
            ImGui::Text("Save Folder: Not set");
        }
        
        ImGui::SameLine();
        ImGui::Text("| Remaining Quota: %lld bytes", g_gameState.remainingQuota);

        ImGui::Separator();

        // Advanced Options Section
        ImGui::Checkbox("Advanced Options", &g_gameState.showAdvancedOptions);
        
        if (g_gameState.showAdvancedOptions)
        {
            ImGui::Indent();
            
            // Force Inproc option
            ImGui::Checkbox("Force Inproc", &g_gameState.forceInproc);
            ImGui::SameLine();
            ImGui::TextDisabled("(?)");
            if (ImGui::IsItemHovered())
            {
                ImGui::SetTooltip("[Debugging only] Forces PlayFab Game Save to run in-process instead of using out-of-process GRTS");
            }
            
            // Set UI Callbacks option
            ImGui::Checkbox("Set UI Callbacks", &g_gameState.setUiCallbacks);
            ImGui::SameLine();
            ImGui::TextDisabled("(?)");
            if (ImGui::IsItemHovered())
            {
                ImGui::SetTooltip("Enables UI callbacks for sync progress, conflicts, and storage dialogs. Always enabled on Steam Deck.");
            }
            
            ImGui::Separator();
            
            // Test Dialog Buttons
            ImGui::Text("Test UI Dialogs:");
            
            if (ImGui::Button("Test Sync Progress", ImVec2(150, 30)))
            {
                ShowSyncProgressDialog(g_gameState.localUserHandle, PFGameSaveFilesSyncState::Downloading, 1024, 10240);
            }
            
            ImGui::SameLine();
            
            if (ImGui::Button("Test Sync Failed", ImVec2(150, 30)))
            {
                ShowSyncFailedDialog(g_gameState.localUserHandle, E_FAIL);
            }
            
            ImGui::SameLine();
            
            if (ImGui::Button("Test Remote Connect", ImVec2(150, 30)))
            {
                ShowRemoteConnectDialogForXUserOnSteamDeck("https://aka.ms/xboxremoteconnect", "ABC123", 12345);
            }
            
            if (ImGui::Button("Test Active Device Contention", ImVec2(200, 30)))
            {
                // Create mock game save descriptors for testing
                static PFGameSaveDescriptor localSave = {};
                static PFGameSaveDescriptor remoteSave = {};
                ShowActiveDeviceContentionDialog(g_gameState.localUserHandle, &localSave, &remoteSave);
            }
            
            ImGui::SameLine();
            
            if (ImGui::Button("Test Conflict Dialog", ImVec2(150, 30)))
            {
                // Create mock game save descriptors for testing
                static PFGameSaveDescriptor localSave = {};
                static PFGameSaveDescriptor remoteSave = {};
                ShowConflictDialog(g_gameState.localUserHandle, &localSave, &remoteSave);
            }
            
            if (ImGui::Button("Test Out of Storage", ImVec2(150, 30)))
            {
                ShowOutOfStorageDialog(g_gameState.localUserHandle, 1048576); // 1MB required
            }
            
            ImGui::SameLine();
            
            if (ImGui::Button("Test Cloud Data Confirmation", ImVec2(200, 30)))
            {
                // Create mock game save descriptor for testing
                static PFGameSaveDescriptor remoteSave = {};
                ShowCloudDataConfirmationDialog(g_gameState.localUserHandle, &remoteSave);
            }
            
            ImGui::SameLine();
            
            if (ImGui::Button("Test SPOP Dialog", ImVec2(150, 30)))
            {
                // Create a mock operation for testing
                static XUserPlatformOperation mockOperation = {};
                ShowSpopPromptDialogForXUserOnSteamDeck(12345, &mockOperation, "TestGamertag", "#1234");
            }
            
            ImGui::Unindent();
        }

        ImGui::Separator();

        // Exit Game button
        if (ImGui::Button("Exit Game", ImVec2(150, 30)))
        {
            m_running = false;
            // Post WM_QUIT message to properly exit the Windows message loop
            PostQuitMessage(0);
        }
    }
    ImGui::End();

    // Render Remote Connect Dialog
    RenderRemoteConnectDialogForXUserOnSteamDeck();
    
    // Open the modal if needed
    if (g_gameState.remoteConnectDialog.showDialog && !ImGui::IsPopupOpen("Xbox Remote Connect"))
    {
        ImGui::OpenPopup("Xbox Remote Connect");
    }

    // Render SPOP Prompt Dialog
    RenderSpopPromptDialogForXUserOnSteamDeck();
    
    // Open the modal if needed
    if (g_gameState.spopPromptDialog.showDialog && !ImGui::IsPopupOpen("Xbox Sign-In Prompt"))
    {
        ImGui::OpenPopup("Xbox Sign-In Prompt");
    }

    // Render Sync Progress Dialog
    RenderSyncProgressDialog();
    
    // Open the sync progress modal if needed
    if (g_gameState.syncProgressDialog.showDialog && !ImGui::IsPopupOpen("Game Save Sync"))
    {
        ImGui::OpenPopup("Game Save Sync");
    }

    // Render Sync Failed Dialog
    RenderSyncFailedDialog();
    
    // Open the sync failed modal if needed
    if (g_gameState.syncFailedDialog.showDialog && !ImGui::IsPopupOpen("Sync Failed"))
    {
        ImGui::OpenPopup("Sync Failed");
    }

    // Render Active Device Contention Dialog
    RenderActiveDeviceContentionDialog();
    
    // Open the active device contention modal if needed
    if (g_gameState.activeDeviceContentionDialog.showDialog && !ImGui::IsPopupOpen("Active Device Contention"))
    {
        ImGui::OpenPopup("Active Device Contention");
    }

    // Render Conflict Dialog
    RenderConflictDialog();
    
    // Open the conflict modal if needed
    if (g_gameState.conflictDialog.showDialog && !ImGui::IsPopupOpen("Save Data Conflict"))
    {
        ImGui::OpenPopup("Save Data Conflict");
    }

    // Render Out of Storage Dialog
    RenderOutOfStorageDialog();
    
    // Open the out of storage modal if needed
    if (g_gameState.outOfStorageDialog.showDialog && !ImGui::IsPopupOpen("Not Enough Storage"))
    {
        ImGui::OpenPopup("Not Enough Storage");
    }

    // Render Cloud Data Confirmation Dialog
    RenderCloudDataConfirmationDialog();
    
    // Open the cloud data confirmation modal if needed
    if (g_gameState.cloudDataConfirmationDialog.showDialog && !ImGui::IsPopupOpen("Confirm Cloud Data"))
    {
        ImGui::OpenPopup("Confirm Cloud Data");
    }

    // Show ImGui demo window (optional, for reference)
    static bool show_demo = false;
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Windows"))
        {
            ImGui::MenuItem("Show Demo Window", nullptr, &show_demo);
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if (show_demo)
    {
        ImGui::ShowDemoWindow(&show_demo);
    }
}

void SimpleGame::Render()
{
    ImGuiIO& io = ImGui::GetIO();

    // Rendering
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(m_window);
}

void SimpleGame::Cleanup()
{
    // Cleanup game save integration
    GameSaveIntegration::CleanupPFGameSave();
    GameSaveIntegration::CleanupSteam();

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    if (m_gameController)
    {
        SDL_GameControllerClose(m_gameController);
    }
    if (m_glContext)
    {
        SDL_GL_DeleteContext(m_glContext);
    }
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

bool SimpleGame::IsRunning() const
{
    return m_running;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Initialize COM for Windows
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    
    SimpleGame game;
    
    if (!game.Initialize())
    {
        CoUninitialize();
        return -1;
    }
    
    // Main message loop with proper Windows message pump
    MSG msg = {};
    while (game.IsRunning())
    {
        // Process all pending Windows messages
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                CoUninitialize();
                return (int)msg.wParam;
            }
            
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        // Run one frame of the game
        game.HandleEvents();
        game.Update();
        game.Render();
        
        // Small sleep to prevent 100% CPU usage
        Sleep(1);
    }
    
    CoUninitialize();
    return 0;
}
