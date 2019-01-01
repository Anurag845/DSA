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
	
	char topele()
	{
		return stk[top];
	}
	
	void push(int ele)
	{
		if(top==49)
			cout<<"Stack overflow"<<endl;
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
		{
			cout<<"Stack underflow"<<endl;
			return 0;
		}
		else
		{
			p=stk[top];
			top=top-1;
			return p;
		}
	}
	
	int empty()
	{
	    if(top==-1)
	        return 1;
	    else
	        return 0;
	}
	
	int full()
	{
	    if(top==49)
	        return 1;
	    else 
	        return 0;
	}
	
	int precedence(char x)
	{
	    if(x=='(')
	        return 0;
	    else if(x=='+' || x=='-')
	        return 1;
	    else if(x=='*' || x=='/')
	    	return 2;
	}
	friend class expression;
};

class expression
{
	char inexp[50],poexp[50];
	stack s1,s2;
   public:
   	expression()
   	{
   		for(int i=0;i<50;i++)
   		{
   			inexp[i]='\0';
   			poexp[i]='\0';
   		}
   	}
   	
   	void accept()
   	{
   		cout<<"Enter the expression to be evaluated"<<endl;
   		cin>>inexp;
   	}
   	
   	void dispin()
   	{
   		cout<<"Entered expression is"<<endl;
   		cout<<inexp<<endl;
   	}
   	
   	void disppo()
   	{
   	    cout<<"After conversion, expression is"<<endl;
   	    cout<<poexp<<endl;
   	}
   	
   	void convert()
   	{
   		int i=0,k=0;
   		char ch,x;
   		s1.push('(');
   		while(inexp[i]!='\0')
   		{
   			i++;
   		}
   		inexp[i]=')';
   		for(i=0;inexp[i]!='\0';i++)
   		{
   			switch(inexp[i])
   			{
   				case '(': s1.push('(');
   						  break;
   				case ')': ch='\0';
   				          while(ch!='(')
   						  {
   						      ch=s1.pop();
   						      if(ch!='(')
   						      {
   						          poexp[k]=ch;
   						      	  k++;
   						      }
   						  }
   						  break;
   				case '*': while(s1.precedence(inexp[i])<=s1.precedence(s1.topele()) && !s1.empty())
   						  {
   						      x=s1.pop();
   							  poexp[k]=x;
   							  k++;
   						  }
   						  s1.push(inexp[i]);
   				          break;
   				case '/': while(s1.precedence(inexp[i])<=s1.precedence(s1.topele()) && !s1.empty())
   						  {
   						      x=s1.pop();
   							  poexp[k]=x;
   							  k++;
   						  }
   						  s1.push(inexp[i]);
   				          break;
   				case '+': while(s1.precedence(inexp[i])<=s1.precedence(s1.topele()) && !s1.empty())
   						  {
   						      x=s1.pop();
   							  poexp[k]=x;
   							  k++;
   						  }
   						  s1.push(inexp[i]);
   						  break;
   				case '-': while(s1.precedence(inexp[i])<=s1.precedence(s1.topele()) && !s1.empty())
   						  {
   						      x=s1.pop();
   							  poexp[k]=x;
   							  k++;
   						  }
   						  s1.push(inexp[i]);
   						  break;
   				default:  poexp[k]=inexp[i];
   				          k++;
   				          break;
   			}
   		}
   	}

   	void evaluate()
   	{
   		float ans;
   		int a,b,temp;
   		for(int i=0;poexp[i]!='\0';i++)
   		{
   			temp=(int)poexp[i]-48;
   			if(temp>=0 && temp<=9)
   			{
				s2.push(temp);   			
   			}
   			else if(poexp[i]=='*')
   			{
   				a=s2.pop();
   				b=s2.pop();
   				s2.push(b*a);
   			}
   			else if(poexp[i]=='/')
   			{
   				a=s2.pop();
   				b=s2.pop();
   				s2.push(b/a);
   			}
   			else if(poexp[i]=='+')
   			{
   				a=s2.pop();
   				b=s2.pop();
   				s2.push(b+a);
   			}
   			else if(poexp[i]=='-')
   			{
   				a=s2.pop();
   				b=s2.pop();
   				s2.push(b-a);
   			}
   		}
   		ans=s2.topele();
   		cout<<"Answer is "<<ans<<endl;
   	}
};

int main()
{   
    expression e;
    e.accept();
    e.dispin();
    e.convert();
    e.disppo();
    e.evaluate();
	return 0;
}	
