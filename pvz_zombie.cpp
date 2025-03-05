//包含 植物大战僵尸的僵尸
#include "pvz_zombie.h"

//实现 植物大战僵尸的僵尸类构造（x方向，y方向，横坐标，纵坐标，
// 攻击力，杀伤半径，移动速度，标志，效果列表，血量）
// 赋值成员属性（参数列表）：x方向（x方向），y方向（y方向），
// 横坐标（初始横坐标），纵坐标（初始纵坐标），攻击力（攻击力），
// 杀伤半径（杀伤半径），移动速度（移动速度），标志（标志），
// 效果列表（效果列表），血量（血量）{}
pvz_zombie::pvz_zombie(short x_direction,
	short y_direction, unsigned short x, unsigned short y,
	unsigned short power, unsigned short r,
	unsigned short v, char sign, unsigned short hp,
	vector<shared_ptr<pvz_effect>>new_effects)
	:x_direction(x_direction), y_direction(y_direction),
	pvz_character(x, y, r, v, sign, new_effects),
	hp(hp), power(power) {}

//实现 植物大战僵尸的僵尸类执行效果（）{}
void pvz_zombie::perform_effects()
{
	//过滤可免疫的效果
	filter_effects();
}

//实现 植物大战僵尸的僵尸类存在（伤害值）{}
char pvz_zombie::exist(unsigned short power)
{
	//自身血量减少，unsigned类型不能出现负数，伤害较高时血量归零
	hp -= hp < power ? hp : power;

	//自身死亡时提示当前角色已死亡
	return hp ? sign : 0;
}

//实现 植物大战僵尸的僵尸类观察（目标）{根据目标返回属性}
unsigned short pvz_zombie::look(char goal)
{
	if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	if (goal == 'p')return power;
	return 0;
}

//实现 植物大战僵尸的僵尸类修改（横坐标，纵坐标）{修改属性}
void pvz_zombie::modify(unsigned short x,
	unsigned short y)
{
	this->x = x; this->y = y;
}