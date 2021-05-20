#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_fase_1 404

long fase_1(int last_status)
{
	return syscall(__NR_fase_1, last_status);
}
