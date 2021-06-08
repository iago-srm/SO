#include<linux/linkage.h>
#include<linux/module.h>

//#include <linux/stat.h>
//#include <linux/fcntl.h>

#include <linux/fcntl.h>
//#include <linux/stdio.h>
//#include <stdlib.h>
//#include <linux/unistd.h>
#include <linux/stat.h>
#include <linux/types.h>

//#include <linux/time.h>
//#include <unistd.h>

#define MAX_SIZE 1024

#include <linux/syscalls.h>
//#include <linux/syscall.h>
//#include<string.h>

//static int last_pos = 0;


long last_num = 0;

asmlinkage long read_number(void){
	return last_num;
}

asmlinkage void write_number(long num){
	pr_info("Numero recebeido: %ld", num);
	pr_info("Numero anterior: %ld", last_num);

	last_num = num;
}
