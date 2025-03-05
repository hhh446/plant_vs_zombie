//包含 Windows操作系统
#include <Windows.h>

//包含 植物大战僵尸的玩家
#include "pvz_player.h"

//包含 程序入口
#include "entrance.h"

//玩法列表
vector<shared_ptr<player>>modes;

//实现 入口类构造（）{}
entrance::entrance() {}

//实现 入口类析构（）{}
entrance::~entrance() {}

//实现 入口类主循环（）{}
void entrance::main_cycle()
{
	//初始化游戏玩法列表
	initialize();

	//程序主循环（没有选择退出）{打印选项；选择玩法}
	while (true)
	{
		//清屏之后打印选项
		cout << "\x1B[2J\x1B[3J\x1B[H"
			<< "请选择游戏：\n0.退出\n1.植物大战僵尸\n"
			<< "敬请期待..." << endl;

		//处理鼠标或键盘事件（没有选择退出）
		// {根据按键或鼠标点击位置，执行对应的逻辑}
		while (true)
		{
			if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
			{
				return;
			}

			if (GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
			{
				modes[0]->main_cycle();
				break;
			}
		}
	}
}

//实现 入口类初始化（）{}
void entrance::initialize()
{
	if (!modes.size())
	{
		modes = {
			make_shared<pvz_player>()
		};
	}
}

//实现 程序入口
shared_ptr<entrance>program_entrance
= make_shared<entrance>();