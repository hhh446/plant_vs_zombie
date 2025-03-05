//包含 植物大战僵尸的植物1
#include "pvz_plant.h"

//包含 植物大战僵尸的僵尸
#include "pvz_zombie.h"

//声明 植物大战僵尸的地图类
class pvz_map
{
public:

	//声明 纯虚 主循环（阳光）=空；
	virtual void main_cycle(unsigned short& sun) = 0;

protected:

	//宽，高
	unsigned short w, h;

	//现状，副本
	string now, backup;

	//当前地图的炮弹、植物、僵尸列表
	vector<shared_ptr<pvz_shell>>shells;
	vector<shared_ptr<pvz_plant>>plants;
	vector<shared_ptr<pvz_zombie>>zombies;

	//声明 构造（宽，高）；
	pvz_map(unsigned short w, unsigned short h);

	//声明 虚 析构（）=默认；
	virtual ~pvz_map() = default;
	
	//声明 绘制（）；
	void draw();

	//声明 初始化（）；
	void initialize();

	//声明 移动（）；
	void move();

	//声明 纯虚 生成僵尸（）=空；
	virtual void new_zombie() = 0;

	//声明 修改角色（植物，横坐标，纵坐标）；
	void modify_coordinates
	(shared_ptr<pvz_plant>& new_plant,
		unsigned short& x, unsigned short& y);

	//声明 修改角色（僵尸，横坐标，纵坐标）；
	void modify_coordinates
	(shared_ptr<pvz_zombie>& new_zombie,
		unsigned short& x, unsigned short& y);
};

//植物大战僵尸的关卡列表，炮弹、植物、僵尸的图鉴
extern vector<shared_ptr<pvz_map>>pvz_maps;
extern vector<shared_ptr<pvz_shell>>pvz_shells_guide;
extern vector<shared_ptr<pvz_plant>>pvz_plants_guide;
extern vector<shared_ptr<pvz_zombie>>pvz_zombies_guide;