#ifndef UNITS_H
#define	UNITS_H
#include "elements.h"
#include "attack.h"
#define MAX_HP 100
#define DEATH 0
#define ALIVE 1
#define MAX_BUFF_TIME 30

struct ATunit_state
{
	int size;
	int HP, max_HP;
	int portrait;
};

class ATunit:public ATelements{
private:
	int size;
	int HP, max_HP;
	int portrait;
	int *buff;//buff的大小和总的buff种类一致，每个里面存buff的持续时间，buff不存在用-1表示；
public:
	ATunit(const AToriginal_state* ori_state,ATunit_state unit_state);
	void unit_be_hurt(int damage,attack_buff be_hurt_buff);
	int unit_check_state();//如果buff=0，change_mode=RESTORE，调用element_change函数
	int* unit_get_HP();
	int unit_get_portrait();
	int unit_get_size();
	int unit_get_buff();
	bool unit_if_stun();
	
};
#endif // !UNITS_H
