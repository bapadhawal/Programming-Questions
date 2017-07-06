#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[1000];
for (int i=0;i<n;i++)
cin>>arr[i];
int x1=0;
for (int i=0;i<n;i++)
x1=x1^arr[i];
int set=x1&~(x1-1);
int x=0,y=0;
for (int i=0;i<n;i++)
{
	if (arr[i]&set)
	x=x^arr[i];
	else 
	y=y^arr[i];
}
cout<<x<<" "<<y<<"\n";
}
