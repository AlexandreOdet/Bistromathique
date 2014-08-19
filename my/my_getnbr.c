/*
** my_getnbr.c for my_getnbr in /home/odet_a/rendu/Piscine-C-Jour_04
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Thu Oct  3 14:17:16 2013 alexandre.odet
** Last update Wed Nov  6 17:50:59 2013 
*/

int	is_neg(char *str)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        c++;
      i++;
    }
  if (c % 2 != 0)
    return (1);
  else
    return (0);
}

int	is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);  
}
