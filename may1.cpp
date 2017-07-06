#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
string s;
while(t--){
	cin>>s;
	int t=s.size();
	int arr[3];
	arr[0]=0;
	arr[1]=0;
	arr[2]=0;
	int flag=0;
	for (int i=0;i<t;i++)
	{
		if (s[i]=='C')
		{
			arr[0]=1;
			if (arr[1]==1||arr[2]==1)
			{
				cout<<"no\n";
				flag=1;
				break;
			}
		}
		else if (s[i]=='E')
		{
			arr[1]=1;
			if (arr[2]==1)
			{
			cout<<"no\n";
			flag=1;
			break;
			}
		}
		else if (s[i]=='S')
		{
			arr[2]=1;
		}
	}
	if (flag==0)
	cout<<"yes\n";
}
return 0;
}
