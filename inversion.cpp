#include <bits/stdc++.h>
using namespace std;
int arr[1005],cnt=0;
void merge(int low,int high){
int mid=(low+high)/2 +1;
int i=low;
int j=mid;
int k=low;
int temp[1005];
while(i<(mid-1) && j<(high)){
	if (arr[i]<arr[j]){
	temp[k]=arr[i];
	i++;
	k++;
	}
	else
	{
	cnt+=mid-i;
	temp[k]=arr[j];
	k++;
	j++;
	}
}
while(i<mid){
temp[k]=arr[i];
k++;
i++;
}
while(j<high){
temp[k]=arr[j];
k++;
j++;
}
for(int k1=low;k1<high;k1++)
arr[k1]=temp[k1];
}
void mergesort(int low,int high){
	if (low<high){
	int mid=(low+high)/2;
	mergesort(low,mid);
	mergesort(mid+1,high);
	merge(low,high);
	}
}
int main(){
int t;
cin>>t;
int n;
while(t--){
	cin>>n;
	for (int i=0;i<n;i++)
	cin>>arr[i];
	mergesort(0,n-1);
	cout<<cnt<<"\n";
}
}
