#include<stdio.h>
#include<unistd.h>

#define oops(m,x) {perror(m); exit(x);}

int main(int ac, char **av){

  int pipe1[2], pipe2[2],newfd,pid1,pid2;
  
  if(ac!=4){
    fprintf(stderr,"usuage : pipe cmd1, cmd2, cmd3\n");
    exit(1);
  }
  
  if(pipe(pipe1)==-1 || pipe(pipe2)==-1)
  oops("Cannot get a pipe",1);
  
  if((pid1=fork())==-1)
    oops("Cannot fork",2);
    
  if(pid1>0){
  
  pid2=fork();   
  
  if(pid2>0){
  
  close(pipe2[1]);
  dup2(pipe2[0],0);
  close(pipe2[0]);
  execlp(av[3],av[3],NULL);
  oops(av[3],4);
  
  }
  
  close(pipe1[1]);
  close(pipe2[0]);
  dup2(pipe1[0],0);
  dup2(pipe2[1],1);
  close(pipe1[0]);
  close(pipe2[1]);

  execlp(av[2],av[2],NULL);
  oops(av[2],4);
  
  }
  
  if(pid1==0){
  
  close(pipe1[0]);
  dup2(pipe1[1],1);
  
  close(pipe1[1]);
  execlp(av[1],av[1],NULL);
  oops(av[1],5);
    
  }
}

