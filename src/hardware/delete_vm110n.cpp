// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Bibliotheque Lapin

#include		"PVM110N.hpp"
#include		"lapin_private.h"

void			bunny_delete_vm110n(t_bunny_vm110n		*hdr)
{
  delete (hbs::PVM110N*)hdr->_private;
  bunny_free(hdr);
  scream_log_if("%p", "vm110n", hdr);
}

