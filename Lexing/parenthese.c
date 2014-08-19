/*
** parenthese.c for parenthese in /home/odet_a
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Thu Oct 24 13:47:49 2013 
** Last update Fri Nov  8 17:11:39 2013 
*/

#include "../bistromathique.h"

int	parentheses(char *str, char *op)
{
  int	i;
  int	nb_p_o;
  int	nb_p_f;

  i = 0;
  nb_p_o = 0;
  nb_p_f = 0;
  while (str[i])
    {
      if (str[i] == op[0])
	nb_p_o++;
      if (str[i] == op[1])
	nb_p_f++;
      if (nb_p_o < nb_p_f)
	{
	  my_putstr(SYNTAXE_ERROR_MSG);
	  return (1);
	}
      i++;
    }
  if ((nb_p_o + nb_p_f) % 2 == 0)
    return (0);
  my_putstr("Il n'y a pas le bon nombre de parentheses\n");
  return (1);
}
