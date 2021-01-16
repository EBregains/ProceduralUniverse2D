#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class ProceduralUniverse
{
private:
	sf::Vector2i mSize{ 0, 0 };
	sf::Vector2i mOffset{ 0, 0 };
	std::vector<bool> mIsThereASolarSystem{};

public:

	// Constructor -------------------------------------------------
	ProceduralUniverse();
	~ProceduralUniverse();

	// Bucle -------------------------------------------------------
	void ProcessEvents();
	void Update(sf::Time dTime);
	void Draw(const std::unique_ptr<sf::RenderWindow>& window);

};

