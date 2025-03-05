//编译器指令 可以让当前头文件在整个项目只编译一次，防止重定义
#pragma once

//声明 玩家类
class player
{
public://公共权限

	//声明 虚 析构（）=默认；
	virtual ~player() = default;
	//声明 纯虚 主循环（）=空；
	virtual void main_cycle() = 0;

protected://保护权限

	//积分
	unsigned short score = 0;

	//声明 构造（积分）；
	player(unsigned short score = 0);

	//声明 纯虚 初始化（）=空；
	virtual void initialize() = 0;
};