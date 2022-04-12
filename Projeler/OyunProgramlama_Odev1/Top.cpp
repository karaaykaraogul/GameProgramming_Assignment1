#define _USE_MATH_DEFINES
#include "Top.hpp"
#include "Pencere.hpp"
#include "AtesNoktasi.hpp"
#include<vector>
#include<iostream>
#include<cmath>

Top::Top(float boyut)
{
	m_sekil.setOrigin(boyut, boyut);
	m_sekil.setRadius(boyut);
	m_sekil.setOutlineThickness(1);
	m_sekil.setOutlineColor(sf::Color::White);
	m_sekil.setFillColor(sf::Color::Red);
}


void Top::ayarla()
{
	int satir = 0;
	for (int i = -10; i < 300; i += 20) {
		for (int j = -10; j < 600; j += 40) {
			Top yeniTop(10.f);
			if (satir % 2 == 0) {
				yeniTop.m_konum.x = j + 20.f;
				yeniTop.m_konum.y = i + 20.f;
			}
			else {
				yeniTop.m_konum.x = j + 40.f;
				yeniTop.m_konum.y = i + 20.f;
			}
			int random = rand() % 5;
			switch (random) {
			case 0:
				yeniTop.m_sekil.setFillColor(sf::Color::Red);
				break;
			case 1:
				yeniTop.m_sekil.setFillColor(sf::Color::Blue);
				break;
			case 2:
				yeniTop.m_sekil.setFillColor(sf::Color::Green);
				break;
			case 3:
				yeniTop.m_sekil.setFillColor(sf::Color::Yellow);
				break;
			case 4:
				yeniTop.m_sekil.setFillColor(sf::Color::Magenta);
				break;
			case 5:
				yeniTop.m_sekil.setFillColor(sf::Color::White);
				break;
			}
			toplar.push_back(yeniTop);
		}
		satir++;
	}
	for (int i = -10; i < 600; i += 20) {
		for (int j = -10; j < 600; j += 20) {
			Top baglanabilirTop(10.f);
			baglanabilirTop.m_sekil.setFillColor(sf::Color::Transparent);
			baglanabilirTop.m_sekil.setOutlineThickness(0);
			baglanabilirTop.m_konum.x = j + 20.f;
			baglanabilirTop.m_konum.y = i + 20.f;

			baglanabilirToplar.push_back(baglanabilirTop);
		}
	}

}

Top Top::topUret(AtesNoktasi& atesNoktasi) {
	Top yeniTop(10.f);

	yeniTop.m_konum = atesNoktasi.aimDirection.getPosition();
	yeniTop.m_sekil.setPosition(atesNoktasi.aimDirection.getPosition());

	yeniTop.hiz = 10.0f;
	yeniTop.m_sekil.setRotation(atesNoktasi.aimDirection.getRotation());

	yeniTop.m_sekil.setOutlineThickness(1);

	yeniTop.hareketEtmisTop = true;

	int random = rand() % 5;
	switch (random) {
	case 0:
		yeniTop.m_sekil.setFillColor(sf::Color::Red);
		break;
	case 1:
		yeniTop.m_sekil.setFillColor(sf::Color::Blue);
		break;
	case 2:
		yeniTop.m_sekil.setFillColor(sf::Color::Green);
		break;
	case 3:
		yeniTop.m_sekil.setFillColor(sf::Color::Yellow);
		break;
	case 4:
		yeniTop.m_sekil.setFillColor(sf::Color::Magenta);
		break;
	case 5:
		yeniTop.m_sekil.setFillColor(sf::Color::White);
		break;
	}
	return yeniTop;
}

bool isFirst = true;
bool carpisma = false;
Top yeniTop(10.0f);
Top siradakiTop(10.0f);
Top siradakiTop2(10.0f);

