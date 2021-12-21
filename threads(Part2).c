/* Name: Aryan Behal
   Roll_Number: 2019026 */


#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h>

//global variable
int x=10;

void* child(void* arg) 
{ 
  
    //child thread code; 

    while(x>-90)
    {
    	x--;
        printf("c: %d \n",x);
    }
    printf("\nX in child thread: %d\n",x);
  
    // exit the child thread 
    pthread_exit(NULL); 
} 

void parent()
{
	pthread_t ptid; 
  
    // Creating a new thread 
    pthread_create(&ptid, NULL, &child, NULL);

    //parent thread
    while(x<100)
    {
    	x++;
        printf("p: %d \n",x);
    }
    printf("\nX in parent thread: %d\n",x);

    // Waiting for the created thread to terminate 
    pthread_join(ptid, NULL);
    printf("\nfinal X: %d\n", x);
    pthread_exit(NULL);
}
int main()
{
	parent();
	return 0;
}