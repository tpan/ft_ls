/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 08:18:32 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:28:15 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define INVALID	1
# define VALID	0

typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;

typedef struct		s_flags
{
	t_bool	hash;
	t_bool	pos_values_append_space;
	t_bool	show_sign;
	t_bool	left_justify;
	t_bool	pad_zeros;
}					t_flags;

typedef	struct		s_format
{
	const char	*str;
	size_t		index;
	size_t		chars_written;
}					t_format;

typedef enum		e_length
{
	DEFAULT, HH, H, L, LL, J, Z
}					t_length;

typedef enum		e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER,
	INVALID_SPECIFIER, CHARS_WRITTEN
}					t_specifier;

typedef struct		s_conversion
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	t_bool			int_negative;
	t_bool			precision_set;
	t_length		length;
	t_specifier		specifier;
}					t_conversion;

int					read_flags(t_conversion *conversion, t_format *format);
int					read_length(t_conversion *conversion, t_format *format);
int					read_precision(t_conversion *conversion, va_list ap,
					t_format *format);
int					read_specifier(t_conversion *conversion, t_format *format);
int					read_width(t_conversion *conversion, va_list arguments,
					t_format *format);
int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
void				apply_width_wchar(t_conversion *conversion,
					wchar_t **draft);
void				apply_precision(t_conversion *conversion, char **draft);
void				apply_prefix(t_conversion *conversion, char **draft);
void				apply_width(t_conversion *conversion, char **draft);
int					compatible_flags(t_conversion *conversion,
					t_format *format);
void				write_conversion_substring(t_conversion *conversion,
					va_list ap, t_format *format);
int					verify_flag_compatibility(t_conversion *conversion);
void				write_chars(t_conversion *conversion, va_list ap,
					t_format *format);
void				write_string(t_conversion *conversion, va_list ap,
					t_format *format);
void				write_hex(t_conversion *conversion, va_list ap,
					t_format *format);
void				write_octal(t_conversion *conversion, va_list ap,
					t_format *format);
void				write_signed_int(t_conversion *conversion, va_list ap,
					t_format *format);
uintmax_t			get_unsigned_int_arg(t_conversion *conversion, va_list ap);
void				write_unsigned_int(t_conversion *conversion, va_list ap,
					t_format *format);
void				write_wchar(t_conversion *conversion, va_list ap,
					t_format *format);
void				write_wstring(t_conversion *conversion, va_list ap,
					t_format *format);
void				apply_precision_wstr(t_conversion *conversion,
					wchar_t **draft);
void				fix_sign(t_conversion *conversion, char **draft);
void				store_chars_written(va_list ap, t_format *format);

#endif
