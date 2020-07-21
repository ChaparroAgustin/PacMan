#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "time.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#define MaxFilas 40 //eje y
#define MaxColumnas 40//eje x
#include "Player.h"

using namespace std;



class Laberinto{
    private:
        sf::Texture Blocks;
        sf::Texture Blocks1;
        sf::Texture Blocks4;
        sf::Sprite Mapa;
        sf::Font font;
        sf::Sprite coin;
        sf::Sprite Fruit;
        sf::Sprite wall;
        sf::Text Tiempo;
        sf::Text Points1;
        sf::Text Points2;
        sf::Text HighScore;
        sf::Text T;
        sf::Text Winner;
        sf::Text Win;
        sf::Text PlayerName;
        sf::Text Escape;
        char temporizador[10];
        int a=0,dir1=4,dir2=4;
        int t=18000;
    public:
        Laberinto();
        ~Laberinto();
        void Dibuja(sf::RenderWindow &window,float h, float w,float t);
        void setWinner(const char *ganador,sf::RenderWindow &window);
        int getPosx(char num);
        int getPosy(char num);
        int chequeoColision(sf::Sprite pkman);
        bool Fruits(sf::Sprite pkman);
        bool Coins(sf::Sprite pkman);
        void setTime(){t--;}
        int getTime(){return t;}
        string s(double n);
};

#endif // MAP_H_INCLUDED

