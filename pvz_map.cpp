//���� ֲ���ս��ʬ�ĵ�ͼ
#include "pvz_map.h"

//ʵ�� ֲ���ս��ʬ�ĵ�ͼ�๹�죨���ߣ���ֵ��Ա���ԣ������б���
// �������ߣ��ߣ�{}
pvz_map::pvz_map(unsigned short w, unsigned short h)
	:w(w), h(h)
{
	//��ʼ��
	initialize();
}

//ʵ�� ֲ���ս��ʬ�ĵ�ͼ���ʼ������{}
void pvz_map::initialize()
{
	unsigned short a = w, b = w + 1, c = b * h - 1;
	now = string(c, ' ');//string(�ַ���,�ַ�)�ɸ�ֵ��ͬ�ַ�
	for (a; a < c; a += b)now[a] = '\n';
	backup = now;
}

//ʵ�� ֲ���ս��ʬ�ĵ�ͼ����ƣ���{�޸ĵ�ͼ��״������Ļ��ӡ}
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

//ʵ�� ֲ���ս��ʬ�ĵ�ͼ���ƶ�����{�����ڵ���ֲ��ͽ�ʬ���ƶ��͹���}
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

//ʵ�� ֲ���ս��ʬ�ĵ�ͼ���޸Ľ�ɫ��ֲ������꣬�����꣩{}
void pvz_map::modify_coordinates
(shared_ptr<pvz_plant>& new_plant,
	unsigned short& x, unsigned short& y)
{
	new_plant->modify(x, y);
}

//ʵ�� ֲ���ս��ʬ�ĵ�ͼ���޸Ľ�ɫ����ʬ�������꣬�����꣩{}
void pvz_map::modify_coordinates
(shared_ptr<pvz_zombie>& new_zombie,
	unsigned short& x, unsigned short& y)
{
	new_zombie->modify(x, y);
}

//ʵ�� �ؿ��б��ڵ���ֲ���ʬ��ͼ��
vector<shared_ptr<pvz_map>>pvz_maps;
vector<shared_ptr<pvz_shell>>pvz_shells_guide;
vector<shared_ptr<pvz_plant>>pvz_plants_guide;
vector<shared_ptr<pvz_zombie>>pvz_zombies_guide;