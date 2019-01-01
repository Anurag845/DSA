#include <iostream>
using namespace std;

/*class node
{
    int avail,seat;
    node *next,*prev;
public:
    node()
    {
        avail=0;
        seat=0;
        next=NULL;
        prev=NULL;
    }
    friend class Linklist;
};

class Linklist
{
    int a[10];
    node* p[10];
public:
    Linklist()
    {
        int i,j;
        node* temp=NULL;
        for(i=0;i<10;i++)
        {
        	p[i]=NULL;
        }
        for(i=0;i<10;i++)
        {
            a[i]=0;
            for(j=0;j<7;j++)
            {
                node* new1=new node;
                new1->seat=j+1;
                new1->prev=temp;
                temp=new1;
                if(temp->seat==1)
                {
                    p[i]=temp;
                }
                if(temp->avail==0)
                    a[i]++;
            }
            p[i]->prev=temp;
        }
    }

    void displayavail()
    {
        int i,j;
        node* current=NULL;
        for(i=0;i<10;i++)
        {
            current=p[i];
            for(j=0;j<7;j++)
            {
                current=p[i];
                current=current->prev;
            }
        }
        for(i=0;i<10;i++)
        {
            node *ptr=p[i];
            for(j=0;j<7;j++)
            {
                node *l=ptr->prev;
                l->next=ptr;
                ptr=ptr->prev;
            }
        }
        cout<<"               ";
        for(i=0;i<7;i++)
        {
            cout<<i+1<<"      ";
        }
        cout<<endl;
        for(i=0;i<10;i++)
        {
            cout<<"Row "<<i<<"     "<<a[i]<<"    ";
            current=p[i];
            for(j=0;j<7;j++)
            {
                cout<<current->avail<<"      ";
                current=current->next;
            }
            cout<<endl;
        }
    }


    void bookseats()
    {
        int i,j=0,no,k,row,cnt=0,c=0,ct=0;
        char ch1,ch2;

        cout<<"Enter the number of seats you want to book"<<endl;
        cin>>no;
        cout<<"Enter the preferred row number"<<endl;
        cin>>row;
        node* current=p[row];

        for(k=0;k<10;k++)
        {
            for(i=0;i<7;i++)
            {
                if(current->avail==0)
                {
                    j++;
                }
                current=current->next;
            }
            if(j>=no)
            {
                cout<<no<<" consecutive seats are available in row "<<row<<". Do you want to confirm the booking? y/n"<<endl;
                cin>>ch1;
                if(ch1=='y' || ch1=='Y')
                {
                    current=p[row];
                    for(i=0;i<7;i++)
                    {
                        if(current->avail==0 && cnt<no)
                        {
                            current->avail=1;
                            a[row]--;
                            cnt++;
                        }
                        current=current->next;
                    }
                    cout<<"Booking successful"<<endl;
                }
                break;
            }
            else
            {
                cout<<no<<" consecutive seats are not available in row "<<row<<endl;
                if(row==9)
                {
                    row=0;
                    k=0;
                }
                else
                    row++;
            }
            c++;
            if(c==10)
            {
                cout<<no<<" consecutive seats are not available in any row"<<endl;
                break;
            }
        }
        cnt=0;
        if(c==10)
        {
            cout<<no<<" consecutive seats are not available in any row"<<endl;
            for(i=0;i<10;i++)
            {
                current=p[i];
                for(j=0;j<7;j++)
                {
                    if(current->avail==0)
                    {
                        cnt++;
                    }
                    current=current->next;
                }
            }
            if(cnt>=no)
            {
                cout<<no<<" seats are located at discrete locations.Do you want to confirm the booking? y/n"<<endl;
                cin>>ch2;
                if(ch2=='y' || ch2=='Y')
                {
                    for(i=0;i<10;i++)
                    {
                        current=p[i];
                        for(j=0;j<7;j++)
                        {
                            if(current->avail==0 && ct<=no)
                            {
                                current->avail=1;
                                a[i]--;
                                ct++;
                            }
                            current=current->next;
                        }
                    }
                    cout<<"Booking successful"<<endl;
                }
            }
            else
            {
                cout<<cnt<<" seats are available at discrete locations.Do you want to confirm the booking?"<<endl;
                for(i=0;i<10;i++)
                {
                    current=p[i];
                    for(j=0;j<7;j++)
                    {
                        if(current->avail==0 && ct<=no)
                          {
                            current->avail=1;
                            a[i]--;
                            ct++;
                        }
                        current=current->next;
                    }
                }
                cout<<"Booking successful"<<endl;
            }
        }
    }


    void cancel()
    {

    }

};

int main()
{
    Linklist L;
    char ch='y';
    int c;
    L.displayavail();
    while(ch=='y' ||ch=='Y')
    {
        cout<<"Press 1 to display available seats"<<endl;
        cout<<"Press 2 to book seats"<<endl;
        cout<<"Press 3 to cancel the booking"<<endl;
        cin>>c;
        switch(c)
        {
            case 1: L.displayavail();
            		break;
            case 2: L.bookseats();
            		break;
            //case 3:L.cancel();
            //break;
            default:cout<<"Entered choice is incorrect"<<endl;
        }
        cout<<"Do you want to continue? y/n"<<endl;
        cin>>ch;
    }
    return 0;
}*/



