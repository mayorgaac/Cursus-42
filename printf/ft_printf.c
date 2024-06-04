/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:58 by amayorga          #+#    #+#             */
/*   Updated: 2024/03/19 21:51:54 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args, format);

	while(*format)
	{
		char c = define_type(format);
		if(c == 'c')
		{
			char caracter = va_arg(args, char);
			ft_putchar(caracter);
		}
		else if( c == 's')
		{
			char *str = va_arg(args, char *);
			ft_putstr(str);
		}
		else if (c == 'p')
		{
			void *ptr = va_arg(args, void *);
			//imprimir puntero
		}
		else if (c == 'd')
		{
			int number = va_arg(args, int);
			//imprimir numero decimal en base 10
		}
		else if (c == 'i')
		{
			int number = va_arg(args, int);
			//imprimir numero entero en base 10
		}
		else if (c == 'u')
		{
			int number = va_arg(args, int);
			//imprimir numero decimal en base 10 sin signo
		}
		else if (c == 'x')
		{
			int number = va_arg(args, int);
			//imprimir numero hexadecimal en minusculas
		}
		else if (c == 'X')
		{
			int number = va_arg(args, int);
			//imprimir numero hexadecimal en mayusculas
		}
		else if (c == '%')
			ft_putchar(c);
		else if (c == '\0')
			 //CADENA FORMATO FINALIZADA
		else
			//ERROR

	}
	
	//Lectura de la cadena de formato
	//Busqueda del caracter de formato %
	//Interpretacion del especificador de formato %d | %f | %...
	//Extraccion de argumento

	//Repeticion del proceso hasta acabar la cadena de formato

	//Manejo de errores
	//Impresion de caracteres normales
}

char define_type(char const *format)
{
	int i;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			*format++;
			return *format;
		}else
			ft_putchar(*format);
		format++;
	}
	return '\0';
}

/* MANEJO DE ERRORES

1. Especificador de formato incorrecto (%z por ejemplo)
2. Argumentos faltantes
3. Argumentos sobrantes
4. Especificadores de formato con longitud (Comprobar si habria que manejar esto)
5. Manejar caracteres de escape e imprimirlos bien ( \n - \r - \t ...)
6. Errores de conversion

*/

/* ESPECIFICADORES DE FORMATO 
	%c Imprime un solo carácter.
	%s Imprime una string (como se define por defecto en C).
	%p El puntero void * dado como argumento se imprime en formato hexadecimal.
	%d Imprime un número decimal (base 10).
	%i Imprime un entero en base 10.
	%u Imprime un número decimal (base 10) sin signo.
	%x Imprime un número hexadecimal (base 16) en minúsculas.
	%X Imprime un número hexadecimal (base 16) en mayúsculas.
	% % para imprimir el símbolo del porcentaje
*/
