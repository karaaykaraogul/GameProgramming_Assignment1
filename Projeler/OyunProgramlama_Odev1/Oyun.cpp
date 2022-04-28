#include "Oyun.hpp"
#include <iostream>
#include "Izgara.hpp"
#include "Top.hpp"
Izgara izgara;
Top top(10.f);
Oyun::Oyun()
{
	m_fps = 60;
	m_cerceveSuresi = sf::seconds(1.0f / m_fps);
	m_devamEdiyormu = true;
	m_atesDerecesi = 90;
}

Oyun::~Oyun()
{
}

void Oyun::setFps(int fps)
{
}
void Oyun::oyunuAyarla(sf::Texture* texture)
{
	top.ayarla(texture);
	izgara.ayarla();
}


void Oyun::oyunuKapat()
{
	m_pencere.kapat();
}
void Oyun::oyunuBaslat(sf::Texture* texture, unsigned int genislik, unsigned int yukseklik)
{
	m_genislik = genislik;
	m_yukseklik = yukseklik;
	m_pencere.olustur(genislik, yukseklik, "Puzzle Bobble");

	oyunuAyarla(texture);

	saatiYenidenBaslat();
	while (m_pencere.acikmi())
	{

		m_pencere.olayKontrol();

		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{
			cizimFonksiyonu(texture);
			saatiYenidenBaslat();
		}
		else
		{
			sf::sleep(m_cerceveSuresi - m_saat.getElapsedTime());
		}

	}
}

void Oyun::cizimFonksiyonu(sf::Texture* texture)
{
	m_pencere.cizimeBasla();



	if (m_devamEdiyormu)
	{
		izgara.ciz(m_pencere);
		m_atesNoktasi.textureEkle(texture);
		m_atesNoktasi.ciz(m_pencere);
		top.cizListe(m_pencere);
		m_atesNoktasi.hareket();
		top.CarpismaKontrolu();
		top.atesEt(m_atesNoktasi,texture);
		if (m_atesNoktasi.aimDirection.getRotation() + 90 > 360) {
			m_atesDerecesi = m_atesNoktasi.aimDirection.getRotation() - 270;
		}
		else {
			m_atesDerecesi = m_atesNoktasi.aimDirection.getRotation() + 90;
		}

	}

	m_pencere.cizimiBitir();
}



void Oyun::saatiYenidenBaslat()
{
	m_saat.restart();
}