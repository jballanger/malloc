/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:48:19 by jballang          #+#    #+#             */
/*   Updated: 2018/05/04 14:06:56 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define TINY 128
# define SMALL 2048
# define LARGE 0x0

# define TINY_MAX (8 * getpagesize())
# define SMALL_MAX (64 * getpagesize())
# define IS_TINY(x) (x <= TINY)
# define IS_SMALL(x) (x > TINY && x <= SMALL)
# define IS_LARGE(x) (x > SMALL)

# include "../libft/libft.h"

# include <sys/mman.h>

typedef struct		s_header
{
	size_t			size;
	void			*address;
	char			free;
	struct s_header	*next;
	struct s_header	*prev;
}					t_header;

typedef struct		s_page
{
	char			type;
	size_t			available;
	t_header		*blocks;
	struct s_page	*next;
	struct s_page	*prev;
}					t_page;

typedef struct		s_mem
{
	void			*root[2];
	size_t			ret[2];
	t_page			*pages;
}					t_mem;

t_mem				g_mem;

void				*malloc(size_t size);
void				free(void *ptr);
void				*realloc(void *ptr, size_t size);
void				*ft_alloc(size_t size);
void				*create_page(char type, size_t type_max, size_t size);
void				*create_large_page(size_t size);
t_page				*search_page(char type, size_t size);
void				*create_header(void **root, t_page *page, size_t size,\
	char free);
void				push_header(t_page *page, t_header *header);
void				*get_block(t_page *page, size_t size);
int					own_ptr(void *ptr);
void				show_pages();

#endif
