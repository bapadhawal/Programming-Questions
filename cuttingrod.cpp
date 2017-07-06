#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n+1];
for (int i=0;i<n;i++)
{
	cin>>arr[i];
}
int ans[n][n+1];
for (int i=0;i<n;i++)
{
	for(int j=0;j<=n;j++)
	{
		if (j==0)
		ans[i][j]=0;
		else if (i==0)
		ans[i][j]=arr[i]*j;
		else if (j<i+1)
		ans[i][j]=ans[i-1][j];
		else 
		ans[i][j]= max(arr[i] + ans[i][j-i-1],ans[i-1][j]);// this is the step most important and need the most attention.
	}
}
for (int i=0;i<n;i++){
for (int j=0;j<=n;j++)
cout<<ans[i][j]<<" ";
cout<<"\n";}
cout<<ans[n-1][n];
return 0;
}
