#include <linux/module.h>
#include <linux/init.h>

int foo = 0;
module_param (foo, int, S_IRUGO | S_IWUSR);

static int __init my_init (void)
{
	printk (KERN_INFO "Hello ch2mod! Loaded at 0x%p\n", my_init);
	printk (KERN_INFO "foo = %d\n", foo);
	return 0;
}

static void __exit my_exit (void)
{
	printk (KERN_INFO "Goodbye ch2mod! Unloaded from 0x%p\n", my_exit);
	printk (KERN_INFO "foo = %d\n", foo);
}

/*module_init (my_init);*/
/*module_exit (my_exit);*/

MODULE_AUTHOR ("David Albert");
MODULE_LICENSE ("GPL v2");
