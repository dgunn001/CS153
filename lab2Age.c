#include "types.h"
#include "user.h"




int main(int argc, char *argv[])
{
	int AgingScheduler(void);	
	

  printf(1, "\n This program tests the aging of processs from  lab#2\n");
  
	AgingScheduler();
	return 0;
 }



int AgingScheduler(void) {

  int pid;
  int i;
  int k;
  int j;
  setpriority(31);
  for (i = 0; i < 3; i++) {
    pid = fork();
    if (pid > 0) {
      continue;
	}
    else if (pid == 0) {
      setpriority(30 - 10*i);
      for( j = 0; j<50000; ++j){
	for( k = 0; k <1000; k++){
	asm("nop");}}
	printf(1, "\n child# %d with original priority %d and new priority %d has finished! \n", getpid(), 30 - 10*i, getpriority());
      exit2(0);
	
    }
    else {
      printf(2, "\n Error \n");
      exit2(1);
    }
  }
  if(pid > 0) {
	while(wait2(0) > 0) {
		printf(1, "\n Parent# %d waiting with priority %d \n", getpid(), getpriority());
	}
      printf(1, "\n Parent#%d exits with priority %d \n", getpid(), getpriority());

  }
  exit2(0);
  return 0;
}
