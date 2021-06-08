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

void add_char(char ch, char *st){
	int i;
	for(i=0; st[i] != 0; i++);
	st[i] = ch;
	st[i + 1] = 0;
}

asmlinkage long sys_fase_1(int last_status)
{

	pr_info("-------------------------------------------------------------------------------------------------");


	// Declaracoes das variaveis
	umode_t mode = 0x777;
	size_t count = 10;//MAX_SIZE;
	static char buffer[MAX_SIZE];// = "teste\n";// = "Kernel write\n\n";

	int status_open = last_status;
	char *file_name = "/teste.txt";
	int size_st;
	int status_write;
	char content[MAX_SIZE];

	mm_segment_t fs;
	
	fs = get_fs();     /* save previous value */
	set_fs(KERNEL_DS); /* use kernel limit */

	pr_info("Id / status open antes do if: %d", status_open);

	if(status_open < 0){ // == 0 nao garanto
		status_open = sys_open(file_name, O_CREAT | O_APPEND | O_RDWR | O_LARGEFILE/*O_WRONLY*/, mode);

		pr_info("Arquivo %s aberto, o id / status open dele e %d", file_name, status_open);

		//syscall(5, "teste.txt", O_WRONLY | O_TRUNC | O_CREAT, 438);	
		buffer[0] = 'a';	
		buffer[1] = 'b';	
		buffer[2] = 'c';	
		buffer[3] = 'd';	
		buffer[4] = '\0';

		//sys_write(status_open, buffer, count);	
	}

	int status_fallocate = sys_fallocate(status_open, mode, 0, MAX_SIZE);
	pr_info("Status fallocate: %d", status_fallocate);

	int status_mlock = sys_mlock(status_open, 100);
	pr_info("Status mlock: %d", status_mlock);

	pr_info("Buffer depois do if do open: %s", buffer);
	add_char('z', buffer);
	pr_info("Buffer depois da func de concat: %s", buffer);

	//sys_unlink();

	//content[0] = 'c';
	//content[0] = '\0';
	pr_info("Content antes do read: %s", content);


	/*int*/ size_st = sys_read(status_open, /*&*/content, count);
	pr_info("Content antes do write: %s, tam: %d", content, size_st);

	//char ch = 'k';
	/*int*/ status_write = sys_write(status_open, &buffer[0], count);

	pr_info("Status write: %d, buffer que tentou ser escrito: %s", status_write, buffer);
	pr_info("Erros possiveis: EAGAIN: %d, EWOULDBLOCK %d, EBADF %d, EDETADDRESSQ %d, EDQUOT %d, EFAULT %d, EFBIG %d, EINTR %d", 
		EAGAIN, EWOULDBLOCK, EBADF, 0, EDQUOT, EFAULT,
		EFBIG, EINTR);

	size_st = sys_read(status_open, content, count);
	pr_info("Content depois do write: %s, tam: %d", content, size_st);


	pr_info("Status open depois de tudo: %d", status_open);
	pr_info("Buffer depois de tudo: %s", buffer);

	sys_close(status_open);
	pr_info("Arquivo com id / status %d fechado", status_open);


	size_st = sys_read(status_open, content, count);
	pr_info("Content depois do close: %s, tam: %d", content, size_st);
	
	//wait(1000);

	set_fs(fs); /* restore before returning to user space */

	
	return status_open;
	//return pr_info("My fase_1 syscall!");//, filename);
}

