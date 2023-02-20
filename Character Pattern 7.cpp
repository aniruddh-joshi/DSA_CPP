#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch='A'+n-i;
        for(int j=1;i>=j;ch++,j++)
        {
            cout<<ch<<"\t";
        }
        cout<<"\n";
    }
}
/*D	
C	D	
B	C	D	
A	B	C	D*/
