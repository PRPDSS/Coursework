//
// Created by Максим Богданов on 02.06.2024.
//
#include <wx/wx.h>
#include "solver.h"

#ifndef CALC_MAINFRAME_H
#define CALC_MAINFRAME_H
#endif //CALC_MAINFRAME_H

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    Solver s();
    Equation eq();

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
};