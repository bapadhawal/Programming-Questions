#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
arr[0]=1;
int two=2,three=3,five=5;
int i2=0,i3=0,i5=0;
for (int i=1;i<n;i++){

	arr[i]=min(two,min(three,five));
	if (arr[i]==two){
	i2++;
	two=arr[i2]*2;
	}
	if (arr[i]==three){
	i3++;
	three=arr[i3]*3;
	}
	if (arr[i]==five){
	i5++;
	five=arr[i5]*5;
	}
}
cout<<arr[n-1]<<" ";
return 0;
}
