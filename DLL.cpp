#include<iostream>
using namespace std;

class node
{
    int data;
    node *next,*prev;
    public:   
    node()
    {
        data=0;
        next=NULL;
        prev=NULL;
    }
    friend class DLL;
};

class DLL
{
    node *s,*l;
    public:
    DLL()
    {
        s=NULL;
        l=NULL;
    }

    void insert()
    {
        node *p=NULL;
        p=new node;
        cout<<"Enter data ";
        cin>>p->data;
        if(s==NULL)
        {
            s=p;
            l=p;
        }
        else
        {
            int c;
            cout<<"Enter 1 to insert at beginning"<<endl;
            cout<<"Enter 2 to insert at end"<<endl;
            cout<<"Enter 3 to insert at the middle"<<endl;
            cin>>c;
            switch(c)
            {
                case 1: p->next=s;
                    	s->prev=p;
                    	s=p;
                    	break;
                case 2: l->next=p;
                    	p->prev=l;
                    	l=p;
                    	break;
                case 3: if(s->next==NULL)
                    	{
                    		s->next=p;
                    		p->prev=s;
                    	    l=p;
                    	}
                    	else
                    	{
                    		p->next=s->next;
                			s->next->prev=p;
                			s->next=p;
                    		p->prev=s;
                    	}
                    	break;
                default:cout<<"Wrong choice"<<endl;
            }
        }
    }

    void remove()
    {
		if(s==NULL)
			cout<<"There is no node to delete"<<endl;
		else
		{
        	node *p=NULL,*p1=NULL,*p2=NULL;
        	int info;
        	cout<<"Enter the data to be deleted"<<endl;
        	cin>>info;
        	while(!cin)
        	{
        	    cin.clear();
        	    cin.ignore('\n',5);
        	    cout<<"Enter only integer values"<<endl;
        	    cin>>info;
        	}
        	p=s;
        	while(p!=NULL && p->data!=info)
        	{
        	    p=p->next;
        	}
        	if(p==NULL)
        	{
        	    cout<<"Entered data is not in the linked list"<<endl;
        	}
        	else if(p->data==info)
        	{	
            	if(p==s)
            	{
            	    s=s->next;
            	    s->prev=NULL;
            	    p->next=NULL;
            	    delete p;   
            	}
            	else if(p==l)
            	{
            	    l=l->prev;
            	    l->next=NULL;
            	    p->prev=NULL;
            	    delete p;
            	}
            	else
            	{
            		p1=p->prev;
            		p2=p->next;
            	    p1->next=p->next;
            	    p2->prev=p->prev;
            	    p->next=NULL;
            	    p->prev=NULL;
            	    delete p;
            	}
        	}
        }
    }

    void show()
    {
        node *p;
        p=s;
        while(p!=NULL)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
        cout<<endl;
    }
};


int main()
{
    char ch='y';
    int choice;
    DLL dl;

    while(ch=='y')
    {
        cout<<"Enter 1 to insert node"<<endl;
        cout<<"Enter 2 to delete node"<<endl;
        cout<<"Enter 3 to display the doubly linked list"<<endl;
        cin>>choice;
   
        while(!cin)
        {
            cin.clear();
            cin.ignore('\n',5);
            cout<<"Enter only integer values"<<endl;
            cin>>choice;
        }
       
        switch(choice)
        {
            case 1: dl.insert();
                break;
            case 2: dl.remove();
                break;
            case 3: dl.show();
                break;
            default:cout<<"Wrong choice"<<endl;
        }
   
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>ch;
    }
    return 0;
}
