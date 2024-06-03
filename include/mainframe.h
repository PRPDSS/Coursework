#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "equation.h"
#include "solver.h"

class MainFrame : public wxFrame {
public:
    MainFrame();

private:
    wxSpinCtrlDouble *numSelectorA;
    wxSpinCtrlDouble *numSelectorB;
    wxSpinCtrlDouble *numSelectorC;
    wxStaticText *resultText;

    void OnExit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

    void OnHelp(wxCommandEvent &event);

    void GetValuesAndSolve(wxCommandEvent &event);
};

#endif // MAINFRAME_H
