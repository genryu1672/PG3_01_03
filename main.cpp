#include<stdio.h>
#include<windows.h>
#include <Time.h>

typedef void (*PFunc)(int*);

//�R�[���o�b�N�֐�
void DispResult(int* s) {

	//printf("����\n", *s);	
	//printf("����\n", *s);
}

void setTimeOut(PFunc p, int second) {

	//�R�[���o�b�N�֐����Ăяo��
	Sleep(second * 1000);

	p(&second);

}

void diceGame() {

	//������
	unsigned int Time = time(nullptr);
	srand(Time);

	const int diceNum = 2;//��
	int dice[diceNum];//�o��
	int Total = 0;//�o�ڂ̌v

	//�T�C�R���̏o�ڂ����߂�
	for (int i = 0; i < diceNum; i++)
	{
		dice[i] = rand() % 6;

		Total += dice[i];
	}

	printf("�id�F�O�@h�F�P�j\n");

	//�Q����I��
	int a = 0;
	scanf_s("%d", &a);

	if (a == 0)
	{
		printf("�I��\n");
	}
	else if (a == 1)
	{
		printf("\n");
	}

	//�R�[���o�b�N�֐�
	PFunc p;
	p = DispResult;//�����Œ��g������(���s����֐���؂�ւ��邱�Ƃ��ł���)
	
	setTimeOut(p, 3);//3�b����������s

	//���ʕ\��
	if (Total % 2 == 0)
	{

		if (a == 0)
		{
			printf("����\n");
		}
		else if (a == 1)
		{
			printf("�s����\n");
		}

		printf("����\n");
	}
	else if (Total % 2 == 1)
	{

		if (a == 0)
		{
			printf("�s����\n");
		}
		else if (a == 1)
		{
			printf("����\n");
		}

		printf("���ʁ@����\n");
	}


	printf("�o��[%d] [%d]\n", dice[0], dice[1]);
	printf("�o�ڂ̌v %d\n", Total);





}




int main() {
	//�֐��|�C���^��錾
	diceGame();
	
	return 0;
}