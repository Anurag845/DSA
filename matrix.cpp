#include<iostream>
using namespace std;

class matrix
{
    int mat[100][100],row,col;
  public:
    void accept()
    {
        cout<<"Enter the number of rows"<<endl;
        cin>>row;
        cout<<"Enter the number of columns"<<endl;
        cin>>col;
        cout<<"Enter the elements"<<endl;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>mat[i][j];
            }
        }
    }
    
    void display()
    {
        cout<<"Matrix is"<<endl;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void uppertri()
    {
        int cnt;
        if(row==col)
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(mat[i][j]==0)
                        cnt++;                   
                }
            }
            if(cnt==(row*row-row)/2)
                cout<<"Matrix is upper-triangular"<<endl;
            else
                cout<<"Matrix is not upper-triangular"<<endl;
        }
        else
            cout<<"Matrix is not square"<<endl;
    }
    
    void sumdiag()
    {
        int sumd=0;
        if(row==col)
        {
            for(int i=0;i<row;i++)
            {        
                sumd+=mat[i][i];         
            }
            cout<<"Sum of diagonal elements is "<<sumd<<endl;
        }
        else
            cout<<"Matrix is not square"<<endl;
    }
    
    void transpose()
    {
        int temp;
        if(row==col)
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<i;j++)
                {
                    temp=mat[i][j];
                    mat[i][j]=mat[j][i];
                    mat[j][i]=temp;
                }
            }
        }
        else
            cout<<"Matrix is not square"<<endl;
    }
    
    void sum(matrix m1,matrix m2)
    {
        if(m1.row==m2.row && m1.col==m2.col)
        {
            row=m1.row;
            col=m1.col;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
                }
            }
        }
        else
            cout<<"Orders of the matrices do not match"<<endl;
    }
    
    void diff(matrix m1,matrix m2)
    {
        if(m1.row==m2.row && m1.col==m2.col)
        {
            row=m1.row;
            col=m1.col;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
                }
            }
        }
        else
            cout<<"Orders of the matrices do not match"<<endl;
    }
    
    void product(matrix m1,matrix m2)
    {
        if(m1.col==m2.row)
        {
            for(int i=0;i<m1.row;i++)
            {
                for(int j=0;j<m2.col;j++)
                {
                    for(int k=0;k<m1.col;k++)
                    {
                        mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
                    }
                }
            }
        }
    }
    
};

int main()
{
    matrix m1,m2,m3;
    char ch='y';
    int choice1,choice2;
    while(ch=='y' || ch=='Y')
    {
        cout<<"Press 1 to enter matrix"<<endl;
        cout<<"Press 2 to display matrix"<<endl;
        cout<<"Press 3 to check whether matrix is upper-triangular"<<endl;
        cout<<"Press 4 to calculate sum of diagonal elements of matrix"<<endl;
        cout<<"Press 5 to calculate transpose matrix"<<endl;
        cout<<"Press 6 to calculate sum of two matrices"<<endl;
        cout<<"Press 7 to calculate difference of two matrices"<<endl;
        cout<<"Press 8 to calculate product of two matrices"<<endl;
        
        cin>>choice1;
        
        switch(choice1)
        {
            case 1: cout<<"Press 1 to enter 1st matrix"<<endl;
                    cout<<"Press 2 to enter 2nd matrix"<<endl;
                    cin>>choice2;
                    
                    switch(choice2)
                    {
                        case 1: m1.accept();
                                break;
                        case 2: m2.accept();
                                break;
                    }
                    break;
            case 2: cout<<"Press 1 to display 1st matrix"<<endl;
                    cout<<"Press 2 to display 2nd matrix"<<endl;
                    cout<<"Press 3 to display 3rd matrix"<<endl;
                    cin>>choice2;
                    
                    switch(choice2)
                    {
                        case 1: m1.display();
                                break;
                        case 2: m2.display();
                                break;
                        case 3: m3.display();
                                break;
                    }
                    break;
            case 3: cout<<"Press 1 to check for 1st matrix"<<endl;
                    cout<<"Press 2 to check for 2nd matrix"<<endl;
                    cin>>choice2;
                    
                    switch(choice2)
                    {
                        case 1: m1.uppertri();
                                break;
                        case 2: m2.uppertri();
                                break;
                    }
                    break;
            case 4: cout<<"Press 1 to calculate for 1st matrix"<<endl;
                    cout<<"Press 2 to calculate for 2nd matrix"<<endl;
                    cin>>choice2;
                    
                    switch(choice2)
                    {
                        case 1: m1.sumdiag();
                                break;
                        case 2: m2.sumdiag();
                                break;
                    }
                    break;
            case 5: cout<<"Press 1 to calculate for 1st matrix"<<endl;
                    cout<<"Press 2 to calculate 2nd matrix"<<endl;
                    cin>>choice2;
                    
                    switch(choice2)
                    {
                        case 1: m1.transpose();
                                break;
                        case 2: m2.transpose();
                                break;
                    }
                    break;   
            case 6: m3.sum(m1,m2);
                    break;
            case 7: m3.diff(m1,m2);
                    break; 
            case 8: m3.product(m1,m2);
                    break;     
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>ch;
    }
    return 0;
}
