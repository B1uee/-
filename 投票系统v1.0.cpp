#include <iostream>
#include <string>
#include <cstring> 
#include <fstream>
#include <sstream>


using namespace std;


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
void SearchVoter(Voter *head); // ��ѯͶƱ����Ϣ 
void CoutVoter(Voter *head); // ���ͶƱ����Ϣ 
void CoutVote(Vote1 *head1, Vote2 *head2); // ���ͶƱ��Ϣ 
void AddVoter(Voter *head, Vote1 *head1, Vote2 *head2); // ����ͶƱ�� 
void DeleteVoter(Voter *&head, Vote1 *head1, Vote2 *head2); // ɾ��ͶƱ�� 
void ReviseVote(Voter *head, Vote1 *head1, Vote2 *head2); // �޸�ͶƱ������Ϣ 
void CoutHighest(Vote1 *head1, Vote2 *head2); // ������Ʊ�������� 
void foutput(Voter *head, Vote1 *head1, Vote2 *head2); // 
void Exit();// �˳�ϵͳ 

// ���� 


// ������ 
int main()
{
	Voter *head;
    Vote1 *head1; 
	Vote2 *head2;
	head = Create();
	head1 = Create1();
	head2 = Create2();
	//SearchVoter(head); 				�ɹ� 
	//CoutVoter(head); 				    �ɹ�
	//CoutVote(head1, head2);  		    �ɹ� 
	AddVoter(head, head1, head2);
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
void SearchVoter(Voter *head)
{
	Voter *p = head;
    cout<<"������ͶƱ�û�������ͶƱ������"<<endl;
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
				cout << p -> name << " "<< p -> number << " "<< p -> choice << " "<< p -> ifvip << endl;
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
 

// ���ͶƱ��Ϣ 
void CoutVote(Vote1 *head1, Vote2 *head2)
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
	Vote2 *s = head2;
	Vote2 *s1 = head2; 
	Vote2 *s2 = head2; 
	C:cout << "�����������ӵ�ͶƱ����Ϣ:" << endl;
	cout << "����:" << "   ";
	cin >>  ming;
	while(p != NULL)
	{
		if(p -> name == ming)
		{
			cout << "�벻Ҫ�ظ�ͶƱ��" << endl; 
			system ("pause");
			goto C; 
		}
		p = p -> next; // p����ָ�����һ���ڵ� 
	}
	q -> name = ming; // �����ռ���ʱ�洢���� 
	A:cout << endl << "ͶƱ��ţ�   " ;
	cin >> hao;
	q -> number = hao;
	if (hao != "a" && hao != "b") 
	{
	cout << "��Ŵ������������룡" << endl; 
	goto A; 
	} 
	B:cout << endl << "ͶƱ�˵ȼ���   " ;
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
	cout << "����������ͶƱ��ѡ�" << endl; 
	cin >> xuan;
	q -> choice = xuan;

	// cout << q -> name << q -> number << q -> choice; �洢�ɹ� 
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
				cout << "\n����ͶƱ��\n" << q->name << " " << q -> number << " " << q -> choice << " " << q -> ifvip << endl;
				cout << "\n��ǰ��Ʊ����\n"; 
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
				cout << "\n����ͶƱ��\n" << q -> name << " " << q -> number << " " << q-> choice << " " << q -> ifvip << endl;
				cout << "\n��ǰ��Ʊ����\n"; 
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
