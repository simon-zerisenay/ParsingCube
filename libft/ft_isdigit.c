/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen<szerisen@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:24:49 by szerisen          #+#    #+#             */
/*   Updated: 2023/09/23 18:19:13 by szerisen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int	ft_isdigit(int c)
// {
// 	if (c < '0' || c > '9')
// 		return (0);
// 	return (c);
// }

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

// int main(){
// 	printf("%c", ft_isdigit(':'));
// }