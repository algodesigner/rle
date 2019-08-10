/*
 * Target platform customisations.
 */

#ifndef _TARGET_H

#if defined WIN32 || defined _WIN32 || defined __CYGWIN__
#  define STDIN_FILENO 0
#  define STDOUT_FILENO 1
#  define STDERR_FILENO 2
#  include <io.h>
#  include <fcntl.h>
#  ifdef __MINGW32__
#    define SET_BINARY_MODE(fd) _setmode(fd, _O_BINARY)
#  else
#    define SET_BINARY_MODE(fd) setmode(fd, O_BINARY)
#  endif
#else
#  define SET_BINARY_MODE(fd) ((void)0)
#endif

#endif
