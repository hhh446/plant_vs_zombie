//编译器指令 可以让当前头文件在整个项目只编译一次，防止重定义
#pragma once

//包含 标准输入输出流
#include <iostream>

//包含 动态数组容器
#include <vector>

using namespace std;

//声明 植物大战僵尸的效果
class pvz_effect
{
public:

	string name;//名称
	unsigned long power, s;//威力，持续时间

	//声明 构造（名称，威力，持续时间）；
	pvz_effect(string name, unsigned long power,
		unsigned long s);

	//声明 析构（）；
	~pvz_effect();

	//声明 克隆（）；
	shared_ptr<pvz_effect>clone();
};

//声明 植物大战僵尸的角色
class pvz_character
{
public:

	//判断当前角色是否存在（伤害值）；
	virtual char exist(unsigned short power = 0) = 0;

	//获取数据（目标数据）；
	virtual unsigned short look(char goal) = 0;

	//往状态列表添加效果（新增效果）；
	void using_effects
	(vector<shared_ptr<pvz_effect>>new_effects);
	
protected:

	//构造函数（横坐标，纵坐标，移动速度，标志，效果列表）；
	pvz_character(unsigned short x, unsigned short y,
		unsigned short r, unsigned short v, char sign,
		vector<shared_ptr<pvz_effect>>new_effects);

	//析构函数（）；
	~pvz_character();

	//标志
	char sign;

	//横坐标，纵坐标，半径，速度，血量
	unsigned short x, y, r, v, hp;

	//状态列表
	vector<shared_ptr<pvz_effect>>effects;
};