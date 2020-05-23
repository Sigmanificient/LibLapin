// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2020
//
// LibLapin

#include		"lapin_private.h"

t_bunny_historic_element *bunny_new_historic_element(t_history_march	march,
						     size_t		time_buffer_len,
						     size_t		state_size)
{
  t_bunny_historic_element *he;
  size_t len;

  if ((he = bunny_malloc(sizeof(*he))) == NULL)
    goto Return;
  len = (sizeof(*he->status) + state_size) * time_buffer_len;
  if ((he->status = bunny_malloc(len)) == NULL)
    goto FreeElement;
  he->status_array_length = time_buffer_len;
  he->status_length = state_size;
  he->last_status = 0;
  he->last_tick = 0;
  he->last_key_frame_tick = 0;
  he->last_computed_tick = 0;
  he->apply_history_march = march;

  return (he);
 FreeElement:
  bunny_free(he);
 Return:
  return (NULL);
}
