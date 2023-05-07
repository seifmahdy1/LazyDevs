#pragma once
#include <SFML/Graphics.hpp>
#include <random>

using namespace std;

class Food {
private:
    int x;
    int y;
    int grid_size;
    float radius;
public:
    Food(int grid_size) : grid_size(grid_size) {
        std::random_device rand;
        std::mt19937 generate(rand());
        std::uniform_int_distribution<> distanceX(0, grid_size - 50);
        std::uniform_int_distribution<> distanceY(0, grid_size - 50);
        x = distanceX(generate);
        y = distanceY(generate);
    }
    float getRadius() {
        return radius;
    }
    int getFoodX() {
        return x;
    }
    int getFoodY() {
        return y;
    }
    void setRadius(float radius1) {
        radius = radius1;
    }
};

class snakePart {
public:
    int posX;
    int posY;
    int direction;
    sf::Sprite* s; //this is how the snake looks
    class node* leftLink; //this is implementation of the linked list data structure
    class node* rightLink;
};
typedef class snakePart* SNAKEPART;
enum direction {
    north, south, west, east
};
//this is to set each of the directions with a number so we can then put it in the class snakePart in the part called direction 
// where north=0, south =1, west =2, east =3 
class Game {
private:
    void updateGame(); //function that updates the gmae contents
    void renderGame();//function that renders the game
    SNAKEPART insertHead(SNAKEPART head, sf::Sprite* sprite);
    SNAKEPART deleteTail(SNAKEPART tail);
public:
    void runGame();//the function that runs the game
};
