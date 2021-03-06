#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

#define MAX_SIZE 0xFFFF

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
		return -1;
	}
	else if (pid == 0) {
		printf("Hello from the child process!\n");

		while (1) {

			for(i = 0; i < 50; i++) printf("-");
			printf("\nINIT\n");

			printf("Tentando abrir arquivo\n");
			file = fopen(file_name, "a+");
			printf("Arquivo aberto com ponteiro: %d\n", file);

			if(file){
				printf("Escrevendo %s no arquivo\n", text);
				fprintf(file, "%s", text);
			}

			fclose(file);

			FILE *r_file = fopen(file_name, "r+");
			char ch;
	
			printf("No arquivo ja tem: {\n");
      
			while(1) {
			      ch = fgetc(r_file);
			      if( feof(r_file) ) break;
			      printf("%c", ch);
			}

			printf("\n} Fim do conteudo do arquivo\n");

		}
	}
  
	else {
		int status;
		printf("Parent process\n");
		(void)waitpid(pid, &status, 0);
		printf("Status do pid: %d\n", status);

		while(1){
			printf("Fim da execução\n");
			sleep(10);
		}
	}

	return 0;
}
