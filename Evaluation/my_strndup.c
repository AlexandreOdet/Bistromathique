/*
** my_strndup.c for my_strndup in /home/odet_a/rendu/Bistro/Evaluation
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Tue Nov  5 09:42:15 2013 
** Last update Thu Nov  7 17:37:12 2013 
*/

#include "../bistromathique.h"

char    *my_strndup(char *src, int nb)
{
  char  *dest;
 
  dest = xmalloc(sizeof(char) *(my_strlen(src) + 1));
  dest = my_strncpy(dest, src, nb);
  dest[my_strlen(src)] = 0;
  return (dest);
}
