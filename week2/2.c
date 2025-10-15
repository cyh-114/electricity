#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() 
{
	while (1)
	{
		int num;
		scanf("%d", &num);
		if (num == -1)
		{
			break;
		}
		else if (num == 0)
		{
			printf("helloworld\n");
		}
		else if (num == 1)
		{
			printf("HELLOWORLD\n");
		}
	}
	return 0;
}
