//包含 植物大战僵尸的植物
#include "pvz_plant.h"

//声明 炮弹1类 继承自：炮弹类
class pvz_shell_1 :public pvz_shell
{
public:

	//声明 构造（x方向，y方向，横坐标，纵坐标）；
	pvz_shell_1(short x_direction = 0,
		short y_direction = 0,
		unsigned short x = 0, unsigned short y = 0);

	//声明 析构（）重写；
	~pvz_shell_1()override;

	//声明 克隆（）重写；
	shared_ptr<pvz_shell>clone()override;

	//声明 移动（）重写；
	void move()override;

	//声明 攻击（）重写；
	vector<shared_ptr<pvz_effect>>attack()override;
};

//声明 植物1类 继承自：植物类
class pvz_plant_1 :public pvz_plant
{
public:

	//声明 构造（横坐标，纵坐标）；
	pvz_plant_1(unsigned short x = 0,
		unsigned short y = 0);

	//声明 析构（）重写；
	~pvz_plant_1()override;

	//声明 过滤效果（）重写；
	void filter_effects()override;

	//声明 攻击（）重写；
	shared_ptr<pvz_shell>attack()override;

	//声明 克隆（）重写；
	shared_ptr<pvz_plant>clone()override;
};