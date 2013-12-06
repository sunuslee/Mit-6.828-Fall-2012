/* See COPYRIGHT for copyright information. */

#ifndef JOS_INC_ASSERT_H
#define JOS_INC_ASSERT_H

#include <inc/stdio.h>

void _warn(const char*, int, const char*, ...);
void _panic(const char*, int, const char*, ...) __attribute__((noreturn));

#define warn(...) _warn(__FILE__, __LINE__, __VA_ARGS__)
#define panic(...) _panic(__FILE__, __LINE__, __VA_ARGS__)

#define assert(x)		\
	do { if (!(x)) panic("assertion failed: %s", #x); } while (0)

// static_assert(x) will generate a compile-time error if 'x' is false.
#define static_assert(x)	switch (x) case 0: case (x):


#define DEBUG_CURRENT   0

#define DEBUG_OFF       0
#define DEBUG_INFO      10
#define DEBUG_DEBUG     20
#define DEBUG_FATAL     30
#define DEBUG_ALL       100


#define debug(level, fmt, ...)						\
	do {								\
		if (level > DEBUG_CURRENT) {				\
			switch (level) {				\
			case DEBUG_INFO:				\
				cprintf("INFO: "fmt, __VA_ARGS__);	\
				break;					\
			case DEBUG_DEBUG:				\
				cprintf("DEBUG: "fmt, __VA_ARGS__);	\
				break;					\
			case DEBUG_FATAL:				\
				cprintf("FATAL: "fmt, __VA_ARGS__);	\
				break;					\
			default:					\
				cprintf("DEBUG: "fmt, __VA_ARGS__);	\
			}						\
		}							\
	} while (0)

#endif /* !JOS_INC_ASSERT_H */
