//#pragma once
#include "string.h"
#include <iostream>
using namespace std;

#include "SFML/Graphics.hpp"
#include "Engine.h"
#include "Menu.h"
#include "Map.h"
#include "Player.h"
#include "HighScore.h"

using namespace sf;

RenderWindow Engine::window;

void Engine::init()
{
    window.create(VideoMode(1080,920,32), "Pac-Man VS");
}

void Engine::MenuEvents()
{
    MenuSelection=0;
    Menu Me(window.getSize().x, window.getSize().y);
    Event event;
    //Crea pantalla de Menu
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyPressed:
            {
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                {
                    Me.MoveUp();
                }
                break;
                case sf::Keyboard::Down:
                {
                    Me.MoveDown();
                }
                break;
                case sf::Keyboard::Return:
                {
                    switch(Me.GetSelectOption())
                    {
                    case 0://one player
                    {
                        MenuSelection=Me.GetSelectOption();
                        window.close();
                    }
                    break;
                    case 1://two players
                    {
                        MenuSelection=Me.GetSelectOption();
                        window.close();
                    }
                    break;
                    case 2:
                    {
                        MenuSelection=Me.GetSelectOption();
                        window.close();
                    }
                    break;
                    case 3:
                    {
                        exit(1);
                    }
                    break;
                    }
                }
                break;
                }
            }
            break;

            case sf::Event::Closed:
            {
                exit(1);
            }
            break;
            }

        }

        //Limpia la pantalla.
        window.clear();
        //Dibuja el Menu
        Me.Draw(window);
        //hace un refresh de la pantalla
        window.display();

    }

}

void Engine::initGame()
{
    window.create(VideoMode(1280,1024,32),"Pac-Man VS");
}

