#ifndef ATTACK_H
#define ATTACK_H
#include "elements.h"
//������ʽ����ս��Զ�̣�ħ��
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
	ATattack(AToriginal_state state,ATattack_state attack);//����ATattack�࣬����������Ϣ
};
#endif // !ATTACK_H
