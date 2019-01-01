#include<iostream>
using namespace std;

class student
{
	int size,marks[100];
  public:
	void accept()
	{
		cout<<"Enter the number of students"<<endl;
		cin>>size;
		cout<<"Enter the marks of the students.If student is absent, enter marks -1"<<endl;
		for(int i=0;i<size;i++)
		{
			cin>>marks[i];
		}
	}
	void average()
	{
		float avg=0,total=0;
		int abs=0;
		for(int i=0;i<size;i++)
		{
			if(marks[i]!=-1)
			{
				total+=marks[i];
			}
			else
				abs++;
		}
		avg=total/(size-abs);
		cout<<"Average of the class is "<<avg<<endl;
	}
	void highest()
	{
		int high;
		high=marks[0];
		for(int i=0;i<size;i++)
		{
			if(marks[i]>high)
				high=marks[i];
		}
		cout<<"The highest marks obtained are "<<high<<endl;
	}
	void lowest()
	{
		int low;
		low=100;
		for(int i=0;i<size;i++)
		{
			if(low>marks[i] && marks[i]!=-1)
				low=marks[i];
		}
		cout<<"The lowest marks obtained are "<<low<<endl;
	}
	void most()
	{
		int cnt,most[100],mostfreq,index,flag;
		for(int i=0;i<size;i++)
		{
			if(marks[i]!=0)
			{
				cnt=0;
				for(int j=0;j<size;j++)
				{
					if(marks[i]==marks[j])
					{
						cnt++;
					}
				}
				most[i]=cnt;
			}
		}
		for(int i=0;i<size;i++)
		{
			if(marks[i]!=0)
			{
				mostfreq=most[0];
				if(most[i]>mostfreq)
				{
					mostfreq=most[i];
					index=i;
					flag=1;
				}
				else if(most[i]==mostfreq)
					flag=0;
			}
		}
		if(flag==1)
		{
			cout<<"The most number of marks are "<<marks[index]<<" and have appeared "<<mostfreq<<" times"<<endl;
		}
		else
			cout<<"All the marks have been scored an equal number of times"<<endl;
	}
	void absent()
	{
		int flag;
		cout<<"Roll numbers of absent students are "<<endl;
		for(int i=0;i<size;i++)
		{
			if(marks[i]<0)
			{
				cout<<i+1<<endl;
				flag=1;
			}
			else
				flag=0;	
		}
		if(flag==0)
		{
			cout<<"All students were present"<<endl;
		}
	}
};

int main()
{
	student s;
	s.accept();
	s.average();
	s.highest();
	s.lowest();
	s.most();
	s.absent();
	return 0;
}
