#include<stdio.h>
#include<windows.h>

typedef void (*PFunc)(int*);

int twice(int a) {
	return a * 2;
}

int triple(int a) {
	return a * 3;
}

//コールバック関数
void DispResult(int* s) {

	//printf("正解\n", *s);	
	printf("正解\n", *s);
}

void setTimeOut(PFunc p, int second) {

	//コールバック関数を呼び出す
	Sleep(second * 1000);

	p(&second);

}

int main() {
	//関数ポインタを宣言
	//void(*pfunc)();
	
	scanf_s("%d\n");//出力
	
	//scanf_s("不正解\n");//出力
	PFunc p;
	p = DispResult;//ここで中身を入れる(実行する関数を切り替えることもできる)
	setTimeOut(p,3);//3秒たったら実行
	return 0;
}