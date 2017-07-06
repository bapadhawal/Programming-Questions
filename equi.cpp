#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[100005];
int sum=0;
for (int i=0;i<n;i++)
{
cin>>arr[i];
sum+=arr[i];
}
int le=0;
for (int i=0;i<n;i++)
{
	sum-=arr[i];
	if (le==sum)
	cout<<arr[i];
	le+=arr[i];
}
return 0;
}
