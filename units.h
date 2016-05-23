#ifndef UNITS_H
#define	UNITS_H
#include "elements.h"
#include "attack.h"
class ATunit:public ATelements{
private:
	int size;
	int HP, max_HP;
	int portrait;
	attack_buff *buff;//buff的大小和总的buff种类一致，每个里面存buff的持续时间，buff不存在用-1表示；
public:
	ATunit(AToriginal_state state,int ori_size,int ori_HP,int ori_portrait);
	int unit_be_hurt(int damage,attack_buff buff);
	int unit_check_state();//如果buff=0，change_mode=RESTORE，调用element_change函数
	int* unit_get_HP();
	int unit_get_portrait();
};
#endif // !UNITS_H
