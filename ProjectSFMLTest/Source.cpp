#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
   sf::CircleShape shape(100.0f);
   shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
         {
            // left key is pressed: move our character
            std::cout << "MORE"<<"\n";
         }

         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
         {
            // left mouse button is pressed: shoot
            std::cout << "MORE" << "\n";
            shape.setFillColor(sf::Color::Yellow);
         }
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	return 0;
}
