/*
** my_strcmp.c for my_strcmp in /home/odet_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Oct  7 11:10:15 2013 alexandre.odet
** Last update Tue Oct  8 16:39:52 2013 alexandre.odet
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i++;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
