#include <cmath>
#include <math.h>
#include "procedures.h"

// Zhang Lu
//信息文件中储存  attackRangeDegree, attackTimeGap
void ATjudgement::judgement_add_dogface(ATdogface new_dogface){
	dogface_information.push_back(new_dogface);
}

void ATjudgement::judgement_add_attack(ATattack new_attack){
	ATattackAndTime new_attackAndTime;
	new_attackAndTime.attack = new_attack;///重载问题?
	new_attackAndTime.timeRemained = new_attack.attack_get_duration();/////////
	attack_information.push_back(new_attackAndTime);         
}

void ATjudgement::judgement_attacks_impdamage(std::list<ATattackAndTime>::iterator attackAndTimeIter, std::list<ATcharacter>::iterator charaIter){
	std::list<ATattackAndTime>::iterator i = attackAndTimeIter;
	std::list<ATcharacter>::iterator j = charaIter;
	int damage = (*i).attack.element_get_damage();
	///////////attack_get_buff??
	///unit_be _hurt只是hp减,没有
	int* attackBuff = (*i).attack.attack_get_buff();
	if(attackBuff[0] > 0){
		(*j).unit_be_hurt(damage, slower);
	}
	if(attackBuff[1] > 0){
		(*j).unit_be_hurt(damage, blood);
	}
	if(attackBuff[2] > 0){
		(*j).unit_be_hurt(damage, stun);
	}
	if(attackBuff[3] > 0){
		(*j).unit_be_hurt(damage, burn);
	}
	if(attackBuff[4] > 0){
		(*j).unit_be_hurt(damage, normal);
	}
}
//远程是碰到人（我）或者碰到墙消失，近程有个时间，每次需要减，攻击时间到，去除（我）
///有一个持续时间，如果时间到了就结束 
void ATjudgement::judgement_attacks(){
	for(auto i = attack_information.begin(); i != attack_information.end(); ){
		while((*i).timeRemained == 0){//循环？
			attack_information.erase(i);
			if(attack_information.empty())
				break;
		}
		int hitflg = 0;
		for(auto j = character_information.begin(); j != character_information.end(); ++j){
			// character judgement first. Followed by dogface judgement.
			if((*i).attack.attack_get_belong() != (*j).element_get_ID()){
				int* posAttack = (*i).attack.element_get_position();
				int* posCharacter = (*j).element_get_position();
				double distance = std::sqrt(std::pow(posAttack[0] - posCharacter[0], 2.0) + std::pow(posAttack[1] - posCharacter[1], 2.0));
				if( (posCharacter[0] - posAttack[0]) >= 0 )
					double dirAttackUnit = std::atan((posCharacter[0] - posAttack[0])/(posCharacter[1] - posAttack[1]));
				else{
					if( (posCharacter[1] - posAttack[1]) >= 0 )
						double dirAttackUnit = Pi/2 + std::atan((posCharacter[0] - posAttack[0])/(posCharacter[1] - posAttack[1]));
					else
						double dirAttackUnit = (-1)*Pi/2 + std::atan((posCharacter[0] - posAttack[0])/(posCharacter[1] - posAttack[1]));
				}
				double attackDir = (*i).attack.element_get_direction();
				double dirStart = attackDir - attackRangeDegree;//undefined
				double dirEnd = attackDir + attackRangeDegree;
				int attackRange = (*i).attack.attack_get_range();
				int unitSize = (*j).unit_get_size();
				double extradir = std::asin(unitSize / distance);
				if( (dirStart < dirAttackUnit)&&(dirAttackUnit < dirEnd) ){
					if(distance < (attackRange + unitSize)){
						judgement_attacks_impdamage(i, j);
						attack_information.erase(i);
						hitflg = 1;
						break;
					}
				}else if( (dirAttackUnit > dirEnd)&&(dirAttackUnit < (extradir + dirEnd)) ){
					double k0 = std::tan(dirEnd);
					double k1 = -1 / k0;
					double crossX = ( posCharacter[1] - posAttack[1] - k1 * posCharacter[0] + k0 * posAttack[0] ) / (k0 - k1);
					double crossY = k0 * crossX + posAttack[1] - k0 * posAttack[0];
					double distance2cross = std::sqrt( std::pow((crossX - posAttack[0]), 2.0) + std::pow((crossY - posAttack[1]), 2.0) );
					if(distance < std::sqrt( std::pow(unitSize, 2.0) + std::pow(distance2cross, 2.0) )){
						judgement_attacks_impdamage(i, j);
						attack_information.erase(i);
						hitflg = 1;
						break;
					}
				}else if( (dirAttackUnit < dirStart)&&(dirAttackUnit > (dirStart - extradir)) ){
					double k0 = std::tan(dirStart);
					double k1 = -1 / k0;
					double crossX = ( posCharacter[1] - posAttack[1] - k1 * posCharacter[0] + k0 * posAttack[0] ) / (k0 - k1);
					double crossY = k0 * crossX + posAttack[1] - k0 * posAttack[0];
					double distance2cross = std::sqrt( std::pow((crossX - posAttack[0]), 2.0) + std::pow((crossY - posAttack[1]), 2.0) );
					if(distance < std::sqrt( std::pow(unitSize, 2.0) + std::pow(distance2cross, 2.0) )){
						judgement_attacks_impdamage(i, j);
						attack_information.erase(i);
						hitflg = 1;
						break;
					}
				}
			}else{
				continue;
			}
			if(hitflg == 0){
				if((*i).attack.attack_get_type() == melee)///////////不需要timegap
					(*i).timeRemained -= attackTimeGap;
				i++;
			}
		}
		for(auto j = dogface_information.begin(); j != dogface_information.end(); ++j){
			if((*i).attack.attack_get_belong() != (*j).element_get_ID()){
				int* posAttack = (*i).attack.element_get_position();
				int* posCharacter = (*j).element_get_position();
				double distance = std::sqrt(std::pow(posAttack[0] - posCharacter[0], 2.0) + std::pow(posAttack[1] - posCharacter[1], 2.0));
				if( (posCharacter[0] - posAttack[0]) >= 0 )
					double dirAttackUnit = std::atan((posCharacter[0] - posAttack[0])/(posCharacter[1] - posAttack[1]));
				else{
					if( (posCharacter[1] - posAttack[1]) >= 0 )
						double dirAttackUnit = Pi/2 + std::atan((posCharacter[0] - posAttack[0])/(posCharacter[1] - posAttack[1]));
					else
						double dirAttackUnit = (-1)*Pi/2 + std::atan((posCharacter[0] - posAttack[0])/(posCharacter[1] - posAttack[1]));
				}
				double attackDir = (*i).attack.element_get_direction();
				double dirStart = attackDir - attackRangeDegree;//undefined
				double dirEnd = attackDir + attackRangeDegree;
				int attackRange = (*i).attack.attack_get_range();
				int unitSize = (*j).unit_get_size();
				double extradir = std::asin(unitSize / distance);
				if( (dirStart < dirAttackUnit)&&(dirAttackUnit < dirEnd) ){
					if(distance < (attackRange + unitSize)){
						judgement_attacks_impdamage(i, j);
						attack_information.erase(i);
						hitflg = 1;
						break;
					}
				}else if( (dirAttackUnit > dirEnd)&&(dirAttackUnit < (extradir + dirEnd)) ){
					double k0 = std::tan(dirEnd);
					double k1 = -1 / k0;
					double crossX = ( posCharacter[1] - posAttack[1] - k1 * posCharacter[0] + k0 * posAttack[0] ) / (k0 - k1);
					double crossY = k0 * crossX + posAttack[1] - k0 * posAttack[0];
					double distance2cross = std::sqrt( std::pow((crossX - posAttack[0]), 2.0) + std::pow((crossY - posAttack[1]), 2.0) );
					if(distance < std::sqrt( std::pow(unitSize, 2.0) + std::pow(distance2cross, 2.0) )){
						judgement_attacks_impdamage(i, j);
						attack_information.erase(i);
						hitflg = 1;
						break;
					}
				}else if( (dirAttackUnit < dirStart)&&(dirAttackUnit > (dirStart - extradir)) ){
					double k0 = std::tan(dirStart);
					double k1 = -1 / k0;
					double crossX = ( posCharacter[1] - posAttack[1] - k1 * posCharacter[0] + k0 * posAttack[0] ) / (k0 - k1);
					double crossY = k0 * crossX + posAttack[1] - k0 * posAttack[0];
					double distance2cross = std::sqrt( std::pow((crossX - posAttack[0]), 2.0) + std::pow((crossY - posAttack[1]), 2.0) );
					if(distance < std::sqrt( std::pow(unitSize, 2.0) + std::pow(distance2cross, 2.0) )){
						judgement_attacks_impdamage(i, j);
						attack_information.erase(i);
						hitflg = 1;
						break;
					}
				}
			}else{
				continue;
			}
			if(hitflg == 0){
				if((*i).attack.attack_get_type() == melee)///////////不需要timegap
					(*i).timeRemained -= attackTimeGap;
				i++;
			}
		}
	}
	
}

