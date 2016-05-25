#ifndef ATTACK_H
#define ATTACK_H
#include "elements.h"
//������ʽ����ս��Զ�̣�ħ��
enum attack_type
{
	melee,remote,magic
};
//��������buff�����٣���Ѫ����ѣ��ȼ��
enum attack_buff{
	slower,blood,stun,burn
};
struct ATattack_state{
	attack_type type;
	attack_buff* buff;
	int belong;//����������
	int range;//������Χ
	int duration;//��������ʱ�䣬��ս�ͼ���
};
class ATattack:public ATelements{
private:
	attack_type type;
	int range;
	int duration;
	attack_buff *buff;
	int belong;//�ж��˺�ʱ���˺�������������
public:
	ATattack(const AToriginal_state* ori_state,ATattack_state attack_state):ATelements(ori_state){};//����ATattack�࣬����������Ϣ
};
#endif // !ATTACK_H
