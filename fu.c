#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define ROW 3
#define COL 3

void menu()
{
	printf("************************************\n");
	printf("********   1、开始(简单)   *********\n");
	printf("********   2、开始(困难)   *********\n");
	printf("********     0、结束       *********\n");
	printf("***********************************\n");
}

void IBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void CBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
				
		}
		if (i < row - 1)
		{
			printf("\n");
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");

				}
			}
		}
		printf("\n");
	}
}

void PlayerBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x <= row && x > 0 && y <= col && y > 0)
		{
			if (board[x - 1][y - 1] == ' ')//x和y减都1是为了方便输入
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}
}

void CmperEasy(char board[ROW][COL], int row, int col)
{
	printf("电脑输入\n");
	while (1)
	{
		//生成随机坐标
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] ==' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

void CmperHard(char board[ROW][COL], int row, int col)
{
	printf("电脑输入\n");
	//判断第一行
	if ((board[0][0] == ' ' && board[0][1] == '*' && board[0][2] == '*') || (board[0][0] == ' ' && board[0][1] == '#' && board[0][2] == '#'))
	{
		board[0][0] = '#';
	}
	else if ((board[0][0] == '*' && board[0][1] == ' ' && board[0][2] == '*') || (board[0][0] == '#' && board[0][1] == ' ' && board[0][2] == '#'))
	{
		board[0][1] = '#';
	}
	else if ((board[0][0] == '*' && board[0][1] == '*' && board[0][2] == ' ') || (board[0][0] == '#' && board[0][1] == '#' && board[0][2] == ' '))
	{
		board[0][2] = '#';
	}
	//判断第二行
	else if ((board[1][0] == ' ' && board[1][1] == '*' && board[1][2] == '*') || (board[1][0] == ' ' && board[1][1] == '#' && board[1][2] == '#'))
	{
		board[1][0] = '#';
	}
	else if ((board[1][0] == '*' && board[1][1] == ' ' && board[1][2] == '*') || (board[1][0] == '#' && board[1][1] == ' ' && board[1][2] == '#'))
	{
		board[1][1] = '#';
	}
	else if ((board[1][0] == '*' && board[1][1] == '*' && board[1][2] == ' ') || (board[1][0] == '#' && board[1][1] == '#' && board[1][2] == ' '))
	{
		board[1][2] = '#';
	}
	//判断第三行
	else if (board[2][0] == ' ' && board[2][1] == '*' && board[2][2] == '*' || board[2][0] == ' ' && board[2][1] == '#' && board[2][2] == '#')
	{
		board[2][0] = '#';
	}
	else if (board[2][0] == '*' && board[2][1] == ' ' && board[2][2] == '*' || board[2][0] == '#' && board[2][1] == ' ' && board[2][2] == '#')
	{
		board[2][1] = '#';
	}
	else if (board[2][0] == '*' && board[2][1] == '*' && board[2][2] == ' ' || board[2][0] == '#' && board[2][1] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
	}
	//判断第一列
	else if (board[0][0] == ' ' && board[1][0] == '*' && board[2][0] == '*' || board[0][0] == ' ' && board[1][0] == '#' && board[2][0] == '#')
	{
		board[0][0] = '#';
	}
	else if (board[0][0] == '*' && board[1][0] == ' ' && board[2][0] == '*' || board[0][0] == '#' && board[1][0] == ' ' && board[2][0] == '#')
	{
		board[1][0] = '#';
	}
	else if (board[0][0] == '*' && board[1][0] == '*' && board[2][0] == ' ' || board[0][0] == '#' && board[1][0] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
	}
	//判断第二列
	else if (board[0][1] == ' ' && board[1][1] == '*' && board[2][1] == '*' || board[0][1] == ' ' && board[1][1] == '#' && board[2][1] == '#')
	{
		board[0][1] = '#';
	}
	else if (board[0][1] == '*' && board[1][1] == ' ' && board[2][1] == '*' || board[0][1] == '#' && board[1][1] == ' ' && board[2][1] == '#')
	{
		board[1][1] = '#';
	}
	else if (board[0][1] == '*' && board[1][1] == '*' && board[2][1] == ' ' || board[0][1] == '#' && board[1][1] == '#' && board[2][1] == ' ')
	{
		board[2][1] = '#';
	}
	//判断第三列
	else if (board[0][2] == ' ' && board[1][2] == '*' && board[2][2] == '*' || board[0][2] == ' ' && board[1][2] == '#' && board[2][2] == '#')
	{
		board[0][2] = '#';
	}
	else if (board[0][2] == '*' && board[1][2] == ' ' && board[2][2] == '*' || board[0][2] == '#' && board[1][2] == ' ' && board[2][2] == '#')
	{
		board[1][2] = '#';
	}
	else if (board[0][2] == '*' && board[1][2] == '*' && board[2][2] == ' ' || board[0][2] == '#' && board[1][2] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
	}
	//判断左对角线
	else if (board[0][0] == ' ' && board[1][1] == '*' && board[2][2] == '*' || board[0][0] == ' ' && board[1][1] == '#' && board[2][2] == '#')
	{
		board[0][0] = '#';
	}
	else if (board[0][0] == '*' && board[1][1] == ' ' && board[2][2] == '*' || board[0][0] == '#' && board[1][1] == ' ' && board[2][2] == '#')
	{
		board[1][1] = '#';
	}
	else if (board[0][0] == '*' && board[1][1] == '*' && board[2][2] == ' ' || board[0][0] == '#' && board[1][1] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
	}
	//判断右对角线
	else if (board[0][2] == ' ' && board[1][1] == '*' && board[2][0] == '*' || board[0][2] == ' ' && board[1][1] == '#' && board[2][0] == '#')
	{
		board[0][2] = '#';
	}
	else if (board[0][2] == '*' && board[1][1] == ' ' && board[2][0] == '*' || board[0][2] == '#' && board[1][1] == ' ' && board[2][0] == '#')
	{
		board[1][1] = '#';
	}
	else if (board[0][2] == '*' && board[1][1] == '*' && board[2][0] == ' ' || board[0][2] == '#' && board[1][1] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
	}
	else if (board[1][1] != '*' && board[1][1] != '#')
	{
		board[1][1] = '#';
	}
	else
	{
		/*while (1)
		{
			int x = 0;
			int y = 0;
			x = rand() % row;
			y = rand() % col;
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
		}*/
		CmperEasy(board, ROW, COL);
	}
}

int IsFull(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Winer(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int ret = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断斜线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'P';
	}
	return 'J';
}

void game(int n)
{
	char t = 0;
	//初始化棋盘
	char board[ROW][COL] = { 0 };
	IBoard(board, ROW, COL);

	//打印棋盘
	CBoard(board, ROW, COL);

	while (1)
	{
		//玩家下棋
		PlayerBoard(board, ROW, COL);
		CBoard(board, ROW, COL);
		system("cls");//清屏
		//判断玩家胜利
		t = Winer(board, ROW, COL);
		if (t != 'J')
		{
			break;
		}
		//电脑下棋
		switch (n)
		{
		case 1:
		{
			CmperEasy(board, ROW, COL);
			CBoard(board, ROW, COL);
			break;
		}
		case 2:
		{
			CmperHard(board, ROW, COL);
			CBoard(board, ROW, COL);
			break;
		}
		}
		//判断电脑胜利
		t = Winer(board, ROW, COL);
		if (t != 'J')
		{
			break;
		}
	}
	//判断其他状态
	if (t == '*')
	{
		CBoard(board, ROW, COL);
		printf("游戏结束，玩家胜利^_^\n");
	}
	else if (t == '#')
	{
		CBoard(board, ROW, COL);
		printf("游戏结束，电脑胜利~_~\n");
	}
	else
	{
		CBoard(board, ROW, COL);
		printf("游戏结束，平局\n");
	}
	printf("再来一局\n");
}

int main()
{
	//三子棋项目
	srand((unsigned int)time(NULL));//时间戳
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		system("cls");//清屏，更加美观
		switch (input)
		{
		case 1:
		{
			game(input);
			break;
		}
		case 2:
		{
			game(input);
			break;
		}
		case 0:
		{
			printf("结束\n");
			break;
		}
		default:
		{
			printf("输入错误,重新输入\n");
			break;
		}
		}
	} while (input);
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_age(const void* e1,const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int sort_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//int main()
//{
//	struct Stu s[] = { {"付青云",20},{"刘济鸿",19},{"李琨琨",22},{"钟金林",21} };
//	int num = sizeof(s) / sizeof(s[0]);
//	//按照年龄排序
//	qsort(s, num, sizeof(s[0]), sort_age);
//	//按照名字排序
////	qsort(s, num, sizeof(s[0]), sort_name);
//
//	for (int i = 0; i < num; i++)
//	{
//		printf("%s %d\n", s[i].name, s[i].age);
//	}
//	return 0;
//}