#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t len;
    len = 0;
    if (str[0] == '\0')
        return(len);
    while(str[len] != '\0')
    {
        len++;
    }
    return (len);
}