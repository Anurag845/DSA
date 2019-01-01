#include<iostream>
using namespace std;
#include<string>
class node
{
    int PRN;
    string name;
    char desig;
    node *next;
public:
    node()
    {
        next=NULL;
        PRN=0;
        name="none";
        desig='\0';
    }
    friend class Pinnacle;
};

class Pinnacle
{
    node *s,*l;
public:
    Pinnacle()
    {
        s=NULL;
        l=NULL;
    }

    void ins_pres()
    {
    	char ch;
        node *p=new node;
        p->desig='p';
        cout<<"Enter PRN of president."<<endl;
        cin>>p->PRN;
        cout<<"Enter name of president."<<endl;
        cin>>p->name;
      /*if(s->desig=='p')
        {
        	cout<<"President already exists Do you want to change president? (y/n)"<<endl;
        	cin>>ch;
            if(ch=='y' || ch=='Y')
            {
            	s->PRN=p->PRN;
                s->name=p->name;
                p->next=NULL;
                delete p;
            }
            else
            {
            	cout<<"Try for another designation"<<endl;
            }
        }*/
        if(s==NULL)
        {
            p->next=NULL;
            s=p;
            l=p;
        }
        else
        {
            p->next=s;
            s=p;
        }
    }

    void ins_sec()
    {
        char ch;
        node *p=new node;
        p->desig='s';
        cout<<"Enter PRN of secretary."<<endl;
        cin>>p->PRN;
        cout<<"Enter name of secretary."<<endl;
        cin>>p->name;
      /*if(l->desig=='s')
        {
               cout<<"Secretary already exists.Do you want to change secretary? (y/n)"<<endl;
               cin>>ch;
               if(ch=='y' || ch=='Y')
               {
               		l->PRN=p->PRN;
                    l->name=p->name;
                    p->next=NULL;
                    delete p;
               }
               else
               {
               		cout<<"Try for another designation"<<endl;
               }
        }*/
        if(s==NULL)
        {
            p->next=NULL;
            s=p;
            l=p;
        }
        else
        {
            l->next=p;
            p->next=NULL;
            l=p;
        }
    }

    void ins_mem()
    {
        node *p=new node;
        p->desig='m';
        cout<<"Enter PRN of member."<<endl;
        cin>>p->PRN;
        cout<<"Enter name of member."<<endl;
        cin>>p->name;
        if(s==NULL)
        {
            p->next=NULL;
            s=p;
            l=p;
        }
        else if(s->desig=='m')
        {
            p->next=s;
            s=p;
        }
        else if(s->desig=='s')
        {
            p->next=s;
            s=p;
        }
        else if(s->desig=='p')
        {
            if(s->next==NULL)
            {
                s->next=p;
                p->next=NULL;
                l=p;
            }
            else
            {
                p->next=s->next;
                s->next=p;
            }
        }
    }


    void del()
    {
        node* current=NULL,*previous=NULL;
        int prn,flag;
        cout<<"Enter the PRN of student whose data is to be deleted"<<endl;
        cin>>prn;
        current=s;
        if(s==NULL)
        {
            cout<<"There is no data to delete"<<endl;
        }
        else
        {
            while(current!=NULL)
            {
                if(current->PRN==prn)
                {
                    flag=1;
                    break;
                }
                else
                {
                    previous=current;
                    current=current->next;
                }
            }
            if(flag==1)
            {
                if(current==s)
                {
                    s=current->next;
                    current->next=NULL;
                    delete current;
                }
                else if(current==l)
                {
                    l=previous;
                    previous->next=NULL;
                    delete current;
                }
                else
                {
                    previous->next=current->next;
                    current->next=NULL;
                    delete current;
                }
            }
            else
            {
                cout<<"Requested PRN wasn't found"<<endl;
            }
        }
    }

    void display()
    {
        node * c=s;
        while(c!=NULL)
        {
            cout<<"Designation :- "<<c->desig<<endl;
            cout<<"PRN :- "<<c->PRN<<endl;
            cout<<"Name :- "<<c->name<<endl;
            c=c->next;
        }
    }

    void no_ppl()
    {
        node *c=NULL;
        c=s;
        int cnt=0;
        while(c!=NULL)
        {
            c=c->next;
            cnt++;
        }
        cout<<"The number of people in the club is "<<cnt<<endl;
    }

    void concat(Pinnacle p1,Pinnacle p2)
    {
        node *c=NULL;
        s=p1.s;
        c=p1.s;
        while(c!=p1.l)
        {
            c=c->next;
        }
        c->next=p2.s;
        l=p2.l;
    }

    void rev()
    {
        rev(s);
    }

    void rev(node* p)
    {
        if(p==NULL)
        {
            return;
        }
        else
        {
            rev(p->next);
            cout<<"Designation :- "<<p->desig<<endl;
            cout<<"PRN :- "<<p->PRN<<endl;
            cout<<"Name :- "<<p->name<<endl;
        }
    }

	void Sort()
	{
		node *pos1=NULL,*pos2=NULL,*min=NULL;
		pos1=s;
		while(pos1!=NULL)
		{
			pos2=pos1;
			min=pos2;
			while(pos2!=NULL)
			{
				if(pos2->PRN<min->PRN)
					min=pos2;
				pos2=pos2->next;
			}
			swap(pos1->PRN,min->PRN);
			swap(pos1->name,min->name);
			swap(pos1->desig,min->desig);
			pos1=pos1->next;
		}
	}
	
