/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:56:17 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:56:17 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static int	len_first_word(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	fill_word(char *word, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (i);
}

static char	**fill_array(char **array, char const *s, char c, int word_count)
{
	int		arr_i;
	int		word_len;

	arr_i = 0;
	while (arr_i < word_count)
	{
		while (*s && *s == c)
			s++;
		word_len = len_first_word(s, c);
		array[arr_i] = malloc((word_len + 1) * sizeof(char));
		if (!array[arr_i])
		{
			while (arr_i > 0)
			{
				free(array[arr_i - 1]);
				arr_i--;
			}
			free(array);
			return (NULL);
		}
		s += fill_word(array[arr_i++], s, c);
	}
	array[arr_i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	array = malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (fill_array(array, s, c, word_count));
}
// #include <stdio.h>
// int main(void)
// {
// 	char **result;
// 	size_t i;
// 	result = ft_split("0,0,,,Hello,World,This,Is,A,Test", ',');
// 	if (!result)
// 	{
// 		printf("Ошибка выделения памяти!\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("Строка %zu: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
