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



void proces_request(int fd);
int main(){

	int sock, fd;
	int port;

//	scanf("%d",&port);
//  printf("port input \n");
	sock=make_server_socket(13000);

	if(sock==-1)
		exit(1);

	while(1){
	
		fd=accept(sock, NULL, NULL);
		if(fd==-1)
			break;

		process_request(fd);
		close(fd);
	}
}
void process_request(int fd){

	time_t now;
	char *cp;

	time(&now);
	cp=ctime(&now);
	write(fd, cp, strlen(cp));
}
