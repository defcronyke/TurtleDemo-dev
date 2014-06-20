/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxTurtle.hpp
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */

#ifndef __DEFCRONYKE__WXTURTLE_HPP__INCLUDED__
#define __DEFCRONYKE__WXTURTLE_HPP__INCLUDED__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <functional>

namespace TurtleDef
{

class wxDrawPanel;

class wxTurtle	// Implements some of the functionality of the Python Turtle
{
	wxDrawPanel* parent;
public:
	wxTurtle(wxDrawPanel* parent);
	virtual ~wxTurtle();

	float deg_to_rad(float n);
	float rad_to_deg(float n);

	void forward(wxDC& context, float distance);
	void back(wxDC& context, float distance);
	void left(float angle);	// Angle in degrees.
	void right(float angle);
	void penup();
	void pendown();

	void frac1(wxDC& context, int n = 5, int l = 500, bool f = false); // TODO: Give these drawing functions less stupid names.
	void frac2(wxDC& context, int n = 5, int l = 500, bool f = false);
	void frac3(wxDC& context, int n = 5, int l = 500, bool f = false);
	void spiro1(wxDC& context, int n = 5, int l = 500, bool f = false);
	void frac4(wxDC& context, int n = 5, int l = 500, bool f = false);

	wxPoint pos;
	float speed;
	float dir; // Direction in degrees.
	bool pen_is_down;
	std::random_device rand_dev;
	wxPen pen;	// The outline colour
	wxBrush brush;	// The filling colour. Not used for drawing lines.
};

}
#endif
