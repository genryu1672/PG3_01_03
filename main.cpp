#include<stdio.h>
#include<windows.h>

typedef void (*PFunc)(int*);

int twice(int a) {
	return a * 2;
}

int triple(int a) {
	return a * 3;
}

//�R�[���o�b�N�֐�
void DispResult(int* s) {

	//printf("����\n", *s);	
	printf("����\n", *s);
}

void setTimeOut(PFunc p, int second) {

	//�R�[���o�b�N�֐����Ăяo��
	Sleep(second * 1000);

	p(&second);

}

int main() {
	//�֐��|�C���^��錾
	//void(*pfunc)();
	
	scanf_s("%d\n");//�o��
	
	//scanf_s("�s����\n");//�o��
	PFunc p;
	p = DispResult;//�����Œ��g������(���s����֐���؂�ւ��邱�Ƃ��ł���)
	setTimeOut(p,3);//3�b����������s
	return 0;
}