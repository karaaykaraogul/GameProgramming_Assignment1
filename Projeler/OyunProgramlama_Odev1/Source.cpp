#include "Oyun.hpp"

int main()
{
	Oyun oyun;
	oyun.oyunuBaslat();
}

//#include<iostream>
//#include<SFML/Graphics.hpp>
//#include<SFML/Window.hpp>
//#include<SFML/System.hpp>
//
//using namespace sf;
//
//int main() 
//{
//	float cerceveSuresi = 1.0f / 60.0f;
//
//	sf::RenderWindow pencere(sf::VideoMode(600, 600), "Merhaba");
//	//ateþ edilecek açýyý göstermekte yardýmcý olan dikdörtgen tanýmlanýr
//	sf::RectangleShape aimDirection;
//	aimDirection.setFillColor(sf::Color::White);
//	aimDirection.setSize(sf::Vector2f(1.f, 100.f));
//	aimDirection.setOrigin(1.f, 100.f);
//	//ateþ eden ana kaynaðý tanýmlar
//	CircleShape shootingPoint;
//	shootingPoint.setFillColor(Color::Green);
//	shootingPoint.setRadius(10.f);
//	shootingPoint.setOrigin(10.f, 10.f);
//
//	aimDirection.setPosition(pencere.getSize().x / 2.f, pencere.getSize().y / 2.f);
//	shootingPoint.setPosition(pencere.getSize().x / 2.f, pencere.getSize().y / 2.f);
//
//
//
//	Clock saat;
//	while (pencere.isOpen())
//	{
//		sf::Event olay;
//
//		while (pencere.pollEvent(olay))
//		{
//			if (olay.type == sf::Event::Closed)
//			{
//				pencere.close();
//			}
//			if (olay.type == sf::Event::Resized)
//			{
//				sf::View view = sf::View(sf::Vector2f(olay.size.width / 2, olay.size.height / 2),
//					sf::Vector2f(olay.size.width, olay.size.height));
//				
//				pencere.setView(view);
//			}
//		}
//
//		
//
//		if (saat.getElapsedTime().asSeconds() >= cerceveSuresi)
//		{
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//				aimDirection.rotate(-10.f);
//				shootingPoint.rotate(-10.f);
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//				aimDirection.rotate(10.f);
//				shootingPoint.rotate(10.f);
//			}
//
//
//			int fps = 1.0f / saat.getElapsedTime().asSeconds();
//			//std:: cout << fps << std :: endl;
//
//			pencere.clear();
//
//			pencere.draw(shootingPoint);
//			pencere.draw(aimDirection);
//
//			pencere.display();
//
//			saat.restart();
//		}
//		else
//		{
//			sf::sleep(sf::seconds(cerceveSuresi) - saat.getElapsedTime());
//		}
//
//
//	}
//}