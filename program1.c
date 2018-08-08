/* Using fork() create a child process, the child process prints its own process id, and id of its parent and then exits.
   The parent process waits for its child to finish by executing the wait() and prints its own pid and the id of its child process and then exit. */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	pid_t child;
	child = fork();

	if(child==0)
	{
		printf("\nChild Process\n");
		printf("My PID is %d \t My Parent PID is %d",getpid(),getppid());
		exit(0);
	}
	else{
	wait();
	printf("\nParent\n");
	printf("My PID is %d \t My Child PID is %d\n",getpid(),child);
	}
}
