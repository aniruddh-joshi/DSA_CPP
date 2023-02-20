#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char count='A';
    for(int i=0;i<n;i++)
    {
        for(int j=0;i>=j;j++)
        {
            cout<<count;
            count++;
           cout<<"\t";
        }
        cout<<"\n";
    }
}
/*A	
B	C	
D	E	F	*/
