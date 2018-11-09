#include <iostream>
#include <string>
#include <cstring> 
#include <fstream>
#include <sstream>

using namespace std;

struct Voter
	{
		string ID;			//投票人 
		string Letter;		//投票问题 
		string Name;		//得票者 
		string VipOrNot;	//是否为vip 
		Voter *Next;
	};
struct VoteA
	{
		string Name;		//得票者 
		int Vote;			//得票数 
		VoteA *Next;
	};
struct VoteB
	{
		string Name;		//同上 
		int Vote;
		VoteB *Next;
	};
int a[10],c[10];

void InterFace0();
void InterFace1();
void InterFace2();
Voter *create1();
VoteA *create2();
VoteB *create3();
void SearchVoter(Voter *head);
void CoutVoter(Voter *head);
void CoutVote(VoteA *head2,VoteB *head3);
void ReviseVote(Voter *head,VoteA *head2,VoteB *head3);
void AddVoter(Voter *head,VoteA *head2,VoteB *head3);
void DeleteVoter(Voter *&head,VoteA *head2,VoteB *head3);
void CoutHighest(VoteA *head2,VoteB *head3);
void foutput(Voter *head,VoteA *head2,VoteB *head3);

int main()
{
	Voter *head1;
	VoteA *head2;
	VoteB *head3;
	head1 = create1();
	head2 = create2();
	head3 = create3();
	int Choice0 = 1,Choice1;
	char temp;
	while (Choice0)
	{
	Choice1 = 1;
	A:system("cls");
	InterFace0();
	cin >> Choice0;
	if (Choice0 == 1)
	{
		B:system("cls");
		InterFace1();
		cin >> Choice1;
		if (Choice1 == 1){
		SearchVoter(head1);goto B;}
		else if (Choice1 == 2){
		CoutVoter(head1);goto B;}
		else if (Choice1 == 3){
		AddVoter(head1,head2,head3);goto B;}
		else if (Choice1 == 4){
		DeleteVoter(head1,head2,head3);goto B;}
		else if (Choice1 == 0)
		{
			system("cls");
			goto A;
		}
		else
		{
		cout <<"请输入正确的编号！\n";
		system("pause");
		goto B;
		}
	}
	else if (Choice0 == 2)
	{
		C:system("cls");
		InterFace2();
		cin >> Choice1;
		if (Choice1 == 1){
		CoutVote(head2,head3);goto C;}
		else if (Choice1 == 2){ 
		ReviseVote(head1,head2,head3);goto C;}
		else if (Choice1 == 3){
		CoutHighest(head2,head3);goto C;}
		else if (Choice1 == 0)
		{
			system("cls");
			goto A;
		}
		else
		{
		cout <<"请输入正确的编号！\n";
		system("pause");
		goto C;
		}
	}
	else if (Choice0 == 3)
	{
		foutput(head1,head2,head3);
		system("cls");
		goto A;
	}
	else
	{
		cout <<"请输入正确的编号！\n";
		system("pause");
		system("cls");
		goto A;
	}
	}
	return 0;
}
Voter *create1()
{
	Voter *head=NULL,*p,*q;
	string All;
	ifstream infile("voter.txt");
	while(getline(infile,All))
	{
		istringstream is(All);
		p = new Voter;
		is>>p->ID;
    	is>>p->Letter;
		is>>p->Name;
    	is>>p->VipOrNot;
    	if (head == NULL)
		{
			head = p;
		}
		else
		{
			q->Next = p;
		}	   
		q = p;
	}
	if (head != NULL)
	q->Next = NULL;
    return(head);
}
VoteA *create2()
{	
	VoteA *head=NULL,*p,*q;
	string All;
	ifstream infile("vote_a.txt");
	while(getline(infile,All))
	{
		istringstream is(All);
		p = new VoteA;
		is>>p->Name;
    	is>>p->Vote;
    	if (head == NULL)
		{
			head = p;
		}
		else
		{
			q->Next = p;
		}	   
		q = p;
	}
	if (head != NULL)
	q->Next = NULL;
    return(head);
}
VoteB *create3()
{
	VoteB *head=NULL,*p,*q;
	string All;
	ifstream infile("vote_b.txt");
	while(getline(infile,All))
	{
		istringstream is(All);
		p = new VoteB;
		is>>p->Name;
    	is>>p->Vote;
    	if (head == NULL)
		{
			head = p;
		}
		else
		{
			q->Next = p;
		}	   
		q = p;
	}
	if (head != NULL)
	q->Next = NULL;
    return(head);
}
void InterFace0()
{
	cout << "*******************************************************************" << endl << endl << endl;
	cout << "                        投票系统处理——v1.0" << endl;
	cout << "               请先选择待操作的文件：" << endl;
	cout << "               1)voter.txt  (操作投票人)" << endl;
	cout << "               2)vote.txt  (操作投票问题)" << endl;
	cout << "               3)保存投票信息" << endl;
	cout << "               0)退出" << endl << endl << endl;
	cout << "*******************************************************************" << endl;
}
void InterFace1()
{
	cout << "*******************************************************************" << endl << endl << endl;
	cout << "               1)查询投票人信息" << endl;
	cout << "               2)输出全部投票人信息" << endl;
	cout << "               3)新增投票人信息" << endl;
	cout << "               4)删除投票人信息" << endl;
	cout << "               0)返回上级菜单" << endl << endl << endl;
	cout << "*******************************************************************" << endl;
}
void InterFace2()
{
	cout << "*******************************************************************" << endl << endl << endl;
	cout << "               1)输出全部投票信息" << endl;
	cout << "               2)修改投票问题信息" << endl;
	cout << "               3)输出最高票" << endl;
	cout << "               0)返回上级菜单" << endl << endl << endl;
	cout << "*******************************************************************" << endl;
}
void SearchVoter(Voter *head)
{
	Voter *p=head;
    cout<<"请输入投票问题姓名与编号(用空格分隔)"<<endl;
    string bh;
	string xm;
    cin >> xm >> bh;
    while(p != NULL)
	{
		if(p->ID==xm)
		{
			if (p->Letter==bh)
			{
				cout<<"用户投票信息如下："<<endl; 
				cout << p->ID << " "<< p->Letter << " "<< p->Name << " "<< p->VipOrNot << endl;
				system ("pause");
				return; 
			}
		}
		p=p->Next;
	}
	cout<<"用户没有投票过此问题！"<<endl; 
	system("pause");
}
void CoutVoter(Voter *head)
{
	Voter *p=head;
    while(p != NULL)
	{
		cout << p->ID << " "
		<< p->Letter << " "
		<< p->Name << " "
		<< p->VipOrNot << endl;
		p=p->Next;
	}
	system("pause");
}
void AddVoter(Voter *head,VoteA *head2,VoteB *head3)
{
	Voter *o = head;
	Voter *p = head;
	Voter *q; 
	VoteA *r = head2;
	VoteA *r1 = head2;
	VoteA *r2 = head2;
	VoteB *s = head3;
	VoteB *s1 = head3;
	VoteB *s2 = head3;
	q = new Voter;
	string xm,bh;
	cout <<"请输入要新增的姓名与投票问题编号(a/b) (用空格分隔):\n";
	cin >> xm >> bh;
	while(p != NULL)
	{
		if(p->ID==xm)
		{
			if (p->Letter==bh)
			{
			cout<<"不能重复投票！"<<endl; 
			system ("pause");
			return; 
			}
		}
		p=p->Next;
	}
	q->ID = xm;
	q->Letter =bh;
	cout <<"\n投票选项一览:"<<endl;
	if (bh=="a")
	{
		while(r != NULL)
		{
			cout << r->Name <<" "<< r->Vote << endl;
			r=r->Next;
		}
	}
	else if (bh=="b")
	{
		while(s != NULL)
		{
			cout << s->Name <<" "<< s->Vote << endl;
			s=s->Next;
		}
	}
	else
	{
		cout <<"编号不合法！"<<endl; 
		system("pause");
		return;
	} 
	cout <<"\n请选择投票:";
	cin >> xm; 
	q->Name = xm;
	while(o->Next != NULL)
	{
		o = o->Next;
	}
	o->Next = q;
	if (bh=="a")
	{
		while(r2 != NULL)
		{
			if (r2->Name == xm)
			{
				cout <<"是否为vip(y/n)？";
				cin >> xm;
				if (xm == "y")
				{
					q->VipOrNot = "vip";
					q->Next = NULL;
					r2->Vote += 3;
				}
				else if (xm == "n")
				{
					q->VipOrNot = "not";
					q->Next = NULL;
					r2->Vote++;
				}
				else
				{
					cout <<"请输入正确选项！\n";
					system("pause");
					return;
				}
				cout <<"\n新增投票：\n"<<q->ID<<" "<<q->Letter<<" "<<q->Name<<" "<<q->VipOrNot<<endl;
				cout <<"\n当前得票数：\n"; 
				while (r1 != NULL)
				{
					cout <<r1->Name<<" "<<r1->Vote<<endl;
					r1 = r1->Next;
				}
				system("pause");
				return;
			}
			r2=r2->Next;
		}
	}
	else if (bh=="b")
	{
		while(s2 != NULL)
		{
			if (s2->Name == xm)
			{
				cout <<"是否为vip(y/n)？";
				cin >> xm;
				if (xm == "y")
				{
					q->VipOrNot = "vip";
					q->Next = NULL;
					s2->Vote += 3;
				}
				else if (xm == "n")
				{
					q->VipOrNot = "not";
					q->Next = NULL;
					s2->Vote++;
				}
				else
				{
					cout <<"请输入正确选项！\n";
					system("pause");
					return;
				}
				cout <<"\n新增投票：\n"<<q->ID<<" "<<q->Letter<<" "<<q->Name<<" "<<q->VipOrNot<<endl;
				cout <<"\n当前得票数：\n"; 
				while (s1 != NULL)
				{
					cout <<s1->Name<<" "<<s1->Vote<<endl;
					s1 = s1->Next;
				}
				system("pause");
				return;
			}
			s2=s2->Next;
		}
	}
	cout <<"选项不存在！"<<endl; 
	system("pause");
}
void DeleteVoter(Voter *&head,VoteA *head2,VoteB *head3)
{
	Voter *p=head,*q=head;
	VoteA *r=head2,*r1=head2;
	VoteB *s=head3,*s1=head3;
	string xm,bh;
	cout <<"请输入要删除的姓名与投票问题编号(a/b) (用空格分隔):\n";
	cin >> xm >> bh;
	while(p != NULL)
	{
		if(p->ID==xm)
		{
			if (p->Letter==bh)
			{
				while (q != NULL)
				{
					if (p==head)
					{
						if (bh=="a")
						{
							while (r != NULL)
							{
								if (p->Name==r->Name)
								{
									if (p->VipOrNot=="vip")
									r->Vote -= 3;
									else
									r->Vote--;
									cout <<"\n删除成功！\n\n当前得票数：\n"; 
									while(r1 != NULL)
									{
									cout << r1->Name <<" "<< r1->Vote<<endl;
									r1=r1->Next;
									}
									break;
								}
								r=r->Next;
							}
						}
						else if (bh=="b")
						{
							while (s != NULL)
							{
								if (p->Name==s->Name)
								{
									if (p->VipOrNot=="vip")
									s->Vote -= 3;
									else
									s->Vote--;
									cout <<"删除成功！\n\n当前得票数：\n"; 
									while(s1 != NULL)
									{
									cout << s1->Name <<" "<< s1->Vote<<endl;
									s1=s1->Next;
									}
								}
								s=s->Next;
							}
						}
						head=head->Next;
						delete p;
						break;
					}
					else if (q->Next==p)
					{
						if (bh=="a")
						{
							while (r != NULL)
							{
								if (p->Name==r->Name)
								{
									if (p->VipOrNot=="vip")
									r->Vote -= 3;
									else
									r->Vote--;
									cout <<"\n删除成功！\n\n当前得票数：\n"; 
									while(r1 != NULL)
									{
									cout << r1->Name <<" "<< r1->Vote<<endl;
									r1=r1->Next;
									}
									break;
								}
								r=r->Next;
							}
						}
						else if (bh=="b")
						{
							while (s != NULL)
							{
								if (p->Name==s->Name)
								{
									if (p->VipOrNot=="vip")
									s->Vote -= 3;
									else
									s->Vote--;
									cout <<"删除成功！\n\n当前得票数：\n"; 
									while(s1 != NULL)
									{
									cout << s1->Name <<" "<< s1->Vote<<endl;
									s1=s1->Next;
									}
								}
								s=s->Next;
							}
						}
						q->Next=p->Next;
						delete p;
						break;
					}
					q=q->Next;
				}
				system ("pause");
				return; 
			}
		}
		p=p->Next;
	}
	cout <<"用户没有投票过此问题！\n";
	system ("pause");
	return;
}
void CoutVote(VoteA *head2,VoteB *head3)
{
	VoteA *p = head2;
	VoteB *q = head3;
	string temp;
	cout <<"请输入需要输出的投票问题编号(a/b):";
	cin >> temp;
	if (temp == "a")
	{
		while(p != NULL)
		{
		cout << p->Name << " "<< p->Vote<<endl;
		p=p->Next;
		}
	}
	else if (temp == "b")
	{
		while(q != NULL)
		{
		cout << q->Name << " "<< q->Vote<<endl;
		q=q->Next;
		}
	}
	system("pause");
}
void ReviseVote(Voter *head,VoteA *head2,VoteB *head3)
{
	Voter *p=head;
	VoteA *r=head2,*r1=head2;
	VoteB *s=head3,*s1=head3;
	string bh,name1,name2;
	cout <<"请输入需要修改的投票问题(a/b):";
	cin >> bh;
	if (bh !="a"&&bh !="b")
	{
		cout <<"编号不合法！\n";
		system("pause");
		return;
	} 
	cout <<"该问题的投票情况如下：\n";
	if (bh =="a")
	{
		while (r != NULL)
		{
			cout << r->Name <<" "<< r->Vote << endl;
			r = r->Next;
		}
		A:cout <<"请输入需要修改的投票选项和修改后的投票选项 (用空格分隔)：";
		cin >> name1 >> name2;
		r = head2;
		while (r != NULL)
		{
			if (r->Name == name2)
			{
				cout <<"修改后选项与其他选项重复，请重新输入！\n";
				goto A;
			}
			r = r->Next;
		}
		r = head2;
		while (r != NULL)
		{
			if (r->Name == name1)
			{
				r->Name = name2; 
				cout <<"修改完成！\n修改后的投票选项如下:\n";
				while (r1 != NULL)
				{
					cout << r1->Name <<" "<< r1->Vote << endl;
					r1 = r1->Next;
				}
				while (p != NULL)
				{
					if (p->Name == name1)
					p->Name = name2;
					p = p->Next;
				}
				system("pause");
				return;
			}
			r = r->Next;
		}
	}
	if (bh =="b")
	{
		while (s != NULL)
		{
			cout << s->Name <<" "<< s->Vote << endl;
			s = s->Next;
		}
		B:cout <<"请输入需要修改的投票选项和修改后的投票选项 (用空格分隔)：";
		cin >> name1 >> name2;
		s = head3;
		while (s != NULL)
		{
			if (s->Name == name2)
			{
				cout <<"修改后选项与其他选项重复，请重新输入！\n";
				goto B;
			}
			s = s->Next;
		}
		s = head3;
		while (s != NULL)
		{
			if (s->Name == name1)
			{
				s->Name = name2; 
				cout <<"修改完成！\n修改后的投票选项如下:\n";
				while (s1 != NULL)
				{
					cout << s1->Name <<" "<< s1->Vote << endl;
					s1 = s1->Next;
				}
				while (p != NULL)
				{
					if (p->Name == name1)
					p->Name = name2;
					p = p->Next;
				}
				system("pause");
				return;
			}
			s = s->Next;
		}
	}
}
void CoutHighest(VoteA *head2,VoteB *head3)
{
	VoteA *p=head2,*p1;
	VoteB *q=head3,*q1;
	string bh;
	int i,j,k=0,temp,temp2=-1,Single=0;
	bool b=true;
	for (i=0;i<10;i++)
	{
		a[i]=0;
		c[i]=0;
	}
	cout <<"请输入需要输出最高票的投票问题编号(a/b):"; 
	cin >> bh;
	if (bh=="a")
	{
		while (p != NULL)
		{
			p=p->Next;
			k++;
		}
		while (k != 0)
		{
			for (p=head2,i=0,j=-1,temp=-1;p != NULL;p = p->Next,i++)
			{
				if (a[i] != 1&&p->Vote > temp)
				{
					a[j] = 0;
					j = i;
					a[i]++; 
					temp = p->Vote;
					if (temp2 == -1)
					p1 = p;
				}
			}
			p = head2;
			if (temp2 > temp)
			b = false;
			if (b&&temp == temp2)
			{
				Single++;
				c[Single] = j;
			}
			while (j > 0)
			{
				p = p->Next;
				j--;
			}
			cout << p->Name <<" "<< p->Vote <<endl;
			temp2 = temp;
			k--;
		}
		if (Single==0)
		cout <<"最高票为"<<p1->Name<<"！\n得票数为"<<p1->Vote<<endl;
		else
		{
			i=1;
			cout << p1->Name;
			while (i <= Single)
			{
				for(p=head2;c[i]>0;c[i]--)
				{
					p=p->Next;
				}
				i++;
				cout <<"与"<< p->Name;
			}
			cout <<"并列第一！\n得票数为"<<p1->Vote<<endl; 
		}
	}
	else if (bh=="b")
	{
		while (q != NULL)
		{
			q=q->Next;
			k++;
		}
		while (k != 0)
		{
			for (q=head3,i=0,j=-1,temp=-1;q != NULL;q = q->Next,i++)
			{
				if (a[i] != 1&&q->Vote > temp)
				{
					a[j] = 0;
					j = i;
					a[i]++; 
					temp = q->Vote;
					if (temp2 == -1)
					q1 = q;
				}
			}
			q = head3;
			if (temp2 > temp)
			b = false;
			if (b&&temp == temp2)
			{
				Single++;
				c[Single] = j;
			}
			while (j > 0)
			{
				q = q->Next;
				j--;
			}
			cout << q->Name <<" "<< q->Vote <<endl;
			temp2 = temp;
			k--;
		}
		if (Single==0)
		cout <<"最高票为"<<q1->Name<<"！\n得票数为"<<q1->Vote<<endl;
		else
		{
			i=1;
			cout << q1->Name;
			while (i <= Single)
			{
				for(q=head3;c[i]>0;c[i]--)
				{
					q=q->Next;
				}
				i++;
				cout <<"与"<< q->Name;
			}
			cout <<"并列第一！\n得票数为"<<q1->Vote<<endl; 
		}
	}
	else
	{
		cout <<"编号不合法！\n";
	}
	system("pause");
}
void foutput(Voter *head,VoteA *head2,VoteB *head3)
{
	ofstream of1("voter.txt");
	ofstream of2("vote_a.txt");
	ofstream of3("vote_b.txt");
	Voter *p = head;
	VoteA *q = head2;
	VoteB *r = head3;
	while(p != NULL){
		of1<<p->ID<<" "; 
		of1<<p->Letter<<" "; 
		of1<<p->Name<<" "; 
		of1<<p->VipOrNot<<" "<<endl; 
		p = p->Next;
	}
	while(q != NULL){
		of2<<q->Name<<" "; 
		of2<<q->Vote<<" "<<endl;
		q = q->Next;
	}
	while(r != NULL){
		of3<<r->Name<<" "; 
		of3<<r->Vote<<" "<<endl;
		r = r->Next;
	}
	cout<<"保存完成！\n";
	system("pause");
	return;
}

