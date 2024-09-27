/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:35:26 by daniema3          #+#    #+#             */
/*   Updated: 2024/09/27 15:35:27 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	gnl_strchr(char *str, char ch)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strdup(char *original)
{
	char	*dup;
	int		i;

	if (original == NULL)
		return (NULL);
	i = 0;
	dup = malloc((gnl_strlen(original) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (original[i] != '\0')
	{
		dup[i] = original[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (str != NULL)
	{
		while (s1[i] != '\0')
		{
			str[i + j] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
	}
	free(s1);
	return (str);
}

char	*gnl_substr(char *str, int start, int max)
{
	char	*sub;
	int		len;
	int		i;

	if (str == NULL)
		return (NULL);
	if (start > gnl_strlen(str))
		return (gnl_strdup(""));
	len = gnl_strlen(&str[start]);
	if (len < max)
		max = len;
	sub = malloc((max + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < max)
	{
		sub[i] = str[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
