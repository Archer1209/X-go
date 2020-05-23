#include "Go.h"
#include "globle.h"

whiteStone::whiteStone()
{
	//设定白子精灵
	if (!tWhiteStone.loadFromFile("data/images/white_stone.png"))
		std::cout << "白子图没有找到" << std::endl;
	sWhiteStone.setTexture(tWhiteStone);
	sWhiteStone.setOrigin(20, 20);
};

whiteStone::~whiteStone()
{

};

void whiteStone::Drop(sf::Vector2i mPosition)
{
	//在棋盘范围内才会落子
	if ((mPosition.x > originPoint.x - GRIDSIZE / 2)
		&& (mPosition.y > originPoint.y - GRIDSIZE / 2)
		&& (mPosition.x < originPoint.x + GRIDSIZE * 19.5)
		&& (mPosition.y < originPoint.y + GRIDSIZE * 19.5))
	{
		x = (mPosition.x - originPoint.x + GRIDSIZE / 2) / GRIDSIZE; 
		y = (mPosition.y - originPoint.y + GRIDSIZE / 2) / GRIDSIZE;

		crossPoint[x][y] = 1;

		sWhiteStone.setPosition(x*GRIDSIZE + originPoint.x, y*GRIDSIZE + originPoint.y);

		std::cout << mPosition.x << "   ";
		std::cout << mPosition.y << std::endl;
		std::cout << x << "   ";
		std::cout << y << std::endl;
		std::cout << x * GRIDSIZE + originPoint.x << "   ";
		std::cout << y * GRIDSIZE + originPoint.y << std::endl << std::endl;

		window.draw(sWhiteStone);
	}
	
}