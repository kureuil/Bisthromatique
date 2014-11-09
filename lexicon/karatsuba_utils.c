/*
** karatsuba_utils.c for Bistromathique in /home/brendan/rendu/Bistromathique/lexicon
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Nov  6 15:06:35 2014 Brendan Rius
** Last update Sun Nov  9 23:18:37 2014 Louis Person
*/

#include "bm_errno.h"
#include "tokens.h"
#include "bm_lexicon_utils.h"
#include "bm_base.h"
#include "karatsuba_utils.h"

t_rcode		pad(t_token *t, t_base *base, int nb, t_token *res)
{
  t_rcode	ret;
  int		i;

  if ((ret = malloc_token_dynamically(res, t->size + nb)) != OK)
    return (ret);
  res->type = NUMBER;
  i = 0;
  while (i < t->size + nb)
    {
      if (i < t->size)
	res->string_value[i] = t->string_value[i];
      else
	res->string_value[i] = base->string[0];
      ++i;
    }
  return (OK);
}

t_rcode		compute_z0(t_base *base,
			   t_delimiters *delimiters,
			   int m2,
			   t_karat_coeff *coefficients)
{
  t_rcode	ret;
  t_token	*z0;

  if ((ret = bm_new_token(&coefficients->z0)) != OK ||
      (ret = bm_new_token(&z0)) != OK)
    return (ret);
  if ((ret = action_mul(base, delimiters->a, delimiters->c, z0)) != OK)
    return (ret);
  if ((ret = pad(z0, base, m2 * 2, coefficients->z0)) != OK)
    return (ret);
  clean_number_str(base, coefficients->z0);
  return (OK);
}

t_rcode		compute_z1(t_base *base,
			   t_delimiters *delimiters,
			   t_karat_coeff *coefficients)
{
  t_rcode	ret;

  if ((ret = bm_new_token(&coefficients->z1)) != OK)
    return (ret);
  return (action_mul(base, delimiters->b, delimiters->d, coefficients->z1));
}

t_rcode		compute_z2(t_base *base,
			   t_delimiters *delimiters,
			   int m2,
			   t_karat_coeff *coefficients)
{
  t_rcode	ret;
  t_token	*apb;
  t_token	*cpd;
  t_token	*z2_tmp;
  t_token	*z2_tmp2;
  t_token	*z2;

  if ((ret = bm_new_token(&coefficients->z2)) != OK ||
      (ret = bm_new_token(&z2)) != OK ||
      (ret = bm_new_token(&apb)) != OK ||
      (ret = bm_new_token(&cpd)) != OK ||
      (ret = bm_new_token(&z2_tmp)) != OK ||
      (ret = bm_new_token(&z2_tmp2)) != OK)
    return (ret);
  action_add(base, delimiters->a, delimiters->b, apb);
  action_add(base, delimiters->c, delimiters->d, cpd);
  action_mul(base, apb, cpd, z2_tmp);
  action_sub_compute(base, z2_tmp, coefficients->z0, z2_tmp2);
  action_sub_compute(base, z2_tmp2, coefficients->z1, z2);
  pad(z2, base, m2, coefficients->z2);
  clean_number_str(base, coefficients->z2);
  bm_free_token(z2_tmp);
  bm_free_token(z2_tmp2);
  bm_free_token(z2);
  return (OK);
}
