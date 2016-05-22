#ifndef CHARACTER_H
#define CHARACTER_H
#include "different_unit.h"
class ATcharacter :public AThero{
private:
	attack_type type;
	int EP;//ÄÜÁ¿Öµ
public:
	ATcharacter(AThero_state state,attack_type ori_type);
};
#endif // !CHARACTER_H
