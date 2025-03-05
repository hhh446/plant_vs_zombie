//���� ֲ���ս��ʬ�Ľ�ɫ
#include "pvz_character.h"

//ʵ�� ֲ���ս��ʬ��Ч���๹�캯�������ƣ�����������ʱ�䣩
// Ϊ��Ա���Ը�ֵ����Ա���ԣ������б��������ƣ����ƣ���
// ������������������ʱ�䣨����ʱ�䣩{}
pvz_effect::pvz_effect(string name, unsigned long power,
	unsigned long s) :name(name), power(power), s(s) {}

//ʵ�� ֲ���ս��ʬ��Ч����������������{}
pvz_effect::~pvz_effect() {}

//ʵ�� ֲ���ս��ʬ��Ч�����¡��������{���Ʋ����ط��ص�ǰ����}
shared_ptr<pvz_effect>pvz_effect::clone()
{
	return make_shared<pvz_effect>(*this);
}


//ʵ�� ֲ���ս��ʬ�Ľ�ɫ�๹�캯���������꣬�����꣬��������
// �����뾶���ƶ��ٶȣ���־����ʼ״̬�б�
// Ϊ��Ա���Ը�ֵ����Ա���ԣ������б����������꣨�����꣩��
// �����꣨�����꣩��������������������������Χ��������Χ����
// �ٶȣ��ٶȣ�����־����־��{����״̬�б�����״̬����}
pvz_character::pvz_character(unsigned short x,
	unsigned short y, unsigned short r, unsigned short v,
	char sign, vector<shared_ptr<pvz_effect>>new_effects)
	:x(x), y(y), r(r), v(v), sign(sign)
{
	using_effects(new_effects);
}

//ʵ�� ֲ���ս��ʬ�Ľ�ɫ��������������{}
pvz_character::~pvz_character() {}

//ʵ�� ֲ���ս��ʬ�����״̬����������״̬�б�{}
void pvz_character::using_effects
(vector<shared_ptr<pvz_effect>>new_effects)
{
	//����������Ч����{�ѵ�ǰЧ����ӵ�״̬�б�}
	for (shared_ptr<pvz_effect>& i : new_effects)
	{
		effects.push_back(i->clone());
	}
}