#pragma once

#include "Cizilebilir.hpp"
#include<SFML/Graphics.hpp>
#include"Kare.hpp"

class Izgara :public Cizilebilir
{
public:
	Izgara();

	void ayarla();

	// Inherited via Cizilebilir
	virtual void ciz(Pencere& pencere) override;

	sf::RectangleShape m_dortgen;


	KareListesi m_kareler;
};
