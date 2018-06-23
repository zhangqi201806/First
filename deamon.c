#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pit_t pid = 0;
	
	pid = fork();
	
	if(pid < 0)
	{
		pritnf("fork error\n");
		exit(0);
	}
	
	if(pid > 0)
	{
		printf("parent process quit\n");
		exit();
	}

	if(pid == 0)
	{
		printf("son processs\n");
		
		pid = setsid();
	}

	while(1)
	{
		sleep(1);
	}
	return 0;
}