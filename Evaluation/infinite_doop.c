/*
** infinite_doop.c for infinite_doop in /home/odet_a/rendu/Bistro/Evaluation
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Fri Nov  1 17:11:25 2013 
** Last update Sat Nov  9 18:40:35 2013 
*/

#include "../bistromathique.h"

t_ptr	**fill_tab(char *op)
{
  t_ptr	**tab;

  tab = xmalloc(sizeof(t_ptr*) * 6);
  tab[0] = xmalloc(sizeof(t_ptr));
  tab[0]->op = op[2];
  tab[0]->ptr = &infinite_add;
  tab[1] = xmalloc(sizeof(t_ptr));
  tab[1]->op = op[3];
  tab[1]->ptr = &infinite_sub;
  tab[2] = xmalloc(sizeof(t_ptr));
  tab[2]->op = op[4];
  tab[2]->ptr = &infinite_mul;
  tab[3] = xmalloc(sizeof(t_ptr));
  tab[3]->op = op[5];
  tab[3]->ptr = &infinite_div;
  tab[4] = xmalloc(sizeof(t_ptr));
  tab[4]->op = op[6];
  tab[4]->ptr = &infinite_mod;
  tab[5] = xmalloc(sizeof(t_ptr));
  tab[5]->op = '\0';
  tab[5]->ptr = NULL;
  return (tab);
}

char	*infinite_doop(t_chain *tok, char *base, char *ops)
{
  int	i;
  t_ptr	**tab;

  tab = fill_tab(ops);
  while (tok->next != NULL)
    {
      i = 0;
      tok = tok->next;
      while (my_strchr(ops, tok->str[0]) == (-1) || my_strlen(tok->str) != 1)
	tok = tok->next;
      while (tab[i]->ptr != NULL)
	{
	  if (tok->str[0] == tab[i]->op)
	    {
	      tok->str = (*tab[i]->ptr)(tok->prev->prev->str, tok->prev->str, base, ops);
	      i = 4;
	    }
	  i++;
	}
      my_rm_elem_prev(&tok);
      my_rm_elem_prev(&tok);
    }
  free(tab);
  return (tok->str);
}
