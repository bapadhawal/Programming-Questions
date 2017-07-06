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
sort(arr,arr+n);
int cnt=0;
for (int i=0;i<n;i++){
	if (arr[i]<=n)
	{
		if (arr[i]==(n-i-1))
		cout<<arr[i]<<" ";
	}
	else
	break;	
}
}
