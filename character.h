#ifndef CHARACTER_H
#define CHARACTER_H
#include "different_unit.h"
class ATcharacter :public AThero{
private:
	attack_type type;
	int EP;//ÄÜÁ¿Öµ
public:
	ATcharacter(const AToriginal_state* ori_state, ATunit_state unit_state,AThero_state hero_state,attack_type ori_type):AThero(ori_state,unit_state,hero_state){};
	ATattack character_attack();
};
#endif // !CHARACTER_H
