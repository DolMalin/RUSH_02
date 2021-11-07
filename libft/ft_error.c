
#include "libft.h"

int    ft_error(t_list *gc)
{
    write(2, "Error\n", 6);
    ft_lstclear(&gc, free);
    exit(EXIT_FAILURE);
    return (0);
}

int    ft_error_msg(t_list *gc, char *msg)
{
	ft_printf(2, "Error: %s", msg);
	ft_lstclear(&gc, free);
	exit(EXIT_FAILURE);
	return (0);
}