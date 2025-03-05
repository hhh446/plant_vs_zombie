//���� ֲ���ս��ʬ��ֲ��
#include "pvz_plant.h"

//���� �ڵ�1�� �̳��ԣ��ڵ���
class pvz_shell_1 :public pvz_shell
{
public:

	//���� ���죨x����y���򣬺����꣬�����꣩��
	pvz_shell_1(short x_direction = 0,
		short y_direction = 0,
		unsigned short x = 0, unsigned short y = 0);

	//���� ����������д��
	~pvz_shell_1()override;

	//���� ��¡������д��
	shared_ptr<pvz_shell>clone()override;

	//���� �ƶ�������д��
	void move()override;

	//���� ����������д��
	vector<shared_ptr<pvz_effect>>attack()override;
};

//���� ֲ��1�� �̳��ԣ�ֲ����
class pvz_plant_1 :public pvz_plant
{
public:

	//���� ���죨�����꣬�����꣩��
	pvz_plant_1(unsigned short x = 0,
		unsigned short y = 0);

	//���� ����������д��
	~pvz_plant_1()override;

	//���� ����Ч��������д��
	void filter_effects()override;

	//���� ����������д��
	shared_ptr<pvz_shell>attack()override;

	//���� ��¡������д��
	shared_ptr<pvz_plant>clone()override;
};