void ATjudgement::judgement_check_state(){
	for(auto i = dogface_information.begin(); i != dogface_information.end(); ++i){
		if((*i).unit_check_state() == DEATH){
			dogface_information.erase(i);
		}
	}
	for(auto i = character_information.begin(); i != character_information.end(); ++i)
		if((*i).unit_check_state() == DEATH){
			character_information.erase(i);
		}
}

// Zhang Chi
ATjudgement::ATjudgement(ATmap initial_map){
	ATcharacter* temp;
	for (auto i = initial_map.load_charater.begin(); i != initial_map.load_charater.end(); ++i)
		 character_information.push_back(*i);
	for (auto i = initial_map.load_map.begin(); i != initial_map.load_map.end(); ++i)
		obstacle_information.push_back(*i);
	unit_ID = 5;

}
int ATjudgement::judgement_map_edge(int *pp, int size){
		if (pp[ROLE_X] > max_x - size)
			pp[ROLE_X] = max_x - size;
		if (pp[ROLE_X] < size)
			pp[ROLE_X] = size;
		if (pp[ROLE_Y] > max_y - size)
			pp[ROLE_Y] = max_y - size;
		if (pp[ROLE_Y] < size)
			pp[ROLE_Y] = size;
		return POSITION_OK;
}
int ATjudgement::judgement_rectangle(ATmap_obstacle rectangle_obstacle, int *pp, int size){
	double temp_x, temp_y, r;
	if ((pp[ROLE_X] <= rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X] - size || pp[ROLE_X] >= rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X] + size) && (pp[ROLE_Y] <= rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y] - size || pp[ROLE_Y] >= rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y] + size))
		return POSITION_OK;
	if (pp[ROLE_X] < rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X] && pp[ROLE_Y] < rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y]){
		r = sqrt((pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X])*(pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X]) + (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y])*(pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y]));
		temp_x = (pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X])*size / r + RECTANGLE_MIN_X;
		temp_y = (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y])*size / r + RECTANGLE_MIN_Y;
		pp[ROLE_X] = (int)temp_x;
		pp[ROLE_Y] = (int)temp_y;
		return POSITION_ERROR
	}
	if (pp[ROLE_X] > rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X] && pp[ROLE_Y] < rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y]){
		r = sqrt((pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X])*(pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X]) + (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y])*(pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y]));
		temp_x = (pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X])*size / r + RECTANGLE_MAX_X;
		temp_y = (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y])*size / r + RECTANGLE_MIN_Y;
		pp[ROLE_X] = (int)temp_x;
		pp[ROLE_Y] = (int)temp_y;
		return POSITION_ERROR;
	}
	if (pp[ROLE_X] < rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X] && pp[ROLE_Y] > rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y]){
		r = sqrt((pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X])*(pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X]) + (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y])*(pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y]));
		temp_x = (pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X])*size / r + RECTANGLE_MIN_X;
		temp_y = (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y])*size / r + RECTANGLE_MAX_Y;
		pp[ROLE_X] = (int)temp_x;
		pp[ROLE_Y] = (int)temp_y;
		return POSITION_ERROR;
	}
	if (pp[ROLE_X] > rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X] && pp[ROLE_Y] > rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y]){
		r = sqrt((pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X])*(pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X]) + (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y])*(pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y]));
		temp_x = (pp[ROLE_X] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X])*size / r + RECTANGLE_MAX_X;
		temp_y = (pp[ROLE_Y] - rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y])*size / r + RECTANGLE_MAX_Y;
		pp[ROLE_X] = (int)temp_x;
		pp[ROLE_Y] = (int)temp_y;
		return POSITION_ERROR;
	}
	if (pp[ROLE_X] < rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_X]){
		pp[ROLE_X] = RECTANGLE_MIN_X - size;
		return POSITION_ERROR;
	}
	if (pp[ROLE_X] > rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_X]){
		pp[ROLE_X] = RECTANGLE_MAX_X + size;
		return POSITION_ERROR;
	}
	if (pp[ROLE_Y] < rectangle_obstacle.shape_paramenter[RECTANGLE_MIN_Y]){
		pp[ROLE_Y] = RECTANGLE_MIN_Y - size;
		return POSITION_ERROR;
	}
	if (pp[ROLE_Y] > rectangle_obstacle.shape_paramenter[RECTANGLE_MAX_Y]){
		pp[ROLE_Y] = RECTANGLE_MAX_Y + size;
		return POSITION_ERROR;
	}
	
}

