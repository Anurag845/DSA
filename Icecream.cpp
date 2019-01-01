#include<iostream>
using namespace std;

class node
{
	int rno;
	string name;
	node* next;
   public:
   	node()
   	{
   		rno=0;
   		name="none";
   		next=NULL;
   	}
   	friend class icecream;
};

class icecream
{
	node *s,*l;
	int no;
   public:
   	icecream()
   	{
   		s=NULL;
   		l=NULL;
   		no=0;
   	}
   
   	void ins_all()
   	{
   		node *previous=NULL;
   		cout<<"Enter the total number of students"<<endl;
   		cin>>no;
   		for(int i=0;i<no;i++)
   		{
   			previous=l;
   			l=new node;
   			if(i==0)
   				s=l;
   			cout<<"Enter name of student"<<endl;
   			cin>>l->name;
   			cout<<"Enter roll number of student"<<endl;
   			cin>>l->rno;
   			l->next=NULL;
   			if(i!=0)
   				previous->next=l;
   		} 
   	}

	void ins_van()
	{
		node *previous=NULL;
		cout<<"Enter the number of students who like vanilla icecream"<<endl;
		cin>>no;
		for(int i=0;i<no;i++)
		{
			previous=l;
			l=new node;
			if(i==0)
				s=l;
			cout<<"Enter name of student"<<endl;
   			cin>>l->name;
   			cout<<"Enter roll number of student"<<endl;
   			cin>>l->rno;
   			l->next=NULL;
   			if(i!=0)
   				previous->next=l;
		}
	}
	
	void ins_but()
	{
		node *previous=NULL;
		cout<<"Enter the number of students who like butterscotch ice-cream"<<endl;
		cin>>no;
		for(int i=0;i<no;i++)
		{
			previous=l;
			l=new node;
			if(i==0)
				s=l;
			cout<<"Enter name of student"<<endl;
   			cin>>l->name;
   			cout<<"Enter roll number of student"<<endl;
   			cin>>l->rno;
   			l->next=NULL;
   			if(i!=0)
   				previous->next=l;
		}
	}
	
	void both(icecream i1,icecream i2)
	{
		node *c1=NULL,*c2=NULL,*previous=NULL;
		c1=i1.s;
		int k=0;
		for(int i=0;i<i1.no;i++)
		{
			c2=i2.s;
			for(int j=0;j<i2.no;j++)
			{
				if(c1->rno==c2->rno)
				{
					previous=l;
					l=new node;					
					l->rno=c1->rno;
					l->name=c1->name;
					l->next=NULL;
					if(k==0)
						s=l;
					else
						previous->next=l;
					k++;
					break;
				}
				c2=c2->next;
			}
			c1=c1->next;
		}
		no=k;
	}
	
	void either(icecream i1,icecream i2)
	{
		node *c1=NULL,*c2=NULL,*previous=NULL;
		c1=i1.s;
		int k=0,i,j;
		for(i=0;i<i1.no;i++)
		{
			previous=l;
			l=new node;
			l->name=c1->name;
			l->rno=c1->rno;
			l->next=NULL;
			if(i==0)
				s=l;
			else
				previous->next=l;
			c1=c1->next;
			k++;
		}
		c2=i2.s;
		for(j=0;j<i2.no;j++)
		{
			c1=i1.s;
			for(i=0;i<i1.no;i++)
			{
				if(c2->rno==c1->rno)
					break;
				c1=c1->next;
			}
			if(i==i1.no)
			{
				previous=l;
				l=new node;
				l->name=c2->name;
				l->rno=c2->rno;
				l->next=NULL;
				previous->next=l;
				k++; 
			}
			c2=c2->next;
		}
		no=k;
	}
	
	void only_van(icecream i1,icecream i2)
	{
		node *c1=NULL,*c2=NULL,*previous=NULL;
		int i,j,k=0;
		c1=i1.s;
		for(i=0;i<i1.no;i++)
		{
			c2=i2.s;
			for(j=0;j<i2.no;j++)
			{
				if(c1->rno==c2->rno)
					break;
				c2=c2->next;
			}
			if(j==i2.no)
			{
				previous=l;
				l=new node;
				l->name=c1->name;
				l->rno=c1->rno;
				l->next=NULL;
				if(k==0)
					s=l;
				else
					previous->next=l;
				k++;
			}
			c1=c1->next;
		}
		no=k;
	}
	
	void only_but(icecream i1,icecream i2)
	{
		node *c1=NULL,*c2=NULL,*previous=NULL;
		int i,j,k=0;
		c2=i2.s;
		for(i=0;i<i2.no;i++)
		{
			c1=i1.s;
			for(j=0;j<i1.no;j++)
			{
				if(c1->rno==c2->rno)
					break;
				c1=c1->next;
			}
			if(j==i1.no)
			{
				previous=l;
				l=new node;
				l->name=c2->name;
				l->rno=c2->rno;
				l->next=NULL;
				if(k==0)
					s=l;
				else
					previous->next=l;
				k++;
			}
			c2=c2->next;
		}
		no=k;
	}
	
	void neither(icecream i1,icecream i2)
	{
		node *c1=NULL,*c2=NULL,*previous=NULL;
		int i,j,k=0;
		c1=i1.s;
		for(i=0;i<i1.no;i++)
		{
			c2=i2.s;
			for(j=0;j<i2.no;j++)
			{
				if(c1->rno==c2->rno)
					break;
				c2=c2->next;
			}
			if(j==i2.no)
			{
				previous=l;
				l=new node;
				l->rno=c1->rno;
				l->name=c1->name;
				l->next=NULL;
				if(k==0)
					s=l;
				else
					previous->next=l;
				k++;
			}
			c1=c1->next;
		}
		no=k;
	}
   	
   	void display()
   	{
   		cout<<"Data is"<<endl;
   		node* c=NULL;
   		c=s;
   		while(c!=NULL)
   		{
   			cout<<"Name:-"<<c->name<<endl;
   			cout<<"Roll number:-"<<c->rno<<endl;
   			c=c->next;
   		}
   	}
   	
};

int main()
{
	char ch='y';
	int ch1;
	icecream i,i1,i2,i3,i4,i5,i6,i7;
	while(ch=='y' || ch=='Y')
	{
		cout<<"Enter 1 to insert data of all students"<<endl;
		cout<<"Enter 2 to insert data of students who like vanilla"<<endl;
		cout<<"Enter 3 to insert data of students who like butterscotch"<<endl;
		cout<<"Enter 4 to display data of students who like both vanilla and butterscotch"<<endl;
		cout<<"Enter 5 to display data of students who like either vanilla or butterscotch"<<endl;
		cout<<"Enter 6 to display data of students who like only vanilla"<<endl;
		cout<<"Enter 7 to display data of students who like only butterscotch"<<endl;
		cout<<"Enter 8 to display data of students who like neither vanilla nor butterscotch"<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1: i.ins_all();
					i.display();
					break;
			case 2: i1.ins_van();
					i1.display();
					break;
			case 3: i2.ins_but();
					i2.display();
					break;
			case 4: i3.both(i1,i2);
					i3.display();
					break;
			case 5: i4.either(i1,i2);
					i4.display();
					break;
			case 6: i5.only_van(i1,i2);
					i5.display();
					break;
			case 7: i6.only_but(i1,i2);
					i6.display();
					break;
			case 8: i7.neither(i,i4);
					i7.display();
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}
