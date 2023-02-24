#include<iostream>
using namespace std;
int main(){
    int arr[100][100];
    int i,j;
    int r,c;
    cin>>r;
    cin>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j];
            cout<<"\t";
        }
        cout<<"\n";
    }
    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==j || i+j==r-1)
            sum=sum+arr[i][j];
        }
    }
        cout<<sum<<endl;
}
