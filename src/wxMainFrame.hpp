/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxMainFrame.hpp
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */

#ifndef __DEFCRONYKE__WXSNAKEFRAME_HPP__INCLUDED__
#define __DEFCRONYKE__WXSNAKEFRAME_HPP__INCLUDED__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

namespace TurtleDef
{

class wxDrawPanel;

class wxMainFrame: public wxFrame
{
public:
	wxMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	virtual ~wxMainFrame();

	void OnExit(wxCommandEvent&);

	wxDrawPanel* draw_panel; // This is a custom class for drawing on, derived from wxPanel.
};

}
#endif
