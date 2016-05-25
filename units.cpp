
#include "units.h"


ATunit::ATunit(const AToriginal_state* ori_state,ATunit_state unit_state):ATelements(ori_state){
	size=unit_state.size;
	HP=unit_state.HP;
	max_HP=MAX_HP;
	portrait=unit_state.portrait;
	//buff??
}

void ATunit::unit_be_hurt(int damage,attack_buff buff){//这个buff 应该没有用
	HP-=damage;

	if(HP<=0){
		HP==0;
	}
}

int ATunit:: unit_get_portrait(){
	return portrait;
}
int* ATunit::unit_get_HP(){
	int* a;
	a=new int;
	*a=HP;
	return a;
}
int ATunit::unit_check_state(){
	if(*buff==slower)
		element_change_speed()
	if(unit_get_HP==0)
		return DEAD;
	
}

//enum attack_buff{
//	slower,blood,stun,burn
//	int element_change_damage(int change_mode, int damageup);//同速度