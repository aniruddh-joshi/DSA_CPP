#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i>=j;j++)
        {
            char ch='A'+i+j-1-1;
            cout<<ch<<"\t";
        }
        cout<<"\n";
    }
}
/*A	
B	C	
C	D	E	
D	E	F	G*/
