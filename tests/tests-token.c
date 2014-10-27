/*
** tests-token.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:12:49 2014 brendan rius
** Last update Mon Oct 27 16:18:13 2014 brendan rius
*/

int		main(int argc, char **argv)
{
  t_queue	*tokens;
  t_token	*token;

  if (argc < 2)
    {
      my_puterror("Wrong number of args\n");
      return (0);
    }
  tokens = get_tokens(lexicon, argv[1]);
  while ((token = (t_token *) front(tokens)))
    {
      my_putstr(token->string_value);
      my_putchar('\n');
    }
  return (0);
}
