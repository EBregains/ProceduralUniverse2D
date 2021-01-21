#include "Entity.h"

Entity::Entity(const sf::Texture& texture)
{
	this->mTexture = texture;
	this->mSprite.setTexture(texture);
}

Entity::~Entity()
{
}

void Entity::Update()
{
}

void Entity::Draw(std::unique_ptr<sf::RenderWindow> window)
{
	window->draw(this->mSprite);
}

void Entity::SetPosition(sf::Vector2i position)
{
	this->mSprite.setPosition(sf::Vector2f(position));
}

sf::Vector2 Entity::GetPosition()
{
	return sf::Vector2(this->mSprite.getPosition());
}

sf::FloatRect Entity::EntityGlobalBounds()
{
	return this->mSprite.getGlobalBounds();
}

void Entity::Move(sf::Vector2 offset)
{
	this->mSprite.move(sf::Vector2f(offset));
}
