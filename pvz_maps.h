//���� ֲ���ս��ʬ�ĵ�ͼ
#include "pvz_map.h"

//���� ֲ���ս��ʬ�Ĺؿ�1��
class pvz_map_1 :public pvz_map
{
	//���� ���ɽ�ʬ������д��
	void new_zombie()override;

public:

	//���� ���죨���ߣ���
	pvz_map_1(unsigned short w = 120,
		unsigned short h = 30);

	//���� ����������д��
	~pvz_map_1()override;

	//���� ��ѭ�������⣩��д��
	void main_cycle(unsigned short& sun)override;
};