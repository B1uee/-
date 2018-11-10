#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cstring> 
#include <fstream>
#include <sstream>
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


//�����ṹ�� 
struct Voter 
{
	string name; // ͶƱ������ 
	string number; //  ͶƱ��� 
	string choice; // ͶƱѡ�� 
	string ifvip; // �Ƿ�Ϊvip 
	Voter *next; 
};

struct Vote1
{
	string choice; // ͶƱ���� 
	int votes; // Ʊ�� 
	Vote1 *next;
};

struct Vote2
{
	string choice;
	int votes;
	Vote2 *next;
};


//�������� 
Voter *Create();
Vote1 *Create1();
Vote2 *Create2();


// ���� 
void Menu(); // ���� 
void Menu1();
void Menu2(); 
void Search(Voter *head); // ��ѯͶƱ����Ϣ 
void PrintVoter(Voter *head); // ���ͶƱ����Ϣ 
void PrintVote(Vote1 *head1, Vote2 *head2); // ���ͶƱ��Ϣ 
void AddVoter(Voter *head, Vote1 *head1, Vote2 *head2); // ����ͶƱ�� 
void DeleteVoter(Voter *&head, Vote1 *head1, Vote2 *head2); // ɾ��ͶƱ�� 
void ReviseInformation(Voter *head, Vote1 *head1, Vote2 *head2); // �޸�ͶƱ������Ϣ 
void PrintTop(Vote1 *head1, Vote2 *head2); // ������Ʊ�������� 
void Save(Voter *head, Vote1 *head1, Vote2 *head2); // 
void Exit();// �˳�ϵͳ 

// ���� 


// ������ 
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



 


// �����ļ�voter.txt
Voter *Create()
{
	ifstream fin("voter.txt");

	if(!fin)
	{
	    cout<<"�Ҳ����ļ�!"<<endl; 
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
    		cout << p -> name <<  "�����������������ݣ�" ;
    		j++;
		}
		else if (p -> ifvip != "vip" && p -> ifvip != "not" )
		{
			cout << p -> ifvip << "VIP������������������ݣ�";
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

// �����ļ� vote_a.txt
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

// �����ļ� vote_b.txt
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

// ��ѯͶƱ����Ϣ���� 
void Search(Voter *head)
{
	Voter *p = head;
    cout << "������ͶƱ�û�������ͶƱ������" << endl;
    string ming;
	string hao;
    cin >> ming >> hao;
    while(p != NULL)
	{
		if(p -> name == ming)
		{
			if (p -> number == hao)
			{
				cout << "ͶƱ�û���Ϣ���£�" << endl; 
				cout << p -> name << " "
				<< p -> number << " "<< p -> choice 
				<< " "<< p -> ifvip << endl;
				system ("pause");
				return; 
			}
		}
		p = p -> next;
	}
	cout<<"�Ҳ�����ͶƱ�û���"<<endl; 
	system("pause");
 } 


//  ���ͶƱ����Ϣ
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
 

// ���ͶƱ��Ϣ 
void PrintVote(Vote1 *head1, Vote2 *head2)
{
	Vote1 *p = head1; 
	cout << "��ѡ�����������Ϣ��ͶƱ��ţ�a/b)" << endl;
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
	else cout << "����������ͶƱ���(a/b)��" << endl; 
	goto A;
	while(p != NULL)
	{
		cout << p -> choice << " "<< p -> votes << endl;
		p = p -> next; 
	}
 } 


// ����ͶƱ��
 void AddVoter(Voter *head, Vote1 *head1, Vote2 *head2)
{
	string ming, hao, xuan;
	Voter *p = head;
	Voter *q ;
	q = new Voter;
	Vote1 *r = head1;
	Vote1 *r1 = head1;
	Vote1 *r2 = head1;	
	Vote1 *r3 = head1; //��������� 
	Vote2 *s = head2;
	Vote2 *s1 = head2; 
	Vote2 *s2 = head2; 
	Vote2 *s3 = head2; //��������� 
	C:cout << "�����������ӵ�ͶƱ����Ϣ" << endl;
	cout << "����:" ;
	cin >>  ming;
	while(p != NULL)
	{
		if(p -> name == ming)
		{
			cout << "�벻Ҫ�ظ�ͶƱ��" << endl; 
			system ("pause");
			goto C; 
		}
		p = p -> next; // ����ѭ�� 
	}
	q -> name = ming; // �����ռ���ʱ�洢���� 
	A:cout << endl << "ͶƱ��ţ�" ;
	cin >> hao;
	q -> number = hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "��Ŵ������������룡" << endl; 
	goto A; 
	} 
	B:cout << endl << "ͶƱ�˵ȼ���" ;
	string level;
	cin >> level;
	if (level != "vip" && level != "not") 
	{
		cout << "�û��ȼ��������������룡" << endl;
		 goto B;
	}
	cout << "��ͶƱѡ�" << endl; 
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
	D:cout << "����������ͶƱ��ѡ�" << endl; 
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
		cout << "�޸�ͶƱѡ����������룡" << endl;
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
		cout << "�޸�ͶƱѡ����������룡" << endl;
		s3 = head2;
		goto D;
	}
	}      

	q -> choice = xuan;
	

	// cout << q -> name << q -> number << q -> choice; �洢�ɹ� 
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
				cout << "\n����ͶƱ��Ϣ��\n" 
				<< q -> name << " " << q -> number 
				<< " " << q -> choice 
				<< " " << q -> ifvip
				 << endl;
				cout << "\n��ǰ��Ʊ����\n"; 
				while (s2 != NULL)
				{
					cout << s2 -> choice << " " << s2 -> votes << endl;
					s2 = s2 -> next;
				}
				cout << "���ͶƱ����Ϣ�ɹ�" << endl; 
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
				cout << "\n����ͶƱ��Ϣ��\n" 
				<< q -> name << " " << q -> number 
				<< " " << q-> choice << " " 
				<< q -> ifvip 
				<< endl;
				cout << "\n��ǰ��Ʊ����\n"; 
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

