#include "element.h"

void ATelements::element_change_position(int* p){
	position[0] = p[0];
	position[1] = p[1]; 
}
//change_time=-1表示永久改变，其余表示改变时间，speedup=0且change_time=-1表示恢复之前速度（也可以自己定义）

int ATelements::element_change_damage(int change_time, int damageup){
	if( (speedup == 0)&&(change_time == -1) ){
		present_damage = normal_damage;
		return RESTORE;
	}
	else if(change_time == -1){
		normal_damage += damageup;
		if(normal_damage > max_damage)
			normal_damage = max_damage;
		present_damage = normal_damage;
		return CHANG;
	}else if(change_time > 0){
		present_damage += damageup;
		return 	BUFF;
	}else{
		return ERROR;
	}
}

int ATelements::element_change_direction(double degree){
	direction += degree;
	return RESULT_OK;
}
