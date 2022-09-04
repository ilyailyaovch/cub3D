/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:33:01 by pleoma            #+#    #+#             */
/*   Updated: 2022/09/04 20:46:42 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int ft_mistake(char *arg)
{
    fprintf(stderr, RED "Error: " WTH);
    fprintf(stderr, "%s", arg);
    return(EXIT_FAILURE);
}