/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtp_free_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:09:21 by mkhabou           #+#    #+#             */
/*   Updated: 2021/09/15 15:09:24 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtp_free_tabs(char **tab1, char **tab2, char **tab3, char **tab4)
{
	ft_free_tab(tab1);
	ft_free_tab(tab2);
	ft_free_tab(tab3);
	ft_free_tab(tab4);
}
