#pragma once
#include "Cizilebilir.hpp"
#include "TemelTurler.hpp"
class AtesNoktasi :public Cizilebilir
{
public:
	AtesNoktasi();
	virtual void ciz(Pencere& pencere) override;
	void hareket();

	sf::RectangleShape aimDirection;

	sf::CircleShape shootingPoint;

};