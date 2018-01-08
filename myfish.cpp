#include <SFML/Graphics.hpp>
#include <iostream>


class CharacterFish
{
 private:
  sf:: Vector2f pos; 
  sf:: Texture texture;
  sf:: Sprite fish; 

 public:
  //creating sprite
  CharacterFish()//(const sf::Vector2f& pos)
  {
    texture.loadFromFile("images/fish1.png");
    fish = sf::Sprite(texture);
    fish.setScale(sf::Vector2f(0.1f,0.1F));
  }
  //function to draw sprite
  void Draw(sf::RenderTarget& rt)
  {
    rt.draw(fish);
  }
  float getPositionX(float positionX)
  {
    return positionX;

  }
  float getPositionY(float positionY)
  {
    return positionY;
  }


};

int numFish = 5;
int width = 600;
int height = 600;
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    CharacterFish fish[numFish];
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

	// input
	for (int i=0;i<numFish;i++)
           {
	     float positionX = rand() % width ;
	     float positionY =rand() %height;
	     if (positionX> (width-(width*0.1)))
	       {
		 positionX = rand() % width ;
	       }
	     if (positionY>(height -(height *0.1)))
	       {
		 positionY = rand() % height ;
	       }
	    

	       fish[i].getPositionX(positionX);
	     
	   } 

        window.clear();
	// CarackterFish drawwing the sprite
	//	fish.Draw(window);
	for (int i=0;i<numFish;i++){
	   	fish[i].Draw(window);
	  //	window.draw(fish[i]);
	}
        window.display();
    }

    return 0;
}
