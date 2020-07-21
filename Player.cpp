#include "Player.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

Player::Player(const char *Name, int x, int y){
    Nombre[30]={0};
    score=0;
    //PacMan 1
    if(!Blocks2.loadFromFile("Files/Map/pacman_map.png",sf::IntRect(140,0,28,28))){exit(1);}
    pkman.setTexture(Blocks2);
    pkman.setOrigin(0,0);
    //SETEO DE FUENTE
    if(!Fuente.loadFromFile("Files/Fuente/Escolar_N.TTF"))
    {
        exit(1);
    }
    //SETEO DE DE LA POSICION DONDE APARECE, TAMAÑO Y COLOR DEL NOMBRE
    PlayerName.setFont(Fuente);
    PlayerName.setString(Name);
    PlayerName.setCharacterSize(30);
    PlayerName.setColor(sf::Color::Cyan);
    PlayerName.setPosition(x,y);

    //SETEO DE DE LA POSICION DONDE APARECE, TAMAÑO Y COLOR DE LAS "COINS"
    coins.setFont(Fuente);
    coins.setCharacterSize(30);
    coins.setColor(sf::Color::Magenta);
    coins.setPosition(x+200,y+50);

    SetNombre(Name);

}

Player::~Player(){

}

void Player::PacManPosyColor(int x, int y,int color){
    pkman.setPosition(x*32,y*32);
    if(color==1){pkman.setColor(sf::Color::Green);}
}

void Player::MostrarPlayer(RenderWindow &window){
    window.draw(pkman);
    coins.setString(s(score));
    window.draw(PlayerName);
    window.draw(coins);

}

void Player::MoveUp(){
    pkman.move(0,-0.5f);
    pkman.setOrigin(28,0);
    pkman.setRotation(270);
}

void Player::MoveDown(){
    pkman.move(0,+0.5f);
    pkman.setOrigin(0,28);
    pkman.setRotation(90);
}

void Player::MoveLeft(){
    pkman.move(-0.5f,0);
    pkman.setOrigin(28,28);
    pkman.setRotation(180);
}

void Player::MoveRight(){
    pkman.move(+0.5f,0);
    pkman.setOrigin(0,0);
    pkman.setRotation(0);
}

//Hace el rebote de la colision
void Player::colision(float x, float y){
    pkman.move(x,y);
}

void Player::playEat(){
    if(!eat.loadFromFile("Files/Sound/dot.wav")){exit(1);}
    collect.setBuffer(eat);
    collect.play();
}

void Player::playExtraFruit(){
    if(!ExtraFruit.openFromFile("Files/Sound/Fruit.ogg")){exit(1);}
    ExtraFruit.play();
}

void Player::playPower(){
    if(!power.openFromFile("Files/Sound/power.wav")){exit(1);}
    power.play();
    power.setLoop(true);
}

void Player::StopPower(){
    power.stop();
}

void Player::setPosition(float x,float y){
    pkman.setPosition(x,y);
}

string Player::s(double n){
    stringstream ss;
    ss<<n;
    return ss.str();
}
