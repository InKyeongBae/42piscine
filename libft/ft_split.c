/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:41:49 by ibae              #+#    #+#             */
/*   Updated: 2022/01/18 16:41:52 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

void	free_ptr(char **s2, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(s2[i]);
		i++;
	}
	free(s2);
}

char	**ft_split_words(char const *s, char c, char **s2, int words_num)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < words_num)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (s2 == NULL)
		{
			free_ptr(s2, word);
			return (0);
		}
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	int		words_num;

	if (s == NULL)
		return (0);
	words_num = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (s2 == NULL)
		return (0);
	ft_split_words(s, c, s2, words_num);
	return (s2);
}
