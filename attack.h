#ifndef ATTACK_H
#define ATTACK_H
#include "elements.h"
//攻击方式：近战，远程，魔法
enum attack_type
{
	melee,remote,magic
};
//攻击所带buff，减速，流血，晕眩，燃烧
enum attack_buff{
	slower=0,blood,stun,burn,normal
};
struct ATattack_state{
	attack_type type;
	int* buff;
	int belong;//攻击发出者
	int range;//攻击范围
	int duration;//攻击持续时间，近战和技能
};
class ATattack:public ATelements{
private:
	attack_type type;
	int range;
	int duration;
	int *buff;
	int belong;//判定伤害时不伤害发出攻击的人
public:
	ATattack(const AToriginal_state* ori_state,ATattack_state attack_state);//返回ATattack类，包括所有信息
	int* attack_get_buff();
	int attack_get_range();
	attack_type attack_get_type();
	int attack_get_duration();
	int attack_get_belong();

};
#endif // !ATTACK_H
