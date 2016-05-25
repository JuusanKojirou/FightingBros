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

};//��ʼ״̬��
class ATelements{
private:
	int element_ID;
	int present_speed,normal_speed, max_speed;//��ǰ�ٶȣ������ٶȺ��ٶ�����
	double direction;//���򣬴洢�Ƕ�
	int present_damage,normal_damage,max_damage;//�˺�,ͬ�ٶ�
	int *position;//λ��
public:
	ATelements(const AToriginal_state* origin_state);//״̬��ʼ��
	int element_change_speed(int change_mode,int speedup);//change_mode=CHANGE��ʾ���øı�,�ı�normal��present��BUFF��ʾ��ʱ�ı䣬ֻ�ı�present��speedup=0��change_mode=-RESTORE��ʾ�ָ�֮ǰ�ٶȣ�Ҳ�����Լ����壩
	void element_change_position(int* p);//*p����x��y�������
	int element_change_damage(int change_mode, int damageup);//ͬ�ٶ�
	int element_change_direction(double degree);//�ı䷽��
	int* element_get_position();
	int element_get_speed();
	int element_get_damage();
	double element_get_direction();
	int element_get_ID();
};
#endif // !ELEMENTS_H
