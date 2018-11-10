#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cstring> 
#include <fstream>
#include <sstream>
#include <stdlib.h>
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#define  TITLE  "投票系统"
#define  RIGHT_MARGIN 40



using namespace std;

//定义枚举Keyboard的键值数据
enum
{
	UP = 72,
	DOWN = 80 ,
	LEFT = 75 ,
	RIGHT = 77 ,
	ENTER = 13 ,
	ESC = 27 ,
};
//定义要显示的菜单
char *menu[] =
{
	"■■查询投票信息■■",
	"■■ 输出投票人 ■■",
	"■■ 新增投票人 ■■",
	"■■ 删除投票人 ■■",
	"■■输出最高票数■■",
	"■■    退出    ■■",
};
//定义结构体
CONSOLE_CURSOR_INFO cci;
//定义默认的坐标位置
COORD pos = {0,0};
//显示菜单
void showmenu(HANDLE hOut ,char **menu , int size , int index) ;
//获取用户输入
int  get_userinput(int *index , int size) ;


//建立结构体 
struct Voter 
{
	string name; // 投票人姓名 
	string number; //  投票编号 
	string choice; // 投票选项 
	string ifvip; // 是否为vip 
	Voter *next; 
};

struct Vote1
{
	string choice; // 投票类型 
	int votes; // 票数 
	Vote1 *next;
};

struct Vote2
{
	string choice;
	int votes;
	Vote2 *next;
};


//建立链表 
Voter *Create();
Vote1 *Create1();
Vote2 *Create2();


// 功能 
void Menu(); // 界面 
void Menu1();
void Menu2(); 
void Search(Voter *head); // 查询投票人信息 
void PrintVoter(Voter *head); // 输出投票人信息 
void PrintVote(Vote1 *head1, Vote2 *head2); // 输出投票信息 
void AddVoter(Voter *head, Vote1 *head1, Vote2 *head2); // 新增投票人 
void DeleteVoter(Voter *&head, Vote1 *head1, Vote2 *head2); // 删除投票人 
void ReviseInformation(Voter *head, Vote1 *head1, Vote2 *head2); // 修改投票问题信息 
void PrintTop(Vote1 *head1, Vote2 *head2); // 输出最高票，并排序 
void Save(Voter *head, Vote1 *head1, Vote2 *head2); // 
void Exit();// 退出系统 

// 其他 


// 主函数 
int main()
{
    int i;
    int ret ;
    int index = 0 ;
    HANDLE hOut;
    //设置窗口的标题
    SetConsoleTitleA(TITLE);
    //获取当前的句柄---设置为标准输出句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //获取光标信息
    GetConsoleCursorInfo(hOut, &cci);
	//设置光标大小
    cci.dwSize = 1;
	//设置光标不可见 FALSE
    cci.bVisible =  0;
    //设置(应用)光标信息
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
				    //查询投票信息
				    break ;
				case 1:
				    //输出投票人
				    break ;
				case 2:
				    //新增投票人
				    break ;
				case 3:
				    //删除投票人
				    break ;
				case 4:
				    //输出最高票数
				    break ;
				case 5:
				    return 0 ;//退出
			}
		}
	}
    return 0;
}

void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
	int i ;
	system("cls");
	//设置显示的文本的颜色
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);
	//初始化控制台显示的X,Y轴的坐标
	pos.X = RIGHT_MARGIN+6;
	pos.Y = 0 ;
	//设置显示到控制台终端的具体位置
	SetConsoleCursorPosition(hOut,pos);
	//调用printf在控制台对应的位置上输出
	cout<<TITLE;

	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象
		if(i == index)
		{
			//红色
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);
			pos.X = RIGHT_MARGIN;
    		pos.Y = 3+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);
    		cout<<menu[i];
		}
		//否则显示为白色
		else
		{
			//白色
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			pos.X = RIGHT_MARGIN;
    		pos.Y = 3+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);    //设置光标坐标
    		cout<<menu[i];
		}
	}
	//刷新标准输出缓冲区
	cout<<flush;
}

