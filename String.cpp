#include<iostream>
using namespace std;

class String
{
	char str[25];
	public:
	
	void accept()
	{
		cout<<"Enter the string"<<endl;
		cin>>str;
	}
	
	void display()
	{
		cout<<"String is "<<str<<endl;
	}
	
	int length()
	{
		int len=0;
		while(str[len]!='\0')
		{
			len++;
		}
		return len;
	}
	
	void copy(String s)
	{
		for(int i=0;i<s.length();i++)
		{
			str[i]=s.str[i];
		}
	}
	
	int frequency()
	{
		char ch;
		int f=0;
		cout<<"Enter the character whose frequency is to be determined"<<endl;
		cin>>ch;
		for(int i=0;i<this->length();i++)
		{
			if(ch==str[i])
				f++;
		}
		return f;
	}
	
	void concatenate(String s1,String s2)
	{
		int i,j;
		for(i=0;i<s1.length();i++)
		{
			str[i]=s1.str[i];
		}
		for(j=i;j<i+s2.length();j++)
		{
			str[j]=s2.str[j-i];
		}
		str[j]='\0';
	}
	
	void equal(String s)
	{
		if(this->length()!=s.length())
		{
			cout<<"Strings are not equal"<<endl;
		}
		else
		{
			int i;
			for(i=0;i<s.length();i++)
			{
				if(str[i]!=s.str[i])
					break;
			}
			if(i==s.length())
				cout<<"Strings are equal"<<endl;
			else
				cout<<"Strings are not equal"<<endl;
		}
	}
	
	void reverse(String s)
	{
		int j=0;
		for(int i=s.length()-1;i>=0;i--,j++)
		{
			str[j]=s.str[i];
		}
		str[j]='\0';
	}
	
	void checksub()
	{
		String s;
		int pos,i,j=0,k=0;
		bool flag=false;
		cout<<"Enter the substring"<<endl;
		cin>>s.str;
		while(1)
		{
			while(j<this->length())
			{
				if(s.str[0]==str[j])
				{
					pos=j;
					break;
				}
				j++;
			}	
			if(j==this->length())
			{
				cout<<s.str<<" not present in "<<str<<endl;
				break;
			}	
			else
			{
				for(i=0;i<s.length();i++)
				{
					if(str[pos+i]==s.str[i])
					{
						flag=true;
					}
					else
						flag=false;	
				}
				if(flag==true)
				{
					cout<<s.str<<" is present in "<<str<<endl;
					break;
				}
				else
				{
					if(j<this->length())
						j++;
					else
						break;
				}
			}
		}
	}
	
	void deletes(int start,int len,String s)
	{
		if(start>=s.length())
		{
			cout<<"Start is greater than length of string"<<endl;
		}
		else if(start+len>=s.length())
		{
			cout<<"Length of string insufficient"<<endl;
		}
		else
		{
			int i,j;
			for(i=0;i!=start;i++)
			{
				str[i]=s.str[i];
			}
			for(j=i;j<s.length()-len;j++)
			{
				str[j]=s.str[j+len];
			}
			str[j]='\0';
		}
	}
	
	void chardelete()
	{
		char c;
		int cnt=0,len;
		len=this->length();
		cout<<"Enter the character to be deleted"<<endl;
		cin>>c;
		for(int i=0;i<this->length();i++)
		{
			if(c==str[i])
				cnt++;
		}
		if(cnt==0)
		{
			cout<<"Entered character is not in the string"<<endl;
		}
		else
		{
			int i,j=0;
			while(this->length()!=len-cnt)
			{
				if(c==str[j])
				{
					for(i=j;i<this->length();i++)
					{
						str[i]=str[i+1];
					}
					str[i]='\0';
					j-=1;
				}
				j++;
			}
		}
	}
	
	void replace()
	{
		String s,rs;
		int pos,i,j=0,k=0,check=0,len1,len2;
		bool flag=false;
		cout<<"Enter the substring"<<endl;
		cin>>s.str;
		len1=s.length();
		while(1)
		{
			while(j<this->length())
			{
				if(s.str[0]==str[j])
				{
					pos=j;
					break;
				}
				j++;
			}	
			if(j==this->length())
			{
				cout<<s.str<<" not present in "<<str<<endl;
				check=0;
				break;
			}	
			else
			{
				for(i=0;i<s.length();i++)
				{
					if(str[pos+i]==s.str[i])
					{
						flag=true;
					}
					else
						flag=false;	
				}
				if(flag==true)
				{
					cout<<s.str<<" is present in "<<str<<endl;
					check=1;
					break;
				}
				else
				{
					if(j<this->length())
						j++;
					else
						break;
				}
			}
		}
		if(check==1)
		{
			for(i=pos;i<this->length()-len1;i++)
			{
				str[i]=str[i+len1];
			}
			str[i]='\0';
			cout<<str<<endl;
			cout<<"Enter replacement string"<<endl;
			cin>>rs.str;
			len2=rs.length();
			for(i=0;i<len2;i++)
			{
				for(j=this->length()+1;j>=pos;j-=1)
				{
					str[j+1]=str[j];
				}
				str[pos]=rs.str[i];
				pos+=1;
			}
		}
	}
	
};

int main()
{
	String s1,s2,s3,s4,s5;
	s1.accept();
	s1.display();
	//s2.accept();
	//s2.display();
	//cout<<"Length is "<<s1.length()<<endl;
	//cout<<"Frequency is "<<s1.frequency()<<endl;
	//s3.concatenate(s1,s2);
	//s3.display();
	//s1.equal(s2);
	//s4.reverse(s1);
	//s4.display();
	//s1.checksub();
	//s5.deletes(2,8,s1);
	//s1.chardelete();
	//s1.display();
	s1.replace();
	s1.display();
	return 0;
}
