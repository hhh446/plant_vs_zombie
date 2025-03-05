//���� ֲ���ս��ʬ��ֲ��
#include "pvz_plant.h"

//ʵ�� ֲ���ս��ʬ���ڵ��๹�죨x����y���򣬺����꣬�����꣬
// �������������뾶���ƶ��ٶȣ���־��Ч���б�
// ��ֵ��Ա���ԣ������б���x����x���򣩣�y����y���򣩣�
// ֲ���ս��ʬ�Ľ�ɫ�๹�죨�����꣬�����꣬������Χ���ƶ��ٶȣ�
// ��־��Ч���б�������������������{}
pvz_shell::pvz_shell(short x_direction, short y_direction,
	unsigned short x, unsigned short y,
	unsigned short power, unsigned short r,
	unsigned short v, char sign,
	vector<shared_ptr<pvz_effect>>new_effects)
	:x_direction(x_direction), y_direction(y_direction),
	pvz_character(x, y, r, v, sign, new_effects),
	power(power) {}

//ʵ�� ֲ���ս��ʬ���ڵ�����ڣ��˺�ֵ��{}
char pvz_shell::exist(unsigned short power)
{
	//���ر�־
	return sign;
}

//ʵ�� ֲ���ս��ʬ���ڵ���۲죨Ŀ�꣩{����Ŀ�귵������}
unsigned short pvz_shell::look(char goal)
{
	if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	if (goal == 'p')return power;
	return 0;
}


//ʵ�� ֲ���ս��ʬ��ֲ���๹�죨Ѫ���������꣬�����꣬��̣����٣�
// ��־��Ч���б���ֵ��Ա���ԣ������б���
// ֲ���ս��ʬ�Ľ�ɫ�๹�죨�����꣬�����꣬��̣����٣���־��
// Ч���б���Ѫ����Ѫ����{}
pvz_plant::pvz_plant(unsigned short hp, unsigned short x,
	unsigned short y, unsigned short r, unsigned short v,
	char sign, vector<shared_ptr<pvz_effect>>new_effects)
	:pvz_character(x, y, r, v, sign, new_effects), hp(hp)
{}

//ʵ�� ֲ���ս��ʬ��ֲ����ִ��Ч������{}
void pvz_plant::perform_effects()
{
	//���˿����ߵ�Ч��������
	filter_effects();

	//ִ���޷����ߵ�Ч��...
}

//ʵ�� ֲ���ս��ʬ��ֲ������ڣ�������{}
char pvz_plant::exist(unsigned short power)
{
	//����Ѫ�����٣�unsigned���Ͳ��ܳ��ָ������˺��ϸ�ʱѪ������
	hp -= hp < power ? hp : power;

	//��������ʱ��ʾ��ǰ��ɫ������
	return hp ? sign : 0;
}

//ʵ�� ֲ���ս��ʬ��ֲ����۲죨Ŀ�꣩{����Ŀ�귵������}
unsigned short pvz_plant::look(char goal)
{
	if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	return 0;
}

//ʵ�� ֲ���ս��ʬ��ֲ�����޸ģ������꣬�����꣩{�޸�����}
void pvz_plant::modify(unsigned short x, unsigned short y)
{
	this->x = x; this->y = y;
}