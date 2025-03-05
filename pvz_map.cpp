//包含 植物大战僵尸的地图
#include "pvz_map.h"

//实现 植物大战僵尸的地图类构造（宽，高）赋值成员属性（参数列表）：
// 宽（宽），高（高）{}
pvz_map::pvz_map(unsigned short w, unsigned short h)
	:w(w), h(h)
{
	//初始化
	initialize();
}

//实现 植物大战僵尸的地图类初始化（）{}
void pvz_map::initialize()
{
	unsigned short a = w, b = w + 1, c = b * h - 1;
	now = string(c, ' ');//string(字符数,字符)可赋值相同字符
	for (a; a < c; a += b)now[a] = '\n';
	backup = now;
}

//实现 植物大战僵尸的地图类绘制（）{修改地图现状并在屏幕打印}
void pvz_map::draw()
{
	now = backup;
	unsigned short a = w + 1, b = 0;
	auto& c = plants;
	auto& d = zombies;
	auto& e = shells;

	for (b = 0; b < c.size(); b++)
	{
		now[c[b]->look('y') * a + c[b]->look('x')]
			= c[b]->look('s');
	}

	for (b = 0; b < d.size(); b++)
	{
		now[d[b]->look('y') * a + d[b]->look('x')]
			= d[b]->look('s');
	}

	for (b = 0; b < e.size(); b++)
	{
		now[e[b]->look('y') * a + e[b]->look('x')]
			= e[b]->look('s');
	}

	cout << "\x1B[2J\x1B[3J\x1B[H" << now;
}

//实现 植物大战僵尸的地图类移动（）{处理炮弹、植物和僵尸的移动和攻击}
void pvz_map::move()
{
	unsigned short a = 0, b = 0, c = 0;
	for (a = 0; a < zombies.size(); a++)
	{
		for (b = 0, c = 0; b < plants.size(); b++)
		{
			if (pow(zombies[a]->look('r'),2)
				>= pow(plants[b]->look('x')
					- zombies[a]->look('x'), 2)
				+ pow(plants[b]->look('y')
					- zombies[a]->look('y'), 2))
			{
				plants[b]->exist(zombies[a]->look('v'));

				plants[b]->using_effects
				(zombies[a]->attack());

				c++;
			}

			if (pow(plants[b]->look('r'), 2)
				>= pow(zombies[a]->look('x')
					- plants[b]->look('x'), 2)
				+ pow(zombies[a]->look('y')
					- plants[b]->look('y'), 2))
			{
				shared_ptr<pvz_shell>new_shell
					= plants[b]->attack();
				if (new_shell != 0)
				{
					shells.push_back(new_shell);
				}
			}
		}

		for (b = 0; b < shells.size(); b++)
		{
			if (pow(shells[b]->look('r'), 2)
				>= pow(zombies[a]->look('x')
					- shells[b]->look('x'), 2)
				+ pow(zombies[a]->look('y')
					- shells[b]->look('y'), 2))
			{
				zombies[a]->using_effects
				(shells[b]->attack());

				if (!zombies[a]->exist
				(shells[b]->look('p')))
				{
					zombies.erase(zombies.begin() + a);
					if (a > 0)a--;
					c = 1;
				}

				shells.erase(shells.begin() + b);
				if (b > 0)b--;
			}
		}

		if (c < 1)
		{
			zombies[a]->move();
			if (zombies[a]->look('x') < 1
				|| zombies[a]->look('x') >= w - 1
				|| zombies[a]->look('y') < 1
				|| zombies[a]->look('y') >= h - 1)
			{
				zombies.erase(zombies.begin() + a);

				if (a)a--;
			}
		}
	}

	for (a = 0; a < shells.size(); a++)
	{
		shells[a]->move();
		if (shells[a]->look('x') >= w - 1
			|| shells[a]->look('x') < 1
			|| shells[a]->look('y') >= h - 1
			|| shells[a]->look('y') < 1)
		{
			shells.erase(shells.begin() + a);
			if (a > 0)a--;
		}
	}
}

//实现 植物大战僵尸的地图类修改角色（植物，横坐标，纵坐标）{}
void pvz_map::modify_coordinates
(shared_ptr<pvz_plant>& new_plant,
	unsigned short& x, unsigned short& y)
{
	new_plant->modify(x, y);
}

//实现 植物大战僵尸的地图类修改角色（僵尸，横坐标，纵坐标）{}
void pvz_map::modify_coordinates
(shared_ptr<pvz_zombie>& new_zombie,
	unsigned short& x, unsigned short& y)
{
	new_zombie->modify(x, y);
}

//实现 关卡列表，炮弹、植物、僵尸的图鉴
vector<shared_ptr<pvz_map>>pvz_maps;
vector<shared_ptr<pvz_shell>>pvz_shells_guide;
vector<shared_ptr<pvz_plant>>pvz_plants_guide;
vector<shared_ptr<pvz_zombie>>pvz_zombies_guide;