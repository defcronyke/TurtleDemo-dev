/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxMainFrame.cpp
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */
#include "wxMainFrame.hpp"
#include "wxDrawPanel.hpp"

namespace TurtleDef
{

wxMainFrame::wxMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
 : wxFrame(0, wxID_ANY, title, pos, size)
{
	wxMenu* file_menu = new wxMenu;
	file_menu->Append(wxID_EXIT);

	wxMenuBar* menu_bar = new wxMenuBar;
	menu_bar->Append(file_menu, "&File");
	SetMenuBar(menu_bar);

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	draw_panel = new wxDrawPanel(static_cast<wxFrame*>(this));
	draw_panel->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Serif")));

	sizer->Add(draw_panel, 1, wxEXPAND);
	SetSizer(sizer);
	SetAutoLayout(true);

	Bind(wxEVT_MENU, &wxMainFrame::OnExit, this, wxID_EXIT);
}

wxMainFrame::~wxMainFrame()
{
}

void wxMainFrame::OnExit(wxCommandEvent&)
{
	Close(true);
}

}
