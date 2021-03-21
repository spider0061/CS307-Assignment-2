#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/init.h>  
MODULE_LICENSE("No License");
MODULE_AUTHOR("Ashutosh Sharma");
MODULE_DESCRIPTION("Crash Test");
MODULE_VERSION("0.1");
static int __init start(void)
{
    printk(KERN_INFO "Loading test module.\n");
	int x=0,y=1;   
	y/=x;
	return 0;  
}
 
static void __exit end(void)
{
    printk(KERN_INFO "Unloading test module.\n");
}
 
module_init(start);
module_exit(end); 
