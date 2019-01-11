#pragma once

#include "resource.h"

namespace ThunderRumble
{

class PlayFabLoginDialog : public CDialogImpl<PlayFabLoginDialog>
{
public:
    enum { IDD = IDD_PLAYFABLOGIN };

    BEGIN_MSG_MAP(PlayFabLoginDialog)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnBnClickedCancel)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/,
        BOOL& /*bHandled*/)
    {
        // Do some initialization code
        return 1;
    }
public:
    LRESULT OnBnClickedCancel(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    {
        return 1;
    }
};

}
