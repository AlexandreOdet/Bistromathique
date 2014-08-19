/*
** my_str_to_chain.c for my_str_to_chain in /home/thibaut.lopez/Piscine-C-eval_expr
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Oct 25 09:16:14 2013 Thibaut Lopez
** Last update Sat Nov  9 18:19:07 2013 
*/

#include "../bistromathique.h"

int	strlen_1word(char *str, char *op)
{
  int	i;

  i = 0;
  if (str[i] == op[0] || str[i] == op[1] || str[i] == op[2] ||
      str[i] == op[3] || str[i] == op[4] || str[i] == op[5] || str[i] == op[6])
    i++;
  else
    {
      while (str[i] != op[0] && str[i] != op[1] && str[i] != op[2] &&
	     str[i] != op[3] && str[i] != op[4] && str[i] != op[5] && str[i] != op[6])
	i++;
    }
  return (i);
}

char	*my_strldup(char *src, int nb, char *op)
{
  char	*dest;
  
  dest = xmalloc(sizeof(char) * (strlen_1word(src, op) + 1));
  dest = my_strncpy(dest, src, nb);
  dest[strlen_1word(src, op)] = 0;
  return (dest);
}

int	my_put_in_2list(t_chain **list, char *str, char *op)
{
  t_chain	*elem;
  char		*dup;

  dup = my_strldup(str, strlen_1word(str, op), op);
  elem = xmalloc(sizeof(*elem));
  elem->str = dup;
  elem->prev = *list;
  elem->next = NULL;
  if (*list != NULL)
    (*list)->next = elem;
  *list = elem;
  return (0);
}

int	lentab(char *str, char *op)
{
  int	i;
  int	nbr_word;
  int	bool;

  i = 0;
  nbr_word = 0;
  bool = 0;
  while (str[i] != '\0')
    {
      if (str[i] == op[0] || str[i] == op[1] || str[i] == op[2] ||
	  str[i] == op[3] || str[i] == op[4] || str[i] == op[5] || str[i] == op[6])
	{
	  nbr_word++;
	  bool = 0;
	}
      else
	{
	  bool++;
	  if (bool == 1)
	    nbr_word++;
	}
      i++;
    }
  return (nbr_word);
}

t_chain	*my_str_to_chain(char *str, char *op)
{
  int		tmp;
  int		j;
  t_chain	*first;
  t_chain	*list;

  j = 0;
  first = NULL;
  list = NULL;
  tmp = lentab(str, op);
  if (tmp < 3)
    my_error(1);
  while (j != tmp)
    {
      my_put_in_2list(&list, str, op);
      if (first == NULL)
	first = list;
      str = str + strlen_1word(str, op);
      j++;
    }
  return (first);
}
