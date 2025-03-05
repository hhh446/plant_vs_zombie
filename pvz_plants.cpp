//包含 植物大战僵尸的部分植物
#include "pvz_plants.h"

//实现 植物大战僵尸的炮弹1类构造（x方向，y方向，横坐标，纵坐标）
// 赋值成员属性（参数列表）：植物大战僵尸的植物1类构造（x方向，
// y方向，横坐标，纵坐标，攻击力，攻击范围，移动速度，标志，
// 效果列表）{}
pvz_shell_1::pvz_shell_1(short x_direction,
	short y_direction, unsigned short x, unsigned short y)
	:pvz_shell(x_direction, y_direction, x, y, 1, 2, 2,
		'a', {}) {}

//实现 植物大战僵尸的炮弹1类析构（）{}
pvz_shell_1::~pvz_shell_1() {}

//实现 植物大战僵尸的炮弹1类克隆（）{深拷贝自己并返回}
shared_ptr<pvz_shell>pvz_shell_1::clone()
{
	return make_shared<pvz_shell_1>(*this);
}

//实现 植物大战僵尸的炮弹1类移动（）{修改坐标}
void pvz_shell_1::move()
{
	x += v * x_direction;
	y += v * y_direction;
}

//实现 植物大战僵尸的炮弹1类攻击（）{}
vector<shared_ptr<pvz_effect>>pvz_shell_1::attack()
{
	return {};
}


//实现 植物大战僵尸的植物1类构造（横坐标，纵坐标）
// 赋值成员属性（参数列表）：植物大战僵尸的植物类构造（血量，横坐标，
// 纵坐标，射程，射速，标志，效果列表）{}
pvz_plant_1::pvz_plant_1(unsigned short x,
	unsigned short y)
	:pvz_plant(10, x, y, 120, 1, 'A', {}) {}

//实现 植物大战僵尸的植物1类析构（）{}
pvz_plant_1::~pvz_plant_1() {}

//实现 植物大战僵尸的植物1类过滤效果（）{}
void pvz_plant_1::filter_effects()
{

}

//实现 植物大战僵尸的植物1类攻击（）{返回炮弹1类指针对象}
shared_ptr<pvz_shell>pvz_plant_1::attack()
{
	return make_shared<pvz_shell_1>(1, 0, x + 1, y);
}

//实现 植物大战僵尸的植物1类克隆（）{深拷贝自己并返回}
shared_ptr<pvz_plant>pvz_plant_1::clone()
{
	return make_shared<pvz_plant_1>(*this);
}