//获取用户输入的接口
int  get_userinput(int *index , int size)
{
	int ch ;
	ch = getch();
	switch(ch)
	{
		//上
		//如果选择上，那么光标向上移动
		case UP : if(*index > 0)  *index -= 1 ;  break;
		//下
		//如果选择下，那么光标向下移动
		case DOWN :if(*index < size -1)  *index += 1 ;  break;
		//左
		case LEFT:
		case 97:return 0 ;
		//右
		case RIGHT:return 0 ;
		//回车
		case ENTER:return ENTER ;
		//ESC
		case ESC: return ESC ;
	}
	return 0 ;
}



 


// 读入文件voter.txt
Voter *Create()
{
	ifstream fin("voter.txt");

	if(!fin)
	{
	    cout<<"找不到文件!"<<endl; 
	    abort();
	} 
	Voter *head=NULL,*p,*q;
	string all;		  
	int j = 0;   
    while(getline(fin,all))
	{
		
		p = new Voter;	
    	istringstream in(all);
    	in >> p -> name;
    	in >> p -> number;
    	in >> p -> choice;
    	in >> p -> ifvip;
    	if (p -> number != "a" && p -> number != "b") 
    	{
    		cout << p -> name <<  "编号输入错误，请检查数据！" ;
    		j++;
		}
		else if (p -> ifvip != "vip" && p -> ifvip != "not" )
		{
			cout << p -> ifvip << "VIP类型输入错误，请检查数据！";
			j++;
		}
    	    	if (head == NULL)
		{
			head = p;
		}
		else
		{
			q -> next = p;
		}	   
		q = p;
	}
	if (j > 0)     	system("pause");system("cls"); 
	if (head != NULL)
	q -> next = NULL;
    return (head);
} 

// 读入文件 vote_a.txt
Vote1 *Create1()
{	
	Vote1 *head=NULL, *p, *q;
	string all;
	ifstream infile("vote_a.txt");
	while(getline(infile,all))
	{
		istringstream in(all);
		p = new Vote1;
		in >> p -> choice;
    	in >> p -> votes;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			q -> next = p;
		}	   
		q = p;
	}
	if (head != NULL)
	q -> next = NULL;
    return (head);
} 

// 读入文件 vote_b.txt
 Vote2 *Create2()
{	
	Vote2 *head=NULL, *p, *q;
	string all;
	ifstream infile("vote_b.txt");
	while(getline(infile,all))
	{
		istringstream in(all);
		p = new Vote2;
		in >> p -> choice;
    	in >> p -> votes;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			q -> next = p;
		}	   
		q = p;
	}
	if (head != NULL)
	q -> next = NULL;
    return (head);
} 

// 查询投票人信息函数 
void Search(Voter *head)
{
	Voter *p = head;
    cout << "请输入投票用户姓名与投票问题编号" << endl;
    string ming;
	string hao;
    cin >> ming >> hao;
    while(p != NULL)
	{
		if(p -> name == ming)
		{
			if (p -> number == hao)
			{
				cout << "投票用户信息如下：" << endl; 
				cout << p -> name << " "
				<< p -> number << " "<< p -> choice 
				<< " "<< p -> ifvip << endl;
				system ("pause");
				return; 
			}
		}
		p = p -> next;
	}
	cout<<"找不到该投票用户！"<<endl; 
	system("pause");
 } 


//  输出投票人信息
void PrintVoter(Voter *head)
{
	Voter *p = head;
	while(p != NULL)
	{
		cout << p -> name << " "<< p -> number << " "<< p -> choice << " "<< p -> ifvip << endl;
		p = p -> next; 
	}
	system("pause");
 } 
 

