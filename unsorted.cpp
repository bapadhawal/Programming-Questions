#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for (int i=0;i<n;i++)
{
	cin>>arr[i];
}
int i=0;
int j=n-1;
while(i<n){
	if (arr[i]<=arr[i+1])
	i++;
	else 
	break;
}
while(j>=0)
{
	if (arr[j]>=arr[j-1])
	j--;
	else 
	break;
}
int max1=INT_MIN,min1=INT_MAX;
for (int k=i+1;k<=j;k++){
	max1=max(max1,arr[k]);
	min1=min(min1,arr[k]);
}
	for (int l=0;l<=i;l++)
	{
		if (arr[l]>min1)
		{
		i=l;
		break;
		}
		
	}
	for (int l=n-1;l>j;l--){
		if (arr[l]<max1)
		{
		j=l;
		break;
		}
	}
	cout<<i<<" "<<j<<" ";	
}
