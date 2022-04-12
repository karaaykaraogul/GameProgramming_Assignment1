#include "AtesNoktasi.hpp"
#include "Pencere.hpp"
#include<iostream>
AtesNoktasi::AtesNoktasi()
{
	aimDirection.setFillColor(sf::Color::White);
	aimDirection.setSize(sf::Vector2f(1.f, 100.f));
	aimDirection.setOrigin(1.f, 100.f);

	shootingPoint.setFillColor(sf::Color::Green);
	shootingPoint.setRadius(10.f);
	shootingPoint.setOrigin(10.f, 10.f);

	aci = 0;
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