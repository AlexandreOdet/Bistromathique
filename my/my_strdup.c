/*
** my_strdup.c for my_strdup in /home/odet_a/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Wed Oct  9 09:02:25 2013 alexandre.odet
** Last update Tue Nov  5 18:09:47 2013 
*/

#include "../bistromathique.h"

char	*my_strdup(char *src)
{
  char	*dest;

  dest = xmalloc(sizeof(char) * (my_strlen(src) +1));
  dest = my_strcpy(dest, src);
  dest[my_strlen(src)] = 0;
  return (dest);
}
