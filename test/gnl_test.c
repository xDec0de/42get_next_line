/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:25:26 by daniema3          #+#    #+#             */
/*   Updated: 2024/12/14 19:19:32 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <string.h>

#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define RESET	"\x1b[0m"

unsigned int	get_digits(long nb)
{
	size_t	digits;

	digits = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		digits++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		digits++;
	}
	return (digits);
}

int	free_test(FILE *file, char *fgets_res, char *gnl_line, int fd, int code)
{
	if (fgets_res != NULL)
		free(fgets_res);
	if (gnl_line != NULL)
		free(gnl_line);
	close(fd);
	fclose(file);
	return (code);
}

int	gnl_test(char *file_path)
{
	FILE	*file;
	int		fd;
	char	*gnl_line;
	char	fgets_line[BUFFER_SIZE];
	char	*fgets_res;

	file = fopen(file_path, "r");
	fd = open(file_path, O_RDONLY);
	if (file == NULL || fd < 0)
		return (-1);
	while (1)
	{
		fgets_res = fgets(fgets_line, BUFFER_SIZE, file);
		gnl_line = get_next_line(fd);
		if (gnl_line == NULL && fgets_res != NULL)
			return (-2);
		if (fgets_res == NULL && gnl_line != NULL)
			return (-3);
		if (fgets_res == NULL && gnl_line == NULL)
			return (0);
		if (strcmp(fgets_line, gnl_line) != 0)
			return (free_test(file, fgets_res, gnl_line, fd, -1));
	}
	return (free_test(file, fgets_res, gnl_line, fd, 0));
}

int	main(void)
{
	char	*file_path;
	int		test;
	int		code;

	test = 1;
	while (test < 2)
	{
		file_path = calloc(6 + get_digits(test), sizeof(char));
		sprintf(file_path, "test/%d", test);
		code = gnl_test(file_path);
		if (code == 0)
			printf(GREEN "Test %d: OK :D" RESET "\n", test);
		else if (code == -1)
			printf(RED "Test %d: Couldn't open file" RESET "\n", test);
		else
			printf(RED "Test %d: "RED"KO :(" RESET "\n", test);
		free(file_path);
		test++;
	}
}
