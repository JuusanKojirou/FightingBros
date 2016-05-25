#include "elements.h"


ATelements::ATelements(const AToriginal_state* origin_state){
	element_ID=origin_state->ID_number;
	position=new int[2];
	position[0]=origin_state->position[0];
	position[1]=origin_state->position[1];
	direction=origin_state->direction;
	present_damage=origin_state->damage[0];
	normal_damage=origin_state->damage[1];
	max_damage=MAX_DAMAGE;
	present_speed=origin_state->speed[0];
	normal_speed=origin_state->speed[1];
	max_speed=MAX_SPEED;
}

void ATelements::element_change_position(int* p){
	position[0] = p[0];
	position[1] = p[1]; 
}
//change_time=-1表示永久改变，其余表示改变时间，speedup=0且change_time=-1表示恢复之前速度（也可以自己定义）


int ATelements::element_change_damage(int change_time, int damageup){
	if( (damageup == 0)&&(change_time == -1) ){
		present_damage = normal_damage;
		return RESTORE;
	}
	else if(change_time == -1){
		normal_damage += damageup;
		if(normal_damage > max_damage)
			normal_damage = max_damage;
		present_damage = normal_damage;
		return CHANGE;
	}else if(change_time > 0){
		present_damage += damageup;
		return 	BUFF;
	}else{
		return RESULT_ERROR;
	}
}
int ATelements::element_change_speed(int change_time, int speedup){
	if( (speedup == 0)&&(change_time == -1) ){
		present_speed = normal_speed;
		return RESTORE;
	}
	else if(change_time == -1){
		normal_speed += speedup;
		if(normal_speed > max_speed)
			normal_speed = max_speed;
		present_speed = normal_speed;
		return CHANGE;
	}else if(change_time > 0){
		present_speed += speedup;
		return 	BUFF;
	}else{
		return RESULT_ERROR;
	}
}

int ATelements::element_change_direction(double degree){
	direction += degree;
	return RESULT_OK;
}


int* ATelements:: element_get_position()
{
	int *p;
	p=new int(2);
	p[0]=position[0];
	p[1]=position[1];
	return p;
}

int ATelements:: element_get_speed()
{
	return present_speed;
}

int ATelements:: element_get_damage()
{
	return present_damage;
}

double ATelements::  element_get_direction()
{
	return direction;
}
int  ATelements::  element_get_ID()
{
	return element_ID;
}