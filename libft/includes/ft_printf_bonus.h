/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:09 by eelissal          #+#    #+#             */
/*   Updated: 2024/12/09 15:34:22 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h> //during tests
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_flags
{
	bool	hashtag;
	bool	space;
	bool	plus;
	bool	right_padding;
	int		width;
	char	pad_char;
}	t_flags;

int		ft_strlen_bonus(const char *s);
char	*ft_strchr_bonus(const char *s, int c);
int		ft_putchar_bonus(int c);
int		ft_putstr_bonus(char *str);
int		ft_unsigned_bonus(unsigned int n);

int		ft_putnbr_bonus(int n, t_flags *flags, long ten_power, int count);
int		ft_putnbr_base_bonus(unsigned long n, char *base);
int		ft_puthexa_low_bonus(unsigned long n, t_flags *flags);
int		ft_puthexa_up_bonus(unsigned long n, t_flags *flags);
int		ft_ptrhexa_bonus(void *ptr);

void	ft_width(char conversion, t_flags *flags, va_list tmp_args);
int		ft_left_padding(t_flags *flags);
int		ft_right_padding(t_flags *flags);
int		ft_nbrlen(long long nbr);
int		ft_hexlen(long long nbr);

int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));

#endif