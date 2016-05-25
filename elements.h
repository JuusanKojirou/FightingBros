#ifndef ELEMENTS_H
#define ELENENTS_H
#define RESTORE -1;
#define	BUFF 0;
#define CHANGE 1;
#define	RESULT_ERROR 250;
#define	RESULT_OK 66;
#define MAX_SPEED 20;
#define MAX_DAMAGE 1000;

struct AToriginal_state
{
	int ID_number;
	int position[2];
	double direction;
	int damage[2];
	int speed[2];

};//初始状态量
class ATelements{
private:
	int element_ID;
	int present_speed,normal_speed, max_speed;//当前速度，正常速度和速度上限
	double direction;//方向，存储角度
	int present_damage,normal_damage,max_damage;//伤害,同速度
	int *position;//位置
public:
	ATelements(const AToriginal_state* origin_state);//状态初始化
	int element_change_speed(int change_mode,int speedup);//change_mode=CHANGE表示永久改变,改变normal和present；BUFF表示临时改变，只改变present；speedup=0且change_mode=-RESTORE表示恢复之前速度（也可以自己定义）
	void element_change_position(int* p);//*p包括x和y轴的坐标
	int element_change_damage(int change_mode, int damageup);//同速度
	int element_change_direction(double degree);//改变方向
	int* element_get_position();
	int element_get_speed();
	int element_get_damage();
	double element_get_direction();
	int element_get_ID();
};
#endif // !ELEMENTS_H
