#include <unistd.h> // For the write function

/**
 * main - Entry point of the program
 *
 * Return: Always 1
 */
int main(void)
{
    char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    write(2, message, 59);
    return 1;
}
