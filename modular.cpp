#include <iostream>
using namespace std;
bool arr[10005];
void sieve(){
    arr[0]=1;
    arr[1]=1;
    for (int i=2;i<=10004;i++){
            if (arr[i]==0){
                for (int j=i+i;j<10005;j+=i){
                    arr[j]=1;
                }   
            }
    }
}
int main() {
	int t;
	cin>>t;
	int n;
	sieve();
	while(t--){
	    cin>>n;
	    for (int i=2;i<=n;i++)
	    {
	        if (arr[i]==0)
	        cout<<i<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
