#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

enum class eStates { Stay, MainMenu, Configs, GameState, Pause, PauseConfigs };

class State
{
private:

friend:

	bool mWantToQuit = false;
	bool mWantToChange = false;
	eStates mNextState = eStates::Stay;

public:
	State();
	~State();

	bool WantToQuit() { return mWantToQuit; };
	bool WantToChange() { return mWantToChange; };

	virtual void ProcessEvents();
	virtual void Update(sf::Time dTime);
	virtual void Draw(const std::unique_ptr<sf::RenderWindow>& window);

	virtual void EnterState() = 0;
	virtual eStates NextState() = 0;
	virtual void QuitState() = 0;
};

