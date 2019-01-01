#include<iostream>
using namespace std;

class Polynomial;
class term
{
	int coeff,exp;
	public:
	term()
	{
		coeff=0;
		exp=0;
	}
	friend class Polynomial;
	friend istream &operator >> (istream &in,Polynomial &p);
	friend ostream &operator << (ostream &out,Polynomial &p);
};

class Polynomial
{
	term t[10];
	int n;
	public:
	
	friend istream &operator >> (istream &in,Polynomial &p);
	friend ostream &operator << (ostream &out,Polynomial &p);
	
	void add(Polynomial &p1,Polynomial &p2)
	{
		int i=0,j=0,k=0;
		while(i<p1.n && j<p2.n)
		{
			if(p1.t[i].exp==p2.t[j].exp)
			{
				t[k].coeff=p1.t[i].coeff+p2.t[j].coeff;
				t[k].exp=p1.t[i].exp;
				i++;
				j++;
				k++;
			}
			else if(p1.t[i].exp>p2.t[j].exp)
			{
				t[k].coeff=p1.t[i].coeff;
				t[k].exp=p1.t[i].exp;
				i++;
				k++;
			}
			else if(p1.t[i].exp<p2.t[j].exp)
			{
				t[k].coeff=p2.t[j].coeff;
				t[k].exp=p2.t[j].exp;
				j++;
				k++;
			}
		}
		while(i==p1.n && j<p2.n)
		{
			t[k].coeff=p2.t[j].coeff;
			t[k].exp=p2.t[j].exp;
			j++;
			k++;
		}
		while(j==p2.n && i<p1.n)
		{
			t[k].coeff=p1.t[i].coeff;
			t[k].exp=p2.t[i].exp;
			i++;
			k++;
		}
		n=k;
	}
	
	void mul(Polynomial &p1,Polynomial &p2)
	{
		int i,j,k=0;
		for(i=0;i<p1.n;i++)
		{
			for(j=0;j<p2.n;j++)
			{
				t[k].coeff=p1.t[i].coeff*p2.t[j].coeff;
				t[k].exp=p1.t[i].exp+p2.t[j].exp;
				k++;
			}
		}
		n=k;
	}
};

istream &operator >> (istream &in,Polynomial &p)
{
	cout<<"Enter the number of terms"<<endl;
	in>>p.n;
	while(!cin)
	{
		in.clear();
		in.ignore(5,'\n');
		cout<<"Enter an integer value"<<endl;
		in>>p.n;
	}
	for(int i=0;i<p.n;i++)
	{
		cout<<"Coefficient of term "<<i+1<<":- ";
 		in>>p.t[i].coeff;
		cout<<"Exponent of term "<<i+1<<":- ";
		in>>p.t[i].exp;
	}
	return in;
}

ostream &operator << (ostream &out,Polynomial &p)
{
	out<<"polynomial is "<<endl;
	for(int i=0;i<p.n;i++)
	{
		out<<p.t[i].coeff<<"x^"<<p.t[i].exp;
		if(i==p.n-1)
			out<<" = 0"<<endl;
		else 
			out<<" + ";
	}
	return out;
}

int main()
{
	Polynomial p1,p2,p3,p4;
	char ch='y';
	int choice;
	while(ch=='y')
	{
		cout<<"Press 1 to enter 1st polynomial"<<endl;
		cout<<"Press 2 to enter 2nd polynomial"<<endl;
		cout<<"Press 3 to perform addition on 2 polynomials"<<endl;
		cout<<"Press 4 to perform multiplication on 2 polynomials"<<endl;
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter an integer value from 1 to 4"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: cin>>p1;
					cout<<"Entered "<<p1<<endl;
					break;
			case 2: cin>>p2;
					cout<<"Entered "<<p2<<endl;
					break;
			case 3: p3.add(p1,p2);
					cout<<"After addition "<<p3<<endl;
					break;
			case 4: p4.mul(p1,p2);
					cout<<"After multiplication "<<p4<<endl;
					break;
			default:cout<<"Incorrect choice"<<endl;
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}
