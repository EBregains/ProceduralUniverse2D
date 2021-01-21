#include "Button.h"

Button::Button(const std::string& label, const sf::Font& font, const sf::Texture& texture) : Entity(texture)
{
	mText.setFont(font);
	mText.setString(sf::String(label));
}

Button::~Button()
{
}

ButtonStatus Button::CheckStatus()
{
	return this->mStatus;
}

void Button::Update()
{
	if (EntityGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition)))
	{
		mStatus = ButtonStatus::HOVERED;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			mStatus = ButtonStatus::PRESSED
	}
	else
		mstatus = ButtonStatus::DISPLAYED;
}
