#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;



class highScore{
    private:
        const char *PATH_HIGHSCORES = "hihgscore.dat";
        sf::Font font;
        sf::Text scores[10];
        sf:: Text Nombres[10];
        char Jugador[30]="Vacio";
        int score=0;
    public:
        highScore();
        ~highScore();
        int getScore(){return score;}
        void setScore(int SCR){score=SCR;}
        char *getJugador(){return Jugador;}
        void setJugador(char *name){strcpy(Jugador,name);}
        void guardarHighscore();
        bool LeerHighscore(int pos);
        void MostrarHighScores(sf::RenderWindow &window);
        string s(double n);
        void OrdenarScores(highScore *obj);
        void creaciondearchivo();
};



#endif // HIGHSCORE_H_INCLUDED
