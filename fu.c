#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define ROW 3
#define COL 3

void menu()
{
	printf("************************************\n");
	printf("********   1����ʼ(��)   *********\n");
	printf("********   2����ʼ(����)   *********\n");
	printf("********     0������       *********\n");
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
		printf("��������:>");
		scanf("%d %d", &x, &y);
		if (x <= row && x > 0 && y <= col && y > 0)
		{
			if (board[x - 1][y - 1] == ' ')//x��y����1��Ϊ�˷�������
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã���������\n");
			}
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	}
}

void CmperEasy(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
	while (1)
	{
		//�����������
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
	printf("��������\n");
	//�жϵ�һ��
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
	//�жϵڶ���
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
	//�жϵ�����
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
	//�жϵ�һ��
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
	//�жϵڶ���
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
	//�жϵ�����
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
	//�ж���Խ���
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
	//�ж��ҶԽ���
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
	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//�ж���
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�ж�б��
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
	//��ʼ������
	char board[ROW][COL] = { 0 };
	IBoard(board, ROW, COL);

	//��ӡ����
	CBoard(board, ROW, COL);

	while (1)
	{
		//�������
		PlayerBoard(board, ROW, COL);
		CBoard(board, ROW, COL);
		system("cls");//����
		//�ж����ʤ��
		t = Winer(board, ROW, COL);
		if (t != 'J')
		{
			break;
		}
		//��������
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
		//�жϵ���ʤ��
		t = Winer(board, ROW, COL);
		if (t != 'J')
		{
			break;
		}
	}
	//�ж�����״̬
	if (t == '*')
	{
		CBoard(board, ROW, COL);
		printf("��Ϸ���������ʤ��^_^\n");
	}
	else if (t == '#')
	{
		CBoard(board, ROW, COL);
		printf("��Ϸ����������ʤ��~_~\n");
	}
	else
	{
		CBoard(board, ROW, COL);
		printf("��Ϸ������ƽ��\n");
	}
	printf("����һ��\n");
}

int main()
{
	//��������Ŀ
	srand((unsigned int)time(NULL));//ʱ���
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		system("cls");//��������������
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
			printf("����\n");
			break;
		}
		default:
		{
			printf("�������,��������\n");
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
//	struct Stu s[] = { {"������",20},{"���ú�",19},{"������",22},{"�ӽ���",21} };
//	int num = sizeof(s) / sizeof(s[0]);
//	//������������
//	qsort(s, num, sizeof(s[0]), sort_age);
//	//������������
////	qsort(s, num, sizeof(s[0]), sort_name);
//
//	for (int i = 0; i < num; i++)
//	{
//		printf("%s %d\n", s[i].name, s[i].age);
//	}
//	return 0;
//}