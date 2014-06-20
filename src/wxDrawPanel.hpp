/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxDrawPanel.hpp
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */

#ifndef __DEFCRONYKE__WXDRAWPANEL_HPP__INCLUDED__
#define __DEFCRONYKE__WXDRAWPANEL_HPP__INCLUDED__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

namespace TurtleDef
{

class wxTurtle;

class wxDrawPanel: public wxPanel
{
public:
	wxDrawPanel(wxFrame* parent);
	virtual ~wxDrawPanel();

	void OnPaint(wxPaintEvent& event);	// Render on wxEVT_PAINT event.
	void OnLeftClick(wxMouseEvent& event);
	void OnRightClick(wxMouseEvent& event);

	void paint_now();					// Render now.
	void render(wxDC& context);			// Rendering happens in here.

	wxFrame* parent;
	wxTurtle* turtle;

	int current_draw_func_num;
	int num_draw_funcs;
};

enum
{

};

}
#endif
