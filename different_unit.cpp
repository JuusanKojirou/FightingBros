#include "different_unit.h"
//different_unit--dogface
ATdogface::ATdogface(const AToriginal_state* ori_state, ATunit_state unit_state,move_type ori_type):ATunit(ori_state,unit_state){
	type = ori_type;
}

move_type ATdogface::dogface_get_type(){
	return type;
}


//different_unit--hero
AThero::AThero(const AToriginal_state* ori_state, ATunit_state unit_state,AThero_state hero_state):ATunit(ori_state,unit_state){
	normal_attack_speed = hero_state.normal_attack_speed;
	present_attack_speed = hero_state.present_attack_speed;
	rotating_speed = hero_state.rotating_speed;
	ATunit ATunit(ori_state,unit_state);
}
int  AThero::hero_change_attack_speed(int change_time, int apup){   //ap means attack speed
	if( (apup == 0)&&(change_time == -1) ){
		present_attack_speed = normal_attack_speed;
		return RESTORE;
	}
	else if(change_time == -1){
		normal_attack_speed += apup;
		present_attack_speed = normal_attack_speed;
		return CHANGE;
	}else if(change_time > 0){
		present_attack_speed += apup;
		return 	BUFF;
	}else{
		return RESULT_ERROR;
	}
}

