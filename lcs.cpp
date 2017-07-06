#include <bits/stdc++.h>
using namespace std;
int main(){
string a,b;
cin>>a>>b;
int m=a.size();
int n=b.size();
int arr[m+1][n+1];
for (int i=0;i<=m;i++){
	for (int j=0;j<=n;j++){
		if (i==0||j==0)
		arr[i][j]=0;
		else if (a[i-1]==b[j-1]){
		arr[i][j]=1+arr[i-1][j-1];
		}
		else
		arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
	}
}
cout<<arr[m][n]<<" ";
}
