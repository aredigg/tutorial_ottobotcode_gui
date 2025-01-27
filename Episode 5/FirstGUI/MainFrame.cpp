#include "MainFrame.h"
#include <wx/wx.h>

enum {
    BUTTON_ID = 2,
    SLIDER_ID = 3,
    TEXT_ID = 4
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
    EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
    EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel *panel = new wxPanel(this);
    wxButton *button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
    wxSlider *slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
    wxTextCtrl *text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));
    CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent &event) {
    wxLogStatus("Button Clicked");
}

void MainFrame::OnSliderChanged(wxCommandEvent &event) {
    wxString str = wxString::Format("Slider value: %d", event.GetInt());
    wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent &event) {
    wxString str = wxString::Format("Text: %s", event.GetString());
    wxLogStatus(str);
}