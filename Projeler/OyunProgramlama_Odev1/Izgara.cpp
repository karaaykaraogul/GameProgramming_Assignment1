#include "Izgara.hpp"
#include "Pencere.hpp"
#include<iostream>

Izgara::Izgara()
{
	KarePtr yeniKare = Kare::kareUret(20.f);
	yeniKare->m_konum.x = 10.f;
	yeniKare->m_konum.y = 10.f;
	m_kareler.push_back(yeniKare);
}

void Izgara::ayarla()
{
	for (int i = -10; i < 600; i += 20) {
		for (int j = -10; j < 600; j += 20) {
			KarePtr yeniKare = Kare::kareUret(20.f);
			yeniKare->m_konum.x = j+20.f;
			yeniKare->m_konum.y = i + 20.f;
			m_kareler.push_back(yeniKare);
		}
	}

	for (int i = 0; i < m_kareler.size(); i++) {
		if (i % 5 == 0) {
			m_kareler[i]->m_sekil.setFillColor(sf::Color(50,50,50));
			
		}
		std::cout << m_kareler[i]->m_konum.x << ", "
			<< m_kareler[i]->m_konum.y << std::endl;
	}
	
}
void Izgara::ciz(Pencere& pencere)
{
	
	for (auto siradaki : m_kareler) {
		siradaki->ciz(pencere);
	}
	

}
