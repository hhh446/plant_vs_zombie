//���� ֲ���ս��ʬ��ֲ��1
#include "pvz_plant.h"

//���� ֲ���ս��ʬ�Ľ�ʬ
#include "pvz_zombie.h"

//���� ֲ���ս��ʬ�ĵ�ͼ��
class pvz_map
{
public:

	//���� ���� ��ѭ�������⣩=�գ�
	virtual void main_cycle(unsigned short& sun) = 0;

protected:

	//����
	unsigned short w, h;

	//��״������
	string now, backup;

	//��ǰ��ͼ���ڵ���ֲ���ʬ�б�
	vector<shared_ptr<pvz_shell>>shells;
	vector<shared_ptr<pvz_plant>>plants;
	vector<shared_ptr<pvz_zombie>>zombies;

	//���� ���죨���ߣ���
	pvz_map(unsigned short w, unsigned short h);

	//���� �� ��������=Ĭ�ϣ�
	virtual ~pvz_map() = default;
	
	//���� ���ƣ�����
	void draw();

	//���� ��ʼ��������
	void initialize();

	//���� �ƶ�������
	void move();

	//���� ���� ���ɽ�ʬ����=�գ�
	virtual void new_zombie() = 0;

	//���� �޸Ľ�ɫ��ֲ������꣬�����꣩��
	void modify_coordinates
	(shared_ptr<pvz_plant>& new_plant,
		unsigned short& x, unsigned short& y);

	//���� �޸Ľ�ɫ����ʬ�������꣬�����꣩��
	void modify_coordinates
	(shared_ptr<pvz_zombie>& new_zombie,
		unsigned short& x, unsigned short& y);
};

//ֲ���ս��ʬ�Ĺؿ��б��ڵ���ֲ���ʬ��ͼ��
extern vector<shared_ptr<pvz_map>>pvz_maps;
extern vector<shared_ptr<pvz_shell>>pvz_shells_guide;
extern vector<shared_ptr<pvz_plant>>pvz_plants_guide;
extern vector<shared_ptr<pvz_zombie>>pvz_zombies_guide;