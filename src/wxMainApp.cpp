/* This file is part of Turtle Demo
 * Copyright (C) 2014 Jeremy Carter
 *
 * This project as a whole is licensed under the wxWindows Library Licence,
 * Version 3.1. See the file called LICENSE found in the project root folder
 * for the text of the license.
 *
 * wxMainApp.cpp
 *
 * Created on: Jun 19, 2014
 *     Author: Jeremy Carter
 *      Email: Jeremy [at] JeremyCarter [dot] ca
 */
#include "wxMainApp.hpp"
#include <iostream>
#include "wxMainFrame.hpp"

namespace TurtleDef
{

bool wxMainApp::OnInit()
{
	std::cout << "Starting Turtle Demo\nCopyright (C) 2014 Jeremy Carter\nThis project as a whole is licensed under the wxWindows Library Licence, Version 3.1. See the file called LICENSE found in the project root folder for the text of the license." << std::endl;
	frame = new wxMainFrame("Turtle Demo", wxDefaultPosition, wxSize(800, 600));
	frame->Show(true);
	std::cout << "Turtle Demo started" << std::endl;
	return true;
}

int wxMainApp::OnExit()
{
	std::cout << "Stopping Turtle Demo." << std::endl;
	// some exit stuff here
	std::cout << "Turtle Demo stopped." << std::endl;
	return 0;
}

}

wxIMPLEMENT_APP(TurtleDef::wxMainApp);
