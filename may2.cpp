#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
int n;
int k;
while(t--){
	cin>>n;
	int arr[n+1];
	
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int max1=INT_MIN;	
	for (int i=0;i<n;i++)
	{
		max1=max(max1,arr[i]);	
	}
	cout<<n-max1<<"\n";
}
return 0;
}
