/*
** my_strcpy.c for my_strcpy in 
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Fri Oct 11 16:52:06 2013 alexandre.odet
** Last update Tue Nov  5 09:57:46 2013 
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
