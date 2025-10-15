#include <stdio.h>
enum {
	GPIO_Speed_2MHz,
	GPIO_Speed_10MHz,
	GPIO_Speed_50MHz,
};
struct GPIO {
	int GPIO_Speed;
};
static void GPIO_StructureInit(struct GPIO* ps);
int main()
{
	struct GPIO s ={};
	GPIO_StructureInit(&s);
	return 0;
}
static void GPIO_StructureInit(struct GPIO*ps)
{
	ps-> GPIO_Speed= GPIO_Speed_2MHz;
}
