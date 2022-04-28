#pragma once
#include "Cizilebilir.hpp"
#include "TemelTurler.hpp"
#include "AtesNoktasi.hpp"
#include "Animasyon.hpp"

class Top :public Cizilebilir
{
public:
	Top(float boyut);
	Top topUret(AtesNoktasi& atesNoktasi, sf::Texture* texture);
	virtual void ciz(Pencere& pencere) override;
	virtual void cizListe(Pencere& pencere);
	void atesEt(AtesNoktasi& atesNoktasi, sf::Texture* texture);
	void CarpismaKontrolu();
	int degenTopBul(int aramaTopu);
	std::vector<Top> toplar;
	std::vector<Top> baglanabilirToplar;
	std::vector<Top> siradakiToplar;
	float hiz;
	sf::Vector2f yon;
	Animasyon anim;
	sf::Texture* texture;

	bool hareketEtmisTop;

	sf::CircleShape m_sekil;
	void ayarla(sf::Texture* texture);
	virtual void animliCiz(Pencere& pencere);
	void topSil(int sira);

};