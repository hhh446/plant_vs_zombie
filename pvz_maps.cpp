//���� Windows����ϵͳ
#include <Windows.h>

//���� ֲ���ս��ʬ�Ĳ��ֵ�ͼ
#include "pvz_maps.h"

//ʵ�� ֲ���ս��ʬ�Ĺؿ�1���죨���ߣ���ֵ��Ա���ԣ������б���
// ֲ���ս��ʬ�ĵ�ͼ�๹�죨���ߣ�{��ʼ����ǰ�ؿ���ͼ}
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

//ʵ�� ֲ���ս��ʬ�Ĺؿ�1��������{}
pvz_map_1::~pvz_map_1() {}

//ʵ�� ֲ���ս��ʬ�Ĺؿ�1��ѭ�������⣩{}
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

//ʵ�� ֲ���ս��ʬ�Ĺؿ�1���ɽ�ʬ����{}
void pvz_map_1::new_zombie()
{
	srand((unsigned)time(0));// ��ʼ�����������
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