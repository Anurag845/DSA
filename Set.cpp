#include<iostream>
using namespace std;

class Student
{	
	int rno[50];
	string name[50];
	int n;
	public:
	
	void getall()
	{
		cout<<"Enter total number of students"<<endl;
		cin>>n;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter only integer value"<<endl;
			cin>>n;
		}
		for(int i=0;i<n;i++)
		{
			cout<<"Enter the name"<<endl;
			cin>>name[i];
			while(!cin)
			{
				cin.clear();
				cin.ignore(20,'\n');
				cout<<"Enter only string value"<<endl;
				cin>>name[i];
			}
			cout<<"Enter the roll number"<<endl;
			cin>>rno[i];
			while(!cin)
			{	
				cin.clear();
				cin.ignore(10,'\n');
				cout<<"Enter only integer value"<<endl;
				cin>>rno[i];
			}
		}	
	}
	
	void getbad(Student s)
	{
		int j,k;
		cout<<"Enter the number of students who play badminton"<<endl;
		cin>>n;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter only integer value"<<endl;
			cin>>n;
		}
		for(int i=0;i<n;i++)
		{
			cout<<"Enter the name"<<endl;
			cin>>name[i];
			while(!cin)
			{
				cin.clear();
				cin.ignore(20,'\n');
				cout<<"Enter only string value"<<endl;
				cin>>name[i];
			}
			for(j=0;j<s.n;j++)
			{
				if(name[i]==s.name[j])
					break;
			}
			if(j==s.n)
			{
				cin.clear();
				cin.ignore(20,'\n');
				cout<<name[i]<<" does not belong to the class"<<endl;
				cin>>name[i];
			}
			for(k=0;k<s.n;k++)
			{
				if(name[i]==s.name[k])
					break;
			}
			rno[i]=s.rno[k];
		}	
	}
	
	void getcric(Student s)
	{
		int j,k;
		cout<<"Enter the number of students who play cricket"<<endl;
		cin>>n;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter only integer value"<<endl;
			cin>>n;
		}
		for(int i=0;i<n;i++)
		{
			cout<<"Enter the name"<<endl;
			cin>>name[i];
			while(!cin)
			{
				cin.clear();
				cin.ignore(20,'\n');
				cout<<"Enter only string value"<<endl;
				cin>>name[i];
			}
			for(j=0;j<s.n;j++)
			{
				if(name[i]==s.name[j])
					break;
			}
			if(j==s.n)
			{
				cin.clear();
				cin.ignore(20,'\n');
				cout<<name[i]<<" does not belong to the class"<<endl;
				cin>>name[i];
			}
			for(k=0;k<s.n;k++)
			{
				if(name[i]==s.name[k])
					break;
			}
			rno[i]=s.rno[k];
		}	
	}
	
	void either(Student s1,Student s2)
	{
		int i,j,k=0;
		for(i=0;i<s1.n;i++)
		{
			rno[i]=s1.rno[i];
			name[i]=s1.name[i];
			k++;
		}
		for(j=0;j<s2.n;j++)
		{
			for(i=0;i<s1.n;i++)
			{
				if(s2.rno[j]==s1.rno[i])
					break;
			}
			if(i==s1.n)
			{
				rno[k]=s2.rno[j];
				name[k]=s2.name[j];
				k++;
			}
		}
		n=k;
		cout<<"Student playing either badminton or cricket are"<<endl;
	}
	
	void both(Student s1,Student s2)
	{
		int i,j,k=0;
		for(i=0;i<s1.n;i++)
		{
			for(j=0;j<s2.n;j++)
			{
				if(s1.rno[i]==s2.rno[j])
					break;
			}
			if(j<s2.n)
			{
				rno[k]=s1.rno[i];
				name[k]=s1.name[i];
				k++;
			}
		}
		n=k;
		cout<<"Students playing both badminton and cricket are"<<endl;
	}
	
	void onlybad(Student s1,Student s2)
	{
		int i,j,k=0;
		for(i=0;i<s1.n;i++)
		{
			for(j=0;j<s2.n;j++)
			{
				if(s1.rno[i]==s2.rno[j])
					break;
			}
			if(j==s2.n)
			{
				rno[k]=s1.rno[i];
				name[k]=s1.name[i];
				k++;
			}
		}
		n=k;
		cout<<"Student who play only badminton are"<<endl;
	}
	
	void onlycric(Student s1,Student s2)
	{
		int i,j,k=0;
		for(i=0;i<s2.n;i++)
		{
			for(j=0;j<s1.n;j++)
			{
				if(s1.rno[i]==s2.rno[j])
					break;
			}
			if(j==s1.n)
			{
				rno[k]=s2.rno[i];
				name[k]=s2.name[i];
				k++;
			}
		}
		n=k;
		cout<<"Students who play only cricket are"<<endl;
	}
	
	void neither(Student s1,Student s2)
	{
		int i,j,k=0;
		for(i=0;i<s1.n;i++)
		{
			for(j=0;j<s2.n;j++)
			{
				if(s1.rno[i]==s2.rno[j])
					break;
			}
			if(j==s2.n)
			{
				rno[k]=s1.rno[i];
				name[k]=s1.name[i];
				k++;
			}
		}
		n=k;
		cout<<"Students who play neither badminton nor cricket are"<<endl;
	}
	
	void display()
	{
		for(int i=0;i<n;i++)
		{
			cout<<"Name is "<<name[i]<<endl;
			cout<<"Roll number is "<<rno[i]<<endl;
		}
	}
};

int main()
{
	Student s,s1,s2,s3,s4,s5,s6,s7;
	char ch='y';
	int choice;
	s.getall();
	s1.getbad(s);
	s2.getcric(s);
	while(ch=='y' || ch=='Y')
	{
		cout<<"Press 1 to display details of students who play either badminton or cricket"<<endl;
		cout<<"Press 2 to display details of students who play both badminton and cricket"<<endl;
		cout<<"Press 3 to display details of students who play only badminton"<<endl;
		cout<<"Press 4 to display details of students who play only cricket"<<endl;
		cout<<"Press 5 to display details of students who play neither badminton nor cricket"<<endl; 
		cin>>choice;
		while(!cin)
		{
			cin.clear();
			cin.ignore(10,'\n');
			cout<<"Enter only integer value"<<endl;
			cin>>choice;
		}
		switch(choice)
		{
			case 1: s3.either(s1,s2);
					s3.display();
					break;
			case 2: s4.both(s1,s2);
					s4.display();
					break;
			case 3: s5.onlybad(s1,s2);
					s5.display();
					break;
			case 4: s6.onlycric(s1,s2);
					s6.display();
					break;
			case 5: s7.neither(s,s3);
					s7.display();
					break;
			default:cout<<"Wrong choice.Please try again"<<endl;
					break;
		}
		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
		while(!cin)
		{
			cin.clear();
			cin.ignore(5,'\n');
			cout<<"Enter only character value"<<endl;
			cin>>ch;
		}
	}
	return 0; 
}
