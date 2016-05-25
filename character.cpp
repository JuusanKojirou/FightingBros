#include "character.h"

ATcharacter::ATcharacter(const AToriginal_state* ori_state, ATunit_state unit_state,AThero_state hero_state,attack_type ori_type):AThero(ori_state,unit_state,hero_state){
	type=ori_type;
}

ATattack ATcharacter::character_attack(){
	ATattack a();
}