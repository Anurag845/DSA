#include<iostream>
using namespace std;

void insort(int *p,const int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=p[i];
		j=i-1;
		while(j>=0 && p[j]<key)
		{
			p[j+1]=p[j];
			j-=1;
		}
		p[j+1]=key;
	}
}

void shellsort(int *p,const int n)
{
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i++)
		{
			int j,key=p[i];
			for(j=i;j>=gap && p[j-gap]>key;j-=gap)
			{
				p[j]=p[j-gap];
			}
			p[j]=key;
		}
	}
}

void bubble(int *p,const int n)
{
	for(int pass=0;pass<n;pass++)
	{
		for(int i=0;i<(n-pass);i++)
		{
			if(p[i]<p[i+1])
			{
				swap(p[i],p[i+1]);
			}
		}
	}
}

int main()
{
	int n,*p;
	cout<<"Size  ";
	cin>>n;
	p=new int[n];
	cout<<"Values"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	bubble(p,n);
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
	return 0;
}
