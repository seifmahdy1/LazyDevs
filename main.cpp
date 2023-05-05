#include <SFML/Graphics.hpp>
#include <random>
using namespace std;
int main(void){
    int x,y;
    sf::RenderWindow gameWindow(sf::VideoMode(1250, 1250),"Snake" );// creates gameWindow object
    // and from the namespace "sf" gets the VideoMode to initialize the window height and width.
    sf::CircleShape food; // from the namespace "sf" gets the CircleShape class and creates a food object.
    food.setRadius(25.f);// sets the food radius to 25 pixels.
    food.setFillColor(sf::Color::Red); // makes the food color red.
    random_device rand; // creates rand object from the random_device class.
    mt19937 generate(rand()); //mt19937 is an engine that generates random numbers.
    uniform_int_distribution<> xDistance(0,1200);// these two lines create two classes for the coordinates that the food
    // should be spawned in they both use the uniform_int_distribution class and the two objects have a range for the x-coordinates
    // and the y-coordinates
    uniform_int_distribution<> yDistance(0,1200);
    x=xDistance(generate); // these two lines actually generate the numbers that will be used in the setPosition method of the food object.
    y=yDistance(generate);
    food.setPosition(x,y);
    while (gameWindow.isOpen()){ // the next 8 lines are for the gameloop and for the displaying of the food in the randomly generated coordinates.
        sf::Event evnt;
        while (gameWindow.pollEvent(evnt)){
            if (evnt.type==sf::Event::Closed){
                gameWindow.close();
            }
        }
        gameWindow.clear();
        gameWindow.draw(food);
        gameWindow.display();
    }
}
