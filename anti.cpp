#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n][n];
for (int i=0;i<n;i++)
{
	for(int j=0;j<n;j++){
	cin>>arr[i][j];
	}
}
int i=0;
int j=0;
while ( i<n ||  j<n){
	if(j<=n-1){
		int k=j;
		while(k>=0){
			cout<<arr[j-k][k]<<" ";
			k--;
		}
		j++;
		cout<<"\n";
	}
	else if (i<=n-1)                       
	{
		i++;
		int k=i;
		int l=n-1;
		while(k<=n-1){
			cout<<arr[k][l]<<" ";
			k++;
			l--;
		}
		
		cout<<"\n"; 
	}
}
}
