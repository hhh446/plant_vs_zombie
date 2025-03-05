//������ָ�� �����õ�ǰͷ�ļ���������Ŀֻ����һ�Σ���ֹ�ض���
#pragma once

//���� ֲ���ս��ʬ�Ľ�ɫ
#include "pvz_character.h"

//���� ֲ���ս��ʬ���ڵ�
class pvz_shell :public pvz_character
{
public:

	//���� ���ڣ��˺�ֵ����д��
	char exist(unsigned short power = 0)override;

	//���� �۲죨Ŀ�꣩��д��
	unsigned short look(char goal)override;

	//���� ���� �ƶ�����=�գ�
	virtual void move() = 0;

	//���� ���� ��������=�գ�
	virtual vector<shared_ptr<pvz_effect>>attack() = 0;

protected:

	//x����y����
	short x_direction, y_direction;

	//������
	unsigned short power;

	//���� ���죨x����y���򣬳�ʼ�����꣬��ʼ�����꣬��������
	// ɱ�˰뾶���ƶ��ٶȣ���־����ʼ״̬�б���
	pvz_shell(short x_direction, short y_direction,
		unsigned short x, unsigned short y,
		unsigned short power, unsigned short r,
		unsigned short v, char sign,
		vector<shared_ptr<pvz_effect>>new_effects);

	//���� �� ��������=Ĭ�ϣ�
	virtual ~pvz_shell() = default;

	//���� ���� ��������=�գ�
	virtual shared_ptr<pvz_shell>clone() = 0;
};

//���� ֲ���ս��ʬ��ֲ��
class pvz_plant :public pvz_character
{
	//������Ԫ ֲ���ս��ʬ�ĵ�ͼ��
	friend class pvz_map;

public:

	//���� ���ڣ��˺�ֵ����д��
	char exist(unsigned short power = 0)override;

	//���� ���� ����Ч������=�գ�
	virtual void filter_effects() = 0;

	//���� ִ��Ч��������
	void perform_effects();

	//���� ���� ��������=�գ�
	virtual shared_ptr<pvz_shell>attack() = 0;

	//���� ���� ��¡����=�գ�
	virtual shared_ptr<pvz_plant>clone() = 0;

	//���� �۲죨Ŀ�꣩��д��
	unsigned short look(char goal)override;

protected:

	//Ѫ��
	unsigned short hp;

	//���� ���죨Ѫ���������꣬�����꣬��̣����٣���־����Ч������
	pvz_plant(unsigned short hp, unsigned short x,
		unsigned short y, unsigned short r,
		unsigned short v, char sign,
		vector<shared_ptr<pvz_effect>>new_effects);

	//���� �� ��������=Ĭ�ϣ�
	virtual ~pvz_plant() = default;

	//���� �޸ģ������꣬�����꣩��
	void modify(unsigned short x, unsigned short y);
};