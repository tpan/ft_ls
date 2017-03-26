/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:19:52 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:08:40 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		generate_base_digit_array(char *arr)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		arr[i] = i + 'A' - 10;
		i++;
	}
}

static int		calc_indices(int *indices, unsigned int value, int base)
{
	int		i;

	i = 0;
	while (value != 0)
	{
		indices[i++] = value % base;
		value = value / base;
	}
	return (--i);
}

static char		*create_base_str(char *digits, int *indices, int i, int value)
{
	int		j;
	char	*result;

	result = (char *)malloc((i + (value < 0 ? 3 : 2)) * sizeof(char));
	j = 0;
	if (value < 0)
		result[j++] = '-';
	while (i >= 0)
		result[j++] = digits[indices[i--]];
	result[j] = '\0';
	return (result);
}

char			*ft_itoa_base(int value, int base)
{
	char			base_digits[16];
	int				conversion_index[64];
	int				i;
	unsigned int	abs_val;

	if (value == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	abs_val = (value < 0 ? -value : value);
	generate_base_digit_array(base_digits);
	i = calc_indices(conversion_index, abs_val, base);
	return (create_base_str(base_digits, conversion_index, i, value));
}
