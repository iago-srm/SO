// #include "hello_world.h"
#include "nossas_syscalls.h"

//#include<sys/linkage.h>
//#include<sys/module.h>


#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <stdio.h>

#define MAX_SIZE 0xFFFF

//#include <linux/printk.h>


int main()
{
	int x = 0;

	while(1){
		x = read_number();
		sleep(1);
		x = x + 1;
		write_number(x);
	}


	return 0;
}
