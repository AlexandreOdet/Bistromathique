/*
** bistromathique.h for bistromathique in /home/odet_a/rendu/Bistro
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Tue Nov  5 14:59:13 2013 
** Last update Sat Nov  9 17:57:05 2013 
*/

#ifndef BISTROMATHIQUE_H_
#define BISTROMATHIQUE_H_

#include <stdlib.h>
#define CONV(Value) ((Value) == 0 ?  (1) : (0))
#define	OP_OPEN_PARENT_IDX 0
#define	OP_CLOSE_PARENT_IDX 1
#define	OP_PLUS_IDX 2
#define	OP_SUB_IDX 3
#define	OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6
#define	SYNTAXE_ERROR_MSG "syntax error\n"
 
typedef struct  s_struct
{
  int		i;
  char		ret;
  char		*new1;
  char		*new2;
  char		*res;
  int		calc;
}		t_struct;

typedef struct	s_ptr
{
  char		op;
  char		 *(*ptr)(char *nb1, char *nb2, char *base, char *op);
}		t_ptr;

typedef struct  s_base
{
  char		*op;
  char		*base;
}		t_base;

typedef struct  s_chain
{
  char		*str;
  struct s_chain	*prev;
  struct s_chain	*next;
}		t_chain;

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_swap(char *s1, char *s2);
char	*my_revstr(char *str); 
int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strndup(char *src, int nb);
int	my_getnbr(char *str);
int	my_list_size(t_chain *begin);
char	*eval_expr(char *base, char *ops, char *expr, unsigned int size);
int	strlen_1word(char *str, char *op);
char	*my_strldup(char *src, int nb, char *op);
int	my_put_in_2list(t_chain **list, char *str, char *op);
int	lentab(char *str, char *op);
t_chain	*my_str_to_chain(char *str, char *op);
void	my_neg_changement(t_chain **t, t_chain **sort, t_chain **pile, t_base tmp);
int	my_neg_special(t_chain **t, t_chain **sort, t_chain **pile, t_base tmp);
t_chain	*my_get_first_chain(t_chain *sort);
void	my_unstack(t_chain **src, t_chain **dest, char *op);
int	my_put_in_list(t_chain **list, char *str);
void	my_stack_op(t_chain **t, t_chain **sort, t_chain **pile, t_base tmp);
t_chain	*my_npi(t_chain *t, t_base tmp);
int	my_strchr(char *str, char src);
int	my_compare_int(char *s1, char *s2, char *base);
char	*inf_abs(char *str, char *op);
char	*inf_back_abs(char *str, char *op);
char    *generate_result_add(char *nb1, char *nb2);
char	*my_loop(char *new, t_struct *t, int i, char *base);
char	*my_add(char *nb1, char *nb2, char *base);
char	*infinite_add(char *nb1, char *nb2, char *base, char *op);
char    *generate_result_sub(char *nb1, char *nb2);
char	*my_sub_loop(t_struct *t, int i, char *base);
char	*my_sub(char *nb1, char *nb2, char *base);
char	*infinite_sub(char *nb1, char *nb2, char *base, char *op);
char	*generate_result_mul(char *nb1, char *nb2);
char	*my_rec_mul(t_struct *t, int ret, int i, char *base);
char	*my_mul(char *nb1, char *nb2, char *base);
char	*infinite_mul(char *nb1, char *nb2, char *base, char *op);
char	*generate_result_div(char *nb1, char *nb2);
char	*my_div2(char *nb1, char *nb2, t_struct *t, char *base);
char	*my_div(char *nb1, char *nb2, char *base);
char	*infinite_div(char *nb1, char *nb2, char *base, char *op);
char	*infinite_mod(char *nb1, char *nb2, char *base, char *op);
char	*infinite_doop(t_chain *ptr, char *base, char *op);
char	*my_strdup(char *src);
t_ptr   **fill_tab(char *op);
void	*xmalloc (size_t n);
int	parentheses(char *str, char *op);
void	my_error(int nb);
int	my_rm_elem_next(t_chain **ptr);
int	my_rm_elem_prev(t_chain **ptr);
int	my_rm_current_elem(t_chain **ptr);

#endif
