#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	s_size;

	s_size = ft_strlen(s);
	copy = malloc(s_size + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s, s_size);
	copy[s_size] = '\0';
	return (copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	aux;

	if (!dest && !src)
		return (NULL);
	aux = 0;
	while (aux < n)
	{
		((char *)dest)[aux] = ((char *)src)[aux];
		aux++;
	}
	return (dest);
}


char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s != '\0')
	{
		if ((unsigned char)c == *s)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

t_list_char	*ft_lstnew_char(char content)
{
	t_list_char	*aux;

	aux = malloc(sizeof(t_list_char));
	if (!aux)
		return (NULL);
	aux->content = content;
	aux->next = NULL;
	return (aux);
}

t_list_char	*ft_lstlast(t_list_char *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		if (count < 10)
			count++;
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list_char **lst, t_list_char *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