// 输出投票信息 
void PrintVote(Vote1 *head1, Vote2 *head2)
{
	Vote1 *p = head1; 
	cout << "请选择您想输出信息的投票编号（a/b)" << endl;
	char c;
	A:cin >> c; 
	if (c == 'a') 
	{
		while(p != NULL)
		{
			cout << p -> choice << " "<< p -> votes << endl;
			p = p -> next; 
		}
		system("pause");
	}	
	else if (c == 'b') 
	{
		Vote2 *p = head2;
		while(p != NULL)
		{
			cout << p -> choice << " "<< p -> votes << endl;
			p = p -> next; 
		}
		system("pause");
	}
	else cout << "请重新输入投票编号(a/b)：" << endl; 
	goto A;
	while(p != NULL)
	{
		cout << p -> choice << " "<< p -> votes << endl;
		p = p -> next; 
	}
 } 


// 新增投票人
 void AddVoter(Voter *head, Vote1 *head1, Vote2 *head2)
{
	string ming, hao, xuan;
	Voter *p = head;
	Voter *q ;
	q = new Voter;
	Vote1 *r = head1;
	Vote1 *r1 = head1;
	Vote1 *r2 = head1;	
	Vote1 *r3 = head1; //错误处理遍历 
	Vote2 *s = head2;
	Vote2 *s1 = head2; 
	Vote2 *s2 = head2; 
	Vote2 *s3 = head2; //错误处理遍历 
	C:cout << "请输入想增加的投票人信息" << endl;
	cout << "姓名:" ;
	cin >>  ming;
	while(p != NULL)
	{
		if(p -> name == ming)
		{
			cout << "请不要重复投票！" << endl; 
			system ("pause");
			goto C; 
		}
		p = p -> next; // 跳出循环 
	}
	q -> name = ming; // 新增空间暂时存储输入 
	A:cout << endl << "投票编号：" ;
	cin >> hao;
	q -> number = hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "编号错误，请重新输入！" << endl; 
	goto A; 
	} 
	B:cout << endl << "投票人等级：" ;
	string level;
	cin >> level;
	if (level != "vip" && level != "not") 
	{
		cout << "用户等级错误，请重新输入！" << endl;
		 goto B;
	}
	cout << "可投票选项：" << endl; 
	if (hao == "a")
	{
		while (r != NULL)
		{
			cout << r -> choice << r -> votes << endl; 	
			r = r -> next;
		}
	}
	else 
	{
		while (s != NULL)
		{
			cout << s -> choice << s -> votes << endl; 	
			s = s -> next;
		}
	}
	D:cout << "请输入您想投票的选项：" << endl; 
	cin >> xuan;
	
	if (hao == "a")
	{
		while (r3 != NULL) 		
		{
			if (r3 -> choice != xuan)	r3 = r3 -> next;
			else break;
		}
			if (r3 == NULL) 
	{
		cout << "无该投票选项，请重新输入！" << endl;
		r3 = head1;
		goto D;
	}
	}
	else 
	{
		while (s3 != NULL) 		
		{
			if (s3 -> choice != xuan)	s3 = s3 -> next;
			else break;
		}
			if (s3 == NULL) 
	{
		cout << "无该投票选项，请重新输入！" << endl;
		s3 = head2;
		goto D;
	}
	}      

	q -> choice = xuan;
	

	// cout << q -> name << q -> number << q -> choice; 存储成功 
	if (hao == "b")
	{
		
		while(s1 != NULL)
		{
			while (s1 -> choice != xuan) 		s1 = s1 -> next;
			if (level == "vip")
			{
				q -> ifvip = "vip";
				q -> next = NULL;
				s1 -> votes += 3;
			}
			else if (level == "not")
			{
				q -> ifvip = "not";
				q -> next = NULL;
				s1 -> votes++;
			}
				cout << "\n新增投票信息：\n" 
				<< q -> name << " " << q -> number 
				<< " " << q -> choice 
				<< " " << q -> ifvip
				 << endl;
				cout << "\n当前得票数：\n"; 
				while (s2 != NULL)
				{
					cout << s2 -> choice << " " << s2 -> votes << endl;
					s2 = s2 -> next;
				}
				cout << "添加投票人信息成功" << endl; 
				system("pause");
				return;	
		}

	}
	else 
	{
		while(r1 != NULL)
		{
			while (r1 -> choice != xuan) 		r1 = r1 -> next;
			if (level == "vip")
			{
				q -> ifvip = "vip";
				q -> next = NULL;
				r1 -> votes += 3;
			}
			else if (level == "not")
			{
				q -> ifvip = "not";
				q -> next = NULL;
				r1 -> votes++;
			}	
				cout << "\n新增投票信息：\n" 
				<< q -> name << " " << q -> number 
				<< " " << q-> choice << " " 
				<< q -> ifvip 
				<< endl;
				cout << "\n当前得票数：\n"; 
				while (r2 != NULL)
				{
					cout << r2 -> choice << " " << r2 -> votes << endl;
					r2 = r2 -> next;
				}
				system("pause");
				return;
		}
	}	 
} 

