#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_READ 404
#define __NR_WRITE 405

long read_number(void)
{
	return syscall(__NR_READ);
}

void write_number(long num)
{
	return syscall(__NR_WRITE, num);
}