int ATjudgement::judgement_circle(ATmap_obstacle circle_obstacle, int *pp, int size){
	double temp_x, temp_y, r;
	r = sqrt((pp[ROLE_X] - circle_obstacle.shape_paramenter[CIRCLE_X])*(pp[ROLE_X] - circle_obstacle.shape_paramenter[CIRCLE_X]) + (pp[ROLE_Y] - circle_obstacle.shape_paramenter[CIRCLE_Y])*(pp[ROLE_Y] - circle_obstacle.shape_paramenter[CIRCLE_Y]));
	if (r < circle_obstacle.shape_paramenter[CIRCLE_R] + size){
		temp_x = (pp[ROLE_X] - circle_obstacle.shape_paramenter[CIRCLE_X])*(size + circle_obstacle.shape_paramenter[CIRCLE_R]) / r + circle_obstacle.shape_paramenter[CIRCLE_X];
		temp_y = (pp[ROLE_Y] - circle_obstacle.shape_paramenter[CIRCLE_Y])*(size + circle_obstacle.shape_paramenter[CIRCLE_R]) / r + circle_obstacle.shape_paramenter[CIRCLE_Y];
		pp[ROLE_X] = (int)temp_x;
		pp[ROLE_Y] = (int)temp_y;

	}
	return POSITION_ERROR;
}
void ATjudgement::judgement_get_signal(int character_ID, int signal_type, int value_1, double value_2){
	for (auto i = character_information.begin(); i != character_information.end();++i)
	if ((*i).element_get_ID==character_ID)
		switch (signal_type){
		case ROTATE_CIR:{(*i).element_change_direction(value_2);}
		case ROTATE_ANTICIR:{(*i).element_change_direction(-value_2); }
		case RELEASE_ATTACK:{judgement_add_attack((*i).character_attack()); }
	}

}
void ATjudgement::judgement_check_position(){
	int new_position[2];
	int *temp;
	int result;
	for (auto i = character_information.begin(); i != character_information.end(); ++i){
		if ((*i).unit_get_buff){//stun Ìø¹ý
			continue;
		}
		
		new_position[ROLE_X] += (int)cos((*i).element_get_direction());
		new_position[ROLE_Y] += (int)sin((*i).element_get_direction());
		judgement_map_edge(new_position, (*i).unit_get_size());
		for (auto j = obstacle_information.begin(); j != obstacle_information.end(); ++j){
			if ((*j).shape == SHAPE_RECTANGLE)
				judgement_rectangle((*j),new_position,(*i).unit_get_size());
			if ((*j).shape == SHAPE_CIRCLE)
				judgement_circle((*j),new_position,(*i).unit_get_size());

		}
		(*i).element_change_position(new_position);
			
	}
}
