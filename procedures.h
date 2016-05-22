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
	ATjudgement(ATmap initial_map);
	void judgement_add_dogface();
	void judgement_add_attack(ATattack new_attack);
	void judgement_get_signal(int charater_ID, int signal_type, int value_1, double value_2);
	void judgement_attacks();
	void judgement_check_state();
	void judgement_check_position();


};
#endif // !PROCEDURES_H
