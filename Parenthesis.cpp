#include<iostream>
using namespace std;
class expression;
class stack
{
	char stk[50];
	int top;
   public:
   	stack()
   	{
   		top=-1;
   		for(int i=0;i<50;i++)
   		{
   			stk[i]='\0';
   		}
   	}
   	
   	void push(char ele)
   	{
   		if(top==49)
   			cout<<"Stack Overflow"<<endl;
   		else
   		{
   			top++;
   			stk[top]=ele;
   		}
   	}
   	
   	char pop()
   	{
   		char p;
   		if(top==-1)
   			cout<<"Stack Underflow"<<endl;
   		else
   		{
   			p=stk[top];
   			top=top-1;
   			return p;	
   		}
   	}
   	friend class expression;
};

class expression
{
	char exp[50];
	stack s;
   public:
   
   	expression()
   	{
   		for(int i=0;i<50;i++)
   		{
   			exp[i]='\0';
   		}
   	}
   	
   	void accept()
   	{
  		cout<<"Enter the expression"<<endl;
  		cin>>exp; 		
   	}
   	
   	void display()
   	{
   		cout<<"Entered expression is"<<endl;
   		cout<<exp<<endl;
   	}
   	
   	void parenthesis()
   	{
   		int i=0,flag;
   		char p;
   		while(exp[i]!='\0')
   		{
   			if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
   			{
   				s.push(exp[i]);
   			}
   			else if(exp[i]==')')
   			{
   				p=s.pop();
   				if(p!='(')
   				{
   					flag=1;
   					break;
   				}
   			}
   			else if(exp[i]=='}')
   			{
   				p=s.pop();
   				if(p!='{')
   				{
   					flag=1;
   					break;
   				}
   			}
   			else if(exp[i]==']')
   			{
   				p=s.pop();
   				if(p!='[')
   				{
   					flag=1;
   					break;
   				}
   			}
   			i++;
   		}
   		if(flag==1 || s.top!=-1)
   			cout<<"Incorrect syntax"<<endl;
   		else
   			cout<<"Syntax is correct"<<endl;
   	}
   		
};

int main()
{
	expression e;
	e.accept();
	e.display();
	e.parenthesis();
	return 0;
}
