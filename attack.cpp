#include "attack.h"

ATattack::ATattack(const AToriginal_state* ori_state, ATattack_state attack_state):ATelements(ori_state){
	type = attack_state.type;
	range = attack_state.range;
	duration = attack_state.duration;
	buff = attack_state.buff;
	belong = attack_state.belong;
}