// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Bibliotheque Lapin

#include		"lapin_private.h"

void			bunny_sound_volume(t_bunny_sound	*sound,
					   double		vol)
{
  enum _music_or_sound	*type = (enum _music_or_sound*)sound;

  if (vol < 0)
    vol = 0;
  else if (vol > 100)
    vol = 100;

  sound->volume = vol;
  if (*type == MUSIC)
    ((struct bunny_music*)sound)->music.setVolume(vol);
  else
    ((struct bunny_effect*)sound)->sound->setVolume(vol);
  scream_log_if("%p sound, %f volume", "sound", sound, vol);
}