void Engine::GameEvents()
{
    //CREA EL OBJETO MAPA
    Laberinto mapa;//objeto Mapa.
    //CREA EL OBJETO HIGHSCORE
    highScore obj;
    //if(MenuSelection==0)//ONE PLAYER MOD..... AUN EN PROCESO.


    if(MenuSelection==1)//TWO PLAYERS MOD
    {
        Event e;
        //CREA LOS OBJETOS JUGADORES, SETEA EL NOMBRE Y LA POSICION EN LA QUE SE MUESTRAN.
        Player P1("Jugador 1",1000,400);
        Player P2("Jugador 2",1000,700);
        //Envia la posicion en donde se imprime el Pacman y el color.
        P1.PacManPosyColor(mapa.getPosx('3'),mapa.getPosy('3'),0);
        P2.PacManPosyColor(mapa.getPosx('4'),mapa.getPosy('4'),1);
        while(window.isOpen())
        {
            mapa.setTime();

            if(P1.getScore()+P2.getScore()==348 || mapa.getTime()<=0)
            {
                //Hace la finalizacion del juego
                if(P1.getScore()>P2.getScore())
                {
                    mapa.setWinner(P1.getNombre(),window);
                }
                if(P1.getScore()<P2.getScore())
                {
                    mapa.setWinner(P2.getNombre(),window);
                }
                sleep(sf::seconds(3));
                window.close();
            }
            while(window.pollEvent(e))
            {
                switch(e.type)
                {
                case sf::Event::KeyReleased:
                    switch(e.key.code)
                    {
                    case sf::Keyboard::W:
                    {
                        P1.setDir(1);
                    }
                    break;
                    case sf::Keyboard::A:
                    {
                        P1.setDir(3);
                    }
                    break;
                    case sf::Keyboard::S:
                    {
                        P1.setDir(2);
                    }
                    break;
                    case sf::Keyboard::D:
                    {
                        P1.setDir(4);
                    }
                    break;
                    case sf::Keyboard::Up:
                    {
                        P2.setDir(1);
                    }
                    break;
                    case sf::Keyboard::Down:
                    {
                        P2.setDir(2);
                    }
                    break;
                    case sf::Keyboard::Right:
                    {
                        P2.setDir(4);
                    }
                    break;
                    case sf::Keyboard::Left:
                    {
                        P2.setDir(3);
                    }
                    break;
                    case sf::Keyboard::Escape:
                    {

                        window.close();
                    }
                    break;
                    }
                    break;

                case sf::Event::Closed:
                {
                    exit(1);
                }
                break;
                }
            }

            //Chequeo de colision con la paredes
            //COLISION PLAYER 1
            if(mapa.chequeoColision(P1.getPkman())==1)
            {
                P1.setDir(0);
                P1.colision(+0.5f,0);
            }
            if(mapa.chequeoColision(P1.getPkman())==2)
            {
                P1.setDir(0);
                P1.colision(-0.5f,0);
            }
            if(mapa.chequeoColision(P1.getPkman())==3)
            {
                P1.setDir(0);
                P1.colision(0,+0.5f);
            }
            if(mapa.chequeoColision(P1.getPkman())==4)
            {
                P1.setDir(0);
                P1.colision(0,-0.5f);
            }

            //COLISION PLAYER 2
            if(mapa.chequeoColision(P2.getPkman())==1)
            {
                P2.setDir(0);
                P2.colision(+0.5f,0);
            }
            if(mapa.chequeoColision(P2.getPkman())==2)
            {
                P2.setDir(0);
                P2.colision(-0.5f,0);
            }
            if(mapa.chequeoColision(P2.getPkman())==3)
            {
                P2.setDir(0);
                P2.colision(0,+0.5f);
            }
            if(mapa.chequeoColision(P2.getPkman())==4)
            {
                P2.setDir(0);
                P2.colision(0,-0.5f);
            }

            //MOVIMIENTOS JUGADOR 1
            if(P1.getDir()==1)
            {
                if(P1.getPkman().getGlobalBounds().intersects(P2.getPkman().getGlobalBounds()))
                {
                    P1.setDir(0);
                    P1.colision(0,+0.5f);
                }
                else
                {
                    P1.MoveUp();
                }

            }
            if(P1.getDir()==2)
            {
                if(P1.getPkman().getGlobalBounds().intersects(P2.getPkman().getGlobalBounds()))
                {
                    P1.setDir(0);
                    P1.colision(0,-0.5f);
                }
                else
                {
                    P1.MoveDown();
                }
            }
            if(P1.getDir()==3)
            {
                if(P1.getPkman().getGlobalBounds().intersects(P2.getPkman().getGlobalBounds()))
                {
                    P1.setDir(0);
                    P1.colision(+0.5f,0);
                }
                else
                {
                    P1.MoveLeft();
                }
            }
            if(P1.getDir()==4)
            {
                if(P1.getPkman().getGlobalBounds().intersects(P2.getPkman().getGlobalBounds()))
                {
                    P1.setDir(0);
                    P1.colision(-0.5f,0);
                }
                else
                {
                    P1.MoveRight();
                }

            }
            //MOVIMIENTOS JUGADOR 2

            if(P2.getDir()==1)
            {
                if(P2.getPkman().getGlobalBounds().intersects(P1.getPkman().getGlobalBounds()))
                {
                    P2.setDir(0);
                    P2.colision(0,+0.5f);
                }
                else
                {
                    P2.MoveUp();
                }
            }
            if(P2.getDir()==2)
            {
                if(P2.getPkman().getGlobalBounds().intersects(P1.getPkman().getGlobalBounds()))
                {
                    P2.setDir(0);
                    P2.colision(0,-0.5f);
                }
                else
                {
                    P2.MoveDown();
                }
            }
            if(P2.getDir()==3)
            {
                if(P2.getPkman().getGlobalBounds().intersects(P1.getPkman().getGlobalBounds()))
                {
                    P2.setDir(0);
                    P2.colision(+0.5f,0);
                }
                else
                {
                    P2.MoveLeft();
                }
            }
            if(P2.getDir()==4)
            {
                if(P2.getPkman().getGlobalBounds().intersects(P1.getPkman().getGlobalBounds()))
                {
                    P2.setDir(0);
                    P2.colision(-0.5f,0);
                }
                else
                {
                    P2.MoveRight();
                }
            }
            //TELETRANSPORTACION JUGADOR 1

            if(P1.getPkman().getPosition().x<32 && P1.getPkman().getPosition().y>=410 && P1.getPkman().getPosition().y<=452)
            {
                P1.setPosition(928,416);
            }
            if(P1.getPkman().getPosition().x>928 && P1.getPkman().getPosition().y>=410 && P1.getPkman().getPosition().y<=452)
            {
                P1.setPosition(32,416);
            }

            //TELETRANSPORTACION JUGADOR 2

            if(P2.getPkman().getPosition().x<32 && P2.getPkman().getPosition().y>=410 && P2.getPkman().getPosition().y<=452)
            {
                P2.setPosition(928,416);
            }
            if(P2.getPkman().getPosition().x>928 && P2.getPkman().getPosition().y>=410 && P2.getPkman().getPosition().y<=452)
            {
                P2.setPosition(32,416);
            }

            //Coins y Frutas
            if(P1.getShield()==0 && P2.getShield()==0)
            {
                P1.StopPower();
                P2.StopPower();
                if(mapa.Coins(P1.getPkman()))
                {
                    P1.setScore();
                    P1.playEat();
                }
                if(mapa.Fruits(P1.getPkman()))
                {
                    P1.setShield(1000);
                    P1.playExtraFruit();
                    P1.playPower();
                }
                if(mapa.Coins(P2.getPkman()))
                {
                    P2.setScore();
                    P2.playEat();
                }
                if(mapa.Fruits(P2.getPkman()))
                {
                    P2.setShield(1000);
                    P2.playExtraFruit();
                    P2.playPower();
                }
            }
            if(P1.getShield()>0)
            {
                if(mapa.Coins(P1.getPkman()))
                {
                    P1.setScore();
                    P1.playEat();
                }
                if(mapa.Fruits(P1.getPkman()))
                {
                    P1.setShield(1000);
                }
                P1.setShield(P1.getShield()-1);
            }
            if(P2.getShield()>0)
            {
                if(mapa.Coins(P2.getPkman()))
                {
                    P2.setScore();
                    P2.playEat();
                }
                if(mapa.Fruits(P2.getPkman()))
                {
                    P1.setShield(1000);
                }
                P2.setShield(P2.getShield()-1);
            }


            //limpia pantalla.
            window.clear();
            //Dibuja el mapa con las frutas.
            mapa.Dibuja(window,window.getSize().x,window.getSize().y,mapa.getTime());
            //Dibuja el nombre y las monedas de los players
            P1.MostrarPlayer(window);
            P2.MostrarPlayer(window);
            //refresh de pantalla.
            window.display();
        }
        //GUARDA EL HIGHSCORE
        obj.setJugador(P1.getNombre());
        obj.setScore(P1.getScore());
        obj.guardarHighscore();
        obj.setJugador(P2.getNombre());
        obj.setScore(P2.getScore());
        obj.guardarHighscore();
    }

    if(MenuSelection==2)//Muestra los HIGHSCORES
    {
        Event e;
        while(window.isOpen())
        {

            while(window.pollEvent(e))
            {
                switch(e.type)
                {
                case sf::Event::KeyReleased:
                    switch(e.key.code)
                    {
                    case sf::Keyboard::Escape:
                    {

                        window.close();
                    }
                    break;
                    }
                    break;
                case sf::Event::Closed:
                {
                    exit(1);
                }
                break;
                }
            }


            //LIMPIA PANTALLA
            window.clear(sf::Color::Red);
            //DIBUJA LOS HIHGSCORES
            obj.MostrarHighScores(window);
            //MUESTRA PANTALLA
            window.display();
        }
    }

}


