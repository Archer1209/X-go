#include "Go.h"
#include "globle.h"


//���캯����������
Go::Go()
{
	Window_width = 1200;
	Window_height = 675;
	window.create(sf::VideoMode(Window_width, Window_height), L"Go by �Ľ���", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);  //����֡Ƶ
}
//����������û��
Go::~Go()
{
}

//=================================  ��ʼ��  ===================================//

//��ʼ������
void Go::Initial()
{
	gameOver = false;
	gameQuit = false;
	crossPoint[19][19] = { 0 };
	originPoint.x = 60;
	originPoint.y = 60;

	LoadMediaData();
}
//����`�ز�
void Go::LoadMediaData()
{
	if (!tBackGround.loadFromFile("data/images/����.jpg"))
		std::cout << "����ͼû���ҵ�" << std::endl;
	sBackGround.setTexture(tBackGround);
}

//=================================  ����  ===================================//

//��ȡ�����¼�
void Go::Input()
{
	sf::Event event;//event types ����Window��Keyboard��Mouse��Joystick��4����Ϣ
					//ͨ��  bool Window :: pollEvent��sf :: Event��event�� �Ӵ���˳��ѯ�ʣ� polled ���¼��� 
					//�����һ���¼��ȴ������ú���������true�������¼���������䣨filled���¼����ݡ� 
					//������ǣ���ú�������false�� ͬ����Ҫ����Ҫע�⣬һ�ο����ж���¼�; ������Ǳ���ȷ������ÿ�����ܵ��¼��� 

	while (window.pollEvent(event))
	{
		//������Ͻǹر�
		if (event.type == sf::Event::Closed)
		{
			window.close();		//���ڿ����ƶ���������С����С�����������Ҫ�رգ���Ҫ�Լ�ȥ����close()����
			gameQuit = true;
		}
		//����ESC��
		if (event.type == sf::Event::EventType::KeyReleased && event.key.code == sf::Keyboard::Escape)
		{
			window.close();		//���ڿ����ƶ���������С����С�����������Ҫ�رգ���Ҫ�Լ�ȥ����close()����
			gameQuit = true;
		}

		//���ͷ�
		if (event.type == sf::Event::EventType::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			if (!gameOver)
			{
				mousePosition.x = sf::Mouse::getPosition(window).x;
				mousePosition.y = sf::Mouse::getPosition(window).y;
				whiteStone wStone;
				wStone.Drop(mousePosition);
			}
		}
	}
}


//=================================  ����  ===================================//

void Go::Draw()
{
	window.clear();
	// ���Ʊ���
	sBackGround.setPosition(0, 0);
	window.draw(sBackGround);
	// ������̨
	window.display();
}


//=================================  ����  ===================================//

void Go::Run()
{
	do
	{
		Initial();

		while (window.isOpen() && gameOver == false)
		{
			Input();

			Draw();
		}

	} while (!gameQuit);
}