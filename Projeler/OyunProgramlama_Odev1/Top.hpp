#pragma once
#include "Cizilebilir.hpp"
#include "TemelTurler.hpp"
#include "AtesNoktasi.hpp"
class Top :public Cizilebilir
{
public:
	Top(float boyut);
	Top topUret(AtesNoktasi& atesNoktasi);
	virtual void ciz(Pencere& pencere) override;
	virtual void cizListe(Pencere& pencere);
	void atesEt(AtesNoktasi& atesNoktasi);
	void CarpismaKontrolu();
	int degenTopBul(int aramaTopu);
	std::vector<Top> toplar;
	std::vector<Top> baglanabilirToplar;
	std::vector<Top> siradakiToplar;
	float hiz;
	sf::Vector2f yon;

	bool hareketEtmisTop;

	sf::CircleShape m_sekil;
	void ayarla();



};