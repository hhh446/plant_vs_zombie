//包含 标准输入输出流
#include <iostream>

//包含 动态数组容器
#include <vector>

//包含 玩家
#include "player.h"

//导入 std命名空间
using namespace std;

//声明 主程序
class main_program :public player
{
	//声明 初始化（）重写；
	void initialize()override;

public:

	//声明 构造（）；
	main_program();

	//声明 析构（）重写；
	~main_program()override;

	//声明 主循环（）重写；
	void main_cycle()override;
};