void Top::atesEt(AtesNoktasi& atesNoktasi)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && toplar.back().hiz <= 0) {

		carpisma = false;
		if (isFirst) {
			yeniTop = topUret(atesNoktasi);
			siradakiTop = topUret(atesNoktasi);
			siradakiTop2 = topUret(atesNoktasi);
			isFirst = false;
		}
		else {
			yeniTop = siradakiTop;
			siradakiTop = siradakiTop2;
			siradakiTop2 = topUret(atesNoktasi);
		}

		yeniTop.m_konum = atesNoktasi.aimDirection.getPosition();
		yeniTop.m_sekil.setPosition(atesNoktasi.aimDirection.getPosition());
		yeniTop.m_sekil.setRotation(atesNoktasi.aimDirection.getRotation());


		siradakiToplar.push_back(siradakiTop);
		siradakiToplar.push_back(siradakiTop2);
		std::cout << siradakiToplar.size() << "\n";
		toplar.push_back(yeniTop);

		siradakiToplar.end()[-1].m_konum = sf::Vector2f(atesNoktasi.aimDirection.getPosition().x - 100.f, atesNoktasi.aimDirection.getPosition().y);

	}

	if (toplar.back().hiz > 0) {

		sf::Vector2f dx;
		if (!carpisma) {
			dx = sf::Vector2f(std::sin(toplar.back().m_sekil.getRotation() / 180 * M_PI), -(std::cos(toplar.back().m_sekil.getRotation() / 180 * M_PI)));
		}
		else {
			dx = sf::Vector2f(-(std::sin(toplar.back().m_sekil.getRotation() / 180 * M_PI)), -(std::cos(toplar.back().m_sekil.getRotation() / 180 * M_PI)));
		}
		dx *= toplar.back().hiz;
		if (toplar.back().m_konum.x <= 0 && !carpisma) {
			dx.x *= -1;
			carpisma = true;
		}
		else if (toplar.back().m_konum.x <= 0 && carpisma) {
			dx.x *= -1;
			carpisma = false;
		}

		if (toplar.back().m_konum.x >= 600 && !carpisma) {
			dx.x *= -1;
			carpisma = true;
		}
		else if (toplar.back().m_konum.x >= 600 && carpisma) {
			dx.x *= -1;
			carpisma = false;
		}
		toplar.back().m_sekil.move(dx);
		toplar.back().m_konum.x = toplar.back().m_sekil.getPosition().x;
		toplar.back().m_konum.y = toplar.back().m_sekil.getPosition().y;
	}
}




