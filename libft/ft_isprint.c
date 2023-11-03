/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen<szerisen@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:27 by szerisen          #+#    #+#             */
/*   Updated: 2023/09/22 21:27:33 by szerisen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int	ft_isprint(int c)
// {
// 	if (c < 32 || c > 126)
// 		return (0);
// 	return (c);
// }

int	ft_isprint(int c)
{
	if (c >= 33 && c < 127)
		return (1);
	else
		return (0);
}

// int main()
// {
//    printf("%c", ft_isprint(' '));
// }