#include<stdio.h>
#include<windows.h>
#include <Time.h>

typedef void (*PFunc)(int*);

//コールバック関数
void DispResult(int* s) {

	//printf("正解\n", *s);	
	//printf("正解\n", *s);
}

void setTimeOut(PFunc p, int second) {

	//コールバック関数を呼び出す
	Sleep(second * 1000);

	p(&second);

}

void diceGame() {

	//初期化
	unsigned int Time = time(nullptr);
	srand(Time);

	const int diceNum = 2;//個数
	int dice[diceNum];//出目
	int Total = 0;//出目の計

	//サイコロの出目を決める
	for (int i = 0; i < diceNum; i++)
	{
		dice[i] = rand() % 6;

		Total += dice[i];
	}

	printf("（d：０　h：１）\n");

	//２択を選ぶ
	int a = 0;
	scanf_s("%d", &a);

	if (a == 0)
	{
		printf("選択\n");
	}
	else if (a == 1)
	{
		printf("\n");
	}

	//コールバック関数
	PFunc p;
	p = DispResult;//ここで中身を入れる(実行する関数を切り替えることもできる)
	
	setTimeOut(p, 3);//3秒たったら実行

	//結果表示
	if (Total % 2 == 0)
	{

		if (a == 0)
		{
			printf("正解\n");
		}
		else if (a == 1)
		{
			printf("不正解\n");
		}

		printf("結果\n");
	}
	else if (Total % 2 == 1)
	{

		if (a == 0)
		{
			printf("不正解\n");
		}
		else if (a == 1)
		{
			printf("正解\n");
		}

		printf("結果　中間\n");
	}


	printf("出目[%d] [%d]\n", dice[0], dice[1]);
	printf("出目の計 %d\n", Total);





}




int main() {
	//関数ポインタを宣言
	diceGame();
	
	return 0;
}