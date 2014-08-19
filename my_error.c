/*
** my_error.c for my_error in /home/odet_a/rendu/Bistro
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Thu Nov  7 17:12:00 2013 
** Last update Fri Nov  8 16:54:13 2013 
*/

#include "bistromathique.h"

void	my_error(int nb)
{
  if (nb == 1)
    my_putstr(SYNTAXE_ERROR_MSG);
  if (nb == 2)
    my_putstr("Stop, division by 0\n");
  if (nb == 3)
    my_putstr("Stop, modulo by 0\n");
  exit(1);
}

int	my_rm_elem_next(t_chain **ptr)
{
  t_chain	*tmp;

  tmp = (*ptr)->next;
  if (ptr == NULL)
    return (1);
  (*ptr)->next = (*ptr)->next->next;
  free(tmp);
  if ((*ptr)->next != NULL)
    (*ptr)->next->prev = *ptr;
  return (0);
}

int	my_rm_elem_prev(t_chain **ptr)
{
  t_chain	*tmp;

  tmp = (*ptr)->prev;
  if (ptr == NULL)
    return (1);
  (*ptr)->prev = (*ptr)->prev->prev;
  free(tmp);
  if ((*ptr)->prev != NULL)
    (*ptr)->prev->next = *ptr;
  return (0);
}

int	my_rm_current_elem(t_chain **ptr)
{
  t_chain	*tmp;

  tmp = *ptr;
  if (ptr == NULL)
    return (1);
  *ptr = (*ptr)->prev;
  free(tmp);
  return (0);
}
