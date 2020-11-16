

static struct class* seconddrv_class;
static struct class_device* seconddrv_class_dev;

volatile unsigned long *gpfcon;
volatile unsigned long *gpfdat;


volatile unsigned long *gpgcon;
volatile unsigned long *gpgdat;

static int second_drv_open(struct inode* inode, struct file* file)
{
	//配置 gpf 0 2 为输入引脚
	request_irq(IRQ_EINT0,buttons_irq,IRQT_BOTHEDGE,"s2",1);
	request_irq(IRQ_EINT2,buttons_irq,IRQT_BOTHEDGE,"s3",1);
	request_irq(IRQ_EINT11,buttons_irq,IRQT_BOTHEDGE,"s4",1);
	request_irq(IRQ_EINT19,buttons_irq,IRQT_BOTHEDGE,"s5",1);

	return 0;
}


ssize_t second_drv_read(struct file* file, char __user* buf,size_t size, loff_t *ppos)
{
	//返回4个引脚的电平
	unsigned char key_vals[4];
	int regval;

	if(size != sizeof(key_vals))
		return -EINVAL;

	//获取 gpf 0 2 电平
	regval = *gpfdat;
	key_vals[0] = (regval & (1<<0)) ? 1:0;
	key_vals[1] = (regval & (1<<2)) ? 1:0;

	//获取gpg 3 11电平
	regval = *gpgdat;
	key_vals[2] = (regval & (1<<3)) ? 1:0;
	key_vals[3] = (regval & (1<<11)) ? 1:0;

	copy_to_user(bug, key_vals, sizeof(key_vals))

	
return sizeof(key_vals);
}

int major;
static int second_drv_init(void)
{
	major = register_chrdev(0,"second_drv",&second_drv_fops);

	seconddrv_class = class_create(THIS_MODULE,"seconddrv");
	
	seconddrv_class_dev = class_device_create(seconddrv_class,NULL,MKDEV(major,0),NULL,"keys");

	//建立地址映射
	gpfcon = (volatile unsigned long*)ioremap(0x56000050,16);
	gpfdat = gpfcon +1;

	
	gpgcon = (volatile unsigned long*)ioremap(0x56000060,16);
	gpgdat = gpgcon +1;

	return 0;

}
static void  second_drv_exit(void)
{
	unregister_chrdev(major,"second_drv");

	
	class_device_unregister(seconddrv_class_dev);
	
	class_device_destroy(seconddrv_class);

	iounmap(gpfcon);
	iounmap(gpgcon);
	
	return 0;

}
int second_drv_close(struct inode* inode,struct file* file)
{

	//释放中断
		
	return 0;
	
}

static struct file_operation second_drv_fops = {
	.owner = THIS_MODULE,
	.open = second_drv_open,
	.read = second_drv_read,
	.release = second_drv_close,
};

module_init(second_drv_init);
module_exit(second_drv_exit);
MODULE_LICENSE("GPL");


