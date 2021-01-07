#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM 18

void *print_msg_func(void *tid)
{
  long id = (long) tid;
  printf("Hello SCR. Written by thread %ld \n",id);
  pthread_exit(NULL);
}

int main()
{
  pthread_t thread[NUM];
  int iret;
  long tid;
   for(tid=0;tid<NUM;tid++){
     iret = pthread_create(&thread[tid], NULL, print_msg_func, (void *)tid);
   }
  
  pthread_exit(NULL);
  return 0;
}
