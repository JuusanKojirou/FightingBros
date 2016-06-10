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
	slower=0,blood,stun,burn,normal
};
struct ATattack_state{
	attack_type type;
	int* buff;
	int belong;//����������
	int range;//������Χ
	int duration;//��������ʱ�䣬��ս�ͼ���
};
class ATattack:public ATelements{
private:
	attack_type type;
	int range;
	int duration;
	int *buff;
	int belong;//�ж��˺�ʱ���˺�������������
public:
	ATattack(const AToriginal_state* ori_state,ATattack_state attack_state);//����ATattack�࣬����������Ϣ
	int* attack_get_buff();
	int attack_get_range();
	attack_type attack_get_type();
	int attack_get_duration();
	int attack_get_belong();

};
#endif // !ATTACK_H
