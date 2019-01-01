#include<iostream>
using namespace std;

class PQueue
{
	int front,rear;
	int job[25];
   public:
   
   	PQueue()
   	{
   		front=-1;
   		rear=-1;
   	}
   
   	void insert()
   	{
   		int i,priority;
   		if(rear==24)
   			cout<<"Queue is full"<<endl;
   		else 
   		{	
   			cout<<"Enter priority of the job"<<endl;
   			cin>>priority;
   			if(front==-1)
   			{
   				front++;
   				rear++;
   				job[front]=priority;
   			}
   			else
   			{
   				for(i=front;i<=rear;i++)
   				{
   					if(priority<job[i])
   						break;
   				}
   				for(int j=rear;j>=i;j--)
   				{
   					job[j+1]=job[j];
   				}
   				job[i]=priority;
   				rear++;
   			}
   		}
   	}
   	
   	void display()
   	{
   		for(int i=front;i<=rear;i++)
   		{
   			cout<<job[i]<<" ";
   		}
   		cout<<endl;
   	}
   	
   	void remove()
   	{
   		if(front==-1)
   		{
   			cout<<"There are no jobs to execute"<<endl;
   		}
   		else
   		{
   			cout<<"Job with priority "<<job[front]<<" has been executed"<<endl;
   			front++;
   		}
   	}
};

int main()
{
	PQueue p;
	char ch='y';
	int choice;
	while(ch=='y' || ch=='Y')
	{
		cout<<"Press 1 to add a job to queue"<<endl;
		cout<<"Press 2 to execute a job from queue"<<endl;
		cout<<"Press 3 to display the job queue"<<endl;
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(1,'\n');
			cout<<"Enter only integer value"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: p.insert();
					break;
			case 2: p.remove();
					break; 
			case 3: p.display();
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}
