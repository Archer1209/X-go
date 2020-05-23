#include "Go.h"
#include "globle.h"


//构造函数创建窗口
Go::Go()
{
	Window_width = 1200;
	Window_height = 675;
	window.create(sf::VideoMode(Window_width, Window_height), L"Go by 夏健潇", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);  //窗口帧频
}
//析构函数还没用
Go::~Go()
{
}

//=================================  初始化  ===================================//

//初始化变量
void Go::Initial()
{
	gameOver = false;
	gameQuit = false;
	crossPoint[19][19] = { 0 };
	originPoint.x = 60;
	originPoint.y = 60;

	LoadMediaData();
}
//加载`素材
void Go::LoadMediaData()
{
	if (!tBackGround.loadFromFile("data/images/棋盘.jpg"))
		std::cout << "背景图没有找到" << std::endl;
	sBackGround.setTexture(tBackGround);
}

//=================================  输入  ===================================//

//获取输入事件
void Go::Input()
{
	sf::Event event;//event types 包括Window、Keyboard、Mouse、Joystick，4类消息
					//通过  bool Window :: pollEvent（sf :: Event＆event） 从窗口顺序询问（ polled ）事件。 
					//如果有一个事件等待处理，该函数将返回true，并且事件变量将填充（filled）事件数据。 
					//如果不是，则该函数返回false。 同样重要的是要注意，一次可能有多个事件; 因此我们必须确保捕获每个可能的事件。 

	while (window.pollEvent(event))
	{
		//点击右上角关闭
		if (event.type == sf::Event::Closed)
		{
			window.close();		//窗口可以移动、调整大小和最小化。但是如果要关闭，需要自己去调用close()函数
			gameQuit = true;
		}
		//按下ESC键
		if (event.type == sf::Event::EventType::KeyReleased && event.key.code == sf::Keyboard::Escape)
		{
			window.close();		//窗口可以移动、调整大小和最小化。但是如果要关闭，需要自己去调用close()函数
			gameQuit = true;
		}

		//左释放
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


//=================================  绘制  ===================================//

void Go::Draw()
{
	window.clear();
	// 绘制背景
	sBackGround.setPosition(0, 0);
	window.draw(sBackGround);
	// 绘制舞台
	window.display();
}


//=================================  运行  ===================================//

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