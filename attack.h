#ifndef ATTACK_H
#define ATTACK_H
#include "elements.h"
//攻击方式：近战，远程，魔法
enum attack_type
{
	melee,remote,magic
};
enum attack_buff{
	slower,blood,stun,burn
};
struct ATattack_state{
	attack_type type;
	attack_buff* buff;
	int owner;
	int range;
	int duration;
};
class ATattack:public ATelements{
private:
	attack_type type;
	int range;
	int duration;
	attack_buff *buff;
	int owner;
public:
	ATattack(AToriginal_state state,ATattack_state attack);//返回ATattack类，包括所有信息
};
#endif // !ATTACK_H
