#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
long long int n;
long int arr[100005],b[100005],c[100005];
b[0]=0;
arr[0]=0;
while (t--){
	cin>>n;
	for (long long int i=1;i<=2*n;i++)
	{
		cin>>arr[i];
		b[i]=arr[i];
	}
	sort(b,b+ 2*n +1);
	for (long long int i=2;i<=2*n;i+=2){
	c[(i/2)]=max(arr[i],arr[i-1]);
	}
	sort(c,c+n+1);
	/*for (long long int i=1;i<=n;i++)
	cout<<c[i]<<" ";
	cout<<"\n";
	for (int i=1;i<=2*n;i++)
	cout<<b[i]<<" ";*/
	long long int temp;
	for (long long int i=2;i<2*n;i+=2){
		temp=b[i+1];
		b[i+1]=b[i];
		b[i]=temp;
	}
	long long int l=b[n+1];
	if (c[(n+1)/2]>=l)
	{
		cout<<c[(n+1)/2]<<"\n";
		for (long long int i=1;i<=2*n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";
	}
	else 
	{
		cout<<l<<"\n";
		for (long long int i=1;i<=2*n;i++)
		cout<<b[i]<<" ";
		cout<<"\n";
	}
}
return 0;
} 
