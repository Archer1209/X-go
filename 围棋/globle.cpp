#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include<sstream>

//======对头文件声明的全局变量进行定义！！！！

bool gameOver, gameQuit;
int Window_width, Window_height, stageWidth, stageHeight;
sf::Vector2i originPoint;	//棋盘的[0,0]点坐标
sf::Vector2i mousePosition;	//鼠标坐标
int crossPoint[19][19];		//交叉点数据，0为空，白为1，黑为-1
sf::RenderWindow window;

