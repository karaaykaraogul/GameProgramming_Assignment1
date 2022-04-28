#include "Oyun.hpp"

int main()
{
	sf::Image img;
	img.loadFromFile("./resimler/puzzle.png");
	img.createMaskFromColor(sf::Color(147, 187, 236), 0);
	sf::Texture texture;
	texture.loadFromImage(img);

	std::srand(time(0));
	Oyun oyun;
	oyun.oyunuBaslat(&texture);
}