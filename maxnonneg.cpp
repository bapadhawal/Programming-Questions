#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for (int i=0;i<n;i++)
cin>>arr[i];
long long int curr=0;
long long int max1=INT_MIN;
int start=0,end=0;
int diff=INT_MIN;
int f1=-1,f2=-1;
for (int i=0;i<n;i++){
	if (arr[i]>=0){
	curr+=(long long )arr[i];	
	}
	else 
	{
		end=i-1;
		if (curr>=max1)
		{
		if ((end - start +1)>diff && curr==max1)
		{
		diff=end-start+1;
		}
		max1=curr;
		f1=start;
		f2=end;
		}
		curr=0;
		start=i+1;
	}
	cout<<curr<<" ";
	cout<<start<<" "<<end<<" ";	
}
cout <<max1<<" ";
cout<<f1<<" "<<f2<<" ";
return 0;
}
