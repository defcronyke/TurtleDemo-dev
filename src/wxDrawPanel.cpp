/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxDrawPanel.cpp
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */
#include "wxDrawPanel.hpp"

#include <iostream>
#include "wxTurtle.hpp"

namespace TurtleDef
{

wxDrawPanel::wxDrawPanel(wxFrame* parent)
 : wxPanel(parent), parent(parent), turtle(0),
   current_draw_func_num(2), num_draw_funcs(5)	// IMPORTANT: Update num_draw_funcs when adding more draw functions.
{
	Bind(wxEVT_PAINT, &wxDrawPanel::OnPaint, this, wxID_ANY);
	Bind(wxEVT_LEFT_DOWN, &wxDrawPanel::OnLeftClick, this, wxID_ANY);
	Bind(wxEVT_RIGHT_DOWN, &wxDrawPanel::OnRightClick, this, wxID_ANY);
}

wxDrawPanel::~wxDrawPanel()
{
}

void wxDrawPanel::OnPaint(wxPaintEvent& event)
{
	std::cout << "Paint event detected. Starting to render." << std::endl;
	wxPaintDC context(this);
	render(context);
}

void wxDrawPanel::OnLeftClick(wxMouseEvent& event)
{
	std::cout << "Left-click detected. Running the same drawing program again." << std::endl;
	Refresh();	// Restart rendering
}

void wxDrawPanel::OnRightClick(wxMouseEvent& event)
{
	std::cout << "Right-click detected. Switching to the next drawing program." << std::endl;
	current_draw_func_num = (current_draw_func_num + 1) % num_draw_funcs; // Advance to next draw function.
	Refresh();
}

void wxDrawPanel::paint_now()
{
	wxClientDC context(this);
	render(context);
}

void wxDrawPanel::render(wxDC& context)
{
	std::cout << "Rendering. Please wait..." << std::endl;

	turtle = new wxTurtle(this);
	context.SetBrush(turtle->brush);
	context.SetPen(turtle->pen);

	if (current_draw_func_num == 0)
	{
		turtle->pos = wxPoint(parent->m_width/2 - 200, parent->m_height/2 + 300);
		turtle->frac1(context, 8, 10);
	}
	else if (current_draw_func_num == 1)
	{
		turtle->pos = wxPoint(parent->m_width/2 - 200, parent->m_height/2);
		turtle->frac2(context, 8, 300);
	}
	else if (current_draw_func_num == 2)
		turtle->frac3(context, 15, 100);
	else if (current_draw_func_num == 3)
	{
		turtle->pos = wxPoint(parent->m_width/2, parent->m_height/2 - 70);
		turtle->spiro1(context, 20, 200);
	}
	else if (current_draw_func_num == 4)
	{
		turtle->pos = wxPoint(parent->m_width/2, parent->m_height/2);
		turtle->frac4(context, 10, 50);
	}

	delete turtle;
	std::cout << "Render finished." << std::endl;
}

}
