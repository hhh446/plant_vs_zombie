//������ָ�� �����õ�ǰͷ�ļ���������Ŀֻ����һ�Σ���ֹ�ض���
#pragma once

//���� ��׼���������
#include <iostream>

//���� ��̬��������
#include <vector>

using namespace std;

//���� ֲ���ս��ʬ��Ч��
class pvz_effect
{
public:

	string name;//����
	unsigned long power, s;//����������ʱ��

	//���� ���죨���ƣ�����������ʱ�䣩��
	pvz_effect(string name, unsigned long power,
		unsigned long s);

	//���� ����������
	~pvz_effect();

	//���� ��¡������
	shared_ptr<pvz_effect>clone();
};

//���� ֲ���ս��ʬ�Ľ�ɫ
class pvz_character
{
public:

	//�жϵ�ǰ��ɫ�Ƿ���ڣ��˺�ֵ����
	virtual char exist(unsigned short power = 0) = 0;

	//��ȡ���ݣ�Ŀ�����ݣ���
	virtual unsigned short look(char goal) = 0;

	//��״̬�б����Ч��������Ч������
	void using_effects
	(vector<shared_ptr<pvz_effect>>new_effects);
	
protected:

	//���캯���������꣬�����꣬�ƶ��ٶȣ���־��Ч���б���
	pvz_character(unsigned short x, unsigned short y,
		unsigned short r, unsigned short v, char sign,
		vector<shared_ptr<pvz_effect>>new_effects);

	//��������������
	~pvz_character();

	//��־
	char sign;

	//�����꣬�����꣬�뾶���ٶȣ�Ѫ��
	unsigned short x, y, r, v, hp;

	//״̬�б�
	vector<shared_ptr<pvz_effect>>effects;
};