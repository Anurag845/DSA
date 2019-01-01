#include<iostream>
using namespace std;

class node
{
	string jbnm;
	int priority;
	node* next;
	public:
	node()
	{
		next=NULL;
		jbnm='\0';
		priority=0;
	}
	friend class PriorityQ;
};

class PriorityQ
{
	node *s,*l;
	public:
	PriorityQ()
	{
		s=NULL;
		l=NULL;
	}
	
	void insert()
	{
		node *c=NULL,*p=NULL,*new1=NULL;
		new1=new node;
		cout<<"Enter job name"<<endl;
		cin>>new1->jbnm;
		cout<<"Enter job priority"<<endl;
		cin>>new1->priority;
		new1->next=NULL;
		if(s==NULL)
		{
			new1->next=NULL;
			s=new1;
			l=new1;
		}
		else
		{
			c=s;
			while(new1->priority > c->priority && c->next!=NULL)
			{
				p=c;
				c=c->next;
			}
			if(c==s && new1->priority<c->priority)
			{
				new1->next=s;
				s=new1;
			}
			else if(c->next==NULL)
			{
				l->next=new1;
				l=new1;
			}
			else
			{
				p->next=new1;
				new1->next=c;
			}
		}
	}
	
	void execute()
	{
		node *c=NULL;
		c=s;
		s=s->next;
		cout<<c->jbnm<<" has been executed"<<endl;
		delete c;
	}
	
	void display()
	{
		node *c=NULL;
		c=s;
		if(s==NULL)
			cout<<"There are no jobs to display"<<endl;
		else
		{
			while(c!=NULL)
			{
				cout<<"Job name:- "<<c->jbnm<<endl;
				cout<<"Priority:- "<<c->priority<<endl<<endl;
				c=c->next;
			}
		}
	}
};

int main()
{
	PriorityQ p;
	char ch='y';
	int choice;
	while(ch=='y')
	{
		cout<<"Press 1 to insert a job into the queue"<<endl;
		cout<<"Press 2 to execute a job from the queue"<<endl;
		cout<<"Press 3 to display the queue"<<endl;
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: p.insert();
					break;
			case 2: p.execute();
			    	break; 
			case 3: p.display();
					break;
			default:cout<<"Incorrect choice"<<endl;
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	} 
	return 0;
}
