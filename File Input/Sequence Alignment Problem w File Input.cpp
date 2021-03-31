#include<iostream>
#include<cstring>
#include<stack>
#include <bits/stdc++.h>
#define GAP 1
#define MIS 2
#define MAT 0
using namespace std;
char Y[100];
char X[100];
int arr[100][100];
stack<int> string1;
stack<int> string2;
void calculation(int x, int y)
{
    int TEMP1 = arr[x-1][y] + GAP;
    int TEMP2 = arr[x][y-1] + GAP;
    int TEMP3 = arr[x-1][y-1] + (X[x-1] == Y[y-1] ? MAT : MIS);
    arr[x][y] = min(TEMP1, min(TEMP2, TEMP3));
}
void backstrack(int x, int y)
{
    if(x==0 && y ==0)
    {
        //cout<<"RET"<<endl;
        return;
    }
    if(x==0 && y > 0)
    {
        string1.push(1001);
        string2.push(y);
        backstrack(x, y-1);
    }
    else if(x>0 && y == 0)
    {
        string1.push(x);
        string2.push(1001);
        backstrack(x, y-1);
    }
    else if(arr[x][y] == arr[x-1][y-1] + (X[x-1] == Y[y-1] ? MAT : MIS))
    {
        string1.push(x);
        string2.push(y);
        //cout<<"Cross"<<endl;
        backstrack(x-1, y-1);
    }
    else if(arr[x][y] == arr[x][y-1] + GAP)
    {
        string1.push(1001);
        string2.push(y);
        backstrack(x, y-1);
    }
    else if(arr[x][y] == arr[x-1][y] + GAP)
    {
        string1.push(x);
        string2.push(1001);
        backstrack(x-1, y);
    }
}
void INITIALIZE()
{
    for(int i=1; i<strlen(X) + 1; i++)
    {
        for(int j=1; j<strlen(Y) + 1; j++)
        {
            calculation(i,j);
        }
    }

}
void input_file()
{
    ifstream open;
    open.open("INPUTFILE.txt");
    //open.getline(X, 100);
    //open.getline(Y, 100);
    //getline(open,Y);
    open>>X>>Y;
}
int main()
{
    input_file();
    cout<<"String 1: "<<X<<endl;
    //cin>>X;
    cout<<"String 2: "<<Y<<endl;
    //cin>>Y;
    int T1 = 0, T2 = 0;
    while(1)
    {
        if(!(T1 > strlen(X) + 1))
        {
           arr[T1][0] = T1*GAP;
           T1++;
        }
        if(!(T2 >strlen(Y) + 1))
        {
            arr[0][T2] = T2*GAP;
            T2++;
        }
        if((T1 > strlen(X) + 1) && (T2 >strlen(Y) + 1))
        {
            break;
        }
    }
    INITIALIZE();
    /*for(int i=0; i<strlen(X) + 1 ; i++)
    {
        for(int j=0; j< strlen(Y) + 1 ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<"Minimum Penalty: "<<arr[strlen(X)][strlen(Y)]<<endl;
    cout<<"P_Gap: "<<GAP<<endl;
    cout<<"P_XY: "<<MIS<<endl;
    backstrack(strlen(X), strlen(Y));
    cout<<"String 1: ";
    while(!string1.empty())
    {
        if(string1.top() != 1001)
        {
            cout<<X[string1.top() - 1];
        }
        else
        {
            cout<<'_';
        }
        string1.pop();
    }
    cout<<endl;
    cout<<"String 2: ";
    while(!string2.empty())
    {
        if(string2.top() != 1001)
        {
            cout<<Y[string2.top() - 1];
        }
        else
        {
            cout<<'_';
        }
        string2.pop();
    }
}
