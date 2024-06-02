#include "mainframe.h"
#include <wx/spinctrl.h>
#include <wx/wxprec.h>
#include <cfloat>


enum {
    ID_Hello = 1,
};

MainFrame::MainFrame()
        : wxFrame(nullptr, wxID_ANY, "Решала", wxDefaultPosition, wxDefaultSize) {

    wxStaticText *text = new wxStaticText(this, wxID_ANY,
                                          "Для решения уравнения вида\nax² + bx + c = 0\nвведите его коэффициенрты ниже:",
                                          wxPoint((GetSize().GetWidth() >> 1) - 100, 20),
                                          wxSize(200, 60));

    wxPanel *inputPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 80), wxSize(GetSize().GetWidth(), 20));
    // литеры
    wxStaticText *textA = new wxStaticText(inputPanel, wxID_ANY, "a:", wxPoint((GetSize().GetWidth() >> 1) - 160, 0));
    // MARK: кнопки ввода значений
    wxSpinCtrlDouble *numSelectorA = new wxSpinCtrlDouble(inputPanel, wxID_ANY, wxEmptyString,
                                                          wxPoint((GetSize().GetWidth() >> 1) - 140, 0), wxSize(100, 20));
    wxSpinCtrlDouble *numSelectorB = new wxSpinCtrlDouble(inputPanel, wxID_ANY, wxEmptyString,
                                                          wxPoint((GetSize().GetWidth() >> 1) - 20, 0), wxSize(100, 20));
    wxSpinCtrlDouble *numSelectorC = new wxSpinCtrlDouble(inputPanel, wxID_ANY, wxEmptyString,
                                                          wxPoint((GetSize().GetWidth() >> 1) + 100, 0), wxSize(100, 20));
    numSelectorA->SetRange(-DBL_MAX, DBL_MAX);
    numSelectorA->SetDigits(5);
    numSelectorB->SetRange(-DBL_MAX, DBL_MAX);
    numSelectorB->SetDigits(5);
    numSelectorC->SetRange(-DBL_MAX, DBL_MAX);
    numSelectorC->SetDigits(5);

    wxButton *getNumsButton = new wxButton(this, wxID_ANY, "Вычислить", wxPoint((GetSize().GetWidth() >> 1) - 40, 120),
                                           wxSize(80, 20));


    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

// Окно "о приложении"
void MainFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox(
            "Программа написана в рамках курсовой работы 2 семестра.\nРазработчик - Богданов М.А.\nmail: prpdss@gmail.com \ntelegram: t.me/parapidosius",
            "О приложении", wxOK | wxICON_INFORMATION);
}
