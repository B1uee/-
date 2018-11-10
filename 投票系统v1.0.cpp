#include <iostream>
#include <string>
#include <cstring> 
#include <fstream>
#include <sstream>


using namespace std;


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
void SearchVoter(Voter *head); // 查询投票人信息 
void CoutVoter(Voter *head); // 输出投票人信息 
void CoutVote(Vote1 *head1, Vote2 *head2); // 输出投票信息 
void AddVoter(Voter *head, Vote1 *head1, Vote2 *head2); // 新增投票人 
void DeleteVoter(Voter *&head, Vote1 *head1, Vote2 *head2); // 删除投票人 
void ReviseVote(Voter *head, Vote1 *head1, Vote2 *head2); // 修改投票问题信息 
void CoutHighest(Vote1 *head1, Vote2 *head2); // 输出最高票，并排序 
void foutput(Voter *head, Vote1 *head1, Vote2 *head2); // 
void Exit();// 退出系统 

// 其他 


// 主函数 
int main()
{
	Voter *head;
    Vote1 *head1; 
	Vote2 *head2;
	head = Create();
	head1 = Create1();
	head2 = Create2();
	//SearchVoter(head); 				成功 
	//CoutVoter(head); 				    成功
	//CoutVote(head1, head2);  		    成功 
	AddVoter(head, head1, head2);
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
void SearchVoter(Voter *head)
{
	Voter *p = head;
    cout<<"请输入投票用户姓名与投票问题编号"<<endl;
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
				cout << p -> name << " "<< p -> number << " "<< p -> choice << " "<< p -> ifvip << endl;
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
void CoutVoter(Voter *head)
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
void CoutVote(Vote1 *head1, Vote2 *head2)
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
	Vote2 *s = head2;
	Vote2 *s1 = head2; 
	Vote2 *s2 = head2; 
	C:cout << "请输入想增加的投票人信息:" << endl;
	cout << "姓名:" << "   ";
	cin >>  ming;
	while(p != NULL)
	{
		if(p -> name == ming)
		{
			cout << "请不要重复投票！" << endl; 
			system ("pause");
			goto C; 
		}
		p = p -> next; // p最终指向最后一个节点 
	}
	q -> name = ming; // 新增空间暂时存储输入 
	A:cout << endl << "投票编号：   " ;
	cin >> hao;
	q -> number = hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "编号错误，请重新输入！" << endl; 
	goto A; 
	} 
	B:cout << endl << "投票人等级：   " ;
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
	cout << "请输入您想投票的选项：" << endl; 
	cin >> xuan;
	q -> choice = xuan;

	// cout << q -> name << q -> number << q -> choice; 存储成功 
	if (xuan == "b")
	{
		while(s1 != NULL)
		{
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
				cout << "\n新增投票：\n" << q->name << " " << q -> number << " " << q -> choice << " " << q -> ifvip << endl;
				cout << "\n当前得票数：\n"; 
				while (s2 != NULL)
				{
					cout << s2 -> choice << " " << s2 -> votes << endl;
					s2 = s2 -> next;
				}
				system("pause");
				return;
			
		}
		s1 = s1 -> next;
	}
	else 
	{
		while(r1 != NULL)
		{
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
				cout << "\n新增投票：\n" << q -> name << " " << q -> number << " " << q-> choice << " " << q -> ifvip << endl;
				cout << "\n当前得票数：\n"; 
				while (r2 != NULL)
				{
					cout << r2 -> choice << " " << r2 -> votes << endl;
					r2 = r2 -> next;
				}
				system("pause");
				return;
		}
		r1 = r1 -> next;
	}
		
	 
	 
} 
