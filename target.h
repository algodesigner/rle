/*
 * Target platform customisations.
 */

#ifndef _TARGET_H
#define _TARGET_H

#ifdef _WIN32
#  include <io.h>
#  include <fcntl.h>
#  define SET_BINARY_MODE(handle) _setmode(_fileno(handle), _O_BINARY)
#else
#  define SET_BINARY_MODE(handle) ((void)0)
#endif

#endif
