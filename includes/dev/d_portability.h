
#pragma once

#include <inttypes.h> // format specifiers

#ifndef __always_inline
# define __always_inline __attribute__ ((always_inline)) inline
#endif

# define PRIdb	PRId8
# define PRIdw	PRId16
# define PRIdd	PRId32
# define PRIdq	PRId64

# define PRIub	PRIu8
# define PRIuw	PRIu16
# define PRIud	PRIu32
# define PRIuq	PRIu64

# define PRIxb	PRIx8
# define PRIxw	PRIx16
# define PRIxd	PRIx32
# define PRIxq	PRIx64

# define PRIXb	PRIX8
# define PRIXw	PRIX16
# define PRIXd	PRIX32
# define PRIXq	PRIX64
