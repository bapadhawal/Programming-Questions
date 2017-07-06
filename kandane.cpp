#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
int neg=0;
int m1=INT_MIN;
for (int i=0;i<n;i++)
{
	cin>>arr[i];
	if (arr[i]<0)
	neg++;
	m1=max(m1,arr[i]);
	
}
int cur=0;
int max1=INT_MIN;
for (int i=0;i<n;i++){
	//cout<<arr[i];
	cur+=arr[i];
	if (cur<0)
	cur=0;
	else if (cur>max1)
	max1=cur;
}
if (neg==n)
cout<<m1<<" ";
else
cout<<max1<<" ";
return 0;
}
