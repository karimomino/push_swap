/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:14 by kamin             #+#    #+#             */
/*   Updated: 2021/12/15 00:19:48 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/*ERROR HANDLING FUNCTIONS*/
int		ft_isnum(char *s);
int		check_input(int ac, char **av);
int		check_ione(char *av);
int		check_itwo(int ac, char **av);
void	print_errors(int error_code);

#endif
