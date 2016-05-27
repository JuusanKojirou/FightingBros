#include "procedures.h"

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
		case RELEASE_ATTACK:{judgement_add_attack((*i).hero_attack()); }
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

