#include "Map.h"

char Map_Pacman[MaxColumnas][MaxFilas]=
{   "811111111111111111111111111118",
    "812222222222221122222222222218",
    "812111121111121121111121111218",
    "812100121000121121000121001218",
    "812111121111121121111121111218",
    "812222222222222222222222222218",
    "812111121121111111121121111218",
    "812111121121111111121121111218",
    "812222221122221122221122222218",
    "811111121111121121111121111118",
    "812222221111121121111122222218",
    "811111121122222222221121111118",
    "811111121121111111121121111118",
    "D2222222112111111112112222222C",
    "811111122222222222222221111118",
    "812222221121111111121122222218",
    "811111121121111111121121111118",
    "812222222222222222222222222218",
    "812111121121111111121211111218",
    "812111121121111111121211111218",
    "812222222222221122222222222218",
    "812111121111121121111121111218",
    "812111121111121121111121111218",
    "812221122222222222222221122218",
    "811121121121111111121121121118",
    "811121121121111111121121121118",
    "812222221122221122221122222218",
    "812111111111121121111111111218",
    "812111111111121121111111111218",
    "812222222222222222222222222218",
    "811111111111111111111111111118",
};
//CONSTRUCTOR
Laberinto::Laberinto()
{
    srand(time(NULL));
    //Random Pacman 1
    while(a==0)
    {
        int x=0+rand()%28;
        int y=0+rand()%31;
        if(Map_Pacman[x][y]=='2')
        {
            Map_Pacman[x][y]='3';
            a=1;
        }
    }
    a=0;
    //Random Pacman 2
    while(a==0)
    {
        int x=0+rand()%28;
        int y=0+rand()%31;
        if(Map_Pacman[x][y]=='2')
        {
            Map_Pacman[x][y]='4';
            a=1;
        }
    }
    //Random Frutas
    while(a<5)
    {
        int x=0+rand()%28;
        int y=0+rand()%31;
        if(Map_Pacman[x][y]=='2')
        {
            Map_Pacman[x][y]='5';
            a++;
        }
    }
    //Carga Fuente
    if(!font.loadFromFile("Files/Fuente/Escolar_N.TTF"))
    {
        exit(1);
    }
    //Coins
    if(!Blocks.loadFromFile("Files/Map/Modificado.png",sf::IntRect(32,0,32,32))){exit(1);}
    coin.setTexture(Blocks);
    //Rectangulo/wall
    if(!Blocks1.loadFromFile("Files/Map/Wall.png")){exit(1);}
    wall.setTexture(Blocks1);
    //Fruta
    if(!Blocks4.loadFromFile("Files/Map/Modificado.png",sf::IntRect(64,0,32,32))){exit(1);}
    Fruit.setTexture(Blocks4);
    //Muestra Time.
    Tiempo.setFont(font);
    Tiempo.setString("Time: ");
    Tiempo.setCharacterSize(30);
    Tiempo.setColor(sf::Color::White);
    Tiempo.setPosition(1000,150);
    //Muestra Coins Player 1.
    Points1.setFont(font);
    Points1.setString("Coins: ");
    Points1.setCharacterSize(30);
    Points1.setColor(sf::Color::Magenta);
    Points1.setPosition(1000,450);
    //Muestra Coins Player 2.
    Points2.setFont(font);
    Points2.setString("Coins: ");
    Points2.setCharacterSize(30);
    Points2.setColor(sf::Color::Magenta);
    Points2.setPosition(1000,750);
    //Muestra HighScore.
    HighScore.setFont(font);
    HighScore.setString("HighScore: ");
    HighScore.setCharacterSize(30);
    HighScore.setColor(sf::Color::White);
    HighScore.setPosition(1000,50);
    //Setea la posicion del contador de tiempo.
    T.setFont(font);
    T.setCharacterSize(30);
    T.setColor(sf::Color::White);
    T.setPosition(1090,150);
    //Setea la posicion del Ganador.
    Winner.setFont(font);
    Winner.setCharacterSize(60);
    Winner.setColor(sf::Color::White);
    Winner.setPosition(600,550);
    //Muestra el ganador es.
    Win.setFont(font);
    Win.setString("EL GANADOR ES: ");
    Win.setCharacterSize(60);
    Win.setColor(sf::Color::White);
    Win.setPosition(550,500);

    Escape.setFont(font);
    Escape.setString("ESC PARA IR AL MENU");
    Escape.setCharacterSize(25);
    Escape.setColor(sf::Color::Cyan);
    Escape.setPosition(1000,900);

}
//DESTRUCTOR
Laberinto::~Laberinto()
{
     for(int x=0 ; x<40 ; x++)
    {
        for(int y=0 ; y<40 ; y++)
        {
            if(Map_Pacman[y][x]==' ' || Map_Pacman[y][x]=='3' || Map_Pacman[y][x]=='4' || Map_Pacman[y][x]=='5')
            {
                Map_Pacman[y][x]='2';
            }
        }
    }
}
//Muestra quien Gano.
void Laberinto::setWinner(const char *ganador, sf::RenderWindow &window)
{
    Winner.setString(ganador);
    window.draw(Win);
    window.draw(Winner);
    window.display();
}

