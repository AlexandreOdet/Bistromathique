/*
** my_strlen.c for my_strlen in 
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Fri Oct 11 16:50:42 2013 alexandre.odet
** Last update Fri Oct 11 16:51:31 2013 alexandre.odet
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
