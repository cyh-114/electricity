#include "RM.h"
#include "I2C.h"
void Start(void) {
	SDA_High();
	SCL_High();
	SDA_Low();
	SCL_Low();
}
void Stop(void) {
	SCL_Low();
	SDA_Low();
	SCL_High();
	SDA_High();
}
void SendByte(unsigned char data) {
	unsigned char i;
	for (i = 0; i < 8; i++) {
		if (data & 0x80) {
			SDA_High();
		} else {
			SDA_Low();
		}
		SCL_High();
		SCL_Low();
		data <<= 1;
	}
	SDA_High();
	SCL_High();
	SCL_Low();
}
unsigned char ReceiveAck(void)
{
	unsigned char ack;
	SDA_High();
	SCL_High();
	ack = SDA_Read();
	SCL_Low();
	return ack;
}
void SendData(unsigned char data)
{
	Start();
	SendByte(data);
	ReceiveAck();
	Stop();
}
