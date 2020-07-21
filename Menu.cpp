#include "Menu.h"


Menu::Menu(float w,float h){
    if(!font.loadFromFile("Files/Fuente/Escolar_N.TTF")){exit(1);}
    if(!texture_back.loadFromFile("Files/Background/PacMan-Neon.png.png")){exit(1);}
    background.setTexture(texture_back);
    if(!music.openFromFile("Files/Sound/Intro.ogg")){exit(1);}
    //music.play();
    music.setLoop(true);

    text[0].setColor(sf::Color::Red);
    text[0].setFont(font);
    text[0].setString("One Player");
    text[0].setPosition(sf::Vector2f(w/4,h/4));

    text[1].setColor(sf::Color::White);
    text[1].setFont(font);
    text[1].setString("Two Players");
    text[1].setPosition(sf::Vector2f(w/4,(h/5)*2));

    text[2].setColor(sf::Color::White);
    text[2].setFont(font);
    text[2].setString("HighScores");
    text[2].setPosition(sf::Vector2f(w/4,(h/5)*3));

    text[3].setColor(sf::Color::White);
    text[3].setFont(font);
    text[3].setString("Exit");
    text[3].setPosition(sf::Vector2f(w/4,(h/6)*4.7));

    SelectOpcion=0;
}


Menu::~Menu(){
}

void Menu::Draw(sf::RenderWindow& window){

    window.draw(background);
    for(int x=0;x<4;x++){
    window.draw(text[x]);
    }
}

void Menu::MoveUp(){

    if(SelectOpcion-1 >=0){
        text[SelectOpcion].setColor(sf::Color::White);
        SelectOpcion--;
        text[SelectOpcion].setColor(sf::Color::Red);
        }

}

void Menu::MoveDown(){

    if(SelectOpcion+1 <4){
        text[SelectOpcion].setColor(sf::Color::White);
        SelectOpcion++;
        text[SelectOpcion].setColor(sf::Color::Red);
        }

}

