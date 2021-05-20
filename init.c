// #include "hello_world.h"
#include "fase1.h"

//#include<sys/linkage.h>
//#include<sys/module.h>


//#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

//#include <linux/printk.h>

int main()
{
   while (1) {
      // hello_world();
      int last_status = -1;
      last_status = fase_1(last_status);


	// Open file
	char *pathname = "text.txt";
	//int mode = ;
	int flags = O_WRONLY; // O_CREAT
	int status_open = open(pathname, flags);

	//printk("Status: %d", status_open);[
	//pr_info("Teste; status: %d", status_open);

   }
   return 0;
}










