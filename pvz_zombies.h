//���� ֲ���ս��ʬ�Ľ�ʬ
#include "pvz_zombie.h"

//���� ֲ���ս��ʬ�Ľ�ʬ1��
class pvz_zombie_1 :public pvz_zombie
{
public:

	//���� ���죨x����y���򣬺����꣬�����꣩��
	pvz_zombie_1(short x_direction = -1,
		short y_direction = 0,
		unsigned short x = 0, unsigned short y = 0);

	//���� ����������д��
	~pvz_zombie_1()override;

	//���� ����Ч��������д��
	void filter_effects()override;

	//���� ����������д��
	vector<shared_ptr<pvz_effect>>attack()override;

	//���� ��¡������д��
	shared_ptr<pvz_zombie>clone()override;

	//���� �ƶ�������д��
	void move()override;
};