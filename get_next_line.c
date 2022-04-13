#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_list_char	*letters;
	int			count;
	int			aux;
	char		*nextline;
	t_list_char	*new;
	static char	*string[256 + 1];
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 )
		return (NULL);	
	if (!string[fd]){
		string[fd] = ft_strdup("");
	}
	if (read(fd, string[fd], BUFFER_SIZE) < 0)
	{
			//  printf("Entrou aqui\n");
		free(string[fd]);
		string[fd] = NULL;
		return (NULL);
	}
	// erro na leitura string fd, talvez observar como pegar obj
	//printf("$%s\n",string[fd]);
	if (string[fd][0] == '\0')
	{
		free(string[fd]);
		string[fd] = NULL;
		return (NULL);
	}
	letters = NULL;
	count = 0;

	
	aux = 0;
	
	while ((string[fd])[aux] != '\n')
	{
		//new = ft_lstnew_char((string[fd])[aux++]);
		new = ft_lstnew_char((string[fd])[aux]);
		string[fd] = ft_strdup(&(string[fd][1]));
		ft_lstadd_back(&(letters), new);
		count++;
		if ((string[fd])[aux] == '\0')
		{	
			if (read(fd, string[fd], BUFFER_SIZE) < 0){
				free(string[fd]);
				string[fd] = NULL;
				free(letters);
				letters = NULL;
				return NULL;}
			aux = 0;
		}
	}
		printf("1TESTE\n");
	count++;
	while ((string[fd])[aux] != '\n')
		aux++;
		
	(string[fd]) = ft_strchr((string[fd]), '\n');
	if (string[fd][aux] == '\n')
		printf("2TESTE\n");
	
	new = ft_lstnew_char((string[fd])[0]);
	string[fd] = ft_strdup(&(string[fd][1]));
	ft_lstadd_back(&(letters), new);
	free (new);
	new = NULL;
	
	nextline = malloc(count + 1);
	if(!nextline){
		free(string[fd]);
		string[fd] = NULL;
		free(letters);
		letters = NULL;
		return NULL;
	}
	aux = 0;
	while (letters != NULL)
	{
		nextline[aux++] = letters->content;
		letters = letters->next;
	}

	nextline[count] = '\0';
	free (letters);
	letters = NULL;
	return (nextline);
	// return NULL;
}
