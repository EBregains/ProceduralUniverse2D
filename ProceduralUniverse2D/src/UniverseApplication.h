#pragma once

#include <stack>
#include "State.h"


/// <summary>
/// Clase that contains the Application.
/// </summary>
class UniverseApplication
{
private:

	/// <summary>
	/// Pointer to main window.
	/// </summary>
	std::unique_ptr<sf::RenderWindow> ptrWindow;

	/// <summary>
	/// Structure that contains the Application States.
	/// </summary>
	std::stack<State> mState;

	/// <summary>
	/// Clock to measure time elapsed between frames.
	/// </summary>
	sf::Clock dTimeClock;

	/// <summary>
	/// The time elapsed between frames
	/// </summary>
	sf::Time dTime;

public:

	/// <summary>
	/// Constructor.
	/// </summary>
	UniverseApplication();

	/// <summary>
	/// Destructor.
	/// </summary>
	~UniverseApplication();

	/// <summary>
	/// Application loop
	/// </summary>
	void Run();

	/// <summary>
	/// Process all the SFML Events on the class member ptrWindow.
	/// </summary>
	void ProcessEvents();

	/// <summary>
	/// Update the State at the top, and looks for changings.
	/// </summary>
	/// <param name="dTime"></param>
	void Update();

	/// <summary>
	/// Clear the main window, draw the current State, and display de Window.
	/// </summary>
	void Draw();

};