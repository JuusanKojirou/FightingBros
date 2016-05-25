#ifndef UNITS_H
#define	UNITS_H
#include "elements.h"
#include "attack.h"
#define MAX_HP 100
#define DEAD 0

struct ATunit_state
{
	int size;
	int HP, max_HP;
	int portrait;
};

class ATunit:public ATelements{
private:
	int size;
	int HP, max_HP;
	int portrait;
	attack_buff *buff;//buff�Ĵ�С���ܵ�buff����һ�£�ÿ�������buff�ĳ���ʱ�䣬buff��������-1��ʾ��
public:
	ATunit(const AToriginal_state* ori_state,ATunit_state unit_state):ATelements(ori_state){};
	void unit_be_hurt(int damage,attack_buff buff);
	int unit_check_state();//���buff=0��change_mode=RESTORE������element_change����
	int* unit_get_HP();
	int unit_get_portrait();
};
#endif // !UNITS_H
