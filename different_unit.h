#ifndef DIFFERENT_UNIT_H
#define DIFFERENT_UNIT_H
#include "units.h"
//移动方式，正常，加速，闪现
enum move_type
{
	run,rush,flash
};
struct AThero_state
{
	int normal_attack_speed;
	int present_attack_speed;
	int rotating_speed;
};
class ATdogface :public ATunit{
private:
	move_type type;
public:
	ATdogface(const AToriginal_state* ori_state, ATunit_state unit_state,move_type ori_type):ATunit(ori_state,unit_state){};
	move_type dogface_get_type();
};
class AThero :public ATunit{
private:
	int normal_attack_speed;
	int present_attack_speed;
	int rotating_speed;
public:
	AThero(const AToriginal_state* ori_state,ATunit_state unit_state,AThero_state state):ATunit(ori_state,unit_state){};
	int hero_change_attack_speed(int change_time, int apup);
	
	
};
#endif // !DIFFERENT_UNIT_H
