/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:11:32 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 16:42:52 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
}	t_stack;

int				sa(t_stack **list);
int				sb(t_stack **list);
int				ss(t_stack **a, t_stack **b);
int				pa(t_stack **a, t_stack **b);
int				pb(t_stack **a, t_stack **b);
int				ra(t_stack **a);
int				rb(t_stack **b);
int				rr(t_stack **a, t_stack **b);
int				rra(t_stack **a);
int				rrb(t_stack **b);
int				rrr(t_stack **a, t_stack **b);
int				get_numbers(int argc, char **argv, long long *nbrs);
void			swap(int *arr1, int *arr2);
int				sort_array(t_stack *a, int *median1,
					int *median2, int *median3);
t_stack			*rotate_a(t_stack **a);
int				balance_stack(t_stack **a, t_stack **b,
					int med_min, int med_max);
int				find_max_or_min(t_stack **stack_b, int *rra_flag,
					int *rb_rrb_flag);
int				b_to_a(t_stack **stack_a, t_stack **stack_b);
int				check_already_sorted(t_stack *ref_stack);
int				ft_max(unsigned int nbr1, unsigned int nbr2);
int				ft_min(int nbr1, int nbr2);
void			ft_print(t_stack *ref_list);
unsigned int	len_list(t_stack *ref_list);
int				sort_2(t_stack	**ref_stack_a);
int				sort_3(t_stack	**ref_stack_a);
int				sort_4(t_stack	**ref_stack_a);
int				sort_5(t_stack	**ref_stack_a);
int				sort_mid(t_stack	**stack_a);
int				sort_big(t_stack	**stack_a);

#endif
