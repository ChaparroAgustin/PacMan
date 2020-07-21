#include "HighScore.h"
#include <wchar.h>

highScore::highScore()
{

    //Carga Fuente
    if(!font.loadFromFile("Files/Fuente/Escolar_N.TTF"))
    {
        exit(1);
    }
    //TEXTOS NOMBRES

    Nombres[0].setFont(font);
    Nombres[0].setCharacterSize(25);
    Nombres[0].setColor(sf::Color::White);
    Nombres[0].setPosition(1280/3,110);

    Nombres[1].setFont(font);
    Nombres[1].setCharacterSize(25);
    Nombres[1].setColor(sf::Color::White);
    Nombres[1].setPosition(1280/3,220);

    Nombres[2].setFont(font);
    Nombres[2].setCharacterSize(25);
    Nombres[2].setColor(sf::Color::White);
    Nombres[2].setPosition(1280/3,330);

    Nombres[3].setFont(font);
    Nombres[3].setCharacterSize(25);
    Nombres[3].setColor(sf::Color::White);
    Nombres[3].setPosition(1280/3,440);

    Nombres[4].setFont(font);
    Nombres[4].setCharacterSize(25);
    Nombres[4].setColor(sf::Color::White);
    Nombres[4].setPosition(1280/3,550);

    Nombres[5].setFont(font);
    Nombres[5].setCharacterSize(25);
    Nombres[5].setColor(sf::Color::White);
    Nombres[5].setPosition(1280/3,660);

    Nombres[6].setFont(font);
    Nombres[6].setCharacterSize(25);
    Nombres[6].setColor(sf::Color::White);
    Nombres[6].setPosition(1280/3,770);

    Nombres[7].setFont(font);
    Nombres[7].setCharacterSize(25);
    Nombres[7].setColor(sf::Color::White);
    Nombres[7].setPosition(1280/3,880);

    Nombres[8].setFont(font);
    Nombres[8].setCharacterSize(25);
    Nombres[8].setColor(sf::Color::White);
    Nombres[8].setPosition(1280/3,990);

    Nombres[9].setFont(font);
    Nombres[9].setCharacterSize(25);
    Nombres[9].setColor(sf::Color::White);
    Nombres[9].setPosition(1280/3,1100);

    //TEXTOS SCORES
    scores[0].setFont(font);
    scores[0].setCharacterSize(25);
    scores[0].setColor(sf::Color::Cyan);
    scores[0].setPosition(1280/2,110);

    scores[1].setFont(font);
    scores[1].setCharacterSize(25);
    scores[1].setColor(sf::Color::Cyan);
    scores[1].setPosition(1280/2,220);

    scores[2].setFont(font);
    scores[2].setCharacterSize(25);
    scores[2].setColor(sf::Color::Cyan);
    scores[2].setPosition(1280/2,330);

    scores[3].setFont(font);
    scores[3].setCharacterSize(25);
    scores[3].setColor(sf::Color::Cyan);
    scores[3].setPosition(1280/2,440);

    scores[4].setFont(font);
    scores[4].setCharacterSize(25);
    scores[4].setColor(sf::Color::Cyan);
    scores[4].setPosition(1280/2,550);

    scores[5].setFont(font);
    scores[5].setCharacterSize(25);
    scores[5].setColor(sf::Color::Cyan);
    scores[5].setPosition(1280/2,660);

    scores[6].setFont(font);
    scores[6].setCharacterSize(25);
    scores[6].setColor(sf::Color::Cyan);
    scores[6].setPosition(1280/2,770);

    scores[7].setFont(font);
    scores[7].setCharacterSize(25);
    scores[7].setColor(sf::Color::Cyan);
    scores[7].setPosition(1280/2,880);

    scores[8].setFont(font);
    scores[8].setCharacterSize(25);
    scores[8].setColor(sf::Color::Cyan);
    scores[8].setPosition(1280/2,990);

    scores[9].setFont(font);
    scores[9].setCharacterSize(25);
    scores[9].setColor(sf::Color::Cyan);
    scores[9].setPosition(1280/2,1100);


}

void highScore::OrdenarScores(highScore *obj)
{
    int auxscore;
    char auxjugador[30];
    for(int x=0; x<10; x++)
    {
        for(int y=0; y<9; y++)
        {
            if(obj[x].getScore()<obj[x+1].getScore())
            {
                strcpy(auxjugador,obj[x].getJugador());
                obj[x].setJugador(obj[x+1].getJugador());
                obj[x+1].setJugador(auxjugador);
                auxscore=obj[x].getScore();
                obj[x].setScore(obj[x+1].getScore());
                obj[x+1].setScore(auxscore);
            }
        }
    }
}

void highScore::guardarHighscore()
{

}

void highScore::creaciondearchivo(){
    FILE *p;
    p=fopen(PATH_HIGHSCORES,"ab");
    if(p==NULL){return;}
    fclose(p);
}


bool highScore::LeerHighscore(int pos)
{
    FILE *p;
    p=fopen(PATH_HIGHSCORES,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(highScore)*pos,SEEK_SET);
    bool leyo=fread(this,sizeof(highScore),1,p);
    fclose(p);
    return leyo;
}

void highScore::MostrarHighScores(sf::RenderWindow &window)
{

    for(int x=0; x<10; x++)
    {
        Nombres[x].setString(Jugador);
        scores[x].setString(s(score));
        window.draw(Nombres[x]);
        window.draw(scores[x]);
    }
}

highScore::~highScore()
{

}

string highScore::s(double n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}

