#include <iostream>
#include <string>
#include <cstring> 
#include <fstream>
#include <sstream>

using namespace std;

struct Voter
	{
		string ID;			//ͶƱ�� 
		string Letter;		//ͶƱ���� 
		string Name;		//��Ʊ�� 
		string VipOrNot;	//�Ƿ�Ϊvip 
		Voter *Next;
	};
struct VoteA
	{
		string Name;		//��Ʊ�� 
		int Vote;			//��Ʊ�� 
		VoteA *Next;
	};
struct VoteB
	{
		string Name;		//ͬ�� 
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
		cout <<"��������ȷ�ı�ţ�\n";
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
		cout <<"��������ȷ�ı�ţ�\n";
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
		cout <<"��������ȷ�ı�ţ�\n";
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
	cout << "                        ͶƱϵͳ������v1.0" << endl;
	cout << "               ����ѡ����������ļ���" << endl;
	cout << "               1)voter.txt  (����ͶƱ��)" << endl;
	cout << "               2)vote.txt  (����ͶƱ����)" << endl;
	cout << "               3)����ͶƱ��Ϣ" << endl;
	cout << "               0)�˳�" << endl << endl << endl;
	cout << "*******************************************************************" << endl;
}
void InterFace1()
{
	cout << "*******************************************************************" << endl << endl << endl;
	cout << "               1)��ѯͶƱ����Ϣ" << endl;
	cout << "               2)���ȫ��ͶƱ����Ϣ" << endl;
	cout << "               3)����ͶƱ����Ϣ" << endl;
	cout << "               4)ɾ��ͶƱ����Ϣ" << endl;
	cout << "               0)�����ϼ��˵�" << endl << endl << endl;
	cout << "*******************************************************************" << endl;
}
void InterFace2()
{
	cout << "*******************************************************************" << endl << endl << endl;
	cout << "               1)���ȫ��ͶƱ��Ϣ" << endl;
	cout << "               2)�޸�ͶƱ������Ϣ" << endl;
	cout << "               3)������Ʊ" << endl;
	cout << "               0)�����ϼ��˵�" << endl << endl << endl;
	cout << "*******************************************************************" << endl;
}
void SearchVoter(Voter *head)
{
	Voter *p=head;
    cout<<"������ͶƱ������������(�ÿո�ָ�)"<<endl;
    string bh;
	string xm;
    cin >> xm >> bh;
    while(p != NULL)
	{
		if(p->ID==xm)
		{
			if (p->Letter==bh)
			{
				cout<<"�û�ͶƱ��Ϣ���£�"<<endl; 
				cout << p->ID << " "<< p->Letter << " "<< p->Name << " "<< p->VipOrNot << endl;
				system ("pause");
				return; 
			}
		}
		p=p->Next;
	}
	cout<<"�û�û��ͶƱ�������⣡"<<endl; 
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
	cout <<"������Ҫ������������ͶƱ������(a/b) (�ÿո�ָ�):\n";
	cin >> xm >> bh;
	while(p != NULL)
	{
		if(p->ID==xm)
		{
			if (p->Letter==bh)
			{
			cout<<"�����ظ�ͶƱ��"<<endl; 
			system ("pause");
			return; 
			}
		}
		p=p->Next;
	}
	q->ID = xm;
	q->Letter =bh;
	cout <<"\nͶƱѡ��һ��:"<<endl;
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
		cout <<"��Ų��Ϸ���"<<endl; 
		system("pause");
		return;
	} 
	cout <<"\n��ѡ��ͶƱ:";
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
				cout <<"�Ƿ�Ϊvip(y/n)��";
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
					cout <<"��������ȷѡ�\n";
					system("pause");
					return;
				}
				cout <<"\n����ͶƱ��\n"<<q->ID<<" "<<q->Letter<<" "<<q->Name<<" "<<q->VipOrNot<<endl;
				cout <<"\n��ǰ��Ʊ����\n"; 
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
				cout <<"�Ƿ�Ϊvip(y/n)��";
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
					cout <<"��������ȷѡ�\n";
					system("pause");
					return;
				}
				cout <<"\n����ͶƱ��\n"<<q->ID<<" "<<q->Letter<<" "<<q->Name<<" "<<q->VipOrNot<<endl;
				cout <<"\n��ǰ��Ʊ����\n"; 
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
	cout <<"ѡ����ڣ�"<<endl; 
	system("pause");
}
void DeleteVoter(Voter *&head,VoteA *head2,VoteB *head3)
{
	Voter *p=head,*q=head;
	VoteA *r=head2,*r1=head2;
	VoteB *s=head3,*s1=head3;
	string xm,bh;
	cout <<"������Ҫɾ����������ͶƱ������(a/b) (�ÿո�ָ�):\n";
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
									cout <<"\nɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
									cout <<"ɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
									cout <<"\nɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
									cout <<"ɾ���ɹ���\n\n��ǰ��Ʊ����\n"; 
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
	cout <<"�û�û��ͶƱ�������⣡\n";
	system ("pause");
	return;
}
void CoutVote(VoteA *head2,VoteB *head3)
{
	VoteA *p = head2;
	VoteB *q = head3;
	string temp;
	cout <<"��������Ҫ�����ͶƱ������(a/b):";
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
	cout <<"��������Ҫ�޸ĵ�ͶƱ����(a/b):";
	cin >> bh;
	if (bh !="a"&&bh !="b")
	{
		cout <<"��Ų��Ϸ���\n";
		system("pause");
		return;
	} 
	cout <<"�������ͶƱ������£�\n";
	if (bh =="a")
	{
		while (r != NULL)
		{
			cout << r->Name <<" "<< r->Vote << endl;
			r = r->Next;
		}
		A:cout <<"��������Ҫ�޸ĵ�ͶƱѡ����޸ĺ��ͶƱѡ�� (�ÿո�ָ�)��";
		cin >> name1 >> name2;
		r = head2;
		while (r != NULL)
		{
			if (r->Name == name2)
			{
				cout <<"�޸ĺ�ѡ��������ѡ���ظ������������룡\n";
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
				cout <<"�޸���ɣ�\n�޸ĺ��ͶƱѡ������:\n";
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
		B:cout <<"��������Ҫ�޸ĵ�ͶƱѡ����޸ĺ��ͶƱѡ�� (�ÿո�ָ�)��";
		cin >> name1 >> name2;
		s = head3;
		while (s != NULL)
		{
			if (s->Name == name2)
			{
				cout <<"�޸ĺ�ѡ��������ѡ���ظ������������룡\n";
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
				cout <<"�޸���ɣ�\n�޸ĺ��ͶƱѡ������:\n";
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
	cout <<"��������Ҫ������Ʊ��ͶƱ������(a/b):"; 
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
		cout <<"���ƱΪ"<<p1->Name<<"��\n��Ʊ��Ϊ"<<p1->Vote<<endl;
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
				cout <<"��"<< p->Name;
			}
			cout <<"���е�һ��\n��Ʊ��Ϊ"<<p1->Vote<<endl; 
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
		cout <<"���ƱΪ"<<q1->Name<<"��\n��Ʊ��Ϊ"<<q1->Vote<<endl;
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
				cout <<"��"<< q->Name;
			}
			cout <<"���е�һ��\n��Ʊ��Ϊ"<<q1->Vote<<endl; 
		}
	}
	else
	{
		cout <<"��Ų��Ϸ���\n";
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
	cout<<"������ɣ�\n";
	system("pause");
	return;
}

