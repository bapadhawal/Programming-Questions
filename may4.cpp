#include <bits/stdc++.h>
using namespace std;
int main(){
int n,k,p1;
scanf("%d%d%d",&n,&k,&p1);
int arr[n];
for (int i=0;i<n;i++)
scanf("%d",&arr[i]);
char ch;
int cnt=0;
	int temp=0;
	int new1=0;
int i=0;
while(p1--){
	cin>>ch;
	cnt=0;
	if (k>n)
	k=n;
	if (ch=='!')
	{
		temp=arr[n-1];
		for (i=n-1;i>=0;i--)
		arr[i]=arr[i-1];
		arr[0]=temp;
		//for (int i=0;i<n;i++)
		 //cout<<arr[i]<<" ";
	}
	else if (ch=='?'){
		for (i=0;i<k;i++)
		cnt+=arr[i];
		new1=cnt;
		for (i=k;i<n;i++)
		{
			new1+=arr[i]-arr[i-k];
			cnt=max(cnt,new1);
		}
		printf("%d\n",cnt);		
	}
}
}
