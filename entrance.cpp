//���� Windows����ϵͳ
#include <Windows.h>

//���� ֲ���ս��ʬ�����
#include "pvz_player.h"

//���� �������
#include "entrance.h"

//�淨�б�
vector<shared_ptr<player>>modes;

//ʵ�� ����๹�죨��{}
entrance::entrance() {}

//ʵ�� �������������{}
entrance::~entrance() {}

//ʵ�� �������ѭ������{}
void entrance::main_cycle()
{
	//��ʼ����Ϸ�淨�б�
	initialize();

	//������ѭ����û��ѡ���˳���{��ӡѡ�ѡ���淨}
	while (true)
	{
		//����֮���ӡѡ��
		cout << "\x1B[2J\x1B[3J\x1B[H"
			<< "��ѡ����Ϸ��\n0.�˳�\n1.ֲ���ս��ʬ\n"
			<< "�����ڴ�..." << endl;

		//������������¼���û��ѡ���˳���
		// {���ݰ����������λ�ã�ִ�ж�Ӧ���߼�}
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

//ʵ�� ������ʼ������{}
void entrance::initialize()
{
	if (!modes.size())
	{
		modes = {
			make_shared<pvz_player>()
		};
	}
}

//ʵ�� �������
shared_ptr<entrance>program_entrance
= make_shared<entrance>();