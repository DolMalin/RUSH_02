
#include "libft.h"

void    *malloc_gc(t_list **gc, size_t size)
{
    void    *malloc_ptr;

    malloc_ptr = malloc(size);
    if (!malloc_ptr)
        ft_error(*gc);
    ft_lstadd_front(gc, ft_lstnew(malloc_ptr));
    return (malloc_ptr);
}
