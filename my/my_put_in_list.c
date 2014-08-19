/*
** my_put_in_list.c for my_put_in_list in /home/odet_a/rendu/Piscine-C-Jour_12/ex_01
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Tue Oct 22 09:47:44 2013 
** Last update Tue Nov  5 16:08:10 2013 
*/

#include "../bistromathique.h"
#include <stdlib.h>

void	my_show_list(t_chain *list)
{
  t_chain	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
