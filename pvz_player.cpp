//包含 Windows操作系统
#include <Windows.h>

//包含 植物大战僵尸的部分地图
#include "pvz_maps.h"

//包含 植物大战僵尸的部分植物
#include "pvz_plants.h"

//包含 植物大战僵尸的部分僵尸
#include "pvz_zombies.h"

//包含 植物大战僵尸的玩家
#include "pvz_player.h"

//实现 植物大战僵尸的玩家类构造（阳光）赋值成员属性（参数列表）：
// 阳光（阳光）{}
pvz_player::pvz_player(unsigned short sun) :sun(sun) {}

//实现 植物大战僵尸的玩家类析构（）{}
pvz_player::~pvz_player() {}

//实现 植物大战僵尸的玩家类主循环（）{选择关卡等}
void pvz_player::main_cycle()
{
	initialize();
	while (true)
	{
		//打印选项
		cout << "请选择关卡：\n0.返回\n1.第一关\n"
			<< "敬请期待..." << endl;

		//处理鼠标或键盘事件（没有选择退出）
		// {根据按键或者鼠标点击位置，执行对应的逻辑}
		while (true)
		{
			//如果（按0）{返回上一函数}
			if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
			{
				return;
			}

			//如果（按1）{调用玩法列表[0]的主循环；退出循环；}
			if (GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
			{
				pvz_maps[0]->main_cycle(this->sun);
				this->score += this->sun / 2;
				this->sun = 0;
				break;
			}
		}
	}
}

//实现 植物大战僵尸的玩家类初始化（）{初始化关卡、植物、炮弹、僵尸}
void pvz_player::initialize()
{
	//如果（植物大战僵尸的关卡为空）{往关卡容器添加元素}
	if (!pvz_maps.size())
	{
		pvz_maps = { make_shared<pvz_map_1>() };
	}

	//如果（植物大战僵尸的僵尸为空）{往僵尸图鉴添加元素}
	if (!pvz_shells_guide.size())
	{
		pvz_shells_guide = {
			make_shared<pvz_shell_1>()
		};
	}

	//如果（植物大战僵尸的植物为空）{往植物图鉴添加元素}
	if (!pvz_plants_guide.size())
	{
		pvz_plants_guide = {
			make_shared<pvz_plant_1>()
		};
	}

	//如果（植物大战僵尸的炮弹为空）{往炮弹图鉴添加元素}
	if (!pvz_zombies_guide.size())
	{
		pvz_zombies_guide = {
			make_shared<pvz_zombie_1>()
		};
	}
}