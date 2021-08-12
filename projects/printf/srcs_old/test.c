#include <stdio.h>
#include <string.h>

int main()
{
	int width = 10;
	int precision = 5;

    char temp_w[100];
    char temp[100];
    int x = 123;

    memset(temp, ' ', sizeof(temp));
	// memset(temp, '0', sizeof(temp));
    temp[99] = 0;
    
    int i = 98;
    while (x > 0) {
        temp[i--] = x % 10 + '0';
        x /= 10;
    }
    
    printf("%s\n", temp);
    return 0;
}