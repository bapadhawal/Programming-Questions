#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m;
int arr[100][100];
int  temp;
cin>>n;
for (int i=0;i<n;i++)
{
	for (int j=0;j<n;j++)
	cin>>arr[i][j];
}
for (int i=0;i<n;i++)
{
	for (int j=0;j<n;j++)
	cout<<arr[i][j]<<" ";
	cout<<"\n";
}
for (int i=0;i<n/2;i++){
	for (int j=i;j<n-i-1;j++)
	{
		 temp=arr[i][j];
		arr[i][j]=arr[j][n-i-1];
		arr[j][n-i-1]=arr[n-i-1][n-j-1];
		arr[n-i-1][n-j-1]=arr[n-j-1][i];
		arr[n-j-1][i]=temp;
	}
}
for (int i=0;i<n;i++)
{
	for (int j=0;j<n;j++)
	cout<<arr[i][j]<<" ";
	cout<<"\n";
}
return 0;
}
