/*                                                     
 * $Id: hello.c,v 1.2 2010/05/19 20:37:22 baker Exp baker $ 
 */                                                    

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	printk("Hello, world\n");
	return 0;
}

static void hello_exit(void)
{
	printk( "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
