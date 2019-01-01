#include<iostream>
using namespace std;

class Student
{
	int marks[3],rno;
	float per;
  public:   
	void accept()
	{
		cout<<"Enter roll number"<<endl;
		cin>>rno;
		for(int i=0;i<3;i++)
		{
			cout<<"Enter marks of subject "<<i+1<<endl;
			cin>>marks[i];
		}
	}
	
	void percentage()
	{
		per=(marks[0]+marks[1]+marks[2])/3.0;
	}
	
	void insort(Student *s,int n)
	{
		float key;
		int temp;
		for(int i=1;i<n;i++)
		{
			key=s[i].per;
			temp=s[i].rno;
			int j=i-1;
			while(j>=0 && key>s[j].per)
			{
				s[j+1].per=s[j].per;
				s[j+1].rno=s[j].rno;
				j=j-1;
			}
			s[j+1].per=key;
			s[j+1].rno=temp;
		}
	}
	
	void shellsort(Student *s,int n)
	{
		for(int gap=n/2;gap>0;gap/=2)
		{
			for(int i=gap;i<n;i++)
			{
				float key=s[i].per;
				int temp=s[i].rno;
				int j;
				for(j=i;j>=gap && s[j-gap].per<key;j-=gap)
				{
					s[j].per=s[j-gap].per;
					s[j].rno=s[j-gap].rno;
				}
				s[j].per=key;
				s[j].rno=temp;
			}
		}
	}
	
	void display(Student *s,int n)
	{
		cout<<"Roll Number"<<"    Rank  "<<"   Percentage"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<s[i].rno<<" \t        "<<i+1<<"  \t "<<s[i].per<<endl;
		}
		cout<<endl;
	}
};

int main()
{
	int n;
	cout<<"Enter the number of students"<<endl;
	cin>>n;
	Student *s=new Student[n];
	Student *temp=s;
	for(int i=0;i<n;i++)
	{
		s[i].accept();
		s[i].percentage();
	}
	temp->insort(temp,n);
	temp->display(temp,n);
	temp->shellsort(temp,n);
	temp->display(temp,n);
	return 0;
}
