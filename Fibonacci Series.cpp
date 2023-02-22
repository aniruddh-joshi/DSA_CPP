#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the range of series\n";
    cin>>n;
    int a,b;
    cout<<"Enter the a= ";
    cin>>a;
    cout<<"Enter the b= ";
    cin>>b;
    cout<<a<<" "<<b<<" ";
    for(int i=1;i<=n;i++)
    {
        int nextNumber=a+b;
        cout<<nextNumber<<" ";
        a=b;
        b=nextNumber;
    }
}
