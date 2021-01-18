#include "UniverseApplication.h"

//----------------- CONSTRUCTOR / DESTRUCTOR ---------------------------------------------------
UniverseApplication::UniverseApplication()
{
	ptrWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(800,800), "Universe Application");
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
		if (!mState.empty())		
		{ 
			ProcessEvents();
			dTime = dTimeClock.restart();
			Update(dTime);
			Draw();
		}								// If is not, means that main menu was closed, so close the window
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
			break;
		}
	}
}

void UniverseApplication::Update()
{
	mState.top().Update(this->dTime);												// If just want to quit, no need to change
	switch (mState.top().NextState())
	{
	case eStates::STAY:
		break;
	case eStates::MainMenu:
		break;
	}
}
// Draw current State passing Window ptr. SFML Documentation says that its faster clearing the screen and redrawing it
void UniverseApplication::Draw()
{
	ptrWindow->clear();
		mState.top().Draw(this->ptrWindow);
	ptrWindow->display();
}
