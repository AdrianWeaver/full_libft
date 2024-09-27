/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:07:18 by aweaver           #+#    #+#             */
/*   Updated: 2024/09/27 15:07:38 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BST
# define T_BST

typedef struct s_bst
{
	void			*content;
	struct s_bst	*left;
	struct s_bst	*right;
}					t_bst;

# ifndef DELETENODES
#  define DELETENODES 1

#  endif
# endif
