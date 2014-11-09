/*
** bm_errno.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct 28 08:46:28 2014 brendan rius
** Last update Sun Nov  9 20:34:57 2014 Louis Person
*/

#ifndef BM_ERRNO_H_
# define BM_ERRNO_H_

# define NB_ERRORS 20

typedef enum	e_rcode
  {
		OK,
		MISMATCHED_P,
		NOTHING_TO_READ,
		COULD_NOT_MALLOC,
		READ_ERROR,
		NOT_ENOUGH_VALUES,
		EMPTY_OPERATORS,
		TOO_MUCH_VALUES,
		NULL_REFERENCE,
		NOT_IN_BASE,
		WRONG_BASE_LEN,
		DUPLICATE_VALUE_IN_BASE,
		INVALID_CHARACTER,
		EMPTY_BASE,
		WRITE_FAILED,
		WRONG_NB_ARGS,
		DUPLICATE_VALUE_IN_OPERATORS_OR_BASE,
		WRONG_OPS_LEN,
		DIVISION_BY_ZERO,
		MODULO_BY_ZERO,
		DIVISION_BY_ITSELF
  }		t_rcode;

char	*bm_get_error(t_rcode code);

int	usage(char *cmd);

#endif /* !BM_ERRNO_H_ */
