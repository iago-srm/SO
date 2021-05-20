#include<linux/linkage.h>
#include<linux/module.h>

asmlinkage long sys_fase_1(void)
{ 
	return pr_info("My fase_1 syscall!\n");
}
