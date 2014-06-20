/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxMainApp.h
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */

#ifndef __DEFCRONYKE__WXSNAKEAPP_H__INCLUDED__
#define __DEFCRONYKE__WXSNAKEAPP_H__INCLUDED__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

namespace TurtleDef
{

class wxMainFrame;
class wxDrawPanel;

class wxMainApp : public wxApp
{
	wxMainFrame* frame;

public:
	virtual bool OnInit();
	virtual int OnExit();
};

}
#endif
