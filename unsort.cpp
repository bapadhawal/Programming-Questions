#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
int n;
int arr[100];
while(t--){
cin>>n;
for (int i=0;i<n;i++)
{
	cin>>arr[i];
}
int min1=INT_MAX,max1=INT_MIN;
int s=0;
for (s=0;s<n-1;s++)
{
	if (arr[s+1]<arr[s])
	break;
}
int e=n-1;
for (e=n-1;e>0;e--)
{
	if (arr[e]<arr[e-1])
	break;
}
for (int i=s;i<e;i++)
{
	max1=max(max1,arr[i]);
	min1=min(min1,arr[i]);
}
//cout<<s<<" "<<e<<"\n";
for (int i=0;i<s;i++)
{
	if (arr[i]>min1)
	{
		s=i;
		break;
	}
}
for (int i=e+1;i<n;i++)
{
	if (arr[i]<max1)
	{
		e=i;
		break;
	}
}
cout<<s<<" "<<e<<"\n";
}
return 0;
}
