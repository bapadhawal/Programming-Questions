#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main(){
int k;
for (int i=0;i<6;i++)
{
	cin>>k;
	arr[k]++;
}
int leg=0,two=0,one=0,c[6];
for(int i=1;i<10;i++)
{
	if (arr[i]>=4)
	{
	leg=1;
	arr[i]-=4;
	}
	if(arr[i]==2)
	{
	two=1;
	}
	if(arr[i]==1)
	{
		c[one]=i;
		one++;
	}
}
if (leg==1&&two==1)
cout<<"Elephant\n";
else if (leg==1 && one==2 && (c[0]<c[1]))
cout<<"Bear\n";
else 
cout<<"Alien\n";
}
