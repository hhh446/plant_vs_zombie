//���� ֲ���ս��ʬ�Ĳ��ֽ�ʬ
#include "pvz_zombies.h"

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ1�๹�죨x����y���򣬺����꣬�����꣩
// ��ֵ��Ա���ԣ������б���ֲ���ս��ʬ�Ľ�ʬ�๹�죨x����y����
// �����꣬�����꣬��������������Χ���ƶ��ٶȣ���־��Ѫ����Ч���б�
// {}
pvz_zombie_1::pvz_zombie_1(short x_direction,
	short y_direction, unsigned short x, unsigned short y)
	:pvz_zombie(x_direction, y_direction, x, y, 1, 1, 1, '*', 10,
		{}) {}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ1����������{}
pvz_zombie_1::~pvz_zombie_1() {}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ1�����Ч������{}
void pvz_zombie_1::filter_effects()
{

}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ1�๥������{����Ч���б����������һ��}
vector<shared_ptr<pvz_effect>>pvz_zombie_1::attack()
{
	return {};
}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ1���¡����{����Լ�������}
shared_ptr<pvz_zombie>pvz_zombie_1::clone()
{
	return make_shared<pvz_zombie_1>(*this);
}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ1���ƶ�����{�ı�����}
void pvz_zombie_1::move()
{
	x += x ? x_direction : v;
	y += y ? y_direction : v;
}