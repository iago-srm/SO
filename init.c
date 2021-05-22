// #include "hello_world.h"
#include "fase1.h"

//#include<sys/linkage.h>
//#include<sys/module.h>


#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

//#include <linux/printk.h>

int main()
{
   int last_status = -1;

   while (1) {
      last_status = fase_1(last_status);
      sleep(10);

      if(fork()){ // pai
	fopen();
      }else{ // filho
	
      }
   }
   return 0;
}
