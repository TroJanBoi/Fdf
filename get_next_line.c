/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:10:05 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/04/26 15:10:05 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

char	*ft_readonly(int fd, char *word, char *stash)
{
	int		size;
	char	*tmp;

	size = read(fd, word, BUFFER_SIZE);
	printf("size : %d\n", size);
	while (size > 0)
	{
		if (size == -1)
			return (0);
		else if (size == 0)
			break ;
		word[size] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, word);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(word, '\n'))
			break ;
		size = read(fd, word, BUFFER_SIZE);
		printf("word : %s\n", word);
	}
	printf("done\n");
	return (stash);
}

unsigned int	ft_check_new_line(char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

static char	*ft_cut_line(char *line)
{
	char			*stash;
	unsigned int	start;

	start = ft_check_new_line(line);
	if (line[start] == '\0' || line[1] == '\0')
		return (0);
	stash = ft_substr(line, start + 1, ft_strlen(line) - start);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[start + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*word;
	char		*line;

	if (!stash)
		stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = (char *)malloc((BUFFER_SIZE + 1));
	if (!word)
		return (0);
	line = ft_readonly(fd, word, stash);
	free(word);
	word = NULL;
	if (!line)
		return (NULL);
	stash = ft_cut_line(line);
	return (line);
}

// // char	*line_dump(int fd)
// // {
// // 	char*buf[10];

// // 	while (read(fd, buf, 110) > 0)
// // 	{
// // 		printf("%s", buf);
// // 	}
// // 	return (NULL);
// // }

// int	main(void) {
// 	char *file = "read_error.txt";
// 	int fd;
// 	char *line;
// 	fd = open(file, O_RDONLY);
// 	int count;

// 	count = 0;
// 	while ((line = get_next_line(fd)) != NULL) {
// 		printf("[%d] %s", ++count, line);
// 		free(line);
// 	}
// 	// line = get_next_line(fd);
// 	// while(count++ < 5)
// 	// {
// 	// 	printf("-%s", line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd);
// 	// }

// 	// while (byte > 0)
// 	// {
// 	// 	byte = read(fd, line, BUFFER_SIZE);
// 	// 	printf("line : %s\n", line);
// 	// 	printf("byte : %d\n", byte);
// 	// }
// 	// line_dump(fd);

// 	// line = get_next_line(fd);
// 	// printf("3:%s", line);
// 	// printf("\n");
// 	// free(line);
// 	close(fd);
// 	return (0);
// }
