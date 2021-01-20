#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Update()
{
}

void Entity::Draw(std::unique_ptr<sf::RenderWindow> window)
{
}

void Entity::SetPosition(sf::Vector2 position)
{

}

sf::Vector2 Entity::GetPosition()
{
	return sf::Vector2(this->mSprite.getPosition());
}

void Entity::Move(sf::Vector2 offset)
{
}
