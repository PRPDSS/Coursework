#include "mainframe.h"
#include <iostream>
#include <cfloat>

enum {
    ID_Button = 1,
};

MainFrame::MainFrame()
        : wxFrame(nullptr, wxID_ANY, "Решала", wxDefaultPosition, wxDefaultSize) {

    wxStaticText *text = new wxStaticText(this, wxID_ANY,
                                          "Для решения уравнения вида\nax² + bx + c = 0\nвведите его коэффициенты ниже:",
                                          wxPoint((GetSize().GetWidth() >> 1) - 100, 20),
                                          wxSize(200, 60));

    wxPanel *inputPanel = new wxPanel(this, wxID_ANY, wxPoint((GetSize().GetWidth() >> 1) - 172, 80), wxSize(345, 20));

    // литеры
    wxStaticText *textA = new wxStaticText(inputPanel, wxID_ANY, "a:", wxPoint(0, 0));
    wxStaticText *textB = new wxStaticText(inputPanel, wxID_ANY, "b:", wxPoint(115, 0));
    wxStaticText *textC = new wxStaticText(inputPanel, wxID_ANY, "c:", wxPoint(230, 0));
    // кнопки ввода значений
    numSelectorA = new wxSpinCtrlDouble(inputPanel, wxID_ANY, wxEmptyString,
                                        wxPoint(13, 0),
                                        wxSize(100, 20));
    numSelectorB = new wxSpinCtrlDouble(inputPanel, wxID_ANY, wxEmptyString,
                                        wxPoint(128, 0),
                                        wxSize(100, 20));
    numSelectorC = new wxSpinCtrlDouble(inputPanel, wxID_ANY, wxEmptyString,
                                        wxPoint(243, 0),
                                        wxSize(100, 20));
    numSelectorA->SetRange(-DBL_MAX, DBL_MAX);
    numSelectorA->SetDigits(5);
    numSelectorB->SetRange(-DBL_MAX, DBL_MAX);
    numSelectorB->SetDigits(5);
    numSelectorC->SetRange(-DBL_MAX, DBL_MAX);
    numSelectorC->SetDigits(5);

    wxButton *getNumsButton = new wxButton(this, ID_Button, "Вычислить", wxPoint((GetSize().GetWidth() >> 1) - 40, 120),
                                           wxSize(80, 20));

    resultText = new wxStaticText(this, wxID_ANY, "", wxPoint((GetSize().GetWidth() >> 1) - 100, 160), wxSize(200, 60));

    wxMenu *menuAbout = new wxMenu;
    menuAbout->Append(wxID_ABOUT);

    wxMenu *menuHelp = new wxMenu;

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuAbout, "&Help");


    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &MainFrame::GetValuesAndSolve, this, ID_Button);
}

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

// Окно "о приложении"
void MainFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox(
            "Программа написана в рамках курсовой работы 2 семестра.\n\nРазработчик - Богданов М.А.\n\nemail: prpdss@gmail.com \ntelegram: t.me/parapidosius",
            "О приложении", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHelp(wxCommandEvent &event) {
    wxMessageBox("", "Справка по использованию");
}

void MainFrame::GetValuesAndSolve(wxCommandEvent &event) {
    clock_t startTime, endTime;
    double a = numSelectorA->GetValue();
    double b = numSelectorB->GetValue();
    double c = numSelectorC->GetValue();
    Equation e(a, b, c);

    startTime = clock();
    auto [x1, x2, numberOfRoots] = Solver::solve(e);
    endTime = clock();
    switch (numberOfRoots) {
        case 1:
            resultText->SetLabel(wxString::Format("Корень уравнения:\nx = %.5f", x1));
            break;
        case 2:
            resultText->SetLabel(wxString::Format("Корни уравнения:\nx1 = %.5f\nx2 = %.5f", x1, x2));
            break;
        case 3:
            resultText->SetLabel(wxString::Format("Любое число удовлетворяет решению\"0 == 0\""));
            break;
        default:
            resultText->SetLabel("Нет действительных корней");
            break;
    }
    std::cout << "Root search time: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << "sec." << std::endl;
}
