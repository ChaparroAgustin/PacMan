#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


class Menu{
    private:
        sf::Music music;
        sf::Font font;
        sf::Text text[4];
        sf::Texture texture_back;
        sf::Sprite background;
        int SelectOpcion;

    public:
        Menu(float w,float h);
        ~Menu();
        void Draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetSelectOption(){return SelectOpcion;}

};


#endif // MENU_H_INCLUDED

