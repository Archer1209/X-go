#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include<sstream>

//======头文件中只进行声明

extern bool gameOver, gameQuit;
extern int Window_width, Window_height, stageWidth, stageHeight;
extern sf::Vector2i originPoint;	//棋盘的[0,0]点坐标
extern sf::Vector2i mousePosition;	//鼠标坐标

extern int crossPoint[19][19];		//交叉点数据，0为空，白为1，黑为-1
extern sf::RenderWindow window;