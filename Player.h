#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "string.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace std;
using namespace sf;

class Player{
    private:
        sf::Texture Blocks2;
        sf::Sprite pkman;
        Font Fuente;
        Text PlayerName;
        Text coins;
        SoundBuffer eat;
        Sound collect;
        Music power;
        Music ExtraFruit;
        int score=0;
        char Nombre[30]="0";
        char monedas[5]="0";
        int Dir;
        int shield=0;
    public:
        Player();
        Player(const char *Name,int x, int y);
        ~Player();
        void setScore(){score+=1;}
        int getScore(){return score;}
        void SetNombre(const char *nickname){strcpy(Nombre,nickname);}
        char *getNombre(){return Nombre;}
        void setDir(int dir){Dir=dir;}
        int getDir(){return Dir;}
        void setPosition(float x, float y);
        void playEat();
        void playPower();
        void playExtraFruit();
        void StopPower();
        void MostrarPlayer(RenderWindow &window);
        void PacManPosyColor(int x, int y, int color);
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
        FloatRect globalBounds(){return pkman.getGlobalBounds();}
        Sprite getPkman(){return pkman;}
        void colision(float x, float y);
        void setShield(int s){shield=s;}
        int getShield(){return shield;}
        string s(double n);
};







#endif // PLAYER_H_INCLUDED
