#include<iostream>
using namespace std;

class Student
{
	int rno;
	int marks[3];
	float per;
	public:
	
	void accept(Student *s,int n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"Enter roll number"<<endl;
			cin>>s[i].rno;
			cout<<"Enter marks of 3 subjects"<<endl;
			for(int j=0;j<3;j++)
			{
				cin>>s[i].marks[j];
			}
		}
		for(int i=0;i<n;i++)
		{
			s[i].per=(s[i].marks[0]+s[i].marks[1]+s[i].marks[2])/3.0;
		}
	}
	
	void display(Student *s,int n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"Roll number\tRank\tPercentage"<<endl;
			cout<<s[i].rno<<"\t\t"<<i+1<<"\t"<<s[i].per<<endl;
		}
	}
	
	void QuickSort(Student *s,int low,int high)
	{
		float pivot;
		int i,j;
		if(low>=high)
			return;
		else
		{
			pivot=s[low].per;
			i=low+1;
			j=high;
			do
			{
				while(s[i].per>pivot && i<=high)
					i+=1;
				while(s[j].per<pivot && j>=low)
					j-=1;
				if(i<j)
				{
					swap(s[i].per,s[j].per);
					swap(s[i].rno,s[j].rno);
					i+=1;
					j-=1;
				}
			}
			while(i<j);
			swap(s[low].per,s[j].per);
			swap(s[low].rno,s[j].rno);
		}
		QuickSort(s,low,j-1);
		QuickSort(s,j+1,high);
	}
};

int main()
{
	Student *s;
	int n;
	cout<<"Enter number of students"<<endl;
	cin>>n;
	s=new Student[n];
	s->accept(s,n);
	s->QuickSort(s,0,n-1);
	s->display(s,n);
	return 0;	
}
