//���� �����
#include "player.h"

//���� ֲ���ս��ʬ�����
class pvz_player :public player
{
public:

	pvz_player(unsigned short sun = 0);
	~pvz_player()override;

	void main_cycle()override;

protected:

	unsigned short sun;

	void initialize()override;
};