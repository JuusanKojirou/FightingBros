#ifndef PROCEDURES_H
#define PROCEDURES_H
#define SHAPE_RECTANGLE 4
#define SHAPE_CIRCLE 2
//signal type
#define ROTATE_CIR 1
#define	ROTATE_ANTICIR 2
#define RELEASE_ATTACK 3
#include <vector>
#include <list>
#include <string>
#include "attack.h"
#include "different_unit.h"
#include "character.h"
struct ATmap_obstacle{
	int shape;
	int* shape_paramenter;
};
struct ATmap{
	std::vector<ATmap_obstacle>load_map;
	std::vector<ATcharacter> load_charater;
};
class ATjudgement{
private:
	std::list<ATattack> attack_information;
	std::list<ATcharacter> character_information;
	std::list<ATdogface> dogface_information;
	int unit_ID;
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
