#include "AtesNoktasi.hpp"
#include "Pencere.hpp"
#include<iostream>
AtesNoktasi::AtesNoktasi()
{
	aimDirection.setFillColor(sf::Color::Transparent);
	aimDirection.setSize(sf::Vector2f(1.f, 100.f));
	aimDirection.setOrigin(1.f, 100.f);

	shootingPoint.setFillColor(sf::Color::Green);
	shootingPoint.setRadius(10.f);
	shootingPoint.setOrigin(10.f, 15.f);

	aci = 0;
}

void AtesNoktasi::textureEkle(sf::Texture* texture)
{
	shootingPoint.setTexture(texture);
	shootingPoint.setTextureRect(sf::IntRect(sf::Vector2i(1,1545),sf::Vector2i(64,64)));
	shootingPoint.setScale(5, 5);
}

void AtesNoktasi::hareket()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (aci > -80.f)
		{
			aimDirection.rotate(-2.f);
			shootingPoint.rotate(-2.f);
			aci -= 2.f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (aci < 80.f)
		{
			aimDirection.rotate(2.f);
			shootingPoint.rotate(2.f);
			aci += 2.f;
		}
	}
}

void AtesNoktasi::ciz(Pencere& pencere)
{
	aimDirection.setPosition(pencere.boyutAlX() / 2.f, pencere.boyutAlY() - 10);
	shootingPoint.setPosition(pencere.boyutAlX() / 2.f, pencere.boyutAlY() - 10);


	pencere.ciz(aimDirection);
	pencere.ciz(shootingPoint);
}