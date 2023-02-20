#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i>=j;j++)
        {
           char ch='A'+i;
           cout<<ch<<"\t";
        }
        cout<<"\n";
    }
}
/*A	
B	B	
C	C	C	
D	D	D	D*/
