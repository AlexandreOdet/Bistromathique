/*
** my_putstr.c for my_putstr in 
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Fri Oct 11 16:49:48 2013 alexandre.odet
** Last update Tue Nov  5 16:59:42 2013 
*/

void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
  return (0);
}
