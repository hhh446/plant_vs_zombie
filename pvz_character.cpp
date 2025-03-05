//包含 植物大战僵尸的角色
#include "pvz_character.h"

//实现 植物大战僵尸的效果类构造函数（名称，威力，持续时间）
// 为成员属性赋值（成员属性（参数列表））：名称（名称），
// 威力（威力），持续时间（持续时间）{}
pvz_effect::pvz_effect(string name, unsigned long power,
	unsigned long s) :name(name), power(power), s(s) {}

//实现 植物大战僵尸的效果类析构函数（）{}
pvz_effect::~pvz_effect() {}

//实现 植物大战僵尸的效果类克隆函数（）{复制并返回返回当前对象}
shared_ptr<pvz_effect>pvz_effect::clone()
{
	return make_shared<pvz_effect>(*this);
}


//实现 植物大战僵尸的角色类构造函数（横坐标，纵坐标，攻击力，
// 攻击半径，移动速度，标志，初始状态列表）
// 为成员属性赋值（成员属性（参数列表））：横坐标（横坐标），
// 纵坐标（纵坐标），攻击力（攻击力），攻击范围（攻击范围），
// 速度（速度），标志（标志）{设置状态列表（新增状态）；}
pvz_character::pvz_character(unsigned short x,
	unsigned short y, unsigned short r, unsigned short v,
	char sign, vector<shared_ptr<pvz_effect>>new_effects)
	:x(x), y(y), r(r), v(v), sign(sign)
{
	using_effects(new_effects);
}

//实现 植物大战僵尸的角色类析构函数（）{}
pvz_character::~pvz_character() {}

//实现 植物大战僵尸的添加状态函数（新增状态列表）{}
void pvz_character::using_effects
(vector<shared_ptr<pvz_effect>>new_effects)
{
	//遍历（新增效果）{把当前效果添加到状态列表}
	for (shared_ptr<pvz_effect>& i : new_effects)
	{
		effects.push_back(i->clone());
	}
}