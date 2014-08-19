/*
** xmalloc.c for xmalloc in /home/odet_a/rendu/Bistro
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Tue Nov  5 16:33:08 2013 
** Last update Sat Nov  9 17:57:24 2013 
*/

#include "../bistromathique.h"

void	*xmalloc (size_t n)
{
  void	*p;

  p = malloc (n);
  if (p == NULL)
    exit(1);
  return (p);
}
