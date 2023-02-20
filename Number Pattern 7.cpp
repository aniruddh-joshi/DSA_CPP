#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num=1;
        for(int j=0;j<n;num++,j++)
        {
            cout<<num+i-1;
            cout<<"\t";
        }
        cout<<"\n";
    }
}
/*1	2	3	
2	3	4	
3	4	5	*/
