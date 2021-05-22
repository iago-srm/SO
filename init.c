// #include "hello_world.h"
#include "fase1.h"

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
	int last_status = -1;

	char *file_name = "/teste.txt";
	char *make_space_file = "/teste2.txt";

	char *text = "k";

	printf("Novo init\n");
	
	FILE *file;

	int status_unlink = unlink(make_space_file);
	printf("Status unlink: %d\n", status_unlink);

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork failed");
		return -1;//exit(EXIT_FAILURE);
	}
	else if (pid == 0) {
		printf("Hello from the child process!\n");
		//_exit(EXIT_SUCCESS);
		while (1) {
		//last_status = fase_1(last_status);
			file = fopen(file_name, "a+");

			//sleep(1);
			printf("Esperou 1 seg\n");

			if(file){
				//printf("Escreveu %s no arquivo\n", text);
				//fputs(text, file);
				fprintf(file, "%s", text);
			}

			fclose(file);

			FILE *r_file = fopen(file_name, "r+");
			char content[MAX_SIZE];
			char ch;
			//fgets(content, MAX_SIZE, r_file);
			
		
			printf("No arquivo ja tem: \n");
			while(1) {
			      ch = fgetc(r_file);
			      if( feof(r_file) ) {
				 break;
			      }
			      printf("%c", ch);
			}

			/*while( /*(ch = fgetc(r_file)) != EOF){/fscanf(r_file, "%s", content)){	
				//printf("%c", ch);
				printf("%s", content);
				//sleep(1);
			}*/
			printf("\nSaiu do loop\n");

			//fclose

			/*if(fork()) // pai
			{ 

			}
			else // filho
			{ 		
			}*/
		}
	}
	else {
		int status;
		printf("Father process\n");
		(void)waitpid(pid, &status, 0);
		printf("Status do pid: %d\n", status);
	}

	

	return 0;
}
