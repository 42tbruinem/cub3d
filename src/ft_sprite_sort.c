/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 13:25:32 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 14:16:37 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_copy_arr(int *dst, int *src, int start, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[start + i];
		i++;
	}
}

double		ft_distget(t_data *data, int *index, int id)
{
	return (data->mapdata.sprites[index[id]].dist);
}

void		ft_sort(int *left, int *right, t_data *data, t_merger *merge)
{
	int	l;
	int	r;
	int	i;

	i = merge->left;
	r = 0;
	l = 0;
	while (l < merge->lsize && r < merge->rsize)
	{
		if (ft_distget(data, left, l) >= ft_distget(data, right, r))
		{
			data->mapdata.indices[i] = left[l];
			l++;
		}
		else
		{
			data->mapdata.indices[i] = right[r];
			r++;
		}
		i++;
	}
	ft_copy_arr(data->mapdata.indices + i, left, l, merge->lsize - l);
	ft_copy_arr(data->mapdata.indices + i, right, r, merge->rsize - r);
}

static void	ft_free_tmps_and_exit(t_data *data, int *right,
			int *left, char *errstr)
{
	free(left);
	free(right);
	exit(ft_error(data, errstr, -1));
}

void		ft_merge_sort(t_data *data, int s, int e)
{
	t_merger	merge;
	int			*right;
	int			*left;

	if (s >= e)
		return ;
	merge.middle = s + (e - s) / 2;
	merge.lsize = merge.middle - s + 1;
	merge.rsize = e - merge.middle;
	merge.left = s;
	merge.right = e;
	right = malloc(sizeof(int) * (merge.lsize + 1));
	left = malloc(sizeof(int) * (merge.rsize + 1));
	if (!right || !left)
		ft_free_tmps_and_exit(data, right, left, ERR_STR_MEM);
	ft_merge_sort(data, s, merge.middle);
	ft_merge_sort(data, merge.middle + 1, e);
	ft_copy_arr(left, data->mapdata.indices, merge.left, merge.lsize);
	ft_copy_arr(right, data->mapdata.indices, merge.middle + 1, merge.rsize);
	ft_sort(left, right, data, &merge);
	free(right);
	free(left);
}
