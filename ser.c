#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main(){

int sock,st;
struct sockaddr_in ser,cli;
sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);


cli.sin_family=PF_INET;
cli.sin_port=htons(6004);
 cli.sin_addr.s_addr = inet_addr("127.0.0.1");

st=bind(sock,(struct sockaddr *)&cli,sizeof(cli));

st=listen(sock,5);

socklen_t l= sizeof(cli);
int s=accept(sock,(struct sockaddr *)&cli,&l);

char msg[15];
recv(s,msg,15,0);
puts(msg);
return 0;
}
