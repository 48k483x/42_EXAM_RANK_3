#include <stdarg.h>
#include <unistd.h>

void	_putstr(char *s, int *length)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		*length += write(1, s++, 1);
}

void	_putdigit(long long int num, int base, int *length)
{
	char *bases = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		length += write(1, "-", 1);
	}
	if (num >= base)
		_putdigit(num / base,  base, length);
	*length += write(1, &bases[num % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int	length = 0;

	va_list list;
	va_start(list, format);
	
	while (*format)
	{
		if ((*format == '%') && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				_putstr((va_arg(list, char *)), &length);
			if (*format == 'd')
				_putdigit((long long int)va_arg(list, int), 10, &length);
			if (*format == 'x')
				_putdigit((long long int)va_arg(list, unsigned int), 16, &length);

		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(list), length);
}

/*#include <stdio.h>
int main(void)
{
	char *s = "0123456789abcdef";
	int	age = 20;
	printf("hado diawli\n");
	ft_printf("hello this the hexadecimals bases = %s\n, and this is my age in int %d\n, and in hexa %x\n", s, age, age);
	ft_printf("%d\n", ft_printf("hello this the hexadecimals bases = %s\n, and this is my age in int %d\n, and in hexa %x\n", s, age, age));
	
	printf("hadi dialhom lassllia\n");
	printf("hello this the hexadecimals bases = %s\n, and this is my age in int %d\n, and in hexa %x\n", s, age, age);
	printf("%d\n", printf("hello this the hexadecimals bases = %s\n, and this is my age in int %d\n, and in hexa %x\n", s, age, age));
}*/
