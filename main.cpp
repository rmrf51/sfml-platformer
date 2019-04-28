#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include "ImGui/"
// #include "ImGui/imgui.cpp"
// #include "ImGui/imgui_draw.cpp"
// #include "ImGui/imgui-SFML.cpp"
// #include "ImGui/imgui_demo.cpp"

// #include "ImGui/imgui.h"
// #include "ImGui/imgui-sfml.h"

// #include <SFML/Graphics/RenderWindow.hpp>
// #include <SFML/System/Clock.hpp>
// #include <SFML/Window/Event.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    //Время
    Clock clock; 

    // Музыка
    Music music;//создаем объект музыки
    music.openFromFile("music.ogg");//загружаем файл
    music.play();//воспроизводим музыку
    music.setVolume(20);

    Image heroimage;
    heroimage.loadFromFile("image/hero.png");

    Texture herotexture;
    herotexture.loadFromImage(heroimage);

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(0,0,37.5,37.5));//получили нужный нам прямоугольник
    herosprite.setPosition(50,25);

    float CurrentFrame;

    while (window.isOpen())
    {

        //Время
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры, чем больше делитель, тем плавнее игра

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { 
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*1, 37.5, 37.5));             
            herosprite.move(-0.2*time, 0); 
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) { 
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*2, 37.5, 37.5)); 
            herosprite.move(0.2*time, 0); 
        }
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) { 
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*3, 37.5, 37.5)); 
            herosprite.move(0, -0.2*time);
        }
		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { 
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(IntRect(37.5 * int(CurrentFrame), 37.5*0, 37.5, 37.5)); 
            herosprite.move(0, 0.2*time); 
        }

        window.clear();
        // window.draw(shape);
        window.draw(herosprite);
        window.display();

    }

    return 0;
}