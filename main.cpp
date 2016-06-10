#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "attack.h"
#include "different_unit.h"
#include "character.h"

using namespace std;

int main(){

	const struct AToriginal_state ori_state_st={110,{1,2},0.4,{3,4},{5,6}};
	const struct AToriginal_state* ori_state=&ori_state_st;
	ATelements element(ori_state);
	cout<<element.element_get_speed()<<endl;

	element.element_change_speed(10,1);

	cout<<element.element_get_speed()<<endl;
	system("pause");
}