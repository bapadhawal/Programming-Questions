#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
int main(){

struct sockaddr_in ser,cli;
int sock,st;

sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

ser.sin_family=PF_INET;
ser.sin_port=htons(6004);
ser.sin_addr.s_addr=inet_addr("127.0.0.1");

st=connect(sock,(struct sockaddr *)&ser,sizeof(ser));

printf("connected\n");

char msg[100];
gets(msg);
send(st,msg,strlen(msg),0);
return 0;
}
