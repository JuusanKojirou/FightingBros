#ifndef UNITS_H
#define	UNITS_H
#include "elements.h"
#include "attack.h"
class ATunit:public ATelements{
private:
	int size;
	int HP, max_HP;
	int portrait;
	attack_buff* buff;
public:
	ATunit(AToriginal_state state,int ori_size,int ori_HP,int ori_portrait);
	virtual int unit_be_hurt(int damage,attack_buff* buff);
};
#endif // !UNITS_H
