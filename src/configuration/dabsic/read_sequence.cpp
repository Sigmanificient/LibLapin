// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2016
//
// Lapin library

#include		<string.h>
#include		"lapin_private.h"

Decision		dabsic_read_sequence(const char		*code,
					     ssize_t		&i,
					     SmallConf		&conf)
{
  dabsic_read_separator(code, i);
  if (readtext(code, i, "[Sequence") == false)
    return (BD_NOT_FOUND);
  dabsic_read_separator(code, i);

  if (dabsic_read_inside_sequence(code, i, conf) == BD_ERROR)
    return (BD_ERROR);

  dabsic_read_separator(code, i);
  if (readtext(code, i, "]") == false)
    scream_error_if
      (return (BD_ERROR), BE_SYNTAX_ERROR,
       "The token ']' was expected to close the sequence scope on line %d",
       whichline(code, i)
       );
  dabsic_read_separator(code, i);
  return (BD_OK);
}

