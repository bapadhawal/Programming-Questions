//Sender
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define ll long long

ll power(ll a, ll b, ll m)
{
	
	ll ret=1,i;
	
	for(i=0;i<b;i++)
		ret=ret*a%m;
	
	return ret;
}


// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        ll res = (x%m + m) % m;
        return res;
    }
}

int main()
{   
    
    int csock,st;
	 ll p,g,x,a;
	ll y,b,c1,c2,plain,plain2;
	p=10007;
	g=7269;
	x=67;
	a=2199;
	y=rand()%p;
	
	
    
    struct sockaddr_in se,cl;
    
    csock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(csock == -1)
    {
        printf("Error c1\n");
        return 0;
    }
    
    
    se.sin_family = PF_INET;
    se.sin_port = htons(6005);
    se.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    st = connect(csock, (struct sockaddr *)&se, sizeof(se));
    printf("Connection established\n");
    
    if(st==-1)
    {
        printf("Error c2\n");
        return 0;
    }
    
	
	ll ms;
	printf("Enter plaintext\n");
	scanf("%lld",&ms);
	c1=power(g,y,p);
	c2=power(a,y,p)*ms%p;
	
    char msg[10];
	sprintf(msg,"%d",ms);
    int len = strlen(msg);
    
    if(send(csock, msg, len, 0) != len)
    {
        printf("Error c3\n");
        return 0;
    }
  
    printf("Encrypted Text sent:- c1=%lld, c2=%lld\n",c1,c2);
    printf("Message sent successful(Exiting)\n");
    close(csock);
    
    
    return 0;
}
