/*
** my_swap.c for my_swap in 
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Sat Oct 12 08:39:52 2013 alexandre.odet
** Last update Sat Oct 12 08:41:32 2013 alexandre.odet
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
