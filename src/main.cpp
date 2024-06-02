#include <iostream>
#include "mainframe.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif


class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

enum
{
    ID_Hello = 1
};

bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame();
    frame->Show(true);
    return true;
}