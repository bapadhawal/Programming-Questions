#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[1000];
for (int i=0;i<n;i++)
cin>>arr[i];
int i=0;
int j=n-1;
while(i<j){
	if (arr[i]==0)
	i++;
	else if(arr[j]==1)
	j--;
	else 
	{
	int temp=arr[j];
	arr[j]=arr[i];
	arr[i]=temp;
	i++;
	j--;	
	}
}
for (int i=0;i<n;i++)
{
cout<<arr[i]<<"";
}
return 0;
}
