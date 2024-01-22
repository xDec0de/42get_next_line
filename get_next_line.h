/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:33:02 by danimart          #+#    #+#             */
/*   Updated: 2024/01/22 13:48:56 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# pragma once

# define GET_NEXT_LINE_H
# define FD_SIZE 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

/* get_next_line_utils.c */

/**
 * @brief Gets the length of a string (str).
 * 
 * @param str the string to use.
 * 
 * @return The length of str. 0 if str is NULL.
 */
int		gnl_strlen(char *str);

/**
 * @brief Finds a char (ch) on a string (str).
 * 
 * @param str the string to use.
 * @param ch the char to find.
 * 
 * @return The index of the first occurence of ch
 * in str if found. -1 if ch isn't present on str
 * or if str is NULL.
 */
int		gnl_strchr(char *str, char ch);

/**
 * @brief Creates a duplicate of a string (str).
 * 
 * @param original the string to duplicate.
 * 
 * @return The duplicate of the original string. This
 * may be NULL if original was NULL or if malloc failed
 */
char	*gnl_strdup(char *original);

/**
 * @brief Joins two strings, or, in other words, appends the
 * content of s1 to s2.
 * 
 * @param s1 the first string to join.
 * @param s2 the second string to join.
 * 
 * @return s1 with the contents of s2 added to the end of it.
 * NULL malloc fails or if s1 or s2 are NULL.
 */
char	*gnl_strjoin(char *s1, char *s2);

/**
 * @brief Gets a substring from a string (str). This substring
 * will be a dumplicate of str, starting to copy the contents
 * of it at the specified position (start), so any previous content
 * to the start index is ignored. The maximum length of the substring
 * is also limited by max.
 * 
 * @param str the original string that will be used to get
 * a substring from.
 * @param start the starting position of the substring.
 * @param max the maximum length of the substring.
 * 
 * @return A substring of str starting at the specified index (start),
 * limited to a maximum length (max). NULL if malloc fails or str is NULL.
 */
char	*gnl_substr(char *str, int start, int max);

/* get_next_line.c */

/**
 * @brief Gets the next line of the file with the specified
 * file descriptor (fd). This function is capable of reading from
 * multiple files at the same time while "remembering" what the next line
 * should be for each file. Note that this function considers a line
 * any content before a '\\n' character.
 * 
 * @param fd the file descriptor to use to read the contents of the file.
 * 
 * @return The next line of the file. NULL will be returned if the end
 * of the document is reached or if any error occurred.
 */
char	*get_next_line(int fd);

#endif
