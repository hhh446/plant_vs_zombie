//包含 玩家类
#include "player.h"

//声明 植物大战僵尸的玩家
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