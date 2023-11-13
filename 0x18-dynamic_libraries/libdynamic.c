#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int _abs(int n)
{
    return (n < 0 ? -n : n);
}

int _isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int _strlen(char *s)
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}

void _puts(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        _putchar(s[i]);
        i++;
    }
}

char *_strcpy(char *dest, char *src)
{
    /* Implement _strcpy function */
    return dest;
}

int _atoi(char *s)
{
    /* Implement _atoi function */
    return 0;
}

char *_strcat(char *dest, char *src)
{
    /* Implement _strcat function */
    return dest;
}

char *_strncat(char *dest, char *src, int n)
{
    /* Implement _strncat function */
    return dest;
}

char *_strncpy(char *dest, char *src, int n)
{
    /* Implement _strncpy function */
    return dest;
}

int _strcmp(char *s1, char *s2)
{
    /* Implement _strcmp function */
    return 0;
}

char *_memset(char *s, char b, unsigned int n)
{
    /* Implement _memset function */
    return s;
}

char *_memcpy(char *dest, char *src, unsigned int n)
{
    /* Implement _memcpy function */
    return dest;
}

char *_strchr(char *s, char c)
{
    /* Implement _strchr function */
    return NULL;
}

unsigned int _strspn(char *s, char *accept)
{
    /* Implement _strspn function */
    return 0;
}

char *_strpbrk(char *s, char *accept)
{
    /* Implement _strpbrk function */
    return NULL;
}

char *_strstr(char *haystack, char *needle)
{
    /* Implement _strstr function */
    return NULL;
}
