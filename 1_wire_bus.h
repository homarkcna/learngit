#ifndef __1_WIRE_BUS_H__
#define __1_WIRE_BUS_H__

extern unsigned char 1_wire_bus_init(void);	
extern void write_one_bit(bit b);	
extern void write_one_byte(unsigned char	value);
extern unsigned char read_one_bit(void);	
extern unsigned char read_one_byte(void);	
extern void read_func();

#endif