class node
{
	int avail,seat; // avail=0 means seat available. avail=1 means booked. seat is for seat number
	node *prev,*next;
	public:
	node()
	{
		avail=0;
		seat=0;
		prev=NULL;
		next=NULL;
	}
	friend class Cinemax;
};

class Cinemax
{
	int available[10];
	node *head[10];    //head node is the first node of each row
	public:
	
	Cinemax()
	{
		node *s=NULL,*l=NULL,*c=NULL;
		for(int i=0;i<10;i++)
		{
			head[i]=NULL;
			available[i]=6;
		}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<7;j++)
			{
				if(j==0)
				{
					c=new node;
					c->next=NULL;
					c->prev=NULL;
					l=c;
					s=c;
					head[i]=c;
				}
				else
				{
					c=new node;
					c->next=NULL;
					l->next=c;
					c->prev=l;
					l=c;
					if(j==3)
						c->avail=1;
				}
			}
			head[i]->prev=l;
			l->next=head[i];
		}
	}
	
	void display()
	{
		node *c=NULL;
		cout<<"    Available\t";
		for(int i=0;i<7;i++)
		{
			cout<<i+1<<"\t";
		}
		cout<<endl;
		for(int i=0;i<10;i++)
		{
			cout<<i+1<<"\t";
			cout<<available[i]<<"\t";
			c=head[i];
			for(int j=0;j<7;j++)
			{
				cout<<c->avail<<"\t";
				c=c->next;
			}
			cout<<endl;
		}
	}
	
	void book()
	{
		node *s=NULL,*l=NULL,*c=NULL;
		int no,count=0,row,cnt=0,ct=0;
		char ch;
		cout<<"Enter the number of seats you want to book"<<endl;
		cin>>no;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value"<<endl;
			cin>>no;
		}
		cout<<"Enter the preferred row"<<endl;
		cin>>row;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value from 1 to 10"<<endl;
			cin>>row; 
		}
		while(cnt<=10)
		{
			if(no<=available[row-1])
			{
				cout<<no<<" seats are available in row "<<row<<".Proceed with booking? (y/n)"<<endl;
				cin>>ch;
				while(ch!='y' && ch!='n')
				{
					cin.clear();
					cin.ignore(5,'\n');
					cout<<"Enter either y or n"<<endl;
					cin>>ch;
				}
				if(ch=='y')
				{
					c=head[row-1];
					count=0;
					for(int i=0;i<7;i++)
					{	
						if(c->avail==0 && count<no)
						{
							c->avail=1;
							available[row-1]-=1;
							count+=1;
						}
						c=c->next;
					}
					cout<<"Booking successful"<<endl;
				} 
				break;
			}
			else
			{
				if(row==10)
					row=1;
				else
					row++;
				cnt++;
			}
		}
		if(cnt==11)
		{
			int sum=0,k=0;
			while(sum<no)
			{
				sum=sum+available[k];
				k++;	
			}
			if(k<=10)
			{
				cout<<no<<" seats available at discrete locations. Proceed with booking? (y/n)"<<endl;
				cin>>ch;
				while(ch!='y' && ch!='n')
				{
					cin.clear();
					cin.ignore(5,'\n');
					cout<<"Enter either y or n"<<endl;
					cin>>ch;
				}
				if(ch=='y')
				{
					for(int i=0;i<10;i++)
					{
						c=head[i];
						for(int j=0;j<7;j++)
						{
							if(c->avail==0 && ct<no)
							{
								c->avail=1;
								available[i]-=1;
								ct++;
							}
							c=c->next;
						}
					}
					cout<<"Booking successful"<<endl;
				}
			}
			else
				cout<<no<<" number of seats not available"<<endl;
		}
	}
	
	void cancel()
	{
		node *c=NULL;
		int i=0,rw,col;
		cout<<"Enter the row number of seat to be cancelled"<<endl;
		cin>>rw;
		while(!cin || rw>10)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value from 1 to 10"<<endl;
			cin>>rw;
		}
		cout<<"Enter the column number of seat to be cancelled"<<endl;
		cin>>col;
		while(!cin || col>7)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value from 1 to 7"<<endl;
			cin>>col;
		}
		c=head[rw-1];
		while(i<col-1)
		{
			c=c->next;
			i++;
		}
		if(c->avail==1)
		{
			c->avail=0;
			available[rw-1]-=1;
			cout<<"Cancellation successful"<<endl;
		}
		else
			cout<<"Seat is already vacant"<<endl;
	}
	
};


int main()
{
	Cinemax C;
	int choice;
	char ch='y';
	while(ch=='y')
	{
		cout<<"Press 1 to display the status of the seats"<<endl;
		cout<<"Press 2 to book seats"<<endl;
		cout<<"Press 3 to cancel booking"<<endl;
		cin>>choice;
		while(choice!=1 && choice!=2 && choice!=3)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value from 1, 2 and 3"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: C.display();
					break;
			case 2: C.book();
					break;
			case 3: C.cancel();
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
		while(ch!='y' && ch!='n')
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter either y or n"<<endl;
			cin>>ch;
		}
	}
	return 0;
}

