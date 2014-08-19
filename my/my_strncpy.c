/*
** my_strncpy.c for my_strncpy in 
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Fri Oct 11 16:59:50 2013 alexandre.odet
** Last update Tue Nov  5 15:23:44 2013 
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n &&src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
