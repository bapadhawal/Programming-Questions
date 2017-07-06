#include <bits/stdc++.h>
using namespace std ;
int main(){
int m,n;
cin>>m>>n;
int arr[m][n];
for (int i=0;i<m;i++){
	for (int j=0;j<n;j++)
	{
		cin>>arr[i][j];
	}
}
int ans[m][n];
ans[0][0]=arr[0][0];
for (int i=1;i<m;i++)
ans[0][i]=arr[0][i] + arr[0][i-1];
for (int i=1;i<n;i++)
ans[i][0]=arr[i][0] + arr[i-1][0];

for (int i=1;i<m;i++)
{
	for (int j=1;j<n;j++){
		
		ans[i][j]=arr[i][j] + min(ans[i-1][j-1],min(ans[i][j-1],ans[i-1][j]));
	}
}
cout<<ans[m-1][n-1]<<" ";
return 0;
}
