/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:21:14 by khtran            #+#    #+#             */
/*   Updated: 2018/01/27 23:24:34 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <wchar.h>
#include <locale.h>

int		main(int ac, char *av[])
{
	int		ret;

	ret = 0;
	(void)ac;
	(void)av;
/*	while (ret < 1000000)
	{
		ft_printf("test %d, retest %.4s\n", 42, "AHAHAHAHA");
		ret++;
	}*/
/*	ret = printf("nbr :%20x\n", 23322330);
	printf("%d\n", ret);
	ret = ft_printf("nbr :%20x\n", 23322330);
	printf("%d\n", ret);

	ret = printf("%.15s is a string\n", "1234567890");
	printf("%d\n", ret);
	ret = ft_printf("%.15s is a string\n", "1234567890");
	printf("%d\n", ret);
*/
	wchar_t *test;
/*	test[0] = 0x53;
	test[1] = 0xd800;
	test[2] = 0x81000;
	test[3] = '\0';
	setlocale(LC_ALL, "");
	ret = printf("%S", test);
	printf(" %d\n", ret);
	ret = ft_printf("%S", test);
	printf(" %d\n", ret);*/
	printf("%d\n", MB_CUR_MAX);
/*	ret = printf("coco et %-#-#--24O titi%#015o", 12, -874);
	printf(" %d\n", ret);
	ret = ft_printf("coco et %-#-#--24O titi%#015o", 12, -874);
	printf(" %d\n", ret)*/;
/*	ret = printf("{%.x}\n", 12);
	printf(" %d\n", ret);
	ret = ft_printf("{%.x}\n", 12);
	printf(" %d\n", ret);*/
	setlocale(LC_ALL, "");
//	test = L"我是一只猫";
/*	ret = printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	printf("\nret = %d\n", ret);
	ret = ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	printf("\nret = %d\n", ret);*/
/*	wchar_t	s[4];

	s[0] = 'a';
	s[1] = 256;
	s[2] = 'u';
	s[3] = '\0';
	ret = printf("test = %S\n", s);
	printf("\nret = %d\n", ret);
	ret = ft_printf("test = %S\n", s);
	printf("\nret = %d\n", ret);*/
//	ft_printf("%9.6lstest %S\n", s, (wchar_t*)"a");
//	test = L"test";
	printf("%d\n", MB_CUR_MAX);
	ret = printf("[MINE] = hello %s %c ..! %d \n", "World", '\0', 42);
	printf("\n%d\n", ret);
	ret = ft_printf("[MINE] = hello %s %c ..! %d \n", "World", '\0', 42);
	printf("\n%d\n", ret);
//L"我是一只猫
	return (0);
}
