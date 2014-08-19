/*
** my_strcmp.c for my_strcmp in /home/odet_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Oct  7 11:10:15 2013 alexandre.odet
** Last update Tue Oct  8 16:48:14 2013 alexandre.odet
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      if (s1[i] < s2[i] && i < n)
	return (-1);
      if (s1[i] > s2[i] && i < n)
	return (1);
      i++;
    }
  return (0);
}