void Top::CarpismaKontrolu()
{
	if (toplar.back().m_konum.y <= 0) {
		toplar.back().hiz = 0;
	}
	for (int i = 0; i < (toplar.size() - 1); i++) {

		float deltaX = toplar[i].m_konum.x - toplar.back().m_konum.x;
		float deltaY = toplar[i].m_konum.y - toplar.back().m_konum.y;

		float intersectX = abs(deltaX) - (toplar[i].m_sekil.getRadius() + toplar.back().m_sekil.getRadius());
		float intersectY = abs(deltaY) - (toplar[i].m_sekil.getRadius() + toplar.back().m_sekil.getRadius());

		float intersectDiagonal = sqrt((deltaX * deltaX) + (deltaY * deltaY)) - ((toplar[i].m_sekil.getRadius() * sqrt(2)) + (toplar.back().m_sekil.getRadius() * sqrt(2)));

		if ((intersectX < 0.0f && intersectY < 0.0f) || intersectDiagonal <= 0.0f) {

			toplar.back().hiz = 0;

			int minAraTop = 0;
			float tempDeltaX = 100.0f;
			float tempDeltaY = 100.0f;
			float tempDeltaDiagonal = 100.0f * sqrt(2);
			for (int j = 0; j < baglanabilirToplar.size(); j++) {
				bool dolu = false;
				float diffX = abs(baglanabilirToplar[j].m_konum.x - toplar.back().m_konum.x);
				float diffY = abs(baglanabilirToplar[j].m_konum.y - toplar.back().m_konum.y);
				float diffDiagonal = sqrt((diffX * diffX) + (diffY * diffY));

				if ((diffX < tempDeltaX && diffY < tempDeltaY) || diffDiagonal < tempDeltaDiagonal) {
					for (int k = 0; k < (toplar.size() - 1); k++) {
						if (baglanabilirToplar[j].m_konum.x == toplar[k].m_konum.x && baglanabilirToplar[j].m_konum.y == toplar[k].m_konum.y) {
							dolu = true;
						}
					}
					if (!dolu) {
						tempDeltaX = diffX;
						tempDeltaY = diffY;
						tempDeltaDiagonal = diffDiagonal;
						minAraTop = j;
					}
				}
			}
			toplar.back().m_konum.x = baglanabilirToplar[minAraTop].m_konum.x;
			toplar.back().m_konum.y = baglanabilirToplar[minAraTop].m_konum.y;

		}

	}
	int yanindakiAyniRenkTopSayisi = 0;
	int patlayacakToplar[100];
	int tempPatlayacakTopSayisi = 0;
	if (toplar.back().hareketEtmisTop && toplar.back().hiz == 0) {
		for (int a = 0; a < toplar.size(); a++) {
			if (toplar[a].m_sekil.getFillColor().toInteger() == toplar.back().m_sekil.getFillColor().toInteger()) {
				float diffX = abs(toplar[a].m_konum.x - toplar.back().m_konum.x);
				float diffY = abs(toplar[a].m_konum.y - toplar.back().m_konum.y);
				float z = sqrt((diffX * diffX) + (diffY * diffY));
				if (z <= 20.0f * sqrt(2) || (diffX <= 20 && diffY == 0) || (diffX == 0 && diffY <= 20)) {
					patlayacakToplar[yanindakiAyniRenkTopSayisi] = a;
					yanindakiAyniRenkTopSayisi++;
				}
			}
		}
	}
	while (tempPatlayacakTopSayisi < yanindakiAyniRenkTopSayisi) {
		tempPatlayacakTopSayisi = yanindakiAyniRenkTopSayisi;
		for (int b = 0; b < 100; b++) {
			if (b > (yanindakiAyniRenkTopSayisi - 1)) {
				break;
			}
			bool isUnique = true;
			int donus = -1;
			if (degenTopBul(patlayacakToplar[b]) < toplar.size()) {
				donus = degenTopBul(patlayacakToplar[b]);
			}
			for (int c = 0; c < 100; c++) {
				if (patlayacakToplar[c] == donus || donus == -1) {
					isUnique = false;
				}
			}
			if (isUnique) {
				patlayacakToplar[yanindakiAyniRenkTopSayisi] = donus;
				yanindakiAyniRenkTopSayisi++;
			}
		}
	}
	int temp;

	if (yanindakiAyniRenkTopSayisi >= 3) {

		std::cout << "\n";
		int silmeKarsitiDenge = 0;
		for (int d = 0; d < yanindakiAyniRenkTopSayisi; d++) {
			int denge = 0;
			int oncesindeKucukSayisi = 0;
			if (patlayacakToplar[d] != 0) {
				for (int i = 0; i < d; i++) {
					if (patlayacakToplar[i] > patlayacakToplar[d]) {
						denge++;
					}
					if (patlayacakToplar[i] < patlayacakToplar[d]) {
						oncesindeKucukSayisi++;
					}
				}
				int sira = 0;
				if (oncesindeKucukSayisi > 0 && denge > 0) {
					sira = patlayacakToplar[d] - (silmeKarsitiDenge - oncesindeKucukSayisi);
				}
				else if (oncesindeKucukSayisi == 0 && denge > 0) {
					sira = patlayacakToplar[d];
				}
				else {
					sira = patlayacakToplar[d] - silmeKarsitiDenge;
				}
				std::cout << patlayacakToplar[d] << " , ";
				toplar.erase(toplar.begin() + sira);
				silmeKarsitiDenge++;

			}
		}
	}
}

int Top::degenTopBul(int aramaTopu) {
	for (int i = 0; i < toplar.size(); i++) {
		if (i != aramaTopu) {
			if (toplar[i].m_sekil.getFillColor().toInteger() == toplar[aramaTopu].m_sekil.getFillColor().toInteger()) {
				float diffX = abs(toplar[i].m_konum.x - toplar[aramaTopu].m_konum.x);
				float diffY = abs(toplar[i].m_konum.y - toplar[aramaTopu].m_konum.y);
				float z = sqrt((diffX * diffX) + (diffY * diffY));
				if (z <= 20.0f * sqrt(2) || (diffX <= 20 && diffY == 0) || (diffX == 0 && diffY <= 20)) {
					return i;
				}
			}
		}
	}
	return -1;
}

void Top::cizListe(Pencere& pencere)
{
	for (auto siradaki : toplar) {
		siradaki.ciz(pencere);
	}
	for (auto siradaki : baglanabilirToplar) {
		siradaki.ciz(pencere);
	}
	for (auto siradaki : siradakiToplar) {
		siradaki.ciz(pencere);
	}
}
void Top::ciz(Pencere& pencere)
{
	m_sekil.setPosition(m_konum);
	pencere.ciz(m_sekil);
}