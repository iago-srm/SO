Adicionar o arquivo fase1.h a 1/initramfs/

Em 1/linux/arch/arm/tools/syscall.tbl, adicionar uma ultima linha assim:
XXX	common	fase_1			sys_fase_1
em que XXX eh o numero da ultima linha que ja existe +1. Colocar esse numero no define em fase1.h

Adicionar a pasta sys_fase_1 a 1/linux

Substituir o arquivo init.c em 1/initramfs/ pelo que esta neste repo

Em 1/linux/include/linux/syscalls.h, adicionar 
asmlinkage long sys_fase_1(void);
no final do arquivo, antes do ultimo #endif

Em 1/linux/Makefile, procurar (ctrl+f) "core-y" e adicionar "sys_fase_1" depois do ultimo item. Fica algo assim:
core-y		+= kernel/ certs/ mm/ fs/ ipc/ security/ crypto/ block/ sys_blocking_dev/ sys_stack/ sys_hello_world/ sys_stop/ sys_fase_1/

Iniciar o kernel (com o docker, a partir da sua maquina) e observar a mensagem em sys_fase_1.c printada no terminal.
