#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#define  TITLE  "ͶƱϵͳ"
#define  RIGHT_MARGIN 40
using namespace std;
//����ö��Keyboard�ļ�ֵ����
enum
{
	UP = 72,
	DOWN = 80 ,
	LEFT = 75 ,
	RIGHT = 77 ,
	ENTER = 13 ,
	ESC = 27 ,
};

//����Ҫ��ʾ�Ĳ˵�
char *menu[] =
{
	"������ѯͶƱ��Ϣ����",
	"���� ���ͶƱ�� ����",
	"���� ����ͶƱ�� ����",
	"���� ɾ��ͶƱ�� ����",
	"����������Ʊ������",
	"����    �˳�    ����",
};
//����ṹ��
CONSOLE_CURSOR_INFO cci;
//����Ĭ�ϵ�����λ��
COORD pos = {0,0};
//��ʾ�˵�
void showmenu(HANDLE hOut ,char **menu , int size , int index) ;
//��ȡ�û�����
int  get_userinput(int *index , int size) ;
int main()
{
    int i;
    int ret ;
    int index = 0 ;
    HANDLE hOut;
    //���ô��ڵı���
    SetConsoleTitleA(TITLE);
    //��ȡ��ǰ�ľ��---����Ϊ��׼������
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //��ȡ�����Ϣ
    GetConsoleCursorInfo(hOut, &cci);
	//���ù���С
    cci.dwSize = 1;
	//���ù�겻�ɼ� FALSE
    cci.bVisible =  0;
    //����(Ӧ��)�����Ϣ
    SetConsoleCursorInfo(hOut, &cci);
    while(1)
    {
    	showmenu(hOut , menu , NR(menu) , index);
		ret = get_userinput(&index , NR(menu));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:
				    //��ѯͶƱ��Ϣ
				    break ;
				case 1:
				    //���ͶƱ��
				    break ;
				case 2:
				    //����ͶƱ��
				    break ;
				case 3:
				    //ɾ��ͶƱ��
				    break ;
				case 4:
				    //������Ʊ��
				    break ;
				case 5:
				    return 0 ;//�˳�
			}
		}
	}
    return 0;
}

void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
	int i ;
	system("cls");
	//������ʾ���ı�����ɫ
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);
	//��ʼ������̨��ʾ��X,Y�������
	pos.X = RIGHT_MARGIN+6;
	pos.Y = 0 ;
	//������ʾ������̨�ն˵ľ���λ��
	SetConsoleCursorPosition(hOut,pos);
	//����printf�ڿ���̨��Ӧ��λ�������
	cout<<TITLE;

	for(i = 0 ; i < size ; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
		//���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ�������
		if(i == index)
		{
			//��ɫ
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);
			pos.X = RIGHT_MARGIN;
    		pos.Y = 3+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos);
    		cout<<menu[i];
		}
		//������ʾΪ��ɫ
		else
		{
			//��ɫ
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			pos.X = RIGHT_MARGIN;
    		pos.Y = 3+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos);    //���ù������
    		cout<<menu[i];
		}
	}
	//ˢ�±�׼���������
	cout<<flush;
}

//��ȡ�û�����Ľӿ�
int  get_userinput(int *index , int size)
{
	int ch ;
	ch = getch();
	switch(ch)
	{
		//��
		//���ѡ���ϣ���ô��������ƶ�
		case UP : if(*index > 0)  *index -= 1 ;  break;
		//��
		//���ѡ���£���ô��������ƶ�
		case DOWN :if(*index < size -1)  *index += 1 ;  break;
		//��
		case LEFT:
		case 97:return 0 ;
		//��
		case RIGHT:return 0 ;
		//�س�
		case ENTER:return ENTER ;
		//ESC
		case ESC: return ESC ;
	}
	return 0 ;
}
