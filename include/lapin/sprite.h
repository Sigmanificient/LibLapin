/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2017
**
** Bibliotheque Lapin
*/

/*!
** \file sprite.h
** A sprite is an animated picture.
** This module handle sprite description
** configuration file and bring functions
** to manipulates sprites and display them.
*/

#ifndef			__LAPIN_SPRITE_H__
# define		__LAPIN_SPRITE_H__
# if			!defined(__LAPIN_H__)
#  error		You cannot include this file directly.
# endif
# include		<string.h>

/*!
** This enumeration describe the way the animation
** in sprite are browsed.
** It can be from left to right, and then loop.
** It can be from right to left, and then loop.
** It can be from left to right to left, and then loop.
*/
typedef enum		e_bunny_frame_browsing
  {
    BFB_LEFT_TO_RIGHT,
    BFB_RIGHT_TO_LEFT,
    BFB_BACK_AND_FORTH
  }			t_bunny_frame_browsing;

/*!
** The t_bunny_animation structure describe an animation.
** An animation must be several clips followed one before
** another.
** Each line is a single animation, the first frame position
** on sprite sheet is described in position.
** The frame itself repetition is present, so each frame
** does not have to stand the same amount of time.
** The delay is a value in second that indicates how
** many second the frame stand for a single display.
** Animation repeat indicates how many time the animation
** must be repeated entirely before being considered terminated.
** For animation repeat, -1 indicates infinite repetition.
** The next_animation describe which animation must
** be followed after the current one. -1 indicates
** it is not followed by another animation.
*/
typedef struct		s_bunny_animation
{
  uint64_t		hash;
  double		delay;
  uint32_t		nbr_frame;
  t_bunny_position	position;
  t_bunny_vector	*frame_repetition;
  t_bunny_frame_browsing browsing;
  int32_t		animation_repeat;
  int32_t		next_animation;
}			t_bunny_animation;

/*!
** The t_bunny_sprite structure is a children of t_bunny_clipable
** so it can be used by any function that handle a t_bunny_clipable.
** It contains an animation array and informations about which
** frame is currently being used to display.
*/
typedef struct		s_bunny_sprite
{
  t_bunny_clipable	clipable;
  const size_t		_private[3];
  t_bunny_vector	*animation;	// [int -> anim]
  t_bunny_map		*hashname_id;	// [hash("") -> int]
  int32_t		current_animation;
  uint32_t		current_frame_repeat;
  uint32_t		current_repeat;
  uint32_t		current_frame;
  double		current_time;
  bool			stop_repeat;
}			t_bunny_sprite;

/*!
** bunny_load_sprite takes a configuration file as parameter.
** The content of the configuration file is described in formats/sprite.
** It returns a t_bunny_sprite on success, NULL on error.
** \param file A configuration file of sprite format.
** \return A valid t_bunny_sprite or NULL on error.
*/
t_bunny_sprite		*bunny_load_sprite(const char		*file);

/*!
** The bunny_sprite_animate function animates the sent sprite, taking
** the elapsed time (in seconds) into consideration.
** The sent sprite is modified accordingly to this elapsed time, so
** the next time you display it, it may be different.
** \param sprite The sprite to animate
** \param elapsed The elapsed time in seconds.
*/
void			bunny_sprite_animate(t_bunny_sprite	*sprite,
					     double		elapsed);

/*!
** This function returns true if the animation is terminated.
** \param sprite The sprite to check.
** \return True if the animation is terminated.
*/
bool			bunny_sprite_is_still(t_bunny_sprite	*sprite);

# if			defined(__STDC_VERSION__) && __STDC_VERSION__ == 201112L
/*!
** Set the current sprite animation to the sent sprite.
** The animation can be sent as string (the animation name) or as
** id. The id is the named hashed into a 64 bits long integer.
** The hash value can be obtained throught the bunny_sprite_animation_name
** function.
** \param The sprite to set the animation to.
** \param anim The animation to set to the sprite.
** \return True if the animation was set. False if the animation does not exists.
*/
#  define		bunny_sprite_set_animation(spr, anim)	\
  _Generic((anim),						\
	   const char*: bunny_sprite_set_animation_name,	\
	   char*: bunny_sprite_set_animation_name,		\
	   uint64_t: bunny_sprite_set_animation_id,		\
	   int: bunny_sprite_set_animation_id			\
	   )(spr, anim)
# endif

/*!
** Set the current sprite animation to the sent sprite.
** The animation name under its string format is used.
** You may see the sprite configuration format to see which node it must
** match.
** \param sprite The sprite to set the animation to.
** \param anim The animation to set to the sprite.
** \return True if the animation was set. False if the animation does not exists.
*/
bool			bunny_sprite_set_animation_name(t_bunny_sprite *sprite,
							const char *anim);

/*!
** Indicates that the animation should not loop anymore. The repeatition
** concerned by this stop is the whole animation repeat.
** This function serves one purpose: being certain that the animation is
** at its final step before starting another one. Because seing for exemple
** a jump animation being terminated and then started again before finally
** seing the landing animation could be very ugly and amateurish.
** \param sprite The sprite with the animation to stop.
*/
void			bunny_sprite_stop_repeat(t_bunny_sprite *sprite);

/*!
** Set the current sprite animation to the sent sprite.
** The animation name under its hash format is used.
** It can be generated with the name under string format sent to
** bunny_sprite_animation_name.
** \param sprite The sprite to set the animation to.
** \param anim The animation to set to the sprite.
** \return True if the animation was set. False if the animation does not exists.
*/
bool			bunny_sprite_set_animation_id(t_bunny_sprite *sprite,
						      uint64_t	anim);

/*!
** Return the current animation name under its hash format.
** \param sprite The sprite to inspect
** \return The name under its hash format.
*/
uint64_t		bunny_sprite_get_animation(const t_bunny_sprite *sprite);

/*!
** Return the hash format of the sent name.
** \param name The name under string format.
** \return The name under hash format.
*/
# define		bunny_sprite_animation_name(name)	\
  bunny_hash(BH_DJB2, name, strlen(name))

#endif	/*		__LAPIN_SPRITE_H__			*/
