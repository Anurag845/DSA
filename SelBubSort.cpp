#include <iostream>
using namespace std;

class Sort
{
	int rno,marks[3];
	float per;
public:
	void accept()
	{
		cout<<"Enter the roll number"<<endl;
		cin>>rno;
		for(int i=0;i<3;i++)
		{
			cout<<"Enter the marks of subject "<<i+1<<endl;
			cin>>marks[i];
		}
	}

	void percentage()
	{
		per=(marks[0]+marks[1]+marks[2])/3;
	}

	void sSort(int n,Sort *p)
	{
		int max,temp2;
		float temp1;
		Sort *tmp;
		tmp=p;
		for(int i=0;i<n;i++)
		{
			max=i;
			for(int j=i;j<n;j++)
			{
				if(p[j].per>p[max].per)
					max=j;
			}
			temp1=p[i].per;
			temp2=p[i].rno;
			p[i].per=p[max].per;
			p[i].rno=p[max].rno;
			p[max].per=temp1;
			p[max].rno=temp2;
		}
		cout<<"High scores are"<<endl;
		cout<<"Rank"<<"  Roll Number"<<"  Percentage"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<"     "<<tmp[i].rno<<"            "<<tmp[i].per<<endl;
		}
	}

	void bSort(int n,Sort *p)
	{
		float temp1;
		int temp2;
		Sort *tmp;
		tmp=p;
		for(int pass=0;pass<n;pass++)
		{
			for(int i=0;i<(n-pass);i++)
			{
				if(p[i].per<p[i+1].per)
				{
					temp1=p[i].per;
					temp2=p[i].rno;
					p[i].per=p[i+1].per;
					p[i].rno=p[i+1].rno;
					p[i+1].per=temp1;
					p[i+1].rno=temp2;
				}
			}
		}
		cout<<"High scores are"<<endl;
		cout<<"Rank"<<"  Roll Number"<<"  Percentage"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<"     "<<tmp[i].rno<<"            "<<tmp[i].per<<endl;
		}
	}
};

int main()
{
	int size;
	cout<<"Enter the number of students"<<endl;
	cin>>size;
	Sort *p=new Sort[size];
	Sort *temp;
	temp=p;
	for(int i=0;i<size;i++)
	{
		p[i].accept();
		p[i].percentage();
	}
	temp->sSort(size,temp);
	temp->bSort(size,temp);
	return 0;
}