// 删除投票人 
void DeleteVoter(Voter *&head, Vote1 *head1, Vote2 *head2)
{
	Voter *p = head;
	Voter *p1 = head;
	Vote1 *r = head1;	
	Vote1 *r1 = head1;
	Vote2 *s = head2;
	Vote2 *s1 = head2;
	string ming, hao; 
	cout << "请输入想删除的投票人信息:" << endl;
	A:cout << "姓名:" ;
	cin >>  ming;	
	int i =0;
	while (p != NULL)
	{
		if(p -> name == ming) 
		{
			i++;
		}
		p = p -> next; 
	}
	if (i == 0)			
	{
		cout << "无该投票人，请重新输入！" << endl; 
		system("pause") ;
		p = head; //重置指针 
		goto A;
	}
	B:cout << "问题编号:" ;
	cin >>  hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "编号错误，请重新输入！" << endl; 
	goto B; 
	} 
	p = head;
	while (p != NULL)
	{
		if (p -> name == ming && p -> number == hao)
		{
			while (p1 != NULL)
			{
				if (p == head)     //判断p是否为首位 
				{
					if (hao == "a" )           //判断是a还是b问题
					{
						while (r != NULL)
						{
							if (p -> choice == r -> choice)
							{
								if (p -> ifvip == "vip")
								r -> votes -= 3;
								else
								r -> votes--;
								cout << "\n删除成功！\n\n当前得票数：\n"; 
								while (r1 != NULL)
								{
									cout << r1 -> choice << " " << r1-> votes << endl;
									r1 = r1 -> next;
								}
								break;
							}
							r=r -> next;
						}					
					} 

					else if (hao == "b")
					{
						while (s != NULL)
						{
							if (p -> choice == s -> choice)
							{
								if (p -> ifvip == "vip")
								s -> votes -= 3;
								else
								s -> votes--;
								cout << "\n删除成功！\n\n当前得票数：\n"; 
								while (s1 != NULL)
								{
									cout << s1 -> choice << " " << s1-> votes << endl;
									s1 = s1 -> next;
								}
							break;
							}
							s=s -> next;
						}		
					}
						head = head -> next;
						delete p;
						break;
				}
				else if (p1 -> next == p)   // P不是首位 
				{
					if (hao == "a")
					{
						while (r != NULL)
						{
							if (p -> choice == r -> choice)
							{
								if (p -> ifvip == "vip")
								r -> votes -= 3;
								else
								r -> votes--;
								cout << "\n删除成功！\n\n当前得票数：\n"; 
								while (r1 != NULL)
								{
								cout << r1 -> choice <<" "<< r1 -> votes <<endl;
								r1 = r1 -> next;
								}
								break;
							}
							r = r -> next;
						}
					}
					else if (hao=="b")
					{
						while (s != NULL)
						{
							if (p -> choice == s -> choice)
							{
								if (p -> ifvip == "vip")
								s -> votes -= 3;
								else
								s -> votes--;
								cout << "删除成功！\n\n当前得票数：\n"; 
								while(s1 != NULL)
								{
								cout << s1 -> choice << " " << s1 -> votes <<endl;
								s1 = s1 -> next;
								}
							}
							s = s -> next;
						}
					}
					p1 -> next = p -> next;
					delete p;
					break;
				}
				p1 = p1 -> next;				
			}
			system ("pause");
			return; 
		}	
			p = p -> next;
		}
		cout <<"用户没有投票过此问题！\n";
		system ("pause");
		return;
}


