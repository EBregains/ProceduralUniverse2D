#include "UniverseApplication.h"

//----------------- CONSTRUCTOR / DESTRUCTOR ---------------------------------------------------
UniverseApplication::UniverseApplication()
{
	ptrWindow->create(sf::VideoMode(800,800), "Universe Application");
	ptrWindow->setFramerateLimit(60);
}
UniverseApplication::~UniverseApplication()
{
}

// RUN LOOP -------------------------------------------------------------------------------------
void UniverseApplication::Run()
{
	while (this->ptrWindow->isOpen())
	{
		dTime = dTimeClock.restart();
		ProcessEvents();
		//Check if theres an state, so Update and Draw
		if (!mState.empty()) {
			Update(dTime);
			Draw();
		} // If is not, means that main menu was closed, so close the window
		else ptrWindow->close();
	}
}

/*
----------------------- FUNCTIONS THAT WORK IN LOOP ----------------------------------------------
*/
// This functions process inputs in SFML, its necesary and was copied by SFML documentation.
void UniverseApplication::ProcessEvents()
{
	sf::Event event{};
	while (this->ptrWindow->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->ptrWindow->close();
			break;

		case sf::Event::LostFocus:
			dTime = sf::Time::Zero;
			break;
		}
	}
}
// Update the current State via dTime
void UniverseApplication::Update(sf::Time dTime)
{
	mState.top().Update(dTime);
	if (mState.top().WantToChange())					// If current State WantToChange, means that want to call other state, or just want to quit
	{
		if (mState.top().WantToQuit()) mState.pop();	// If just want to quit, no need to change
		else
		{
			switch (mState.top().NextState)
			{
			case eStates::MainMenu:
				break;
			}
		}
		;		// If dont want to quit, means want to change to other state
	}
}
// Draw current State passing Window ptr. SFML Documentation says that its faster clearing the screen and redrawing it
void UniverseApplication::Draw()
{
	ptrWindow->clear();
		mState.top().Draw(this->ptrWindow);
	ptrWindow->display();
}