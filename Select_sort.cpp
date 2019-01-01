#include<iostream>
using namespace std;
//#include<string.h>

class sort;
class student
{
    int rno,marks;
    //string name;
  public:
    student()
    {
        rno=0;
        marks=0;
        //name="student";
    }
    void accept()
    {
        cout<<"Enter roll number"<<endl;
        cin>>rno;
        cout<<"Enter marks"<<endl;
        cin>>marks;
       // cout<<"Enter name"<<endl;
       // cin>>name;
    }
    friend class sort;
};

class sort
{
    student s[5];
  public:
    void getdata()
    {
        int i;
        for(i=0;i<5;i++)
        {
            s[i].accept();
            cout<<endl;
        }
    }
    void select_sort()
    {
        int i,j,max;
        int tmarks,trno;
        //string tname;
        for(i=0;i<5;i++)
        {
            max=i;
            for(j=i;j<5;j++)
            {
                if(s[j].marks >= s[max].marks)
                    max=j;
            }
            tmarks=s[max].marks;
            trno=s[max].rno;
            //strcpy(tname,s[max].name);
            s[max].marks=s[i].marks;
            s[max].rno=s[i].rno;
            //strcpy(s[max].name,s[i].name);
            s[i].marks=tmarks;
            s[i].rno=trno;
            //strcpy(s[i].name,tname);
        }
    }
    void display()
    {
        int i;
        for(i=0;i<5;i++)
        {
           // cout<<s[i].name<<endl;
            cout<<s[i].rno<<endl;
            cout<<s[i].marks<<endl<<endl;
        }
    }
};

int main()
{
    sort st;
    st.getdata();
    st.select_sort();
    st.display();
    return 0;
}
