#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
  int cs,n;
  int bufsize=1024;
  char *buffer=malloc(bufsize);
  char fname[255];

  // Create address object to store the address of server
  struct sockaddr_in address;
  address.sin_family=AF_INET; // iP PROTOCOL FAMILY = 2
  address.sin_port=htons(15000);
  inet_pton(AF_INET,argv[1],&address.sin_addr); //SAVING INTERNET ADDRESS IN THIS VAR USING IP GIEN AT EXECUTION AND FAMILY OF IP
  
  //SOCKET CREATION AND CONNECTION ESTABLISHMENT PHASE
  cs=socket(AF_INET,SOCK_STREAM,0);
  connect(cs,(struct sockaddr *)&address,sizeof(address));
  printf("\nEnter filename: ");scanf("%s",fname);
  
  send(cs,fname,255,0);
  while((recv(cs,buffer,bufsize,0))>0)
    printf("%s",buffer);
  
  printf("\nEOF\n");
  return close(cs); //close socket!
}
