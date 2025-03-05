//包含 植物大战僵尸的部分僵尸
#include "pvz_zombies.h"

//实现 植物大战僵尸的僵尸1类构造（x方向，y方向，横坐标，纵坐标）
// 赋值成员属性（参数列表）：植物大战僵尸的僵尸类构造（x方向，y方向，
// 横坐标，纵坐标，攻击力，攻击范围，移动速度，标志，血量，效果列表）
// {}
pvz_zombie_1::pvz_zombie_1(short x_direction,
	short y_direction, unsigned short x, unsigned short y)
	:pvz_zombie(x_direction, y_direction, x, y, 1, 1, 1, '*', 10,
		{}) {}

//实现 植物大战僵尸的僵尸1类析构（）{}
pvz_zombie_1::~pvz_zombie_1() {}

//实现 植物大战僵尸的僵尸1类过滤效果（）{}
void pvz_zombie_1::filter_effects()
{

}

//实现 植物大战僵尸的僵尸1类攻击（）{返回效果列表给被攻击的一方}
vector<shared_ptr<pvz_effect>>pvz_zombie_1::attack()
{
	return {};
}

//实现 植物大战僵尸的僵尸1类克隆（）{深拷贝自己并返回}
shared_ptr<pvz_zombie>pvz_zombie_1::clone()
{
	return make_shared<pvz_zombie_1>(*this);
}

//实现 植物大战僵尸的僵尸1类移动（）{改变坐标}
void pvz_zombie_1::move()
{
	x += x ? x_direction : v;
	y += y ? y_direction : v;
}