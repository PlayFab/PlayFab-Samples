//--------------------------------------------------------------------------------------
// Layout.h
//
// Header for friendly names of UI elements
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#pragma once

namespace UiConstants
{
    // HUD + Legend
    const int c_simpleLegendHUD   = 100;
    const int c_unlinkLegendHUD   = 200;

    // Xbox Live Sign-In
    const int c_xboxLiveSignInOverlay = 400;
    const int c_xboxLiveSignInButton  = 403;

    // Acquire PlayFab Account Choices
    const int c_acquirePlayFabAccountChoicesOverlay = 500;
    const int c_acquireChoicesFacebookButton        = 504;
    const int c_acquireChoicesXboxLiveButton        = 505;

    // Sign-In Complete
    const int c_signInCompleteOverlay = 600;
    const int c_signInCompleteMessage = 603;

    // Sign-In Failure
    const int c_signInFailureOverlay       = 700;
    const int c_signInFailureMessage       = 703;
    const int c_backToAcquireAccountButton = 705;

    // Sign-In with Xbox Failure
    const int c_signInWithXboxFailureOverlay = 800;
    const int c_signInDifferentUserButton    = 805;

    // Account Already Linked
    const int c_unlinkPlayFabAccountPopUp  = 900;
    const int c_unlinkPlayFabAccountButton = 903;
} // namespace UIConstants
