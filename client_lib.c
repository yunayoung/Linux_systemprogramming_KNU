#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<strings.h>
//#include"socklib.h"


void talk_with_server(int fd);
int main(int ac, char *av[]){

	int fd,port;
	char host[30];
//	printf("host port : ");
//	scanf("%s %d",host,&port);
	fd= connect_to_server(av[1], atoi(av[2]));
	if(fd==-1)
		exit(1);

	talk_with_server(fd);
	close(fd);

}

void talk_with_server(int fd){

	char buf[50];
	int n;
	n=read(fd,buf,50);
	write(1,buf,n);
}


