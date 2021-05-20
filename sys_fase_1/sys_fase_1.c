#include<linux/linkage.h>
#include<linux/module.h>

asmlinkage long sys_fase_1(int t1, int t2, int t3, int flags,
 int mode)
{ 
	// pr_info("Flags: %d", flags);
	// pr_info("Mode: %d", mode);
	// pr_info("Filename: %s", filename);
	return pr_info("My fase_1 syscall!; Flags: %d; mode: %d\nt1: %d, t2: %d, t3: %d\n\n", 
		flags, mode, t1, t2, t3);//, filename);
}

// /* Deal with CONFIG_MODVERSIONS */
// #if CONFIG_MODVERSIONS==1
// #define MODVERSIONS
// #include <linux/modversions.h>
// #endif

// #include <sys/syscall.h> /* The list of system calls */

// /* For the current (process) structure, we need
//  * this to know who the current user is. */
// #include <linux/sched.h>

// /* In 2.2.3 /usr/include/linux/version.h includes a
//  * macro for this, but 2.0.35 doesn't − so I add it
//  * here if necessary. */
// #ifndef KERNEL_VERSION
// #define KERNEL_VERSION(a,b,c) ((a)*65536+(b)*256+(c))
// #endif
// #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,2,0)
// #include <asm/uaccess.h>
// #endif
// /* The system call table (a table of functions). We
//  * just define this as external, and the kernel will
//  * fill it up for us when we are insmod'ed
//  */
// extern void *sys_call_table[];
// /* UID we want to spy on − will be filled from the
//  * command line */
// int uid;
// #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,2,0)
// MODULE_PARM(uid, "i");
// #endif
// /* A pointer to the original system call. The reason
//  * we keep this, rather than call the original function
//  * (sys_open), is because somebody else might have
//  * replaced the system call before us. Note that this
//  * is not 100% safe, because if another module
//  * replaced sys_open before us, then when we're inserted
//  * we'll call the function in that module − and it
//  * might be removed before we are.
//  *
//  * Another reason for this is that we can't get sys_open.
//  * It's a static variable, so it is not exported. */
// asmlinkage int (*original_call)(const char *, int, int);
// /* For some reason, in 2.2.3 current−>uid gave me
//  * zero, not the real user ID. I tried to find what went
//  * wrong, but I couldn't do it in a short time, and
//  * I'm lazy − so I'll just use the system call to get the
//  * uid, the way a process would.
//  *
//  * For some reason, after I recompiled the kernel this
//  * problem went away.
//  */
// asmlinkage int (*getuid_call)();
// /* The function we'll replace sys_open (the function
//  * called when you call the open system call) with. To
//  * find the exact prototype, with the number and type 
// * of arguments, we find the original function first
//  * (it's at fs/open.c).
//  *
//  * In theory, this means that we're tied to the
//  * current version of the kernel. In practice, the
//  * system calls almost never change (it would wreck havoc
//  * and require programs to be recompiled, since the system
//  * calls are the interface between the kernel and the
//  * processes).
//  */
// asmlinkage int our_sys_open(const char *filename,
//  int flags,
//  int mode)
// {
//  int i = 0;
//  char ch;
//  /* Check if this is the user we're spying on */
//  if (uid == getuid_call()) {
//  /* getuid_call is the getuid system call,
//  * which gives the uid of the user who
//  * ran the process which called the system
//  * call we got */
//  /* Report the file, if relevant */
//  printk("Opened file by %d: ", uid);
//  do {
// #if LINUX_VERSION_CODE >= KERNEL_VERSION(2,2,0)
//  get_user(ch, filename+i);
// #else
//  ch = get_user(filename+i);
// #endif
//  i++;
//  printk("%c", ch);
//  } while (ch != 0);
//  printk("\n");
//  }
//  /* Call the original sys_open − otherwise, we lose
//  * the ability to open files */
//  return original_call(filename, flags, mode);
// }
// /* Initialize the module − replace the system call */
// int init_module()
// {
//  /* Warning − too late for it now, but maybe for
//  * next time... */
//  printk("I'm dangerous. I hope you did a ");
//  printk("sync before you insmod'ed me.\n");
//  printk("My counterpart, cleanup_module(), is even");
//  printk("more dangerous. If\n");
//  printk("you value your file system, it will ");
//  printk("be \"sync; rmmod\" \n");
//  printk("when you remove this module.\n");
//  /* Keep a pointer to the original function in
//  * original_call, and then replace the system call
//  * in the system call table with our_sys_open */
//  original_call = sys_call_table[__NR_open];

// sys_call_table[__NR_open] = our_sys_open;
//  /* To get the address of the function for system
//  * call foo, go to sys_call_table[__NR_foo]. */
//  printk("Spying on UID:%d\n", uid);
//  /* Get the system call for getuid */
//  getuid_call = sys_call_table[__NR_getuid];
//  return 0;
// }
// /* Cleanup − unregister the appropriate file from /proc */
// void cleanup_module()
// {
//  /* Return the system call back to normal */
//  if (sys_call_table[__NR_open] != our_sys_open) {
//  printk("Somebody else also played with the ");
//  printk("open system call\n");
//  printk("The system may be left in ");
//  printk("an unstable state.\n");
//  }
//  sys_call_table[__NR_open] = original_call;
// } 


