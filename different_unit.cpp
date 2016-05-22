#include "different_unit.h"

ATdogface ATdogface::ATdogface(AToriginal_state state, move_type ori_type, int ori_size, int ori_HP, int ori_portrait){
	ATunit(AToriginal_state state, int ori_size,int ori_HP, int ori_portrait);
	type = ori_type;
}

move_type dogface_get_type(){
	return type;
}

AThero AThero::AThero(AThero_state state){
	attack_speed = state.attack_speed;
	rotating_speed = state.rotating_speed;
	
	AToriginal_state hero_original_state;
	hero_original_state.ID_number = state.hero_ID;
	hero_original_state.position = state.position;
	hero_original_state.direction = state.direction;
	hero_original_state.damage = state.damage;
	hero_original_state.speed = state.speed;
	ATunit(hero_original_state, size, HP, ///这里开始)
}

