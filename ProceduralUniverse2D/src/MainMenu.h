#pragma once
#include "State.h"
#include "Button.h"

class MainMenu :
    public State
{
private:

    /// <summary>
    /// Sprite that holds the main menu bakground image.
    /// </summary>
    sf::Sprite spriteBackground;
    /// <summary>
    /// Backround image.
    /// </summary>
    sf::Texture textureBackground;

    /// <summary>
    /// Cointainer that holds all of the buttons in the main menu.
    /// </summary>
    std::vector<Button> buttons;

public:

    /// <summary>
    /// Constructor.
    /// </summary>
    MainMenu();
    /// </summary>
    /// Destructor
    /// </summary>
    ~MainMenu();

    /// <summary>
    /// Update de main menu State.
    /// </summary>
    /// <param name="dTime"> Time elapsed between frames. </param>
    void Update(sf::Time dTime);

    /// <summary>
    /// Draw all the Entitys in the main menu.
    /// </summary>
    /// <param name="window"> Target window. </param>
    void Draw(const std::unique_ptr<sf::RenderWindow>& window);

};

