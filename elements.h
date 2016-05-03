#ifndef ELEMENTS_H
#define ELENENTS_H
struct AToriginal_state
{
	int position[2];
	double direction;
	int damage;
	int speed[2];

};//��ʼ״̬��
class ATelements{
private:
	int present_speed,normal_speed, max_speed;//�ٶȺ��ٶ�����
	double direction;//���򣬴洢�Ƕ�
	int damage;//�˺�
	int *position;//λ��
public:
	ATelements(const AToriginal_state* origin_state);//״̬��ʼ��
	int element_change_speed(int change_time,int speedup);//change_time=-1��ʾ���øı䣬�����ʾ�ı�ʱ�䣬speedup=0��change_time=-1��ʾ�ָ�֮ǰ�ٶȣ�Ҳ�����Լ����壩
	void element_change_position(int* p);
	int element_change_damage(int change_time, int damageup);
	int element_change_direction(double degree);
	int* element_get_position();
	int element_get_speed();
	int element_get_damage();
};
#endif // !ELEMENTS_H
