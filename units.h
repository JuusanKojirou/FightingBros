#ifndef UNITS_H
#define	UNITS_H
#include "elements.h"
#include "attack.h"
class ATunit:public ATelements{
private:
	int size;
	int HP, max_HP;
	int portrait;
	attack_buff *buff;//buff�Ĵ�С���ܵ�buff����һ�£�ÿ�������buff�ĳ���ʱ�䣬buff��������-1��ʾ��
public:
	ATunit(AToriginal_state state,int ori_size,int ori_HP,int ori_portrait);
	int unit_be_hurt(int damage,attack_buff buff);
	void unit_check_state();//���buff=0��change_mode=RESTORE������element_change����
};
#endif // !UNITS_H
