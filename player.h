//������ָ�� �����õ�ǰͷ�ļ���������Ŀֻ����һ�Σ���ֹ�ض���
#pragma once

//���� �����
class player
{
public://����Ȩ��

	//���� �� ��������=Ĭ�ϣ�
	virtual ~player() = default;
	//���� ���� ��ѭ������=�գ�
	virtual void main_cycle() = 0;

protected://����Ȩ��

	//����
	unsigned short score = 0;

	//���� ���죨���֣���
	player(unsigned short score = 0);

	//���� ���� ��ʼ������=�գ�
	virtual void initialize() = 0;
};