/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:58 by amayorga          #+#    #+#             */
/*   Updated: 2024/09/19 12:43:31 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		bytes;

	bytes = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	i_need_lines(format, args, &bytes);
	va_end(args);
	return (bytes);
}

void	i_need_lines(char const *format, va_list args, int *bytes)
{
	int	len;

	len = 0;
	while (format[len] != '\0')
	{
		if (format[len] == '%' && format[len + 1] == '\0')
		{
			va_end(args);
			*bytes = -1;
			return ;
		}
		else if (format[len] == '%')
		{
			len++;
			print_type(args, format[len], bytes);
		}
		else
			ft_putchar(format[len], bytes);
		len++;
	}
}

void	print_type(va_list args, char c, int *bytes)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), bytes);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), bytes);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), bytes);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), bytes);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), bytes);
	else if (c == 'x')
		ft_puthex_uint(va_arg(args, int), "0123456789abcdef", bytes);
	else if (c == 'X')
		ft_puthex_uint(va_arg(args, int), "0123456789ABCDEF", bytes);
	else if (c == '%')
		ft_putchar(c, bytes);
}

/*int main(void)
{
    //Caracter estandar
    int num1 = printf("Caracter estandar: %c\n", 'A');
    int num2 = ft_printf("Caracter estandar: %c\n", 'A');
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Caracter especial
    num1 = printf("Caracter especial: %c\n", '\n');
    num2 = ft_printf("Caracter especial: %c\n", '\n');
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Caracter nulo
    num1 = printf("Caracter nulo: %c\n", '\0');
    num2 = ft_printf("Caracter nulo: %c\n", '\0');
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Cadena estandar
    num1 = printf("Cadena estandar: %s\n", "Hello World");
    num2 = ft_printf("Cadena estandar: %s\n", "Hello World");
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Cadena vacia
    num1 //Caracter estandar
    int num1 = printf("Caracter estandar: %c\n", 'A');
    int num2 = ft_printf("Caracter estandar: %c\n", 'A');
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Caracter especial
    num1 = printf("Caracter especial: %c\n", '\n');
    num2 = ft_printf("Caracter especial: %c\n", '\n');
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Caracter nulo
    num1 = printf("Caracter nulo: %c\n", '\0');
    num2 = = printf("Cadena vacia: %s\n", "");
    num2 = ft_printf("Cadena vacia: %s\n", "");
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Cadena con caracteres especiales
    num1 = printf
	("Cadena caracteres especiales: %s\n", "Line1\nLine2\tTabbed");
    num2 = ft_printf
	("Cadena caracteres especiales: %s\n", "Line1\nLine2\tTabbed");
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Cadena nula
    num1 = printf("Cadena nula: %s\n", (char *)NULL);
    num2 = ft_printf("Cadena nula: %s\n", (char *)NULL);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Puntero nulo
    num1 = printf("Puntero nulo: %p\n", NULL);
    num2 = ft_printf("Puntero nulo: %p\n", NULL);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Puntero valido
    int x = 0;
    num1 = printf("Puntero valido: %p\n", (void *)&x);
    num2 = ft_printf("Puntero valido: %p\n", (void *)&x);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Numero positivo
    num1 = printf("Numero positivo: %d\n", 123456789);
    num2 = ft_printf("Numero positivo: %d\n", 123456789);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Numero negativo
    num1 = printf("Numero negativo: %d\n", -123456789);
    num2 = ft_printf("Numero negativo: %d\n", -123456789);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Numero maximo
    num1 = printf("Numero maximo: %d\n", INT_MAX);
    num2 = ft_printf("Numero maximo: %d\n", INT_MAX);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Numero minimo
    num1 = printf("Numero minimo: %d\n", INT_MIN);
    num2 = ft_printf("Numero maximo: %d\n", INT_MIN);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Simbolo porcentaje
    num1 = printf("Porcentaje: %%\n");
    num2 = ft_printf("Porcentaje: %%\n");
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Hexadecimal grande
    num1 = printf("Hexadecimal grande: %x\n", UINT_MAX);
    num2 = ft_printf("Hexadecimal grande: %x\n", UINT_MAX);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Hexadecimal negativo
    num1 = printf("Hexadecimal negativo: %x\n", INT_MIN);
    num2 = ft_printf("hexadecimal negativo: %x\n", INT_MIN);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Unsigned int max
    num1 = printf("unsigned int max: %x\n", UINT_MAX);
    num2 = ft_printf("unsigned int max: %x\n", UINT_MAX);
    printf("Bytes: %i\t%i\n\n", num1, num2);

    //Unsigned int min
    num1 = printf("unsigned int min: %x\n", 0);
    num2 = ft_printf("unsigned int min: %x\n", 0);
    printf("Bytes: %i\t%i\n\n", num1, num2);

}*/
