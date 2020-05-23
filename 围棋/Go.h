#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include<sstream>

#define	GRIDSIZE 30

class Go
{
public:
	Go();
	~Go();

	sf::Texture tBackGround, tButtons;
	sf::Sprite sBackGround, sButtons;

	//sf::RenderWindow window;

	void Run();

	void Initial();
	void LoadMediaData();

	void Input();


	void Logic();
	void isWin();

	void Draw();
	void DrawButton();
};

class whiteStone
{
public:
	whiteStone();
	~whiteStone();
	int x, y;	//对应棋子的x轴和y轴
	sf::Texture tWhiteStone;
	sf::Sprite sWhiteStone;

	void Drop(sf::Vector2i mousePosition);	//落子
};