#ifndef I2C_H
#define I2C_H

void Start(void);
void Stop(void);
void SendByte(unsigned char data);
unsigned char ReceiveAck(void);
void SendData(unsigned char data);

#endif
