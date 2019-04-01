//--------------------------------------------------------------------------------------
// Main.cpp
//
// Entry point for Xbox One exclusive title.
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Game.h"


#include <ppltasks.h>

using namespace concurrency;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::Foundation;
using namespace DirectX;

bool g_HDRMode = false;

ref class ViewProvider sealed : public IFrameworkView
{
public:
    ViewProvider() :
        m_exit(false)
    {
    }

    // IFrameworkView methods
    virtual void Initialize(CoreApplicationView^ applicationView)
    {
        applicationView->Activated +=
            ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &ViewProvider::OnActivated);

        CoreApplication::Suspending +=
            ref new EventHandler<SuspendingEventArgs^>(this, &ViewProvider::OnSuspending);

        CoreApplication::Resuming +=
            ref new EventHandler<Platform::Object^>(this, &ViewProvider::OnResuming);

        CoreApplication::DisableKinectGpuReservation = true;

        ::g_game = std::make_unique<Sample>();
    }

    virtual void Uninitialize()
    {
        g_game.reset();
    }

    virtual void SetWindow(CoreWindow^ window)
    {
        window->Closed +=
            ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &ViewProvider::OnWindowClosed);

        // Default window thread to CPU 0
        SetThreadAffinityMask(GetCurrentThread(), 0x1);

        g_game->Initialize(reinterpret_cast<IUnknown*>(window));
    }

    virtual void Load(Platform::String^ entryPoint)
    {
    }

    virtual void Run()
    {
        while (!m_exit)
        {
            g_game->Tick();

            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
        }
    }

protected:
    // Event handlers
    void OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
    {
        CoreWindow::GetForCurrentThread()->Activate();
    }

    void OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
    {
        auto deferral = args->SuspendingOperation->GetDeferral();

        create_task([this, deferral]()
        {
            g_game->OnSuspending();

            deferral->Complete();
        });
    }

    void OnResuming(Platform::Object^ sender, Platform::Object^ args)
    {
        g_game->OnResuming();
    }

    void OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
    {
        m_exit = true;
    }

private:
    bool                    m_exit;
};

ref class ViewProviderFactory : IFrameworkViewSource
{
public:
    virtual IFrameworkView^ CreateView()
    {
        return ref new ViewProvider();
    }
};


// Entry point
[Platform::MTAThread]
int __cdecl main(Platform::Array<Platform::String^>^ /*argv*/)
{
    // Default main thread to CPU 0
    SetThreadAffinityMask(GetCurrentThread(), 0x1);

    auto viewProviderFactory = ref new ViewProviderFactory();
    CoreApplication::Run(viewProviderFactory);
    return 0;
}


// Exit helper
void ExitSample()
{
    Windows::ApplicationModel::Core::CoreApplication::Exit();
}