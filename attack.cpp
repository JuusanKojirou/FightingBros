#include "attack.h"

ATattack::ATattack(const AToriginal_state* ori_state, ATattack_state attack_state):ATelements(ori_state){
	type = attack_state.type;
	range = attack_state.range;
	duration = attack_state.duration;
	buff = attack_state.buff;
	belong = attack_state.belong;
}
int* ATattack::attack_get_buff(){
	int * at=buff;
	return at;
}

int ATattack::attack_get_range(){
	return range;
}
attack_type ATattack:: attack_get_type(){
	return type;
}
int ATattack::attack_get_duration(){
	return duration;
}
int ATattack::attack_get_belong(){
	return belong;
}