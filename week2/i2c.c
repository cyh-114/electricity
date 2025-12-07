#include "RM.h"
#include "I2C.h"
void Start(void) {
	SDA_High();
	HAL_Delay(5);
	SCL_High();
	HAL_Delay(5);
	SDA_Low();
	HAL_Delay(5);
	SCL_Low();
}
void Stop(void) {
	SCL_Low();
	HAL_Delay(5);
	SDA_Low();
	HAL_Delay(5);
	SCL_High();
	HAL_Delay(5);
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
		HAL_Delay(5);
		SCL_Low();
		HAL_Delay(5);
		data <<= 1;
	}
}
unsigned char ReceiveAck(void)
{
	unsigned char ack;
	SDA_High();
	HAL_Delay(5);
	SCL_High();
	HAL_Delay(5);
	ack = SDA_Read();
	SCL_Low();
	HAL_Delay(5);
	return ack;
}
void SendData(unsigned char data)
{
	Start();
	SendByte(data);
	ReceiveAck();
	Stop();
}
