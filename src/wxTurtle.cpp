/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxTurtle.cpp
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */

#include "wxTurtle.hpp"
#include <math.h>
#include <random>

#include "wxDrawPanel.hpp"

namespace TurtleDef
{

wxTurtle::wxTurtle(wxDrawPanel* parent)
 : parent(parent),
   pos(wxPoint(parent->parent->m_width/2, parent->parent->m_height - 50)),
   speed(1.f), dir(90.f), pen_is_down(true),
   pen(wxColour(15, 5, 100), 2, wxPENSTYLE_SOLID),
   brush(wxColour(111, 154, 90), wxBRUSHSTYLE_SOLID)	// Not used for drawing lines.
{
}

wxTurtle::~wxTurtle()
{
}

float wxTurtle::deg_to_rad(float n)
{
	return n * (M_PI/180.f);
}

float wxTurtle::rad_to_deg(float n)
{
	return n * (180.f/M_PI);
}

void wxTurtle::forward(wxDC& context, float distance)
{
	wxPoint new_pos = wxPoint(pos.x + (distance*speed) * cos(deg_to_rad(dir)) + 0.5f, pos.y - (distance*speed) * sin(deg_to_rad(dir)) + 0.5f);
	if (new_pos.x > (pen.GetWidth()+1) && new_pos.x < parent->m_width-(pen.GetWidth()+1) &&	// Minus pen size + 1.
		new_pos.y > (pen.GetWidth()+1) && new_pos.y < parent->m_height-(pen.GetWidth()+1) &&  // TODO: This statement will clip an entire line if part of the line goes out of bounds. Shorten the line instead.
		pen_is_down)
	{
		context.DrawLine(pos, new_pos);
	}
	pos = new_pos;
}

void wxTurtle::back(wxDC& context, float distance)
{
	wxPoint new_pos = wxPoint(pos.x - (distance*speed) * cos(deg_to_rad(dir)) - 0.5f, pos.y + (distance*speed) * sin(deg_to_rad(dir)) - 0.5f);
	if (new_pos.x > (pen.GetWidth()+1) && new_pos.x < parent->m_width-(pen.GetWidth()+1) &&	// Minus pen size + 1.
		new_pos.y > (pen.GetWidth()+1) && new_pos.y < parent->m_height-(pen.GetWidth()+1) &&
		pen_is_down)
	{
		context.DrawLine(pos, new_pos);
	}
	pos = new_pos;
}

void wxTurtle::left(float angle)
{
	dir += angle;
}

void wxTurtle::right(float angle)
{
	dir -= angle;
}

void wxTurtle::penup()
{
	pen_is_down = false;
}

void wxTurtle::pendown()
{
	pen_is_down = true;
}

void wxTurtle::frac1(wxDC& context, int n, int l, bool f)
{
	wxColour new_colour(0, 125, 255);
	std::function<void(float)> turn1([&](float angle){ left(angle); });
	std::function<void(float)> turn2([&](float angle){ right(angle); });

	if(f)
	{
		new_colour = wxColour(255, 125, 0);
		turn1 = [&](float angle){ right(angle); };
		turn2 = [&](float angle){ left(angle); };
	}
	if (n <= 0)	// Base case
	{
		pen.SetColour(new_colour);
		context.SetPen(pen);
		forward(context, l);
		return;
	}
	frac1(context, n-1, l, f);
	turn1(45.f);
	frac1(context, n-1, l, f);
	turn2(135.f);
	frac1(context, n-1, l, !f);
	turn2(90.f);
	frac1(context, n-1, l, !f);
	turn1(45.f);
}

void wxTurtle::frac2(wxDC& context, int n, int l, bool f)
{
	std::function<void(float)> turn1([&](float angle){ left(angle); });
	std::function<void(float)> turn2([&](float angle){ right(angle); });

	if(f)
		{
			turn1 = [&](float angle){ right(angle); };
			turn2 = [&](float angle){ left(angle); };
		}

	if (n <= 0)	// Base case
	{
		forward(context, l);
		return;
	}
	{
		std::default_random_engine rand_eng(rand_dev());
		std::uniform_int_distribution<int> uniform_dist(0, 5);
		int colour = uniform_dist(rand_eng);
		wxColour new_colour(0,0,0);
		if (colour == 0)
			new_colour = wxColour(255, 0, 0);
		else if (colour == 1)
			new_colour = wxColour(255, 125, 0);
		else if (colour == 2)
			new_colour = wxColour(255, 255, 0);
		else if (colour == 3)
			new_colour = wxColour(0, 125, 0);
		else if (colour == 4)
			new_colour = wxColour(0, 0, 255);
		else
			new_colour = wxColour(255, 0, 255);
		pen.SetColour(new_colour);
		context.SetPen(pen);
	}
	{
		std::default_random_engine rand_eng(rand_dev());
		std::uniform_int_distribution<int> uniform_dist(0, 1);
		int flipped = uniform_dist(rand_eng);
		frac2(context, n-1, l, flipped);
		turn2(100.f);
		frac2(context, n-1, l/2, flipped);
		turn2(60.f);
		frac2(context, n-1, l/3, flipped);
		turn2(60.f);
		frac2(context, n-1, l/4, flipped);
		turn1(180.f);
	}

}

void wxTurtle::frac3(wxDC& context, int n, int l, bool f)
{
	if (n <= 0)
	{
		forward(context, l);
		return;
	}

	forward(context, l);
	left(35.f);

	std::default_random_engine rand_eng(rand_dev());
	std::uniform_int_distribution<int> uniform_dist(0, 1);
	int left_or_right = uniform_dist(rand_eng); // 0 is left, 1 is right

	if (left_or_right)
	{
		right(25.f);
		wxColour new_pen_colour((l*n) % 256, n/(l+1) % 256, 100);
		pen.SetColour(new_pen_colour);
		pen.SetWidth(3);
		context.SetPen(pen);
	}
	else
	{
		left(70.f);
		wxColour new_pen_colour(100, (n/(l+1)) % 256, (l/2) % 256);
		pen.SetColour(new_pen_colour);
		pen.SetWidth(2);
		context.SetPen(pen);
	}
	forward(context, l/2);

	if (left_or_right)
	{
		left(85.f);
		wxColour new_pen_colour(l/6 % 256, 100, n % 256);
		pen.SetColour(new_pen_colour);
		pen.SetWidth(3);
		context.SetPen(pen);
	}
	else
	{
		right(25.f);
		wxColour new_pen_colour(l/3 % 256, n % 256, l % 256);
		pen.SetColour(new_pen_colour);
		pen.SetWidth(3);
		context.SetPen(pen);
	}

	forward(context, l/3);
	left(16.f);
	frac3(context, n-1, l/2);	// Recurse
	frac3(context, n-1, l);		// Recurse
}

void wxTurtle::spiro1(wxDC& context, int n, int l, bool f)
{
	if (n <= 0)
		return;
	forward(context, l);
	left(160.f);
	pen.SetColour(127, 255, 0);
	context.SetPen(pen);
	forward(context, l);
	right(90.f);
	pen.SetColour(0, 127, 127);
	context.SetPen(pen);
	spiro1(context, n-1, l);
}

void wxTurtle::frac4(wxDC& context, int n, int l, bool f)
{
	if (n <= 0)
		return;

	if (f)
		left(static_cast<float>(n % 4 * 23));
	else
		right(static_cast<float>(n % 3 * 12));

	{
		std::default_random_engine rand_eng(rand_dev());
		std::uniform_int_distribution<int> uniform_dist(0, 1);
		int forward_or_back = uniform_dist(rand_eng);
		if (forward_or_back)
		{
			forward(context, l);
			left(static_cast<float>(n % 4 * 16));
		}
		else
			back(context, l);
	}

	int r, g, b;
	{
		std::default_random_engine rand_eng(rand_dev());
		std::uniform_int_distribution<int> uniform_dist(0, 255);
		r = uniform_dist(rand_eng);
	}
	{
		std::default_random_engine rand_eng(rand_dev());
		std::uniform_int_distribution<int> uniform_dist(0, 255);
		g = uniform_dist(rand_eng);
	}
	{
		std::default_random_engine rand_eng(rand_dev());
		std::uniform_int_distribution<int> uniform_dist(0, 255);
		b = uniform_dist(rand_eng);
	}

	pen.SetColour(wxColour(r, g, b));
	context.SetPen(pen);

	frac4(context, n-1, l, !f);
	frac4(context, n-2, l/3, !f);
	frac4(context, n-2, l, f);
}

}
