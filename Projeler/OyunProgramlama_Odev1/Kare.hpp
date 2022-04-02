#pragma once
#include "Cizilebilir.hpp"
#include "TemelTurler.hpp"
class Kare :public Cizilebilir
{
public:
	Kare(float boyut);
	static std::shared_ptr<Kare> kareUret(float boyut);
	virtual void ciz(Pencere& pencere) override;


	sf::RectangleShape m_sekil;




};
typedef std::shared_ptr<Kare>	KarePtr;
typedef std::vector<KarePtr>	KareListesi;