// 修改投票问题信息
void ReviseInformation(Voter *head, Vote1 *head1, Vote2 *head2)
{
	Voter *p = head;
	Vote1 *r = head1;
	Vote1 *r1 = head1;
	Vote2 *s = head2;
	Vote2 *s1 = head2;
	string hao, pre, now;
	cout << "请输入需要修改的投票问题编号(a/b):" << endl;
	cin >> hao; 
	if (hao != "a" && hao != "b")
	{
		cout << "输入编号错误，请重新输入！" << endl;
	} 
	cout << "投票情况一览" << endl; 
	if (hao == "a")
	{
		while (r != NULL)
		{
			cout << r -> choice << " " << r -> votes << endl;
			r = r -> next;
		}
		A:cout << "请输入想修改的选项和修改后的选项 (中间空格分隔)：" << endl;
		cin >> pre >> now;
		while (r1 != NULL) // 错误处理是否重复 
		{
			if (r1 -> choice == now)
			{
				cout << "已有选项，请重新输入！" << endl;
				r1 = head1;            //重置 
				goto A;
			}
			r1 = r1 -> next;
		}
		r1 = head1;
		r = head1;
		while (r != NULL)
		{
			if (r -> choice == pre)
			{
				r -> choice = now; 
				cout << "修改成功！" << endl 
				<< "修改后的投票选项一览" << endl; 
				while (r1 != NULL)
				{
					cout << r1 -> choice << " " << r1 -> votes << endl;
					r1 = r1 -> next;
				}
				while (p != NULL)       // 更新Voter信息 
				{
					if (p -> choice == pre)	 p -> choice = now;
					p = p -> next;
				}
				system("pause");
				return;
			}
			r = r -> next;
		}
	}
	else
	{
		while (s != NULL)
		{
			cout << s -> choice << " " << s -> votes << endl;
			s = s -> next;
		}
		B:cout <<"请输入想修改的选项和修改后的选项 (中间空格分隔)：";
		cin >> pre >> now;
		while (s1 != NULL)
		{
			if (s1 -> choice == now)
			{
				cout <<"已有选项，请重新输入！" << endl;
				s1 = head2;
				goto B;
			}
			s = s -> next;
		}
		s = head2;
		s1 = head2;
		while (s != NULL)
		{
			if (s -> choice == pre)
			{
				s -> choice = now; 
				cout << "修改成功！" << endl 
				<< "修改后的投票选项一览" << endl; 
				while (s1 != NULL)
				{
					cout << s1 -> choice << " " << s1 -> votes << endl;
					s1 = s1 -> next;
				}
				while (p != NULL)
				{
					if (p -> choice == pre)	 p -> choice = now;
					p = p -> next;				
				}
				system("pause");
				return;
			}
			s = s -> next;
		}
	}
}


void PrintTop(Vote1 *head1, Vote2 *head2)
{
	Vote1 *p = head1;
	Vote1 *r1 = head1; 
	Vote2 *s = head2;
	Vote1 *o = head1;
	string hao;
	Vote1 *temp;
	Vote1 *w;
	B:cout << "请输入需要排序的投票问题编号(a/b):" << endl; 
	cin >>  hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "编号错误，请重新输入！" << endl; 
	goto B; 
	} 
	if (hao == "a")
	{
		for (p = head1; p -> next != NULL; p = p -> next  )
		{
			o = p -> next;
			if (p -> votes > o -> votes)
			{
				if( p == head1)
				{
					temp = p -> next;
					p -> next = o -> next;
					o -> next = head1;
					head1 = temp;
				}
				else
				{
					for(temp = head1; temp -> next != p; temp= temp -> next)
					{
						temp = temp;
					}
					temp -> next = o;
					w = o -> next;
					o -> next = p;
					p->next = w;
					w = p;
					p = o;
					o = w;					 			
				}
			}
		}
		while (r1 != NULL)
		{
			cout << r1 -> choice << " " << r1 -> votes << endl; 
			r1 = r1 -> next; 
		}
	 }
}




































