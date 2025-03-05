//������ָ�� �����õ�ǰͷ�ļ���������Ŀֻ����һ�Σ���ֹ�ض���
#pragma once

//���� ֲ���ս��ʬ�Ľ�ɫ
#include "pvz_character.h"

//���� ֲ���ս��ʬ�Ľ�ʬ
class pvz_zombie :public pvz_character
{
	//������Ԫ ֲ���ս��ʬ�ĵ�ͼ��
	friend class pvz_map;

public:

	//���� ���ڣ���������д��
	char exist(unsigned short power = 0)override;

	//���� ���� ����Ч������=�գ�
	virtual void filter_effects() = 0;

	//���� ִ��Ч��������
	void perform_effects();

	//���� �۲죨Ŀ�꣩��д��
	unsigned short look(char goal)override;

	//���� ���� ��������=�գ�
	virtual vector<shared_ptr<pvz_effect>>attack() = 0;

	//���� ���� ��¡����=�գ�
	virtual shared_ptr<pvz_zombie>clone() = 0;

	//���� ���� �ƶ�����=�գ�
	virtual void move() = 0;

protected:

	//x����y����
	short x_direction, y_direction;

	//Ѫ����������
	unsigned short hp, power;

	//���� ���죨x����y���򣬺����꣬�����꣬�������������뾶��
	// �ƶ��ٶȣ���־��Ѫ����Ч���б���
	pvz_zombie(short x_direction, short y_direction,
		unsigned short x, unsigned short y,
		unsigned short power, unsigned short r,
		unsigned short v, char sign, unsigned short hp,
		vector<shared_ptr<pvz_effect>>new_effects);

	//���� �� ��������=Ĭ�ϣ�
	virtual ~pvz_zombie() = default;

	//���� �޸ģ������꣬�����꣩��
	void modify(unsigned short x, unsigned short y);
};