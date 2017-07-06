#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
int n;
int arr[100005],b[100005];
b[0]=0;
arr[0]=0;
while (t--){
	cin>>n;
	for (int i=1;i<=2*n;i++)
	{
	cin>>arr[i];
	}
	sort(arr,arr+2*n+1);
	for(int i=1;i<=n;i++)
	{
	b[i]=max(arr[i],arr[n+i]);
	}
	sort(b,b+n+1);
	cout<<b[(n+1)/2]<<"\n";
	for (int i=1;i<=n;i++){
	cout<<arr[i]<<" "<<arr[n+i]<<" ";
	}
	cout<<"\n";
	
}
return 0;
}
