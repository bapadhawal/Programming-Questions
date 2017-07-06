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
vector <int> Lmin(n);
vector <int> Rmax(n);
Lmin[0]=arr[0];
for (int i=1;i<n;i++)
{
	Lmin[i]=min(Lmin[i-1],arr[i]);
	//cout<<Lmin[i]<<" ";
}
//cout<<"\n";
Rmax[n-1]=arr[n-1];
for (int i=n-2;i>=0;i--)
{
 	Rmax[i]=max(Rmax[i+1],arr[i]);
 	//cout<<Rmax[i]<<" ";
}
int diff=-1;
int i=0;// this is the also another method to remember the method okk so please take a look to it.
int j=0;
while (i<n && j<n){//this is the most important case to be understood
	if (Lmin[i]<=Rmax[j])
	{
		diff=max(diff,j-i);
		j++;
	}
	else
	i++;
}
cout<<diff<<" ";
return 0;
}
