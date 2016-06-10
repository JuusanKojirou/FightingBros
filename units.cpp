
#include "units.h"


ATunit::ATunit(const AToriginal_state* ori_state,ATunit_state unit_state):ATelements(ori_state){
	size=unit_state.size;
	HP=unit_state.HP;
	max_HP=MAX_HP;
	portrait=unit_state.portrait;
	//buff??
}

void ATunit::unit_be_hurt(int damage,attack_buff be_hurt_buff){//这个buff 应该没有用
	HP-=damage;

	if(be_hurt_buff==slower){
	buff[0]=MAX_BUFF_TIME;
	}
	if(be_hurt_buff==blood){
	buff[1]=MAX_BUFF_TIME;
	}
	if(be_hurt_buff==stun){
	buff[2]=MAX_BUFF_TIME;
	}
	if(be_hurt_buff==burn){
	buff[3]=MAX_BUFF_TIME;
	}
	if(HP<=0){
		HP=0;
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
	if(buff[slower]>0){
		element_change_speed(buff[0],1);
		buff[slower]--;
	}
	if(buff[blood]>0){
		unit_be_hurt(5,normal);
		buff[blood]--;
	}
	if(buff[stun]>0){
		buff[stun]--;
	}
	if(buff[burn]>0){
		element_change_damage(buff[0],1);
		buff[burn]--;
	}
	if(unit_get_HP()==0)
		return DEATH;
	else
		return ALIVE;
}

int ATunit::unit_get_size(){
		return size;
}

int ATunit::unit_get_buff(){
	return *buff;
}

bool ATunit::unit_if_stun(){
	if(buff[3]>-1)
		return true;
	else
		return false;
}

