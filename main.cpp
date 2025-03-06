//包含 主程序
#include "main_program.h"

int main()
{
	//程序入口
	shared_ptr<main_program>program_entrance
		= make_shared<main_program>();
	program_entrance->main_cycle();
	return 0;
}
