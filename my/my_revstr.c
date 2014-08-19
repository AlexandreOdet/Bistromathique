/*
** my_evil_str.c for my_evil_str in /home/odet_a/rendu/Piscine-C-Jour_04
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Thu Oct  3 10:01:19 2013 alexandre.odet
** Last update Tue Nov  5 17:00:31 2013 
*/

void	my_swap(char *a, char *b)
{
  char c;

  c = *a;
  *a = *b;
  *b = c;
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while(str[i])
    i++;
  return (i);
}

char	*my_revstr(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      my_swap(&str[j], &str[i]);
      i++;
      j--;
    }
  return (str);
}