// ɾ��ͶƱ�� 
void DeleteVoter(Voter *&head, Vote1 *head1, Vote2 *head2)
{
	Voter *p = head;
	Voter *p1 = head;
	Vote1 *r = head1;	
	Vote1 *r1 = head1;
	Vote2 *s = head2;
	Vote2 *s1 = head2;
	string ming, hao; 
	cout << "��������ɾ����ͶƱ����Ϣ:" << endl;
	A:cout << "����:" ;
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
		cout << "�޸�ͶƱ�ˣ����������룡" << endl; 
		system("pause") ;
		p = head; //����ָ�� 
		goto A;
	}
	B:cout << "������:" ;
	cin >>  hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "��Ŵ������������룡" << endl; 
	goto B; 
	} 
	p = head;
	while (p != NULL)
	{
		if (p -> name == ming && p -> number == hao)
		{
			while (p1 != NULL)
			{
				if (p == head)     //�ж�p�Ƿ�Ϊ��λ 
				{
					if (hao == "a" )           //�ж���a����b����
					{
						while (r != NULL)
						{
							if (p -> choice == r -> choice)
							{
								if (p -> ifvip == "vip")
								r -> votes -= 3;
								else
								r -> votes--;
								cout << "\nɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
								cout << "\nɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
				else if (p1 -> next == p)   // P������λ 
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
								cout << "\nɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
								cout << "ɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
		cout <<"�û�û��ͶƱ�������⣡\n";
		system ("pause");
		return;
}


// �޸�ͶƱ������Ϣ
void ReviseInformation(Voter *head, Vote1 *head1, Vote2 *head2)
{
	Voter *p = head;
	Vote1 *r = head1;
	Vote1 *r1 = head1;
	Vote2 *s = head2;
	Vote2 *s1 = head2;
	string hao, pre, now;
	cout << "��������Ҫ�޸ĵ�ͶƱ������(a/b):" << endl;
	cin >> hao; 
	if (hao != "a" && hao != "b")
	{
		cout << "�����Ŵ������������룡" << endl;
	} 
	cout << "ͶƱ���һ��" << endl; 
	if (hao == "a")
	{
		while (r != NULL)
		{
			cout << r -> choice << " " << r -> votes << endl;
			r = r -> next;
		}
		A:cout << "���������޸ĵ�ѡ����޸ĺ��ѡ�� (�м�ո�ָ�)��" << endl;
		cin >> pre >> now;
		while (r1 != NULL) // �������Ƿ��ظ� 
		{
			if (r1 -> choice == now)
			{
				cout << "����ѡ����������룡" << endl;
				r1 = head1;            //���� 
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
				cout << "�޸ĳɹ���" << endl 
				<< "�޸ĺ��ͶƱѡ��һ��" << endl; 
				while (r1 != NULL)
				{
					cout << r1 -> choice << " " << r1 -> votes << endl;
					r1 = r1 -> next;
				}
				while (p != NULL)       // ����Voter��Ϣ 
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
		B:cout <<"���������޸ĵ�ѡ����޸ĺ��ѡ�� (�м�ո�ָ�)��";
		cin >> pre >> now;
		while (s1 != NULL)
		{
			if (s1 -> choice == now)
			{
				cout <<"����ѡ����������룡" << endl;
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
				cout << "�޸ĳɹ���" << endl 
				<< "�޸ĺ��ͶƱѡ��һ��" << endl; 
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
	B:cout << "��������Ҫ�����ͶƱ������(a/b):" << endl; 
	cin >>  hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "��Ŵ������������룡" << endl; 
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




































