#ifndef ELEMENTS_H
#define ELENENTS_H
struct AToriginal_state
{
	int position[2];
	double direction;
	int damage;
	int speed[2];

};//初始状态量
class ATelements{
private:
	int present_speed,normal_speed, max_speed;//速度和速度上限
	double direction;//方向，存储角度
	int damage;//伤害
	int *position;//位置
public:
	ATelements(const AToriginal_state* origin_state);//状态初始化
	int element_change_speed(int change_time,int speedup);//change_time=-1表示永久改变，其余表示改变时间，speedup=0且change_time=-1表示恢复之前速度（也可以自己定义）
	void element_change_position(int* p);
	int element_change_damage(int change_time, int damageup);
	int element_change_direction(double degree);
	int* element_get_position();
	int element_get_speed();
	int element_get_damage();
};
#endif // !ELEMENTS_H
