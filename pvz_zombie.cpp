//���� ֲ���ս��ʬ�Ľ�ʬ
#include "pvz_zombie.h"

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ�๹�죨x����y���򣬺����꣬�����꣬
// ��������ɱ�˰뾶���ƶ��ٶȣ���־��Ч���б�Ѫ����
// ��ֵ��Ա���ԣ������б���x����x���򣩣�y����y���򣩣�
// �����꣨��ʼ�����꣩�������꣨��ʼ�����꣩��������������������
// ɱ�˰뾶��ɱ�˰뾶�����ƶ��ٶȣ��ƶ��ٶȣ�����־����־����
// Ч���б�Ч���б���Ѫ����Ѫ����{}
pvz_zombie::pvz_zombie(short x_direction,
	short y_direction, unsigned short x, unsigned short y,
	unsigned short power, unsigned short r,
	unsigned short v, char sign, unsigned short hp,
	vector<shared_ptr<pvz_effect>>new_effects)
	:x_direction(x_direction), y_direction(y_direction),
	pvz_character(x, y, r, v, sign, new_effects),
	hp(hp), power(power) {}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ��ִ��Ч������{}
void pvz_zombie::perform_effects()
{
	//���˿����ߵ�Ч��
	filter_effects();
}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ����ڣ��˺�ֵ��{}
char pvz_zombie::exist(unsigned short power)
{
	//����Ѫ�����٣�unsigned���Ͳ��ܳ��ָ������˺��ϸ�ʱѪ������
	hp -= hp < power ? hp : power;

	//��������ʱ��ʾ��ǰ��ɫ������
	return hp ? sign : 0;
}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ��۲죨Ŀ�꣩{����Ŀ�귵������}
unsigned short pvz_zombie::look(char goal)
{
	if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	if (goal == 'p')return power;
	return 0;
}

//ʵ�� ֲ���ս��ʬ�Ľ�ʬ���޸ģ������꣬�����꣩{�޸�����}
void pvz_zombie::modify(unsigned short x,
	unsigned short y)
{
	this->x = x; this->y = y;
}