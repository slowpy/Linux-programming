/*app_a.c*/
#include <stdio.h>
#include <pthread.h>
void thread(void)
{
	int i;
	for(i=0;i<3;i++)
	{
		printf("This is a pthread.\n");
		sleep(1);
	}
}

int main(void)
{
	pthread_t id;
	int i,ret;
	ret=pthread_create(&id,NULL,(void *) thread,NULL);
	if(ret!=0)
	{
		printf ("Create pthread error!\n");
		exit (1);
	}
#if 1
	for(i=0;i<3;i++)
	{
		printf("This is the main process.\n");
		sleep(2);
	}
#endif
	pthread_join(id,NULL);//等待線程（pthread）結束

        
        printf("main process exit\n");
	return (0);
}
