#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include<sstream>

//======ͷ�ļ���ֻ��������

extern bool gameOver, gameQuit;
extern int Window_width, Window_height, stageWidth, stageHeight;
extern sf::Vector2i originPoint;	//���̵�[0,0]������
extern sf::Vector2i mousePosition;	//�������

extern int crossPoint[19][19];		//��������ݣ�0Ϊ�գ���Ϊ1����Ϊ-1
extern sf::RenderWindow window;