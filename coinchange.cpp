#include <bits/stdc++.h>
using namespace std;
int ans[100];
int main(){
int n;
cin>>n;
int arr[n];
for (int i=0;i<n;i++)
cin>>arr[i];
int k;
cin>>k;
ans[0]=1;// this is the initiating part dont miss it okk
for(int i=0;i<n;i++)
{
	for (int j=arr[i];j<=k;j++)
	{
		ans[j]+=ans[j-arr[i]];
		cout<<ans[j]<<" ";
	}
}
cout<<ans[k]<<" ";
}
