#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include "ft_printf.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <locale.h>
#include <limits.h>


int main()
{
	setlocale(LC_ALL, "");
	int a = 0;
	float d = 0.123456;
	char *str = "salut";

	a = printf("\n[% 0+-#10.o] [% 0+-#10.5o]\n", 42, 42);
	ft_putnbr(a);
	a = ft_printf("\n[% 0+-#10.o] [% 0+-#10.5o]\n", 42, 42);
	ft_putnbr(a);

	a = printf("\n[%.06s\\n] [%.09s\\n]\n", "c", "c");
	ft_putnbr(a);
	a = ft_printf("\n[%.06s] [%.09s]\n", "c", "c");
	ft_putnbr(a);

	a = printf("\n[%.09d\\n] [%.08d\\n]\n", 42, 42);
	ft_putnbr(a);
	a = ft_printf("\n[%.09d\\n] [%.08d\\n]\n", 42, 42);
	ft_putnbr(a);

	a = printf("\n[%10d\\n] [%d\\n]\n", 42000, 42000);
	ft_putnbr(a);
	a = ft_printf("\n[%10d\\n] [%d\\n]\n", 42000, 42000);
	ft_putnbr(a);

	a = printf("%+020i\n", 15);
	ft_putnbr(a);
	a = ft_printf("%+020i\n", 15);
	ft_putnbr(a);

	return(0);
}