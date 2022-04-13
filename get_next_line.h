#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list_char
{
	char				content;
	struct s_list_char	*next;
}	t_list_char;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

t_list_char	*ft_lstnew_char(char content);
t_list_char	*ft_lstlast(t_list_char *lst);
void				ft_lstadd_back(t_list_char **lst, t_list_char *new);
#endif
