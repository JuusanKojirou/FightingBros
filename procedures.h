#ifndef PROCEDURES_H
#define PROCEDURES_H
#define SHAPE_RECTANGLE 4
#define SHAPE_CIRCLE 3
//signal type
#define ROTATE_CIR 1
#define	ROTATE_ANTICIR -1
#define RELEASE_ATTACK 3
#define RECTANGLE_MIN_X 0
#define	RECTANGLE_MAX_X 1
#define RECTANGLE_MIN_Y 2
#define RECTANGLE_MAX_Y 3
#define ROLE_X 0
#define ROLE_Y 1
#define CIRCLE_X 0
#define CIRCLE_Y 1
#define CIRCLE_R 3
#include <vector>
#include <list>
#include <string>
#include "attack.h"
#include "different_unit.h"
#include "character.h"
enum obstacle_type
{
	wall,glass,water,spring
};
struct ATmap_obstacle{
	int shape;
	obstacle_type type;
	int* shape_paramenter;
};
struct ATmap{
	int limit[2];
	std::vector<ATmap_obstacle>load_map;
	std::vector<ATcharacter> load_charater;
};
class ATjudgement{
private:
	std::list<ATattack> attack_information;
	std::list<ATcharacter> character_information;
	std::list<ATdogface> dogface_information;
	std::vector<ATmap_obstacle> obstacle_information;
	int unit_ID;//´Ó5¿ªÊ¼
	int max_x, max_y;
	int* judgement_rectangle(ATmap_obstacle rectangle_obstacle,int *pp,int size);
	int* judgement_circle(ATmap_obstacle circle_obstacle,int *pp,int size);
	int* judgement_map_edge(int *pp, int size);
public:
	ATjudgement(ATmap initial_map);//C
	void judgement_add_dogface(ATdogface new_dogface);//L
	void judgement_add_attack(ATattack new_attack); //L
	void judgement_get_signal(int charater_ID, int signal_type, int value_1, double value_2);//C
	void judgement_attacks();//L
	void judgement_check_state();//L
	void judgement_check_position();//C


};
#endif // !PROCEDURES_H
