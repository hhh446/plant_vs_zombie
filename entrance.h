//包含 标准输入输出流
#include <iostream>

//包含 动态数组容器
#include <vector>

//包含 玩家
#include "player.h"

//导入 std命名空间
using namespace std;

//声明 入口
class entrance :public player
{
	//声明 初始化（）重写；
	void initialize()override;

public:

	//声明 构造（）；
	entrance();

	//声明 析构（）重写；
	~entrance()override;

	//声明 主循环（）重写；
	void main_cycle()override;
};

//声明 程序入口
extern shared_ptr<entrance>program_entrance;