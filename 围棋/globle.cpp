#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include<sstream>

//======��ͷ�ļ�������ȫ�ֱ������ж��壡������

bool gameOver, gameQuit;
int Window_width, Window_height, stageWidth, stageHeight;
sf::Vector2i originPoint;	//���̵�[0,0]������
sf::Vector2i mousePosition;	//�������
int crossPoint[19][19];		//��������ݣ�0Ϊ�գ���Ϊ1����Ϊ-1
sf::RenderWindow window;

