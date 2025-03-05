//���� ֲ���ս��ʬ�Ĳ���ֲ��
#include "pvz_plants.h"

//ʵ�� ֲ���ս��ʬ���ڵ�1�๹�죨x����y���򣬺����꣬�����꣩
// ��ֵ��Ա���ԣ������б���ֲ���ս��ʬ��ֲ��1�๹�죨x����
// y���򣬺����꣬�����꣬��������������Χ���ƶ��ٶȣ���־��
// Ч���б�{}
pvz_shell_1::pvz_shell_1(short x_direction,
	short y_direction, unsigned short x, unsigned short y)
	:pvz_shell(x_direction, y_direction, x, y, 1, 2, 2,
		'a', {}) {}

//ʵ�� ֲ���ս��ʬ���ڵ�1����������{}
pvz_shell_1::~pvz_shell_1() {}

//ʵ�� ֲ���ս��ʬ���ڵ�1���¡����{����Լ�������}
shared_ptr<pvz_shell>pvz_shell_1::clone()
{
	return make_shared<pvz_shell_1>(*this);
}

//ʵ�� ֲ���ս��ʬ���ڵ�1���ƶ�����{�޸�����}
void pvz_shell_1::move()
{
	x += v * x_direction;
	y += v * y_direction;
}

//ʵ�� ֲ���ս��ʬ���ڵ�1�๥������{}
vector<shared_ptr<pvz_effect>>pvz_shell_1::attack()
{
	return {};
}


//ʵ�� ֲ���ս��ʬ��ֲ��1�๹�죨�����꣬�����꣩
// ��ֵ��Ա���ԣ������б���ֲ���ս��ʬ��ֲ���๹�죨Ѫ���������꣬
// �����꣬��̣����٣���־��Ч���б�{}
pvz_plant_1::pvz_plant_1(unsigned short x,
	unsigned short y)
	:pvz_plant(10, x, y, 120, 1, 'A', {}) {}

//ʵ�� ֲ���ս��ʬ��ֲ��1����������{}
pvz_plant_1::~pvz_plant_1() {}

//ʵ�� ֲ���ս��ʬ��ֲ��1�����Ч������{}
void pvz_plant_1::filter_effects()
{

}

//ʵ�� ֲ���ս��ʬ��ֲ��1�๥������{�����ڵ�1��ָ�����}
shared_ptr<pvz_shell>pvz_plant_1::attack()
{
	return make_shared<pvz_shell_1>(1, 0, x + 1, y);
}

//ʵ�� ֲ���ս��ʬ��ֲ��1���¡����{����Լ�������}
shared_ptr<pvz_plant>pvz_plant_1::clone()
{
	return make_shared<pvz_plant_1>(*this);
}