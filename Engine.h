#include "SFML/Graphics.hpp"



class Engine{
    private:
        static sf::RenderWindow window;
        int MenuSelection;
    public:
        void MenuEvents();
        void init();
        void initGame();
        void GameEvents();
} ;



