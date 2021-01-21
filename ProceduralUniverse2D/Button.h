#pragma once
#include "Entity.h"

enum class ButtonStatus
{
    DISPLAYED = 0,
    HOVERED,
    PRESSED
};

class Button :
    public Entity
{
private:

    sf::Vector2i mSize{ 0, 0 };
    sf::Text mText;
    ButtonStatus mStatus{ ButtonStatus::DISPLAYED };

public:

    Button(const std::string& label, const sf::Font& font, const sf::Texture& texture) : Entity(texture);
    virtual ~Button();

    ButtonStatus CheckStatus();
    void Update();

};