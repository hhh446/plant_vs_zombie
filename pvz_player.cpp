//���� Windows����ϵͳ
#include <Windows.h>

//���� ֲ���ս��ʬ�Ĳ��ֵ�ͼ
#include "pvz_maps.h"

//���� ֲ���ս��ʬ�Ĳ���ֲ��
#include "pvz_plants.h"

//���� ֲ���ս��ʬ�Ĳ��ֽ�ʬ
#include "pvz_zombies.h"

//���� ֲ���ս��ʬ�����
#include "pvz_player.h"

//ʵ�� ֲ���ս��ʬ������๹�죨���⣩��ֵ��Ա���ԣ������б���
// ���⣨���⣩{}
pvz_player::pvz_player(unsigned short sun) :sun(sun) {}

//ʵ�� ֲ���ս��ʬ���������������{}
pvz_player::~pvz_player() {}

//ʵ�� ֲ���ս��ʬ���������ѭ������{ѡ��ؿ���}
void pvz_player::main_cycle()
{
	initialize();
	while (true)
	{
		//��ӡѡ��
		cout << "��ѡ��ؿ���\n0.����\n1.��һ��\n"
			<< "�����ڴ�..." << endl;

		//������������¼���û��ѡ���˳���
		// {���ݰ������������λ�ã�ִ�ж�Ӧ���߼�}
		while (true)
		{
			//�������0��{������һ����}
			if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
			{
				return;
			}

			//�������1��{�����淨�б�[0]����ѭ�����˳�ѭ����}
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

//ʵ�� ֲ���ս��ʬ��������ʼ������{��ʼ���ؿ���ֲ��ڵ�����ʬ}
void pvz_player::initialize()
{
	//�����ֲ���ս��ʬ�Ĺؿ�Ϊ�գ�{���ؿ��������Ԫ��}
	if (!pvz_maps.size())
	{
		pvz_maps = { make_shared<pvz_map_1>() };
	}

	//�����ֲ���ս��ʬ�Ľ�ʬΪ�գ�{����ʬͼ�����Ԫ��}
	if (!pvz_shells_guide.size())
	{
		pvz_shells_guide = {
			make_shared<pvz_shell_1>()
		};
	}

	//�����ֲ���ս��ʬ��ֲ��Ϊ�գ�{��ֲ��ͼ�����Ԫ��}
	if (!pvz_plants_guide.size())
	{
		pvz_plants_guide = {
			make_shared<pvz_plant_1>()
		};
	}

	//�����ֲ���ս��ʬ���ڵ�Ϊ�գ�{���ڵ�ͼ�����Ԫ��}
	if (!pvz_zombies_guide.size())
	{
		pvz_zombies_guide = {
			make_shared<pvz_zombie_1>()
		};
	}
}