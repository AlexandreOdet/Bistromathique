/*
** my_putchar.c for my_putchar in 
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Fri Oct 11 16:49:14 2013 alexandre.odet
** Last update Tue Nov  5 10:07:22 2013 
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
