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

Alguns comandos possivelmente úteis:
  793  ln SO/fase1.h initramfs/fase1.h
  794  vim linux/arch/arm/tools/syscall.tbl
  795  ls SO
  796  ln SO/sys_fase_1/ linux/sys_fase_1
  797  man ln | grep soft
  798  ln -s SO/sys_fase_1/* linux/sys_fase_1
  799  mkdir linux/sys_fase_1
  800  ln -s SO/sys_fase_1/* linux/sys_fase_1
  801  clear
  802  ls linux/sys_fase_1/
  803  cat linux/sys_fase_1/sys_fase_1.c 
  804  rm linux/sys_fase_1/sys_fase_1.c 
  805  rm linux/sys_fase_1/Makefile 
  806  cp SO/sys_fase_1 linux/sys_fase_1
  807  cp -r SO/sys_fase_1 linux/sys_fase_1
  808  ls linux/sys_
  809  ls linux/sys_fase_1/
  810  ln SO/sys_fase_1/sys_fase_1.c linux/sys_fase_1/sys_fase_1.c 
  811  rm linux/sys_fase_1/sys_fase_1.c 
  812  rm linux/sys_fase_1/Makefile 
  813  ln SO/sys_fase_1/sys_fase_1.c linux/sys_fase_1/sys_fase_1.c 
  814  ln SO/sys_fase_1/Makefile linux/sys_fase_1/Makefile
  815  cp initramfs/init.c initramfs/bkp_init.c
  816  ln SO/init.c initramfs/init.c
  817  rm initramfs/init.c
  818  ln SO/init.c initramfs/init.c
  819  clear
  820  vim linux/include/linux/syscalls.h 
  821  cat linux/Makefile 
  822  cat linux/Makefile | grep core-y
  823  gedit linux/Makefile

  ln linux/arch/arm/tools/syscall.tbl ~/Documents/Poli/SO/pcs3746-sistemas-operacionais/1/SO/syscall.tbl

