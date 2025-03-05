//包含 Windows操作系统
#include <Windows.h>

//包含 植物大战僵尸的部分地图
#include "pvz_maps.h"

//实现 植物大战僵尸的关卡1构造（宽，高）赋值成员属性（参数列表）：
// 植物大战僵尸的地图类构造（宽，高）{初始化当前关卡地图}
pvz_map_1::pvz_map_1(unsigned short w, unsigned short h)
	:pvz_map(w, h)
{
	unsigned short a = 0, b = w + 1, c = b * h - 1,
		d = w - 1, e = b * 26, f = b * 3 + 2;
	for (a; a < c; a++)
	{
		if (a < w || a > c - b || a % b == d || !(a % b))
		{
			now[a] = '#';
		}
	}
	for (a = b * 9 + 1; a <= e; a++)
	{
		now[a] = '#'; if (a % b == d)a += f;
	}
	backup = now;
}

//实现 植物大战僵尸的关卡1析构（）{}
pvz_map_1::~pvz_map_1() {}

//实现 植物大战僵尸的关卡1主循环（阳光）{}
void pvz_map_1::main_cycle(unsigned short& sun)
{
	unsigned short x = 2, y = 11, a = 0;
	unsigned char select_plant = 'A';
	while (true)
	{
		new_zombie();
		move();

		if (GetAsyncKeyState(0x41))select_plant = 'A';

		if (GetAsyncKeyState(VK_UP))
		{
			shared_ptr<pvz_plant>new_plant
				= pvz_plants_guide[select_plant - 65]
				->clone();
			if (new_plant != 0)
			{
				modify_coordinates(new_plant, x, y);
				plants.push_back(new_plant);
			}
		}
		if (GetAsyncKeyState(VK_DOWN))break;

		if (GetAsyncKeyState(VK_LEFT) && x > 4)x -= 3;
		if (GetAsyncKeyState(VK_RIGHT) && x < 114)x += 3;
		if (GetAsyncKeyState(VK_NUMPAD1) & 0x8000)y = 11;
		if (GetAsyncKeyState(VK_NUMPAD2) & 0x8000)y = 15;
		if (GetAsyncKeyState(VK_NUMPAD3) & 0x8000)y = 19;
		if (GetAsyncKeyState(VK_NUMPAD4) & 0x8000)y = 23;
		if (GetAsyncKeyState(VK_NUMPAD5) & 0x8000)y = 27;

		Sleep(100);
		draw();
	}
}

//实现 植物大战僵尸的关卡1生成僵尸（）{}
void pvz_map_1::new_zombie()
{
	srand((unsigned)time(0));// 初始化随机数种子
	unsigned short x = w - 1, y = (rand() % 5) * 4 + 11,
		i = 0;

	for (i; i < zombies.size(); i++)
	{
		if (zombies[i]->look('x') == x
			&& zombies[i]->look('y') == y)
		{
			return;
		}
	}

	shared_ptr<pvz_zombie>new_zombie = pvz_zombies_guide
		[rand() % pvz_zombies_guide.size()]->clone();
	modify_coordinates(new_zombie, x, y);
	zombies.push_back(new_zombie);
}