	void merge(Pinnacle p1,Pinnacle p2)
	{
		p1.Sort();
		p2.Sort();
		node *c1=NULL,*c2=NULL,*c3=NULL,*p=NULL;
		int k=0;
		c1=p1.s;
		c2=p2.s;
		while(c1!=NULL && c2!=NULL)
		{
			if(c1->PRN<c2->PRN)
			{
				c3=new node;
				c3->PRN=c1->PRN;
				c3->name=c1->name;
				c3->desig=c1->desig;
				if(k==0)
					s=c3;
				else
					p->next=c3;
				l=c3;
				k++;
				p=c3;
				c1=c1->next;
			}
			else if(c1->PRN>c2->PRN)
			{
				c3=new node;
				c3->PRN=c2->PRN;
				c3->name=c2->name;
				c3->desig=c2->desig;
				if(k==0)
					s=c3;
				else
					p->next=c3;
				l=c3;
				k++;
				p=c3;				
				c2=c2->next;			
			}
		}
		while(c1!=NULL && c2==NULL)
		{
			c3=new node;
			c3->PRN=c1->PRN;
			c3->name=c1->name;
			c3->desig=c1->desig;
			if(k==0)
				s=c3;
			else
				p->next=c3;
			l=c3;
			k++;
			p=c3;
			c1=c1->next;
		}
		while(c1==NULL && c2!=NULL)
		{
			c3=new node;
			c3->PRN=c2->PRN;
			c3->name=c2->name;
			c3->desig=c2->desig;
			if(k==0)
				s=c3;
			else
				p->next=c3;
			l=c3;
			k++;
			p=c3;				
			c2=c2->next;
		}
	}

};

int main()
{
    Pinnacle p1,p2,p3,p4;
    char ch='y';
    int choice1,choice2,choice3;
    while(ch=='y' || ch=='Y')
    {
        cout<<"Enter 1 to insert data."<<endl;
        cout<<"Enter 2 to delete data."<<endl;
        cout<<"Enter 3 to display the club data."<<endl;
        cout<<"Enter 4 to display the number of members in the club."<<endl;
        cout<<"Enter 5 to display list in reverse order."<<endl;
        cout<<"Enter 6 to concatenate two strings."<<endl;
        cout<<"Enter 7 to sort list."<<endl;
        cin>>choice1;
        switch(choice1)
        {
        case 1: cout<<"For list 1 enter 1"<<endl;
                cout<<"For list 2 enter 2"<<endl;
                cin>>choice2;
                if(choice2==1)
                {
                    cout<<"Enter 1 to enter President's data"<<endl;
                    cout<<"Enter 2 to enter Secretary's data"<<endl;
                    cout<<"Enter 3 to enter Member's data"<<endl;
                    cin>>choice3;
                    switch(choice3)
                    {
                        case 1: p1.ins_pres();
                                break;
                        case 2: p1.ins_sec();
                                break;
                        case 3: p1.ins_mem();
                                break;
                    }
                }
                else if(choice2==2)
                {
                    cout<<"Enter 1 to enter President's data"<<endl;
                    cout<<"Enter 2 to enter Secretary's data"<<endl;
                    cout<<"Enter 3 to enter Member's data"<<endl;
                    cin>>choice3;
                    switch(choice3)
                    {
                        case 1: p2.ins_pres();
                                break;
                        case 2: p2.ins_sec();
                                break;
                        case 3: p2.ins_mem();
                                break;
                    }
                }
                else
                    cout<<"Entered choice is incorrect."<<endl;
            break;
        case 2: cout<<"For list 1 enter 1"<<endl;
                cout<<"For list 2 enter 2"<<endl;
                cin>>choice2;
                if(choice2==1)
                {
                    p1.del();
                }
                else if(choice2==2)
                {
                    p2.del();
                }
                else
                    cout<<"Entered choice is incorrect."<<endl;
            break;
        case 3: cout<<"For list 1 enter 1"<<endl;
                cout<<"For list 2 enter 2"<<endl;
                cout<<"For list 3 enter 3"<<endl;
                cin>>choice2;
                switch(choice2)
                {
                    case 1: p1.display();
                            break;
                    case 2: p2.display();
                            break;
                    case 3: p3.display();
                            break;
                }
            break;
        case 4: cout<<"For list 1 enter 1"<<endl;
                cout<<"For list 2 enter 2"<<endl;
                cout<<"For list 3 enter 3"<<endl;
                cin>>choice2;
                switch(choice2)
                {
                    case 1: p1.no_ppl();
                            break;
                    case 2: p2.no_ppl();
                            break;
                    case 3: p3.no_ppl();
                            break;
                }
            break;
        case 5: cout<<"For list 1 enter 1"<<endl;
                cout<<"For list 2 enter 2"<<endl;
                cout<<"For list 3 enter 3"<<endl;
                cin>>choice2;
                switch(choice2)
                {
                    case 1: p1.rev();
                            break;
                    case 2: p2.rev();
                            break;
                    case 3: p3.rev();
                            break;
                }
            break;
        case 6: p3.concat(p1,p2);
            break;
        case 7: p1.Sort();
        	break;
        case 8: p4.merge(p1,p2);
        		p4.display();	
        	break;
        default: cout<<"Entered choice is incorrect."<<endl;
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>ch;
    }
    return 0;
}
