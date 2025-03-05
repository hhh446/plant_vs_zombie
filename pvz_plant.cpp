//包含 植物大战僵尸的植物
#include "pvz_plant.h"

//实现 植物大战僵尸的炮弹类构造（x方向，y方向，横坐标，纵坐标，
// 攻击力，攻击半径，移动速度，标志，效果列表）
// 赋值成员属性（参数列表）：x方向（x方向），y方向（y方向），
// 植物大战僵尸的角色类构造（横坐标，纵坐标，攻击范围，移动速度，
// 标志，效果列表），攻击力（攻击力）{}
pvz_shell::pvz_shell(short x_direction, short y_direction,
	unsigned short x, unsigned short y,
	unsigned short power, unsigned short r,
	unsigned short v, char sign,
	vector<shared_ptr<pvz_effect>>new_effects)
	:x_direction(x_direction), y_direction(y_direction),
	pvz_character(x, y, r, v, sign, new_effects),
	power(power) {}

//实现 植物大战僵尸的炮弹类存在（伤害值）{}
char pvz_shell::exist(unsigned short power)
{
	//返回标志
	return sign;
}

//实现 植物大战僵尸的炮弹类观察（目标）{根据目标返回属性}
unsigned short pvz_shell::look(char goal)
{
	if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	if (goal == 'p')return power;
	return 0;
}


//实现 植物大战僵尸的植物类构造（血量，横坐标，纵坐标，射程，射速，
// 标志，效果列表）赋值成员属性（参数列表）：
// 植物大战僵尸的角色类构造（横坐标，纵坐标，射程，射速，标志，
// 效果列表），血量（血量）{}
pvz_plant::pvz_plant(unsigned short hp, unsigned short x,
	unsigned short y, unsigned short r, unsigned short v,
	char sign, vector<shared_ptr<pvz_effect>>new_effects)
	:pvz_character(x, y, r, v, sign, new_effects), hp(hp)
{}

//实现 植物大战僵尸的植物类执行效果（）{}
void pvz_plant::perform_effects()
{
	//过滤可免疫的效果（）；
	filter_effects();

	//执行无法免疫的效果...
}

//实现 植物大战僵尸的植物类存在（威力）{}
char pvz_plant::exist(unsigned short power)
{
	//自身血量减少，unsigned类型不能出现负数，伤害较高时血量归零
	hp -= hp < power ? hp : power;

	//自身死亡时提示当前角色已死亡
	return hp ? sign : 0;
}

//实现 植物大战僵尸的植物类观察（目标）{根据目标返回属性}
unsigned short pvz_plant::look(char goal)
{
	if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	return 0;
}

//实现 植物大战僵尸的植物类修改（横坐标，纵坐标）{修改属性}
void pvz_plant::modify(unsigned short x, unsigned short y)
{
	this->x = x; this->y = y;
}