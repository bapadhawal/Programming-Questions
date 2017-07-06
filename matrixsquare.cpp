#include <bits/stdc++.h>
using namespace std;
int main(){
int m,n;
cin>>m>>n;
int arr[m][n];
for (int i=0;i<m;i++)
{
	for (int j=0;j<n;j++)
	{
		cin>>arr[i][j];
	}
}
int ans[m][n];
for (int i=0;i<m;i++)
ans[i][0]=arr[i][0];
for (int i=0;i<n;i++)
ans[0][i]=arr[0][i];
for (int i=1;i<m;i++)
{
	for (int j=1;j<n;j++)
	{
		if (arr[i][j]==1)
		ans[i][j]=1+min(ans[i-1][j-1],min(ans[i-1][j],ans[i][j-1]));
		else 
		ans[i][j]=0;
	}
}
int m1=INT_MIN;
for (int i=0;i<m;i++)
{
	for (int j=0;j<n;j++)
	{
		m1=max(m1,ans[i][j]);
	}
}
cout<<m1<<" ";
}
