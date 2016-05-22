#ifndef DIFFERENT_UNIT_H
#define DIFFERENT_UNIT_H
#include "units.h"
//�ƶ���ʽ�����������٣�����
enum move_type
{
	run,rush,flash
};
struct AThero_state
{
	int attack_speed;
	int rotating_speed;
	int size;
	int HP, max_HP;
	int portrait;
	int present_speed, normal_speed, max_speed;//�ٶȺ��ٶ�����
	double direction;//���򣬴洢�Ƕ�
	int damage;//�˺�
	int *position;//λ��
};
class ATdogface :public ATunit{
private:
	move_type type;
public:
	ATdogface(AToriginal_state state, move_type ori_type, int ori_size, int ori_HP, int ori_portrait);
	move_type dogface_get_type();
};
class AThero :public ATunit{
private:
	int attack_speed;
	int rotating_speed;
public:
	AThero(AThero_state state);
	ATattack hero_attack();
	int hero_change_attack_speed();
	
	
};
#endif // !DIFFERENT_UNIT_H
