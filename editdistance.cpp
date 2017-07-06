#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int main(){
string s1,s2;
cin>>s1>>s2;
int m=s1.size();
int n=s2.size();
cout<<m<<n<<" ";

for (int i=0;i<=m;i++)
{
	for (int j=0;j<=n;j++){
		if (i==0)
		arr[i][j]=j;
		else if (j==0)
		arr[i][j]=i;
		else if (s1[i-1]==s2[j-1])
		arr[i][j]=arr[i-1][j-1];
		else 
		arr[i][j]=1+ min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));	
	}
}
cout<<arr[m][n]<<" ";
return 0;
}
