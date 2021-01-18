#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

/// <summary>
/// Includes all States in the program. Starts with STAY (equals 0) and ends in QUIT.
/// </summary>
enum class eStates { STAY, MainMenu, Configs, GameState, Pause, PauseConfigs, QUIT};

/// <summary>
/// Base Class for all States in the application.
/// </summary>
class State
{
private:
	/// <summary>
	/// Indicates if the State wants to change, and the next State type. It's STAY by default.
	/// </summary>
	eStates mNextState{ eStates::STAY };

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	State();
	
	/// <summary>
	/// Destructor.
	/// </summary>
	virtual ~State();

	/// <summary>
	/// Process SFML Events happened in the window passed as parameter. Use just if differents States need differents SFML Events behaviour. Empty by default.
	/// </summary>
	/// <param name="window"> Window to take SFML Events. </param>
	virtual void ProcessEvents(const std::unique_ptr<sf::RenderWindow>& window) {};

	/// <summary>
	/// Update all Entities declared in the State, using the elapsed time passed as parameter.
	/// </summary>
	/// <param name="dTime"> The time between frames. </param>
	virtual void Update(sf::Time dTime);

	/// <summary>
	/// Print all Entities declared in the State, on the window passed as parameter.
	/// </summary>
	/// <param name="window">Target window</param>
	virtual void Draw(const std::unique_ptr<sf::RenderWindow>& window);

	/// <summary>
	/// Getter method of data member mNextState.
	/// </summary>
	/// <returns> Returns eState::STAY by default </returns>
	virtual inline eStates NextState() { return mNextState; };

};

