//���� ��׼���������
#include <iostream>

//���� ��̬��������
#include <vector>

//���� ���
#include "player.h"

//���� std�����ռ�
using namespace std;

//���� ���
class entrance :public player
{
	//���� ��ʼ��������д��
	void initialize()override;

public:

	//���� ���죨����
	entrance();

	//���� ����������д��
	~entrance()override;

	//���� ��ѭ��������д��
	void main_cycle()override;
};

//���� �������
extern shared_ptr<entrance>program_entrance;