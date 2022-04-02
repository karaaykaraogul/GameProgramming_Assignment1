#include "Kare.hpp"
#include "Pencere.hpp"
Kare::Kare(float boyut)
{
	m_sekil.setOrigin(boyut / 2, boyut / 2);
	m_sekil.setSize(sf::Vector2f(boyut, boyut));
	m_sekil.setOutlineThickness(1);
	m_sekil.setOutlineColor(sf::Color(125,125,125));
	m_sekil.setFillColor(sf::Color::Transparent);
}

KarePtr Kare::kareUret(float boyut)
{
	return std::make_shared<Kare>(boyut);
}


void Kare::ciz(Pencere& pencere)
{
	m_sekil.setPosition(m_konum);

	pencere.ciz(m_sekil);
}
