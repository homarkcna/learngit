

unsigned char 1_wire_bus_init(void)	//��ʼ��
{
	unsigned char result;
	
	delay_us(10);		//��ʱһ��ʱ��
	DQ=0;						//����
	delay_us(500);		//480-960us
	DQ=1;						//������
	delay_us(20);		//��ʱ15-60us�ȴ��ӻ�Ӧ��
	if(DQ==0)	{result=1;}
	else			{result=0;}
	delay_us(10);		//��ʱһ��ʱ��
	return	result;
	//����1��Ч
	
}





void write_one_bit(bit b)	//дһλ
{
	if(b)	//д1
	{
		DQ=0;						//����		
		delay_us(10);		//15us��
		DQ=1;						//����
		delay_us(10);		//Ϊд��һbit׼��
		
	}
	
	else//д0
	{
		DQ=0;						//����
		delay_us(80);		//����60us���ϣ�120us��
		DQ=1;						//�ͷ�����
		delay_us(10);		//Ϊд��һbit׼��
	}
	
}


void write_one_byte(unsigned char	value)	//дһ���ֽ�	
{
	unsigned char	i;
	fof(i=0;i<8;i++)
	{
		write_one_bit(value&0x01);
		value=value>>1;
		
	}
}



unsigned char read_one_bit(void)	//��һλ
{
	unsigned char result;
	DQ=0;						//����
	delay_us(2);		//��������1us
	DQ=1;						//�ͷ�����
	delay_us(10);		//15us�ڶ�ȡ����
	result=DQ;
	delay_us(10);		//��ʱһ��ʱ��
	
	return	result;
	
}


unsigned char read_one_byte(void)	//��һ���ֽ�
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
		write_one_byte(0x33)	//���Ͷ�д����
	}

}





