#include<iostream>
using namespace std;

class TrainProgram
{
	int rno;
	public:
	void accept(TrainProgram *p,const int n)
	{
		cout<<"Enter the roll numbers of students who attended the training program"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>p[i].rno;
		}
	}

	void display(TrainProgram *p,const int n)
	{
		p->QuickSort(p,0,n-1);
		cout<<"The roll numbers entered by you are"<<endl;
		for (int i=0;i<n;i++)
		{
			cout<<p[i].rno<<"\t";
		}
		cout<<endl;
	}
	
	void linear(TrainProgram *p,const int n)
	{
		cout<<"----------- Linear Search -----------"<<endl;
		int i,s;
		cout<<"Enter the roll number to be searched"<<endl;
		cin>>s;
		while(!cin)
		{	
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value"<<endl;
			cin>>s;
		}
		for(i=0;i<n;i++)
		{
			if(s==p[i].rno)
				break;
		}
		if(i<n)
			cout<<s<<" found at position "<<i<<endl;
		else
			cout<<s<<" not found in the list"<<endl;
	}
	
	void binary(TrainProgram *p,const int n)
	{
		cout<<"----------- Binary Search -----------"<<endl;
		int s;
		cout<<"Enter the roll number to be searched"<<endl;
		cin>>s;
		int l=0,r=n-1;
		while(l<=r)
		{
			int mid=l+(r-l)/2;
			if(s==p[mid].rno)
			{
				cout<<s<<" found at position "<<mid<<endl;
				return;
			}
			if(p[mid].rno<s)
				l=mid+1;
			else
				r=mid-1;
		}
		cout<<s<<" not found in the list"<<endl;
	}
	
	void sentinel(TrainProgram *p,const int n)
	{
		cout<<"----------- Sentinel Search -----------"<<endl;
		int i=0,s,key=p[n-1].rno;
		cout<<"Enter the roll number to be searched"<<endl;
		cin>>s;
		p[n-1].rno=s;
		while(p[i].rno!=s)
		{
			i++;
		}
		p[n-1].rno=key;
		if((i<n-1) || (s==p[n-1].rno))
			cout<<s<<" found at position "<<i<<endl;
		else 
			cout<<s<<" not found in the list"<<endl;
	}
	
	void fibonacci(TrainProgram *p,const int n)
	{
		cout<<"----------- Fibonacci Search -----------"<<endl;
		int x;
		cout<<"Enter the roll number to be searched"<<endl;
		cin>>x;
    		int fb2 = 0;   
    		int fb1 = 1;   
    		int fibM = fb2 + fb1;  
    		while (fibM < n)
    		{
    	    		fb2 = fb1;
    	    		fb1 = fibM;
    	    		fibM  = fb2 + fb1;
    		}
    		int offset = -1;
    		while (fibM > 1)
    		{
    	    		int i = min(offset+fb2, n-1);
    	    		if (p[i].rno < x)
    	    		{
    	        		fibM  = fb1;
    	        		fb1 = fb2;
    	        		fb2 = fibM - fb1;
    	        		offset = i;
    	    		}
    	    		else if (p[i].rno > x)
    	    		{
    	    			fibM  = fb2;
    	        		fb1 = fb1 - fb2;
    	        		fb2 = fibM - fb1;
    	    		}
    	    		else
    	    		{
    	    			cout<<x<<" found at position "<<i<<endl;
				break;
    	    		}
    		}
    		if(fb1 && p[offset+1].rno==x)
    		{
    			cout<<x<<" found at position "<<offset+1<<endl;
    		}
    		cout<<x<<" not found in the list"<<endl;
	}
	
	void QuickSort(TrainProgram *s,int low,int high)
	{
		int pivot,i,j;
		if(low>high)
			return;
		else
		{
			pivot=low;
			i=low;
			j=high;
			while(i<j)
			{
				while(s[i].rno <= s[pivot].rno && i<=high)
					i++;
				while(s[j].rno > s[pivot].rno && j>=low)
					j-=1;
				if(i<j)
					swap(s[i].rno,s[j].rno);
			}
			swap(s[pivot].rno,s[j].rno);
			Quicksort(s,low,j-1);
			Quicksort(s,j+1,high);
		}
	}
};


int main()
{
	TrainProgram *p;
	int n;
	cout<<"Enter the total number of students who attended the training program"<<endl;
	cin>>n;
	while(!cin)
	{
		cin.clear();
		cin.ignore(5,'\n');
		cout<<"Enter an integer value"<<endl;
		cin>>n;
	}
	p=new TrainProgram[n];
	p->accept(p,n);
	p->display(p,n);
	char ch='y';
	int choice;
	while(ch=='y')
	{
		cout<<"Enter 1 to perform linear search"<<endl;
		cout<<"Enter 2 to perform binary search"<<endl;
		cout<<"Enter 3 to perform sentinel search"<<endl;
		cout<<"Enter 4 to perform fibonacci search"<<endl;
		cin>>choice;
		while(choice!=1 && choice!=2 && choice!=3 && choice!=4)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter a value from 1 to 4"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: p->linear(p,n);
					break;
			case 2: p->binary(p,n);
					break;
			case 3: p->sentinel(p,n);
					break;
			case 4: p->fibonacci(p,n);
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
