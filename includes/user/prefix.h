
#pragma once

///TODO: The idea is to make the prefixes macros so the user can customize the prefixes while compiling

#ifndef __AVL_SET_PREF
///TODO: Hange the prefix of __SET_PREFIX when i ll know which prefix use
# define __AVL_SET_PREF(x) AVL_ ## x
#else
# error "Error: Colision with __AVL_SET_PREF."
#endif 

#ifndef __AVL_SET_VEX3_PREF
# define __AVL_SET_VEX3_PREF(x) vx_ ## x
#else
# error "Error: Colision with __AVL_SET_VEX3_PREF."
#endif

#ifndef __AVL_SET_VEX2_PREF
# define __AVL_SET_VEX2_PREF(x) vx2_ ## x
#else
# error "Error: Colision with __AVL_SET_VEX2_PREF."
#endif

#ifndef __AVL_SET_EVEX_PREF
#define __AVL_SET_EVEX_PREF(x) evx_ ## x
#else
# error "Error: Colision with __AVL_SET_EVEX_PREF."
#endif

#ifndef __AVL_SET_EVEX_RSVPREF
#define __AVL_SET_EVEX_RSVPREF(x) __evx_ ## x
#else
# error "Error: Colision with __AVL_SET_EVEX_RSVPREF."
#endif

#ifndef __AVL_SET_INST_PREF
# define __AVL_SET_INST_PREF(x) i_ ## x
#else
# error "Error: Colision with __AVL_SET_INST_PREF."
#endif

#ifndef __AVL_SET_MODRM_PREF
# define __AVL_SET_MODRM_PREF(x) m ## x
#else
# error "Error: Colision with __AVL_SET_MODRM_PREF."
#endif

#ifndef __AVL_SET_SIB_PREF
# define __AVL_SET_SIB_PREF(x) s ## x
#else
# error "Error: Colision with __AVL_SET_SIB_PREF."
#endif
