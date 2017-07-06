#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}
int ans[n];
for(int i=0;i<n;i++)
ans[i]=1;
for (int i=1;i<n;i++)
{
	for (int j=0;j<i;j++)
	{
		if (arr[j]<arr[i])
		ans[i]=max(ans[j]+1,ans[i]);
	}
}
int m1=INT_MIN;
for(int i=0;i<n;i++)
{
	m1=max(m1,ans[i]);
}
cout<<m1<<" ";
return 0;
}
