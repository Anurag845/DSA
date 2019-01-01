#include<iostream>
using namespace std;

class Deque
{
	string dq[25];
	int front,rear;
	public:
	Deque()
	{
		front=-1;
		rear=-1;
	}
	
	void insert_front()
	{
		string jbnm;
		cout<<"Enter data"<<endl;
		cin>>jbnm;
		if(front==0 && rear==24)
			cout<<"Overflow"<<endl;
		else if(front==-1)
		{
			front++;
			rear++;
			dq[front]=jbnm;
		}
		else if(front!=0)
		{
			front-=1;
			dq[front]=jbnm;
		}
		else
		{
			for(int i=rear;i>=front;i-=1)
			{
				dq[i+1]=dq[i];
			}
			rear++;
			dq[front]=jbnm;
		}
	}
	
	void insert_rear()
	{
		string jbnm;
		cout<<"Enter data"<<endl;
		cin>>jbnm;
		if(rear==24)
			cout<<"Overflow"<<endl;
		else if(front==-1)
		{
			front++;
			rear++;
			dq[front]=jbnm;
		}
		else
		{
			rear++;
			dq[rear]=jbnm;
		}
	}
	
	void delete_front()
	{
		if(front==-1)
			cout<<"Underflow"<<endl;
		else
		{
			cout<<dq[front]<<" has been deleted"<<endl;
			if(front==rear)
			{
				front=rear=-1;
			}
			else
				front++;
		} 		
	}
	
	void delete_rear()
	{
		if(front==-1)
			cout<<"Underflow"<<endl;
		else
		{
			cout<<dq[rear]<<" has been deleted"<<endl;
			if(front==rear)
			{
				front=rear=-1;
			}
			else
				rear-=1;
		}
	}
	
	void display()
	{
		if(front==-1)
			cout<<"There is no data to display"<<endl;
		else
		{
			for(int i=front;i<=rear;i++)
				cout<<dq[i]<<" ";
			cout<<endl;
		}
	}
	
};

int main()
{
	Deque D;
	char ch='y';
	int choice;
	while(ch=='y')
	{
		cout<<"Press 1 to insert at the front"<<endl;
		cout<<"Press 2 to insert at the rear"<<endl;
		cout<<"Press 3 to delete from the front"<<endl;
		cout<<"Press 4 to delete from the rear"<<endl;
		cout<<"Press 5 to display the dequeue"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: D.insert_front();
					break;
			case 2: D.insert_rear();
					break;
			case 3: D.delete_front();
					break;
			case 4: D.delete_rear();
					break;
			case 5: D.display();
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}
