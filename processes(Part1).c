/* Name: Aryan Behal
   Roll_Number: 2019026 */

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

//global variable
int x=10;

int main()
{
	pid_t ret_value;
	int status;
	int i;

	//forking
	ret_value=fork();
	if(ret_value<0)
	{
		printf("could not fork..\n");
		//couldn't create child process
	}
	else if( ret_value == 0)
	{
		//child process	
		while(x>-90)
		{
			x--;
	        printf("c: %d \n",x);
		}
		printf("\nfinal X in child process: %d\n",x);
		exit(0);
	}
	else
	{
		//parent process
		while(x<100)
		{
			x++;
	        printf("p: %d \n",x);
		}
		printf("\nfinal X in parent process: %d\n",x);
		waitpid(ret_value,&status,0);
		printf("\nfinal X: %d\n", x);
		exit(0);
	}	
}	
