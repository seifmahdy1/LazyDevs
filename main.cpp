#include <vector>
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include <iostream>
using namespace std;
using namespace sf;
int pagenumber = 1000;
int main(void){
    RenderWindow window(VideoMode(1920,1080),"GameBox");
     Menu menu(1920,1080);
     Texture mainmenubg;
     mainmenubg.loadFromFile("/Users/seifmahdy/CLionProjects/GameBox/fotor_2023-5-7_16_34_19.png");// photo will
     //be uploaded on github.
     Sprite bg;
     bg.setTexture(mainmenubg);
    // 1000  main menu
    //-1 close
    //0 entername page
    // 1 credits
    // 2 choose game menu
    string name,cname;
    void playerName(RenderWindow& window, string& name);
    void creditsName(RenderWindow& window);
     while (true){
         if (pagenumber==1000){
             while(window.isOpen()){
                 Event evnt;
                 while(window.pollEvent(evnt)) {
                     if (evnt.type == Event::Closed) {
                         window.close();
                         break;
                     }
                     if (evnt.type==Event::KeyPressed) {
                         if (evnt.key.code == Keyboard::Up) {
                             menu.moveUp();
                         }
                         if (evnt.key.code == Keyboard::Down) {
                             menu.moveDown();
                         }
                         if (evnt.key.code == Keyboard::Enter){
                             if (menu.pressed()==0){
                                 pagenumber=0;
                             }
                             if (menu.pressed()==1){
                                 pagenumber=1;
                             }
                             if (menu.pressed()==2){
                                 pagenumber=-1;
                             }
                         }
                     }
                 }
                 window.clear();
                 if (pagenumber!=1000){
                     break;
                 }
                 window.draw(bg);
                 menu.draw(window);
                 window.display();
             }
             if (pagenumber==-1) {
                 window.close();
                 break;
             }
             if (pagenumber==0){
                 playerName(window,name);
             }
             if (pagenumber==1){
                 creditsName(window);
             }

         }
     }
}
void playerName(RenderWindow& window, string& name){
    if (!name.empty()){
        name.clear();
    }
    Texture background;
    background.loadFromFile("/Users/seifmahdy/CLionProjects/GameBox/coma_star_cluster_coma_berenices_constellation_891324_1920x1080.jpg");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("/Users/seifmahdy/CLionProjects/GameBox/PixeloidMono-d94EV.ttf" );
    Text t1;
    Text t2;
    t1.setFont(font);
    t2.setFont(font);
    t1.setString("Enter your name: ");
    t1.setCharacterSize(100);
    t2.setCharacterSize(100);
    t1.setPosition(460,190);
    t2.setPosition(600,330);
    t1.setFillColor(Color::White);
    t2.setFillColor(Color{100,50,160});
    while(window.isOpen()){
        Event evnt;
        while(window.pollEvent(evnt)) {
            if (evnt.type == Event::Closed) {
                window.close();
            }
           if (evnt.type==Event::TextEntered){
                name+=static_cast<char>(evnt.text.unicode);// adds the characters of the name character by character
                //to the empty string.
           }
           if (Keyboard::isKeyPressed(Keyboard::Backspace) && name.size()>0 ){ //erases characters if backspace is pressed
               // and if the size of the name is more than 0.
                name.resize(name.size()-1);
           }

           if (Keyboard::isKeyPressed(Keyboard::Enter) && name.size() >= 1){
               pagenumber=2;
               return;
           }
           if (Keyboard::isKeyPressed(Keyboard::Escape)) {
               pagenumber = 1000;
               return;
           }
        }
        t2.setString(name);
        window.clear();
        window.draw(bg);
        window.draw(t1);
        window.draw(t2);
        window.display();
    }
}
void creditsName(RenderWindow& window){
    Texture background;
    background.loadFromFile("/Users/seifmahdy/CLionProjects/GameBox/coma_star_cluster_coma_berenices_constellation_891324_1920x1080.jpg");
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("/Users/seifmahdy/CLionProjects/GameBox/PixeloidMono-d94EV.ttf" );
    Text t1;
    Text t2;
    Text t3;
    Text t4;
    t1.setFont(font);
    t2.setFont(font);
    t3.setFont(font);
    t4.setFont(font);
    t1.setString("Created By");
    t2.setString("Seif El Din Mahdy");
    t3.setString("Youssef El Bashaar");
    t4.setString("Seif Mohamed");
    t1.setCharacterSize(60);
    t2.setCharacterSize(75);
    t3.setCharacterSize(75);
    t4.setCharacterSize(75);
    t1.setPosition(750,190);
    t2.setPosition(520,380);
    t3.setPosition(520, 540);
    t4.setPosition(520,700);
    t1.setFillColor({Color{19,168,163}});
    t2.setFillColor(Color::White);
    t3.setFillColor(Color::White);
    t4.setFillColor(Color::White);
    while(window.isOpen()){
        Event evnt;
        while(window.pollEvent(evnt)) {
            if (evnt.type == Event::Closed) {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                pagenumber = 1000;
                return;
            }
        window.clear();
        window.draw(bg);
        window.draw(t1);
        window.draw(t2);
        window.draw(t3);
        window.draw(t4);
        window.display();
    }
}
}