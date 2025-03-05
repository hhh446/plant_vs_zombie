//包含 植物大战僵尸的僵尸
#include "pvz_zombie.h"

//声明 植物大战僵尸的僵尸1类
class pvz_zombie_1 :public pvz_zombie
{
public:

	//声明 构造（x方向，y方向，横坐标，纵坐标）；
	pvz_zombie_1(short x_direction = -1,
		short y_direction = 0,
		unsigned short x = 0, unsigned short y = 0);

	//声明 析构（）重写；
	~pvz_zombie_1()override;

	//声明 过滤效果（）重写；
	void filter_effects()override;

	//声明 攻击（）重写；
	vector<shared_ptr<pvz_effect>>attack()override;

	//声明 克隆（）重写；
	shared_ptr<pvz_zombie>clone()override;

	//声明 移动（）重写；
	void move()override;
};