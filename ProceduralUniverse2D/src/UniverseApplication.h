#pragma once
#include <stack>
#include "State.h"

class UniverseApplication
{
private:

	std::unique_ptr<sf::RenderWindow> ptrWindow;
	std::stack<State> mState;

	sf::Clock dTimeClock;
	sf::Time dTime;

public:

	UniverseApplication();
	~UniverseApplication();
	
	void Run();
	void ProcessEvents();
	void Update(sf::Time dTime);
	void Draw();
};

