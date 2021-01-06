#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>

int main()

{
  int cs,ns,fd,n;
  int bufsize=1024;
  char *buffer=malloc(bufsize);
  char fname[255];


  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = htons(15000);
  address.sin_addr.s_addr = INADDR_ANY;


  cs=socket(AF_INET,SOCK_STREAM,0);
  //to listen the incomming filename from client
  bind(cs,(struct sockaddr *)&address,sizeof(address)); 
  listen(cs,3);
  ns=accept(cs,(struct sockaddr *)NULL,NULL); //when connection arrives, it opens a new socket to communicate an thus a new object (client side (ns))
  recv(ns,fname,255,0);
  fd=open(fname,O_RDONLY);  //creating file object(can put 00 in 2nd argument)
  n=read(fd,buffer,bufsize);//reading from file object
  send(ns,buffer,n,0);
  
  close(ns);
  return close(cs);

}
