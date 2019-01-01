#include<iostream>
using namespace std;

class student
{
	int rno;
	public:
	void accept(student *s,const int n)
	{
		cout<<"Enter roll nos"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>s[i].rno;
		}
	}
	
	void display(student *s,const int n)
	{
		Quicksort(s,0,n-1);
		cout<<"Entered roll numbers are"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<s[i].rno<<" ";
		}
		cout<<endl;
	}
	
	void fibonacci(student *s,const int n)
	{
		cout<<endl<<"-----------------Fibonacci---------------------------"<<endl;
		int x;
		cout<<"Enter element to be searched"<<endl;
		cin>>x;
		int fb2=0;
		int fb1=1;
		int fb=fb2+fb1;
		while(fb<n)
		{
			fb2=fb1;
			fb1=fb;
			fb=fb2+fb1;
		}
		int offset=-1;
		while(fb>1)
		{
			int i=min((offset+fb2),n-1);
			if(s[i].rno<x)
			{
				fb=fb1;
				fb1=fb2;
				fb2=fb-fb1;
				offset=i;
			}
			else if(s[i].rno>x)
			{
				fb=fb2;
				fb1=fb1-fb2;
				fb2=fb-fb1;
			}
			else
			{
				cout<<"Found at position "<<i<<endl;
				return;
			}
		}
		if(fb1 && s[offset+1].rno==x)
		{
			cout<<"Found at position "<<offset+1<<endl;
			return;
		}
		else
		{
			cout<<"Not found"<<endl;
			return;
		}
	}
	
	void linear(student *s,const int n)
	{
		int i,x;
		cout<<"Enter element to be searched"<<endl;
		cin>>x;
		for(i=0;i<n;i++)
		{
			if(s[i].rno==x)
				break;
		}
		if(i<n)
			cout<<"Found at position "<<i<<endl;
		else
			cout<<"Not found"<<endl;
	}
	
	void sentinel(student *s,const int n)
	{
		int sent,x,i=0;
		sent=s[n-1].rno;
		cout<<"Enter element to be searched"<<endl;
		cin>>x;
		s[n-1].rno=x;
		while(s[i].rno!=s[n-1].rno)
		{
			i++;
		}
		s[n-1].rno=sent;
		if(i<n-1 || x==s[n-1].rno)
			cout<<"Found at position "<<i<<endl;
		else
			cout<<"Not found"<<endl;
	}
		
	void binary(student *s,const int n)
	{
		int l=0,r=n-1,x;
		cout<<"Enter element to be searched"<<endl;
		cin>>x;
		while(l<=r)
		{
			int mid=l+(r-l)/2;
			if(x==s[mid].rno)
			{
				cout<<"Found at position "<<mid<<endl;
				return;
			}
			if(x>s[mid].rno)
			{
				l=mid+1;
			}
			else if(x<s[mid].rno)
			{
				r=mid-1;
			}
		}
		cout<<"Not found"<<endl;
	}
	
	void Quicksort(student *s,int low,int high)
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
	
	
	
	
	
	/*{
		int i,j,pivot;
		if(low>=high)
			return;
		else
		{
			i=low+1;
			j=high;
			pivot=s[low].rno;
			do
			{
				while(s[i].rno<pivot && i<=high)
					i++;
				while(s[j].rno>pivot && j>=low)
					j-=1;
				if(i<j)
				{
					swap(s[i].rno,s[j].rno);
					i++;
					j-=1;
				}
			}while(i<j);
			swap(s[low].rno,s[j].rno);
		}
		Quicksort(s,low,j-1);
		Quicksort(s,j+1,high);
	}*/
	
};

int main()
{
	student *s;
	int n;
	cout<<"Enter number of students"<<endl;
	cin>>n;
	s=new student[n];
	s->accept(s,n);
	s->display(s,n);
	s->fibonacci(s,n);
	s->binary(s,n);
	s->sentinel(s,n);
	return 0;
}
