

unsigned char 1_wire_bus_init(void)	//初始化
{
	unsigned char result;
	
	delay_us(10);		//延时一段时间
	DQ=0;						//拉低
	delay_us(500);		//480-960us
	DQ=1;						//上升沿
	delay_us(20);		//延时15-60us等待从机应答
	if(DQ==0)	{result=1;}
	else			{result=0;}
	delay_us(10);		//延时一段时间
	return	result;
	//返回1有效
	
}





void write_one_bit(bit b)	//写一位
{
	if(b)	//写1
	{
		DQ=0;						//拉低		
		delay_us(10);		//15us内
		DQ=1;						//拉高
		delay_us(10);		//为写下一bit准备
		
	}
	
	else//写0
	{
		DQ=0;						//拉低
		delay_us(80);		//保持60us以上，120us内
		DQ=1;						//释放总线
		delay_us(10);		//为写下一bit准备
	}
	
}


void write_one_byte(unsigned char	value)	//写一个字节	
{
	unsigned char	i;
	fof(i=0;i<8;i++)
	{
		write_one_bit(value&0x01);
		value=value>>1;
		
	}
}



unsigned char read_one_bit(void)	//读一位
{
	unsigned char result;
	DQ=0;						//拉低
	delay_us(2);		//保持至少1us
	DQ=1;						//释放总线
	delay_us(10);		//15us内读取数据
	result=DQ;
	delay_us(10);		//延时一段时间
	
	return	result;
	
}


unsigned char read_one_byte(void)	//读一个字节
{
	unsigned char result,i;
	for(i=0;i<8;i++)
	{
		result=result>>1;
		if(read_one_bit())	{result|=0x80;}
	}
	return	result;
	
}



void read_func()
{
	
	if(1_wire_bus_init())
	{
		write_one_byte(0x33)	//发送读写命令
	}

}





