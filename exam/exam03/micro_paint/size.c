#include <stdio.h>

typedef struct s_config
{
    char    background;
    int     width;
    int     height;
}   t_config;

typedef struct s_shape
{
    char    type;
    float   y;
    char   c;
    float   x;
    float   width;
    float   height;
}   t_shape;

int main(void)
{
    // int ret_scanf;
    // char    *buff;
    // t_config    config;
    // t_shape    shape;
    FILE *file;

    // printf("the size of int :   %ld\n", sizeof(ret_scanf));
    // printf("the size of char* : %ld\n", sizeof(buff));
    // printf("the size of config : %ld\n", sizeof(config));
    // printf("the size of shape : %ld\n", sizeof(shape));
    printf("the size of file : %ld\n", sizeof(file));
}