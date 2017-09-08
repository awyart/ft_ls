/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:37:22 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 10:21:50 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define INT_MIN	-2147483648
# define BUFF_SIZE	4096
# define OPTIONS "sSpdDioOuUxXcCbBIfFnN%"
# define AH content
# define FLAG1	"#+- 0"
# define FLAG2	"lhjzt."
# define NB_OPTIONS	22
# define ULL unsigned long long
# define LL long long

typedef struct			s_flag
{
	int					len;
	char				flag_type;
	int					flag_len;
	int					nb_type;
	int					width;
	int					precision;
	int					count;
	int					flags[128];
}						t_flag;

typedef struct			s_next
{
	char				status[1];
	void				(*f)(t_flag *flag, char content[BUFF_SIZE]);
}						t_next;

typedef struct			s_conv
{
	char				status[1];
	void				(*f)(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
}						t_conv;

void					ft_putchar(char c);
int						ft_putchar_unicode(unsigned int c);
void					ft_putnchar(int n, char c);
void					ft_putstr(char const *s);
size_t					ft_strlen(const char *s);
size_t					ft_strlen_unicode(wchar_t *s);
char					*ft_strchr(const char *s, int c);
void					ft_itoa(long long value, char str[BUFF_SIZE]);
void					ft_itoab_ll(unsigned long long value,
								int base, char str[BUFF_SIZE]);
void					ft_itoab_l(long long value,
								int base, char str[BUFF_SIZE]);
void					ft_down(char *str);
int						ft_isdigit(int c);
int						ft_pops(int c);
char					*ft_strcpy(char *dst, const char *src);
long long				ft_ent(double x);
long long				ft_ent_l(long double x);
long long				ft_ent_m(double x);
long long				ft_ent_ml(long double x);

int						ft_printf(char *str, ...);

int						ft_get_flag(char *format, t_flag *flag,
						va_list *ap, char content[BUFF_SIZE]);
void					conv_s(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_sm(t_flag *flag, va_list *ap,
						char *content);
void					conv_d(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_dm(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_p(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_o(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_om(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_u(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_um(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_x(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_xm(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_b(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_f(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_fm(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_bm(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_c(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_cm(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_n(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_nm(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_im(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);
void					conv_per(t_flag *flag, va_list *ap,
						char content[BUFF_SIZE]);

void					ft_s(t_flag *flag, char content[BUFF_SIZE]);
void					ft_sm(t_flag *flag, wchar_t *content);
void					ft_p(t_flag *flag, char content[BUFF_SIZE]);
void					ft_d(t_flag *flag, char content[BUFF_SIZE]);
void					ft_o(t_flag *flag, char content[BUFF_SIZE]);
void					ft_u(t_flag *flag, char content[BUFF_SIZE]);
void					ft_c(t_flag *flag, char c);
void					ft_cm(t_flag *flag, int s);
void					ft_b(t_flag *flag, char content[BUFF_SIZE]);
void					ft_bm(t_flag *flag, char content[BUFF_SIZE]);
void					ft_x(t_flag *flag, char content[BUFF_SIZE]);
void					ft_xm(t_flag *flag, char content[BUFF_SIZE]);
void					assign_long(t_flag *flag, long *a);
unsigned int			ft_countbits(unsigned int c);
void					ft_f(t_flag *flag, char content[BUFF_SIZE],
							char ct[BUFF_SIZE]);

#endif
