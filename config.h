/*
 * Configuration
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Default memory device file */
#if defined(__BEOS__) || defined(__HAIKU__)
#define DEFAULT_MEM_DEV "/dev/misc/mem"
#elif defined(__sun)
#define DEFAULT_MEM_DEV "/dev/xsvc"
#elif defined(__APPLE__)
#define DEFAULT_MEM_DEV "I/O Registry"
#else
#define DEFAULT_MEM_DEV "/dev/mem"
#endif

/* Use mmap or not */
#ifndef __BEOS__
#define USE_MMAP
#endif

/* Use memory alignment workaround or not */
#ifndef FORCE_UNALIGNED_READ
#define ALIGNMENT_WORKAROUND
#endif

/* Avoid unaligned memcpy on /dev/mem */
#ifdef __aarch64__
#define USE_SLOW_MEMCPY
#endif

#endif
