#pragma once
#include<sfml/Graphics.hpp>
#include "TemelTurler.hpp"
class Pencere
{
public:
	Pencere();
	void olustur(unsigned int genislik,
		unsigned int yukseklik,
		sf::String baslik);
	void cizimeBasla();
	void cizimiBitir();
	bool acikmi();
	int boyutAlX();
	int boyutAlY();
	void olayKontrol();
	void ciz(sf::Drawable& sekil);
	void tusBasilmaFonksiyonuEkle(KlavyeFonksiyonu yeniFonk);

	void kapat();
private:
	FareHareketFonkListesi	m_fareHareketFonkListesi;
	FareButonFonkListesi	m_fareBasilmaFonkListesi;
	FareButonFonkListesi	m_fareBirakmaFonkListesi;
	KlavyeFonksiyonListesi	m_tusBasmaFonkListesi;
	sf::RenderWindow m_pencere;
};

