#include "attack.h"

ATattack ATattack::ATattack(AToriginal_state state, ATattack_state attack){
	type = attack.type;
	range = attack.range;
	duration = attack.duration;
	buff = attack.buff;
	owner = attack.owner;
	ATelements(AToriginal_state);
}