#include <stdarg.h>
#include <unistd.h>

/**
 * print_d - Custom function to print integers
 * @args: va_list containing the integer to be printed
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int print_d(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    int divisor = 1;

    if (num < 0)
    {
        write(1, "-", 1);
        count++;
        num = -num;
    }

    while (num / divisor > 9)
        divisor *= 10;

    while (divisor != 0)
    {
        char digit = '0' + num / divisor;
        write(1, &digit, 1);
        count++;
        num %= divisor;
        divisor /= 10;
    }

    return count;
}

/**
 * print_i - Custom function to print integers
 * @args: va_list containing the integer to be printed
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int print_i(va_list args)
{
    return print_d(args);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++;
            switch (*ptr)
            {
            case 'd':
                count += print_d(args);
                break;
            case 'i':
                count += print_i(args);
                break;
            default:
                write(1, &(*ptr), 1);
                count++;
                break;
            }
        }
        else
        {
            write(1, &(*ptr), 1);
            count++;
        }
    }

    va_end(args);
    return count;
}

int main(void)
{
    int len;

    len = _printf("Let's try %d and %i format specifiers.\n", 42, -123);
    _printf("Length:[%d]\n", len);

    return (0);
}

