/*
** my_list_size.c for my_list_size in /home/odet_a/rendu/Piscine-C-Jour_12/ex_02
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Tue Oct 22 11:17:51 2013 
** Last update Fri Nov  8 15:09:25 2013 
*/

#include "../bistromathique.h"

int	my_list_size(t_chain *begin)
{
  int	i;

  i = 0;
  while (begin != NULL)
    {
      i++;
      begin = begin->next;
    }
  return (i);
}