int Laberinto::getPosx(char num){
    for(int x=1 ; x<40 ; x++)
    {
        for(int y=0 ; y<40 ; y++)
        {
            if(Map_Pacman[y][x]==num)
            {
                return x;
            }
        }
    }
    return 0;
}

int Laberinto::getPosy(char num){
    for(int x=0 ; x<40 ; x++)
    {
        for(int y=0 ; y<40 ; y++)
        {
            if(Map_Pacman[y][x]==num)
            {
                return y;
            }
        }
    }
    return 0;
}

int Laberinto::chequeoColision(sf::Sprite pkman){
    for(int y=0 ; y<40 ; y++)
    {
        for(int x=0 ; x<40 ; x++)
        {
            wall.setPosition(x*32,y*32);
            if(Map_Pacman[y][x]=='1')
            {
                if(pkman.getGlobalBounds().intersects(wall.getGlobalBounds()))
                {
                    if(pkman.getPosition().x>wall.getPosition().x)
                    {
                        return 1;
                    }
                    else if(pkman.getPosition().x<wall.getPosition().x)
                    {
                        return 2;
                    }
                    else if(pkman.getPosition().y>wall.getPosition().y)
                    {
                        return 3;
                    }
                    else if(pkman.getPosition().y<wall.getPosition().y)
                    {
                        return 4;
                    }
                }
            }
        }
    }
    return 0;
}

bool Laberinto::Coins(sf::Sprite pkman){
    for(int x=0 ; x<40 ; x++)
    {
        for(int y=0 ; y<40 ; y++)
        {
            coin.setPosition(x*32,y*32);
            if(Map_Pacman[y][x]=='2' )
            {
                if(pkman.getPosition().x>coin.getPosition().x-25 && pkman.getPosition().x<coin.getPosition().x+30 &&
                   pkman.getPosition().y>coin.getPosition().y-25 && pkman.getPosition().y<coin.getPosition().y+30)
                {
                    Map_Pacman[y][x]=' ';
                    return true;
                }
            }
        }
    }
    return false;
}

bool Laberinto::Fruits(sf::Sprite pkman){
    for(int x=0 ; x<40 ; x++)
    {
        for(int y=0 ; y<40 ; y++)
        {
            Fruit.setPosition(x*32,y*32);
            if(Map_Pacman[y][x]=='5')
            {
                if(pkman.getGlobalBounds().intersects(Fruit.getGlobalBounds()))
                {
                    Map_Pacman[y][x]=' ';
                    return true;
                }
            }
        }
    }
    return false;
}

//Dibuja el mapa con todas las cosas.
void Laberinto::Dibuja(sf::RenderWindow &window,float h, float w, float t)
{
    for(int x=0 ; x<40 ; x++)
    {
        for(int y=0 ; y<40 ; y++)
        {
            if(Map_Pacman[y][x]=='0')
            {
                Mapa.setTextureRect(sf::IntRect(0,0,15,15));
                Mapa.setPosition(x*32,y*32);
                window.draw(Mapa);
            }
            if(Map_Pacman[y][x]=='1')
            {
                wall.setColor(sf::Color::Magenta);
                wall.setPosition(x*32,y*32);
                window.draw(wall);
            }
            if(Map_Pacman[y][x]=='2')
            {
                coin.setPosition(x*32,y*32);
                window.draw(coin);
            }
            if(Map_Pacman[y][x]=='5')
            {
                Fruit.setPosition(x*32,y*32);
                window.draw(Fruit);

            }
        }
    }
    T.setString(s(t/100));
    window.draw(Escape);
    window.draw(Tiempo);
    window.draw(Points1);
    window.draw(Points2);
    window.draw(HighScore);
    window.draw(T);
}

string Laberinto::s(double n){
    stringstream ss;
    ss<<n;
    return ss.str();
}
