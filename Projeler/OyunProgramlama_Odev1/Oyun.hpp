#pragma once
#include "TemelTurler.hpp"
#include "Pencere.hpp"
#include "AtesNoktasi.hpp"
class Oyun
{
public:
	Oyun();
	~Oyun();
	void setFps(int fps);
	void oyunuBaslat(sf::Texture* texture, unsigned int genislik = 600, unsigned int yukseklik = 600);
	void cizimFonksiyonu(sf::Texture* texture);
	void oyunuAyarla(sf::Texture* texture);
	void klavyeBasildi(sf::Keyboard::Key tus);
	void oyunuKapat();

private:

	void saatiYenidenBaslat();

	AtesNoktasi			m_atesNoktasi;

	sf::Time			m_gecenSure;
	sf::Time			m_cerceveSuresi;

	sf::Clock			m_saat;
	Pencere				m_pencere;
	KaplamaHaritasi		m_aracKaplamaListesi;
	int					m_fps;
	FontPtr				m_font;
	int					m_genislik;
	int					m_yukseklik;
	bool				m_devamEdiyormu;

	int					m_atesDerecesi;
};