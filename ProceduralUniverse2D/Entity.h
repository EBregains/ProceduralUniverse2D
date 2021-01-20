#pragma once
#include "SFML\Graphics.hpp"

class Entity
{
private:

	/// <summary>
	/// Entity Sprite.
	/// </summary>
	sf::Sprite mSprite;
	/// <summary>
	/// Entity Texture.
	/// </summary>
	sf::Texture mTexture;

public:

	/// <summary>
	/// Constructor.
	/// </summary>
	Entity();
	/// <summary>
	/// Destructor.
	/// </summary>
	virtual ~Entity();

	/// <summary>
	/// Update the entity status
	/// </summary>
	virtual void Update();

	/// <summary>
	/// Draw the Entity Sprite data member at certain windows.
	/// </summary>
	/// <param name="window"> Targeted window</param>
	virtual void Draw(std::unique_ptr<sf::RenderWindow> window);

	/// <summary>
	/// Set the data member Sprite at certain position.
	/// </summary>
	/// <param name="position"> New position. </param>
	virtual void SetPosition(sf::Vector2 position);

	/// <summary>
	/// Get the current Entitys Sprite position.
	/// </summary>
	/// <returns> Sprite data member position. </returns>
	virtual sf::Vector2 GetPosition();

	/// <summary>
	/// Move the sprite relatively to the current position.
	/// </summary>
	/// <param name="offset"> Decired offset. </param>
	virtual void Move(sf::Vector2 offset);

};

