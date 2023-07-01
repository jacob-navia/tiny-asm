/* as.h - global header file
   Copyright (C) 1987-2023 Free Software Foundation, Inc.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  

   This file is a selection of the header files found in the Gnu 
   assembler (gas). It is the minimal subset of declarations that are
   needed to run the code in "asm.c".
   
*/

#ifndef GAS
#define GAS 1
#define __CONFIG_H__ 1
/* Default architecture. */
#define DEFAULT_ARCH "riscv64"
/* Default compression algorithm for --enable-compressed-debug-sections. */
#define DEFAULT_COMPRESSED_DEBUG_ALGORITHM COMPRESS_DEBUG_GABI_ZLIB
/* Define to 1 if you want to generate ELF common symbols with the STT_COMMON
   type by default. */
#define DEFAULT_GENERATE_ELF_STT_COMMON 0
/* Define to 1 if you want to generate RISC-V arch attribute by default. */
#define DEFAULT_RISCV_ATTR 1
/* Define if you want run-time sanity checks. */
#define ENABLE_CHECKING 1
/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#define ENABLE_NLS 0
/* Define if <sys/stat.h> has struct stat.st_mtim.tv_nsec */
#define HAVE_ST_MTIM_TV_NSEC 1
/* Define if <sys/stat.h> has struct stat.st_mtim.tv_sec */
#define HAVE_ST_MTIM_TV_SEC 1
/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries. */
#define LT_OBJDIR "libs/"
/* Name of package */
#define PACKAGE "tiny-as"
/* Define to the full name of this package. */
#define PACKAGE_NAME "tiny-gas"
/* Define to the full name and version of this package. */
#define PACKAGE_STRING "tiny-gas 0.9"
/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "tiny-gas"
#define VERSION "0.9"
/* Define to the version of this package. */
#define PACKAGE_VERSION "0.9"
/* Target alias. */
#define TARGET_ALIAS "riscv64-unknown-linux-gnu"
/* Define as 1 if big endian. */
#define TARGET_BYTES_BIG_ENDIAN 0
/* Canonical target. */
#define TARGET_CANONICAL "riscv64-unknown-linux-gnu"
/* Target CPU. */
#define TARGET_CPU "riscv64"
/* Target OS. */
#define TARGET_OS "linux-gnu"
/* Target vendor. */
#define TARGET_VENDOR "pine64"
/* Enable GNU extensions on systems that have them.  */
#define _GNU_SOURCE 1

/* System include files first...  */
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>

#include "getopt.h"
/* Compiler compatibility macros */
/* For ease of writing code which uses GCC extensions but needs to be
   portable to other compilers, we provide the GCC_VERSION macro that
   simplifies testing __GNUC__ and __GNUC_MINOR__ together, and various
   wrappers around __attribute__.  Also, __extension__ will be #defined
   to nothing if it doesn't work.  See below.  */

#ifndef	_ANSIDECL_H
#define _ANSIDECL_H	1

/* This macro simplifies testing whether we are using gcc, and if it
   is of a particular minimum version. (Both major & minor numbers are
   significant.)  This macro will evaluate to 0 if we are not using
   gcc at all.  */
#ifndef GCC_VERSION
#define GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
#endif /* GCC_VERSION */

/* Attribute __malloc__ on functions was valid as of gcc 2.96. */
#ifndef ATTRIBUTE_MALLOC
# if (GCC_VERSION >= 2096)
#  define ATTRIBUTE_MALLOC __attribute__ ((__malloc__))
# else
#  define ATTRIBUTE_MALLOC
# endif /* GNUC >= 2.96 */
#endif /* ATTRIBUTE_MALLOC */

/* Attributes on labels were valid as of gcc 2.93 and g++ 4.5.  For
   g++ an attribute on a label must be followed by a semicolon.  */
#ifndef ATTRIBUTE_UNUSED_LABEL
# ifndef __cplusplus
#  if GCC_VERSION >= 2093
#   define ATTRIBUTE_UNUSED_LABEL ATTRIBUTE_UNUSED
#  else
#   define ATTRIBUTE_UNUSED_LABEL
#  endif
# else
#  if GCC_VERSION >= 4005
#   define ATTRIBUTE_UNUSED_LABEL ATTRIBUTE_UNUSED ;
#  else
#   define ATTRIBUTE_UNUSED_LABEL
#  endif
# endif
#endif

/* Similarly to ARG_UNUSED below.  Prior to GCC 3.4, the C++ frontend
   couldn't parse attributes placed after the identifier name, and now
   the entire compiler is built with C++.  */
#ifndef ATTRIBUTE_UNUSED
#if GCC_VERSION >= 3004
#  define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#else
#define ATTRIBUTE_UNUSED
#endif
#endif /* ATTRIBUTE_UNUSED */

/* Before GCC 3.4, the C++ frontend couldn't parse attributes placed after the
   identifier name.  */
#if ! defined(__cplusplus) || (GCC_VERSION >= 3004)
# define ARG_UNUSED(NAME) NAME ATTRIBUTE_UNUSED
#else /* !__cplusplus || GNUC >= 3.4 */
# define ARG_UNUSED(NAME) NAME
#endif /* !__cplusplus || GNUC >= 3.4 */

#ifndef ATTRIBUTE_NORETURN
#define ATTRIBUTE_NORETURN __attribute__ ((__noreturn__))
#endif /* ATTRIBUTE_NORETURN */

/* Attribute `nonnull' was valid as of gcc 3.3.  */
#ifndef ATTRIBUTE_NONNULL
# if (GCC_VERSION >= 3003)
#  define ATTRIBUTE_NONNULL(m) __attribute__ ((__nonnull__ (m)))
# else
#  define ATTRIBUTE_NONNULL(m)
# endif /* GNUC >= 3.3 */
#endif /* ATTRIBUTE_NONNULL */

/* Attribute `returns_nonnull' was valid as of gcc 4.9.  */
#ifndef ATTRIBUTE_RETURNS_NONNULL
# if (GCC_VERSION >= 4009)
#  define ATTRIBUTE_RETURNS_NONNULL __attribute__ ((__returns_nonnull__))
# else
#  define ATTRIBUTE_RETURNS_NONNULL
# endif /* GNUC >= 4.9 */
#endif /* ATTRIBUTE_RETURNS_NONNULL */

/* Attribute `pure' was valid as of gcc 3.0.  */
#ifndef ATTRIBUTE_PURE
# if (GCC_VERSION >= 3000)
#  define ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define ATTRIBUTE_PURE
# endif /* GNUC >= 3.0 */
#endif /* ATTRIBUTE_PURE */

/* Use ATTRIBUTE_PRINTF when the format specifier must not be NULL.
   This was the case for the `printf' format attribute by itself
   before GCC 3.3, but as of 3.3 we need to add the `nonnull'
   attribute to retain this behavior.  */
#ifndef ATTRIBUTE_PRINTF
#define ATTRIBUTE_PRINTF(m, n) __attribute__ ((__format__ (__printf__, m, n))) ATTRIBUTE_NONNULL(m)
#define ATTRIBUTE_PRINTF_1 ATTRIBUTE_PRINTF(1, 2)
#define ATTRIBUTE_PRINTF_2 ATTRIBUTE_PRINTF(2, 3)
#define ATTRIBUTE_PRINTF_3 ATTRIBUTE_PRINTF(3, 4)
#define ATTRIBUTE_PRINTF_4 ATTRIBUTE_PRINTF(4, 5)
#define ATTRIBUTE_PRINTF_5 ATTRIBUTE_PRINTF(5, 6)
#endif /* ATTRIBUTE_PRINTF */

/* Use ATTRIBUTE_FPTR_PRINTF when the format attribute is to be set on
   a function pointer.  Format attributes were allowed on function
   pointers as of gcc 3.1.  */
#ifndef ATTRIBUTE_FPTR_PRINTF
# if (GCC_VERSION >= 3001)
#  define ATTRIBUTE_FPTR_PRINTF(m, n) ATTRIBUTE_PRINTF(m, n)
# else
#  define ATTRIBUTE_FPTR_PRINTF(m, n)
# endif /* GNUC >= 3.1 */
# define ATTRIBUTE_FPTR_PRINTF_1 ATTRIBUTE_FPTR_PRINTF(1, 2)
# define ATTRIBUTE_FPTR_PRINTF_2 ATTRIBUTE_FPTR_PRINTF(2, 3)
# define ATTRIBUTE_FPTR_PRINTF_3 ATTRIBUTE_FPTR_PRINTF(3, 4)
# define ATTRIBUTE_FPTR_PRINTF_4 ATTRIBUTE_FPTR_PRINTF(4, 5)
# define ATTRIBUTE_FPTR_PRINTF_5 ATTRIBUTE_FPTR_PRINTF(5, 6)
#endif /* ATTRIBUTE_FPTR_PRINTF */

/* Use ATTRIBUTE_NULL_PRINTF when the format specifier may be NULL.  A
   NULL format specifier was allowed as of gcc 3.3.  */
#ifndef ATTRIBUTE_NULL_PRINTF
# if (GCC_VERSION >= 3003)
#  define ATTRIBUTE_NULL_PRINTF(m, n) __attribute__ ((__format__ (__printf__, m, n)))
# else
#  define ATTRIBUTE_NULL_PRINTF(m, n)
# endif /* GNUC >= 3.3 */
# define ATTRIBUTE_NULL_PRINTF_1 ATTRIBUTE_NULL_PRINTF(1, 2)
# define ATTRIBUTE_NULL_PRINTF_2 ATTRIBUTE_NULL_PRINTF(2, 3)
# define ATTRIBUTE_NULL_PRINTF_3 ATTRIBUTE_NULL_PRINTF(3, 4)
# define ATTRIBUTE_NULL_PRINTF_4 ATTRIBUTE_NULL_PRINTF(4, 5)
# define ATTRIBUTE_NULL_PRINTF_5 ATTRIBUTE_NULL_PRINTF(5, 6)
#endif /* ATTRIBUTE_NULL_PRINTF */

/* Attribute `sentinel' was valid as of gcc 3.5.  */
#ifndef ATTRIBUTE_SENTINEL
# if (GCC_VERSION >= 3005)
#  define ATTRIBUTE_SENTINEL __attribute__ ((__sentinel__))
# else
#  define ATTRIBUTE_SENTINEL
# endif /* GNUC >= 3.5 */
#endif /* ATTRIBUTE_SENTINEL */


#ifndef ATTRIBUTE_ALIGNED_ALIGNOF
# if (GCC_VERSION >= 3000)
#  define ATTRIBUTE_ALIGNED_ALIGNOF(m) __attribute__ ((__aligned__ (__alignof__ (m))))
# else
#  define ATTRIBUTE_ALIGNED_ALIGNOF(m)
# endif /* GNUC >= 3.0 */
#endif /* ATTRIBUTE_ALIGNED_ALIGNOF */

/* Useful for structures whose layout must match some binary specification
   regardless of the alignment and padding qualities of the compiler.  */
#ifndef ATTRIBUTE_PACKED
# define ATTRIBUTE_PACKED __attribute__ ((packed))
#endif

/* Attribute `hot' and `cold' was valid as of gcc 4.3.  */
#ifndef ATTRIBUTE_COLD
# if (GCC_VERSION >= 4003)
#  define ATTRIBUTE_COLD __attribute__ ((__cold__))
# else
#  define ATTRIBUTE_COLD
# endif /* GNUC >= 4.3 */
#endif /* ATTRIBUTE_COLD */
#ifndef ATTRIBUTE_HOT
# if (GCC_VERSION >= 4003)
#  define ATTRIBUTE_HOT __attribute__ ((__hot__))
# else
#  define ATTRIBUTE_HOT
# endif /* GNUC >= 4.3 */
#endif /* ATTRIBUTE_HOT */

/* Attribute 'no_sanitize_undefined' was valid as of gcc 4.9.  */
#ifndef ATTRIBUTE_NO_SANITIZE_UNDEFINED
# if (GCC_VERSION >= 4009)
#  define ATTRIBUTE_NO_SANITIZE_UNDEFINED __attribute__ ((no_sanitize_undefined))
# else
#  define ATTRIBUTE_NO_SANITIZE_UNDEFINED
# endif /* GNUC >= 4.9 */
#endif /* ATTRIBUTE_NO_SANITIZE_UNDEFINED */

/* Attribute 'nonstring' was valid as of gcc 8.  */
#ifndef ATTRIBUTE_NONSTRING
# if GCC_VERSION >= 8000
#  define ATTRIBUTE_NONSTRING __attribute__ ((__nonstring__))
# else
#  define ATTRIBUTE_NONSTRING
# endif
#endif

/* Attribute `alloc_size' was valid as of gcc 4.3.  */
#ifndef ATTRIBUTE_RESULT_SIZE_1
# if (GCC_VERSION >= 4003)
#  define ATTRIBUTE_RESULT_SIZE_1 __attribute__ ((alloc_size (1)))
# else
#  define ATTRIBUTE_RESULT_SIZE_1
#endif
#endif

#ifndef ATTRIBUTE_RESULT_SIZE_2
# if (GCC_VERSION >= 4003)
#  define ATTRIBUTE_RESULT_SIZE_2 __attribute__ ((alloc_size (2)))
# else
#  define ATTRIBUTE_RESULT_SIZE_2
#endif
#endif

#ifndef ATTRIBUTE_RESULT_SIZE_1_2
# if (GCC_VERSION >= 4003)
#  define ATTRIBUTE_RESULT_SIZE_1_2 __attribute__ ((alloc_size (1, 2)))
# else
#  define ATTRIBUTE_RESULT_SIZE_1_2
#endif
#endif

/* Attribute `warn_unused_result' was valid as of gcc 3.3.  */
#ifndef ATTRIBUTE_WARN_UNUSED_RESULT
# if GCC_VERSION >= 3003
#  define ATTRIBUTE_WARN_UNUSED_RESULT __attribute__ ((warn_unused_result))
# else
#  define ATTRIBUTE_WARN_UNUSED_RESULT
# endif
#endif

/* We use __extension__ in some places to suppress -pedantic warnings
   about GCC extensions.  This feature didn't work properly before
   gcc 2.8.  */
#if GCC_VERSION < 2008
#define __extension__
#endif

/* This is used to declare a const variable which should be visible
   outside of the current compilation unit.  Use it as
     EXPORTED_CONST int i = 1;
   This is because the semantics of const are different in C and C++.
   "extern const" is permitted in C but it looks strange, and gcc
   warns about it when -Wc++-compat is not used.  */
#ifdef __cplusplus
#define EXPORTED_CONST extern const
#else
#define EXPORTED_CONST const
#endif

/* Be conservative and only use enum bitfields with C++ or GCC.
   FIXME: provide a complete autoconf test for buggy enum bitfields.  */

#ifdef __cplusplus
#define ENUM_BITFIELD(TYPE) enum TYPE
#elif (GCC_VERSION > 2000)
#define ENUM_BITFIELD(TYPE) __extension__ enum TYPE
#else
#define ENUM_BITFIELD(TYPE) unsigned int
#endif

#if defined(__cplusplus) && __cpp_constexpr >= 200704
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif

/* A macro to disable the copy constructor and assignment operator.
   When building with C++11 and above, the methods are explicitly
   deleted, causing a compile-time error if something tries to copy.
   For C++03, this just declares the methods, causing a link-time
   error if the methods end up called (assuming you don't
   define them).  For C++03, for best results, place the macro
   under the private: access specifier, like this,

   class name_lookup
   {
     private:
       DISABLE_COPY_AND_ASSIGN (name_lookup);
   };

   so that most attempts at copy are caught at compile-time.  */

#if defined(__cplusplus) && __cplusplus >= 201103
#define DISABLE_COPY_AND_ASSIGN(TYPE)		\
  TYPE (const TYPE&) = delete;			\
  void operator= (const TYPE &) = delete
  #else
#define DISABLE_COPY_AND_ASSIGN(TYPE)		\
  TYPE (const TYPE&);				\
  void operator= (const TYPE &)
#endif /* __cplusplus >= 201103 */

#endif	/* ansidecl.h	*/
/* The first getopt value for machine-independent long options.
   150 isn't special; it's just an arbitrary non-ASCII char value.  */
#define OPTION_STD_BASE 150
/* The first getopt value for machine-dependent long options.
   290 gives the standard options room to grow.  */
#define OPTION_MD_BASE  290

#ifdef DEBUG
#undef NDEBUG
#endif
#if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 6)
#define __PRETTY_FUNCTION__  ((char *) NULL)
#endif
#define gas_assert(P)	((void) ((P) ? 0 : (abort (), 0)))
#undef abort
#define abort()		as_abort (__FILE__, __LINE__, __PRETTY_FUNCTION__)
#define TARGET_ALIAS "riscv64-unknown-linux-gnu"
#define TARGET_CANONICAL "riscv64-unknown-linux-gnu"
#define DEFAULT_COMPRESSED_DEBUG_ALGORITHM COMPRESS_DEBUG_GABI_ZLIB
#define TARGET_CPU "riscv64"
/* Main header file for the bfd library -- portable access to object files. */
#ifndef __BFD_H_SEEN__
#define __BFD_H_SEEN__

/* Symbol concatenation utilities. */
#ifndef SYM_CAT_H
#define SYM_CAT_H

#define CONCAT2(a,b)	 a##b
#define CONCAT3(a,b,c)	 a##b##c
#define CONCAT4(a,b,c,d) a##b##c##d
#define CONCAT5(a,b,c,d,e) a##b##c##d##e
#define CONCAT6(a,b,c,d,e,f) a##b##c##d##e##f
#define STRINGX(s) #s
#define XCONCAT2(a,b)     CONCAT2(a,b)
#define XCONCAT3(a,b,c)   CONCAT3(a,b,c)
#define XCONCAT4(a,b,c,d) CONCAT4(a,b,c,d)
#define XCONCAT5(a,b,c,d,e) CONCAT5(a,b,c,d,e)
#define XCONCAT6(a,b,c,d,e,f) CONCAT6(a,b,c,d,e,f)
/* Note the layer of indirection here is typically used to allow
   stringification of the expansion of macros.  I.e. "#define foo
   bar", "XSTRING(foo)", to yield "bar".  Be aware that this only
   works for __STDC__, not for traditional C which will still resolve
   to "foo".  */
#define XSTRING(s) STRINGX(s) 
#endif /* SYM_CAT_H */
#if defined (__STDC__) || defined (ALMOST_STDC) || defined (HAVE_STRINGIZE)
#ifndef SABER
/* This hack is to avoid a problem with some strict ANSI C preprocessors.
   The problem is, "32_" is not a valid preprocessing token, and we don't
   want extra underscores (e.g., "nlm_32_").  The XCONCAT2 macro will
   cause the inner CONCAT2 macros to be evaluated first, producing
   still-valid pp-tokens.  Then the final concatenation can be done.  */
#undef CONCAT4
#define CONCAT4(a,b,c,d) XCONCAT2(CONCAT2(a,b),CONCAT2(c,d))
#endif
#endif

/* This is a utility macro to handle the situation where the code
   wants to place a constant string into the code, followed by a
   comma and then the length of the string.  Doing this by hand
   is error prone, so using this macro is safer.  */
#define STRING_COMMA_LEN(STR) (STR), (sizeof (STR) - 1)
#define BFD_SUPPORTS_PLUGINS 1

/* The word size used by BFD on the host.  This may be 64 with a 32
   bit target if the host is 64 bit, or if other 64 bit targets have
   been selected with --enable-targets, or if --enable-64-bit-bfd.  */
#define BFD_ARCH_SIZE 64

/* The word size of the default bfd target.  */
#define BFD_DEFAULT_TARGET_SIZE 64

/* Boolean type used in bfd.
   General rule: Functions which are bfd_boolean return TRUE on
   success and FALSE on failure (unless they're a predicate).  */
# define FALSE 0
# define TRUE 1

/* Silence "applying zero offset to null pointer" UBSAN warnings.  */
#define PTR_ADD(P,A) ((A) != 0 ? (P) + (A) : (P))
/* Also prevent non-zero offsets from being applied to a null pointer.  */
#define NPTR_ADD(P,A) ((P) != NULL ? (P) + (A) : (P))

/* Represent a target address.  Also used as a generic unsigned type
   which is guaranteed to be big enough to hold any arithmetic types
   we need to deal with.  */
typedef uint64_t bfd_vma;

/* A generic signed type which is guaranteed to be big enough to hold any
   arithmetic types we need to deal with.  Can be assumed to be compatible
   with bfd_vma in the same way that signed and unsigned ints are compatible
   (as parameters, in assignment, etc).  */
typedef int64_t bfd_signed_vma;
typedef uint64_t symvalue;

#define HALF_BFD_SIZE_TYPE \
  (((size_t) 1) << (8 * sizeof (size_t) / 2))
/* An offset into a file.  BFD always uses the largest possible offset
   based on the build time availability of fseek, fseeko, or fseeko64.  */
typedef int64_t file_ptr;
typedef uint64_t ufile_ptr;
typedef uint32_t flagword;	/* 32 bits of flags */
typedef uint8_t bfd_byte;

/* Forward declarations.  */
typedef struct bfd bfd;
struct bfd_link_info;
struct bfd_link_hash_entry;
typedef struct bfd_section *sec_ptr;
typedef struct reloc_cache_entry arelent;
struct orl;

#define	align_power(addr, align)	\
  (((addr) + ((bfd_vma) 1 << (align)) - 1) & (-((bfd_vma) 1 << (align))))

/* Align an address upward to a boundary, expressed as a number of bytes.
   E.g. align to an 8-byte boundary with argument of 8.  Take care never
   to wrap around if the address is within boundary-1 of the end of the
   address space.  */
#define BFD_ALIGN(this, boundary)					  \
  ((((bfd_vma) (this) + (boundary) - 1) >= (bfd_vma) (this))		  \
   ? (((bfd_vma) (this) + ((boundary) - 1)) & ~ (bfd_vma) ((boundary)-1)) \
   : ~ (bfd_vma) 0)

/* Return TRUE if the start of STR matches PREFIX, FALSE otherwise.  */

static inline bool startswith (const char *str, const char *prefix)
{
  return strncmp (str, prefix, strlen (prefix)) == 0;
}

/* Extracted from libbfd.c.  */
static void *bfd_alloc (bfd *abfd, size_t wanted);
static void *bfd_zalloc (bfd *abfd, size_t wanted);
static void bfd_release (bfd *, void *);

/* Byte swapping macros for user section data.  */
#define bfd_get_8(abfd, ptr)  ((bfd_vma) *(const bfd_byte *) (ptr) & 0xff)
#define bfd_get_signed_8(abfd, ptr) \
  ((((bfd_signed_vma) *(const bfd_byte *) (ptr) & 0xff) ^ 0x80) - 0x80)
#define bfd_get_16(abfd,data) (*(unsigned short *)(data))
static bfd_vma bfd_getl8 (const void *p);
static bfd_vma bfd_getl16 (const void *p);
static bfd_vma bfd_getl24(const void *p);
static bfd_vma bfd_getl32 (const void *p);
static bfd_vma bfd_getl64 (const void *p);
static void bfd_putl8 (bfd_vma src,void *p);
static void bfd_putl16 (bfd_vma src,void *p);
static void bfd_putl24(bfd_vma src, void *p);
static void bfd_putl32 (bfd_vma src, void *p);
static void bfd_putl64 (bfd_vma src, void *p);

#define bfd_get(bits, abfd, ptr)                       \
  ((bits) == 8 ? bfd_get_8 (abfd, ptr)                 \
   : (bits) == 16 ? bfd_getl16 (ptr)             \
   : (bits) == 32 ? bfd_getl32 (ptr)             \
   : (bits) == 64 ? bfd_getl64 (ptr)             \
   : (abort (), (bfd_vma) - 1))

#define bfd_put(bits, abfd, val, ptr)                  \
  ((bits) == 8 ? bfd_putl8  ( val, ptr)           \
   : (bits) == 16 ? bfd_putl16 (val, ptr)        \
   : (bits) == 32 ? bfd_putl32 (val, ptr)        \
   : (bits) == 64 ? bfd_putl64 (val, ptr)        \
   : (abort (), (void) 0))


/* Byte swapping macros for file header data.  */
#define bfd_h_put_signed_16 bfd_putl16
#define bfd_h_put_signed_64 bfd_putl64
static uint64_t bfd_getl64 (const void *);
static bfd_vma bfd_getl32 (const void *);
static bfd_vma bfd_getl16 (const void *);
/* Extracted from hash.c.  */
/* An element in the hash table.  Most uses will actually use a larger
   structure, and an instance of this will be the first field.  */
struct bfd_hash_entry {
  /* Next entry for this hash code.  */
  struct bfd_hash_entry *next;
  /* String being hashed.  */
  const char *string;
  /* Hash code.  This is the full hash code, not the index into the
     table.  */
  unsigned long hash;
};

/* A hash table.  */
struct bfd_hash_table {
  /* The hash array.  */
  struct bfd_hash_entry **table;
  /* A function used to create new elements in the hash table.  The
     first entry is itself a pointer to an element.  When this
     function is first invoked, this pointer will be NULL.  However,
     having the pointer permits a hierarchy of method functions to be
     built each of which calls the function in the superclass.  Thus
     each function should be written to allocate a new block of memory
     only if the argument is NULL.  */
  struct bfd_hash_entry *(*newfunc)
    (struct bfd_hash_entry *, struct bfd_hash_table *, const char *);
  /* An objalloc for this hash table.  This is a struct objalloc *,
     but we use void * to avoid requiring the inclusion of objalloc.h.  */
  void *memory;
  /* The number of slots in the hash table.  */
  unsigned int size;
  /* The number of entries in the hash table.  */
  unsigned int count;
  /* The size of elements.  */
  unsigned int entsize;
  /* If non-zero, don't grow the hash table.  */
  unsigned int frozen:1;
};

static bool bfd_hash_table_init_n (struct bfd_hash_table *,
    struct bfd_hash_entry *(* /*newfunc*/)
       (struct bfd_hash_entry *, struct bfd_hash_table *, const char *),
    unsigned int /*entsize*/, unsigned int /*size*/);

static bool bfd_hash_table_init (struct bfd_hash_table *,
    struct bfd_hash_entry *(* /*newfunc*/)
       (struct bfd_hash_entry *, struct bfd_hash_table *, const char *),
    unsigned int /*entsize*/);

static void bfd_hash_table_free (struct bfd_hash_table *);
static struct bfd_hash_entry *bfd_hash_lookup
   (struct bfd_hash_table *, const char *,
    bool /*create*/, bool /*copy*/);

static struct bfd_hash_entry *bfd_hash_insert (struct bfd_hash_table *,
    const char *, unsigned long /*hash*/);

static void bfd_hash_rename (struct bfd_hash_table *,
    const char *, struct bfd_hash_entry *);
static void *bfd_hash_allocate (struct bfd_hash_table *, unsigned int /*size*/);
static struct bfd_hash_entry *bfd_hash_newfunc (struct bfd_hash_entry *,
    struct bfd_hash_table *, const char *);
static struct bfd_hash_entry * bfd_section_hash_newfunc (struct bfd_hash_entry *entry,
			  struct bfd_hash_table *table, const char *string);
/* Extracted from section.c.  */
/* Linenumber stuff.  */
typedef struct lineno_cache_entry {
  unsigned int line_number;    /* Linenumber from start of function.  */
  union {
    struct bfd_symbol *sym;    /* Function name.  */
    bfd_vma offset;            /* Offset into section.  */
  } u;
} alent;

/* ----------------------------------------------------------- Section definition */
typedef struct bfd_section {
  /* The name of the section; the name isn't a copy, the pointer is
     the same as that passed to bfd_make_section.  */
  const char *name;

  /* The next section in the list belonging to the BFD, or NULL.  */
  struct bfd_section *next;

  /* The previous section in the list belonging to the BFD, or NULL.  */
  struct bfd_section *prev;

  /* A unique sequence number.  */
  unsigned int id;

  /* A unique section number which can be used by assembler to
     distinguish different sections with the same section name.  */
  unsigned int section_id;

  /* Which section in the bfd; 0..n-1 as sections are created in a bfd.  */
  unsigned int index;

  /* The field flags contains attributes of the section. Some
     flags are read in from the object file, and some are
     synthesized from other information.  */
  flagword flags;

#define SEC_NO_FLAGS                      0x0

  /* Tells the OS to allocate space for this section when loading.
     This is clear for a section containing debug information only.  */
#define SEC_ALLOC                         0x1

  /* Tells the OS to load the section from the file when loading.
     This is clear for a .bss section.  */
#define SEC_LOAD                          0x2

  /* The section contains data still to be relocated, so there is
     some relocation information too.  */
#define SEC_RELOC                         0x4

  /* A signal to the OS that the section contains read only data.  */
#define SEC_READONLY                      0x8

  /* The section contains code only.  */
#define SEC_CODE                         0x10

  /* The section contains data only.  */
#define SEC_DATA                         0x20

  /* The section will reside in ROM.  */
#define SEC_ROM                          0x40

  /* The section contains constructor information. This section
     type is used by the linker to create lists of constructors and
     destructors used by <<g++>>. When a back end sees a symbol
     which should be used in a constructor list, it creates a new
     section for the type of name (e.g., <<__CTOR_LIST__>>), attaches
     the symbol to it, and builds a relocation. To build the lists
     of constructors, all the linker has to do is catenate all the
     sections called <<__CTOR_LIST__>> and relocate the data
     contained within - exactly the operations it would peform on
     standard data.  */
#define SEC_CONSTRUCTOR                  0x80

  /* The section has contents - a data section could be
     <<SEC_ALLOC>> | <<SEC_HAS_CONTENTS>>; a debug section could be
     <<SEC_HAS_CONTENTS>>  */
#define SEC_HAS_CONTENTS                0x100

  /* An instruction to the linker to not output the section
     even if it has information which would normally be written.  */
#define SEC_NEVER_LOAD                  0x200

  /* The section contains thread local data.  */
#define SEC_THREAD_LOCAL                0x400

  /* The section's size is fixed.  Generic linker code will not
     recalculate it and it is up to whoever has set this flag to
     get the size right.  */
#define SEC_FIXED_SIZE                  0x800

  /* The section contains common symbols (symbols may be defined
     multiple times, the value of a symbol is the amount of
     space it requires, and the largest symbol value is the one
     used).  Most targets have exactly one of these (which we
     translate to bfd_com_section_ptr), but ECOFF has two.  */
#define SEC_IS_COMMON                  0x1000

  /* The section contains only debugging information.  For
     example, this is set for ELF .debug and .stab sections.
     strip tests this flag to see if a section can be
     discarded.  */
#define SEC_DEBUGGING                  0x2000

  /* The contents of this section are held in memory pointed to
     by the contents field.  This is checked by bfd_get_section_contents,
     and the data is retrieved from memory if appropriate.  */
#define SEC_IN_MEMORY                  0x4000

  /* The contents of this section are to be excluded by the
     linker for executable and shared objects unless those
     objects are to be further relocated.  */
#define SEC_EXCLUDE                    0x8000

  /* The contents of this section are to be sorted based on the sum of
     the symbol and addend values specified by the associated relocation
     entries.  Entries without associated relocation entries will be
     appended to the end of the section in an unspecified order.  */
#define SEC_SORT_ENTRIES              0x10000

  /* When linking, duplicate sections of the same name should be
     discarded, rather than being combined into a single section as
     is usually done.  This is similar to how common symbols are
     handled.  See SEC_LINK_DUPLICATES below.  */
#define SEC_LINK_ONCE                 0x20000

  /* If SEC_LINK_ONCE is set, this bitfield describes how the linker
     should handle duplicate sections.  */
#define SEC_LINK_DUPLICATES           0xc0000

  /* This value for SEC_LINK_DUPLICATES means that duplicate
     sections with the same name should simply be discarded.  */
#define SEC_LINK_DUPLICATES_DISCARD       0x0

  /* This value for SEC_LINK_DUPLICATES means that the linker
     should warn if there are any duplicate sections, although
     it should still only link one copy.  */
#define SEC_LINK_DUPLICATES_ONE_ONLY  0x40000

  /* This value for SEC_LINK_DUPLICATES means that the linker
     should warn if any duplicate sections are a different size.  */
#define SEC_LINK_DUPLICATES_SAME_SIZE 0x80000

  /* This value for SEC_LINK_DUPLICATES means that the linker
     should warn if any duplicate sections contain different
     contents.  */
#define SEC_LINK_DUPLICATES_SAME_CONTENTS \
  (SEC_LINK_DUPLICATES_ONE_ONLY | SEC_LINK_DUPLICATES_SAME_SIZE)

  /* This section was created by the linker as part of dynamic
     relocation or other arcane processing.  It is skipped when
     going through the first-pass output, trusting that someone
     else up the line will take care of it later.  */
#define SEC_LINKER_CREATED           0x100000

  /* This section contains a section ID to distinguish different
     sections with the same section name.  */
#define SEC_ASSEMBLER_SECTION_ID     0x100000

  /* This section should not be subject to garbage collection.
     Also set to inform the linker that this section should not be
     listed in the link map as discarded.  */
#define SEC_KEEP                     0x200000

  /* This section contains "short" data, and should be placed
     "near" the GP.  */
#define SEC_SMALL_DATA               0x400000

  /* Attempt to merge identical entities in the section.
     Entity size is given in the entsize field.  */
#define SEC_MERGE                    0x800000

  /* If given with SEC_MERGE, entities to merge are zero terminated
     strings where entsize specifies character size instead of fixed
     size entries.  */
#define SEC_STRINGS                 0x1000000

  /* This section contains data about section groups.  */
#define SEC_GROUP                   0x2000000

  /* The section is a COFF shared library section.  This flag is
     only for the linker.  If this type of section appears in
     the input file, the linker must copy it to the output file
     without changing the vma or size.  FIXME: Although this
     was originally intended to be general, it really is COFF
     specific (and the flag was renamed to indicate this).  It
     might be cleaner to have some more general mechanism to
     allow the back end to control what the linker does with
     sections.  */
#define SEC_COFF_SHARED_LIBRARY     0x4000000

  /* This input section should be copied to output in reverse order
     as an array of pointers.  This is for ELF linker internal use
     only.  */
#define SEC_ELF_REVERSE_COPY        0x4000000

  /* This section contains data which may be shared with other
     executables or shared objects. This is for COFF only.  */
#define SEC_COFF_SHARED             0x8000000

  /* Indicate that section has the purecode flag set.  */
#define SEC_ELF_PURECODE            0x8000000

  /* When a section with this flag is being linked, then if the size of
     the input section is less than a page, it should not cross a page
     boundary.  If the size of the input section is one page or more,
     it should be aligned on a page boundary.  This is for TI
     TMS320C54X only.  */
#define SEC_TIC54X_BLOCK           0x10000000

  /* Conditionally link this section; do not link if there are no
     references found to any symbol in the section.  This is for TI
     TMS320C54X only.  */
#define SEC_TIC54X_CLINK           0x20000000

  /* This section contains vliw code.  This is for Toshiba MeP only.  */
#define SEC_MEP_VLIW               0x20000000

  /* All symbols, sizes and relocations in this section are octets
     instead of bytes.  Required for DWARF debug sections as DWARF
     information is organized in octets, not bytes.  */
#define SEC_ELF_OCTETS             0x40000000

  /* Indicate that section has the no read flag set. This happens
     when memory read flag isn't set. */
#define SEC_COFF_NOREAD            0x40000000

  /*  End of section flags.  */

  /* Some internal packed boolean fields.  */
  /* See the vma field.  */
  unsigned int user_set_vma : 1;

  /* A mark flag used by some of the linker backends.  */
  unsigned int linker_mark : 1;

  /* Another mark flag used by some of the linker backends.  Set for
     output sections that have an input section.  */
  unsigned int linker_has_input : 1;

  /* Mark flag used by some linker backends for garbage collection.  */
  unsigned int gc_mark : 1;

  /* Section compression status.  */
  unsigned int compress_status : 2;
#define COMPRESS_SECTION_NONE    0
#define COMPRESS_SECTION_DONE    1
#define DECOMPRESS_SECTION_ZLIB  2
#define DECOMPRESS_SECTION_ZSTD  3

  /* The following flags are used by the ELF linker. */
  /* Mark sections which have been allocated to segments.  */
  unsigned int segment_mark : 1;

  /* Type of sec_info information.  */
  unsigned int sec_info_type:3;
#define SEC_INFO_TYPE_NONE      0
#define SEC_INFO_TYPE_STABS     1
#define SEC_INFO_TYPE_MERGE     2
#define SEC_INFO_TYPE_EH_FRAME  3
#define SEC_INFO_TYPE_JUST_SYMS 4
#define SEC_INFO_TYPE_TARGET    5
#define SEC_INFO_TYPE_EH_FRAME_ENTRY 6
#define SEC_INFO_TYPE_SFRAME  7

  /* Nonzero if this section uses RELA relocations, rather than REL.  */
  unsigned int use_rela_p:1;

  /* Bits used by various backends.  The generic code doesn't touch
     these fields.  */

  unsigned int sec_flg0:1;
  unsigned int sec_flg1:1;
  unsigned int sec_flg2:1;
  unsigned int sec_flg3:1;
  unsigned int sec_flg4:1;
  unsigned int sec_flg5:1;

  /* End of internal packed boolean fields.  */

  /*  The virtual memory address of the section - where it will be
      at run time.  The symbols are relocated against this.  The
      user_set_vma flag is maintained by bfd; if it's not set, the
      backend can assign addresses (for example, in <<a.out>>, where
      the default address for <<.data>> is dependent on the specific
      target and various flags).  */
  bfd_vma vma;

  /*  The load address of the section - where it would be in a
      rom image; really only used for writing section header
      information.  */
  bfd_vma lma;

  /* The size of the section in *octets*, as it will be output.
     Contains a value even if the section has no contents (e.g., the
     size of <<.bss>>).  */
  size_t size;

  /* For input sections, the original size on disk of the section, in
     octets.  This field should be set for any section whose size is
     changed by linker relaxation.  It is required for sections where
     the linker relaxation scheme doesn't cache altered section and
     reloc contents (stabs, eh_frame, SEC_MERGE, some coff relaxing
     targets), and thus the original size needs to be kept to read the
     section multiple times.  For output sections, rawsize holds the
     section size calculated on a previous linker relaxation pass.  */
  size_t rawsize;

  /* The compressed size of the section in octets.  */
  size_t compressed_size;

  /* If this section is going to be output, then this value is the
     offset in *bytes* into the output section of the first byte in the
     input section (byte ==> smallest addressable unit on the
     target).  In most cases, if this was going to start at the
     100th octet (8-bit quantity) in the output section, this value
     would be 100.  However, if the target byte size is 16 bits
     (bfd_octets_per_byte is "2"), this value would be 50.  */
  bfd_vma output_offset;

  /* The output section through which to map on output.  */
  struct bfd_section *output_section;

  /* If an input section, a pointer to a vector of relocation
     records for the data in this section.  */
  struct reloc_cache_entry *relocation;

  /* If an output section, a pointer to a vector of pointers to
     relocation records for the data in this section.  */
  struct reloc_cache_entry **orelocation;

  /* The number of relocation records in one of the above.  */
  unsigned reloc_count;

  /* The alignment requirement of the section, as an exponent of 2 -
     e.g., 3 aligns to 2^3 (or 8).  */
  unsigned int alignment_power;

  /* Information below is back end specific - and not always used
     or updated.  */

  /* File position of section data.  */
  file_ptr filepos;

  /* File position of relocation info.  */
  file_ptr rel_filepos;

  /* File position of line data.  */
  file_ptr line_filepos;

  /* Pointer to data for applications.  */
  void *userdata;

  /* If the SEC_IN_MEMORY flag is set, this points to the actual
     contents.  */
  bfd_byte *contents;

  /* Attached line number information.  */
  alent *lineno;

  /* Number of line number records.  */
  unsigned int lineno_count;

  /* Entity size for merging purposes.  */
  unsigned int entsize;

  /* Points to the kept section if this section is a link-once section,
     and is discarded.  */
  struct bfd_section *kept_section;

  /* When a section is being output, this value changes as more
     linenumbers are written out.  */
  file_ptr moving_line_filepos;

  /* What the section number is in the target world.  */
  int target_index;

  void *used_by_bfd;

  /* If this is a constructor section then here is a list of the
     relocations created to relocate items within it.  */
  struct relent_chain *constructor_chain;

  /* The BFD which owns the section.  */
  bfd *owner;

  /* A symbol which points at this section only.  */
  struct bfd_symbol *symbol;
  struct bfd_symbol **symbol_ptr_ptr;

  /* Early in the link process, map_head and map_tail are used to build
     a list of input sections attached to an output section.  Later,
     output sections use these fields for a list of bfd_link_order
     structs.  The linked_to_symbol_name field is for ELF assembler
     internal use.  */
  union {
    struct bfd_link_order *link_order;
    struct bfd_section *s;
    const char *linked_to_symbol_name;
  } map_head, map_tail;

  /* Points to the output section this section is already assigned to,
     if any.  This is used when support for non-contiguous memory
     regions is enabled.  */
  struct bfd_section *already_assigned;

  /* Explicitly specified section type, if non-zero.  */
  unsigned int type;

} asection; /* ======================================= end of section definition */

static inline const char * bfd_section_name (const asection *sec)
{ return sec->name; }

static inline size_t bfd_section_size (const asection *sec)
{ return sec->size; }

static inline bfd_vma bfd_section_vma (const asection *sec)
{ return sec->vma; }

static inline bfd_vma bfd_section_lma (const asection *sec)
{ return sec->lma; }

static inline unsigned int bfd_section_alignment (const asection *sec)
{ return sec->alignment_power; }

static inline flagword bfd_section_flags (const asection *sec)
{ return sec->flags; }

static inline void * bfd_section_userdata (const asection *sec)
{ return sec->userdata; }
static inline bool bfd_is_com_section (const asection *sec)
{ return (sec->flags & SEC_IS_COMMON) != 0; }

/* Note: the following are provided as inline functions rather than macros
   because not all callers use the return value.  A macro implementation
   would use a comma expression, eg: "((ptr)->foo = val, TRUE)" and some
   compilers will complain about comma expressions that have no effect.  */
static inline bool bfd_set_section_userdata (asection *sec, void *val)
{ sec->userdata = val; return true; }

static inline bool bfd_set_section_vma (asection *sec, bfd_vma val)
{ sec->vma = sec->lma = val; sec->user_set_vma = true; return true; }

static inline bool bfd_set_section_lma (asection *sec, bfd_vma val)
{ sec->lma = val; return true; }

static inline bool bfd_set_section_alignment (asection *sec, unsigned int val)
{
  if (val >= sizeof (bfd_vma) * 8 - 1) return false;
  sec->alignment_power = val;
  return true;
}

/* These sections are global, and are managed by BFD.  The application
   and target back end are not permitted to change the values in
   these sections.  */
#define BFD_ABS_SECTION_NAME "*ABS*"
#define BFD_UND_SECTION_NAME "*UND*"
#define BFD_COM_SECTION_NAME "*COM*"
#define BFD_IND_SECTION_NAME "*IND*"

struct bfd_symbol;
#define BFD_FAKE_SECTION(SEC, SYM, NAME, IDX, FLAGS)                   \
  /* name, next, prev, id,  section_id, index, flags, user_set_vma, */ \
  {  NAME, NULL, NULL, IDX, 0,          0,     FLAGS, 0,               \
								       \
  /* linker_mark, linker_has_input, gc_mark, decompress_status,     */ \
     0,           0,                1,       0,                        \
								       \
  /* segment_mark, sec_info_type, use_rela_p,                       */ \
     0,            0,             0,                                   \
								       \
  /* sec_flg0, sec_flg1, sec_flg2, sec_flg3, sec_flg4, sec_flg5,    */ \
     0,        0,        0,        0,        0,        0,              \
								       \
  /* vma, lma, size, rawsize, compressed_size,                      */ \
     0,   0,   0,    0,       0,                                       \
								       \
  /* output_offset, output_section, relocation, orelocation,        */ \
     0,             &SEC,           NULL,       NULL,                  \
								       \
  /* reloc_count, alignment_power, filepos, rel_filepos,            */ \
     0,           0,               0,       0,                         \
								       \
  /* line_filepos, userdata, contents, lineno, lineno_count,        */ \
     0,            NULL,     NULL,     NULL,   0,                      \
								       \
  /* entsize, kept_section, moving_line_filepos,                    */ \
     0,       NULL,         0,                                         \
								       \
  /* target_index, used_by_bfd, constructor_chain, owner,           */ \
     0,            NULL,        NULL,              NULL,               \
								       \
  /* symbol,                    symbol_ptr_ptr,                     */ \
     (struct bfd_symbol *) SYM, &SEC.symbol,                           \
								       \
  /* map_head, map_tail, already_assigned, type                     */ \
     { NULL }, { NULL }, NULL,             0                           \
								       \
    }
/* ------------------------------------------------------ symbol definition */
/* These symbols are global, not specific to any BFD.  Therefore, anything
   that tries to change them is broken, and should be repaired.  */
typedef struct bfd_symbol {
  /* A pointer to the BFD which owns the symbol. This information
     is necessary so that a back end can work out what additional
     information (invisible to the application writer) is carried
     with the symbol.

     This field is *almost* redundant, since you can use section->owner
     instead, except that some symbols point to the global sections
     bfd_{abs,com,und}_section.  This could be fixed by making
     these globals be per-bfd (or per-target-flavor).  FIXME.  */
  struct bfd *the_bfd; /* Use bfd_asymbol_bfd(sym) to access this field.  */

  /* The text of the symbol. The name is left alone, and not copied; the
     application may not alter it.  */
  const char *name;

  /* The value of the symbol.  This really should be a union of a
     numeric value with a pointer, since some flags indicate that
     a pointer to another symbol is stored here.  */
  symvalue value;

  /* Attributes of a symbol.  */
#define BSF_NO_FLAGS            0

  /* The symbol has local scope; <<static>> in <<C>>. The value
     is the offset into the section of the data.  */
#define BSF_LOCAL               (1 << 0)

  /* The symbol has global scope; initialized data in <<C>>. The
     value is the offset into the section of the data.  */
#define BSF_GLOBAL              (1 << 1)

  /* The symbol has global scope and is exported. The value is
     the offset into the section of the data.  */
#define BSF_EXPORT              BSF_GLOBAL /* No real difference.  */

  /* A normal C symbol would be one of:
     <<BSF_LOCAL>>, <<BSF_UNDEFINED>> or <<BSF_GLOBAL>>.  */

  /* The symbol is a debugging record. The value has an arbitrary
     meaning, unless BSF_DEBUGGING_RELOC is also set.  */
#define BSF_DEBUGGING           (1 << 2)

  /* The symbol denotes a function entry point.  Used in ELF,
     perhaps others someday.  */
#define BSF_FUNCTION            (1 << 3)

  /* Used by the linker.  */
#define BSF_KEEP                (1 << 5)

  /* An ELF common symbol.  */
#define BSF_ELF_COMMON          (1 << 6)

  /* A weak global symbol, overridable without warnings by
     a regular global symbol of the same name.  */
#define BSF_WEAK                (1 << 7)

  /* This symbol was created to point to a section, e.g. ELF's
     STT_SECTION symbols.  */
#define BSF_SECTION_SYM         (1 << 8)

  /* The symbol used to be a common symbol, but now it is
     allocated.  */
#define BSF_OLD_COMMON          (1 << 9)

  /* In some files the type of a symbol sometimes alters its
     location in an output file - ie in coff a <<ISFCN>> symbol
     which is also <<C_EXT>> symbol appears where it was
     declared and not at the end of a section.  This bit is set
     by the target BFD part to convey this information.  */
#define BSF_NOT_AT_END          (1 << 10)

  /* Signal that the symbol is the label of constructor section.  */
#define BSF_CONSTRUCTOR         (1 << 11)

  /* Signal that the symbol is a warning symbol.  The name is a
     warning.  The name of the next symbol is the one to warn about;
     if a reference is made to a symbol with the same name as the next
     symbol, a warning is issued by the linker.  */
#define BSF_WARNING             (1 << 12)

  /* Signal that the symbol is indirect.  This symbol is an indirect
     pointer to the symbol with the same name as the next symbol.  */
#define BSF_INDIRECT            (1 << 13)

  /* BSF_FILE marks symbols that contain a file name.  This is used
     for ELF STT_FILE symbols.  */
#define BSF_FILE                (1 << 14)

  /* Symbol is from dynamic linking information.  */
#define BSF_DYNAMIC             (1 << 15)

  /* The symbol denotes a data object.  Used in ELF, and perhaps
     others someday.  */
#define BSF_OBJECT              (1 << 16)

  /* This symbol is a debugging symbol.  The value is the offset
     into the section of the data.  BSF_DEBUGGING should be set
     as well.  */
#define BSF_DEBUGGING_RELOC     (1 << 17)

  /* This symbol is thread local.  Used in ELF.  */
#define BSF_THREAD_LOCAL        (1 << 18)

  /* This symbol represents a complex relocation expression,
     with the expression tree serialized in the symbol name.  */
#define BSF_RELC                (1 << 19)

  /* This symbol represents a signed complex relocation expression,
     with the expression tree serialized in the symbol name.  */
#define BSF_SRELC               (1 << 20)

  /* This symbol was created by bfd_get_synthetic_symtab.  */
#define BSF_SYNTHETIC           (1 << 21)

  /* This symbol is an indirect code object.  Unrelated to BSF_INDIRECT.
     The dynamic linker will compute the value of this symbol by
     calling the function that it points to.  BSF_FUNCTION must
     also be also set.  */
#define BSF_GNU_INDIRECT_FUNCTION (1 << 22)
  /* This symbol is a globally unique data object.  The dynamic linker
     will make sure that in the entire process there is just one symbol
     with this name and type in use.  BSF_OBJECT must also be set.  */
#define BSF_GNU_UNIQUE          (1 << 23)

  /* This section symbol should be included in the symbol table.  */
#define BSF_SECTION_SYM_USED    (1 << 24)

  flagword flags;

  /* A pointer to the section to which this symbol is
     relative.  This will always be non NULL, there are special
     sections for undefined and absolute symbols.  */
  struct bfd_section *section;

  /* Back end special data.  */
  union {
      void *p;
      bfd_vma i;
    }
  udata;
} asymbol; /* ===================================== end of symbol definition */

static asection _bfd_std_section[];
/* Pointer to the common section.  */
#define bfd_com_section_ptr (&_bfd_std_section[0])
/* Pointer to the undefined section.  */
#define bfd_und_section_ptr (&_bfd_std_section[1])
/* Pointer to the absolute section.  */
#define bfd_abs_section_ptr (&_bfd_std_section[2])
/* Pointer to the indirect section.  */
#define bfd_ind_section_ptr (&_bfd_std_section[3])

#define GLOBAL_SYM_INIT(NAME, SECTION)  { 0, NAME, 0, BSF_SECTION_SYM, SECTION, { 0 }}
static const asymbol global_syms[] = {
  GLOBAL_SYM_INIT (BFD_COM_SECTION_NAME, bfd_com_section_ptr),
  GLOBAL_SYM_INIT (BFD_UND_SECTION_NAME, bfd_und_section_ptr),
  GLOBAL_SYM_INIT (BFD_ABS_SECTION_NAME, bfd_abs_section_ptr),
  GLOBAL_SYM_INIT (BFD_IND_SECTION_NAME, bfd_ind_section_ptr)
};
#define STD_SECTION(NAME, IDX, FLAGS) \
  BFD_FAKE_SECTION(_bfd_std_section[IDX], &global_syms[IDX], NAME, IDX, FLAGS)

static asection _bfd_std_section[] = {
  STD_SECTION (BFD_COM_SECTION_NAME, 0, SEC_IS_COMMON),
  STD_SECTION (BFD_UND_SECTION_NAME, 1, 0),
  STD_SECTION (BFD_ABS_SECTION_NAME, 2, 0),
  STD_SECTION (BFD_IND_SECTION_NAME, 3, 0)
};
#undef STD_SECTION
static inline bool bfd_is_und_section (const asection *sec)
{ return sec == bfd_und_section_ptr; }

static inline bool bfd_is_abs_section (const asection *sec)
{ return sec == bfd_abs_section_ptr; }

static inline bool bfd_is_ind_section (const asection *sec)
{ return sec == bfd_ind_section_ptr; }

static inline bool bfd_is_const_section (const asection *sec)
{
  return (sec >= _bfd_std_section
	  && sec < _bfd_std_section + (sizeof (_bfd_std_section)
				       / sizeof (_bfd_std_section[0])));
}

/* Return TRUE if input section SEC has been discarded.  */
static inline bool discarded_section (const asection *sec)
{
  return (!bfd_is_abs_section (sec)
	  && bfd_is_abs_section (sec->output_section)
	  && sec->sec_info_type != SEC_INFO_TYPE_MERGE
	  && sec->sec_info_type != SEC_INFO_TYPE_JUST_SYMS);
}
/* We use a macro to initialize the static asymbol structures because
   traditional C does not permit us to initialize a union member while
   gcc warns if we don't initialize it.
   the_bfd, name, value, attr, section [, udata]  */
#ifdef __STDC__
#define GLOBAL_SYM_INIT(NAME, SECTION) \
  { 0, NAME, 0, BSF_SECTION_SYM, SECTION, { 0 }}
#else
#define GLOBAL_SYM_INIT(NAME, SECTION) \
  { 0, NAME, 0, BSF_SECTION_SYM, SECTION }
#endif

static asection *bfd_get_section_by_name (bfd *abfd, const char *name);
static asection *bfd_get_section_by_name_if (bfd *abfd, const char *name,
    bool (*func) (bfd *abfd, asection *sect, void *obj), void *obj);
static asection *make_section_old_way (bfd *abfd, const char *name);
static asection *make_section_anyway (bfd *abfd, const char *name);
static void bfd_rename_section (asection *sec, const char *newname);
static bool set_section_contents (bfd *abfd, asection *section, const void *data,
    file_ptr offset, size_t count);
const char *bfd_generic_group_name (bfd *, const asection *sec);

/* Extracted from syms.c.  */
/* Information about a symbol that nm needs.  */
typedef struct _symbol_info {
  symvalue value;
  char type;
  const char *name;            /* Symbol name.  */
  unsigned char stab_type;     /* Stab type.  */
  char stab_other;             /* Stab other.  */
  short stab_desc;             /* Stab desc.  */
  const char *stab_name;       /* String for stab type.  */
} symbol_info;

static asymbol *elf_make_empty_symbol(bfd *);
static bool is_local_label (asymbol *sym);
static bool is_local_label_name (const char *name);
static bool bfd_set_symtab (bfd *abfd, asymbol **location, unsigned int count);
/* Extracted from archive.c.  */
/* A canonical archive symbol.  */
/* This is a type pun with struct symdef/struct ranlib on purpose!  */
typedef struct carsym {
  const char *name;
  file_ptr file_offset;        /* Look here to find the file.  */
} carsym;

/* A count of carsyms (canonical archive symbols).  */
 typedef unsigned long symindex;
#define BFD_NO_MORE_SYMBOLS ((symindex) ~0)

/* Extracted from archures.c.  */
enum bfd_architecture {
  bfd_arch_unknown,   /* File arch not known.  */
  bfd_arch_obscure,   /* Arch known, not one of these.  */
  bfd_arch_riscv=63,
#define bfd_mach_riscv32	132
#define bfd_mach_riscv64	164
  bfd_arch_last=87
  };

typedef struct bfd_arch_info {
  int bits_per_word;
  int bits_per_address;
  int bits_per_byte;
  enum bfd_architecture arch;
  unsigned long mach;
  const char *arch_name;
  const char *printable_name;
  unsigned int section_align_power;
  /* TRUE if this is the default machine for the architecture.
     The default arch should be the first entry for an arch so that
     all the entries for that arch can be accessed via <<next>>.  */
  bool the_default;
  const struct bfd_arch_info * (*compatible) (const struct bfd_arch_info *,
					      const struct bfd_arch_info *);

  bool (*scan) (const struct bfd_arch_info *, const char *);

  /* Allocate via bfd_malloc and return a fill buffer of size COUNT.  If
     IS_BIGENDIAN is TRUE, the order of bytes is big endian.  If CODE is
     TRUE, the buffer contains code.  */
  void *(*fill) (size_t count, bool is_bigendian, bool code);

  const struct bfd_arch_info *next;

  /* On some architectures the offset for a relocation can point into
     the middle of an instruction.  This field specifies the maximum
     offset such a relocation can have (in octets).  This affects the
     behaviour of the disassembler, since a value greater than zero
     means that it may need to disassemble an instruction twice, once
     to get its length and then a second time to display it.  If the
     value is negative then this has to be done for every single
     instruction, regardless of the offset of the reloc.  */
  signed int max_reloc_offset_into_insn;
}
bfd_arch_info_type;

static bool bfd_default_set_arch_mach (bfd *abfd, 
				enum bfd_architecture arch, unsigned long mach);
enum bfd_architecture bfd_get_arch (const bfd *abfd);

/* Extracted from bfd.c.  */
typedef enum bfd_format {
    bfd_unknown = 0,   /* File format is unknown.  */
    bfd_object,        /* Linker/assembler/compiler output.  */
    bfd_archive,       /* Object archive file.  */
    bfd_core,          /* Core dump.  */
    bfd_type_end       /* Marks the end; don't use it!  */
} bfd_format;

enum bfd_direction {
    no_direction = 0,
    read_direction = 1,
    write_direction = 2,
    both_direction = 3
};

enum bfd_plugin_format {
    bfd_plugin_unknown = 0,
    bfd_plugin_yes = 1,
    bfd_plugin_no = 2
};

struct bfd_build_id {
    size_t size;
    bfd_byte data[1];
};

struct bfd {
  /* The filename the application opened the BFD with.  */
  const char *filename;

  /* A pointer to the target jump table.  */
  const struct bfd_target *xvec;

  /* The IOSTREAM, and corresponding IO vector that provide access
     to the file backing the BFD.  */
  void *iostream;
  const struct bfd_iovec *iovec;

  /* The caching routines use these to maintain a
     least-recently-used list of BFDs.  */
  struct bfd *lru_prev, *lru_next;

  /* Track current file position (or current buffer offset for
     in-memory BFDs).  When a file is closed by the caching routines,
     BFD retains state information on the file here.  */
  ufile_ptr where;

  /* File modified time, if mtime_set is TRUE.  */
  long mtime;

  /* A unique identifier of the BFD  */
  unsigned int id;

  /* Format_specific flags.  */
  flagword flags;

  /* Values that may appear in the flags field of a BFD.  These also
     appear in the object_flags field of the bfd_target structure, where
     they indicate the set of flags used by that backend (not all flags
     are meaningful for all object file formats) (FIXME: at the moment,
     the object_flags values have mostly just been copied from backend
     to another, and are not necessarily correct).  */

#define BFD_NO_FLAGS                0x0

  /* BFD contains relocation entries.  */
#define HAS_RELOC                   0x1

  /* BFD is directly executable.  */
#define EXEC_P                      0x2

  /* BFD has line number information (basically used for F_LNNO in a
     COFF header).  */
#define HAS_LINENO                  0x4

  /* BFD has debugging information.  */
#define HAS_DEBUG                  0x08

  /* BFD has symbols.  */
#define HAS_SYMS                   0x10

  /* BFD has local symbols (basically used for F_LSYMS in a COFF
     header).  */
#define HAS_LOCALS                 0x20

  /* BFD is a dynamic object.  */
#define DYNAMIC                    0x40

  /* Text section is write protected (if D_PAGED is not set, this is
     like an a.out NMAGIC file) (the linker sets this by default, but
     clears it for -r or -N).  */
#define WP_TEXT                    0x80

  /* BFD is dynamically paged (this is like an a.out ZMAGIC file) (the
     linker sets this by default, but clears it for -r or -n or -N).  */
#define D_PAGED                   0x100

  /* BFD is relaxable (this means that bfd_relax_section may be able to
     do something) (sometimes bfd_relax_section can do something even if
     this is not set).  */
#define BFD_IS_RELAXABLE          0x200

  /* This may be set before writing out a BFD to request using a
     traditional format.  For example, this is used to request that when
     writing out an a.out object the symbols not be hashed to eliminate
     duplicates.  */
#define BFD_TRADITIONAL_FORMAT    0x400

  /* This flag indicates that the BFD contents are actually cached
     in memory.  If this is set, iostream points to a bfd_in_memory
     struct.  */
#define BFD_IN_MEMORY             0x800

  /* This BFD has been created by the linker and doesn't correspond
     to any input file.  */
#define BFD_LINKER_CREATED       0x1000

  /* This may be set before writing out a BFD to request that it
     be written using values for UIDs, GIDs, timestamps, etc. that
     will be consistent from run to run.  */
#define BFD_DETERMINISTIC_OUTPUT 0x2000

  /* Compress sections in this BFD.  */
#define BFD_COMPRESS             0x4000

  /* Decompress sections in this BFD.  */
#define BFD_DECOMPRESS           0x8000

  /* BFD is a dummy, for plugins.  */
#define BFD_PLUGIN              0x10000

  /* Compress sections in this BFD with SHF_COMPRESSED from gABI.  */
#define BFD_COMPRESS_GABI       0x20000

  /* Convert ELF common symbol type to STT_COMMON or STT_OBJECT in this
     BFD.  */
#define BFD_CONVERT_ELF_COMMON  0x40000

  /* Use the ELF STT_COMMON type in this BFD.  */
#define BFD_USE_ELF_STT_COMMON  0x80000

  /* Put pathnames into archives (non-POSIX).  */
#define BFD_ARCHIVE_FULL_PATH  0x100000

#define BFD_CLOSED_BY_CACHE    0x200000
  /* Compress sections in this BFD with SHF_COMPRESSED zstd.  */
#define BFD_COMPRESS_ZSTD      0x400000

  /* Flags bits which are for BFD use only.  */
#define BFD_FLAGS_FOR_BFD_USE_MASK \
  (BFD_IN_MEMORY | BFD_COMPRESS | BFD_DECOMPRESS | BFD_LINKER_CREATED \
   | BFD_PLUGIN | BFD_TRADITIONAL_FORMAT | BFD_DETERMINISTIC_OUTPUT \
   | BFD_COMPRESS_GABI | BFD_CONVERT_ELF_COMMON | BFD_USE_ELF_STT_COMMON)

  /* The format which belongs to the BFD. (object, core, etc.)  */
  ENUM_BITFIELD (bfd_format) format : 3;

  /* The direction with which the BFD was opened.  */
  ENUM_BITFIELD (bfd_direction) direction : 2;

  /* Is the file descriptor being cached?  That is, can it be closed as
     needed, and re-opened when accessed later?  */
  unsigned int cacheable : 1;

  /* Marks whether there was a default target specified when the
     BFD was opened. This is used to select which matching algorithm
     to use to choose the back end.  */
  unsigned int target_defaulted : 1;

  /* ... and here: (``once'' means at least once).  */
  unsigned int opened_once : 1;

  /* Set if we have a locally maintained mtime value, rather than
     getting it from the file each time.  */
  unsigned int mtime_set : 1;

  /* Flag set if symbols from this BFD should not be exported.  */
  unsigned int no_export : 1;

  /* Remember when output has begun, to stop strange things
     from happening.  */
  unsigned int output_has_begun : 1;

  /* Have archive map.  */
  unsigned int has_armap : 1;

  /* Set if this is a thin archive.  */
  unsigned int is_thin_archive : 1;

  /* Set if this archive should not cache element positions.  */
  unsigned int no_element_cache : 1;

  /* Set if only required symbols should be added in the link hash table for
     this object.  Used by VMS linkers.  */
  unsigned int selective_search : 1;

  /* Set if this is the linker output BFD.  */
  unsigned int is_linker_output : 1;

  /* Set if this is the linker input BFD.  */
  unsigned int is_linker_input : 1;

  /* If this is an input for a compiler plug-in library.  */
  ENUM_BITFIELD (bfd_plugin_format) plugin_format : 2;

  /* Set if this is a plugin output file.  */
  unsigned int lto_output : 1;

  /* Set if this is a slim LTO object not loaded with a compiler plugin.  */
  unsigned int lto_slim_object : 1;

  /* Do not attempt to modify this file.  Set when detecting errors
     that BFD is not prepared to handle for objcopy/strip.  */
  unsigned int read_only : 1;

  /* Set to dummy BFD created when claimed by a compiler plug-in
     library.  */
  bfd *plugin_dummy_bfd;

  /* The offset of this bfd in the file, typically 0 if it is not
     contained in an archive.  */
  ufile_ptr origin;

  /* The origin in the archive of the proxy entry.  This will
     normally be the same as origin, except for thin archives,
     when it will contain the current offset of the proxy in the
     thin archive rather than the offset of the bfd in its actual
     container.  */
  ufile_ptr proxy_origin;

  /* A hash table for section names.  */
  struct bfd_hash_table section_htab;

  /* Pointer to linked list of sections.  */
  struct bfd_section *sections;

  /* The last section on the section list.  */
  struct bfd_section *section_last;

  /* The number of sections.  */
  unsigned int section_count;

  /* The archive plugin file descriptor.  */
  int archive_plugin_fd;

  /* The number of opens on the archive plugin file descriptor.  */
  unsigned int archive_plugin_fd_open_count;

  /* A field used by _bfd_generic_link_add_archive_symbols.  This will
     be used only for archive elements.  */
  int archive_pass;

  /* The total size of memory from bfd_alloc.  */
  size_t alloc_size;

  /* Stuff only useful for object files:
     The start address.  */
  bfd_vma start_address;

  /* Symbol table for output BFD (with symcount entries).
     Also used by the linker to cache input BFD symbols.  */
  struct bfd_symbol **outsymbols;

  /* Used for input and output.  */
  unsigned int symcount;

  /* Used for slurped dynamic symbol tables.  */
  unsigned int dynsymcount;

  /* Pointer to structure which contains architecture information.  */
  const struct bfd_arch_info *arch_info;

  /* Cached length of file for bfd_get_size.  0 until bfd_get_size is
     called, 1 if stat returns an error or the file size is too large to
     return in ufile_ptr.  Both 0 and 1 should be treated as "unknown".  */
  ufile_ptr size;

  /* Stuff only useful for archives.  */
  void *arelt_data;
  struct bfd *my_archive;      /* The containing archive BFD.  */
  struct bfd *archive_next;    /* The next BFD in the archive.  */
  struct bfd *archive_head;    /* The first BFD in the archive.  */
  struct bfd *nested_archives; /* List of nested archive in a flattened
				  thin archive.  */

  union {
    /* For input BFDs, a chain of BFDs involved in a link.  */
    struct bfd *next;
    /* For output BFD, the linker hash table.  */
    struct bfd_link_hash_table *hash;
  } link;

  /* Used by the back end to hold private data.  */
  union {
      struct aout_data_struct *aout_data;
      struct artdata *aout_ar_data;
      struct coff_tdata *coff_obj_data;
      struct pe_tdata *pe_obj_data;
      struct xcoff_tdata *xcoff_obj_data;
      struct ecoff_tdata *ecoff_obj_data;
      struct srec_data_struct *srec_data;
      struct verilog_data_struct *verilog_data;
      struct ihex_data_struct *ihex_data;
      struct tekhex_data_struct *tekhex_data;
      struct elf_obj_tdata *elf_obj_data;
      struct mmo_data_struct *mmo_data;
      struct trad_core_struct *trad_core_data;
      struct som_data_struct *som_data;
      struct hpux_core_struct *hpux_core_data;
      struct hppabsd_core_struct *hppabsd_core_data;
      struct sgi_core_struct *sgi_core_data;
      struct lynx_core_struct *lynx_core_data;
      struct osf_core_struct *osf_core_data;
      struct cisco_core_struct *cisco_core_data;
      struct netbsd_core_struct *netbsd_core_data;
      struct mach_o_data_struct *mach_o_data;
      struct mach_o_fat_data_struct *mach_o_fat_data;
      struct plugin_data_struct *plugin_data;
      struct bfd_pef_data_struct *pef_data;
      struct bfd_pef_xlib_data_struct *pef_xlib_data;
      struct bfd_sym_data_struct *sym_data;
      void *any;
  } tdata;

  /* Used by the application to hold private data.  */
  void *usrdata;

  /* Where all the allocated stuff under this BFD goes.  This is a
     struct objalloc *, but we use void * to avoid requiring the inclusion
     of objalloc.h.  */
  void *memory;

  /* For input BFDs, the build ID, if the object has one. */
  const struct bfd_build_id *build_id;
};

static int elf_get_default_section_type(unsigned);

static inline const char * bfd_get_filename (const bfd *abfd)
{ return abfd->filename; }

static inline bool bfd_get_cacheable (const bfd *abfd)
{ return abfd->cacheable; }

static inline enum bfd_format bfd_get_format (const bfd *abfd)
{ return abfd->format; }

static inline flagword
bfd_get_file_flags (const bfd *abfd)
{
  return abfd->flags;
}

static inline bfd_vma
bfd_get_start_address (const bfd *abfd)
{
  return abfd->start_address;
}

static inline unsigned int bfd_get_symcount (const bfd *abfd)
{
  return abfd->symcount;
}

static inline unsigned int bfd_get_dynamic_symcount (const bfd *abfd)
{
  return abfd->dynsymcount;
}

static inline struct bfd_symbol ** bfd_get_outsymbols (const bfd *abfd)
{ return abfd->outsymbols; }

static inline unsigned int bfd_count_sections (const bfd *abfd)
{ return abfd->section_count; }

static inline bool bfd_has_map (const bfd *abfd)
{ return abfd->has_armap; }

static inline bool bfd_is_thin_archive (const bfd *abfd)
{ return abfd->is_thin_archive; }

static inline void * bfd_usrdata (const bfd *abfd)
{ return abfd->usrdata; }

/* See note beside bfd_set_section_userdata.  */
static inline bool bfd_set_cacheable (bfd * abfd, bool val)
{ abfd->cacheable = val; return true; }

static inline void bfd_set_thin_archive (bfd *abfd, bool val)
{ abfd->is_thin_archive = val; }

static inline void bfd_set_usrdata (bfd *abfd, void *val)
{
  abfd->usrdata = val;
}

static inline asection * bfd_asymbol_section (const asymbol *sy)
{
  return sy->section;
}

static inline bfd_vma bfd_asymbol_value (const asymbol *sy)
{
  return sy->section->vma + sy->value;
}

static inline const char * bfd_asymbol_name (const asymbol *sy)
{
  return sy->name;
}

static inline struct bfd * bfd_asymbol_bfd (const asymbol *sy)
{
  return sy->the_bfd;
}

static inline void bfd_set_asymbol_name (asymbol *sy, const char *name)
{
  sy->name = name;
}

/* For input sections return the original size on disk of the
   section.  For output sections return the current size.  */
static inline size_t
bfd_get_section_limit_octets (const bfd *abfd, const asection *sec)
{
  if (abfd->direction != write_direction && sec->rawsize != 0)
    return sec->rawsize;
  return sec->size;
}

/* Find the address one past the end of SEC.  */
static inline size_t
bfd_get_section_limit (const bfd *abfd, const asection *sec)
{
  return bfd_get_section_limit_octets (abfd, sec);
}

/* For input sections return the larger of the current size and the
   original size on disk of the section.  For output sections return
   the current size.  */
static inline size_t
bfd_get_section_alloc_size (const bfd *abfd, const asection *sec)
{
  if (abfd->direction != write_direction && sec->rawsize > sec->size)
    return sec->rawsize;
  return sec->size;
}

/* Functions to handle insertion and deletion of a bfd's sections.  These
   only handle the list pointers, ie. do not adjust section_count,
   target_index etc.  */
static inline void bfd_section_list_remove (bfd *abfd, asection *s)
{
  asection *next = s->next;
  asection *prev = s->prev;
  if (prev) prev->next = next;
  else abfd->sections = next;
  if (next) next->prev = prev;
  else abfd->section_last = prev;
}

static inline void bfd_section_list_append (bfd *abfd, asection *s)
{
  s->next = 0;
  if (abfd->section_last)
    {
      s->prev = abfd->section_last;
      abfd->section_last->next = s;
    }
  else
    {
      s->prev = 0;
      abfd->sections = s;
    }
  abfd->section_last = s;
}

static inline void bfd_section_list_prepend (bfd *abfd, asection *s)
{
  s->prev = 0;
  if (abfd->sections)
    {
      s->next = abfd->sections;
      abfd->sections->prev = s;
    }
  else
    {
      s->next = 0;
      abfd->section_last = s;
    }
  abfd->sections = s;
}

static inline void bfd_section_list_insert_after (bfd *abfd, asection *a, asection *s)
{
  asection *next = a->next;
  s->next = next;
  s->prev = a;
  a->next = s;
  if (next)
    next->prev = s;
  else
    abfd->section_last = s;
}

static inline void bfd_section_list_insert_before (bfd *abfd, asection *b, asection *s)
{
  asection *prev = b->prev;
  s->prev = prev;
  s->next = b;
  b->prev = s;
  if (prev)
    prev->next = s;
  else
    abfd->sections = s;
}

static inline bool
bfd_section_removed_from_list (const bfd *abfd, const asection *s)
{
  return s->next ? s->next->prev != s : abfd->section_last != s;
}

typedef enum bfd_error
{
  bfd_error_no_error = 0, bfd_error_system_call, bfd_error_invalid_target,
  bfd_error_wrong_format, bfd_error_wrong_object_format,
  bfd_error_invalid_operation, bfd_error_no_memory, bfd_error_no_symbols,
  bfd_error_no_armap, bfd_error_no_more_archived_files,
  bfd_error_malformed_archive, bfd_error_missing_dso,
  bfd_error_file_not_recognized, bfd_error_file_ambiguously_recognized,
  bfd_error_no_contents, bfd_error_nonrepresentable_section,
  bfd_error_no_debug_section, bfd_error_bad_value, bfd_error_file_truncated,
  bfd_error_file_too_big, bfd_error_sorry, bfd_error_on_input,
  bfd_error_invalid_error_code
} bfd_error_type;

static bfd_error_type bfd_get_error (void);
static void bfd_set_error (bfd_error_type error_tag);
static char *bfd_errmsg (bfd_error_type error_tag);
typedef void (*bfd_error_handler_type) (const char *, va_list);
static void error_handler (const char *fmt, ...) ATTRIBUTE_PRINTF_1;
typedef void (*bfd_assert_handler_type) (const char *bfd_formatmsg,
					 const char *bfd_version,
					 const char *bfd_file,
					 int bfd_line);
static void bfd_sprintf_vma (bfd *, char *, bfd_vma);

#define bfd_printf_vma(abfd,x) bfd_fprintf_vma (abfd, stdout, x)

/* Extracted from bfdio.c.  */
static size_t bfd_bwrite (const void *, size_t, bfd *);
static int Seek (bfd *, file_ptr, int);

/* Extracted from bfdwin.c.  */
struct _bfd_window_internal;

typedef struct _bfd_window {
  /* What the user asked for.  */
  void *data;
  size_t size;
  /* The actual window used by BFD.  Small user-requested read-only
     regions sharing a page may share a single window into the object
     file.  Read-write versions shouldn't until I've fixed things to
     keep track of which portions have been claimed by the
     application; don't want to give the same region back when the
     application wants two writable copies!  */
  struct _bfd_window_internal *i;
} bfd_window;

/* Extracted from compress.c.  */
/* Types of compressed DWARF debug sections.  */
enum compressed_debug_section_type
{
  COMPRESS_DEBUG_NONE = 0,
  COMPRESS_DEBUG_GNU_ZLIB = 1 << 1,
  COMPRESS_DEBUG_GABI_ZLIB = 1 << 2,
  COMPRESS_DEBUG_ZSTD = 1 << 3,
  COMPRESS_UNKNOWN = 1 << 4
};

/* Tuple for compressed_debug_section_type and their name.  */
struct compressed_type_tuple {
  enum compressed_debug_section_type type;
  const char *name;
};

/* Compression header ch_type values.  */
enum compression_type {
  ch_none = 0,
  ch_compress_zlib = 1 ,       /* Compressed with zlib.  */
  ch_compress_zstd = 2         /* Compressed with zstd (www.zstandard.org).  */
};

static inline char * bfd_debug_name_to_zdebug (bfd *abfd, const char *name)
{
  size_t len = strlen (name);
  char *new_name = (char *) bfd_alloc (abfd, len + 2);
  if (new_name == NULL)
    return NULL;
  new_name[0] = '.';
  new_name[1] = 'z';
  memcpy (new_name + 2, name + 1, len);
  return new_name;
}

static inline char * bfd_zdebug_name_to_debug (bfd *abfd, const char *name)
{
  size_t len = strlen (name);
  char *new_name = (char *) bfd_alloc (abfd, len);
  if (new_name == NULL)
    return NULL;
  new_name[0] = '.';
  memcpy (new_name + 1, name + 2, len - 1);
  return new_name;
}
static void bfd_update_compression_header (bfd *abfd, 
						bfd_byte *contents, asection *sec);

static int bfd_get_compression_header_size (bfd *abfd, asection *sec);
static bool elf_write_object_contents (bfd *abfd);
static bool bfd_compress_section
   (bfd *abfd, asection *section, bfd_byte *uncompressed_buffer);

/* Extracted from format.c.  */
static bool bfd_set_format (bfd *abfd, bfd_format format);
/* Extracted from linker.c.  */
/* Return TRUE if the symbol described by a linker hash entry H
   is going to be absolute.  Linker-script defined symbols can be
   converted from absolute to section-relative ones late in the
   link.  Use this macro to correctly determine whether the symbol
   will actually end up absolute in output.  */

struct bfd_link_hash_entry *bfd_generic_define_start_stop
   (struct bfd_link_info *info, const char *symbol, asection *sec);

struct bfd_elf_version_tree * bfd_find_version_for_sym
   (struct bfd_elf_version_tree *verdefs,
    const char *sym_name, bool *hide);

/* Extracted from opncls.c.  */
static bool bfd_close (bfd *abfd);
static bool close_all_done (bfd *);

/* Extracted from reloc.c.  */
typedef enum bfd_reloc_status {
  /* No errors detected.  Note - the value 2 is used so that it
     will not be mistaken for the boolean TRUE or FALSE values.  */
  bfd_reloc_ok = 2,

  /* The relocation was performed, but there was an overflow.  */
  bfd_reloc_overflow,

  /* The address to relocate was not within the section supplied.  */
  bfd_reloc_outofrange,

  /* Used by special functions.  */
  bfd_reloc_continue,

  /* Unsupported relocation size requested.  */
  bfd_reloc_notsupported,

  /* Target specific meaning.  */
  bfd_reloc_other,

  /* The symbol to relocate against was undefined.  */
  bfd_reloc_undefined,

  /* The relocation was performed, but may not be ok.  If this type is
     returned, the error_message argument to bfd_perform_relocation
     will be set.  */
  bfd_reloc_dangerous
} bfd_reloc_status_type;

typedef const struct reloc_howto_struct reloc_howto_type;
struct reloc_cache_entry {
  /* A pointer into the canonical table of pointers.  */
  struct bfd_symbol **sym_ptr_ptr;

  /* offset in section.  */
  size_t address;

  /* addend for relocation value.  */
  bfd_vma addend;

  /* Pointer to how to perform the required relocation.  */
  reloc_howto_type *howto;

};

enum complain_overflow {
  /* Do not complain on overflow.  */
  complain_overflow_dont,

  /* Complain if the value overflows when considered as a signed
     number one bit larger than the field.  ie. A bitfield of N bits
     is allowed to represent -2**n to 2**n-1.  */
  complain_overflow_bitfield,

  /* Complain if the value overflows when considered as a signed
     number.  */
  complain_overflow_signed,

  /* Complain if the value overflows when considered as an
     unsigned number.  */
  complain_overflow_unsigned
};

struct reloc_howto_struct {
  /* The type field has mainly a documentary use - the back end can
     do what it wants with it, though normally the back end's idea of
     an external reloc number is stored in this field.  */
  unsigned int type;

  /* The size of the item to be relocated in bytes.  */
  unsigned int size:4;

  /* The number of bits in the field to be relocated.  This is used
     when doing overflow checking.  */
  unsigned int bitsize:7;

  /* The value the final relocation is shifted right by.  This drops
     unwanted data from the relocation.  */
  unsigned int rightshift:6;

  /* The bit position of the reloc value in the destination.
     The relocated value is left shifted by this amount.  */
  unsigned int bitpos:6;

  /* What type of overflow error should be checked for when
     relocating.  */
  ENUM_BITFIELD (complain_overflow) complain_on_overflow:2;

  /* The relocation value should be negated before applying.  */
  unsigned int negate:1;

  /* The relocation is relative to the item being relocated.  */
  unsigned int pc_relative:1;

  /* Some formats record a relocation addend in the section contents
     rather than with the relocation.  For ELF formats this is the
     distinction between USE_REL and USE_RELA (though the code checks
     for USE_REL == 1/0).  The value of this field is TRUE if the
     addend is recorded with the section contents; when performing a
     partial link (ld -r) the section contents (the data) will be
     modified.  The value of this field is FALSE if addends are
     recorded with the relocation (in arelent.addend); when performing
     a partial link the relocation will be modified.
     All relocations for all ELF USE_RELA targets should set this field
     to FALSE (values of TRUE should be looked on with suspicion).
     However, the converse is not true: not all relocations of all ELF
     USE_REL targets set this field to TRUE.  Why this is so is peculiar
     to each particular target.  For relocs that aren't used in partial
     links (e.g. GOT stuff) it doesn't matter what this is set to.  */
  unsigned int partial_inplace:1;

  /* When some formats create PC relative instructions, they leave
     the value of the pc of the place being relocated in the offset
     slot of the instruction, so that a PC relative relocation can
     be made just by adding in an ordinary offset (e.g., sun3 a.out).
     Some formats leave the displacement part of an instruction
     empty (e.g., ELF); this flag signals the fact.  */
  unsigned int pcrel_offset:1;

  /* Whether bfd_install_relocation should just install the addend,
     or should follow the practice of some older object formats and
     install a value including the symbol.  */
  unsigned int install_addend:1;

  /* src_mask selects the part of the instruction (or data) to be used
     in the relocation sum.  If the target relocations don't have an
     addend in the reloc, eg. ELF USE_REL, src_mask will normally equal
     dst_mask to extract the addend from the section contents.  If
     relocations do have an addend in the reloc, eg. ELF USE_RELA, this
     field should normally be zero.  Non-zero values for ELF USE_RELA
     targets should be viewed with suspicion as normally the value in
     the dst_mask part of the section contents should be ignored.  */
  bfd_vma src_mask;

  /* dst_mask selects which parts of the instruction (or data) are
     replaced with a relocated value.  */
  bfd_vma dst_mask;

  /* If this field is non null, then the supplied function is
     called rather than the normal function.  This allows really
     strange relocation methods to be accommodated.  */
  bfd_reloc_status_type (*special_function)
    (bfd *, arelent *, struct bfd_symbol *, void *, asection *,
     bfd *, char **);

  /* The textual name of the relocation type.  */
  const char *name;
};

#define HOWTO_INSTALL_ADDEND 0
#define HOWTO_RSIZE(sz) ((sz) < 0 ? -(sz) : (sz))
#define HOWTO(type, right, size, bits, pcrel, left, ovf, func, name,   \
	      inplace, src_mask, dst_mask, pcrel_off)                  \
  { (unsigned) type, HOWTO_RSIZE (size), bits, right, left, ovf,       \
    size < 0, pcrel, inplace, pcrel_off, HOWTO_INSTALL_ADDEND,         \
    src_mask, dst_mask, func, name }
#define EMPTY_HOWTO(C) \
  HOWTO ((C), 0, 1, 0, false, 0, complain_overflow_dont, NULL, \
	 NULL, false, 0, 0, false)

static inline unsigned int bfd_get_reloc_size (reloc_howto_type *howto)
{
  return howto->size;
}

typedef struct relent_chain
{
  arelent relent;
  struct relent_chain *next;
} arelent_chain;

static bfd_reloc_status_type bfd_check_overflow (enum complain_overflow how,
    unsigned int bitsize, unsigned int rightshift, unsigned int addrsize,
    bfd_vma relocation);

static bool bfd_reloc_offset_in_range (reloc_howto_type *howto,
    bfd *abfd, asection *section, size_t offset);

static bfd_reloc_status_type bfd_install_relocation (bfd *abfd,
    arelent *reloc_entry, void *data, bfd_vma data_start,
    asection *input_section, char **error_message);

enum bfd_reloc_code_real {
  _dummy_first_bfd_reloc_code_real,

  BFD_RELOC_CTOR,
/* Basic absolute relocations of N bits.  */
  BFD_RELOC_64, BFD_RELOC_32, BFD_RELOC_26, BFD_RELOC_24, BFD_RELOC_16,
  BFD_RELOC_14, BFD_RELOC_8,

/* PC-relative relocations.  Sometimes these are relative to the address
of the relocation itself; sometimes they are relative to the start of
the section containing the relocation.  It depends on the specific target.  */
  BFD_RELOC_64_PCREL, BFD_RELOC_32_PCREL, BFD_RELOC_24_PCREL, BFD_RELOC_16_PCREL,
  BFD_RELOC_12_PCREL, BFD_RELOC_8_PCREL,

/* Section relative relocations.  Some targets need this for DWARF2.  */
  BFD_RELOC_32_SECREL,
  BFD_RELOC_16_SECIDX,

/* For ELF.  */
  BFD_RELOC_32_GOT_PCREL, BFD_RELOC_16_GOT_PCREL, BFD_RELOC_8_GOT_PCREL,
  BFD_RELOC_32_GOTOFF, BFD_RELOC_16_GOTOFF, BFD_RELOC_LO16_GOTOFF,
  BFD_RELOC_HI16_GOTOFF, BFD_RELOC_HI16_S_GOTOFF, BFD_RELOC_8_GOTOFF,
  BFD_RELOC_64_PLT_PCREL, BFD_RELOC_32_PLT_PCREL, BFD_RELOC_24_PLT_PCREL,
  BFD_RELOC_16_PLT_PCREL, BFD_RELOC_8_PLT_PCREL, BFD_RELOC_64_PLTOFF,
  BFD_RELOC_32_PLTOFF, BFD_RELOC_16_PLTOFF, BFD_RELOC_LO16_PLTOFF,
  BFD_RELOC_HI16_PLTOFF, BFD_RELOC_HI16_S_PLTOFF, BFD_RELOC_8_PLTOFF,

/* Size relocations.  */
  BFD_RELOC_SIZE32, BFD_RELOC_SIZE64,

/* Relocations used by 68K ELF.  */
  BFD_RELOC_68K_GLOB_DAT,
  BFD_RELOC_68K_JMP_SLOT,
  BFD_RELOC_68K_RELATIVE,
  BFD_RELOC_68K_TLS_GD32,
  BFD_RELOC_68K_TLS_GD16,
  BFD_RELOC_68K_TLS_GD8,
  BFD_RELOC_68K_TLS_LDM32,
  BFD_RELOC_68K_TLS_LDM16,
  BFD_RELOC_68K_TLS_LDM8,
  BFD_RELOC_68K_TLS_LDO32,
  BFD_RELOC_68K_TLS_LDO16,
  BFD_RELOC_68K_TLS_LDO8,
  BFD_RELOC_68K_TLS_IE32,
  BFD_RELOC_68K_TLS_IE16,
  BFD_RELOC_68K_TLS_IE8,
  BFD_RELOC_68K_TLS_LE32,
  BFD_RELOC_68K_TLS_LE16,
  BFD_RELOC_68K_TLS_LE8,

/* Linkage-table relative.  */
  BFD_RELOC_32_BASEREL,
  BFD_RELOC_16_BASEREL,
  BFD_RELOC_LO16_BASEREL,
  BFD_RELOC_HI16_BASEREL,
  BFD_RELOC_HI16_S_BASEREL,
  BFD_RELOC_8_BASEREL,
  BFD_RELOC_RVA,

/* These PC-relative relocations are stored as word displacements --
i.e., byte displacements shifted right two bits.  The 30-bit word
displacement (<<32_PCREL_S2>> -- 32 bits, shifted 2) is used on the
SPARC.  (SPARC tools generally refer to this as <<WDISP30>>.)  The
signed 16-bit displacement is used on the MIPS, and the 23-bit
displacement is used on the Alpha.  */
  BFD_RELOC_32_PCREL_S2,
  BFD_RELOC_16_PCREL_S2,
  BFD_RELOC_23_PCREL_S2,

/* High 22 bits and low 10 bits of 32-bit value, placed into lower bits of
the target word.  These are used on the SPARC.  */
  BFD_RELOC_HI22,
  BFD_RELOC_LO10,

/* For systems that allocate a Global Pointer register, these are
displacements off that register.  These relocation types are
handled specially, because the value the register will have is
decided relatively late.  */
  BFD_RELOC_GPREL16,
  BFD_RELOC_GPREL32,

  BFD_RELOC_NONE,
  BFD_RELOC_VTABLE_INHERIT,
  BFD_RELOC_VTABLE_ENTRY,

/* RISC-V relocations.  */
  BFD_RELOC_RISCV_HI20=1321, BFD_RELOC_RISCV_PCREL_HI20, BFD_RELOC_RISCV_PCREL_LO12_I,
  BFD_RELOC_RISCV_PCREL_LO12_S, BFD_RELOC_RISCV_LO12_I, BFD_RELOC_RISCV_LO12_S,
  BFD_RELOC_RISCV_GPREL12_I, BFD_RELOC_RISCV_GPREL12_S, BFD_RELOC_RISCV_TPREL_HI20,
  BFD_RELOC_RISCV_TPREL_LO12_I, BFD_RELOC_RISCV_TPREL_LO12_S, BFD_RELOC_RISCV_TPREL_ADD,
  BFD_RELOC_RISCV_CALL, BFD_RELOC_RISCV_CALL_PLT, BFD_RELOC_RISCV_ADD8, BFD_RELOC_RISCV_ADD16,
  BFD_RELOC_RISCV_ADD32, BFD_RELOC_RISCV_ADD64, BFD_RELOC_RISCV_SUB8, BFD_RELOC_RISCV_SUB16,
  BFD_RELOC_RISCV_SUB32, BFD_RELOC_RISCV_SUB64, BFD_RELOC_RISCV_GOT_HI20, BFD_RELOC_RISCV_TLS_GOT_HI20,
  BFD_RELOC_RISCV_TLS_GD_HI20, BFD_RELOC_RISCV_JMP, BFD_RELOC_RISCV_TLS_DTPMOD32,
  BFD_RELOC_RISCV_TLS_DTPREL32, BFD_RELOC_RISCV_TLS_DTPMOD64, BFD_RELOC_RISCV_TLS_DTPREL64,
  BFD_RELOC_RISCV_TLS_TPREL32, BFD_RELOC_RISCV_TLS_TPREL64, BFD_RELOC_RISCV_ALIGN,
  BFD_RELOC_RISCV_RVC_BRANCH, BFD_RELOC_RISCV_RVC_JUMP, BFD_RELOC_RISCV_RVC_LUI,
  BFD_RELOC_RISCV_GPREL_I, BFD_RELOC_RISCV_GPREL_S, BFD_RELOC_RISCV_TPREL_I,
  BFD_RELOC_RISCV_TPREL_S, BFD_RELOC_RISCV_RELAX, BFD_RELOC_RISCV_CFA,
  BFD_RELOC_RISCV_SUB6, BFD_RELOC_RISCV_SET6, BFD_RELOC_RISCV_SET8, BFD_RELOC_RISCV_SET16,
  BFD_RELOC_RISCV_SET32, BFD_RELOC_RISCV_32_PCREL, BFD_RELOC_RISCV_SET_ULEB128,
  BFD_RELOC_RISCV_SUB_ULEB128,

  BFD_RELOC_UNUSED };
typedef enum bfd_reloc_code_real bfd_reloc_code_real_type;

static reloc_howto_type *riscv_reloc_type_lookup (bfd *abfd, bfd_reloc_code_real_type code);
static reloc_howto_type *riscv_reloc_name_lookup (bfd *abfd, const char *reloc_name);
static void riscv_init_ext_order(void);

/* Extracted from stabs.c.  */
/* This structure is used to keep track of stabs in sections
   information while linking.  */

struct stab_info {
  /* A hash table used to hold stabs strings.  */
  struct bfd_strtab_hash *strings;
  /* The header file hash table.  */
  struct bfd_hash_table includes;
  /* The first .stabstr section.  */
  struct bfd_section *stabstr;
};

/* Defined to TRUE if unused section symbol should be kept.  */
#define TARGET_KEEP_UNUSED_SECTION_SYMBOLS true

enum bfd_flavour {
  /* N.B. Update bfd_flavour_name if you change this.  */
  bfd_target_unknown_flavour, bfd_target_aout_flavour, bfd_target_coff_flavour,
  bfd_target_ecoff_flavour, bfd_target_xcoff_flavour,
  bfd_target_elf_flavour,
  bfd_target_tekhex_flavour, bfd_target_srec_flavour, bfd_target_verilog_flavour,
  bfd_target_ihex_flavour, bfd_target_som_flavour, bfd_target_msdos_flavour,
  bfd_target_evax_flavour, bfd_target_mmo_flavour, bfd_target_mach_o_flavour,
  bfd_target_pef_flavour, bfd_target_pef_xlib_flavour, bfd_target_sym_flavour
};

enum bfd_endian { BFD_ENDIAN_BIG, BFD_ENDIAN_LITTLE, BFD_ENDIAN_UNKNOWN };

/* Forward declarations.  */
struct flag_info; typedef void (*bfd_cleanup) (bfd *);

static inline enum bfd_flavour bfd_get_flavour (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return bfd_target_elf_flavour;
}

static inline flagword bfd_applicable_file_flags (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 0x4ec1ff;
}

static inline bool bfd_family_coff (const bfd *abfd ATTRIBUTE_UNUSED)
{
	return false;
}

static inline bool bfd_big_endian (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 0; //abfd->xvec->byteorder == BFD_ENDIAN_BIG;
}
static inline bool bfd_little_endian (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 1; //abfd->xvec->byteorder == BFD_ENDIAN_LITTLE;
}

static inline bool
bfd_header_big_endian (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 0; //abfd->xvec->header_byteorder == BFD_ENDIAN_BIG;
}

static inline bool
bfd_header_little_endian (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 1; //abfd->xvec->header_byteorder == BFD_ENDIAN_LITTLE;
}

static inline flagword bfd_applicable_section_flags (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 0x3c1a13f; // abfd->xvec->section_flags;
}

static inline char
bfd_get_symbol_leading_char (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 0; //abfd->xvec->symbol_leading_char;
}

static inline enum bfd_flavour
bfd_asymbol_flavour (const asymbol *sy)
{
  if ((sy->flags & BSF_SYNTHETIC) != 0)
    return bfd_target_unknown_flavour;
  return bfd_target_elf_flavour; //sy->the_bfd->xvec->flavour;
}

static inline bool
bfd_keep_unused_section_symbols (const bfd *abfd ATTRIBUTE_UNUSED)
{
  return 1; //abfd->xvec->keep_unused_section_symbols;
}

#define elf_shstrtab(bfd)	(elf_tdata(bfd) -> o->strtab_ptr)
///////////////////////////////////////////end of bfd.h
#endif

/* Other stuff from config.h.  */
#ifdef NEED_DECLARATION_ENVIRON
static char **environ;
#endif
#ifdef NEED_DECLARATION_FFS
static int ffs (int);
#endif
struct obstack;
#define obstack_chunk_alloc xmalloc
#define obstack_chunk_free xfree
#define xfree free

#if GCC_VERSION >= 7000
#define gas_mul_overflow(a, b, res) __builtin_mul_overflow (a, b, res)
#else
/* Assumes unsigned values.  Careful!  Args evaluated multiple times.  */
#define gas_mul_overflow(a, b, res) \
  ((*res) = (a), (*res) *= (b), (b) != 0 && (*res) / (b) != (a))
#endif

/* asintl.h - gas-specific header for gettext code. */
#ifndef ENABLE_NLS
# include <libintl.h>
# define _(String) gettext (String)
# ifdef gettext_noop
#  define N_(String) gettext_noop (String)
# else
#  define N_(String) (String)
# endif
#else
# define gettext(Msgid) (Msgid)
# define dgettext(Domainname, Msgid) (Msgid)
# define dcgettext(Domainname, Msgid, Category) (Msgid)
# define ngettext(Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
# define dngettext(Domainname, Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
# define dcngettext(Domainname, Msgid1, Msgid2, n, Category) \
  (n == 1 ? Msgid1 : Msgid2)
# define _(String) (String)
# define N_(String) (String)
#endif

#define BAD_CASE(val)							    \
  {									    \
    as_fatal (_("Case value %ld unexpected at line %d of file \"%s\"\n"),   \
	      (long) val, __LINE__, __FILE__);				    \
  }

/* flonum.h - Floating point package
 ------------------------------------------------------------------------
 *									*
 *	Arbitrary-precision floating point arithmetic.			*
 *									*
 *									*
 *	Notation: a floating point number is expressed as		*
 *	MANTISSA * (2 ** EXPONENT).					*
 *									*
 *	If this offends more traditional mathematicians, then		*
 *	please tell me your nomenclature for flonums!			*
 *									*
 ------------------------------------------------------------------------*/

/* bignum.h-arbitrary precision integers */
/***********************************************************************\
 *									*
 *	Arbitrary-precision integer arithmetic.				*
 *	For speed, we work in groups of bits, even though this		*
 *	complicates algorithms.						*
 *	Each group of bits is called a 'littlenum'.			*
 *	A bunch of littlenums representing a (possibly large)		*
 *	integer is called a 'bignum'.					*
 *	Bignums are >= 0.						*
 *									*
 \***********************************************************************/
#define	LITTLENUM_NUMBER_OF_BITS	(16)
#define	LITTLENUM_RADIX			(1 << LITTLENUM_NUMBER_OF_BITS)
#define	LITTLENUM_MASK			(0xFFFF)
#define LITTLENUM_SHIFT			(1)
#define CHARS_PER_LITTLENUM		(1 << LITTLENUM_SHIFT)
#ifndef BITS_PER_CHAR
#define BITS_PER_CHAR			(8)
#endif

typedef unsigned short LITTLENUM_TYPE;

/***********************************************************************\
 ------------------------------------------------------------------------
 *									*
 *	Variable precision floating point numbers.			*
 *									*
 *	Exponent is the place value of the low littlenum. E.g.:		*
 *	If  0:  low points to the units             littlenum.		*
 *	If  1:  low points to the LITTLENUM_RADIX   littlenum.		*
 *	If -1:  low points to the 1/LITTLENUM_RADIX littlenum.		*
 *									*
 \***********************************************************************/

/* JF:  A sign value of 0 means we have been asked to assemble NaN
   A sign value of 'P' means we've been asked to assemble +Inf
   A sign value of 'N' means we've been asked to assemble -Inf
   A sign value of 'Q' means we've been asked to assemble +QNaN
   A sign value of 'q' means we've been asked to assemble -QNaN
   A sign value of 'S' means we've been asked to assemble +SNaN
   A sign value of 's' means we've been asked to assemble -SNaN
   */
struct FLONUM_STRUCT {
  LITTLENUM_TYPE *low;		/* low order littlenum of a bignum */
  LITTLENUM_TYPE *high;		/* high order littlenum of a bignum */
  LITTLENUM_TYPE *leader;	/* -> 1st non-zero littlenum */
  /* If flonum is 0.0, leader==low-1 */
  long exponent;		/* base LITTLENUM_RADIX */
  char sign;			/* '+' or '-' */
};

typedef struct FLONUM_STRUCT FLONUM_TYPE;

/***********************************************************************\
 *									*
 *	Since we can (& do) meet with exponents like 10^5000, it	*
 *	is silly to make a table of ~ 10,000 entries, one for each	*
 *	power of 10. We keep a table where item [n] is a struct		*
 *	FLONUM_FLOATING_POINT representing 10^(2^n). We then		*
 *	multiply appropriate entries from this table to get any		*
 *	particular power of 10. For the example of 10^5000, a table	*
 *	of just 25 entries suffices: 10^(2^-12)...10^(2^+12).		*
 *									*
 \***********************************************************************/

static const FLONUM_TYPE flonum_positive_powers_of_ten[];
static const FLONUM_TYPE flonum_negative_powers_of_ten[];
static const int table_size_of_flonum_powers_of_ten;
/* Flonum_XXX_powers_of_ten[] table has legal indices from 0 to
   + this number inclusive.  */

/***********************************************************************\
 *									*
 *	Declare worker functions.					*
 *									*
 \***********************************************************************/

static int atof_generic (char **address_of_string_pointer,
		  const char *string_of_decimal_marks,
		  const char *string_of_decimal_exponent_marks,
		  FLONUM_TYPE * address_of_generic_floating_point_number);

static void flonum_copy (FLONUM_TYPE * in, FLONUM_TYPE * out);
static void flonum_multip (const FLONUM_TYPE * a, const FLONUM_TYPE * b,
		    FLONUM_TYPE * product);

/***********************************************************************\
 *									*
 *	Declare error codes.						*
 *									*
 \***********************************************************************/

#define ERROR_EXPONENT_OVERFLOW (2)

/* These are assembler-wide concepts */

static bfd *stdoutput;
typedef bfd_vma addressT;
typedef bfd_signed_vma offsetT;

/* Type of symbol value, etc.  For use in prototypes.  */
typedef addressT valueT;


#if defined (DEBUG)
#ifndef know
#define know(p) gas_assert(p)	/* Verify our assumptions!  */
#endif /* not yet defined */
#else
#define know(p)	do {} while (0)	/* know() checks are no-op.ed  */
#endif

typedef asection *segT;
#define SEG_NORMAL(SEG)		(   (SEG) != absolute_section	\
				 && (SEG) != undefined_section	\
				 && (SEG) != reg_section	\
				 && (SEG) != expr_section)
typedef int subsegT;

/* What subseg we are accessing now?  */
static subsegT now_subseg;

/* Segment our instructions emit to.  */
static segT now_seg;

#define segment_name(SEG)	bfd_section_name (SEG)

static segT reg_section, expr_section;
/* Shouldn't these be eliminated someday?  */
static segT text_section, data_section, bss_section;
#define absolute_section	bfd_abs_section_ptr
#define undefined_section	bfd_und_section_ptr

enum _relax_state {
  /* Dummy frag used by listing code.  */
  rs_dummy = 0,

  /* Variable chars to be repeated fr_offset times.
     Fr_symbol unused. Used with fr_offset == 0 for a
     constant length frag.  */
  rs_fill,

  /* Align.  The fr_offset field holds the power of 2 to which to
     align.  The fr_var field holds the number of characters in the
     fill pattern.  The fr_subtype field holds the maximum number of
     bytes to skip when aligning, or 0 if there is no maximum.  */
  rs_align,

  /* Align code.  The fr_offset field holds the power of 2 to which
     to align.  This type is only generated by machine specific
     code, which is normally responsible for handling the fill
     pattern.  The fr_subtype field holds the maximum number of
     bytes to skip when aligning, or 0 if there is no maximum.  */
  rs_align_code,

  /* Test for alignment.  Like rs_align, but used by several targets
     to warn if data is not properly aligned.  */
  rs_align_test,

  /* Org: Fr_offset, fr_symbol: address. 1 variable char: fill
     character.  */
  rs_org,

  /* Machine specific relaxable (or similarly alterable) instruction.  */
  rs_machine_dependent,

  /* .space directive with expression operand that needs to be computed
     later.  Similar to rs_org, but different.
     fr_symbol: operand
     1 variable char: fill character  */
  rs_space,

  /* .nop directive with expression operand that needs to be computed
     later.  Similar to rs_space, but different.  It fills with no-op
     instructions.
     fr_symbol: operand
     1 constant byte: no-op fill control byte.  */
  rs_space_nop,

  /* Similar to rs_fill.  It is used to implement .nop directive .  */
  rs_fill_nop,

  /* A DWARF leb128 value; only ELF uses this.  The subtype is 0 for
     unsigned, 1 for signed.  */
  rs_leb128,

  /* Exception frame information which we may be able to optimize.  */
  rs_cfa,

  /* Cross-fragment dwarf2 line number optimization.  */
  rs_dwarf2dbg,

  /* SFrame FRE type selection optimization.  */
  rs_sframe
};

typedef enum _relax_state relax_stateT;

/* This type is used in prototypes, so it can't be a type that will be
   widened for argument passing.  */
typedef unsigned int relax_substateT;

/* Enough bits for address, but still an integer type.
   Could be a problem, cross-assembling for 64-bit machines.  */
typedef addressT relax_addressT;

struct relax_type
{
  /* Forward reach. Signed number. > 0.  */
  offsetT rlx_forward;
  /* Backward reach. Signed number. < 0.  */
  offsetT rlx_backward;

  /* Bytes length of this address.  */
  unsigned char rlx_length;

  /* Next longer relax-state.  0 means there is no 'next' relax-state.  */
  relax_substateT rlx_more;
};

typedef struct relax_type relax_typeS;

/* main program "as.c" (command arguments etc).  */

static unsigned char flag_no_comments; /* -f */
static unsigned char flag_debug; /* -D */
static unsigned char flag_signed_overflow_ok; /* -J */

/* True if local symbols should be retained.  */
static int flag_keep_locals; /* -L */

/* True if we are assembling in MRI mode.  */
#define flag_mri 0

/* True if alternate macro mode is in effect.  */
static bool flag_macro_alternate;

/* Should the data section be made read-only and appended to the text
   section?  */
static unsigned char flag_readonly_data_in_text; /* -R */

/* True if warnings should be inhibited.  */
static int flag_no_warnings; /* -W */

/* True if warnings count as errors.  */
static int flag_fatal_warnings; /* --fatal-warnings */

/* True if we should attempt to generate output even if non-fatal errors
   are detected.  */
static unsigned char flag_always_generate_output; /* -Z */

/* This is true if the assembler should output time and space usage.  */
static unsigned char flag_print_statistics;

/* True if local absolute symbols are to be stripped.  */
static int flag_strip_local_absolute;

/* True if we should generate a traditional format object file.  */
static int flag_traditional_format;

/* Type of compressed debug sections we should generate.   */
static enum compressed_debug_section_type flag_compress_debug;

/* TRUE if .note.GNU-stack section with SEC_CODE should be created */
static int flag_execstack;

/* TRUE if .note.GNU-stack section with SEC_CODE should be created */
static int flag_noexecstack;

/* TRUE if .sframe section should be created.  */
static int flag_gen_sframe;

/* name of emitted object file */
static const char *out_file_name;

/* Keep the output file.  */
static int keep_it;

/* TRUE if we need a second pass.  */
static int need_pass_2;

/* TRUE if we should do no relaxing, and
   leave lots of padding.  */
static int linkrelax;

static int do_not_pad_sections_to_alignment;

enum multibyte_input_handling
{
  multibyte_allow = 0,
  multibyte_warn,
  multibyte_warn_syms
};
static enum multibyte_input_handling multibyte_handling;

/* Type of debugging information we should generate.  We currently support
   stabs, ECOFF, and DWARF2.

   NOTE!  This means debug information about the assembly source code itself
   and _not_ about possible debug information from a high-level language.
   This is especially relevant to DWARF2, since the compiler may emit line
   number directives that the assembler resolves.  */

enum debug_info_type
{
  DEBUG_UNSPECIFIED,
  DEBUG_NONE,
  DEBUG_STABS,
  DEBUG_ECOFF,
  DEBUG_DWARF,
  DEBUG_DWARF2,
};

static enum debug_info_type debug_type;
static int use_gnu_debug_info_extensions;
static bool flag_dwarf_sections;
static int flag_dwarf_cie_version;
static unsigned int dwarf_level;

/* Verbosity level.  */
static int verbose;


/* Obstack chunk size.  Keep large for efficient space use, make small to
   increase malloc calls for monitoring memory allocation.  */
static int chunksize;

struct _pseudo_type
{
  /* assembler mnemonic, lower case, no '.' */
  const char *poc_name;
  /* Do the work */
  void (*poc_handler) (int);
  /* Value to pass to handler */
  int poc_val;
};

typedef struct _pseudo_type pseudo_typeS;

#if (__GNUC__ >= 2) && !defined(VMS)
/* for use with -Wformat */

#if __GNUC__ == 2 && __GNUC_MINOR__ < 6
/* Support for double underscores in attribute names was added in gcc
   2.6, so avoid them if we are using an earlier version.  */
#define __printf__ printf
#define __format__ format
#endif

#define PRINTF_LIKE(FCN) \
  void FCN (const char *format, ...) \
    __attribute__ ((__format__ (__printf__, 1, 2)))
#define PRINTF_WHERE_LIKE(FCN) \
  void FCN (const char *file, unsigned int line, const char *format, ...) \
    __attribute__ ((__format__ (__printf__, 3, 4)))
#define PRINTF_INDENT_LIKE(FCN) \
  void FCN (const char *file, unsigned int line, unsigned int indent, \
	    const char *format, ...) \
    __attribute__ ((__format__ (__printf__, 4, 5)))

#else /* __GNUC__ < 2 || defined(VMS) */

#define PRINTF_LIKE(FCN)	void FCN (const char *format, ...)
#define PRINTF_WHERE_LIKE(FCN)	void FCN (const char *file, \
					  unsigned int line, \
					  const char *format, ...)
#define PRINTF_INDENT_LIKE(FCN)	void FCN (const char *file, \
					  unsigned int line, \
					  unsigned int indent, \
					  const char *format, ...)

#endif /* __GNUC__ < 2 || defined(VMS) */

static PRINTF_LIKE (as_bad);
static PRINTF_LIKE (as_fatal) ATTRIBUTE_NORETURN;
static PRINTF_LIKE (as_warn);
static PRINTF_WHERE_LIKE (as_bad_where);
static PRINTF_WHERE_LIKE (as_warn_where);
static PRINTF_INDENT_LIKE (as_info_where);

static void   as_abort (const char *, int, const char *) ATTRIBUTE_NORETURN;
static void   signal_init (void);
static int    had_errors (void);
static int    had_warnings (void);
static void   as_warn_value_out_of_range (const char *, offsetT, offsetT, offsetT,
				   const char *, unsigned);
static void   print_version_id (void);

/* Number of littlenums required to hold an extended precision number.	*/
#define MAX_LITTLENUMS 6

static bool assign_section_numbers (bfd *abfd, void *link_info);
static char * atof_ieee (char *, int, LITTLENUM_TYPE *);
static char * atof_ieee_detail (char *, int, int, LITTLENUM_TYPE *, FLONUM_TYPE *);
static const char * ieee_md_atof (int, char *, int *, bool);
static char * input_scrub_new_file (const char *);
static char * input_scrub_next_buffer (char **bufp);
static bool   scan_for_multibyte_characters (const unsigned char *, const unsigned char *, bool);
static int    gen_to_words (LITTLENUM_TYPE *, int, long);
static int    seen_at_least_1_file (void);
static void   as_report_context (void);
static const char * as_where (unsigned int *);
static const char * as_where_top (unsigned int *);
static const char * as_where_physical (unsigned int *);
static void   bump_line_counters (void);
static void   do_scrub_begin (int);
static void   input_scrub_begin (void);
static void   input_scrub_close (void);
static void   input_scrub_end (void);
static void   new_logical_line (const char *, int);
static void   new_logical_line_flags (const char *, int, int);
static void   subsegs_begin (void);
static void   subsegs_end (struct obstack **);
static void   subseg_change (segT, int);
static segT   subseg_new (const char *, subsegT);
static segT   subseg_force_new (const char *, subsegT);
static void   subseg_set (segT, subsegT);
static int    subseg_text_p (segT);
static int    seg_not_empty_p (segT);
static segT   subseg_get (const char *, int);
static bool compute_section_file_positions(bfd *,void *);

static char *remap_debug_filename (const char *);
static void add_debug_prefix_map (const char *);
static void *xmemdup(const void *,size_t,size_t);
static void *xcalloc(size_t,size_t);
static char *xstrerror(int);
static void *xrealloc(void *,size_t);
static char *getpwd(void);
static void xexit(int status) ATTRIBUTE_NORETURN;
#define _hex_array_size 256
#define _hex_bad	99
#define LIBIBERTY_H
#define MAX_ALLOCA_SIZE 4032
#define hex_p(c)	(hex_value (c) != _hex_bad)
/* Are we ASCII? */
#if HOST_CHARSET == HOST_CHARSET_ASCII

static const unsigned char _hex_value[_hex_array_size] =
{
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* NUL SOH STX ETX */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* EOT ENQ ACK BEL */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* BS  HT  LF  VT  */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* FF  CR  SO  SI  */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* DLE DC1 DC2 DC3 */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* DC4 NAK SYN ETB */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* CAN EM  SUB ESC */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* FS  GS  RS  US  */

  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* SP  !   "   #   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* $   %   &   '   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* (   )   *   +   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* ,   -   .   /   */
  0,        1,        2,        3,          /* 0   1   2   3   */
  4,        5,        6,        7,          /* 4   5   6   7   */
  8,        9,        _hex_bad, _hex_bad,   /* 8   9   :   ;   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* <   =   >   ?   */

  _hex_bad, 10,       11,       12,         /* @   A   B   C   */
  13,       14,       15,       _hex_bad,   /* D   E   F   G   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* H   I   J   K   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* L   M   N   O   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* P   Q   R   S   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* T   U   V   W   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* X   Y   Z   [   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* \   ]   ^   _   */

  _hex_bad, 10,       11,       12,         /* `   a   b   c   */
  13,       14,       15,       _hex_bad,   /* d   e   f   g   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* h   i   j   k   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* l   m   n   o   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* p   q   r   s   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* t   u   v   w   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* x   y   z   {   */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* |   }   ~   DEL */

  /* The high half of unsigned char, all values are _hex_bad.  */
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,

  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,

  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,

  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
  _hex_bad, _hex_bad, _hex_bad, _hex_bad,
};
#endif /* not ASCII */
/* If you change this, note well: Some code relies on side effects in
   the argument being performed exactly once.  */
#define hex_value(c)	((unsigned int) _hex_value[(unsigned char) (c)])
#define XNEWVEC(T, N)		((T *) xmalloc (sizeof (T) * (N)))
#define XCNEW(T) ((T *) xcalloc(1,sizeof(T)))
#define XCNEWVEC(T,N) ((T *)xcalloc((N),sizeof(T)))
#define XNEW(T) ((T *)xmalloc(sizeof(T)))
#define XRESIZEVEC(T, P, N) ((T *) xrealloc((void *)(P),sizeof(T)*(N)))
#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))
#define XDELETEVEC(P) free((void *)P)
static void *xmalloc(size_t);
static long get_run_time(void);
static char *concat(const char *,...);
static int xatexit(void (*fn)(void));
static void xmalloc_set_program_name(const char *);
static const char *lbasename(const char *);
static const char *unix_lbasename(const char *Name);
static void xmalloc_failed(size_t);
static inline char * xmemdup0 (const char *in, size_t len)
{
  return xmemdup (in, len, len + 1);
}

struct expressionS;
struct fix;
typedef struct symbol symbolS;
typedef struct frag fragS;

/* literal.c */
static int check_eh_frame (struct expressionS *, unsigned int *);
static int eh_frame_estimate_size_before_relax (fragS *);
static int eh_frame_relax_frag (fragS *);
static void eh_frame_convert_frag (fragS *);
static void eh_begin (void);
static int generic_force_reloc (struct fix *);

/* expr.h -> header file for expr.c */
/* By popular demand, we define a struct to represent an expression.
   This will no doubt mutate as expressions become baroque.

   Currently, we support expressions like "foo OP bar + 42".  In other
   words we permit a (possibly undefined) symbol, a (possibly
   undefined) symbol and the operation used to combine the symbols,
   and an (absolute) augend.  RMS says this is so we can have 1-pass
   assembly for any compiler emissions, and a 'case' statement might
   emit 'undefined1 - undefined2'.

   The type of an expression used to be stored as a segment.  That got
   confusing because it overloaded the concept of a segment.  I added
   an operator field, instead.  */

/* This is the type of an expression.  The operator types are also
   used while parsing an expression.

   NOTE: This enumeration must match the op_rank array in expr.c.  */

typedef enum {
  /* An illegal expression.  */
  O_illegal,
  /* A nonexistent expression.  */
  O_absent,
  /* X_add_number (a constant expression).  */
  O_constant,
  /* X_add_symbol + X_add_number.  */
  O_symbol,
  /* X_add_symbol + X_add_number - the base address of the image.  */
  O_symbol_rva,
  /* The section index of X_add_symbol.  */
  O_secidx,
  /* A register (X_add_number is register number).  */
  O_register,
  /* A big value.  If X_add_number is negative or 0, the value is in
     generic_floating_point_number.  Otherwise the value is in
     generic_bignum, and X_add_number is the number of LITTLENUMs in
     the value.  */
  O_big,
  /* (- X_add_symbol) + X_add_number.  */
  O_uminus,
  /* (~ X_add_symbol) + X_add_number.  */
  O_bit_not,
  /* (! X_add_symbol) + X_add_number.  */
  O_logical_not,
  /* (X_add_symbol * X_op_symbol) + X_add_number.  */
  O_multiply,
  /* (X_add_symbol / X_op_symbol) + X_add_number.  */
  O_divide,
  /* (X_add_symbol % X_op_symbol) + X_add_number.  */
  O_modulus,
  /* (X_add_symbol << X_op_symbol) + X_add_number.  */
  O_left_shift,
  /* (X_add_symbol >> X_op_symbol) + X_add_number.  */
  O_right_shift,
  /* (X_add_symbol | X_op_symbol) + X_add_number.  */
  O_bit_inclusive_or,
  /* (X_add_symbol |~ X_op_symbol) + X_add_number.  */
  O_bit_or_not,
  /* (X_add_symbol ^ X_op_symbol) + X_add_number.  */
  O_bit_exclusive_or,
  /* (X_add_symbol & X_op_symbol) + X_add_number.  */
  O_bit_and,
  /* (X_add_symbol + X_op_symbol) + X_add_number.  */
  O_add,
  /* (X_add_symbol - X_op_symbol) + X_add_number.  */
  O_subtract,
  /* (X_add_symbol == X_op_symbol) + X_add_number.  */
  O_eq,
  /* (X_add_symbol != X_op_symbol) + X_add_number.  */
  O_ne,
  /* (X_add_symbol < X_op_symbol) + X_add_number.  */
  O_lt,
  /* (X_add_symbol <= X_op_symbol) + X_add_number.  */
  O_le,
  /* (X_add_symbol >= X_op_symbol) + X_add_number.  */
  O_ge,
  /* (X_add_symbol > X_op_symbol) + X_add_number.  */
  O_gt,
  /* (X_add_symbol && X_op_symbol) + X_add_number.  */
  O_logical_and,
  /* (X_add_symbol || X_op_symbol) + X_add_number.  */
  O_logical_or,
  /* X_op_symbol [ X_add_symbol ] */
  O_index,
  /* machine dependent operators */
  O_md1,  O_md2,  O_md3,  O_md4,  O_md5,  O_md6,  O_md7,  O_md8,
  O_md9,  O_md10, O_md11, O_md12, O_md13, O_md14, O_md15, O_md16,
  O_md17, O_md18, O_md19, O_md20, O_md21, O_md22, O_md23, O_md24,
  O_md25, O_md26, O_md27, O_md28, O_md29, O_md30, O_md31, O_md32,
  /* this must be the largest value */
  O_max
} operatorT;

typedef struct expressionS
{
  /* The main symbol.  */
  symbolS *X_add_symbol;
  /* The second symbol, if needed.  */
  symbolS *X_op_symbol;
  /* A number to add.  */
  offsetT X_add_number;

  /* The type of the expression.  We can't assume that an arbitrary
     compiler can handle a bitfield of enum type.  FIXME: We could
     check this using autoconf.  */
#ifdef __GNUC__
  operatorT X_op : 8;
#else
  unsigned char X_op;
#endif

  /* Non-zero if X_add_number should be regarded as unsigned.  This is
     only valid for O_constant expressions.  It is only used when an
     O_constant must be extended into a bignum (i.e., it is not used
     when performing arithmetic on these values).
     FIXME: This field is not set very reliably.  */
  unsigned int X_unsigned : 1;
  /* This is used to implement "word size + 1 bit" arithmetic, so that e.g.
     expressions used with .sleb128 directives can use the full range available
     for an unsigned word, but can also properly represent all values of a
     signed word.  */
  unsigned int X_extrabit : 1;

  /* 7 additional bits can be defined if needed.  */

  /* Machine dependent field */
  unsigned short X_md;
} expressionS;

enum expr_mode
{
  expr_evaluate,
  expr_normal,
  expr_defer
};

/* "result" should be type (expressionS *).  */
#define expression(result) expr (0, result, expr_normal)
#define expression_and_evaluate(result) expr (0, result, expr_evaluate)
#define deferred_expression(result) expr (0, result, expr_defer)

/* If an expression is O_big, look here for its value. These common
   data may be clobbered whenever expr() is called.  */
/* Flonums returned here.  Big enough to hold most precise flonum.  */
static FLONUM_TYPE generic_floating_point_number;
/* Bignums returned here.  */
static LITTLENUM_TYPE generic_bignum[];
/* Number of littlenums in above.  */
#define SIZE_OF_LARGE_NUMBER (20)

typedef char operator_rankT;

static char get_symbol_name (char **);
static char restore_line_pointer (char);
static void expr_begin (void);
static void expr_end (void);
static void expr_set_precedence (void);
static void add_to_result (expressionS *, offsetT, int);
static void subtract_from_result (expressionS *, offsetT, int);
static segT expr (int, expressionS *, enum expr_mode);
static unsigned int get_single_number (void);
static symbolS *make_expr_symbol (const expressionS * expressionP);
static int expr_symbol_where (symbolS *, const char **, unsigned int *);
static void current_location (expressionS *);
static uint32_t generic_bignum_to_int32 (void);
static int resolve_expression (expressionS *);

static bool literal_prefix_dollar_hex;

/* This one starts the chain of target dependent headers.  */

/* ELF object file format. */

#ifndef _OBJ_ELF_H
#define _OBJ_ELF_H

#define OBJ_ELF 1

/* Note that all macros in this file should be wrapped in #ifndef, for
   sake of obj-multi.h which includes this file.  */

#ifndef OUTPUT_FLAVOR
#define OUTPUT_FLAVOR bfd_target_elf_flavour
#endif

/* BFD back-end data structures for ELF files. */
#ifndef _LIBELF_H_
#define _LIBELF_H_ 1

//----------------------------------------------include "elf/common.h"
/* ELF support for BFD. */
/* This file is part of ELF support for BFD, and contains the portions
   that are common to both the internal and external representations.
   For example, ELFMAG0 is the byte 0x7F in both the internal (in-memory)
   and external (in-file) representations.  */

#ifndef _ELF_COMMON_H
#define _ELF_COMMON_H

/* Fields in e_ident[].  */

#define EI_MAG0		0	/* File identification byte 0 index */
#define ELFMAG0		   0x7F	/* Magic number byte 0 */

#define EI_MAG1		1	/* File identification byte 1 index */
#define ELFMAG1		    'E'	/* Magic number byte 1 */

#define EI_MAG2		2	/* File identification byte 2 index */
#define ELFMAG2		    'L'	/* Magic number byte 2 */

#define EI_MAG3		3	/* File identification byte 3 index */
#define ELFMAG3		    'F'	/* Magic number byte 3 */

#define EI_CLASS	4	/* File class */
#define ELFCLASSNONE	      0	/* Invalid class */
#define ELFCLASS32	      1	/* 32-bit objects */
#define ELFCLASS64	      2	/* 64-bit objects */

#define EI_DATA		5	/* Data encoding */
#define ELFDATANONE	      0	/* Invalid data encoding */
#define ELFDATA2LSB	      1	/* 2's complement, little endian */
#define ELFDATA2MSB	      2	/* 2's complement, big endian */

#define EI_VERSION	6	/* File version */

#define EI_OSABI	7	/* Operating System/ABI indication */
#define ELFOSABI_NONE	      0	/* UNIX System V ABI */
#define ELFOSABI_GNU	      3	/* GNU */
#define ELFOSABI_LINUX	      3	/* Alias for ELFOSABI_GNU */
#define ELFOSABI_OPENBSD     12	/* OpenBSD */

#define ELFOSABI_STANDALONE 255	/* Standalone (embedded) application */

#define EI_ABIVERSION	8	/* ABI version */

#define EI_PAD		9	/* Start of padding bytes */


/* Values for e_type, which identifies the object file type.  */

#define ET_NONE		0	/* No file type */
#define ET_REL		1	/* Relocatable file */
#define ET_EXEC		2	/* Position-dependent executable file */
#define ET_DYN		3	/* Position-independent executable or
				   shared object file */
#define ET_CORE		4	/* Core file */
#define ET_LOOS		0xFE00	/* Operating system-specific */
#define ET_HIOS		0xFEFF	/* Operating system-specific */
#define ET_LOPROC	0xFF00	/* Processor-specific */
#define ET_HIPROC	0xFFFF	/* Processor-specific */

/* Values for e_machine, which identifies the architecture.  These numbers
   are officially assigned by registry@sco.com.  See below for a list of
   ad-hoc numbers used during initial development.  */

#define EM_NONE		  0	/* No machine */
#define EV_NONE		0		/* Invalid ELF version */
#define EV_CURRENT	1		/* Current version */
#define EM_RISCV    243

/* Value for e_phnum. */
#define PN_XNUM		0xffff		/* Extended numbering */

/* Values for program header, p_type field.  */

#define PT_NULL		0		/* Program header table entry unused */
#define PT_LOAD		1		/* Loadable program segment */
#define PT_DYNAMIC	2		/* Dynamic linking information */
#define PT_INTERP	3		/* Program interpreter */
#define PT_NOTE		4		/* Auxiliary information */
#define PT_SHLIB	5		/* Reserved, unspecified semantics */
#define PT_PHDR		6		/* Entry for header table itself */
#define PT_TLS		7		/* Thread local storage segment */
#define PT_LOOS		0x60000000	/* OS-specific */
#define PT_HIOS		0x6fffffff	/* OS-specific */
#define PT_LOPROC	0x70000000	/* Processor-specific */
#define PT_HIPROC	0x7FFFFFFF	/* Processor-specific */

#define PT_GNU_EH_FRAME	(PT_LOOS + 0x474e550) /* Frame unwind information */
#define PT_SUNW_EH_FRAME PT_GNU_EH_FRAME      /* Solaris uses the same value */
#define PT_GNU_STACK	(PT_LOOS + 0x474e551) /* Stack flags */
#define PT_GNU_RELRO	(PT_LOOS + 0x474e552) /* Read-only after relocation */
#define PT_GNU_PROPERTY	(PT_LOOS + 0x474e553) /* GNU property */
#define PT_GNU_SFRAME	(PT_LOOS + 0x474e554) /* SFrame stack trace information */

/* Program segment permissions, in program header p_flags field.  */
#define PF_X		(1 << 0)	/* Segment is executable */
#define PF_W		(1 << 1)	/* Segment is writable */
#define PF_R		(1 << 2)	/* Segment is readable */
/* #define PF_MASKOS	0x0F000000    *//* OS-specific reserved bits */
#define PF_MASKOS	0x0FF00000	/* New value, Oct 4, 1999 Draft */
#define PF_MASKPROC	0xF0000000	/* Processor-specific reserved bits */

/* Values for section header, sh_type field.  */
#define SHT_NULL	0		/* Section header table entry unused */
#define SHT_PROGBITS	1		/* Program specific (private) data */
#define SHT_SYMTAB	2		/* Link editing symbol table */
#define SHT_STRTAB	3		/* A string table */
#define SHT_RELA	4		/* Relocation entries with addends */
#define SHT_HASH	5		/* A symbol hash table */
#define SHT_DYNAMIC	6		/* Information for dynamic linking */
#define SHT_NOTE	7		/* Information that marks file */
#define SHT_NOBITS	8		/* Section occupies no space in file */
#define SHT_REL		9		/* Relocation entries, no addends */
#define SHT_SHLIB	10		/* Reserved, unspecified semantics */
#define SHT_DYNSYM	11		/* Dynamic linking symbol table */

#define SHT_INIT_ARRAY	  14		/* Array of ptrs to init functions */
#define SHT_FINI_ARRAY	  15		/* Array of ptrs to finish functions */
#define SHT_PREINIT_ARRAY 16		/* Array of ptrs to pre-init funcs */
#define SHT_GROUP	  17		/* Section contains a section group */
#define SHT_SYMTAB_SHNDX  18		/* Indices for SHN_XINDEX entries */
#define SHT_RELR	  19		/* RELR relative relocations */

#define SHT_LOOS	0x60000000	/* First of OS specific semantics */
#define SHT_HIOS	0x6fffffff	/* Last of OS specific semantics */

#define SHT_GNU_INCREMENTAL_INPUTS 0x6fff4700   /* incremental build data */
#define SHT_GNU_ATTRIBUTES 0x6ffffff5	/* Object attributes */
#define SHT_GNU_HASH	0x6ffffff6	/* GNU style symbol hash table */
#define SHT_GNU_LIBLIST	0x6ffffff7	/* List of prelink dependencies */

/* The next three section types are defined by Solaris, and are named
   SHT_SUNW*.  We use them in GNU code, so we also define SHT_GNU*
   versions.  */
#define SHT_SUNW_verdef	0x6ffffffd	/* Versions defined by file */
#define SHT_SUNW_verneed 0x6ffffffe	/* Versions needed by file */
#define SHT_SUNW_versym	0x6fffffff	/* Symbol versions */

#define SHT_GNU_verdef	SHT_SUNW_verdef
#define SHT_GNU_verneed	SHT_SUNW_verneed
#define SHT_GNU_versym	SHT_SUNW_versym

#define SHT_LOPROC	0x70000000	/* Processor-specific semantics, lo */
#define SHT_HIPROC	0x7FFFFFFF	/* Processor-specific semantics, hi */
#define SHT_LOUSER	0x80000000	/* Application-specific semantics */
/* #define SHT_HIUSER	0x8FFFFFFF    *//* Application-specific semantics */
#define SHT_HIUSER	0xFFFFFFFF	/* New value, defined in Oct 4, 1999 Draft */

/* Values for section header, sh_flags field.  */
#define SHF_WRITE	(1 << 0)	/* Writable data during execution */
#define SHF_ALLOC	(1 << 1)	/* Occupies memory during execution */
#define SHF_EXECINSTR	(1 << 2)	/* Executable machine instructions */
#define SHF_MERGE	(1 << 4)	/* Data in this section can be merged */
#define SHF_STRINGS	(1 << 5)	/* Contains null terminated character strings */
#define SHF_INFO_LINK	(1 << 6)	/* sh_info holds section header table index */
#define SHF_LINK_ORDER	(1 << 7)	/* Preserve section ordering when linking */
#define SHF_OS_NONCONFORMING (1 << 8)	/* OS specific processing required */
#define SHF_GROUP	(1 << 9)	/* Member of a section group */
#define SHF_TLS		(1 << 10)	/* Thread local storage section */
#define SHF_COMPRESSED	(1 << 11)	/* Section with compressed data */

/* #define SHF_MASKOS	0x0F000000    *//* OS-specific semantics */
#define SHF_MASKOS	0x0FF00000	/* New value, Oct 4, 1999 Draft */
#define SHF_GNU_RETAIN	      (1 << 21)	/* Section should not be garbage collected by the linker.  */
#define SHF_MASKPROC	0xF0000000	/* Processor-specific semantics */

/* This used to be implemented as a processor specific section flag.
   We just make it generic.  */
#define SHF_EXCLUDE	0x80000000	/* Link editor is to exclude
					   this section from executable
					   and shared library that it
					   builds when those objects
					   are not to be further
					   relocated.  */

#define SHF_GNU_MBIND	0x01000000	/* Mbind section.  */

/* Compression types.  */
#define ELFCOMPRESS_ZLIB   1		/* Compressed with zlib.  */
#define ELFCOMPRESS_ZSTD   2		/* Compressed with zstd  */
					/* (see http://www.zstandard.org). */
#define ELFCOMPRESS_LOOS   0x60000000	/* OS-specific semantics, lo */
#define ELFCOMPRESS_HIOS   0x6FFFFFFF	/* OS-specific semantics, hi */
#define ELFCOMPRESS_LOPROC 0x70000000	/* Processor-specific semantics, lo */
#define ELFCOMPRESS_HIPROC 0x7FFFFFFF	/* Processor-specific semantics, hi */

/* Values of note segment descriptor types for core files.  */
#define NT_PRSTATUS	1		/* Contains copy of prstatus struct */
#define NT_FPREGSET	2		/* Contains copy of fpregset struct */
#define NT_PRPSINFO	3		/* Contains copy of prpsinfo struct */
#define NT_TASKSTRUCT	4		/* Contains copy of task struct */
#define NT_AUXV		6		/* Contains copy of Elfxx_auxv_t */
#define NT_PRXFPREG	0x46e62b7f	/* Contains a user_xfpregs_struct; */
					/*   note name must be "LINUX".  */
#define NT_PPC_VMX	0x100		/* PowerPC Altivec/VMX registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_VSX	0x102		/* PowerPC VSX registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_TAR	0x103		/* PowerPC Target Address Register */
					/*   note name must be "LINUX".  */
#define NT_PPC_PPR	0x104		/* PowerPC Program Priority Register */
					/*   note name must be "LINUX".  */
#define NT_PPC_DSCR	0x105		/* PowerPC Data Stream Control Register */
					/*   note name must be "LINUX".  */
#define NT_PPC_EBB	0x106		/* PowerPC Event Based Branch Registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_PMU	0x107		/* PowerPC Performance Monitor Registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_CGPR	0x108		/* PowerPC TM checkpointed GPR Registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_CFPR	0x109		/* PowerPC TM checkpointed FPR Registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_CVMX	0x10a		/* PowerPC TM checkpointed VMX Registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_CVSX	0x10b		/* PowerPC TM checkpointed VSX Registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_SPR	0x10c		/* PowerPC TM Special Purpose Registers */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_CTAR	0x10d		/* PowerPC TM checkpointed TAR */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_CPPR	0x10e		/* PowerPC TM checkpointed PPR */
					/*   note name must be "LINUX".  */
#define NT_PPC_TM_CDSCR	0x10f		/* PowerPC TM checkpointed Data SCR */
					/*   note name must be "LINUX".  */
#define NT_386_TLS	0x200		/* x86 TLS information */
					/*   note name must be "LINUX".  */
#define NT_386_IOPERM	0x201		/* x86 io permissions */
					/*   note name must be "LINUX".  */
#define NT_X86_XSTATE	0x202		/* x86 XSAVE extended state */
					/*   note name must be "LINUX".  */
#define NT_X86_CET	0x203		/* x86 CET state.  */
					/*   note name must be "LINUX".  */
#define NT_S390_HIGH_GPRS 0x300		/* S/390 upper halves of GPRs  */
					/*   note name must be "LINUX".  */
#define NT_S390_TIMER	0x301		/* S390 timer */
					/*   note name must be "LINUX".  */
#define NT_S390_TODCMP	0x302		/* S390 TOD clock comparator */
					/*   note name must be "LINUX".  */
#define NT_S390_TODPREG	0x303		/* S390 TOD programmable register */
					/*   note name must be "LINUX".  */
#define NT_S390_CTRS	0x304		/* S390 control registers */
					/*   note name must be "LINUX".  */
#define NT_S390_PREFIX	0x305		/* S390 prefix register */
					/*   note name must be "LINUX".  */
#define NT_S390_LAST_BREAK      0x306   /* S390 breaking event address */
					/*   note name must be "LINUX".  */
#define NT_S390_SYSTEM_CALL     0x307   /* S390 system call restart data */
					/*   note name must be "LINUX".  */
#define NT_S390_TDB	0x308		/* S390 transaction diagnostic block */
					/*   note name must be "LINUX".  */
#define NT_S390_VXRS_LOW	0x309	/* S390 vector registers 0-15 upper half */
					/*   note name must be "LINUX".  */
#define NT_S390_VXRS_HIGH	0x30a	/* S390 vector registers 16-31 */
					/*   note name must be "LINUX".  */
#define NT_S390_GS_CB	0x30b		/* s390 guarded storage registers */
					/*   note name must be "LINUX".  */
#define NT_S390_GS_BC	0x30c		/* s390 guarded storage broadcast control block */
					/*   note name must be "LINUX".  */
#define NT_ARM_VFP	0x400		/* ARM VFP registers */
/* The following definitions should really use NT_AARCH_..., but defined
   this way for compatibility with Linux.  */
#define NT_ARM_TLS	0x401		/* AArch TLS registers */
					/*   note name must be "LINUX".  */
#define NT_ARM_HW_BREAK	0x402		/* AArch hardware breakpoint registers */
					/*   note name must be "LINUX".  */
#define NT_ARM_HW_WATCH	0x403		/* AArch hardware watchpoint registers */
					/*   note name must be "LINUX".  */
#define NT_ARM_SYSTEM_CALL      0x404   /* AArch ARM system call number */
					/*   note name must be "LINUX".  */
#define NT_ARM_SVE	0x405		/* AArch SVE registers.  */
					/*   note name must be "LINUX".  */
#define NT_ARM_PAC_MASK	0x406		/* AArch pointer authentication code masks */
					/*   note name must be "LINUX".  */
#define NT_ARM_PACA_KEYS  0x407		/* ARM pointer authentication address
					   keys */
					/*   note name must be "LINUX".  */
#define NT_ARM_PACG_KEYS  0x408		/* ARM pointer authentication generic
					   keys */
					/*  note name must be "LINUX".  */
#define NT_ARM_TAGGED_ADDR_CTRL	0x409	/* AArch64 tagged address control
					   (prctl()) */
					/*   note name must be "LINUX".  */
#define NT_ARM_PAC_ENABLED_KEYS	0x40a	/* AArch64 pointer authentication
					   enabled keys (prctl()) */
					/*   note name must be "LINUX".  */
#define NT_ARM_SSVE     0x40b        	/* AArch64 SME streaming SVE registers.  */
					/*   Note: name must be "LINUX".  */
#define NT_ARM_ZA       0x40c           /* AArch64 SME ZA register.  */
					/*   Note: name must be "LINUX".  */
#define NT_ARC_V2	0x600		/* ARC HS accumulator/extra registers.  */
					/*   note name must be "LINUX".  */
#define NT_LARCH_CPUCFG 0xa00		/* LoongArch CPU config registers */
					/*   note name must be "LINUX".  */
#define NT_LARCH_CSR    0xa01		/* LoongArch Control State Registers */
					/*   note name must be "LINUX".  */
#define NT_LARCH_LSX    0xa02		/* LoongArch SIMD eXtension registers */
					/*   note name must be "LINUX".  */
#define NT_LARCH_LASX   0xa03		/* LoongArch Advanced SIMD eXtension registers */
					/*   note name must be "LINUX".  */
#define NT_LARCH_LBT    0xa04		/* LoongArch Binary Translation registers */
					/*   note name must be "CORE".  */
#define NT_RISCV_CSR    0x900		/* RISC-V Control and Status Registers */
					/*   note name must be "LINUX".  */
#define NT_SIGINFO	0x53494749	/* Fields of siginfo_t.  */
#define NT_FILE		0x46494c45	/* Description of mapped files.  */

/* The range 0xff000000 to 0xffffffff is set aside for notes that don't
   originate from any particular operating system.  */
#define NT_GDB_TDESC	0xff000000	/* Contains copy of GDB's target description XML.  */

/* Note segments for core files on dir-style procfs systems.  */

#define NT_PSTATUS	10		/* Has a struct pstatus */
#define NT_FPREGS	12		/* Has a struct fpregset */
#define NT_PSINFO	13		/* Has a struct psinfo */
#define NT_LWPSTATUS	16		/* Has a struct lwpstatus_t */
#define NT_LWPSINFO	17		/* Has a struct lwpsinfo_t */
#define NT_WIN32PSTATUS	18		/* Has a struct win32_pstatus */

/* Note segment for SystemTap probes.  */
#define NT_STAPSDT	3

/* Values of note segment descriptor types for object files.  */

#define NT_VERSION	1		/* Contains a version string.  */
#define NT_ARCH		2		/* Contains an architecture string.  */
#define NT_GO_BUILDID	4		/* Contains GO buildid data.  */

/* Values for notes in non-core files using name "GNU".  */

#define NT_GNU_ABI_TAG		1
#define NT_GNU_HWCAP		2	/* Used by ld.so and kernel vDSO.  */
#define NT_GNU_BUILD_ID		3	/* Generated by ld --build-id.  */
#define NT_GNU_GOLD_VERSION	4	/* Generated by gold.  */
#define NT_GNU_PROPERTY_TYPE_0  5	/* Generated by gcc.  */

#define NT_GNU_BUILD_ATTRIBUTE_OPEN	0x100
#define NT_GNU_BUILD_ATTRIBUTE_FUNC	0x101

#define GNU_BUILD_ATTRIBUTE_TYPE_NUMERIC	'*'
#define GNU_BUILD_ATTRIBUTE_TYPE_STRING		'$'
#define GNU_BUILD_ATTRIBUTE_TYPE_BOOL_TRUE	'+'
#define GNU_BUILD_ATTRIBUTE_TYPE_BOOL_FALSE	'!'

#define GNU_BUILD_ATTRIBUTE_VERSION	1
#define GNU_BUILD_ATTRIBUTE_STACK_PROT	2
#define GNU_BUILD_ATTRIBUTE_RELRO	3
#define GNU_BUILD_ATTRIBUTE_STACK_SIZE	4
#define GNU_BUILD_ATTRIBUTE_TOOL	5
#define GNU_BUILD_ATTRIBUTE_ABI		6
#define GNU_BUILD_ATTRIBUTE_PIC		7
#define GNU_BUILD_ATTRIBUTE_SHORT_ENUM	8

#define NOTE_GNU_PROPERTY_SECTION_NAME	".note.gnu.property"
#define GNU_BUILD_ATTRS_SECTION_NAME	".gnu.build.attributes"

/* Values used in GNU .note.gnu.property notes (NT_GNU_PROPERTY_TYPE_0).  */
#define GNU_PROPERTY_STACK_SIZE			1
#define GNU_PROPERTY_NO_COPY_ON_PROTECTED	2

/* A 4-byte unsigned integer property: A bit is set if it is set in all
   relocatable inputs.  */
#define GNU_PROPERTY_UINT32_AND_LO	0xb0000000
#define GNU_PROPERTY_UINT32_AND_HI	0xb0007fff

/* A 4-byte unsigned integer property: A bit is set if it is set in any
   relocatable inputs.  */
#define GNU_PROPERTY_UINT32_OR_LO	0xb0008000
#define GNU_PROPERTY_UINT32_OR_HI	0xb000ffff

/* The needed properties by the object file.  */
#define GNU_PROPERTY_1_NEEDED		GNU_PROPERTY_UINT32_OR_LO

/* Set if the object file requires canonical function pointers and
   cannot be used with copy relocation.  */
#define GNU_PROPERTY_1_NEEDED_INDIRECT_EXTERN_ACCESS	(1U << 0)

/* Processor-specific semantics, lo */
#define GNU_PROPERTY_LOPROC  0xc0000000
/* Processor-specific semantics, hi */
#define GNU_PROPERTY_HIPROC  0xdfffffff
/* Application-specific semantics, lo */
#define GNU_PROPERTY_LOUSER  0xe0000000
/* Application-specific semantics, hi */
#define GNU_PROPERTY_HIUSER  0xffffffff

/* GNU_PROPERTY_X86_ISA_1_BASELINE: CMOV, CX8 (cmpxchg8b), FPU (fld),
   MMX, OSFXSR (fxsave), SCE (syscall), SSE and SSE2.  */
#define GNU_PROPERTY_X86_ISA_1_BASELINE		(1U << 0)
/* GNU_PROPERTY_X86_ISA_1_V2: GNU_PROPERTY_X86_ISA_1_BASELINE,
   CMPXCHG16B (cmpxchg16b), LAHF-SAHF (lahf), POPCNT (popcnt), SSE3,
   SSSE3, SSE4.1 and SSE4.2.  */
#define GNU_PROPERTY_X86_ISA_1_V2		(1U << 1)
/* GNU_PROPERTY_X86_ISA_1_V3: GNU_PROPERTY_X86_ISA_1_V2, AVX, AVX2, BMI1,
   BMI2, F16C, FMA, LZCNT, MOVBE, XSAVE.  */
#define GNU_PROPERTY_X86_ISA_1_V3		(1U << 2)
/* GNU_PROPERTY_X86_ISA_1_V4: GNU_PROPERTY_X86_ISA_1_V3, AVX512F,
   AVX512BW, AVX512CD, AVX512DQ and AVX512VL.  */
#define GNU_PROPERTY_X86_ISA_1_V4		(1U << 3)

/* Values used in GNU .note.ABI-tag notes (NT_GNU_ABI_TAG).  */
#define GNU_ABI_TAG_LINUX	0
#define GNU_ABI_TAG_HURD	1
#define GNU_ABI_TAG_SOLARIS	2
#define GNU_ABI_TAG_FREEBSD	3
#define GNU_ABI_TAG_NETBSD	4
#define GNU_ABI_TAG_SYLLABLE	5
#define GNU_ABI_TAG_NACL	6

/* These three macros disassemble and assemble a symbol table st_info field,
   which contains the symbol binding and symbol type.  The STB_ and STT_
   defines identify the binding and type.  */

#define ELF_ST_BIND(val)		(((unsigned int)(val)) >> 4)
#define ELF_ST_TYPE(val)		((val) & 0xF)
#define ELF_ST_INFO(bind,type)		(((bind) << 4) + ((type) & 0xF))

/* The 64bit and 32bit versions of these macros are identical, but
   the ELF spec defines them, so here they are.  */
#define ELF32_ST_BIND  ELF_ST_BIND
#define ELF32_ST_TYPE  ELF_ST_TYPE
#define ELF32_ST_INFO  ELF_ST_INFO
#define ELF64_ST_BIND  ELF_ST_BIND
#define ELF64_ST_TYPE  ELF_ST_TYPE
#define ELF64_ST_INFO  ELF_ST_INFO

/* This macro disassembles and assembles a symbol's visibility into
   the st_other field.  The STV_ defines specify the actual visibility.  */

#define ELF_ST_VISIBILITY(v)		((v) & 0x3)
/* The remaining bits in the st_other field are not currently used.
   They should be set to zero.  */

#define ELF32_ST_VISIBILITY  ELF_ST_VISIBILITY
#define ELF64_ST_VISIBILITY  ELF_ST_VISIBILITY


#define STN_UNDEF	0		/* Undefined symbol index */

#define STB_LOCAL	0		/* Symbol not visible outside obj */
#define STB_GLOBAL	1		/* Symbol visible outside obj */
#define STB_WEAK	2		/* Like globals, lower precedence */
#define STB_LOOS	10		/* OS-specific semantics */
#define STB_GNU_UNIQUE	10		/* Symbol is unique in namespace */
#define STB_HIOS	12		/* OS-specific semantics */
#define STB_LOPROC	13		/* Processor-specific semantics */
#define STB_HIPROC	15		/* Processor-specific semantics */

#define STT_NOTYPE	0		/* Symbol type is unspecified */
#define STT_OBJECT	1		/* Symbol is a data object */
#define STT_FUNC	2		/* Symbol is a code object */
#define STT_SECTION	3		/* Symbol associated with a section */
#define STT_FILE	4		/* Symbol gives a file name */
#define STT_COMMON	5		/* An uninitialised common block */
#define STT_TLS		6		/* Thread local data object */
#define STT_RELC	8		/* Complex relocation expression */
#define STT_SRELC	9		/* Signed Complex relocation expression */
#define STT_LOOS	10		/* OS-specific semantics */
#define STT_GNU_IFUNC	10		/* Symbol is an indirect code object */
#define STT_HIOS	12		/* OS-specific semantics */
#define STT_LOPROC	13		/* Processor-specific semantics */
#define STT_HIPROC	15		/* Processor-specific semantics */

/* The following constants control how a symbol may be accessed once it has
   become part of an executable or shared library.  */

#define STV_DEFAULT	0		/* Visibility is specified by binding type */
#define STV_INTERNAL	1		/* OS specific version of STV_HIDDEN */
#define STV_HIDDEN	2		/* Can only be seen inside currect component */
#define STV_PROTECTED	3		/* Treat as STB_LOCAL inside current component */

/* These constants are used for the version number of a Elf32_Verdef
   structure.  */

#define VER_DEF_NONE		0
#define VER_DEF_CURRENT		1

/* These constants appear in the vd_flags field of a Elf32_Verdef
   structure.

   Cf. the Solaris Linker and Libraries Guide, Ch. 7, Object File Format,
   Versioning Sections, for a description:

   http://docs.sun.com/app/docs/doc/819-0690/chapter6-93046?l=en&a=view  */

#define VER_FLG_BASE		0x1
#define VER_FLG_WEAK		0x2
#define VER_FLG_INFO		0x4

/* These special constants can be found in an Elf32_Versym field.  */

#define VER_NDX_LOCAL		0
#define VER_NDX_GLOBAL		1

/* These constants are used for the version number of a Elf32_Verneed
   structure.  */

#define VER_NEED_NONE		0
#define VER_NEED_CURRENT	1

/* This flag appears in a Versym structure.  It means that the symbol
   is hidden, and is only visible with an explicit version number.
   This is a GNU extension.  */

#define VERSYM_HIDDEN		0x8000

/* This is the mask for the rest of the Versym information.  */

#define VERSYM_VERSION		0x7fff

/* This is a special token which appears as part of a symbol name.  It
   indictes that the rest of the name is actually the name of a
   version node, and is not part of the actual name.  This is a GNU
   extension.  For example, the symbol name `stat@ver2' is taken to
   mean the symbol `stat' in version `ver2'.  */

#define ELF_VER_CHR	'@'

/* Section Group Flags.	 */
#define GRP_COMDAT		0x1	/* A COMDAT group */
#define GRP_MASKOS 	 0x0ff00000	/* Bits in this range reserved for OS specific use.  */
#define GRP_MASKPROC 	 0xf0000000	/* Bits in this range reserved for processor use.  */

/* Auxv a_type values.  */

#define AT_NULL		0		/* End of vector */
#define AT_IGNORE	1		/* Entry should be ignored */
#define AT_EXECFD	2		/* File descriptor of program */
#define AT_PHDR		3		/* Program headers for program */
#define AT_PHENT	4		/* Size of program header entry */
#define AT_PHNUM	5		/* Number of program headers */
#define AT_PAGESZ	6		/* System page size */
#define AT_BASE		7		/* Base address of interpreter */
#define AT_FLAGS	8		/* Flags */
#define AT_ENTRY	9		/* Entry point of program */
#define AT_NOTELF	10		/* Program is not ELF */
#define AT_UID		11		/* Real uid */
#define AT_EUID		12		/* Effective uid */
#define AT_GID		13		/* Real gid */
#define AT_EGID		14		/* Effective gid */
#define AT_CLKTCK	17		/* Frequency of times() */
#define AT_PLATFORM	15		/* String identifying platform.  */
#define AT_HWCAP	16		/* Machine dependent hints about
					   processor capabilities.  */
#define AT_FPUCW	18		/* Used FPU control word.  */
#define AT_DCACHEBSIZE	19		/* Data cache block size.  */
#define AT_ICACHEBSIZE	20		/* Instruction cache block size.  */
#define AT_UCACHEBSIZE	21		/* Unified cache block size.  */
#define AT_IGNOREPPC	22		/* Entry should be ignored */
#define	AT_SECURE	23		/* Boolean, was exec setuid-like?  */
#define AT_BASE_PLATFORM 24		/* String identifying real platform,
					   may differ from AT_PLATFORM.  */
#define AT_RANDOM	25		/* Address of 16 random bytes.  */
#define AT_HWCAP2	26		/* Extension of AT_HWCAP.  */
#define AT_EXECFN	31		/* Filename of executable.  */
/* Pointer to the global system page used for system calls and other
   nice things.  */
#define AT_SYSINFO	32
#define AT_SYSINFO_EHDR	33 /* Pointer to ELF header of system-supplied DSO.  */

/* More complete cache descriptions than AT_[DIU]CACHEBSIZE.  If the
   value is -1, then the cache doesn't exist.  Otherwise:

   bit 0-3:  Cache set-associativity; 0 means fully associative.
   bit 4-7:  Log2 of cacheline size.
   bit 8-31:  Size of the entire cache >> 8.  */

#define AT_L1I_CACHESHAPE 34
#define AT_L1D_CACHESHAPE 35
#define AT_L2_CACHESHAPE  36
#define AT_L3_CACHESHAPE  37

#define ELF64_R_INFO(s,t)	(((bfd_vma) (s) << 31 << 1) + (bfd_vma) (t))
#endif /* _ELF_COMMON_H */
//------------------------------------------------include "elf/external.h"
/* ELF support for BFD. */
/* This file is part of ELF support for BFD, and contains the portions
   that describe how ELF is represented externally by the BFD library.
   I.E. it describes the in-file representation of ELF.  It requires
   the elf/common.h file which contains the portions that are common to
   both the internal and external representations.  */

/* The 64-bit stuff is kind of random.  Perhaps someone will publish a
   spec someday.  */

#ifndef _ELF_EXTERNAL_H
#define _ELF_EXTERNAL_H

/* Special section indices, which may show up in st_shndx fields, among
   other places.  */

#define SHN_LORESERVE	0xFF00		/* Begin range of reserved indices */
#define SHN_LOPROC	0xFF00		/* Begin range of appl-specific */
#define SHN_HIPROC	0xFF1F		/* End range of appl-specific */
#define SHN_LOOS	0xFF20		/* OS specific semantics, lo */
#define SHN_HIOS	0xFF3F		/* OS specific semantics, hi */
#define SHN_ABS		0xFFF1		/* Associated symbol is absolute */
#define SHN_COMMON	0xFFF2		/* Associated symbol is in common */
#define SHN_XINDEX	0xFFFF		/* Section index is held elsewhere */
#define SHN_HIRESERVE	0xFFFF		/* End range of reserved indices */

typedef struct {
  unsigned char	e_ident[16];		/* ELF "magic number" */
  unsigned char	e_type[2];		/* Identifies object file type */
  unsigned char	e_machine[2];		/* Specifies required architecture */
  unsigned char	e_version[4];		/* Identifies object file version */
  unsigned char	e_entry[8];		/* Entry point virtual address */
  unsigned char	e_phoff[8];		/* Program header table file offset */
  unsigned char	e_shoff[8];		/* Section header table file offset */
  unsigned char	e_flags[4];		/* Processor-specific flags */
  unsigned char	e_ehsize[2];		/* ELF header size in bytes */
  unsigned char	e_phentsize[2];		/* Program header table entry size */
  unsigned char	e_phnum[2];		/* Program header table entry count */
  unsigned char	e_shentsize[2];		/* Section header table entry size */
  unsigned char	e_shnum[2];		/* Section header table entry count */
  unsigned char	e_shstrndx[2];		/* Section header string table index */
} Elf64_External_Ehdr;

/* Program header */
typedef struct {
  unsigned char	p_type[4];		/* Identifies program segment type */
  unsigned char	p_flags[4];		/* Segment flags */
  unsigned char	p_offset[8];		/* Segment file offset */
  unsigned char	p_vaddr[8];		/* Segment virtual address */
  unsigned char	p_paddr[8];		/* Segment physical address */
  unsigned char	p_filesz[8];		/* Segment size in file */
  unsigned char	p_memsz[8];		/* Segment size in memory */
  unsigned char	p_align[8];		/* Segment alignment, file & memory */
} Elf64_External_Phdr;

/* Section header */
typedef struct {
  unsigned char	sh_name[4];		/* Section name, index in string tbl */
  unsigned char	sh_type[4];		/* Type of section */
  unsigned char	sh_flags[8];		/* Miscellaneous section attributes */
  unsigned char	sh_addr[8];		/* Section virtual addr at execution */
  unsigned char	sh_offset[8];		/* Section file offset */
  unsigned char	sh_size[8];		/* Size of section in bytes */
  unsigned char	sh_link[4];		/* Index of another section */
  unsigned char	sh_info[4];		/* Additional section information */
  unsigned char	sh_addralign[8];	/* Section alignment */
  unsigned char	sh_entsize[8];		/* Entry size if section holds table */
} Elf64_External_Shdr;

typedef struct {
  unsigned char	ch_type[4];		/* Type of compression */
  unsigned char	ch_reserved[4];		/* Padding */
  unsigned char	ch_size[8];		/* Size of uncompressed data in bytes */
  unsigned char	ch_addralign[8];	/* Alignment of uncompressed data  */
} Elf64_External_Chdr;

/* Symbol table entry */
typedef struct {
  unsigned char	st_name[4];		/* Symbol name, index in string tbl */
  unsigned char	st_info[1];		/* Type and binding attributes */
  unsigned char	st_other[1];		/* No defined meaning, 0 */
  unsigned char	st_shndx[2];		/* Associated section index */
  unsigned char	st_value[8];		/* Value of the symbol */
  unsigned char	st_size[8];		/* Associated symbol size */
} Elf64_External_Sym;

typedef struct {
  unsigned char est_shndx[4];		/* Section index */
} Elf_External_Sym_Shndx;

/* Note segments */

typedef struct {
  unsigned char	namesz[4];		/* Size of entry's owner string */
  unsigned char	descsz[4];		/* Size of the note descriptor */
  unsigned char	type[4];		/* Interpretation of the descriptor */
  char		name[1];		/* Start of the name+desc data */
} Elf_External_Note;

/* Align an address upward to a boundary, expressed as a number of bytes.
   E.g. align to an 8-byte boundary with argument of 8.  */
#define ELF_ALIGN_UP(addr, boundary) \
  (((bfd_vma) (addr) + ((boundary) - 1)) & ~ (bfd_vma) ((boundary) -1))

/* Compute the offset of the note descriptor from size of note entry's
   owner string and note alignment.  */
#define ELF_NOTE_DESC_OFFSET(namesz, align) \
  ELF_ALIGN_UP (offsetof (Elf_External_Note, name) + (namesz), (align))

/* Compute the offset of the next note entry from size of note entry's
   owner string, size of the note descriptor and note alignment.  */
#define ELF_NOTE_NEXT_OFFSET(namesz, descsz, align) \
  ELF_ALIGN_UP (ELF_NOTE_DESC_OFFSET ((namesz), (align)) + (descsz), \
		(align))

/* Relocation Entries */
typedef struct {
  unsigned char r_offset[4];	/* Location at which to apply the action */
  unsigned char	r_info[4];	/* index and type of relocation */
} Elf32_External_Rel;

typedef struct {
  unsigned char r_offset[4];	/* Location at which to apply the action */
  unsigned char	r_info[4];	/* index and type of relocation */
  unsigned char	r_addend[4];	/* Constant addend used to compute value */
} Elf32_External_Rela;

typedef struct {
  unsigned char r_data[4];	/* RELR entry */
} Elf32_External_Relr;

typedef struct {
  unsigned char r_offset[8];	/* Location at which to apply the action */
  unsigned char	r_info[8];	/* index and type of relocation */
} Elf64_External_Rel;

typedef struct {
  unsigned char r_offset[8];	/* Location at which to apply the action */
  unsigned char	r_info[8];	/* index and type of relocation */
  unsigned char	r_addend[8];	/* Constant addend used to compute value */
} Elf64_External_Rela;

typedef struct {
  unsigned char r_data[8];	/* RELR entry */
} Elf64_External_Relr;

/* dynamic section structure */
typedef struct {
  unsigned char	d_tag[8];		/* entry tag value */
  union {
    unsigned char	d_val[8];
    unsigned char	d_ptr[8];
  } d_un;
} Elf64_External_Dyn;

/* The version structures are currently size independent.  They are
   named without a 32 or 64.  If that ever changes, these structures
   will need to be renamed.  */

/* This structure appears in a SHT_GNU_verdef section.  */

typedef struct {
  unsigned char		vd_version[2];
  unsigned char		vd_flags[2];
  unsigned char		vd_ndx[2];
  unsigned char		vd_cnt[2];
  unsigned char		vd_hash[4];
  unsigned char		vd_aux[4];
  unsigned char		vd_next[4];
} Elf_External_Verdef;

/* This structure appears in a SHT_GNU_verdef section.  */

typedef struct {
  unsigned char		vda_name[4];
  unsigned char		vda_next[4];
} Elf_External_Verdaux;

/* This structure appears in a SHT_GNU_verneed section.  */

typedef struct {
  unsigned char		vn_version[2];
  unsigned char		vn_cnt[2];
  unsigned char		vn_file[4];
  unsigned char		vn_aux[4];
  unsigned char		vn_next[4];
} Elf_External_Verneed;

/* This structure appears in a SHT_GNU_verneed section.  */

typedef struct {
  unsigned char		vna_hash[4];
  unsigned char		vna_flags[2];
  unsigned char		vna_other[2];
  unsigned char		vna_name[4];
  unsigned char		vna_next[4];
} Elf_External_Vernaux;

/* This structure appears in a SHT_GNU_versym section.  This is not a
   standard ELF structure; ELF just uses Elf32_Half.  */

typedef struct {
  unsigned char		vs_vers[2];
} ATTRIBUTE_PACKED  Elf_External_Versym;

/* Structure for syminfo section.  */
typedef struct
{
  unsigned char		si_boundto[2];
  unsigned char		si_flags[2];
} Elf_External_Syminfo;


/* This structure appears on the stack and in NT_AUXV core file notes.  */
typedef struct {
  unsigned char		a_type[8];
  unsigned char		a_val[8];
} Elf64_External_Auxv;

/* Size of SHT_GROUP section entry.  */

#define GRP_ENTRY_SIZE		4

#endif /* _ELF_EXTERNAL_H */
//---------------------------------------------include "elf/internal.h"
/* ELF support for BFD. */
/* This file is part of ELF support for BFD, and contains the portions
   that describe how ELF is represented internally in the BFD library.
   I.E. it describes the in-memory representation of ELF.  It requires
   the elf-common.h file which contains the portions that are common to
   both the internal and external representations.  */

/* NOTE that these structures are not kept in the same order as they appear
   in the object file.  In some cases they've been reordered for more optimal
   packing under various circumstances.  */

#ifndef _ELF_INTERNAL_H
#define _ELF_INTERNAL_H

/* Special section indices, which may show up in st_shndx fields, among
   other places.  */
#undef SHN_UNDEF
#undef SHN_LORESERVE
#undef SHN_LOPROC
#undef SHN_HIPROC
#undef SHN_LOOS
#undef SHN_HIOS
#undef SHN_ABS
#undef SHN_COMMON
#undef SHN_XINDEX
#undef SHN_HIRESERVE
#define SHN_UNDEF	0		/* Undefined section reference */
#define SHN_LORESERVE	(-0x100u)	/* Begin range of reserved indices */
#define SHN_LOPROC	(-0x100u)	/* Begin range of appl-specific */
#define SHN_HIPROC	(-0xE1u)	/* End range of appl-specific */
#define SHN_LOOS	(-0xE0u)	/* OS specific semantics, lo */
#define SHN_HIOS	(-0xC1u)	/* OS specific semantics, hi */
#define SHN_ABS		(-0xFu)		/* Associated symbol is absolute */
#define SHN_COMMON	(-0xEu)		/* Associated symbol is in common */
#define SHN_XINDEX	(-0x1u)		/* Section index is held elsewhere */
#define SHN_HIRESERVE	(-0x1u)		/* End range of reserved indices */
#define SHN_BAD		(-0x101u)	/* Used internally by bfd */

/* ELF Header */

#define EI_NIDENT	16		/* Size of e_ident[] */

typedef struct elf_internal_ehdr {
  unsigned char		e_ident[EI_NIDENT]; /* ELF "magic number" */
  bfd_vma		e_entry;	/* Entry point virtual address */
  size_t		e_phoff;	/* Program header table file offset */
  size_t		e_shoff;	/* Section header table file offset */
  unsigned long		e_version;	/* Identifies object file version */
  unsigned long		e_flags;	/* Processor-specific flags */
  unsigned short	e_type;		/* Identifies object file type */
  unsigned short	e_machine;	/* Specifies required architecture */
  unsigned int		e_ehsize;	/* ELF header size in bytes */
  unsigned int		e_phentsize;	/* Program header table entry size */
  unsigned int		e_phnum;	/* Program header table entry count */
  unsigned int		e_shentsize;	/* Section header table entry size */
  unsigned int		e_shnum;	/* Section header table entry count */
  unsigned int		e_shstrndx;	/* Section header string table index */
} Elf_Internal_Ehdr;

/* Program header */

struct elf_internal_phdr {
  unsigned long	p_type;		     /* Identifies program segment type.  */
  unsigned long	p_flags;	     /* Segment flags.  */
  bfd_vma	p_offset;	     /* Segment file offset in octets.  */
  bfd_vma	p_vaddr;	     /* Segment virtual address in octets.  */
  bfd_vma	p_paddr;	     /* Segment physical address in octets.  */
  bfd_vma	p_filesz;	     /* Segment size in file in octets.  */
  bfd_vma	p_memsz;	     /* Segment size in memory in octets.  */
  bfd_vma	p_align;	     /* Segment alignment in bytes, file
					& memory */
};

typedef struct elf_internal_phdr Elf_Internal_Phdr;

/* Section header */
typedef struct elf_internal_shdr {
  unsigned int	sh_name;		/* Section name, index in string tbl */
  unsigned int	sh_type;		/* Type of section */
  bfd_vma	sh_flags;		/* Miscellaneous section attributes */
  bfd_vma	sh_addr;		/* Section virtual addr at execution in
					   octets.  */
  file_ptr	sh_offset;		/* Section file offset in octets.  */
  size_t	sh_size;		/* Size of section in octets.  */
  unsigned int	sh_link;		/* Index of another section */
  unsigned int	sh_info;		/* Additional section information */
  bfd_vma	sh_addralign;		/* Section alignment */
  size_t	sh_entsize;		/* Entry size if section holds table */

  /* The internal rep also has some cached info associated with it. */
  asection *	bfd_section;		/* Associated BFD section.  */
  unsigned char *contents;		/* Section contents.  */
} Elf_Internal_Shdr;

/* Compression header */

typedef struct elf_internal_chdr {
  unsigned int	ch_type;		/* Type of compression */
  size_t	ch_size;		/* Size of uncompressed data in bytes */
  bfd_vma	ch_addralign;		/* Alignment of uncompressed data */
} Elf_Internal_Chdr;

/* Symbol table entry */

typedef struct elf_internal_sym {
  bfd_vma	st_value;		/* Value of the symbol */
  bfd_vma	st_size;		/* Associated symbol size */
  unsigned long	st_name;		/* Symbol name, index in string tbl */
  unsigned char	st_info;		/* Type and binding attributes */
  unsigned char	st_other;		/* Visibilty, and target specific */
  unsigned char st_target_internal;	/* Internal-only information */
  unsigned int  st_shndx;		/* Associated section index */
} Elf_Internal_Sym;

/* Note segments */

typedef struct elf_internal_note {
  unsigned long	namesz;			/* Size of entry's owner string */
  unsigned long	descsz;			/* Size of the note descriptor */
  unsigned long	type;			/* Interpretation of the descriptor */
  char *	namedata;		/* Start of the name+desc data */
  char *	descdata;		/* Start of the desc data */
  bfd_vma	descpos;		/* File offset of the descdata */
} Elf_Internal_Note;

/* Relocation Entries */

typedef struct elf_internal_rela {
  bfd_vma	r_offset;	/* Location at which to apply the action */
  bfd_vma	r_info;		/* Index and Type of relocation */
  bfd_vma	r_addend;	/* Constant addend used to compute value */
} Elf_Internal_Rela;

/* dynamic section structure */

typedef struct elf_internal_dyn {
  /* This needs to support 64-bit values in elf64.  */
  bfd_vma d_tag;		/* entry tag value */
  union {
    /* This needs to support 64-bit values in elf64.  */
    bfd_vma	d_val;
    bfd_vma	d_ptr;
  } d_un;
} Elf_Internal_Dyn;

/* This structure appears in a SHT_GNU_verdef section.  */

typedef struct elf_internal_verdef {
  unsigned short vd_version;	/* Version number of structure.  */
  unsigned short vd_flags;	/* Flags (VER_FLG_*).  */
  unsigned short vd_ndx;	/* Version index.  */
  unsigned short vd_cnt;	/* Number of verdaux entries.  */
  unsigned long	 vd_hash;	/* Hash of name.  */
  unsigned long	 vd_aux;	/* Offset to verdaux entries.  */
  unsigned long	 vd_next;	/* Offset to next verdef.  */

  /* These fields are set up when BFD reads in the structure.  FIXME:
     It would be cleaner to store these in a different structure.  */
  bfd			      *vd_bfd;		/* BFD.  */
  const char		      *vd_nodename;	/* Version name.  */
  struct elf_internal_verdef  *vd_nextdef;	/* vd_next as pointer.  */
  struct elf_internal_verdaux *vd_auxptr;	/* vd_aux as pointer.  */
  unsigned int		       vd_exp_refno;	/* Used by the linker.  */
} Elf_Internal_Verdef;

/* This structure appears in a SHT_GNU_verdef section.  */

typedef struct elf_internal_verdaux {
  unsigned long vda_name;	/* String table offset of name.  */
  unsigned long vda_next;	/* Offset to next verdaux.  */

  /* These fields are set up when BFD reads in the structure.  FIXME:
     It would be cleaner to store these in a different structure.  */
  const char *vda_nodename;			/* vda_name as pointer.  */
  struct elf_internal_verdaux *vda_nextptr;	/* vda_next as pointer.  */
} Elf_Internal_Verdaux;

/* This structure appears in a SHT_GNU_verneed section.  */

typedef struct elf_internal_verneed {
  unsigned short vn_version;	/* Version number of structure.  */
  unsigned short vn_cnt;	/* Number of vernaux entries.  */
  unsigned long	 vn_file;	/* String table offset of library name.  */
  unsigned long	 vn_aux;	/* Offset to vernaux entries.  */
  unsigned long	 vn_next;	/* Offset to next verneed.  */

  /* These fields are set up when BFD reads in the structure.  FIXME:
     It would be cleaner to store these in a different structure.  */
  bfd			      *vn_bfd;		/* BFD.  */
  const char                  *vn_filename;	/* vn_file as pointer.  */
  struct elf_internal_vernaux *vn_auxptr;	/* vn_aux as pointer.  */
  struct elf_internal_verneed *vn_nextref;	/* vn_nextref as pointer.  */
} Elf_Internal_Verneed;

/* This structure appears in a SHT_GNU_verneed section.  */

typedef struct elf_internal_vernaux {
  unsigned long	 vna_hash;	/* Hash of dependency name.  */
  unsigned short vna_flags;	/* Flags (VER_FLG_*).  */
  unsigned short vna_other;	/* Unused.  */
  unsigned long	 vna_name;	/* String table offset to version name.  */
  unsigned long	 vna_next;	/* Offset to next vernaux.  */

  /* These fields are set up when BFD reads in the structure.  FIXME:
     It would be cleaner to store these in a different structure.  */
  const char                  *vna_nodename;	/* vna_name as pointer.  */
  struct elf_internal_vernaux *vna_nextptr;	/* vna_next as pointer.  */
} Elf_Internal_Vernaux;

/* This structure appears in a SHT_GNU_versym section.  This is not a
   standard ELF structure; ELF just uses Elf32_Half.  */

typedef struct elf_internal_versym {
  unsigned short vs_vers;
} Elf_Internal_Versym;

/* Structure for syminfo section.  */
typedef struct
{
  unsigned short int 	si_boundto;
  unsigned short int	si_flags;
} Elf_Internal_Syminfo;

/* This structure appears on the stack and in NT_AUXV core file notes.  */
typedef struct
{
  bfd_vma a_type;
  bfd_vma a_val;
} Elf_Internal_Auxv;


/* This structure is used to describe how sections should be assigned
   to program segments.  */

struct elf_segment_map
{
  /* Next program segment.  */
  struct elf_segment_map *next;
  /* Program segment type.  */
  unsigned long p_type;
  /* Program segment flags.  */
  unsigned long p_flags;
  /* Program segment physical address in octets.  */
  bfd_vma p_paddr;
  /* Program segment virtual address offset from section vma in bytes.  */
  bfd_vma p_vaddr_offset;
  /* Program segment alignment.  */
  bfd_vma p_align;
  /* Segment size in file and memory in octets.  */
  bfd_vma p_size;
  /* Whether the p_flags field is valid; if not, the flags are based
     on the section flags.  */
  unsigned int p_flags_valid : 1;
  /* Whether the p_paddr field is valid; if not, the physical address
     is based on the section lma values.  */
  unsigned int p_paddr_valid : 1;
  /* Whether the p_align field is valid; if not, PT_LOAD segment
     alignment is based on the default maximum page size.  */
  unsigned int p_align_valid : 1;
  /* Whether the p_size field is valid; if not, the size are based
     on the section sizes.  */
  unsigned int p_size_valid : 1;
  /* Whether this segment includes the file header.  */
  unsigned int includes_filehdr : 1;
  /* Whether this segment includes the program headers.  */
  unsigned int includes_phdrs : 1;
  /* Assume this PT_LOAD header has an lma of zero when sorting
     headers before assigning file offsets.  PT_LOAD headers with this
     flag set are placed after one with includes_filehdr set, and
     before PT_LOAD headers without this flag set.  */
  unsigned int no_sort_lma : 1;
  /* Index holding original order before sorting segments.  */
  unsigned int idx;
  /* Number of sections (may be 0).  */
  unsigned int count;
  /* Sections.  Actual number of elements is in count field.  */
  asection *sections[1];
};

/* .tbss is special.  It doesn't contribute memory space to normal
   segments and it doesn't take file space in normal segments.  */
#define ELF_TBSS_SPECIAL(sec_hdr, segment)			\
  (((sec_hdr)->sh_flags & SHF_TLS) != 0				\
   && (sec_hdr)->sh_type == SHT_NOBITS				\
   && (segment)->p_type != PT_TLS)

#define ELF_SECTION_SIZE(sec_hdr, segment)			\
  (ELF_TBSS_SPECIAL(sec_hdr, segment) ? 0 : (sec_hdr)->sh_size)

#endif /* _ELF_INTERNAL_H */

/* The number of entries in a section is its size divided by the size
   of a single entry.  This is normally only applicable to reloc and
   symbol table sections.
   PR 9934: It is possible to have relocations that do not refer to
   symbols, thus it is also possible to have a relocation section in
   an object file, but no symbol table.  */
#define NUM_SHDR_ENTRIES(shdr) ((shdr)->sh_entsize > 0 ? (shdr)->sh_size / (shdr)->sh_entsize : 0)

#define NAME(x, y) x ## 64 ## _ ## y

#define ElfNAME(X)	NAME(Elf,X)
#define elfNAME(X)	NAME(elf,X)

/* Information held for an ELF symbol.  The first field is the
   corresponding asymbol.  Every symbol is an ELF file is actually a
   pointer to this structure, although it is often handled as a
   pointer to an asymbol.  */

typedef struct {
  /* The BFD symbol.  */
  asymbol symbol;
  /* ELF symbol information.  */
  Elf_Internal_Sym internal_elf_sym;
  /* Backend specific information.  */
  union
    {
      unsigned int hppa_arg_reloc;
      void *mips_extr;
      void *any;
    }
  tc_data;

  /* Version information.  This is from an Elf_Internal_Versym
     structure in a SHT_GNU_versym section.  It is zero if there is no
     version information.  */
  unsigned short version;

} elf_symbol_type;

struct elf_strtab_hash;
struct got_entry;
struct plt_entry;

union gotplt_union
  {
    bfd_signed_vma refcount;
    bfd_vma offset;
    struct got_entry *glist;
    struct plt_entry *plist;
  };

struct elf_link_virtual_table_entry
  {
    /* Virtual table entry use information.  This array is nominally of size
       size/sizeof(target_void_pointer), though we have to be able to assume
       and track a size while the symbol is still undefined.  It is indexed
       via offset/sizeof(target_void_pointer).  */
    size_t size;
    bool *used;

    /* Virtual table derivation info.  */
    struct elf_link_hash_entry *parent;
  };

/* ELF symbol version.  */
enum elf_symbol_version
  {
    unknown = 0,
    unversioned,
    versioned,
    versioned_hidden
  };

/* Will references to this symbol always reference the symbol
   in this object?  */
#define SYMBOL_REFERENCES_LOCAL(INFO, H) \
  _bfd_elf_symbol_refs_local_p (H, INFO, 0)

/* Will _calls_ to this symbol always call the version in this object?  */
#define SYMBOL_CALLS_LOCAL(INFO, H) \
  _bfd_elf_symbol_refs_local_p (H, INFO, 1)

/* Whether an undefined weak symbol should resolve to its link-time
   value, even in PIC or PIE objects.  The linker_def test is to
   handle symbols like __ehdr_start that may be undefweak in early
   stages of linking but are guaranteed to be defined later.  */
#define UNDEFWEAK_NO_DYNAMIC_RELOC(INFO, H)		\
  ((H)->root.type == bfd_link_hash_undefweak		\
   && !(H)->root.linker_def				\
   && (ELF_ST_VISIBILITY ((H)->other) != STV_DEFAULT	\
       || (INFO)->dynamic_undefined_weak == 0))

/* Common symbols that are turned into definitions don't have the
   DEF_REGULAR flag set, so they might appear to be undefined.
   Symbols defined in linker scripts also don't have DEF_REGULAR set.  */
#define ELF_COMMON_DEF_P(H) \
  (!(H)->def_regular							\
   && !(H)->def_dynamic							\
   && (H)->root.type == bfd_link_hash_defined)

/* Records local symbols to be emitted in the dynamic symbol table.  */

struct elf_link_local_dynamic_entry
{
  struct elf_link_local_dynamic_entry *next;

  /* The input bfd this symbol came from.  */
  bfd *input_bfd;

  /* The index of the local symbol being copied.  */
  long input_indx;

  /* The index in the outgoing dynamic symbol table.  */
  long dynindx;

  /* A copy of the input symbol.  */
  Elf_Internal_Sym isym;
};

struct elf_link_loaded_list
{
  struct elf_link_loaded_list *next;
  bfd *abfd;
};

/* Structures used by the eh_frame optimization code.  */
struct eh_cie_fde {
  union {
    struct {
      /* If REMOVED == 1, this is the CIE that the FDE originally used.
	 The CIE belongs to the same .eh_frame input section as the FDE.

	 If REMOVED == 0, this is the CIE that we have chosen to use for
	 the output FDE.  The CIE's REMOVED field is also 0, but the CIE
	 might belong to a different .eh_frame input section from the FDE.

	 May be NULL to signify that the FDE should be discarded.  */
      struct eh_cie_fde *cie_inf;
      struct eh_cie_fde *next_for_section;
    } fde;
    struct {
      /* CIEs have three states:

	 - REMOVED && !MERGED: Slated for removal because we haven't yet
	   proven that an FDE needs it.  FULL_CIE, if nonnull, points to
	   more detailed information about the CIE.

	 - REMOVED && MERGED: We have merged this CIE with MERGED_WITH,
	   which may not belong to the same input section.

	 - !REMOVED: We have decided to keep this CIE.  SEC is the
	   .eh_frame input section that contains the CIE.  */
      union {
	struct cie *full_cie;
	struct eh_cie_fde *merged_with;
	asection *sec;
      } u;

      /* The offset of the personality data from the start of the CIE,
	 or 0 if the CIE doesn't have any.  */
      unsigned int personality_offset : 8;

      /* Length of augmentation.  aug_str_len is the length of the
	 string including null terminator.  aug_data_len is the length
	 of the rest up to the initial insns.  */
      unsigned int aug_str_len : 3;
      unsigned int aug_data_len : 5;

      /* True if we have marked relocations associated with this CIE.  */
      unsigned int gc_mark : 1;

      /* True if we have decided to turn an absolute LSDA encoding into
	 a PC-relative one.  */
      unsigned int make_lsda_relative : 1;

      /* True if we have decided to turn an absolute personality
	 encoding into a PC-relative one.  */
      unsigned int make_per_encoding_relative : 1;

      /* True if the CIE contains personality data and if that
	 data uses a PC-relative encoding.  Always true when
	 make_per_encoding_relative is.  */
      unsigned int per_encoding_relative : 1;

      /* True if the CIE contains personality data aligned to a
	 multiple of eight bytes.  */
      unsigned int per_encoding_aligned8 : 1;

      /* True if we need to add an 'R' (FDE encoding) entry to the
	 CIE's augmentation data.  */
      unsigned int add_fde_encoding : 1;

      /* True if we have merged this CIE with another.  */
      unsigned int merged : 1;

      /* Unused bits.  */
      unsigned int pad1 : 9;
    } cie;
  } u;
  unsigned int reloc_index;
  unsigned int size;
  unsigned int offset;
  unsigned int new_offset;
  unsigned int fde_encoding : 8;
  unsigned int lsda_encoding : 8;
  unsigned int lsda_offset : 8;

  /* True if this entry represents a CIE, false if it represents an FDE.  */
  unsigned int cie : 1;

  /* True if this entry is currently marked for removal.  */
  unsigned int removed : 1;

  /* True if we need to add a 'z' (augmentation size) entry to the CIE's
     augmentation data, and an associated byte to each of the CIE's FDEs.  */
  unsigned int add_augmentation_size : 1;

  /* True if we have decided to convert absolute FDE relocations into
     relative ones.  This applies to the first relocation in the FDE,
     which is against the code that the FDE describes.  */
  unsigned int make_relative : 1;

  /* Unused bits.  */
  unsigned int pad1 : 4;

  unsigned int *set_loc;
};

struct eh_frame_sec_info
{
  unsigned int count;
  struct cie *cies;
  struct eh_cie_fde entry[1];
};

struct eh_frame_array_ent {
  bfd_vma initial_loc;
  size_t range;
  bfd_vma fde;
};

struct htab;

#define DWARF2_EH_HDR 1
#define COMPACT_EH_HDR 2

/* Endian-neutral code indicating that a function cannot be unwound.  */
#define COMPACT_EH_CANT_UNWIND_OPCODE 0x015d5d01

struct dwarf_eh_frame_hdr_info {
  struct htab *cies;
  unsigned int fde_count;
  /* TRUE if .eh_frame_hdr should contain the sorted search table.
     We build it if we successfully read all .eh_frame input sections
     and recognize them.  */
  bool table;
  struct eh_frame_array_ent *array;
};

struct compact_eh_frame_hdr_info {
  unsigned int allocated_entries;
  /* eh_frame_entry fragments.  */
  asection **entries;
};

struct eh_frame_hdr_info
{
  asection *hdr_sec;
  unsigned int array_count;
  bool frame_hdr_is_compact;
  union
    {
      struct dwarf_eh_frame_hdr_info dwarf;
      struct compact_eh_frame_hdr_info compact;
    }
  u;
};

/* Enum used to identify target specific extensions to the elf_obj_tdata
   and elf_link_hash_table structures.  Note the enums deliberately start
   from 1 so that we can detect an uninitialized field.  The generic value
   is last so that additions to this enum do not need to modify more than
   one line.  */
enum elf_target_id { RISCV_ELF_DATA=39, GENERIC_ELF_DATA };

struct elf_sym_strtab { Elf_Internal_Sym sym; unsigned long dest_index; };

#define elf_symbol_from(S) \
  ((((S)->flags & BSF_SYNTHETIC) == 0				\
    && (S)->the_bfd != NULL					\
    && (S)->the_bfd->tdata.elf_obj_data != 0)			\
   ? (elf_symbol_type *) (S)					\
   : 0)
/* Mapping of ELF section names and types.  */
struct bfd_elf_special_section {
  const char *prefix;
  unsigned int prefix_length;
  /* 0 means name must match PREFIX exactly.
     -1 means name must start with PREFIX followed by an arbitrary string.
     -2 means name must match PREFIX exactly or consist of PREFIX followed
     by a dot then anything.
     > 0 means name must start with the first PREFIX_LENGTH chars of
     PREFIX and finish with the last SUFFIX_LENGTH chars of PREFIX.  */
  signed int suffix_length;
  unsigned int type;
  bfd_vma attr;
};

enum action_discarded { COMPLAIN = 1, PRETEND = 2 };

typedef asection * (*elf_gc_mark_hook_fn)
  (asection *, struct bfd_link_info *, Elf_Internal_Rela *,
   struct elf_link_hash_entry *, Elf_Internal_Sym *);

enum elf_property_kind {
    /* A new property.  */
    property_unknown = 0,
    /* A property ignored by backend.  */
    property_ignored,
    /* A corrupt property reported by backend.  */
    property_corrupt,
    /* A property should be removed due to property merge.  */
    property_remove,
    /* A property which is a number.  */
    property_number
 };

typedef struct elf_property {
  unsigned int pr_type;
  unsigned int pr_datasz;
  union
    {
      /* For property_number, this is a number.  */
      bfd_vma number;
      /* Add a new one if elf_property_kind is updated.  */
    } u;
  enum elf_property_kind pr_kind;
} elf_property;

typedef struct elf_property_list {
  struct elf_property_list *next;
  struct elf_property property;
} elf_property_list;

/* Information about reloc sections associated with a bfd_elf_section_data
   structure.  */
struct bfd_elf_section_reloc_data {
  /* The ELF header for the reloc section associated with this
     section, if any.  */
  Elf_Internal_Shdr *hdr;
  /* The number of relocations currently assigned to HDR.  */
  unsigned int count;
  /* The ELF section number of the reloc section.  Only used for an
     output file.  */
  int idx;
  /* Used by the backend linker to store the symbol hash table entries
     associated with relocs against global symbols.  */
  struct elf_link_hash_entry **hashes;
};

/* Information stored for each BFD section in an ELF file.  This
   structure is allocated by elf_new_section_hook.  */
struct bfd_elf_section_data {
  /* The ELF header for this section.  */
  Elf_Internal_Shdr this_hdr;

  /* INPUT_SECTION_FLAGS if specified in the linker script.  */
  struct flag_info *section_flag_info;

  /* Information about the REL and RELA reloc sections associated
     with this section, if any.  */
  struct bfd_elf_section_reloc_data rel, rela;

  /* The ELF section number of this section.  */
  int this_idx;

  /* Used by the backend linker when generating a shared library to
     record the dynamic symbol index for a section symbol
     corresponding to this section.  A value of 0 means that there is
     no dynamic symbol for this section.  */
  int dynindx;

  /* A pointer to the linked-to section for SHF_LINK_ORDER.  */
  asection *linked_to;

  /* A pointer to the swapped relocs.  If the section uses REL relocs,
     rather than RELA, all the r_addend fields will be zero.  This
     pointer may be NULL.  It is used by the backend linker.  */
  Elf_Internal_Rela *relocs;

  /* A pointer to a linked list tracking dynamic relocs copied for
     local symbols.  */
  void *local_dynrel;

  /* A pointer to the bfd section used for dynamic relocs.  */
  asection *sreloc;

  union {
    /* Group name, if this section is a member of a group.  */
    const char *name;

    /* Group signature sym, if this is the SHT_GROUP section.  */
    struct bfd_symbol *id;
  } group;

  /* For a member of a group, points to the SHT_GROUP section.
     NULL for the SHT_GROUP section itself and non-group sections.  */
  asection *sec_group;

  /* A linked list of member sections in the group.  Circular when used by
     the linker.  For the SHT_GROUP section, points at first member.  */
  asection *next_in_group;

  /* The FDEs associated with this section.  The u.fde.next_in_section
     field acts as a chain pointer.  */
  struct eh_cie_fde *fde_list;

  /* Link from a text section to its .eh_frame_entry section.  */
  asection *eh_frame_entry;

  /* TRUE if the section has secondary reloc sections associated with it.
     FIXME: In the future it might be better to change this into a list
     of secondary reloc sections, making lookup easier and faster.  */
  bool has_secondary_relocs;

  /* A pointer used for various section optimizations.  */
  void *sec_info;
};

#define elf_section_data(sec) ((struct bfd_elf_section_data*)(sec)->used_by_bfd)
#define elf_linked_to_section(sec) (elf_section_data(sec)->linked_to)
#define elf_section_type(sec)	(elf_section_data(sec)->this_hdr.sh_type)
#define elf_section_flags(sec)	(elf_section_data(sec)->this_hdr.sh_flags)
#define elf_section_info(sec)	(elf_section_data(sec)->this_hdr.sh_info)
#define elf_group_name(sec)	(elf_section_data(sec)->group.name)
#define elf_group_id(sec)	(elf_section_data(sec)->group.id)
#define elf_next_in_group(sec)	(elf_section_data(sec)->next_in_group)
#define elf_fde_list(sec)	(elf_section_data(sec)->fde_list)
#define elf_sec_group(sec)	(elf_section_data(sec)->sec_group)
#define elf_section_eh_frame_entry(sec)	(elf_section_data(sec)->eh_frame_entry)

#define xvec_get_elf_backend_data(xvec) \
  ((const struct elf_backend_data *) (xvec)->backend_data)

#define get_elf_backend_data(abfd) \
   xvec_get_elf_backend_data ((abfd)->xvec)

/* The least object attributes (within an attributes subsection) known
   for any target.  Some code assumes that the value 0 is not used and
   the field for that attribute can instead be used as a marker to
   indicate that attributes have been initialized.  */
#define LEAST_KNOWN_OBJ_ATTRIBUTE 2

/* The maximum number of known object attributes for any target.  */
#define NUM_KNOWN_OBJ_ATTRIBUTES 77

/* The value of an object attribute.  The type indicates whether the attribute
   holds and integer, a string, or both.  It can also indicate that there can
   be no default (i.e. all values must be written to file, even zero), or
   that the value is in error and should not be written to file.  */

typedef struct obj_attribute
{
#define ATTR_TYPE_FLAG_INT_VAL    (1 << 0)
#define ATTR_TYPE_FLAG_STR_VAL    (1 << 1)
#define ATTR_TYPE_FLAG_NO_DEFAULT (1 << 2)
#define ATTR_TYPE_FLAG_ERROR	  (1 << 3)

#define ATTR_TYPE_HAS_INT_VAL(TYPE)	((TYPE) & ATTR_TYPE_FLAG_INT_VAL)
#define ATTR_TYPE_HAS_STR_VAL(TYPE)	((TYPE) & ATTR_TYPE_FLAG_STR_VAL)
#define ATTR_TYPE_HAS_NO_DEFAULT(TYPE)	((TYPE) & ATTR_TYPE_FLAG_NO_DEFAULT)
#define ATTR_TYPE_HAS_ERROR(TYPE)	((TYPE) & ATTR_TYPE_FLAG_ERROR)

  int type;
  unsigned int i;
  char *s;
} obj_attribute;

typedef struct obj_attribute_list
{
  struct obj_attribute_list *next;
  unsigned int tag;
  obj_attribute attr;
} obj_attribute_list;

/* Object attributes may either be defined by the processor ABI, index
   OBJ_ATTR_PROC in the *_obj_attributes arrays, or be GNU-specific
   (and possibly also processor-specific), index OBJ_ATTR_GNU.  */
#define OBJ_ATTR_PROC 0
#define OBJ_ATTR_GNU 1
#define OBJ_ATTR_FIRST OBJ_ATTR_PROC
#define OBJ_ATTR_LAST OBJ_ATTR_GNU

/* The following object attribute tags are taken as generic, for all
   targets and for "gnu" where there is no target standard.  */
enum {
  Tag_NULL = 0,
  Tag_File = 1,
  Tag_Section = 2,
  Tag_Symbol = 3,
  Tag_compatibility = 32
};

/* The following struct stores information about every SystemTap section
   found in the object file.  */
struct sdt_note
{
  struct sdt_note *next;
  size_t size;
  bfd_byte data[1];
};

/* tdata information grabbed from an elf core file.  */
struct core_elf_obj_tdata
{
  int signal;
  int pid;
  int lwpid;
  char* program;
  char* command;
};

/* Extra tdata information held for output ELF BFDs.  */
struct output_elf_obj_tdata
{
  struct elf_segment_map *seg_map;
  struct elf_strtab_hash *strtab_ptr;

  /* STT_SECTION symbols for each section */
  asymbol **section_syms;

  /* NT_GNU_BUILD_ID note type info.  */
  struct
  {
    bool (*after_write_object_contents) (bfd *);
    const char *style;
    asection *sec;
  } build_id;

  /* FDO_PACKAGING_METADATA note type info.  */
  struct
  {
    bool (*after_write_object_contents) (bfd *);
    const char *json;
    asection *sec;
  } package_metadata;

  /* Records the result of `get_program_header_size'.  */
  size_t program_header_size;

  /* Used when laying out sections.  */
  file_ptr next_file_pos;

  /* Linker information.  */
  struct bfd_link_info *link_info;

  unsigned int num_section_syms;
  unsigned int shstrtab_section, strtab_section;

  /* Segment flags for the PT_GNU_STACK segment.  */
  unsigned int stack_flags;

  /* Used to determine if PT_GNU_SFRAME segment header should be
     created.  */
  asection *sframe;

  /* Used to determine if the e_flags field has been initialized */
  bool flags_init;
};

/* Indicate if the bfd contains SHF_GNU_MBIND/SHF_GNU_RETAIN sections or
   symbols that have the STT_GNU_IFUNC symbol type or STB_GNU_UNIQUE
   binding.  Used to set the osabi field in the ELF header structure.  */
enum elf_gnu_osabi
{
  elf_gnu_osabi_mbind = 1 << 0,
  elf_gnu_osabi_ifunc = 1 << 1,
  elf_gnu_osabi_unique = 1 << 2,
  elf_gnu_osabi_retain = 1 << 3,
};

typedef struct elf_section_list
{
  Elf_Internal_Shdr	     hdr;
  unsigned int		     ndx;
  struct elf_section_list *  next;
} elf_section_list;

enum dynamic_lib_link_class {
  DYN_NORMAL = 0,
  DYN_AS_NEEDED = 1,
  DYN_DT_NEEDED = 2,
  DYN_NO_ADD_NEEDED = 4,
  DYN_NO_NEEDED = 8
};

/* Some private data is stashed away for future use using the tdata pointer
   in the bfd structure.  */

struct elf_obj_tdata
{
  Elf_Internal_Ehdr elf_header[1];	/* Actual data, but ref like ptr */
  Elf_Internal_Shdr **elf_sect_ptr;
  Elf_Internal_Phdr *phdr;
  Elf_Internal_Shdr symtab_hdr;
  Elf_Internal_Shdr shstrtab_hdr;
  Elf_Internal_Shdr strtab_hdr;
  Elf_Internal_Shdr dynsymtab_hdr;
  Elf_Internal_Shdr dynstrtab_hdr;
  Elf_Internal_Shdr dynversym_hdr;
  Elf_Internal_Shdr dynverref_hdr;
  Elf_Internal_Shdr dynverdef_hdr;
  elf_section_list * symtab_shndx_list;
  bfd_vma gp;				/* The gp value */
  unsigned int gp_size;			/* The gp size */
  unsigned int num_elf_sections;	/* elf_sect_ptr size */
  unsigned char *being_created;

  /* A mapping from external symbols to entries in the linker hash
     table, used when linking.  This is indexed by the symbol index
     minus the sh_info field of the symbol table header.  */
  struct elf_link_hash_entry **sym_hashes;

  /* Track usage and final offsets of GOT entries for local symbols.
     This array is indexed by symbol index.  Elements are used
     identically to "got" in struct elf_link_hash_entry.  */
  union
    {
      bfd_signed_vma *refcounts;
      bfd_vma *offsets;
      struct got_entry **ents;
    } local_got;

  /* The linker ELF emulation code needs to let the backend ELF linker
     know what filename should be used for a dynamic object if the
     dynamic object is found using a search.  The emulation code then
     sometimes needs to know what name was actually used.  Until the
     file has been added to the linker symbol table, this field holds
     the name the linker wants.  After it has been added, it holds the
     name actually used, which will be the DT_SONAME entry if there is
     one.  */
  const char *dt_name;

  /* The linker emulation needs to know what audit libs
     are used by a dynamic object.  */
  const char *dt_audit;

  /* Used by find_nearest_line entry point.  */
  void *line_info;

  /* A place to stash dwarf1 info for this bfd.  */
  void *dwarf1_find_line_info;

  /* A place to stash dwarf2 info for this bfd.  */
  void *dwarf2_find_line_info;

  /* Stash away info for yet another find line/function variant.  */
  void *elf_find_function_cache;

  /* Number of symbol version definitions we are about to emit.  */
  unsigned int cverdefs;

  /* Number of symbol version references we are about to emit.  */
  unsigned int cverrefs;

  /* Symbol version definitions in external objects.  */
  Elf_Internal_Verdef *verdef;

  /* Symbol version references to external objects.  */
  Elf_Internal_Verneed *verref;

  /* A pointer to the .eh_frame section.  */
  asection *eh_frame_section;

  /* Symbol buffer.  */
  void *symbuf;

  /* List of GNU properties.  Will be updated by setup_gnu_properties
     after all input GNU properties are merged for output.  */
  elf_property_list *properties;

  obj_attribute known_obj_attributes[2][NUM_KNOWN_OBJ_ATTRIBUTES];
  obj_attribute_list *other_obj_attributes[2];

  /* Linked-list containing information about every Systemtap section
     found in the object file.  Each section corresponds to one entry
     in the list.  */
  struct sdt_note *sdt_note_head;

  Elf_Internal_Shdr **group_sect_ptr;
  unsigned int num_group;

  /* Index into group_sect_ptr, updated by setup_group when finding a
     section's group.  Used to optimize subsequent group searches.  */
  unsigned int group_search_offset;

  unsigned int symtab_section, dynsymtab_section;
  unsigned int dynversym_section, dynverdef_section, dynverref_section;

  /* An identifier used to distinguish different target
     specific extensions to this structure.  */
  ENUM_BITFIELD (elf_target_id) object_id : 6;

  /* Whether a dyanmic object was specified normally on the linker
     command line, or was specified when --as-needed was in effect,
     or was found via a DT_NEEDED entry.  */
  ENUM_BITFIELD (dynamic_lib_link_class) dyn_lib_class : 4;

  /* Whether the bfd uses OS specific bits that require ELFOSABI_GNU.  */
  ENUM_BITFIELD (elf_gnu_osabi) has_gnu_osabi : 4;

  /* Whether if the bfd contains the GNU_PROPERTY_NO_COPY_ON_PROTECTED
     property.  */
  unsigned int has_no_copy_on_protected : 1;

  /* Whether if the bfd contains the
     GNU_PROPERTY_1_NEEDED_INDIRECT_EXTERN_ACCESS property.  */
  unsigned int has_indirect_extern_access : 1;

  /* Irix 5 often screws up the symbol table, sorting local symbols
     after global symbols.  This flag is set if the symbol table in
     this BFD appears to be screwed up.  If it is, we ignore the
     sh_info field in the symbol table header, and always read all the
     symbols.  */
  unsigned int bad_symtab : 1;

  /* Set if DT_FLAGS_1 has DF_1_PIE set.  */
  unsigned int is_pie : 1;

  /* Information grabbed from an elf core file.  */
  struct core_elf_obj_tdata *core;

  /* More information held for output ELF BFDs.  */
  struct output_elf_obj_tdata *o;
};

#define elf_tdata(bfd)		((bfd) -> tdata.elf_obj_data)

#define elf_object_id(bfd)	(elf_tdata(bfd) -> object_id)
#define elf_program_header_size(bfd) (elf_tdata(bfd) -> o->program_header_size)
#define elf_elfheader(bfd)	(elf_tdata(bfd) -> elf_header)
#define elf_elfsections(bfd)	(elf_tdata(bfd) -> elf_sect_ptr)
#define elf_numsections(bfd)	(elf_tdata(bfd) -> num_elf_sections)
#define elf_seg_map(bfd)	(elf_tdata(bfd) -> o->seg_map)
#define elf_link_info(bfd)	(elf_tdata(bfd) -> o->link_info)
#define elf_next_file_pos(bfd)	(elf_tdata(bfd) -> o->next_file_pos)
#define elf_stack_flags(bfd)	(elf_tdata(bfd) -> o->stack_flags)
#define elf_sframe(bfd)		(elf_tdata(bfd) -> o->sframe)
#define elf_shstrtab(bfd)	(elf_tdata(bfd) -> o->strtab_ptr)
#define elf_onesymtab(bfd)	(elf_tdata(bfd) -> symtab_section)
#define elf_symtab_shndx_list(bfd)	(elf_tdata(bfd) -> symtab_shndx_list)
#define elf_strtab_sec(bfd)	(elf_tdata(bfd) -> o->strtab_section)
#define elf_shstrtab_sec(bfd)	(elf_tdata(bfd) -> o->shstrtab_section)
#define elf_symtab_hdr(bfd)	(elf_tdata(bfd) -> symtab_hdr)
#define elf_dynsymtab(bfd)	(elf_tdata(bfd) -> dynsymtab_section)
#define elf_dynversym(bfd)	(elf_tdata(bfd) -> dynversym_section)
#define elf_dynverdef(bfd)	(elf_tdata(bfd) -> dynverdef_section)
#define elf_dynverref(bfd)	(elf_tdata(bfd) -> dynverref_section)
#define elf_eh_frame_section(bfd)  (elf_tdata(bfd) -> eh_frame_section)
#define elf_section_syms(bfd)	(elf_tdata(bfd) -> o->section_syms)
#define elf_num_section_syms(bfd) (elf_tdata(bfd) -> o->num_section_syms)
#define core_prpsinfo(bfd)	(elf_tdata(bfd) -> prpsinfo)
#define core_prstatus(bfd)	(elf_tdata(bfd) -> prstatus)
#define elf_gp(bfd)		(elf_tdata(bfd) -> gp)
#define elf_gp_size(bfd)	(elf_tdata(bfd) -> gp_size)
#define elf_sym_hashes(bfd)	(elf_tdata(bfd) -> sym_hashes)
#define elf_local_got_refcounts(bfd) (elf_tdata(bfd) -> local_got.refcounts)
#define elf_local_got_offsets(bfd) (elf_tdata(bfd) -> local_got.offsets)
#define elf_local_got_ents(bfd) (elf_tdata(bfd) -> local_got.ents)
#define elf_dt_name(bfd)	(elf_tdata(bfd) -> dt_name)
#define elf_dt_audit(bfd)	(elf_tdata(bfd) -> dt_audit)
#define elf_dyn_lib_class(bfd)	(elf_tdata(bfd) -> dyn_lib_class)
#define elf_bad_symtab(bfd)	(elf_tdata(bfd) -> bad_symtab)
#define elf_flags_init(bfd)	(elf_tdata(bfd) -> o->flags_init)
#define elf_known_obj_attributes(bfd) (elf_tdata (bfd) -> known_obj_attributes)
#define elf_other_obj_attributes(bfd) (elf_tdata (bfd) -> other_obj_attributes)
#define elf_known_obj_attributes_proc(bfd) \
  (elf_known_obj_attributes (bfd) [OBJ_ATTR_PROC])
#define elf_other_obj_attributes_proc(bfd) \
  (elf_other_obj_attributes (bfd) [OBJ_ATTR_PROC])
#define elf_properties(bfd) (elf_tdata (bfd) -> properties)
#define elf_has_no_copy_on_protected(bfd) \
  (elf_tdata(bfd) -> has_no_copy_on_protected)
#define elf_has_indirect_extern_access(bfd) \
  (elf_tdata(bfd) -> has_indirect_extern_access)

static unsigned int _bfd_elf_section_from_bfd_section
  (bfd *, asection *);
static bfd_reloc_status_type bfd_elf_generic_reloc (bfd *, arelent *, asymbol *, void *, asection *, bfd *, char **);
static bool bfd_elf_allocate_object (bfd *, size_t, enum elf_target_id);
#define _bfd_generic_init_private_section_data \
  _bfd_elf_init_private_section_data
#define _bfd_elf_read_minisymbols _bfd_generic_read_minisymbols
#define _bfd_elf_minisymbol_to_symbol _bfd_generic_minisymbol_to_symbol
/* If the target doesn't have reloc handling written yet:  */
static int _bfd_elf_symbol_from_bfd_symbol (bfd *, asymbol **);
static struct elf_strtab_hash * _bfd_elf_strtab_init (void);
static void _bfd_elf_strtab_free (struct elf_strtab_hash *);
static void _bfd_elf_strtab_clear_all_refs (struct elf_strtab_hash *);
static size_t _bfd_elf_strtab_offset (struct elf_strtab_hash *, size_t);
static void _bfd_elf_strtab_finalize (struct elf_strtab_hash *);

static void bfd_elf64_swap_reloca_out (bfd *, const Elf_Internal_Rela *, bfd_byte *);
static void bfd_elf_set_obj_attr_contents (bfd *, bfd_byte *, bfd_vma);
static void bfd_elf_add_obj_attr_int (bfd *, int, unsigned int, unsigned int);
#define bfd_elf_add_proc_attr_int(BFD, TAG, VALUE) \
  bfd_elf_add_obj_attr_int ((BFD), OBJ_ATTR_PROC, (TAG), (VALUE))
static void bfd_elf_add_obj_attr_string (bfd *, int, unsigned int, const char *,const char *);
#define bfd_elf_add_proc_attr_string(BFD, TAG, VALUE) \
  bfd_elf_add_obj_attr_string ((BFD), OBJ_ATTR_PROC, (TAG), (VALUE),NULL)
static void bfd_elf_add_obj_attr_int_string (bfd *, int, unsigned int,
					     unsigned int, const char *);
#define bfd_elf_add_proc_attr_int_string(BFD, TAG, INTVAL, STRVAL) \
  bfd_elf_add_obj_attr_int_string ((BFD), OBJ_ATTR_PROC, (TAG), \
				   (INTVAL), (STRVAL))
static int _bfd_elf_obj_attrs_arg_type (bfd *, int, unsigned int);
/* Hash for local symbol with the first section id, ID, in the input
   file and the local symbol index, SYM.  */
#define ELF_LOCAL_SYMBOL_HASH(ID, SYM) \
  (((((ID) & 0xffU) << 24) | (((ID) & 0xff00) << 8)) \
   ^ (SYM) ^ (((ID) & 0xffff0000U) >> 16))

/* Will a symbol be bound to the definition within the shared
   library, if any.  A unique symbol can never be bound locally.  */
#define SYMBOLIC_BIND(INFO, H) \
    (!(H)->unique_global \
     && ((INFO)->symbolic \
	 || (H)->start_stop \
	 || ((INFO)->dynamic && !(H)->dynamic)))

/* Determine if a section contains CTF data, using its name.  */
static inline bool bfd_section_is_ctf (const asection *sec)
{
  const char *name = bfd_section_name (sec);
  return startswith (name, ".ctf") && (name[4] == 0 || name[4] == '.');
}

enum linkonce_type {
  LINKONCE_UNSET = 0, LINKONCE_DISCARD, LINKONCE_ONE_ONLY,
  LINKONCE_SAME_SIZE, LINKONCE_SAME_CONTENTS
};
#endif /* _LIBELF_H_ */
/* tc-riscv.h -- header file for tc-riscv.c. */
/* ================================================================== tc-riscv.h */
#ifndef TC_RISCV
#define TC_RISCV

//----------------------------------------------------include "opcode/riscv.h"
/* riscv.h.  RISC-V opcode list for GDB, the GNU debugger. */
#ifndef _RISCV_H_
#define _RISCV_H_

//----------------------------------------------------include "riscv-opc.h"
/* riscv-opc.h.  RISC-V instruction opcode and CSR macros. */
#ifndef RISCV_ENCODING_H
#define RISCV_ENCODING_H
/* Instruction opcode macros.  */
#define MATCH_SLLI_RV32 0x1013
#define MASK_SLLI_RV32  0xfe00707f
#define MATCH_SRLI_RV32 0x5013
#define MASK_SRLI_RV32  0xfe00707f
#define MATCH_SRAI_RV32 0x40005013
#define MASK_SRAI_RV32  0xfe00707f
#define MATCH_FRFLAGS 0x102073
#define MASK_FRFLAGS  0xfffff07f
#define MATCH_FSFLAGS 0x101073
#define MASK_FSFLAGS  0xfff0707f
#define MATCH_FSFLAGSI 0x105073
#define MASK_FSFLAGSI  0xfff0707f
#define MATCH_FRRM 0x202073
#define MASK_FRRM  0xfffff07f
#define MATCH_FSRM 0x201073
#define MASK_FSRM  0xfff0707f
#define MATCH_FSRMI 0x205073
#define MASK_FSRMI  0xfff0707f
#define MATCH_FSCSR 0x301073
#define MASK_FSCSR  0xfff0707f
#define MATCH_FRCSR 0x302073
#define MASK_FRCSR  0xfffff07f
#define MATCH_RDCYCLE 0xc0002073
#define MASK_RDCYCLE  0xfffff07f
#define MATCH_RDTIME 0xc0102073
#define MASK_RDTIME  0xfffff07f
#define MATCH_RDINSTRET 0xc0202073
#define MASK_RDINSTRET  0xfffff07f
#define MATCH_RDCYCLEH 0xc8002073
#define MASK_RDCYCLEH  0xfffff07f
#define MATCH_RDTIMEH 0xc8102073
#define MASK_RDTIMEH  0xfffff07f
#define MATCH_RDINSTRETH 0xc8202073
#define MASK_RDINSTRETH  0xfffff07f
#define MATCH_SCALL 0x73
#define MASK_SCALL  0xffffffff
#define MATCH_SBREAK 0x100073
#define MASK_SBREAK  0xffffffff
#define MATCH_BEQ 0x63
#define MASK_BEQ  0x707f
#define MATCH_BNE 0x1063
#define MASK_BNE  0x707f
#define MATCH_BLT 0x4063
#define MASK_BLT  0x707f
#define MATCH_BGE 0x5063
#define MASK_BGE  0x707f
#define MATCH_BLTU 0x6063
#define MASK_BLTU  0x707f
#define MATCH_BGEU 0x7063
#define MASK_BGEU  0x707f
#define MATCH_JALR 0x67
#define MASK_JALR  0x707f
#define MATCH_JAL 0x6f
#define MASK_JAL  0x7f
#define MATCH_LUI 0x37
#define MASK_LUI  0x7f
#define MATCH_AUIPC 0x17
#define MASK_AUIPC  0x7f
#define MATCH_ADDI 0x13
#define MASK_ADDI  0x707f
#define MATCH_SLLI 0x1013
#define MASK_SLLI  0xfc00707f
#define MATCH_SLTI 0x2013
#define MASK_SLTI  0x707f
#define MATCH_SLTIU 0x3013
#define MASK_SLTIU  0x707f
#define MATCH_XORI 0x4013
#define MASK_XORI  0x707f
#define MATCH_SRLI 0x5013
#define MASK_SRLI  0xfc00707f
#define MATCH_SRAI 0x40005013
#define MASK_SRAI  0xfc00707f
#define MATCH_ORI 0x6013
#define MASK_ORI  0x707f
#define MATCH_ANDI 0x7013
#define MASK_ANDI  0x707f
#define MATCH_ADD 0x33
#define MASK_ADD  0xfe00707f
#define MATCH_SUB 0x40000033
#define MASK_SUB  0xfe00707f
#define MATCH_SLL 0x1033
#define MASK_SLL  0xfe00707f
#define MATCH_SLT 0x2033
#define MASK_SLT  0xfe00707f
#define MATCH_SLTU 0x3033
#define MASK_SLTU  0xfe00707f
#define MATCH_XOR 0x4033
#define MASK_XOR  0xfe00707f
#define MATCH_SRL 0x5033
#define MASK_SRL  0xfe00707f
#define MATCH_SRA 0x40005033
#define MASK_SRA  0xfe00707f
#define MATCH_OR 0x6033
#define MASK_OR  0xfe00707f
#define MATCH_AND 0x7033
#define MASK_AND  0xfe00707f
#define MATCH_ADDIW 0x1b
#define MASK_ADDIW  0x707f
#define MATCH_SLLIW 0x101b
#define MASK_SLLIW  0xfe00707f
#define MATCH_SRLIW 0x501b
#define MASK_SRLIW  0xfe00707f
#define MATCH_SRAIW 0x4000501b
#define MASK_SRAIW  0xfe00707f
#define MATCH_ADDW 0x3b
#define MASK_ADDW  0xfe00707f
#define MATCH_SUBW 0x4000003b
#define MASK_SUBW  0xfe00707f
#define MATCH_SLLW 0x103b
#define MASK_SLLW  0xfe00707f
#define MATCH_SRLW 0x503b
#define MASK_SRLW  0xfe00707f
#define MATCH_SRAW 0x4000503b
#define MASK_SRAW  0xfe00707f
#define MATCH_LB 0x3
#define MASK_LB  0x707f
#define MATCH_LH 0x1003
#define MASK_LH  0x707f
#define MATCH_LW 0x2003
#define MASK_LW  0x707f
#define MATCH_LD 0x3003
#define MASK_LD  0x707f
#define MATCH_LBU 0x4003
#define MASK_LBU  0x707f
#define MATCH_LHU 0x5003
#define MASK_LHU  0x707f
#define MATCH_LWU 0x6003
#define MASK_LWU  0x707f
#define MATCH_SB 0x23
#define MASK_SB  0x707f
#define MATCH_SH 0x1023
#define MASK_SH  0x707f
#define MATCH_SW 0x2023
#define MASK_SW  0x707f
#define MATCH_SD 0x3023
#define MASK_SD  0x707f
#define MATCH_PAUSE 0x0100000f
#define MASK_PAUSE  0xffffffff
#define MATCH_FENCE 0xf
#define MASK_FENCE  0x707f
#define MATCH_FENCE_I 0x100f
#define MASK_FENCE_I  0x707f
#define MATCH_FENCE_TSO 0x8330000f
#define MASK_FENCE_TSO  0xfff0707f
#define MATCH_MUL 0x2000033
#define MASK_MUL  0xfe00707f
#define MATCH_MULH 0x2001033
#define MASK_MULH  0xfe00707f
#define MATCH_MULHSU 0x2002033
#define MASK_MULHSU  0xfe00707f
#define MATCH_MULHU 0x2003033
#define MASK_MULHU  0xfe00707f
#define MATCH_DIV 0x2004033
#define MASK_DIV  0xfe00707f
#define MATCH_DIVU 0x2005033
#define MASK_DIVU  0xfe00707f
#define MATCH_REM 0x2006033
#define MASK_REM  0xfe00707f
#define MATCH_REMU 0x2007033
#define MASK_REMU  0xfe00707f
#define MATCH_MULW 0x200003b
#define MASK_MULW  0xfe00707f
#define MATCH_DIVW 0x200403b
#define MASK_DIVW  0xfe00707f
#define MATCH_DIVUW 0x200503b
#define MASK_DIVUW  0xfe00707f
#define MATCH_REMW 0x200603b
#define MASK_REMW  0xfe00707f
#define MATCH_REMUW 0x200703b
#define MASK_REMUW  0xfe00707f
#define MATCH_AMOADD_W 0x202f
#define MASK_AMOADD_W  0xf800707f
#define MATCH_AMOXOR_W 0x2000202f
#define MASK_AMOXOR_W  0xf800707f
#define MATCH_AMOOR_W 0x4000202f
#define MASK_AMOOR_W  0xf800707f
#define MATCH_AMOAND_W 0x6000202f
#define MASK_AMOAND_W  0xf800707f
#define MATCH_AMOMIN_W 0x8000202f
#define MASK_AMOMIN_W  0xf800707f
#define MATCH_AMOMAX_W 0xa000202f
#define MASK_AMOMAX_W  0xf800707f
#define MATCH_AMOMINU_W 0xc000202f
#define MASK_AMOMINU_W  0xf800707f
#define MATCH_AMOMAXU_W 0xe000202f
#define MASK_AMOMAXU_W  0xf800707f
#define MATCH_AMOSWAP_W 0x800202f
#define MASK_AMOSWAP_W  0xf800707f
#define MATCH_LR_W 0x1000202f
#define MASK_LR_W  0xf9f0707f
#define MATCH_SC_W 0x1800202f
#define MASK_SC_W  0xf800707f
#define MATCH_AMOADD_D 0x302f
#define MASK_AMOADD_D  0xf800707f
#define MATCH_AMOXOR_D 0x2000302f
#define MASK_AMOXOR_D  0xf800707f
#define MATCH_AMOOR_D 0x4000302f
#define MASK_AMOOR_D  0xf800707f
#define MATCH_AMOAND_D 0x6000302f
#define MASK_AMOAND_D  0xf800707f
#define MATCH_AMOMIN_D 0x8000302f
#define MASK_AMOMIN_D  0xf800707f
#define MATCH_AMOMAX_D 0xa000302f
#define MASK_AMOMAX_D  0xf800707f
#define MATCH_AMOMINU_D 0xc000302f
#define MASK_AMOMINU_D  0xf800707f
#define MATCH_AMOMAXU_D 0xe000302f
#define MASK_AMOMAXU_D  0xf800707f
#define MATCH_AMOSWAP_D 0x800302f
#define MASK_AMOSWAP_D  0xf800707f
#define MATCH_LR_D 0x1000302f
#define MASK_LR_D  0xf9f0707f
#define MATCH_SC_D 0x1800302f
#define MASK_SC_D  0xf800707f
#define MATCH_ECALL 0x73
#define MASK_ECALL  0xffffffff
#define MATCH_EBREAK 0x100073
#define MASK_EBREAK  0xffffffff
#define MATCH_URET 0x200073
#define MASK_URET  0xffffffff
#define MATCH_SRET 0x10200073
#define MASK_SRET  0xffffffff
#define MATCH_HRET 0x20200073
#define MASK_HRET  0xffffffff
#define MATCH_MRET 0x30200073
#define MASK_MRET  0xffffffff
#define MATCH_DRET 0x7b200073
#define MASK_DRET  0xffffffff
#define MATCH_SFENCE_VM 0x10400073
#define MASK_SFENCE_VM  0xfff07fff
#define MATCH_SFENCE_VMA 0x12000073
#define MASK_SFENCE_VMA  0xfe007fff
#define MATCH_WFI 0x10500073
#define MASK_WFI  0xffffffff
#define MATCH_CSRRW 0x1073
#define MASK_CSRRW  0x707f
#define MATCH_CSRRS 0x2073
#define MASK_CSRRS  0x707f
#define MATCH_CSRRC 0x3073
#define MASK_CSRRC  0x707f
#define MATCH_CSRRWI 0x5073
#define MASK_CSRRWI  0x707f
#define MATCH_CSRRSI 0x6073
#define MASK_CSRRSI  0x707f
#define MATCH_CSRRCI 0x7073
#define MASK_CSRRCI  0x707f
#define MATCH_FADD_S 0x53
#define MASK_FADD_S  0xfe00007f
#define MATCH_FSUB_S 0x8000053
#define MASK_FSUB_S  0xfe00007f
#define MATCH_FMUL_S 0x10000053
#define MASK_FMUL_S  0xfe00007f
#define MATCH_FDIV_S 0x18000053
#define MASK_FDIV_S  0xfe00007f
#define MATCH_FSGNJ_S 0x20000053
#define MASK_FSGNJ_S  0xfe00707f
#define MATCH_FSGNJN_S 0x20001053
#define MASK_FSGNJN_S  0xfe00707f
#define MATCH_FSGNJX_S 0x20002053
#define MASK_FSGNJX_S  0xfe00707f
#define MATCH_FMIN_S 0x28000053
#define MASK_FMIN_S  0xfe00707f
#define MATCH_FMAX_S 0x28001053
#define MASK_FMAX_S  0xfe00707f
#define MATCH_FSQRT_S 0x58000053
#define MASK_FSQRT_S  0xfff0007f
#define MATCH_FADD_D 0x2000053
#define MASK_FADD_D  0xfe00007f
#define MATCH_FSUB_D 0xa000053
#define MASK_FSUB_D  0xfe00007f
#define MATCH_FMUL_D 0x12000053
#define MASK_FMUL_D  0xfe00007f
#define MATCH_FDIV_D 0x1a000053
#define MASK_FDIV_D  0xfe00007f
#define MATCH_FSGNJ_D 0x22000053
#define MASK_FSGNJ_D  0xfe00707f
#define MATCH_FSGNJN_D 0x22001053
#define MASK_FSGNJN_D  0xfe00707f
#define MATCH_FSGNJX_D 0x22002053
#define MASK_FSGNJX_D  0xfe00707f
#define MATCH_FMIN_D 0x2a000053
#define MASK_FMIN_D  0xfe00707f
#define MATCH_FMAX_D 0x2a001053
#define MASK_FMAX_D  0xfe00707f
#define MATCH_FCVT_S_D 0x40100053
#define MASK_FCVT_S_D  0xfff0007f
#define MATCH_FCVT_D_S 0x42000053
#define MASK_FCVT_D_S  0xfff0007f
#define MATCH_FSQRT_D 0x5a000053
#define MASK_FSQRT_D  0xfff0007f
#define MATCH_FADD_Q 0x6000053
#define MASK_FADD_Q  0xfe00007f
#define MATCH_FSUB_Q 0xe000053
#define MASK_FSUB_Q  0xfe00007f
#define MATCH_FMUL_Q 0x16000053
#define MASK_FMUL_Q  0xfe00007f
#define MATCH_FDIV_Q 0x1e000053
#define MASK_FDIV_Q  0xfe00007f
#define MATCH_FSGNJ_Q 0x26000053
#define MASK_FSGNJ_Q  0xfe00707f
#define MATCH_FSGNJN_Q 0x26001053
#define MASK_FSGNJN_Q  0xfe00707f
#define MATCH_FSGNJX_Q 0x26002053
#define MASK_FSGNJX_Q  0xfe00707f
#define MATCH_FMIN_Q 0x2e000053
#define MASK_FMIN_Q  0xfe00707f
#define MATCH_FMAX_Q 0x2e001053
#define MASK_FMAX_Q  0xfe00707f
#define MATCH_FCVT_S_Q 0x40300053
#define MASK_FCVT_S_Q  0xfff0007f
#define MATCH_FCVT_Q_S 0x46000053
#define MASK_FCVT_Q_S  0xfff0007f
#define MATCH_FCVT_D_Q 0x42300053
#define MASK_FCVT_D_Q  0xfff0007f
#define MATCH_FCVT_Q_D 0x46100053
#define MASK_FCVT_Q_D  0xfff0007f
#define MATCH_FSQRT_Q 0x5e000053
#define MASK_FSQRT_Q  0xfff0007f
#define MATCH_FLE_S 0xa0000053
#define MASK_FLE_S  0xfe00707f
#define MATCH_FLT_S 0xa0001053
#define MASK_FLT_S  0xfe00707f
#define MATCH_FEQ_S 0xa0002053
#define MASK_FEQ_S  0xfe00707f
#define MATCH_FLE_D 0xa2000053
#define MASK_FLE_D  0xfe00707f
#define MATCH_FLT_D 0xa2001053
#define MASK_FLT_D  0xfe00707f
#define MATCH_FEQ_D 0xa2002053
#define MASK_FEQ_D  0xfe00707f
#define MATCH_FLE_Q 0xa6000053
#define MASK_FLE_Q  0xfe00707f
#define MATCH_FLT_Q 0xa6001053
#define MASK_FLT_Q  0xfe00707f
#define MATCH_FEQ_Q 0xa6002053
#define MASK_FEQ_Q  0xfe00707f
#define MATCH_FCVT_W_S 0xc0000053
#define MASK_FCVT_W_S  0xfff0007f
#define MATCH_FCVT_WU_S 0xc0100053
#define MASK_FCVT_WU_S  0xfff0007f
#define MATCH_FCVT_L_S 0xc0200053
#define MASK_FCVT_L_S  0xfff0007f
#define MATCH_FCVT_LU_S 0xc0300053
#define MASK_FCVT_LU_S  0xfff0007f
#define MATCH_FMV_X_S 0xe0000053
#define MASK_FMV_X_S  0xfff0707f
#define MATCH_FCLASS_S 0xe0001053
#define MASK_FCLASS_S  0xfff0707f
#define MATCH_FCVT_W_D 0xc2000053
#define MASK_FCVT_W_D  0xfff0007f
#define MATCH_FCVT_WU_D 0xc2100053
#define MASK_FCVT_WU_D  0xfff0007f
#define MATCH_FCVT_L_D 0xc2200053
#define MASK_FCVT_L_D  0xfff0007f
#define MATCH_FCVT_LU_D 0xc2300053
#define MASK_FCVT_LU_D  0xfff0007f
#define MATCH_FMV_X_D 0xe2000053
#define MASK_FMV_X_D  0xfff0707f
#define MATCH_FCLASS_D 0xe2001053
#define MASK_FCLASS_D  0xfff0707f
#define MATCH_FCVT_W_Q 0xc6000053
#define MASK_FCVT_W_Q  0xfff0007f
#define MATCH_FCVT_WU_Q 0xc6100053
#define MASK_FCVT_WU_Q  0xfff0007f
#define MATCH_FCVT_L_Q 0xc6200053
#define MASK_FCVT_L_Q  0xfff0007f
#define MATCH_FCVT_LU_Q 0xc6300053
#define MASK_FCVT_LU_Q  0xfff0007f
#define MATCH_FCLASS_Q 0xe6001053
#define MASK_FCLASS_Q  0xfff0707f
#define MATCH_FCVT_S_W 0xd0000053
#define MASK_FCVT_S_W  0xfff0007f
#define MATCH_FCVT_S_WU 0xd0100053
#define MASK_FCVT_S_WU  0xfff0007f
#define MATCH_FCVT_S_L 0xd0200053
#define MASK_FCVT_S_L  0xfff0007f
#define MATCH_FCVT_S_LU 0xd0300053
#define MASK_FCVT_S_LU  0xfff0007f
#define MATCH_FMV_S_X 0xf0000053
#define MASK_FMV_S_X  0xfff0707f
#define MATCH_FCVT_D_W 0xd2000053
#define MASK_FCVT_D_W  0xfff0007f
#define MATCH_FCVT_D_WU 0xd2100053
#define MASK_FCVT_D_WU  0xfff0007f
#define MATCH_FCVT_D_L 0xd2200053
#define MASK_FCVT_D_L  0xfff0007f
#define MATCH_FCVT_D_LU 0xd2300053
#define MASK_FCVT_D_LU  0xfff0007f
#define MATCH_FMV_D_X 0xf2000053
#define MASK_FMV_D_X  0xfff0707f
#define MATCH_FCVT_Q_W 0xd6000053
#define MASK_FCVT_Q_W  0xfff0007f
#define MATCH_FCVT_Q_WU 0xd6100053
#define MASK_FCVT_Q_WU  0xfff0007f
#define MATCH_FCVT_Q_L 0xd6200053
#define MASK_FCVT_Q_L  0xfff0007f
#define MATCH_FCVT_Q_LU 0xd6300053
#define MASK_FCVT_Q_LU  0xfff0007f
#define MATCH_CLZ 0x60001013
#define MASK_CLZ  0xfff0707f
#define MATCH_CTZ 0x60101013
#define MASK_CTZ  0xfff0707f
#define MATCH_CPOP 0x60201013
#define MASK_CPOP  0xfff0707f
#define MATCH_MIN 0xa004033
#define MASK_MIN  0xfe00707f
#define MATCH_MINU 0xa005033
#define MASK_MINU  0xfe00707f
#define MATCH_MAX 0xa006033
#define MASK_MAX  0xfe00707f
#define MATCH_MAXU 0xa007033
#define MASK_MAXU  0xfe00707f
#define MATCH_SEXT_B 0x60401013
#define MASK_SEXT_B  0xfff0707f
#define MATCH_SEXT_H 0x60501013
#define MASK_SEXT_H  0xfff0707f
#define MATCH_PACK 0x8004033
#define MASK_PACK  0xfe00707f
#define MATCH_PACKH 0x8007033
#define MASK_PACKH  0xfe00707f
#define MATCH_PACKW 0x800403b
#define MASK_PACKW  0xfe00707f
#define MATCH_ANDN 0x40007033
#define MASK_ANDN  0xfe00707f
#define MATCH_ORN 0x40006033
#define MASK_ORN  0xfe00707f
#define MATCH_XNOR 0x40004033
#define MASK_XNOR  0xfe00707f
#define MATCH_ROL 0x60001033
#define MASK_ROL  0xfe00707f
#define MATCH_ROR 0x60005033
#define MASK_ROR  0xfe00707f
#define MATCH_RORI 0x60005013
#define MASK_RORI  0xfc00707f
#define MATCH_GREVI 0x68005013
#define MASK_GREVI  0xfc00707f
#define MATCH_GORCI 0x28005013
#define MASK_GORCI  0xfc00707f
#define MATCH_SHFLI 0x8001013
#define MASK_SHFLI  0xfe00707f
#define MATCH_UNSHFLI 0x8005013
#define MASK_UNSHFLI  0xfe00707f
#define MATCH_CLZW 0x6000101b
#define MASK_CLZW  0xfff0707f
#define MATCH_CTZW 0x6010101b
#define MASK_CTZW  0xfff0707f
#define MATCH_CPOPW 0x6020101b
#define MASK_CPOPW  0xfff0707f
#define MATCH_ROLW 0x6000103b
#define MASK_ROLW  0xfe00707f
#define MATCH_RORW 0x6000503b
#define MASK_RORW  0xfe00707f
#define MATCH_RORIW 0x6000501b
#define MASK_RORIW  0xfe00707f
#define MATCH_SH1ADD 0x20002033
#define MASK_SH1ADD  0xfe00707f
#define MATCH_SH2ADD 0x20004033
#define MASK_SH2ADD  0xfe00707f
#define MATCH_SH3ADD 0x20006033
#define MASK_SH3ADD  0xfe00707f
#define MATCH_SH1ADD_UW 0x2000203b
#define MASK_SH1ADD_UW  0xfe00707f
#define MATCH_SH2ADD_UW 0x2000403b
#define MASK_SH2ADD_UW  0xfe00707f
#define MATCH_SH3ADD_UW 0x2000603b
#define MASK_SH3ADD_UW  0xfe00707f
#define MATCH_ADD_UW 0x800003b
#define MASK_ADD_UW  0xfe00707f
#define MATCH_SLLI_UW 0x800101b
#define MASK_SLLI_UW  0xfc00707f
#define MATCH_CLMUL 0xa001033
#define MASK_CLMUL  0xfe00707f
#define MATCH_CLMULH 0xa003033
#define MASK_CLMULH  0xfe00707f
#define MATCH_CLMULR 0xa002033
#define MASK_CLMULR  0xfe00707f
#define MATCH_XPERM4 0x28002033
#define MASK_XPERM4  0xfe00707f
#define MATCH_XPERM8 0x28004033
#define MASK_XPERM8  0xfe00707f
#define MATCH_BCLRI 0x48001013
#define MASK_BCLRI  0xfc00707f
#define MATCH_BSETI 0x28001013
#define MASK_BSETI  0xfc00707f
#define MATCH_BINVI 0x68001013
#define MASK_BINVI  0xfc00707f
#define MATCH_BEXTI 0x48005013
#define MASK_BEXTI  0xfc00707f
#define MATCH_BCLR  0x48001033
#define MASK_BCLR   0xfe00707f
#define MATCH_BSET  0x28001033
#define MASK_BSET   0xfe00707f
#define MATCH_BINV  0x68001033
#define MASK_BINV   0xfe00707f
#define MATCH_BEXT  0x48005033
#define MASK_BEXT   0xfe00707f
#define MATCH_FLW 0x2007
#define MASK_FLW  0x707f
#define MATCH_FLD 0x3007
#define MASK_FLD  0x707f
#define MATCH_FLQ 0x4007
#define MASK_FLQ  0x707f
#define MATCH_FSW 0x2027
#define MASK_FSW  0x707f
#define MATCH_FSD 0x3027
#define MASK_FSD  0x707f
#define MATCH_FSQ 0x4027
#define MASK_FSQ  0x707f
#define MATCH_FMADD_S 0x43
#define MASK_FMADD_S  0x600007f
#define MATCH_FMSUB_S 0x47
#define MASK_FMSUB_S  0x600007f
#define MATCH_FNMSUB_S 0x4b
#define MASK_FNMSUB_S  0x600007f
#define MATCH_FNMADD_S 0x4f
#define MASK_FNMADD_S  0x600007f
#define MATCH_FMADD_D 0x2000043
#define MASK_FMADD_D  0x600007f
#define MATCH_FMSUB_D 0x2000047
#define MASK_FMSUB_D  0x600007f
#define MATCH_FNMSUB_D 0x200004b
#define MASK_FNMSUB_D  0x600007f
#define MATCH_FNMADD_D 0x200004f
#define MASK_FNMADD_D  0x600007f
#define MATCH_FMADD_Q 0x6000043
#define MASK_FMADD_Q  0x600007f
#define MATCH_FMSUB_Q 0x6000047
#define MASK_FMSUB_Q  0x600007f
#define MATCH_FNMSUB_Q 0x600004b
#define MASK_FNMSUB_Q  0x600007f
#define MATCH_FNMADD_Q 0x600004f
#define MASK_FNMADD_Q  0x600007f
#define MATCH_C_ADDI4SPN 0x0
#define MASK_C_ADDI4SPN  0xe003
#define MATCH_C_FLD 0x2000
#define MASK_C_FLD  0xe003
#define MATCH_C_LW 0x4000
#define MASK_C_LW  0xe003
#define MATCH_C_FLW 0x6000
#define MASK_C_FLW  0xe003
#define MATCH_C_FSD 0xa000
#define MASK_C_FSD  0xe003
#define MATCH_C_SW 0xc000
#define MASK_C_SW  0xe003
#define MATCH_C_FSW 0xe000
#define MASK_C_FSW  0xe003
#define MATCH_C_ADDI 0x1
#define MASK_C_ADDI  0xe003
#define MATCH_C_JAL 0x2001
#define MASK_C_JAL  0xe003
#define MATCH_C_LI 0x4001
#define MASK_C_LI  0xe003
#define MATCH_C_LUI 0x6001
#define MASK_C_LUI  0xe003
#define MATCH_C_SRLI 0x8001
#define MASK_C_SRLI  0xec03
#define MATCH_C_SRLI64 0x8001
#define MASK_C_SRLI64  0xfc7f
#define MATCH_C_SRAI 0x8401
#define MASK_C_SRAI  0xec03
#define MATCH_C_SRAI64 0x8401
#define MASK_C_SRAI64  0xfc7f
#define MATCH_C_ANDI 0x8801
#define MASK_C_ANDI  0xec03
#define MATCH_C_SUB 0x8c01
#define MASK_C_SUB  0xfc63
#define MATCH_C_XOR 0x8c21
#define MASK_C_XOR  0xfc63
#define MATCH_C_OR 0x8c41
#define MASK_C_OR  0xfc63
#define MATCH_C_AND 0x8c61
#define MASK_C_AND  0xfc63
#define MATCH_C_SUBW 0x9c01
#define MASK_C_SUBW  0xfc63
#define MATCH_C_ADDW 0x9c21
#define MASK_C_ADDW  0xfc63
#define MATCH_C_J 0xa001
#define MASK_C_J  0xe003
#define MATCH_C_BEQZ 0xc001
#define MASK_C_BEQZ  0xe003
#define MATCH_C_BNEZ 0xe001
#define MASK_C_BNEZ  0xe003
#define MATCH_C_SLLI 0x2
#define MASK_C_SLLI  0xe003
#define MATCH_C_SLLI64 0x2
#define MASK_C_SLLI64 0xf07f
#define MATCH_C_FLDSP 0x2002
#define MASK_C_FLDSP  0xe003
#define MATCH_C_LWSP 0x4002
#define MASK_C_LWSP  0xe003
#define MATCH_C_FLWSP 0x6002
#define MASK_C_FLWSP  0xe003
#define MATCH_C_MV 0x8002
#define MASK_C_MV  0xf003
#define MATCH_C_ADD 0x9002
#define MASK_C_ADD  0xf003
#define MATCH_C_FSDSP 0xa002
#define MASK_C_FSDSP  0xe003
#define MATCH_C_SWSP 0xc002
#define MASK_C_SWSP  0xe003
#define MATCH_C_FSWSP 0xe002
#define MASK_C_FSWSP  0xe003
#define MATCH_C_NOP 0x1
#define MASK_C_NOP  0xffff
#define MATCH_C_ADDI16SP 0x6101
#define MASK_C_ADDI16SP  0xef83
#define MATCH_C_JR 0x8002
#define MASK_C_JR  0xf07f
#define MATCH_C_JALR 0x9002
#define MASK_C_JALR  0xf07f
#define MATCH_C_EBREAK 0x9002
#define MASK_C_EBREAK  0xffff
#define MATCH_C_LD 0x6000
#define MASK_C_LD  0xe003
#define MATCH_C_SD 0xe000
#define MASK_C_SD  0xe003
#define MATCH_C_ADDIW 0x2001
#define MASK_C_ADDIW  0xe003
#define MATCH_C_LDSP 0x6002
#define MASK_C_LDSP  0xe003
#define MATCH_C_SDSP 0xe002
#define MASK_C_SDSP  0xe003
#define MATCH_SM3P0 0x10801013
#define MASK_SM3P0  0xfff0707f
#define MATCH_SM3P1 0x10901013
#define MASK_SM3P1  0xfff0707f
#define MATCH_SHA256SUM0 0x10001013
#define MASK_SHA256SUM0  0xfff0707f
#define MATCH_SHA256SUM1 0x10101013
#define MASK_SHA256SUM1  0xfff0707f
#define MATCH_SHA256SIG0 0x10201013
#define MASK_SHA256SIG0  0xfff0707f
#define MATCH_SHA256SIG1 0x10301013
#define MASK_SHA256SIG1  0xfff0707f
#define MATCH_SHA512SUM0R 0x50000033
#define MASK_SHA512SUM0R  0xfe00707f
#define MATCH_SHA512SUM1R 0x52000033
#define MASK_SHA512SUM1R  0xfe00707f
#define MATCH_SHA512SIG0L 0x54000033
#define MASK_SHA512SIG0L  0xfe00707f
#define MATCH_SHA512SIG0H 0x5c000033
#define MASK_SHA512SIG0H  0xfe00707f
#define MATCH_SHA512SIG1L 0x56000033
#define MASK_SHA512SIG1L  0xfe00707f
#define MATCH_SHA512SIG1H 0x5e000033
#define MASK_SHA512SIG1H  0xfe00707f
#define MATCH_SM4ED 0x30000033
#define MASK_SM4ED  0x3e00707f
#define MATCH_SM4KS 0x34000033
#define MASK_SM4KS  0x3e00707f
#define MATCH_AES32ESMI 0x26000033
#define MASK_AES32ESMI  0x3e00707f
#define MATCH_AES32ESI 0x22000033
#define MASK_AES32ESI  0x3e00707f
#define MATCH_AES32DSMI 0x2e000033
#define MASK_AES32DSMI  0x3e00707f
#define MATCH_AES32DSI 0x2a000033
#define MASK_AES32DSI  0x3e00707f
#define MATCH_SHA512SUM0 0x10401013
#define MASK_SHA512SUM0  0xfff0707f
#define MATCH_SHA512SUM1 0x10501013
#define MASK_SHA512SUM1  0xfff0707f
#define MATCH_SHA512SIG0 0x10601013
#define MASK_SHA512SIG0  0xfff0707f
#define MATCH_SHA512SIG1 0x10701013
#define MASK_SHA512SIG1  0xfff0707f
#define MATCH_AES64KS1I 0x31001013
#define MASK_AES64KS1I  0xff00707f
#define MATCH_AES64IM 0x30001013
#define MASK_AES64IM  0xfff0707f
#define MATCH_AES64KS2 0x7e000033
#define MASK_AES64KS2  0xfe00707f
#define MATCH_AES64ESM 0x36000033
#define MASK_AES64ESM  0xfe00707f
#define MATCH_AES64ES 0x32000033
#define MASK_AES64ES  0xfe00707f
#define MATCH_AES64DSM 0x3e000033
#define MASK_AES64DSM  0xfe00707f
#define MATCH_AES64DS 0x3a000033
#define MASK_AES64DS  0xfe00707f
#define MATCH_FADD_H 0x4000053
#define MASK_FADD_H 0xfe00007f
#define MATCH_FSUB_H 0xc000053
#define MASK_FSUB_H 0xfe00007f
#define MATCH_FMUL_H 0x14000053
#define MASK_FMUL_H 0xfe00007f
#define MATCH_FDIV_H 0x1c000053
#define MASK_FDIV_H 0xfe00007f
#define MATCH_FSGNJ_H 0x24000053
#define MASK_FSGNJ_H 0xfe00707f
#define MATCH_FSGNJN_H 0x24001053
#define MASK_FSGNJN_H 0xfe00707f
#define MATCH_FSGNJX_H 0x24002053
#define MASK_FSGNJX_H 0xfe00707f
#define MATCH_FMIN_H 0x2c000053
#define MASK_FMIN_H 0xfe00707f
#define MATCH_FMAX_H 0x2c001053
#define MASK_FMAX_H 0xfe00707f
#define MATCH_FCVT_H_S 0x44000053
#define MASK_FCVT_H_S 0xfff0007f
#define MATCH_FCVT_S_H 0x40200053
#define MASK_FCVT_S_H 0xfff0007f
#define MATCH_FSQRT_H 0x5c000053
#define MASK_FSQRT_H 0xfff0007f
#define MATCH_FLE_H 0xa4000053
#define MASK_FLE_H 0xfe00707f
#define MATCH_FLT_H 0xa4001053
#define MASK_FLT_H 0xfe00707f
#define MATCH_FEQ_H 0xa4002053
#define MASK_FEQ_H 0xfe00707f
#define MATCH_FCVT_W_H 0xc4000053
#define MASK_FCVT_W_H 0xfff0007f
#define MATCH_FCVT_WU_H 0xc4100053
#define MASK_FCVT_WU_H 0xfff0007f
#define MATCH_FMV_X_H 0xe4000053
#define MASK_FMV_X_H 0xfff0707f
#define MATCH_FCLASS_H 0xe4001053
#define MASK_FCLASS_H 0xfff0707f
#define MATCH_FCVT_H_W 0xd4000053
#define MASK_FCVT_H_W 0xfff0007f
#define MATCH_FCVT_H_WU 0xd4100053
#define MASK_FCVT_H_WU 0xfff0007f
#define MATCH_FMV_H_X 0xf4000053
#define MASK_FMV_H_X 0xfff0707f
#define MATCH_FLH 0x1007
#define MASK_FLH 0x707f
#define MATCH_FSH 0x1027
#define MASK_FSH 0x707f
#define MATCH_FMADD_H 0x4000043
#define MASK_FMADD_H 0x600007f
#define MATCH_FMSUB_H 0x4000047
#define MASK_FMSUB_H 0x600007f
#define MATCH_FNMSUB_H 0x400004b
#define MASK_FNMSUB_H 0x600007f
#define MATCH_FNMADD_H 0x400004f
#define MASK_FNMADD_H 0x600007f
#define MATCH_FCVT_H_D 0x44100053
#define MASK_FCVT_H_D 0xfff0007f
#define MATCH_FCVT_D_H 0x42200053
#define MASK_FCVT_D_H 0xfff0007f
#define MATCH_FCVT_H_Q 0x44300053
#define MASK_FCVT_H_Q 0xfff0007f
#define MATCH_FCVT_Q_H 0x46200053
#define MASK_FCVT_Q_H 0xfff0007f
#define MATCH_FCVT_L_H 0xc4200053
#define MASK_FCVT_L_H 0xfff0007f
#define MATCH_FCVT_LU_H 0xc4300053
#define MASK_FCVT_LU_H 0xfff0007f
#define MATCH_FCVT_H_L 0xd4200053
#define MASK_FCVT_H_L 0xfff0007f
#define MATCH_FCVT_H_LU 0xd4300053
#define MASK_FCVT_H_LU 0xfff0007f
#define MATCH_VSETVL  0x80007057
#define MASK_VSETVL  0xfe00707f
#define MATCH_VSETIVLI  0xc0007057
#define MASK_VSETIVLI  0xc000707f
#define MATCH_VSETVLI  0x00007057
#define MASK_VSETVLI  0x8000707f
#define MATCH_VLMV  0x02b00007
#define MASK_VLMV  0xfff0707f
#define MATCH_VSMV  0x02b00027
#define MASK_VSMV  0xfff0707f
#define MATCH_VLE8V  0x00000007
#define MASK_VLE8V  0xfdf0707f
#define MATCH_VLE16V  0x00005007
#define MASK_VLE16V  0xfdf0707f
#define MATCH_VLE32V  0x00006007
#define MASK_VLE32V  0xfdf0707f
#define MATCH_VLE64V  0x00007007
#define MASK_VLE64V  0xfdf0707f
#define MATCH_VSE8V  0x00000027
#define MASK_VSE8V  0xfdf0707f
#define MATCH_VSE16V  0x00005027
#define MASK_VSE16V  0xfdf0707f
#define MATCH_VSE32V  0x00006027
#define MASK_VSE32V  0xfdf0707f
#define MATCH_VSE64V  0x00007027
#define MASK_VSE64V  0xfdf0707f
#define MATCH_VLSE8V  0x08000007
#define MASK_VLSE8V  0xfc00707f
#define MATCH_VLSE16V  0x08005007
#define MASK_VLSE16V  0xfc00707f
#define MATCH_VLSE32V  0x08006007
#define MASK_VLSE32V  0xfc00707f
#define MATCH_VLSE64V  0x08007007
#define MASK_VLSE64V  0xfc00707f
#define MATCH_VSSE8V  0x08000027
#define MASK_VSSE8V  0xfc00707f
#define MATCH_VSSE16V  0x08005027
#define MASK_VSSE16V  0xfc00707f
#define MATCH_VSSE32V  0x08006027
#define MASK_VSSE32V  0xfc00707f
#define MATCH_VSSE64V  0x08007027
#define MASK_VSSE64V  0xfc00707f
#define MATCH_VLOXEI8V  0x0c000007
#define MASK_VLOXEI8V  0xfc00707f
#define MATCH_VLOXEI16V  0x0c005007
#define MASK_VLOXEI16V  0xfc00707f
#define MATCH_VLOXEI32V  0x0c006007
#define MASK_VLOXEI32V  0xfc00707f
#define MATCH_VLOXEI64V  0x0c007007
#define MASK_VLOXEI64V  0xfc00707f
#define MATCH_VSOXEI8V  0x0c000027
#define MASK_VSOXEI8V  0xfc00707f
#define MATCH_VSOXEI16V  0x0c005027
#define MASK_VSOXEI16V  0xfc00707f
#define MATCH_VSOXEI32V  0x0c006027
#define MASK_VSOXEI32V  0xfc00707f
#define MATCH_VSOXEI64V  0x0c007027
#define MASK_VSOXEI64V  0xfc00707f
#define MATCH_VLUXEI8V  0x04000007
#define MASK_VLUXEI8V  0xfc00707f
#define MATCH_VLUXEI16V  0x04005007
#define MASK_VLUXEI16V  0xfc00707f
#define MATCH_VLUXEI32V  0x04006007
#define MASK_VLUXEI32V  0xfc00707f
#define MATCH_VLUXEI64V  0x04007007
#define MASK_VLUXEI64V  0xfc00707f
#define MATCH_VSUXEI8V  0x04000027
#define MASK_VSUXEI8V  0xfc00707f
#define MATCH_VSUXEI16V  0x04005027
#define MASK_VSUXEI16V  0xfc00707f
#define MATCH_VSUXEI32V  0x04006027
#define MASK_VSUXEI32V  0xfc00707f
#define MATCH_VSUXEI64V  0x04007027
#define MASK_VSUXEI64V  0xfc00707f
#define MATCH_VLE8FFV  0x01000007
#define MASK_VLE8FFV  0xfdf0707f
#define MATCH_VLE16FFV  0x01005007
#define MASK_VLE16FFV  0xfdf0707f
#define MATCH_VLE32FFV  0x01006007
#define MASK_VLE32FFV  0xfdf0707f
#define MATCH_VLE64FFV  0x01007007
#define MASK_VLE64FFV  0xfdf0707f
#define MATCH_VLSEG2E8V  0x20000007
#define MASK_VLSEG2E8V  0xfdf0707f
#define MATCH_VSSEG2E8V  0x20000027
#define MASK_VSSEG2E8V  0xfdf0707f
#define MATCH_VLSEG3E8V  0x40000007
#define MASK_VLSEG3E8V  0xfdf0707f
#define MATCH_VSSEG3E8V  0x40000027
#define MASK_VSSEG3E8V  0xfdf0707f
#define MATCH_VLSEG4E8V  0x60000007
#define MASK_VLSEG4E8V  0xfdf0707f
#define MATCH_VSSEG4E8V  0x60000027
#define MASK_VSSEG4E8V  0xfdf0707f
#define MATCH_VLSEG5E8V  0x80000007
#define MASK_VLSEG5E8V  0xfdf0707f
#define MATCH_VSSEG5E8V  0x80000027
#define MASK_VSSEG5E8V  0xfdf0707f
#define MATCH_VLSEG6E8V  0xa0000007
#define MASK_VLSEG6E8V  0xfdf0707f
#define MATCH_VSSEG6E8V  0xa0000027
#define MASK_VSSEG6E8V  0xfdf0707f
#define MATCH_VLSEG7E8V  0xc0000007
#define MASK_VLSEG7E8V  0xfdf0707f
#define MATCH_VSSEG7E8V  0xc0000027
#define MASK_VSSEG7E8V  0xfdf0707f
#define MATCH_VLSEG8E8V  0xe0000007
#define MASK_VLSEG8E8V  0xfdf0707f
#define MATCH_VSSEG8E8V  0xe0000027
#define MASK_VSSEG8E8V  0xfdf0707f
#define MATCH_VLSEG2E16V 0x20005007
#define MASK_VLSEG2E16V  0xfdf0707f
#define MATCH_VSSEG2E16V 0x20005027
#define MASK_VSSEG2E16V  0xfdf0707f
#define MATCH_VLSEG3E16V 0x40005007
#define MASK_VLSEG3E16V  0xfdf0707f
#define MATCH_VSSEG3E16V 0x40005027
#define MASK_VSSEG3E16V  0xfdf0707f
#define MATCH_VLSEG4E16V 0x60005007
#define MASK_VLSEG4E16V  0xfdf0707f
#define MATCH_VSSEG4E16V 0x60005027
#define MASK_VSSEG4E16V  0xfdf0707f
#define MATCH_VLSEG5E16V 0x80005007
#define MASK_VLSEG5E16V  0xfdf0707f
#define MATCH_VSSEG5E16V 0x80005027
#define MASK_VSSEG5E16V  0xfdf0707f
#define MATCH_VLSEG6E16V 0xa0005007
#define MASK_VLSEG6E16V  0xfdf0707f
#define MATCH_VSSEG6E16V 0xa0005027
#define MASK_VSSEG6E16V  0xfdf0707f
#define MATCH_VLSEG7E16V 0xc0005007
#define MASK_VLSEG7E16V  0xfdf0707f
#define MATCH_VSSEG7E16V 0xc0005027
#define MASK_VSSEG7E16V  0xfdf0707f
#define MATCH_VLSEG8E16V 0xe0005007
#define MASK_VLSEG8E16V  0xfdf0707f
#define MATCH_VSSEG8E16V 0xe0005027
#define MASK_VSSEG8E16V  0xfdf0707f
#define MATCH_VLSEG2E32V 0x20006007
#define MASK_VLSEG2E32V  0xfdf0707f
#define MATCH_VSSEG2E32V 0x20006027
#define MASK_VSSEG2E32V  0xfdf0707f
#define MATCH_VLSEG3E32V 0x40006007
#define MASK_VLSEG3E32V  0xfdf0707f
#define MATCH_VSSEG3E32V 0x40006027
#define MASK_VSSEG3E32V  0xfdf0707f
#define MATCH_VLSEG4E32V 0x60006007
#define MASK_VLSEG4E32V  0xfdf0707f
#define MATCH_VSSEG4E32V 0x60006027
#define MASK_VSSEG4E32V  0xfdf0707f
#define MATCH_VLSEG5E32V 0x80006007
#define MASK_VLSEG5E32V  0xfdf0707f
#define MATCH_VSSEG5E32V 0x80006027
#define MASK_VSSEG5E32V  0xfdf0707f
#define MATCH_VLSEG6E32V 0xa0006007
#define MASK_VLSEG6E32V  0xfdf0707f
#define MATCH_VSSEG6E32V 0xa0006027
#define MASK_VSSEG6E32V  0xfdf0707f
#define MATCH_VLSEG7E32V 0xc0006007
#define MASK_VLSEG7E32V  0xfdf0707f
#define MATCH_VSSEG7E32V 0xc0006027
#define MASK_VSSEG7E32V  0xfdf0707f
#define MATCH_VLSEG8E32V 0xe0006007
#define MASK_VLSEG8E32V  0xfdf0707f
#define MATCH_VSSEG8E32V 0xe0006027
#define MASK_VSSEG8E32V  0xfdf0707f
#define MATCH_VLSEG2E64V 0x20007007
#define MASK_VLSEG2E64V  0xfdf0707f
#define MATCH_VSSEG2E64V 0x20007027
#define MASK_VSSEG2E64V  0xfdf0707f
#define MATCH_VLSEG3E64V 0x40007007
#define MASK_VLSEG3E64V  0xfdf0707f
#define MATCH_VSSEG3E64V 0x40007027
#define MASK_VSSEG3E64V  0xfdf0707f
#define MATCH_VLSEG4E64V 0x60007007
#define MASK_VLSEG4E64V  0xfdf0707f
#define MATCH_VSSEG4E64V 0x60007027
#define MASK_VSSEG4E64V  0xfdf0707f
#define MATCH_VLSEG5E64V 0x80007007
#define MASK_VLSEG5E64V  0xfdf0707f
#define MATCH_VSSEG5E64V 0x80007027
#define MASK_VSSEG5E64V  0xfdf0707f
#define MATCH_VLSEG6E64V 0xa0007007
#define MASK_VLSEG6E64V  0xfdf0707f
#define MATCH_VSSEG6E64V 0xa0007027
#define MASK_VSSEG6E64V  0xfdf0707f
#define MATCH_VLSEG7E64V 0xc0007007
#define MASK_VLSEG7E64V  0xfdf0707f
#define MATCH_VSSEG7E64V 0xc0007027
#define MASK_VSSEG7E64V  0xfdf0707f
#define MATCH_VLSEG8E64V 0xe0007007
#define MASK_VLSEG8E64V  0xfdf0707f
#define MATCH_VSSEG8E64V 0xe0007027
#define MASK_VSSEG8E64V  0xfdf0707f
#define MATCH_VLSSEG2E8V 0x28000007
#define MASK_VLSSEG2E8V  0xfc00707f
#define MATCH_VSSSEG2E8V 0x28000027
#define MASK_VSSSEG2E8V  0xfc00707f
#define MATCH_VLSSEG3E8V 0x48000007
#define MASK_VLSSEG3E8V  0xfc00707f
#define MATCH_VSSSEG3E8V 0x48000027
#define MASK_VSSSEG3E8V  0xfc00707f
#define MATCH_VLSSEG4E8V 0x68000007
#define MASK_VLSSEG4E8V  0xfc00707f
#define MATCH_VSSSEG4E8V 0x68000027
#define MASK_VSSSEG4E8V  0xfc00707f
#define MATCH_VLSSEG5E8V 0x88000007
#define MASK_VLSSEG5E8V  0xfc00707f
#define MATCH_VSSSEG5E8V 0x88000027
#define MASK_VSSSEG5E8V  0xfc00707f
#define MATCH_VLSSEG6E8V 0xa8000007
#define MASK_VLSSEG6E8V  0xfc00707f
#define MATCH_VSSSEG6E8V 0xa8000027
#define MASK_VSSSEG6E8V  0xfc00707f
#define MATCH_VLSSEG7E8V 0xc8000007
#define MASK_VLSSEG7E8V  0xfc00707f
#define MATCH_VSSSEG7E8V 0xc8000027
#define MASK_VSSSEG7E8V  0xfc00707f
#define MATCH_VLSSEG8E8V 0xe8000007
#define MASK_VLSSEG8E8V  0xfc00707f
#define MATCH_VSSSEG8E8V 0xe8000027
#define MASK_VSSSEG8E8V  0xfc00707f
#define MATCH_VLSSEG2E16V 0x28005007
#define MASK_VLSSEG2E16V 0xfc00707f
#define MATCH_VSSSEG2E16V 0x28005027
#define MASK_VSSSEG2E16V 0xfc00707f
#define MATCH_VLSSEG3E16V 0x48005007
#define MASK_VLSSEG3E16V 0xfc00707f
#define MATCH_VSSSEG3E16V 0x48005027
#define MASK_VSSSEG3E16V 0xfc00707f
#define MATCH_VLSSEG4E16V 0x68005007
#define MASK_VLSSEG4E16V 0xfc00707f
#define MATCH_VSSSEG4E16V 0x68005027
#define MASK_VSSSEG4E16V 0xfc00707f
#define MATCH_VLSSEG5E16V 0x88005007
#define MASK_VLSSEG5E16V 0xfc00707f
#define MATCH_VSSSEG5E16V 0x88005027
#define MASK_VSSSEG5E16V 0xfc00707f
#define MATCH_VLSSEG6E16V 0xa8005007
#define MASK_VLSSEG6E16V 0xfc00707f
#define MATCH_VSSSEG6E16V 0xa8005027
#define MASK_VSSSEG6E16V 0xfc00707f
#define MATCH_VLSSEG7E16V 0xc8005007
#define MASK_VLSSEG7E16V 0xfc00707f
#define MATCH_VSSSEG7E16V 0xc8005027
#define MASK_VSSSEG7E16V 0xfc00707f
#define MATCH_VLSSEG8E16V 0xe8005007
#define MASK_VLSSEG8E16V 0xfc00707f
#define MATCH_VSSSEG8E16V 0xe8005027
#define MASK_VSSSEG8E16V 0xfc00707f
#define MATCH_VLSSEG2E32V 0x28006007
#define MASK_VLSSEG2E32V 0xfc00707f
#define MATCH_VSSSEG2E32V 0x28006027
#define MASK_VSSSEG2E32V 0xfc00707f
#define MATCH_VLSSEG3E32V 0x48006007
#define MASK_VLSSEG3E32V 0xfc00707f
#define MATCH_VSSSEG3E32V 0x48006027
#define MASK_VSSSEG3E32V 0xfc00707f
#define MATCH_VLSSEG4E32V 0x68006007
#define MASK_VLSSEG4E32V 0xfc00707f
#define MATCH_VSSSEG4E32V 0x68006027
#define MASK_VSSSEG4E32V 0xfc00707f
#define MATCH_VLSSEG5E32V 0x88006007
#define MASK_VLSSEG5E32V 0xfc00707f
#define MATCH_VSSSEG5E32V 0x88006027
#define MASK_VSSSEG5E32V 0xfc00707f
#define MATCH_VLSSEG6E32V 0xa8006007
#define MASK_VLSSEG6E32V 0xfc00707f
#define MATCH_VSSSEG6E32V 0xa8006027
#define MASK_VSSSEG6E32V 0xfc00707f
#define MATCH_VLSSEG7E32V 0xc8006007
#define MASK_VLSSEG7E32V 0xfc00707f
#define MATCH_VSSSEG7E32V 0xc8006027
#define MASK_VSSSEG7E32V 0xfc00707f
#define MATCH_VLSSEG8E32V 0xe8006007
#define MASK_VLSSEG8E32V 0xfc00707f
#define MATCH_VSSSEG8E32V 0xe8006027
#define MASK_VSSSEG8E32V 0xfc00707f
#define MATCH_VLSSEG2E64V 0x28007007
#define MASK_VLSSEG2E64V 0xfc00707f
#define MATCH_VSSSEG2E64V 0x28007027
#define MASK_VSSSEG2E64V 0xfc00707f
#define MATCH_VLSSEG3E64V 0x48007007
#define MASK_VLSSEG3E64V 0xfc00707f
#define MATCH_VSSSEG3E64V 0x48007027
#define MASK_VSSSEG3E64V 0xfc00707f
#define MATCH_VLSSEG4E64V 0x68007007
#define MASK_VLSSEG4E64V 0xfc00707f
#define MATCH_VSSSEG4E64V 0x68007027
#define MASK_VSSSEG4E64V 0xfc00707f
#define MATCH_VLSSEG5E64V 0x88007007
#define MASK_VLSSEG5E64V 0xfc00707f
#define MATCH_VSSSEG5E64V 0x88007027
#define MASK_VSSSEG5E64V 0xfc00707f
#define MATCH_VLSSEG6E64V 0xa8007007
#define MASK_VLSSEG6E64V 0xfc00707f
#define MATCH_VSSSEG6E64V 0xa8007027
#define MASK_VSSSEG6E64V 0xfc00707f
#define MATCH_VLSSEG7E64V 0xc8007007
#define MASK_VLSSEG7E64V 0xfc00707f
#define MATCH_VSSSEG7E64V 0xc8007027
#define MASK_VSSSEG7E64V 0xfc00707f
#define MATCH_VLSSEG8E64V 0xe8007007
#define MASK_VLSSEG8E64V 0xfc00707f
#define MATCH_VSSSEG8E64V 0xe8007027
#define MASK_VSSSEG8E64V 0xfc00707f
#define MATCH_VLOXSEG2EI8V 0x2c000007
#define MASK_VLOXSEG2EI8V 0xfc00707f
#define MATCH_VSOXSEG2EI8V 0x2c000027
#define MASK_VSOXSEG2EI8V 0xfc00707f
#define MATCH_VLOXSEG3EI8V 0x4c000007
#define MASK_VLOXSEG3EI8V 0xfc00707f
#define MATCH_VSOXSEG3EI8V 0x4c000027
#define MASK_VSOXSEG3EI8V 0xfc00707f
#define MATCH_VLOXSEG4EI8V 0x6c000007
#define MASK_VLOXSEG4EI8V 0xfc00707f
#define MATCH_VSOXSEG4EI8V 0x6c000027
#define MASK_VSOXSEG4EI8V 0xfc00707f
#define MATCH_VLOXSEG5EI8V 0x8c000007
#define MASK_VLOXSEG5EI8V 0xfc00707f
#define MATCH_VSOXSEG5EI8V 0x8c000027
#define MASK_VSOXSEG5EI8V 0xfc00707f
#define MATCH_VLOXSEG6EI8V 0xac000007
#define MASK_VLOXSEG6EI8V 0xfc00707f
#define MATCH_VSOXSEG6EI8V 0xac000027
#define MASK_VSOXSEG6EI8V 0xfc00707f
#define MATCH_VLOXSEG7EI8V 0xcc000007
#define MASK_VLOXSEG7EI8V 0xfc00707f
#define MATCH_VSOXSEG7EI8V 0xcc000027
#define MASK_VSOXSEG7EI8V 0xfc00707f
#define MATCH_VLOXSEG8EI8V 0xec000007
#define MASK_VLOXSEG8EI8V 0xfc00707f
#define MATCH_VSOXSEG8EI8V 0xec000027
#define MASK_VSOXSEG8EI8V 0xfc00707f
#define MATCH_VLUXSEG2EI8V 0x24000007
#define MASK_VLUXSEG2EI8V 0xfc00707f
#define MATCH_VSUXSEG2EI8V 0x24000027
#define MASK_VSUXSEG2EI8V 0xfc00707f
#define MATCH_VLUXSEG3EI8V 0x44000007
#define MASK_VLUXSEG3EI8V 0xfc00707f
#define MATCH_VSUXSEG3EI8V 0x44000027
#define MASK_VSUXSEG3EI8V 0xfc00707f
#define MATCH_VLUXSEG4EI8V 0x64000007
#define MASK_VLUXSEG4EI8V 0xfc00707f
#define MATCH_VSUXSEG4EI8V 0x64000027
#define MASK_VSUXSEG4EI8V 0xfc00707f
#define MATCH_VLUXSEG5EI8V 0x84000007
#define MASK_VLUXSEG5EI8V 0xfc00707f
#define MATCH_VSUXSEG5EI8V 0x84000027
#define MASK_VSUXSEG5EI8V 0xfc00707f
#define MATCH_VLUXSEG6EI8V 0xa4000007
#define MASK_VLUXSEG6EI8V 0xfc00707f
#define MATCH_VSUXSEG6EI8V 0xa4000027
#define MASK_VSUXSEG6EI8V 0xfc00707f
#define MATCH_VLUXSEG7EI8V 0xc4000007
#define MASK_VLUXSEG7EI8V 0xfc00707f
#define MATCH_VSUXSEG7EI8V 0xc4000027
#define MASK_VSUXSEG7EI8V 0xfc00707f
#define MATCH_VLUXSEG8EI8V 0xe4000007
#define MASK_VLUXSEG8EI8V 0xfc00707f
#define MATCH_VSUXSEG8EI8V 0xe4000027
#define MASK_VSUXSEG8EI8V 0xfc00707f
#define MATCH_VLOXSEG2EI16V 0x2c005007
#define MASK_VLOXSEG2EI16V 0xfc00707f
#define MATCH_VSOXSEG2EI16V 0x2c005027
#define MASK_VSOXSEG2EI16V 0xfc00707f
#define MATCH_VLOXSEG3EI16V 0x4c005007
#define MASK_VLOXSEG3EI16V 0xfc00707f
#define MATCH_VSOXSEG3EI16V 0x4c005027
#define MASK_VSOXSEG3EI16V 0xfc00707f
#define MATCH_VLOXSEG4EI16V 0x6c005007
#define MASK_VLOXSEG4EI16V 0xfc00707f
#define MATCH_VSOXSEG4EI16V 0x6c005027
#define MASK_VSOXSEG4EI16V 0xfc00707f
#define MATCH_VLOXSEG5EI16V 0x8c005007
#define MASK_VLOXSEG5EI16V 0xfc00707f
#define MATCH_VSOXSEG5EI16V 0x8c005027
#define MASK_VSOXSEG5EI16V 0xfc00707f
#define MATCH_VLOXSEG6EI16V 0xac005007
#define MASK_VLOXSEG6EI16V 0xfc00707f
#define MATCH_VSOXSEG6EI16V 0xac005027
#define MASK_VSOXSEG6EI16V 0xfc00707f
#define MATCH_VLOXSEG7EI16V 0xcc005007
#define MASK_VLOXSEG7EI16V 0xfc00707f
#define MATCH_VSOXSEG7EI16V 0xcc005027
#define MASK_VSOXSEG7EI16V 0xfc00707f
#define MATCH_VLOXSEG8EI16V 0xec005007
#define MASK_VLOXSEG8EI16V 0xfc00707f
#define MATCH_VSOXSEG8EI16V 0xec005027
#define MASK_VSOXSEG8EI16V 0xfc00707f
#define MATCH_VLUXSEG2EI16V 0x24005007
#define MASK_VLUXSEG2EI16V 0xfc00707f
#define MATCH_VSUXSEG2EI16V 0x24005027
#define MASK_VSUXSEG2EI16V 0xfc00707f
#define MATCH_VLUXSEG3EI16V 0x44005007
#define MASK_VLUXSEG3EI16V 0xfc00707f
#define MATCH_VSUXSEG3EI16V 0x44005027
#define MASK_VSUXSEG3EI16V 0xfc00707f
#define MATCH_VLUXSEG4EI16V 0x64005007
#define MASK_VLUXSEG4EI16V 0xfc00707f
#define MATCH_VSUXSEG4EI16V 0x64005027
#define MASK_VSUXSEG4EI16V 0xfc00707f
#define MATCH_VLUXSEG5EI16V 0x84005007
#define MASK_VLUXSEG5EI16V 0xfc00707f
#define MATCH_VSUXSEG5EI16V 0x84005027
#define MASK_VSUXSEG5EI16V 0xfc00707f
#define MATCH_VLUXSEG6EI16V 0xa4005007
#define MASK_VLUXSEG6EI16V 0xfc00707f
#define MATCH_VSUXSEG6EI16V 0xa4005027
#define MASK_VSUXSEG6EI16V 0xfc00707f
#define MATCH_VLUXSEG7EI16V 0xc4005007
#define MASK_VLUXSEG7EI16V 0xfc00707f
#define MATCH_VSUXSEG7EI16V 0xc4005027
#define MASK_VSUXSEG7EI16V 0xfc00707f
#define MATCH_VLUXSEG8EI16V 0xe4005007
#define MASK_VLUXSEG8EI16V 0xfc00707f
#define MATCH_VSUXSEG8EI16V 0xe4005027
#define MASK_VSUXSEG8EI16V 0xfc00707f
#define MATCH_VLOXSEG2EI32V 0x2c006007
#define MASK_VLOXSEG2EI32V 0xfc00707f
#define MATCH_VSOXSEG2EI32V 0x2c006027
#define MASK_VSOXSEG2EI32V 0xfc00707f
#define MATCH_VLOXSEG3EI32V 0x4c006007
#define MASK_VLOXSEG3EI32V 0xfc00707f
#define MATCH_VSOXSEG3EI32V 0x4c006027
#define MASK_VSOXSEG3EI32V 0xfc00707f
#define MATCH_VLOXSEG4EI32V 0x6c006007
#define MASK_VLOXSEG4EI32V 0xfc00707f
#define MATCH_VSOXSEG4EI32V 0x6c006027
#define MASK_VSOXSEG4EI32V 0xfc00707f
#define MATCH_VLOXSEG5EI32V 0x8c006007
#define MASK_VLOXSEG5EI32V 0xfc00707f
#define MATCH_VSOXSEG5EI32V 0x8c006027
#define MASK_VSOXSEG5EI32V 0xfc00707f
#define MATCH_VLOXSEG6EI32V 0xac006007
#define MASK_VLOXSEG6EI32V 0xfc00707f
#define MATCH_VSOXSEG6EI32V 0xac006027
#define MASK_VSOXSEG6EI32V 0xfc00707f
#define MATCH_VLOXSEG7EI32V 0xcc006007
#define MASK_VLOXSEG7EI32V 0xfc00707f
#define MATCH_VSOXSEG7EI32V 0xcc006027
#define MASK_VSOXSEG7EI32V 0xfc00707f
#define MATCH_VLOXSEG8EI32V 0xec006007
#define MASK_VLOXSEG8EI32V 0xfc00707f
#define MATCH_VSOXSEG8EI32V 0xec006027
#define MASK_VSOXSEG8EI32V 0xfc00707f
#define MATCH_VLUXSEG2EI32V 0x24006007
#define MASK_VLUXSEG2EI32V 0xfc00707f
#define MATCH_VSUXSEG2EI32V 0x24006027
#define MASK_VSUXSEG2EI32V 0xfc00707f
#define MATCH_VLUXSEG3EI32V 0x44006007
#define MASK_VLUXSEG3EI32V 0xfc00707f
#define MATCH_VSUXSEG3EI32V 0x44006027
#define MASK_VSUXSEG3EI32V 0xfc00707f
#define MATCH_VLUXSEG4EI32V 0x64006007
#define MASK_VLUXSEG4EI32V 0xfc00707f
#define MATCH_VSUXSEG4EI32V 0x64006027
#define MASK_VSUXSEG4EI32V 0xfc00707f
#define MATCH_VLUXSEG5EI32V 0x84006007
#define MASK_VLUXSEG5EI32V 0xfc00707f
#define MATCH_VSUXSEG5EI32V 0x84006027
#define MASK_VSUXSEG5EI32V 0xfc00707f
#define MATCH_VLUXSEG6EI32V 0xa4006007
#define MASK_VLUXSEG6EI32V 0xfc00707f
#define MATCH_VSUXSEG6EI32V 0xa4006027
#define MASK_VSUXSEG6EI32V 0xfc00707f
#define MATCH_VLUXSEG7EI32V 0xc4006007
#define MASK_VLUXSEG7EI32V 0xfc00707f
#define MATCH_VSUXSEG7EI32V 0xc4006027
#define MASK_VSUXSEG7EI32V 0xfc00707f
#define MATCH_VLUXSEG8EI32V 0xe4006007
#define MASK_VLUXSEG8EI32V 0xfc00707f
#define MATCH_VSUXSEG8EI32V 0xe4006027
#define MASK_VSUXSEG8EI32V 0xfc00707f
#define MATCH_VLOXSEG2EI64V 0x2c007007
#define MASK_VLOXSEG2EI64V 0xfc00707f
#define MATCH_VSOXSEG2EI64V 0x2c007027
#define MASK_VSOXSEG2EI64V 0xfc00707f
#define MATCH_VLOXSEG3EI64V 0x4c007007
#define MASK_VLOXSEG3EI64V 0xfc00707f
#define MATCH_VSOXSEG3EI64V 0x4c007027
#define MASK_VSOXSEG3EI64V 0xfc00707f
#define MATCH_VLOXSEG4EI64V 0x6c007007
#define MASK_VLOXSEG4EI64V 0xfc00707f
#define MATCH_VSOXSEG4EI64V 0x6c007027
#define MASK_VSOXSEG4EI64V 0xfc00707f
#define MATCH_VLOXSEG5EI64V 0x8c007007
#define MASK_VLOXSEG5EI64V 0xfc00707f
#define MATCH_VSOXSEG5EI64V 0x8c007027
#define MASK_VSOXSEG5EI64V 0xfc00707f
#define MATCH_VLOXSEG6EI64V 0xac007007
#define MASK_VLOXSEG6EI64V 0xfc00707f
#define MATCH_VSOXSEG6EI64V 0xac007027
#define MASK_VSOXSEG6EI64V 0xfc00707f
#define MATCH_VLOXSEG7EI64V 0xcc007007
#define MASK_VLOXSEG7EI64V 0xfc00707f
#define MATCH_VSOXSEG7EI64V 0xcc007027
#define MASK_VSOXSEG7EI64V 0xfc00707f
#define MATCH_VLOXSEG8EI64V 0xec007007
#define MASK_VLOXSEG8EI64V 0xfc00707f
#define MATCH_VSOXSEG8EI64V 0xec007027
#define MASK_VSOXSEG8EI64V 0xfc00707f
#define MATCH_VLUXSEG2EI64V 0x24007007
#define MASK_VLUXSEG2EI64V 0xfc00707f
#define MATCH_VSUXSEG2EI64V 0x24007027
#define MASK_VSUXSEG2EI64V 0xfc00707f
#define MATCH_VLUXSEG3EI64V 0x44007007
#define MASK_VLUXSEG3EI64V 0xfc00707f
#define MATCH_VSUXSEG3EI64V 0x44007027
#define MASK_VSUXSEG3EI64V 0xfc00707f
#define MATCH_VLUXSEG4EI64V 0x64007007
#define MASK_VLUXSEG4EI64V 0xfc00707f
#define MATCH_VSUXSEG4EI64V 0x64007027
#define MASK_VSUXSEG4EI64V 0xfc00707f
#define MATCH_VLUXSEG5EI64V 0x84007007
#define MASK_VLUXSEG5EI64V 0xfc00707f
#define MATCH_VSUXSEG5EI64V 0x84007027
#define MASK_VSUXSEG5EI64V 0xfc00707f
#define MATCH_VLUXSEG6EI64V 0xa4007007
#define MASK_VLUXSEG6EI64V 0xfc00707f
#define MATCH_VSUXSEG6EI64V 0xa4007027
#define MASK_VSUXSEG6EI64V 0xfc00707f
#define MATCH_VLUXSEG7EI64V 0xc4007007
#define MASK_VLUXSEG7EI64V 0xfc00707f
#define MATCH_VSUXSEG7EI64V 0xc4007027
#define MASK_VSUXSEG7EI64V 0xfc00707f
#define MATCH_VLUXSEG8EI64V 0xe4007007
#define MASK_VLUXSEG8EI64V 0xfc00707f
#define MATCH_VSUXSEG8EI64V 0xe4007027
#define MASK_VSUXSEG8EI64V 0xfc00707f
#define MATCH_VLSEG2E8FFV 0x21000007
#define MASK_VLSEG2E8FFV 0xfdf0707f
#define MATCH_VLSEG3E8FFV 0x41000007
#define MASK_VLSEG3E8FFV 0xfdf0707f
#define MATCH_VLSEG4E8FFV 0x61000007
#define MASK_VLSEG4E8FFV 0xfdf0707f
#define MATCH_VLSEG5E8FFV 0x81000007
#define MASK_VLSEG5E8FFV 0xfdf0707f
#define MATCH_VLSEG6E8FFV 0xa1000007
#define MASK_VLSEG6E8FFV 0xfdf0707f
#define MATCH_VLSEG7E8FFV 0xc1000007
#define MASK_VLSEG7E8FFV 0xfdf0707f
#define MATCH_VLSEG8E8FFV 0xe1000007
#define MASK_VLSEG8E8FFV 0xfdf0707f
#define MATCH_VLSEG2E16FFV 0x21005007
#define MASK_VLSEG2E16FFV 0xfdf0707f
#define MATCH_VLSEG3E16FFV 0x41005007
#define MASK_VLSEG3E16FFV 0xfdf0707f
#define MATCH_VLSEG4E16FFV 0x61005007
#define MASK_VLSEG4E16FFV 0xfdf0707f
#define MATCH_VLSEG5E16FFV 0x81005007
#define MASK_VLSEG5E16FFV 0xfdf0707f
#define MATCH_VLSEG6E16FFV 0xa1005007
#define MASK_VLSEG6E16FFV 0xfdf0707f
#define MATCH_VLSEG7E16FFV 0xc1005007
#define MASK_VLSEG7E16FFV 0xfdf0707f
#define MATCH_VLSEG8E16FFV 0xe1005007
#define MASK_VLSEG8E16FFV 0xfdf0707f
#define MATCH_VLSEG2E32FFV 0x21006007
#define MASK_VLSEG2E32FFV 0xfdf0707f
#define MATCH_VLSEG3E32FFV 0x41006007
#define MASK_VLSEG3E32FFV 0xfdf0707f
#define MATCH_VLSEG4E32FFV 0x61006007
#define MASK_VLSEG4E32FFV 0xfdf0707f
#define MATCH_VLSEG5E32FFV 0x81006007
#define MASK_VLSEG5E32FFV 0xfdf0707f
#define MATCH_VLSEG6E32FFV 0xa1006007
#define MASK_VLSEG6E32FFV 0xfdf0707f
#define MATCH_VLSEG7E32FFV 0xc1006007
#define MASK_VLSEG7E32FFV 0xfdf0707f
#define MATCH_VLSEG8E32FFV 0xe1006007
#define MASK_VLSEG8E32FFV 0xfdf0707f
#define MATCH_VLSEG2E64FFV 0x21007007
#define MASK_VLSEG2E64FFV 0xfdf0707f
#define MATCH_VLSEG3E64FFV 0x41007007
#define MASK_VLSEG3E64FFV 0xfdf0707f
#define MATCH_VLSEG4E64FFV 0x61007007
#define MASK_VLSEG4E64FFV 0xfdf0707f
#define MATCH_VLSEG5E64FFV 0x81007007
#define MASK_VLSEG5E64FFV 0xfdf0707f
#define MATCH_VLSEG6E64FFV 0xa1007007
#define MASK_VLSEG6E64FFV 0xfdf0707f
#define MATCH_VLSEG7E64FFV 0xc1007007
#define MASK_VLSEG7E64FFV 0xfdf0707f
#define MATCH_VLSEG8E64FFV 0xe1007007
#define MASK_VLSEG8E64FFV 0xfdf0707f
#define MATCH_VL1RE8V  0x02800007
#define MASK_VL1RE8V  0xfff0707f
#define MATCH_VL1RE16V  0x02805007
#define MASK_VL1RE16V  0xfff0707f
#define MATCH_VL1RE32V  0x02806007
#define MASK_VL1RE32V  0xfff0707f
#define MATCH_VL1RE64V  0x02807007
#define MASK_VL1RE64V  0xfff0707f
#define MATCH_VL2RE8V  0x22800007
#define MASK_VL2RE8V  0xfff0707f
#define MATCH_VL2RE16V  0x22805007
#define MASK_VL2RE16V  0xfff0707f
#define MATCH_VL2RE32V  0x22806007
#define MASK_VL2RE32V  0xfff0707f
#define MATCH_VL2RE64V  0x22807007
#define MASK_VL2RE64V  0xfff0707f
#define MATCH_VL4RE8V  0x62800007
#define MASK_VL4RE8V  0xfff0707f
#define MATCH_VL4RE16V  0x62805007
#define MASK_VL4RE16V  0xfff0707f
#define MATCH_VL4RE32V  0x62806007
#define MASK_VL4RE32V  0xfff0707f
#define MATCH_VL4RE64V  0x62807007
#define MASK_VL4RE64V  0xfff0707f
#define MATCH_VL8RE8V  0xe2800007
#define MASK_VL8RE8V  0xfff0707f
#define MATCH_VL8RE16V  0xe2805007
#define MASK_VL8RE16V  0xfff0707f
#define MATCH_VL8RE32V  0xe2806007
#define MASK_VL8RE32V  0xfff0707f
#define MATCH_VL8RE64V  0xe2807007
#define MASK_VL8RE64V  0xfff0707f
#define MATCH_VS1RV  0x02800027
#define MASK_VS1RV  0xfff0707f
#define MATCH_VS2RV  0x22800027
#define MASK_VS2RV  0xfff0707f
#define MATCH_VS4RV  0x62800027
#define MASK_VS4RV  0xfff0707f
#define MATCH_VS8RV  0xe2800027
#define MASK_VS8RV  0xfff0707f
#define MATCH_VADDVV  0x00000057
#define MASK_VADDVV  0xfc00707f
#define MATCH_VADDVX  0x00004057
#define MASK_VADDVX  0xfc00707f
#define MATCH_VADDVI  0x00003057
#define MASK_VADDVI  0xfc00707f
#define MATCH_VSUBVV  0x08000057
#define MASK_VSUBVV  0xfc00707f
#define MATCH_VSUBVX  0x08004057
#define MASK_VSUBVX  0xfc00707f
#define MATCH_VRSUBVX  0x0c004057
#define MASK_VRSUBVX  0xfc00707f
#define MATCH_VRSUBVI  0x0c003057
#define MASK_VRSUBVI  0xfc00707f
#define MATCH_VWCVTXXV  0xc4006057
#define MASK_VWCVTXXV  0xfc0ff07f
#define MATCH_VWCVTUXXV  0xc0006057
#define MASK_VWCVTUXXV  0xfc0ff07f
#define MATCH_VWADDVV  0xc4002057
#define MASK_VWADDVV  0xfc00707f
#define MATCH_VWADDVX  0xc4006057
#define MASK_VWADDVX  0xfc00707f
#define MATCH_VWSUBVV  0xcc002057
#define MASK_VWSUBVV  0xfc00707f
#define MATCH_VWSUBVX  0xcc006057
#define MASK_VWSUBVX  0xfc00707f
#define MATCH_VWADDWV  0xd4002057
#define MASK_VWADDWV  0xfc00707f
#define MATCH_VWADDWX  0xd4006057
#define MASK_VWADDWX  0xfc00707f
#define MATCH_VWSUBWV  0xdc002057
#define MASK_VWSUBWV  0xfc00707f
#define MATCH_VWSUBWX  0xdc006057
#define MASK_VWSUBWX  0xfc00707f
#define MATCH_VWADDUVV  0xc0002057
#define MASK_VWADDUVV  0xfc00707f
#define MATCH_VWADDUVX  0xc0006057
#define MASK_VWADDUVX  0xfc00707f
#define MATCH_VWSUBUVV  0xc8002057
#define MASK_VWSUBUVV  0xfc00707f
#define MATCH_VWSUBUVX  0xc8006057
#define MASK_VWSUBUVX  0xfc00707f
#define MATCH_VWADDUWV  0xd0002057
#define MASK_VWADDUWV  0xfc00707f
#define MATCH_VWADDUWX  0xd0006057
#define MASK_VWADDUWX  0xfc00707f
#define MATCH_VWSUBUWV  0xd8002057
#define MASK_VWSUBUWV  0xfc00707f
#define MATCH_VWSUBUWX  0xd8006057
#define MASK_VWSUBUWX  0xfc00707f
#define MATCH_VZEXT_VF8  0x48012057
#define MASK_VZEXT_VF8  0xfc0ff07f
#define MATCH_VSEXT_VF8  0x4801a057
#define MASK_VSEXT_VF8  0xfc0ff07f
#define MATCH_VZEXT_VF4  0x48022057
#define MASK_VZEXT_VF4  0xfc0ff07f
#define MATCH_VSEXT_VF4  0x4802a057
#define MASK_VSEXT_VF4  0xfc0ff07f
#define MATCH_VZEXT_VF2  0x48032057
#define MASK_VZEXT_VF2  0xfc0ff07f
#define MATCH_VSEXT_VF2  0x4803a057
#define MASK_VSEXT_VF2  0xfc0ff07f
#define MATCH_VADCVVM  0x40000057
#define MASK_VADCVVM  0xfe00707f
#define MATCH_VADCVXM  0x40004057
#define MASK_VADCVXM  0xfe00707f
#define MATCH_VADCVIM  0x40003057
#define MASK_VADCVIM  0xfe00707f
#define MATCH_VMADCVVM  0x44000057
#define MASK_VMADCVVM  0xfe00707f
#define MATCH_VMADCVXM  0x44004057
#define MASK_VMADCVXM  0xfe00707f
#define MATCH_VMADCVIM  0x44003057
#define MASK_VMADCVIM  0xfe00707f
#define MATCH_VMADCVV  0x46000057
#define MASK_VMADCVV  0xfe00707f
#define MATCH_VMADCVX  0x46004057
#define MASK_VMADCVX  0xfe00707f
#define MATCH_VMADCVI  0x46003057
#define MASK_VMADCVI  0xfe00707f
#define MATCH_VSBCVVM  0x48000057
#define MASK_VSBCVVM  0xfe00707f
#define MATCH_VSBCVXM  0x48004057
#define MASK_VSBCVXM  0xfe00707f
#define MATCH_VMSBCVVM  0x4c000057
#define MASK_VMSBCVVM  0xfe00707f
#define MATCH_VMSBCVXM  0x4c004057
#define MASK_VMSBCVXM  0xfe00707f
#define MATCH_VMSBCVV  0x4e000057
#define MASK_VMSBCVV  0xfe00707f
#define MATCH_VMSBCVX  0x4e004057
#define MASK_VMSBCVX  0xfe00707f
#define MATCH_VNOTV  0x2c0fb057
#define MASK_VNOTV  0xfc0ff07f
#define MATCH_VANDVV  0x24000057
#define MASK_VANDVV  0xfc00707f
#define MATCH_VANDVX  0x24004057
#define MASK_VANDVX  0xfc00707f
#define MATCH_VANDVI  0x24003057
#define MASK_VANDVI  0xfc00707f
#define MATCH_VORVV  0x28000057
#define MASK_VORVV  0xfc00707f
#define MATCH_VORVX  0x28004057
#define MASK_VORVX  0xfc00707f
#define MATCH_VORVI  0x28003057
#define MASK_VORVI  0xfc00707f
#define MATCH_VXORVV  0x2c000057
#define MASK_VXORVV  0xfc00707f
#define MATCH_VXORVX  0x2c004057
#define MASK_VXORVX  0xfc00707f
#define MATCH_VXORVI  0x2c003057
#define MASK_VXORVI  0xfc00707f
#define MATCH_VSLLVV  0x94000057
#define MASK_VSLLVV  0xfc00707f
#define MATCH_VSLLVX  0x94004057
#define MASK_VSLLVX  0xfc00707f
#define MATCH_VSLLVI  0x94003057
#define MASK_VSLLVI  0xfc00707f
#define MATCH_VSRLVV  0xa0000057
#define MASK_VSRLVV  0xfc00707f
#define MATCH_VSRLVX  0xa0004057
#define MASK_VSRLVX  0xfc00707f
#define MATCH_VSRLVI  0xa0003057
#define MASK_VSRLVI  0xfc00707f
#define MATCH_VSRAVV  0xa4000057
#define MASK_VSRAVV  0xfc00707f
#define MATCH_VSRAVX  0xa4004057
#define MASK_VSRAVX  0xfc00707f
#define MATCH_VSRAVI  0xa4003057
#define MASK_VSRAVI  0xfc00707f
#define MATCH_VNCVTXXW  0xb0004057
#define MASK_VNCVTXXW  0xfc0ff07f
#define MATCH_VNSRLWV  0xb0000057
#define MASK_VNSRLWV  0xfc00707f
#define MATCH_VNSRLWX  0xb0004057
#define MASK_VNSRLWX  0xfc00707f
#define MATCH_VNSRLWI  0xb0003057
#define MASK_VNSRLWI  0xfc00707f
#define MATCH_VNSRAWV  0xb4000057
#define MASK_VNSRAWV  0xfc00707f
#define MATCH_VNSRAWX  0xb4004057
#define MASK_VNSRAWX  0xfc00707f
#define MATCH_VNSRAWI  0xb4003057
#define MASK_VNSRAWI  0xfc00707f
#define MATCH_VMSEQVV  0x60000057
#define MASK_VMSEQVV  0xfc00707f
#define MATCH_VMSEQVX  0x60004057
#define MASK_VMSEQVX  0xfc00707f
#define MATCH_VMSEQVI  0x60003057
#define MASK_VMSEQVI  0xfc00707f
#define MATCH_VMSNEVV  0x64000057
#define MASK_VMSNEVV  0xfc00707f
#define MATCH_VMSNEVX  0x64004057
#define MASK_VMSNEVX  0xfc00707f
#define MATCH_VMSNEVI  0x64003057
#define MASK_VMSNEVI  0xfc00707f
#define MATCH_VMSLTVV  0x6c000057
#define MASK_VMSLTVV  0xfc00707f
#define MATCH_VMSLTVX  0x6c004057
#define MASK_VMSLTVX  0xfc00707f
#define MATCH_VMSLTUVV  0x68000057
#define MASK_VMSLTUVV  0xfc00707f
#define MATCH_VMSLTUVX  0x68004057
#define MASK_VMSLTUVX  0xfc00707f
#define MATCH_VMSLEVV  0x74000057
#define MASK_VMSLEVV  0xfc00707f
#define MATCH_VMSLEVX  0x74004057
#define MASK_VMSLEVX  0xfc00707f
#define MATCH_VMSLEVI  0x74003057
#define MASK_VMSLEVI  0xfc00707f
#define MATCH_VMSLEUVV  0x70000057
#define MASK_VMSLEUVV  0xfc00707f
#define MATCH_VMSLEUVX  0x70004057
#define MASK_VMSLEUVX  0xfc00707f
#define MATCH_VMSLEUVI  0x70003057
#define MASK_VMSLEUVI  0xfc00707f
#define MATCH_VMSGTVX  0x7c004057
#define MASK_VMSGTVX  0xfc00707f
#define MATCH_VMSGTVI  0x7c003057
#define MASK_VMSGTVI  0xfc00707f
#define MATCH_VMSGTUVX  0x78004057
#define MASK_VMSGTUVX  0xfc00707f
#define MATCH_VMSGTUVI  0x78003057
#define MASK_VMSGTUVI  0xfc00707f
#define MATCH_VMINVV  0x14000057
#define MASK_VMINVV  0xfc00707f
#define MATCH_VMINVX  0x14004057
#define MASK_VMINVX  0xfc00707f
#define MATCH_VMAXVV  0x1c000057
#define MASK_VMAXVV  0xfc00707f
#define MATCH_VMAXVX  0x1c004057
#define MASK_VMAXVX  0xfc00707f
#define MATCH_VMINUVV  0x10000057
#define MASK_VMINUVV  0xfc00707f
#define MATCH_VMINUVX  0x10004057
#define MASK_VMINUVX  0xfc00707f
#define MATCH_VMAXUVV  0x18000057
#define MASK_VMAXUVV  0xfc00707f
#define MATCH_VMAXUVX  0x18004057
#define MASK_VMAXUVX  0xfc00707f
#define MATCH_VMULVV  0x94002057
#define MASK_VMULVV  0xfc00707f
#define MATCH_VMULVX  0x94006057
#define MASK_VMULVX  0xfc00707f
#define MATCH_VMULHVV  0x9c002057
#define MASK_VMULHVV  0xfc00707f
#define MATCH_VMULHVX  0x9c006057
#define MASK_VMULHVX  0xfc00707f
#define MATCH_VMULHUVV  0x90002057
#define MASK_VMULHUVV  0xfc00707f
#define MATCH_VMULHUVX  0x90006057
#define MASK_VMULHUVX  0xfc00707f
#define MATCH_VMULHSUVV  0x98002057
#define MASK_VMULHSUVV  0xfc00707f
#define MATCH_VMULHSUVX  0x98006057
#define MASK_VMULHSUVX  0xfc00707f
#define MATCH_VWMULVV  0xec002057
#define MASK_VWMULVV  0xfc00707f
#define MATCH_VWMULVX  0xec006057
#define MASK_VWMULVX  0xfc00707f
#define MATCH_VWMULUVV  0xe0002057
#define MASK_VWMULUVV  0xfc00707f
#define MATCH_VWMULUVX  0xe0006057
#define MASK_VWMULUVX  0xfc00707f
#define MATCH_VWMULSUVV  0xe8002057
#define MASK_VWMULSUVV  0xfc00707f
#define MATCH_VWMULSUVX  0xe8006057
#define MASK_VWMULSUVX  0xfc00707f
#define MATCH_VMACCVV  0xb4002057
#define MASK_VMACCVV  0xfc00707f
#define MATCH_VMACCVX  0xb4006057
#define MASK_VMACCVX  0xfc00707f
#define MATCH_VNMSACVV  0xbc002057
#define MASK_VNMSACVV  0xfc00707f
#define MATCH_VNMSACVX  0xbc006057
#define MASK_VNMSACVX  0xfc00707f
#define MATCH_VMADDVV  0xa4002057
#define MASK_VMADDVV  0xfc00707f
#define MATCH_VMADDVX  0xa4006057
#define MASK_VMADDVX  0xfc00707f
#define MATCH_VNMSUBVV  0xac002057
#define MASK_VNMSUBVV  0xfc00707f
#define MATCH_VNMSUBVX  0xac006057
#define MASK_VNMSUBVX  0xfc00707f
#define MATCH_VWMACCUVV  0xf0002057
#define MASK_VWMACCUVV  0xfc00707f
#define MATCH_VWMACCUVX  0xf0006057
#define MASK_VWMACCUVX  0xfc00707f
#define MATCH_VWMACCVV  0xf4002057
#define MASK_VWMACCVV  0xfc00707f
#define MATCH_VWMACCVX  0xf4006057
#define MASK_VWMACCVX  0xfc00707f
#define MATCH_VWMACCSUVV 0xfc002057
#define MASK_VWMACCSUVV  0xfc00707f
#define MATCH_VWMACCSUVX 0xfc006057
#define MASK_VWMACCSUVX  0xfc00707f
#define MATCH_VWMACCUSVX 0xf8006057
#define MASK_VWMACCUSVX  0xfc00707f
#define MATCH_VQMACCUVV  0xf0000057
#define MASK_VQMACCUVV  0xfc00707f
#define MATCH_VQMACCUVX  0xf0004057
#define MASK_VQMACCUVX  0xfc00707f
#define MATCH_VQMACCVV  0xf4000057
#define MASK_VQMACCVV  0xfc00707f
#define MATCH_VQMACCVX  0xf4004057
#define MASK_VQMACCVX  0xfc00707f
#define MATCH_VQMACCSUVV 0xfc000057
#define MASK_VQMACCSUVV  0xfc00707f
#define MATCH_VQMACCSUVX 0xfc004057
#define MASK_VQMACCSUVX  0xfc00707f
#define MATCH_VQMACCUSVX 0xf8004057
#define MASK_VQMACCUSVX  0xfc00707f
#define MATCH_VDIVVV  0x84002057
#define MASK_VDIVVV  0xfc00707f
#define MATCH_VDIVVX  0x84006057
#define MASK_VDIVVX  0xfc00707f
#define MATCH_VDIVUVV  0x80002057
#define MASK_VDIVUVV  0xfc00707f
#define MATCH_VDIVUVX  0x80006057
#define MASK_VDIVUVX  0xfc00707f
#define MATCH_VREMVV  0x8c002057
#define MASK_VREMVV  0xfc00707f
#define MATCH_VREMVX  0x8c006057
#define MASK_VREMVX  0xfc00707f
#define MATCH_VREMUVV  0x88002057
#define MASK_VREMUVV  0xfc00707f
#define MATCH_VREMUVX  0x88006057
#define MASK_VREMUVX  0xfc00707f
#define MATCH_VMERGEVVM  0x5c000057
#define MASK_VMERGEVVM  0xfe00707f
#define MATCH_VMERGEVXM  0x5c004057
#define MASK_VMERGEVXM  0xfe00707f
#define MATCH_VMERGEVIM  0x5c003057
#define MASK_VMERGEVIM  0xfe00707f
#define MATCH_VMVVV  0x5e000057
#define MASK_VMVVV  0xfff0707f
#define MATCH_VMVVX  0x5e004057
#define MASK_VMVVX  0xfff0707f
#define MATCH_VMVVI  0x5e003057
#define MASK_VMVVI  0xfff0707f
#define MATCH_VSADDUVV  0x80000057
#define MASK_VSADDUVV  0xfc00707f
#define MATCH_VSADDUVX  0x80004057
#define MASK_VSADDUVX  0xfc00707f
#define MATCH_VSADDUVI  0x80003057
#define MASK_VSADDUVI  0xfc00707f
#define MATCH_VSADDVV  0x84000057
#define MASK_VSADDVV  0xfc00707f
#define MATCH_VSADDVX  0x84004057
#define MASK_VSADDVX  0xfc00707f
#define MATCH_VSADDVI  0x84003057
#define MASK_VSADDVI  0xfc00707f
#define MATCH_VSSUBUVV  0x88000057
#define MASK_VSSUBUVV  0xfc00707f
#define MATCH_VSSUBUVX  0x88004057
#define MASK_VSSUBUVX  0xfc00707f
#define MATCH_VSSUBVV  0x8c000057
#define MASK_VSSUBVV  0xfc00707f
#define MATCH_VSSUBVX  0x8c004057
#define MASK_VSSUBVX  0xfc00707f
#define MATCH_VAADDUVV  0x20002057
#define MASK_VAADDUVV  0xfc00707f
#define MATCH_VAADDUVX  0x20006057
#define MASK_VAADDUVX  0xfc00707f
#define MATCH_VAADDVV  0x24002057
#define MASK_VAADDVV  0xfc00707f
#define MATCH_VAADDVX  0x24006057
#define MASK_VAADDVX  0xfc00707f
#define MATCH_VASUBUVV  0x28002057
#define MASK_VASUBUVV  0xfc00707f
#define MATCH_VASUBUVX  0x28006057
#define MASK_VASUBUVX  0xfc00707f
#define MATCH_VASUBVV  0x2c002057
#define MASK_VASUBVV  0xfc00707f
#define MATCH_VASUBVX  0x2c006057
#define MASK_VASUBVX  0xfc00707f
#define MATCH_VSMULVV  0x9c000057
#define MASK_VSMULVV  0xfc00707f
#define MATCH_VSMULVX  0x9c004057
#define MASK_VSMULVX  0xfc00707f
#define MATCH_VSSRLVV  0xa8000057
#define MASK_VSSRLVV  0xfc00707f
#define MATCH_VSSRLVX  0xa8004057
#define MASK_VSSRLVX  0xfc00707f
#define MATCH_VSSRLVI  0xa8003057
#define MASK_VSSRLVI  0xfc00707f
#define MATCH_VSSRAVV  0xac000057
#define MASK_VSSRAVV  0xfc00707f
#define MATCH_VSSRAVX  0xac004057
#define MASK_VSSRAVX  0xfc00707f
#define MATCH_VSSRAVI  0xac003057
#define MASK_VSSRAVI  0xfc00707f
#define MATCH_VNCLIPUWV  0xb8000057
#define MASK_VNCLIPUWV  0xfc00707f
#define MATCH_VNCLIPUWX  0xb8004057
#define MASK_VNCLIPUWX  0xfc00707f
#define MATCH_VNCLIPUWI  0xb8003057
#define MASK_VNCLIPUWI  0xfc00707f
#define MATCH_VNCLIPWV  0xbc000057
#define MASK_VNCLIPWV  0xfc00707f
#define MATCH_VNCLIPWX  0xbc004057
#define MASK_VNCLIPWX  0xfc00707f
#define MATCH_VNCLIPWI  0xbc003057
#define MASK_VNCLIPWI  0xfc00707f
#define MATCH_VFADDVV  0x00001057
#define MASK_VFADDVV  0xfc00707f
#define MATCH_VFADDVF  0x00005057
#define MASK_VFADDVF  0xfc00707f
#define MATCH_VFSUBVV  0x08001057
#define MASK_VFSUBVV  0xfc00707f
#define MATCH_VFSUBVF  0x08005057
#define MASK_VFSUBVF  0xfc00707f
#define MATCH_VFRSUBVF  0x9c005057
#define MASK_VFRSUBVF  0xfc00707f
#define MATCH_VFWADDVV  0xc0001057
#define MASK_VFWADDVV  0xfc00707f
#define MATCH_VFWADDVF  0xc0005057
#define MASK_VFWADDVF  0xfc00707f
#define MATCH_VFWSUBVV  0xc8001057
#define MASK_VFWSUBVV  0xfc00707f
#define MATCH_VFWSUBVF  0xc8005057
#define MASK_VFWSUBVF  0xfc00707f
#define MATCH_VFWADDWV  0xd0001057
#define MASK_VFWADDWV  0xfc00707f
#define MATCH_VFWADDWF  0xd0005057
#define MASK_VFWADDWF  0xfc00707f
#define MATCH_VFWSUBWV  0xd8001057
#define MASK_VFWSUBWV  0xfc00707f
#define MATCH_VFWSUBWF  0xd8005057
#define MASK_VFWSUBWF  0xfc00707f
#define MATCH_VFMULVV  0x90001057
#define MASK_VFMULVV  0xfc00707f
#define MATCH_VFMULVF  0x90005057
#define MASK_VFMULVF  0xfc00707f
#define MATCH_VFDIVVV  0x80001057
#define MASK_VFDIVVV  0xfc00707f
#define MATCH_VFDIVVF  0x80005057
#define MASK_VFDIVVF  0xfc00707f
#define MATCH_VFRDIVVF  0x84005057
#define MASK_VFRDIVVF  0xfc00707f
#define MATCH_VFWMULVV  0xe0001057
#define MASK_VFWMULVV  0xfc00707f
#define MATCH_VFWMULVF  0xe0005057
#define MASK_VFWMULVF  0xfc00707f
#define MATCH_VFMADDVV  0xa0001057
#define MASK_VFMADDVV  0xfc00707f
#define MATCH_VFMADDVF  0xa0005057
#define MASK_VFMADDVF  0xfc00707f
#define MATCH_VFNMADDVV  0xa4001057
#define MASK_VFNMADDVV  0xfc00707f
#define MATCH_VFNMADDVF  0xa4005057
#define MASK_VFNMADDVF  0xfc00707f
#define MATCH_VFMSUBVV  0xa8001057
#define MASK_VFMSUBVV  0xfc00707f
#define MATCH_VFMSUBVF  0xa8005057
#define MASK_VFMSUBVF  0xfc00707f
#define MATCH_VFNMSUBVV  0xac001057
#define MASK_VFNMSUBVV  0xfc00707f
#define MATCH_VFNMSUBVF  0xac005057
#define MASK_VFNMSUBVF  0xfc00707f
#define MATCH_VFMACCVV  0xb0001057
#define MASK_VFMACCVV  0xfc00707f
#define MATCH_VFMACCVF  0xb0005057
#define MASK_VFMACCVF  0xfc00707f
#define MATCH_VFNMACCVV  0xb4001057
#define MASK_VFNMACCVV  0xfc00707f
#define MATCH_VFNMACCVF  0xb4005057
#define MASK_VFNMACCVF  0xfc00707f
#define MATCH_VFMSACVV  0xb8001057
#define MASK_VFMSACVV  0xfc00707f
#define MATCH_VFMSACVF  0xb8005057
#define MASK_VFMSACVF  0xfc00707f
#define MATCH_VFNMSACVV  0xbc001057
#define MASK_VFNMSACVV  0xfc00707f
#define MATCH_VFNMSACVF  0xbc005057
#define MASK_VFNMSACVF  0xfc00707f
#define MATCH_VFWMACCVV  0xf0001057
#define MASK_VFWMACCVV  0xfc00707f
#define MATCH_VFWMACCVF  0xf0005057
#define MASK_VFWMACCVF  0xfc00707f
#define MATCH_VFWNMACCVV 0xf4001057
#define MASK_VFWNMACCVV  0xfc00707f
#define MATCH_VFWNMACCVF 0xf4005057
#define MASK_VFWNMACCVF  0xfc00707f
#define MATCH_VFWMSACVV  0xf8001057
#define MASK_VFWMSACVV  0xfc00707f
#define MATCH_VFWMSACVF  0xf8005057
#define MASK_VFWMSACVF  0xfc00707f
#define MATCH_VFWNMSACVV 0xfc001057
#define MASK_VFWNMSACVV  0xfc00707f
#define MATCH_VFWNMSACVF 0xfc005057
#define MASK_VFWNMSACVF  0xfc00707f
#define MATCH_VFSQRTV  0x4c001057
#define MASK_VFSQRTV  0xfc0ff07f
#define MATCH_VFRSQRT7V  0x4c021057
#define MASK_VFRSQRT7V  0xfc0ff07f
#define MATCH_VFREC7V  0x4c029057
#define MASK_VFREC7V  0xfc0ff07f
#define MATCH_VFCLASSV  0x4c081057
#define MASK_VFCLASSV  0xfc0ff07f
#define MATCH_VFMINVV  0x10001057
#define MASK_VFMINVV  0xfc00707f
#define MATCH_VFMINVF  0x10005057
#define MASK_VFMINVF  0xfc00707f
#define MATCH_VFMAXVV  0x18001057
#define MASK_VFMAXVV  0xfc00707f
#define MATCH_VFMAXVF  0x18005057
#define MASK_VFMAXVF  0xfc00707f
#define MATCH_VFSGNJVV  0x20001057
#define MASK_VFSGNJVV  0xfc00707f
#define MATCH_VFSGNJVF  0x20005057
#define MASK_VFSGNJVF  0xfc00707f
#define MATCH_VFSGNJNVV  0x24001057
#define MASK_VFSGNJNVV  0xfc00707f
#define MATCH_VFSGNJNVF  0x24005057
#define MASK_VFSGNJNVF  0xfc00707f
#define MATCH_VFSGNJXVV  0x28001057
#define MASK_VFSGNJXVV  0xfc00707f
#define MATCH_VFSGNJXVF  0x28005057
#define MASK_VFSGNJXVF  0xfc00707f
#define MATCH_VMFEQVV  0x60001057
#define MASK_VMFEQVV  0xfc00707f
#define MATCH_VMFEQVF  0x60005057
#define MASK_VMFEQVF  0xfc00707f
#define MATCH_VMFNEVV  0x70001057
#define MASK_VMFNEVV  0xfc00707f
#define MATCH_VMFNEVF  0x70005057
#define MASK_VMFNEVF  0xfc00707f
#define MATCH_VMFLTVV  0x6c001057
#define MASK_VMFLTVV  0xfc00707f
#define MATCH_VMFLTVF  0x6c005057
#define MASK_VMFLTVF  0xfc00707f
#define MATCH_VMFLEVV  0x64001057
#define MASK_VMFLEVV  0xfc00707f
#define MATCH_VMFLEVF  0x64005057
#define MASK_VMFLEVF  0xfc00707f
#define MATCH_VMFGTVF  0x74005057
#define MASK_VMFGTVF  0xfc00707f
#define MATCH_VMFGEVF  0x7c005057
#define MASK_VMFGEVF  0xfc00707f
#define MATCH_VFMERGEVFM 0x5c005057
#define MASK_VFMERGEVFM  0xfe00707f
#define MATCH_VFMVVF  0x5e005057
#define MASK_VFMVVF  0xfff0707f
#define MATCH_VFCVTXUFV  0x48001057
#define MASK_VFCVTXUFV  0xfc0ff07f
#define MATCH_VFCVTXFV  0x48009057
#define MASK_VFCVTXFV  0xfc0ff07f
#define MATCH_VFCVTFXUV  0x48011057
#define MASK_VFCVTFXUV  0xfc0ff07f
#define MATCH_VFCVTFXV  0x48019057
#define MASK_VFCVTFXV  0xfc0ff07f
#define MATCH_VFCVTRTZXUFV 0x48031057
#define MASK_VFCVTRTZXUFV 0xfc0ff07f
#define MATCH_VFCVTRTZXFV 0x48039057
#define MASK_VFCVTRTZXFV 0xfc0ff07f
#define MATCH_VFWCVTXUFV 0x48041057
#define MASK_VFWCVTXUFV  0xfc0ff07f
#define MATCH_VFWCVTXFV  0x48049057
#define MASK_VFWCVTXFV  0xfc0ff07f
#define MATCH_VFWCVTFXUV 0x48051057
#define MASK_VFWCVTFXUV  0xfc0ff07f
#define MATCH_VFWCVTFXV  0x48059057
#define MASK_VFWCVTFXV  0xfc0ff07f
#define MATCH_VFWCVTFFV  0x48061057
#define MASK_VFWCVTFFV  0xfc0ff07f
#define MATCH_VFWCVTRTZXUFV 0x48071057
#define MASK_VFWCVTRTZXUFV 0xfc0ff07f
#define MATCH_VFWCVTRTZXFV 0x48079057
#define MASK_VFWCVTRTZXFV 0xfc0ff07f
#define MATCH_VFNCVTXUFW 0x48081057
#define MASK_VFNCVTXUFW  0xfc0ff07f
#define MATCH_VFNCVTXFW  0x48089057
#define MASK_VFNCVTXFW  0xfc0ff07f
#define MATCH_VFNCVTFXUW 0x48091057
#define MASK_VFNCVTFXUW  0xfc0ff07f
#define MATCH_VFNCVTFXW  0x48099057
#define MASK_VFNCVTFXW  0xfc0ff07f
#define MATCH_VFNCVTFFW  0x480a1057
#define MASK_VFNCVTFFW  0xfc0ff07f
#define MATCH_VFNCVTRODFFW 0x480a9057
#define MASK_VFNCVTRODFFW 0xfc0ff07f
#define MATCH_VFNCVTRTZXUFW 0x480b1057
#define MASK_VFNCVTRTZXUFW 0xfc0ff07f
#define MATCH_VFNCVTRTZXFW 0x480b9057
#define MASK_VFNCVTRTZXFW 0xfc0ff07f
#define MATCH_VREDSUMVS  0x00002057
#define MASK_VREDSUMVS  0xfc00707f
#define MATCH_VREDMAXVS  0x1c002057
#define MASK_VREDMAXVS  0xfc00707f
#define MATCH_VREDMAXUVS 0x18002057
#define MASK_VREDMAXUVS  0xfc00707f
#define MATCH_VREDMINVS  0x14002057
#define MASK_VREDMINVS  0xfc00707f
#define MATCH_VREDMINUVS 0x10002057
#define MASK_VREDMINUVS  0xfc00707f
#define MATCH_VREDANDVS  0x04002057
#define MASK_VREDANDVS  0xfc00707f
#define MATCH_VREDORVS  0x08002057
#define MASK_VREDORVS  0xfc00707f
#define MATCH_VREDXORVS  0x0c002057
#define MASK_VREDXORVS  0xfc00707f
#define MATCH_VWREDSUMUVS 0xc0000057
#define MASK_VWREDSUMUVS 0xfc00707f
#define MATCH_VWREDSUMVS 0xc4000057
#define MASK_VWREDSUMVS  0xfc00707f
#define MATCH_VFREDOSUMVS 0x0c001057
#define MASK_VFREDOSUMVS 0xfc00707f
#define MATCH_VFREDUSUMVS 0x04001057
#define MASK_VFREDUSUMVS 0xfc00707f
#define MATCH_VFREDMAXVS 0x1c001057
#define MASK_VFREDMAXVS  0xfc00707f
#define MATCH_VFREDMINVS 0x14001057
#define MASK_VFREDMINVS  0xfc00707f
#define MATCH_VFWREDOSUMVS 0xcc001057
#define MASK_VFWREDOSUMVS 0xfc00707f
#define MATCH_VFWREDUSUMVS 0xc4001057
#define MASK_VFWREDUSUMVS 0xfc00707f
#define MATCH_VMANDMM  0x66002057
#define MASK_VMANDMM  0xfe00707f
#define MATCH_VMNANDMM  0x76002057
#define MASK_VMNANDMM  0xfe00707f
#define MATCH_VMANDNMM 0x62002057
#define MASK_VMANDNMM  0xfe00707f
#define MATCH_VMXORMM  0x6e002057
#define MASK_VMXORMM  0xfe00707f
#define MATCH_VMORMM  0x6a002057
#define MASK_VMORMM  0xfe00707f
#define MATCH_VMNORMM  0x7a002057
#define MASK_VMNORMM  0xfe00707f
#define MATCH_VMORNMM  0x72002057
#define MASK_VMORNMM  0xfe00707f
#define MATCH_VMXNORMM  0x7e002057
#define MASK_VMXNORMM  0xfe00707f
#define MATCH_VCPOPM  0x40082057
#define MASK_VCPOPM  0xfc0ff07f
#define MATCH_VFIRSTM  0x4008a057
#define MASK_VFIRSTM  0xfc0ff07f
#define MATCH_VMSBFM  0x5000a057
#define MASK_VMSBFM  0xfc0ff07f
#define MATCH_VMSIFM  0x5001a057
#define MASK_VMSIFM  0xfc0ff07f
#define MATCH_VMSOFM  0x50012057
#define MASK_VMSOFM  0xfc0ff07f
#define MATCH_VIOTAM  0x50082057
#define MASK_VIOTAM  0xfc0ff07f
#define MATCH_VIDV  0x5008a057
#define MASK_VIDV  0xfdfff07f
#define MATCH_VMVXS  0x42002057
#define MASK_VMVXS  0xfe0ff07f
#define MATCH_VMVSX  0x42006057
#define MASK_VMVSX  0xfff0707f
#define MATCH_VFMVFS  0x42001057
#define MASK_VFMVFS  0xfe0ff07f
#define MATCH_VFMVSF  0x42005057
#define MASK_VFMVSF  0xfff0707f
#define MATCH_VSLIDEUPVX 0x38004057
#define MASK_VSLIDEUPVX  0xfc00707f
#define MATCH_VSLIDEUPVI 0x38003057
#define MASK_VSLIDEUPVI  0xfc00707f
#define MATCH_VSLIDEDOWNVX 0x3c004057
#define MASK_VSLIDEDOWNVX 0xfc00707f
#define MATCH_VSLIDEDOWNVI 0x3c003057
#define MASK_VSLIDEDOWNVI 0xfc00707f
#define MATCH_VSLIDE1UPVX 0x38006057
#define MASK_VSLIDE1UPVX 0xfc00707f
#define MATCH_VSLIDE1DOWNVX 0x3c006057
#define MASK_VSLIDE1DOWNVX 0xfc00707f
#define MATCH_VFSLIDE1UPVF 0x38005057
#define MASK_VFSLIDE1UPVF 0xfc00707f
#define MATCH_VFSLIDE1DOWNVF 0x3c005057
#define MASK_VFSLIDE1DOWNVF 0xfc00707f
#define MATCH_VRGATHERVV 0x30000057
#define MASK_VRGATHERVV  0xfc00707f
#define MATCH_VRGATHERVX 0x30004057
#define MASK_VRGATHERVX  0xfc00707f
#define MATCH_VRGATHERVI 0x30003057
#define MASK_VRGATHERVI  0xfc00707f
#define MATCH_VRGATHEREI16VV 0x38000057
#define MASK_VRGATHEREI16VV 0xfc00707f
#define MATCH_VCOMPRESSVM 0x5e002057
#define MASK_VCOMPRESSVM 0xfe00707f
#define MATCH_VMV1RV  0x9e003057
#define MASK_VMV1RV  0xfe0ff07f
#define MATCH_VMV2RV  0x9e00b057
#define MASK_VMV2RV  0xfe0ff07f
#define MATCH_VMV4RV  0x9e01b057
#define MASK_VMV4RV  0xfe0ff07f
#define MATCH_VMV8RV  0x9e03b057
#define MASK_VMV8RV  0xfe0ff07f
#define MATCH_VDOTVV  0xe4000057
#define MASK_VDOTVV  0xfc00707f
#define MATCH_VDOTUVV  0xe0000057
#define MASK_VDOTUVV  0xfc00707f
#define MATCH_VFDOTVV  0xe4001057
#define MASK_VFDOTVV  0xfc00707f
/* Svinval instruction.  */
#define MATCH_SINVAL_VMA 0x16000073
#define MASK_SINVAL_VMA 0xfe007fff
#define MATCH_SFENCE_W_INVAL 0x18000073
#define MASK_SFENCE_W_INVAL 0xffffffff
#define MATCH_SFENCE_INVAL_IR 0x18100073
#define MASK_SFENCE_INVAL_IR 0xffffffff
#define MATCH_HINVAL_VVMA 0x26000073
#define MASK_HINVAL_VVMA 0xfe007fff
#define MATCH_HINVAL_GVMA 0x66000073
#define MASK_HINVAL_GVMA 0xfe007fff
/* Hypervisor instruction.  */
#define MATCH_HFENCE_VVMA 0x22000073
#define MASK_HFENCE_VVMA 0xfe007fff
#define MATCH_HFENCE_GVMA 0x62000073
#define MASK_HFENCE_GVMA 0xfe007fff
#define MATCH_HLV_B 0x60004073
#define MASK_HLV_B 0xfff0707f
#define MATCH_HLV_H 0x64004073
#define MASK_HLV_H 0xfff0707f
#define MATCH_HLV_W 0x68004073
#define MASK_HLV_W 0xfff0707f
#define MATCH_HLV_D 0x6c004073
#define MASK_HLV_D 0xfff0707f
#define MATCH_HLV_BU 0x60104073
#define MASK_HLV_BU 0xfff0707f
#define MATCH_HLV_HU 0x64104073
#define MASK_HLV_HU 0xfff0707f
#define MATCH_HLV_WU 0x68104073
#define MASK_HLV_WU 0xfff0707f
#define MATCH_HLVX_HU 0x64304073
#define MASK_HLVX_HU 0xfff0707f
#define MATCH_HLVX_WU 0x68304073
#define MASK_HLVX_WU 0xfff0707f
#define MATCH_HSV_B 0x62004073
#define MASK_HSV_B 0xfe007fff
#define MATCH_HSV_H 0x66004073
#define MASK_HSV_H 0xfe007fff
#define MATCH_HSV_W 0x6a004073
#define MASK_HSV_W 0xfe007fff
#define MATCH_HSV_D 0x6e004073
#define MASK_HSV_D 0xfe007fff
/* Zicbop hint instructions. */
#define MATCH_PREFETCH_I 0x6013
#define MASK_PREFETCH_I 0x1f07fff
#define MATCH_PREFETCH_R 0x106013
#define MASK_PREFETCH_R 0x1f07fff
#define MATCH_PREFETCH_W 0x306013
#define MASK_PREFETCH_W 0x1f07fff
/* Zicbom/Zicboz instructions. */
#define MATCH_CBO_CLEAN 0x10200f
#define MASK_CBO_CLEAN 0xfff07fff
#define MATCH_CBO_FLUSH 0x20200f
#define MASK_CBO_FLUSH 0xfff07fff
#define MATCH_CBO_INVAL 0x200f
#define MASK_CBO_INVAL 0xfff07fff
#define MATCH_CBO_ZERO 0x40200f
#define MASK_CBO_ZERO 0xfff07fff
/* Zawrs intructions.  */
#define MATCH_WRS_NTO 0x00d00073
#define MASK_WRS_NTO 0xffffffff
#define MATCH_WRS_STO 0x01d00073
#define MASK_WRS_STO 0xffffffff
/* Vendor-specific (T-Head) XTheadBa instructions.  */
#define MATCH_TH_ADDSL 0x0000100b
#define MASK_TH_ADDSL 0xf800707f
/* Vendor-specific (T-Head) XTheadBb instructions.  */
#define MATCH_TH_SRRI 0x1000100b
#define MASK_TH_SRRI 0xfc00707f
#define MATCH_TH_SRRIW 0x1400100b
#define MASK_TH_SRRIW 0xfe00707f
#define MATCH_TH_EXT 0x0000200b
#define MASK_TH_EXT 0x0000707f
#define MATCH_TH_EXTU 0x0000300b
#define MASK_TH_EXTU 0x0000707f
#define MATCH_TH_FF0 0x8400100b
#define MASK_TH_FF0 0xfff0707f
#define MATCH_TH_FF1 0x8600100b
#define MASK_TH_FF1 0xfff0707f
#define MATCH_TH_REV 0x8200100b
#define MASK_TH_REV 0xfff0707f
#define MATCH_TH_REVW 0x9000100b
#define MASK_TH_REVW 0xfff0707f
#define MATCH_TH_TSTNBZ 0x8000100b
#define MASK_TH_TSTNBZ 0xfff0707f
/* Vendor-specific (T-Head) XTheadBs instructions.  */
#define MATCH_TH_TST 0x8800100b
#define MASK_TH_TST 0xfc00707f
/* Vendor-specific (T-Head) XTheadCmo instructions.  */
#define MATCH_TH_DCACHE_CALL 0x0010000b
#define MASK_TH_DCACHE_CALL 0xffffffff
#define MATCH_TH_DCACHE_CIALL 0x0030000b
#define MASK_TH_DCACHE_CIALL 0xffffffff
#define MATCH_TH_DCACHE_IALL 0x0020000b
#define MASK_TH_DCACHE_IALL 0xffffffff
#define MATCH_TH_DCACHE_CPA 0x0290000b
#define MASK_TH_DCACHE_CPA 0xfff07fff
#define MATCH_TH_DCACHE_CIPA 0x02b0000b
#define MASK_TH_DCACHE_CIPA 0xfff07fff
#define MATCH_TH_DCACHE_IPA 0x02a0000b
#define MASK_TH_DCACHE_IPA 0xfff07fff
#define MATCH_TH_DCACHE_CVA 0x0250000b
#define MASK_TH_DCACHE_CVA 0xfff07fff
#define MATCH_TH_DCACHE_CIVA 0x0270000b
#define MASK_TH_DCACHE_CIVA 0xfff07fff
#define MATCH_TH_DCACHE_IVA 0x0260000b
#define MASK_TH_DCACHE_IVA 0xfff07fff
#define MATCH_TH_DCACHE_CSW 0x0210000b
#define MASK_TH_DCACHE_CSW 0xfff07fff
#define MATCH_TH_DCACHE_CISW 0x0230000b
#define MASK_TH_DCACHE_CISW 0xfff07fff
#define MATCH_TH_DCACHE_ISW 0x0220000b
#define MASK_TH_DCACHE_ISW 0xfff07fff
#define MATCH_TH_DCACHE_CPAL1 0x0280000b
#define MASK_TH_DCACHE_CPAL1 0xfff07fff
#define MATCH_TH_DCACHE_CVAL1 0x0240000b
#define MASK_TH_DCACHE_CVAL1 0xfff07fff
#define MATCH_TH_ICACHE_IALL 0x0100000b
#define MASK_TH_ICACHE_IALL 0xffffffff
#define MATCH_TH_ICACHE_IALLS 0x0110000b
#define MASK_TH_ICACHE_IALLS 0xffffffff
#define MATCH_TH_ICACHE_IPA 0x0380000b
#define MASK_TH_ICACHE_IPA 0xfff07fff
#define MATCH_TH_ICACHE_IVA 0x0300000b
#define MASK_TH_ICACHE_IVA 0xfff07fff
#define MATCH_TH_L2CACHE_CALL 0x0150000b
#define MASK_TH_L2CACHE_CALL 0xffffffff
#define MATCH_TH_L2CACHE_CIALL 0x0170000b
#define MASK_TH_L2CACHE_CIALL 0xffffffff
#define MATCH_TH_L2CACHE_IALL 0x0160000b
#define MASK_TH_L2CACHE_IALL 0xffffffff
/* Vendor-specific (T-Head) XTheadCondMov instructions.  */
#define MATCH_TH_MVEQZ 0x4000100b
#define MASK_TH_MVEQZ 0xfe00707f
#define MATCH_TH_MVNEZ 0x4200100b
#define MASK_TH_MVNEZ 0xfe00707f
/* Vendor-specific (T-Head) XTheadFMemIdx instructions. */
#define MATCH_TH_FLRD 0x6000600b
#define MASK_TH_FLRD 0xf800707f
#define MATCH_TH_FLRW 0x4000600b
#define MASK_TH_FLRW 0xf800707f
#define MATCH_TH_FLURD 0x7000600b
#define MASK_TH_FLURD 0xf800707f
#define MATCH_TH_FLURW 0x5000600b
#define MASK_TH_FLURW 0xf800707f
#define MATCH_TH_FSRD 0x6000700b
#define MASK_TH_FSRD 0xf800707f
#define MATCH_TH_FSRW 0x4000700b
#define MASK_TH_FSRW 0xf800707f
#define MATCH_TH_FSURD 0x7000700b
#define MASK_TH_FSURD 0xf800707f
#define MATCH_TH_FSURW 0x5000700b
#define MASK_TH_FSURW 0xf800707f
/* Vendor-specific (T-Head) XTheadFmv instructions. */
#define MATCH_TH_FMV_HW_X 0x5000100b
#define MASK_TH_FMV_HW_X 0xfff0707f
#define MATCH_TH_FMV_X_HW 0x6000100b
#define MASK_TH_FMV_X_HW 0xfff0707f
/* Vendor-specific (T-Head) XTheadInt instructions. */
#define MATCH_TH_IPOP 0x0050000b
#define MASK_TH_IPOP 0xffffffff
#define MATCH_TH_IPUSH 0x0040000b
#define MASK_TH_IPUSH 0xffffffff
/* Vendor-specific (T-Head) XTheadMac instructions.  */
#define MATCH_TH_MULA 0x2000100b
#define MASK_TH_MULA 0xfe00707f
#define MATCH_TH_MULAH 0x2800100b
#define MASK_TH_MULAH 0xfe00707f
#define MATCH_TH_MULAW 0x2400100b
#define MASK_TH_MULAW 0xfe00707f
#define MATCH_TH_MULS 0x2200100b
#define MASK_TH_MULS 0xfe00707f
#define MATCH_TH_MULSH 0x2a00100b
#define MASK_TH_MULSH 0xfe00707f
#define MATCH_TH_MULSW 0x2600100b
#define MASK_TH_MULSW 0xfe00707f
/* Vendor-specific (T-Head) XTheadMemPair instructions. */
#define MATCH_TH_LDD 0xf800400b
#define MASK_TH_LDD 0xf800707f
#define MATCH_TH_LWD 0xe000400b
#define MASK_TH_LWD 0xf800707f
#define MATCH_TH_LWUD 0xf000400b
#define MASK_TH_LWUD 0xf800707f
#define MATCH_TH_SDD 0xf800500b
#define MASK_TH_SDD 0xf800707f
#define MATCH_TH_SWD 0xe000500b
#define MASK_TH_SWD 0xf800707f
/* Vendor-specific (T-Head) XTheadMemIdx instructions. */
#define MATCH_TH_LDIA 0x7800400b
#define MASK_TH_LDIA 0xf800707f
#define MATCH_TH_LDIB 0x6800400b
#define MASK_TH_LDIB 0xf800707f
#define MATCH_TH_LWIA 0x5800400b
#define MASK_TH_LWIA 0xf800707f
#define MATCH_TH_LWIB 0x4800400b
#define MASK_TH_LWIB 0xf800707f
#define MATCH_TH_LWUIA 0xd800400b
#define MASK_TH_LWUIA 0xf800707f
#define MATCH_TH_LWUIB 0xc800400b
#define MASK_TH_LWUIB 0xf800707f
#define MATCH_TH_LHIA 0x3800400b
#define MASK_TH_LHIA 0xf800707f
#define MATCH_TH_LHIB 0x2800400b
#define MASK_TH_LHIB 0xf800707f
#define MATCH_TH_LHUIA 0xb800400b
#define MASK_TH_LHUIA 0xf800707f
#define MATCH_TH_LHUIB 0xa800400b
#define MASK_TH_LHUIB 0xf800707f
#define MATCH_TH_LBIA 0x1800400b
#define MASK_TH_LBIA 0xf800707f
#define MATCH_TH_LBIB 0x0800400b
#define MASK_TH_LBIB 0xf800707f
#define MATCH_TH_LBUIA 0x9800400b
#define MASK_TH_LBUIA 0xf800707f
#define MATCH_TH_LBUIB 0x8800400b
#define MASK_TH_LBUIB 0xf800707f
#define MATCH_TH_SDIA 0x7800500b
#define MASK_TH_SDIA 0xf800707f
#define MATCH_TH_SDIB 0x6800500b
#define MASK_TH_SDIB 0xf800707f
#define MATCH_TH_SWIA 0x5800500b
#define MASK_TH_SWIA 0xf800707f
#define MATCH_TH_SWIB 0x4800500b
#define MASK_TH_SWIB 0xf800707f
#define MATCH_TH_SHIA 0x3800500b
#define MASK_TH_SHIA 0xf800707f
#define MATCH_TH_SHIB 0x2800500b
#define MASK_TH_SHIB 0xf800707f
#define MATCH_TH_SBIA 0x1800500b
#define MASK_TH_SBIA 0xf800707f
#define MATCH_TH_SBIB 0x0800500b
#define MASK_TH_SBIB 0xf800707f
#define MATCH_TH_LRD 0x6000400b
#define MASK_TH_LRD 0xf800707f
#define MATCH_TH_LRW 0x4000400b
#define MASK_TH_LRW 0xf800707f
#define MATCH_TH_LRWU 0xc000400b
#define MASK_TH_LRWU 0xf800707f
#define MATCH_TH_LRH 0x2000400b
#define MASK_TH_LRH 0xf800707f
#define MATCH_TH_LRHU 0xa000400b
#define MASK_TH_LRHU 0xf800707f
#define MATCH_TH_LRB 0x0000400b
#define MASK_TH_LRB 0xf800707f
#define MATCH_TH_LRBU 0x8000400b
#define MASK_TH_LRBU 0xf800707f
#define MATCH_TH_SRD 0x6000500b
#define MASK_TH_SRD 0xf800707f
#define MATCH_TH_SRW 0x4000500b
#define MASK_TH_SRW 0xf800707f
#define MATCH_TH_SRH 0x2000500b
#define MASK_TH_SRH 0xf800707f
#define MATCH_TH_SRB 0x0000500b
#define MASK_TH_SRB 0xf800707f
#define MATCH_TH_LURD 0x7000400b
#define MASK_TH_LURD 0xf800707f
#define MATCH_TH_LURW 0x5000400b
#define MASK_TH_LURW 0xf800707f
#define MATCH_TH_LURWU 0xd000400b
#define MASK_TH_LURWU 0xf800707f
#define MATCH_TH_LURH 0x3000400b
#define MASK_TH_LURH 0xf800707f
#define MATCH_TH_LURHU 0xb000400b
#define MASK_TH_LURHU 0xf800707f
#define MATCH_TH_LURB 0x1000400b
#define MASK_TH_LURB 0xf800707f
#define MATCH_TH_LURBU 0x9000400b
#define MASK_TH_LURBU 0xf800707f
#define MATCH_TH_SURD 0x7000500b
#define MASK_TH_SURD 0xf800707f
#define MATCH_TH_SURW 0x5000500b
#define MASK_TH_SURW 0xf800707f
#define MATCH_TH_SURH 0x3000500b
#define MASK_TH_SURH 0xf800707f
#define MATCH_TH_SURB 0x1000500b
#define MASK_TH_SURB 0xf800707f
/* Vendor-specific (T-Head) XTheadSync instructions.  */
#define MATCH_TH_SFENCE_VMAS 0x0400000b
#define MASK_TH_SFENCE_VMAS 0xfe007fff
#define MATCH_TH_SYNC 0x0180000b
#define MASK_TH_SYNC 0xffffffff
#define MATCH_TH_SYNC_I 0x01a0000b
#define MASK_TH_SYNC_I 0xffffffff
#define MATCH_TH_SYNC_IS 0x01b0000b
#define MASK_TH_SYNC_IS 0xffffffff
#define MATCH_TH_SYNC_S 0x0190000b
#define MASK_TH_SYNC_S 0xffffffff
/* Vendor-specific (Ventana Microsystems) XVentanaCondOps instructions */
#define MATCH_VT_MASKC 0x607b
#define MASK_VT_MASKC 0xfe00707f
#define MATCH_VT_MASKCN 0x707b
#define MASK_VT_MASKCN 0xfe00707f
/* Unprivileged Counter/Timers CSR addresses.  */
#define CSR_CYCLE 0xc00
#define CSR_TIME 0xc01
#define CSR_INSTRET 0xc02
#define CSR_HPMCOUNTER3 0xc03
#define CSR_HPMCOUNTER4 0xc04
#define CSR_HPMCOUNTER5 0xc05
#define CSR_HPMCOUNTER6 0xc06
#define CSR_HPMCOUNTER7 0xc07
#define CSR_HPMCOUNTER8 0xc08
#define CSR_HPMCOUNTER9 0xc09
#define CSR_HPMCOUNTER10 0xc0a
#define CSR_HPMCOUNTER11 0xc0b
#define CSR_HPMCOUNTER12 0xc0c
#define CSR_HPMCOUNTER13 0xc0d
#define CSR_HPMCOUNTER14 0xc0e
#define CSR_HPMCOUNTER15 0xc0f
#define CSR_HPMCOUNTER16 0xc10
#define CSR_HPMCOUNTER17 0xc11
#define CSR_HPMCOUNTER18 0xc12
#define CSR_HPMCOUNTER19 0xc13
#define CSR_HPMCOUNTER20 0xc14
#define CSR_HPMCOUNTER21 0xc15
#define CSR_HPMCOUNTER22 0xc16
#define CSR_HPMCOUNTER23 0xc17
#define CSR_HPMCOUNTER24 0xc18
#define CSR_HPMCOUNTER25 0xc19
#define CSR_HPMCOUNTER26 0xc1a
#define CSR_HPMCOUNTER27 0xc1b
#define CSR_HPMCOUNTER28 0xc1c
#define CSR_HPMCOUNTER29 0xc1d
#define CSR_HPMCOUNTER30 0xc1e
#define CSR_HPMCOUNTER31 0xc1f
#define CSR_CYCLEH 0xc80
#define CSR_TIMEH 0xc81
#define CSR_INSTRETH 0xc82
#define CSR_HPMCOUNTER3H 0xc83
#define CSR_HPMCOUNTER4H 0xc84
#define CSR_HPMCOUNTER5H 0xc85
#define CSR_HPMCOUNTER6H 0xc86
#define CSR_HPMCOUNTER7H 0xc87
#define CSR_HPMCOUNTER8H 0xc88
#define CSR_HPMCOUNTER9H 0xc89
#define CSR_HPMCOUNTER10H 0xc8a
#define CSR_HPMCOUNTER11H 0xc8b
#define CSR_HPMCOUNTER12H 0xc8c
#define CSR_HPMCOUNTER13H 0xc8d
#define CSR_HPMCOUNTER14H 0xc8e
#define CSR_HPMCOUNTER15H 0xc8f
#define CSR_HPMCOUNTER16H 0xc90
#define CSR_HPMCOUNTER17H 0xc91
#define CSR_HPMCOUNTER18H 0xc92
#define CSR_HPMCOUNTER19H 0xc93
#define CSR_HPMCOUNTER20H 0xc94
#define CSR_HPMCOUNTER21H 0xc95
#define CSR_HPMCOUNTER22H 0xc96
#define CSR_HPMCOUNTER23H 0xc97
#define CSR_HPMCOUNTER24H 0xc98
#define CSR_HPMCOUNTER25H 0xc99
#define CSR_HPMCOUNTER26H 0xc9a
#define CSR_HPMCOUNTER27H 0xc9b
#define CSR_HPMCOUNTER28H 0xc9c
#define CSR_HPMCOUNTER29H 0xc9d
#define CSR_HPMCOUNTER30H 0xc9e
#define CSR_HPMCOUNTER31H 0xc9f
/* Privileged Supervisor CSR addresses.  */
#define CSR_SSTATUS 0x100
#define CSR_SIE 0x104
#define CSR_STVEC 0x105
#define CSR_SCOUNTEREN 0x106
#define CSR_SENVCFG 0x10a
#define CSR_SSCRATCH 0x140
#define CSR_SEPC 0x141
#define CSR_SCAUSE 0x142
#define CSR_STVAL 0x143
#define CSR_SIP 0x144
#define CSR_SATP 0x180
/* Privileged Machine CSR addresses. */
#define CSR_MVENDORID 0xf11
#define CSR_MARCHID 0xf12
#define CSR_MIMPID 0xf13
#define CSR_MHARTID 0xf14
#define CSR_MCONFIGPTR 0xf15
#define CSR_MSTATUS 0x300
#define CSR_MISA 0x301
#define CSR_MEDELEG 0x302
#define CSR_MIDELEG 0x303
#define CSR_MIE 0x304
#define CSR_MTVEC 0x305
#define CSR_MCOUNTEREN 0x306
#define CSR_MSTATUSH 0x310
#define CSR_MSCRATCH 0x340
#define CSR_MEPC 0x341
#define CSR_MCAUSE 0x342
#define CSR_MTVAL 0x343
#define CSR_MIP 0x344
#define CSR_MTINST 0x34a
#define CSR_MTVAL2 0x34b
#define CSR_MENVCFG 0x30a
#define CSR_MENVCFGH 0x31a
#define CSR_MSECCFG 0x747
#define CSR_MSECCFGH 0x757
#define CSR_PMPCFG0 0x3a0
#define CSR_PMPCFG1 0x3a1
#define CSR_PMPCFG2 0x3a2
#define CSR_PMPCFG3 0x3a3
#define CSR_PMPCFG4 0x3a4
#define CSR_PMPCFG5 0x3a5
#define CSR_PMPCFG6 0x3a6
#define CSR_PMPCFG7 0x3a7
#define CSR_PMPCFG8 0x3a8
#define CSR_PMPCFG9 0x3a9
#define CSR_PMPCFG10 0x3aa
#define CSR_PMPCFG11 0x3ab
#define CSR_PMPCFG12 0x3ac
#define CSR_PMPCFG13 0x3ad
#define CSR_PMPCFG14 0x3ae
#define CSR_PMPCFG15 0x3af
#define CSR_PMPADDR0 0x3b0
#define CSR_PMPADDR1 0x3b1
#define CSR_PMPADDR2 0x3b2
#define CSR_PMPADDR3 0x3b3
#define CSR_PMPADDR4 0x3b4
#define CSR_PMPADDR5 0x3b5
#define CSR_PMPADDR6 0x3b6
#define CSR_PMPADDR7 0x3b7
#define CSR_PMPADDR8 0x3b8
#define CSR_PMPADDR9 0x3b9
#define CSR_PMPADDR10 0x3ba
#define CSR_PMPADDR11 0x3bb
#define CSR_PMPADDR12 0x3bc
#define CSR_PMPADDR13 0x3bd
#define CSR_PMPADDR14 0x3be
#define CSR_PMPADDR15 0x3bf
#define CSR_PMPADDR16 0x3c0
#define CSR_PMPADDR17 0x3c1
#define CSR_PMPADDR18 0x3c2
#define CSR_PMPADDR19 0x3c3
#define CSR_PMPADDR20 0x3c4
#define CSR_PMPADDR21 0x3c5
#define CSR_PMPADDR22 0x3c6
#define CSR_PMPADDR23 0x3c7
#define CSR_PMPADDR24 0x3c8
#define CSR_PMPADDR25 0x3c9
#define CSR_PMPADDR26 0x3ca
#define CSR_PMPADDR27 0x3cb
#define CSR_PMPADDR28 0x3cc
#define CSR_PMPADDR29 0x3cd
#define CSR_PMPADDR30 0x3ce
#define CSR_PMPADDR31 0x3cf
#define CSR_PMPADDR32 0x3d0
#define CSR_PMPADDR33 0x3d1
#define CSR_PMPADDR34 0x3d2
#define CSR_PMPADDR35 0x3d3
#define CSR_PMPADDR36 0x3d4
#define CSR_PMPADDR37 0x3d5
#define CSR_PMPADDR38 0x3d6
#define CSR_PMPADDR39 0x3d7
#define CSR_PMPADDR40 0x3d8
#define CSR_PMPADDR41 0x3d9
#define CSR_PMPADDR42 0x3da
#define CSR_PMPADDR43 0x3db
#define CSR_PMPADDR44 0x3dc
#define CSR_PMPADDR45 0x3dd
#define CSR_PMPADDR46 0x3de
#define CSR_PMPADDR47 0x3df
#define CSR_PMPADDR48 0x3e0
#define CSR_PMPADDR49 0x3e1
#define CSR_PMPADDR50 0x3e2
#define CSR_PMPADDR51 0x3e3
#define CSR_PMPADDR52 0x3e4
#define CSR_PMPADDR53 0x3e5
#define CSR_PMPADDR54 0x3e6
#define CSR_PMPADDR55 0x3e7
#define CSR_PMPADDR56 0x3e8
#define CSR_PMPADDR57 0x3e9
#define CSR_PMPADDR58 0x3ea
#define CSR_PMPADDR59 0x3eb
#define CSR_PMPADDR60 0x3ec
#define CSR_PMPADDR61 0x3ed
#define CSR_PMPADDR62 0x3ee
#define CSR_PMPADDR63 0x3ef
#define CSR_MCYCLE 0xb00
#define CSR_MINSTRET 0xb02
#define CSR_MHPMCOUNTER3 0xb03
#define CSR_MHPMCOUNTER4 0xb04
#define CSR_MHPMCOUNTER5 0xb05
#define CSR_MHPMCOUNTER6 0xb06
#define CSR_MHPMCOUNTER7 0xb07
#define CSR_MHPMCOUNTER8 0xb08
#define CSR_MHPMCOUNTER9 0xb09
#define CSR_MHPMCOUNTER10 0xb0a
#define CSR_MHPMCOUNTER11 0xb0b
#define CSR_MHPMCOUNTER12 0xb0c
#define CSR_MHPMCOUNTER13 0xb0d
#define CSR_MHPMCOUNTER14 0xb0e
#define CSR_MHPMCOUNTER15 0xb0f
#define CSR_MHPMCOUNTER16 0xb10
#define CSR_MHPMCOUNTER17 0xb11
#define CSR_MHPMCOUNTER18 0xb12
#define CSR_MHPMCOUNTER19 0xb13
#define CSR_MHPMCOUNTER20 0xb14
#define CSR_MHPMCOUNTER21 0xb15
#define CSR_MHPMCOUNTER22 0xb16
#define CSR_MHPMCOUNTER23 0xb17
#define CSR_MHPMCOUNTER24 0xb18
#define CSR_MHPMCOUNTER25 0xb19
#define CSR_MHPMCOUNTER26 0xb1a
#define CSR_MHPMCOUNTER27 0xb1b
#define CSR_MHPMCOUNTER28 0xb1c
#define CSR_MHPMCOUNTER29 0xb1d
#define CSR_MHPMCOUNTER30 0xb1e
#define CSR_MHPMCOUNTER31 0xb1f
#define CSR_MCYCLEH 0xb80
#define CSR_MINSTRETH 0xb82
#define CSR_MHPMCOUNTER3H 0xb83
#define CSR_MHPMCOUNTER4H 0xb84
#define CSR_MHPMCOUNTER5H 0xb85
#define CSR_MHPMCOUNTER6H 0xb86
#define CSR_MHPMCOUNTER7H 0xb87
#define CSR_MHPMCOUNTER8H 0xb88
#define CSR_MHPMCOUNTER9H 0xb89
#define CSR_MHPMCOUNTER10H 0xb8a
#define CSR_MHPMCOUNTER11H 0xb8b
#define CSR_MHPMCOUNTER12H 0xb8c
#define CSR_MHPMCOUNTER13H 0xb8d
#define CSR_MHPMCOUNTER14H 0xb8e
#define CSR_MHPMCOUNTER15H 0xb8f
#define CSR_MHPMCOUNTER16H 0xb90
#define CSR_MHPMCOUNTER17H 0xb91
#define CSR_MHPMCOUNTER18H 0xb92
#define CSR_MHPMCOUNTER19H 0xb93
#define CSR_MHPMCOUNTER20H 0xb94
#define CSR_MHPMCOUNTER21H 0xb95
#define CSR_MHPMCOUNTER22H 0xb96
#define CSR_MHPMCOUNTER23H 0xb97
#define CSR_MHPMCOUNTER24H 0xb98
#define CSR_MHPMCOUNTER25H 0xb99
#define CSR_MHPMCOUNTER26H 0xb9a
#define CSR_MHPMCOUNTER27H 0xb9b
#define CSR_MHPMCOUNTER28H 0xb9c
#define CSR_MHPMCOUNTER29H 0xb9d
#define CSR_MHPMCOUNTER30H 0xb9e
#define CSR_MHPMCOUNTER31H 0xb9f
#define CSR_MCOUNTINHIBIT 0x320
#define CSR_MHPMEVENT3 0x323
#define CSR_MHPMEVENT4 0x324
#define CSR_MHPMEVENT5 0x325
#define CSR_MHPMEVENT6 0x326
#define CSR_MHPMEVENT7 0x327
#define CSR_MHPMEVENT8 0x328
#define CSR_MHPMEVENT9 0x329
#define CSR_MHPMEVENT10 0x32a
#define CSR_MHPMEVENT11 0x32b
#define CSR_MHPMEVENT12 0x32c
#define CSR_MHPMEVENT13 0x32d
#define CSR_MHPMEVENT14 0x32e
#define CSR_MHPMEVENT15 0x32f
#define CSR_MHPMEVENT16 0x330
#define CSR_MHPMEVENT17 0x331
#define CSR_MHPMEVENT18 0x332
#define CSR_MHPMEVENT19 0x333
#define CSR_MHPMEVENT20 0x334
#define CSR_MHPMEVENT21 0x335
#define CSR_MHPMEVENT22 0x336
#define CSR_MHPMEVENT23 0x337
#define CSR_MHPMEVENT24 0x338
#define CSR_MHPMEVENT25 0x339
#define CSR_MHPMEVENT26 0x33a
#define CSR_MHPMEVENT27 0x33b
#define CSR_MHPMEVENT28 0x33c
#define CSR_MHPMEVENT29 0x33d
#define CSR_MHPMEVENT30 0x33e
#define CSR_MHPMEVENT31 0x33f
/* Privileged Hypervisor CSR addresses. */
#define CSR_HSTATUS 0x600
#define CSR_HEDELEG 0x602
#define CSR_HIDELEG 0x603
#define CSR_HIE 0x604
#define CSR_HCOUNTEREN 0x606
#define CSR_HGEIE 0x607
#define CSR_HTVAL 0x643
#define CSR_HIP 0x644
#define CSR_HVIP 0x645
#define CSR_HTINST 0x64a
#define CSR_HGEIP 0xe12
#define CSR_HENVCFG 0x60a
#define CSR_HENVCFGH 0x61a
#define CSR_HGATP 0x680
#define CSR_HTIMEDELTA 0x605
#define CSR_HTIMEDELTAH 0x615
#define CSR_VSSTATUS 0x200
#define CSR_VSIE 0x204
#define CSR_VSTVEC 0x205
#define CSR_VSSCRATCH 0x240
#define CSR_VSEPC 0x241
#define CSR_VSCAUSE 0x242
#define CSR_VSTVAL 0x243
#define CSR_VSIP 0x244
#define CSR_VSATP 0x280
/* Droppped CSR addresses.  */
#define CSR_MBASE 0x380
#define CSR_MBOUND 0x381
#define CSR_MIBASE 0x382
#define CSR_MIBOUND 0x383
#define CSR_MDBASE 0x384
#define CSR_MDBOUND 0x385
#define CSR_MSCOUNTEREN 0x321
#define CSR_MHCOUNTEREN 0x322
#define CSR_USTATUS 0x0
#define CSR_UIE 0x4
#define CSR_UTVEC 0x5
#define CSR_USCRATCH 0x40
#define CSR_UEPC 0x41
#define CSR_UCAUSE 0x42
#define CSR_UTVAL 0x43
#define CSR_UIP 0x44
#define CSR_SEDELEG 0x102
#define CSR_SIDELEG 0x103
/* Smaia extension */
#define CSR_MISELECT 0x350
#define CSR_MIREG    0x351
#define CSR_MTOPEI   0x35c
#define CSR_MTOPI    0xfb0
#define CSR_MVIEN    0x308
#define CSR_MVIP     0x309
#define CSR_MIDELEGH 0x313
#define CSR_MIEH     0x314
#define CSR_MVIENH   0x318
#define CSR_MVIPH    0x319
#define CSR_MIPH     0x354
/* Smstateen extension */
#define CSR_MSTATEEN0 0x30c
#define CSR_MSTATEEN1 0x30d
#define CSR_MSTATEEN2 0x30e
#define CSR_MSTATEEN3 0x30f
#define CSR_SSTATEEN0 0x10c
#define CSR_SSTATEEN1 0x10d
#define CSR_SSTATEEN2 0x10e
#define CSR_SSTATEEN3 0x10f
#define CSR_HSTATEEN0 0x60c
#define CSR_HSTATEEN1 0x60d
#define CSR_HSTATEEN2 0x60e
#define CSR_HSTATEEN3 0x60f
#define CSR_MSTATEEN0H 0x31c
#define CSR_MSTATEEN1H 0x31d
#define CSR_MSTATEEN2H 0x31e
#define CSR_MSTATEEN3H 0x31f
#define CSR_HSTATEEN0H 0x61c
#define CSR_HSTATEEN1H 0x61d
#define CSR_HSTATEEN2H 0x61e
#define CSR_HSTATEEN3H 0x61f
/* Ssaia extension */
#define CSR_SISELECT 0x150
#define CSR_SIREG    0x151
#define CSR_STOPEI   0x15c
#define CSR_STOPI    0xdb0
#define CSR_SIEH     0x114
#define CSR_SIPH     0x154
#define CSR_HVIEN     0x608
#define CSR_HVICTL    0x609
#define CSR_HVIPRIO1  0x646
#define CSR_HVIPRIO2  0x647
#define CSR_VSISELECT 0x250
#define CSR_VSIREG    0x251
#define CSR_VSTOPEI   0x25c
#define CSR_VSTOPI    0xeb0
#define CSR_HIDELEGH  0x613
#define CSR_HVIENH    0x618
#define CSR_HVIPH     0x655
#define CSR_HVIPRIO1H 0x656
#define CSR_HVIPRIO2H 0x657
#define CSR_VSIEH     0x214
#define CSR_VSIPH     0x254
/* Sscofpmf extension */
#define CSR_SCOUNTOVF 0xda0
#define CSR_MHPMEVENT3H 0x723
#define CSR_MHPMEVENT4H 0x724
#define CSR_MHPMEVENT5H 0x725
#define CSR_MHPMEVENT6H 0x726
#define CSR_MHPMEVENT7H 0x727
#define CSR_MHPMEVENT8H 0x728
#define CSR_MHPMEVENT9H 0x729
#define CSR_MHPMEVENT10H 0x72a
#define CSR_MHPMEVENT11H 0x72b
#define CSR_MHPMEVENT12H 0x72c
#define CSR_MHPMEVENT13H 0x72d
#define CSR_MHPMEVENT14H 0x72e
#define CSR_MHPMEVENT15H 0x72f
#define CSR_MHPMEVENT16H 0x730
#define CSR_MHPMEVENT17H 0x731
#define CSR_MHPMEVENT18H 0x732
#define CSR_MHPMEVENT19H 0x733
#define CSR_MHPMEVENT20H 0x734
#define CSR_MHPMEVENT21H 0x735
#define CSR_MHPMEVENT22H 0x736
#define CSR_MHPMEVENT23H 0x737
#define CSR_MHPMEVENT24H 0x738
#define CSR_MHPMEVENT25H 0x739
#define CSR_MHPMEVENT26H 0x73a
#define CSR_MHPMEVENT27H 0x73b
#define CSR_MHPMEVENT28H 0x73c
#define CSR_MHPMEVENT29H 0x73d
#define CSR_MHPMEVENT30H 0x73e
#define CSR_MHPMEVENT31H 0x73f
/* Sstc extension */
#define CSR_STIMECMP 0x14d
#define CSR_STIMECMPH 0x15d
#define CSR_VSTIMECMP 0x24d
#define CSR_VSTIMECMPH 0x25d
/* Unprivileged Floating-Point CSR addresses.  */
#define CSR_FFLAGS 0x1
#define CSR_FRM 0x2
#define CSR_FCSR 0x3
/* Unprivileged Debug CSR addresses.  */
#define CSR_DCSR 0x7b0
#define CSR_DPC 0x7b1
#define CSR_DSCRATCH0 0x7b2
#define CSR_DSCRATCH1 0x7b3
#define CSR_TSELECT 0x7a0
#define CSR_TDATA1 0x7a1
#define CSR_TDATA2 0x7a2
#define CSR_TDATA3 0x7a3
#define CSR_TINFO 0x7a4
#define CSR_TCONTROL 0x7a5
#define CSR_HCONTEXT 0x6a8
#define CSR_SCONTEXT 0x5a8
#define CSR_MCONTEXT 0x7a8
#define CSR_MSCONTEXT 0x7aa
/* Unprivileged Scalar Crypto CSR addresses.  */
#define CSR_SEED 0x015
/* Unprivileged Vector CSR addresses.  */
#define CSR_VSTART 0x008
#define CSR_VXSAT 0x009
#define CSR_VXRM 0x00a
#define CSR_VCSR 0x00f
#define CSR_VL 0xc20
#define CSR_VTYPE 0xc21
#define CSR_VLENB 0xc22
#endif /* RISCV_ENCODING_H */
typedef uint64_t insn_t;

static inline unsigned int riscv_insn_length (insn_t insn)
{
  if ((insn & 0x3) != 0x3) /* RVC instructions.  */
    return 2;
  if ((insn & 0x1f) != 0x1f) /* 32-bit instructions.  */
    return 4;
  if ((insn & 0x3f) == 0x1f) /* 48-bit instructions.  */
    return 6;
  if ((insn & 0x7f) == 0x3f) /* 64-bit instructions.  */
    return 8;
  /* 80- ... 176-bit instructions.  */
  if ((insn & 0x7f) == 0x7f && (insn & 0x7000) != 0x7000)
    return 10 + ((insn >> 11) & 0xe);
  /* Maximum value returned by this function.  */
#define RISCV_MAX_INSN_LEN 22
  /* Longer instructions not supported at the moment.  */
  return 2;
}

#define RVC_JUMP_BITS 11
#define RVC_JUMP_REACH ((1ULL << RVC_JUMP_BITS) * RISCV_JUMP_ALIGN)

#define RVC_BRANCH_BITS 8
#define RVC_BRANCH_REACH ((1ULL << RVC_BRANCH_BITS) * RISCV_BRANCH_ALIGN)

#define RV_X(x, s, n)  (((x) >> (s)) & ((1 << (n)) - 1))
#define RV_IMM_SIGN(x) (-(((x) >> 31) & 1))
#define RV_X_SIGNED(x, s, n) (RV_X(x, s, n) | ((-(RV_X(x, (s + n - 1), 1))) << (n)))

#define EXTRACT_ITYPE_IMM(x) \
  (RV_X(x, 20, 12) | (RV_IMM_SIGN(x) << 12))
#define EXTRACT_STYPE_IMM(x) \
  (RV_X(x, 7, 5) | (RV_X(x, 25, 7) << 5) | (RV_IMM_SIGN(x) << 12))
#define EXTRACT_BTYPE_IMM(x) \
  ((RV_X(x, 8, 4) << 1) | (RV_X(x, 25, 6) << 5) | (RV_X(x, 7, 1) << 11) | (RV_IMM_SIGN(x) << 12))
#define EXTRACT_UTYPE_IMM(x) \
  ((RV_X(x, 12, 20) << 12) | (RV_IMM_SIGN(x) << 32))
#define EXTRACT_JTYPE_IMM(x) \
  ((RV_X(x, 21, 10) << 1) | (RV_X(x, 20, 1) << 11) | (RV_X(x, 12, 8) << 12) | (RV_IMM_SIGN(x) << 20))
#define EXTRACT_CITYPE_IMM(x) \
  (RV_X(x, 2, 5) | (-RV_X(x, 12, 1) << 5))
#define EXTRACT_CITYPE_LUI_IMM(x) \
  (EXTRACT_CITYPE_IMM (x) << RISCV_IMM_BITS)
#define EXTRACT_CITYPE_ADDI16SP_IMM(x) \
  ((RV_X(x, 6, 1) << 4) | (RV_X(x, 2, 1) << 5) | (RV_X(x, 5, 1) << 6) | (RV_X(x, 3, 2) << 7) | (-RV_X(x, 12, 1) << 9))
#define EXTRACT_CITYPE_LWSP_IMM(x) \
  ((RV_X(x, 4, 3) << 2) | (RV_X(x, 12, 1) << 5) | (RV_X(x, 2, 2) << 6))
#define EXTRACT_CITYPE_LDSP_IMM(x) \
  ((RV_X(x, 5, 2) << 3) | (RV_X(x, 12, 1) << 5) | (RV_X(x, 2, 3) << 6))
#define EXTRACT_CSSTYPE_IMM(x) \
  (RV_X(x, 7, 6) << 0)
#define EXTRACT_CSSTYPE_SWSP_IMM(x) \
  ((RV_X(x, 9, 4) << 2) | (RV_X(x, 7, 2) << 6))
#define EXTRACT_CSSTYPE_SDSP_IMM(x) \
  ((RV_X(x, 10, 3) << 3) | (RV_X(x, 7, 3) << 6))
#define EXTRACT_CIWTYPE_IMM(x) \
  (RV_X(x, 5, 8))
#define EXTRACT_CIWTYPE_ADDI4SPN_IMM(x) \
  ((RV_X(x, 6, 1) << 2) | (RV_X(x, 5, 1) << 3) | (RV_X(x, 11, 2) << 4) | (RV_X(x, 7, 4) << 6))
#define EXTRACT_CLTYPE_IMM(x) \
  ((RV_X(x, 5, 2) << 0) | (RV_X(x, 10, 3) << 2))
#define EXTRACT_CLTYPE_LW_IMM(x) \
  ((RV_X(x, 6, 1) << 2) | (RV_X(x, 10, 3) << 3) | (RV_X(x, 5, 1) << 6))
#define EXTRACT_CLTYPE_LD_IMM(x) \
  ((RV_X(x, 10, 3) << 3) | (RV_X(x, 5, 2) << 6))
#define EXTRACT_CBTYPE_IMM(x) \
  ((RV_X(x, 3, 2) << 1) | (RV_X(x, 10, 2) << 3) | (RV_X(x, 2, 1) << 5) | (RV_X(x, 5, 2) << 6) | (-RV_X(x, 12, 1) << 8))
#define EXTRACT_CJTYPE_IMM(x) \
  ((RV_X(x, 3, 3) << 1) | (RV_X(x, 11, 1) << 4) | (RV_X(x, 2, 1) << 5) | (RV_X(x, 7, 1) << 6) | (RV_X(x, 6, 1) << 7) | (RV_X(x, 9, 2) << 8) | (RV_X(x, 8, 1) << 10) | (-RV_X(x, 12, 1) << 11))
#define EXTRACT_RVV_VI_IMM(x) \
  (RV_X(x, 15, 5) | (-RV_X(x, 19, 1) << 5))
#define EXTRACT_RVV_VI_UIMM(x) \
  (RV_X(x, 15, 5))
#define EXTRACT_RVV_OFFSET(x) \
  (RV_X(x, 29, 3))
#define EXTRACT_RVV_VB_IMM(x) \
  (RV_X(x, 20, 10))
#define EXTRACT_RVV_VC_IMM(x) \
  (RV_X(x, 20, 11))

#define ENCODE_ITYPE_IMM(x) \
  (RV_X(x, 0, 12) << 20)
#define ENCODE_STYPE_IMM(x) \
  ((RV_X(x, 0, 5) << 7) | (RV_X(x, 5, 7) << 25))
#define ENCODE_BTYPE_IMM(x) \
  ((RV_X(x, 1, 4) << 8) | (RV_X(x, 5, 6) << 25) | (RV_X(x, 11, 1) << 7) | (RV_X(x, 12, 1) << 31))
#define ENCODE_UTYPE_IMM(x) \
  (RV_X(x, 12, 20) << 12)
#define ENCODE_JTYPE_IMM(x) \
  ((RV_X(x, 1, 10) << 21) | (RV_X(x, 11, 1) << 20) | (RV_X(x, 12, 8) << 12) | (RV_X(x, 20, 1) << 31))
#define ENCODE_CITYPE_IMM(x) \
  ((RV_X(x, 0, 5) << 2) | (RV_X(x, 5, 1) << 12))
#define ENCODE_CITYPE_LUI_IMM(x) \
  ENCODE_CITYPE_IMM ((x) >> RISCV_IMM_BITS)
#define ENCODE_CITYPE_ADDI16SP_IMM(x) \
  ((RV_X(x, 4, 1) << 6) | (RV_X(x, 5, 1) << 2) | (RV_X(x, 6, 1) << 5) | (RV_X(x, 7, 2) << 3) | (RV_X(x, 9, 1) << 12))
#define ENCODE_CITYPE_LWSP_IMM(x) \
  ((RV_X(x, 2, 3) << 4) | (RV_X(x, 5, 1) << 12) | (RV_X(x, 6, 2) << 2))
#define ENCODE_CITYPE_LDSP_IMM(x) \
  ((RV_X(x, 3, 2) << 5) | (RV_X(x, 5, 1) << 12) | (RV_X(x, 6, 3) << 2))
#define ENCODE_CSSTYPE_IMM(x) \
  (RV_X(x, 0, 6) << 7)
#define ENCODE_CSSTYPE_SWSP_IMM(x) \
  ((RV_X(x, 2, 4) << 9) | (RV_X(x, 6, 2) << 7))
#define ENCODE_CSSTYPE_SDSP_IMM(x) \
  ((RV_X(x, 3, 3) << 10) | (RV_X(x, 6, 3) << 7))
#define ENCODE_CIWTYPE_IMM(x) \
  (RV_X(x, 0, 8) << 5)
#define ENCODE_CIWTYPE_ADDI4SPN_IMM(x) \
  ((RV_X(x, 2, 1) << 6) | (RV_X(x, 3, 1) << 5) | (RV_X(x, 4, 2) << 11) | (RV_X(x, 6, 4) << 7))
#define ENCODE_CLTYPE_IMM(x) \
  ((RV_X(x, 0, 2) << 5) | (RV_X(x, 2, 3) << 10))
#define ENCODE_CLTYPE_LW_IMM(x) \
  ((RV_X(x, 2, 1) << 6) | (RV_X(x, 3, 3) << 10) | (RV_X(x, 6, 1) << 5))
#define ENCODE_CLTYPE_LD_IMM(x) \
  ((RV_X(x, 3, 3) << 10) | (RV_X(x, 6, 2) << 5))
#define ENCODE_CBTYPE_IMM(x) \
  ((RV_X(x, 1, 2) << 3) | (RV_X(x, 3, 2) << 10) | (RV_X(x, 5, 1) << 2) | (RV_X(x, 6, 2) << 5) | (RV_X(x, 8, 1) << 12))
#define ENCODE_CJTYPE_IMM(x) \
  ((RV_X(x, 1, 3) << 3) | (RV_X(x, 4, 1) << 11) | (RV_X(x, 5, 1) << 2) | (RV_X(x, 6, 1) << 7) | (RV_X(x, 7, 1) << 6) | (RV_X(x, 8, 2) << 9) | (RV_X(x, 10, 1) << 8) | (RV_X(x, 11, 1) << 12))
#define ENCODE_RVV_VB_IMM(x) \
  (RV_X(x, 0, 10) << 20)
#define ENCODE_RVV_VC_IMM(x) \
  (RV_X(x, 0, 11) << 20)

#define VALID_ITYPE_IMM(x) (EXTRACT_ITYPE_IMM(ENCODE_ITYPE_IMM(x)) == (x))
#define VALID_STYPE_IMM(x) (EXTRACT_STYPE_IMM(ENCODE_STYPE_IMM(x)) == (x))
#define VALID_BTYPE_IMM(x) (EXTRACT_BTYPE_IMM(ENCODE_BTYPE_IMM(x)) == (x))
#define VALID_UTYPE_IMM(x) (EXTRACT_UTYPE_IMM(ENCODE_UTYPE_IMM(x)) == (x))
#define VALID_JTYPE_IMM(x) (EXTRACT_JTYPE_IMM(ENCODE_JTYPE_IMM(x)) == (x))
#define VALID_CITYPE_IMM(x) (EXTRACT_CITYPE_IMM(ENCODE_CITYPE_IMM(x)) == (x))
#define VALID_CITYPE_LUI_IMM(x) (ENCODE_CITYPE_LUI_IMM(x) != 0 \
				 && EXTRACT_CITYPE_LUI_IMM(ENCODE_CITYPE_LUI_IMM(x)) == (x))
#define VALID_CITYPE_ADDI16SP_IMM(x) (ENCODE_CITYPE_ADDI16SP_IMM(x) != 0 \
				      && EXTRACT_CITYPE_ADDI16SP_IMM(ENCODE_CITYPE_ADDI16SP_IMM(x)) == (x))
#define VALID_CITYPE_LWSP_IMM(x) (EXTRACT_CITYPE_LWSP_IMM(ENCODE_CITYPE_LWSP_IMM(x)) == (x))
#define VALID_CITYPE_LDSP_IMM(x) (EXTRACT_CITYPE_LDSP_IMM(ENCODE_CITYPE_LDSP_IMM(x)) == (x))
#define VALID_CSSTYPE_IMM(x) (EXTRACT_CSSTYPE_IMM(ENCODE_CSSTYPE_IMM(x)) == (x))
#define VALID_CSSTYPE_SWSP_IMM(x) (EXTRACT_CSSTYPE_SWSP_IMM(ENCODE_CSSTYPE_SWSP_IMM(x)) == (x))
#define VALID_CSSTYPE_SDSP_IMM(x) (EXTRACT_CSSTYPE_SDSP_IMM(ENCODE_CSSTYPE_SDSP_IMM(x)) == (x))
#define VALID_CIWTYPE_IMM(x) (EXTRACT_CIWTYPE_IMM(ENCODE_CIWTYPE_IMM(x)) == (x))
#define VALID_CIWTYPE_ADDI4SPN_IMM(x) (EXTRACT_CIWTYPE_ADDI4SPN_IMM(ENCODE_CIWTYPE_ADDI4SPN_IMM(x)) == (x))
#define VALID_CLTYPE_IMM(x) (EXTRACT_CLTYPE_IMM(ENCODE_CLTYPE_IMM(x)) == (x))
#define VALID_CLTYPE_LW_IMM(x) (EXTRACT_CLTYPE_LW_IMM(ENCODE_CLTYPE_LW_IMM(x)) == (x))
#define VALID_CLTYPE_LD_IMM(x) (EXTRACT_CLTYPE_LD_IMM(ENCODE_CLTYPE_LD_IMM(x)) == (x))
#define VALID_CBTYPE_IMM(x) (EXTRACT_CBTYPE_IMM(ENCODE_CBTYPE_IMM(x)) == (x))
#define VALID_CJTYPE_IMM(x) (EXTRACT_CJTYPE_IMM(ENCODE_CJTYPE_IMM(x)) == (x))
#define VALID_RVV_VB_IMM(x) (EXTRACT_RVV_VB_IMM(ENCODE_RVV_VB_IMM(x)) == (x))
#define VALID_RVV_VC_IMM(x) (EXTRACT_RVV_VC_IMM(ENCODE_RVV_VC_IMM(x)) == (x))

#define RISCV_RTYPE(insn, rd, rs1, rs2) \
  ((MATCH_ ## insn) | ((rd) << OP_SH_RD) | ((rs1) << OP_SH_RS1) | ((rs2) << OP_SH_RS2))
#define RISCV_ITYPE(insn, rd, rs1, imm) \
  ((MATCH_ ## insn) | ((rd) << OP_SH_RD) | ((rs1) << OP_SH_RS1) | ENCODE_ITYPE_IMM(imm))
#define RISCV_STYPE(insn, rs1, rs2, imm) \
  ((MATCH_ ## insn) | ((rs1) << OP_SH_RS1) | ((rs2) << OP_SH_RS2) | ENCODE_STYPE_IMM(imm))
#define RISCV_BTYPE(insn, rs1, rs2, target) \
  ((MATCH_ ## insn) | ((rs1) << OP_SH_RS1) | ((rs2) << OP_SH_RS2) | ENCODE_BTYPE_IMM(target))
#define RISCV_UTYPE(insn, rd, bigimm) \
  ((MATCH_ ## insn) | ((rd) << OP_SH_RD) | ENCODE_UTYPE_IMM(bigimm))
#define RISCV_JTYPE(insn, rd, target) \
  ((MATCH_ ## insn) | ((rd) << OP_SH_RD) | ENCODE_JTYPE_IMM(target))

#define RISCV_NOP RISCV_ITYPE(ADDI, 0, 0, 0)
#define RVC_NOP MATCH_C_ADDI

#define RISCV_CONST_HIGH_PART(VALUE) \
  (((VALUE) + (RISCV_IMM_REACH/2)) & ~(RISCV_IMM_REACH-1))
#define RISCV_CONST_LOW_PART(VALUE) ((VALUE) - RISCV_CONST_HIGH_PART (VALUE))
#define RISCV_PCREL_HIGH_PART(VALUE, PC) RISCV_CONST_HIGH_PART((VALUE) - (PC))
#define RISCV_PCREL_LOW_PART(VALUE, PC) RISCV_CONST_LOW_PART((VALUE) - (PC))

#define RISCV_JUMP_BITS RISCV_BIGIMM_BITS
#define RISCV_JUMP_ALIGN_BITS 1
#define RISCV_JUMP_ALIGN (1 << RISCV_JUMP_ALIGN_BITS)
#define RISCV_JUMP_REACH ((1ULL << RISCV_JUMP_BITS) * RISCV_JUMP_ALIGN)

#define RISCV_IMM_BITS 12
#define RISCV_BIGIMM_BITS (32 - RISCV_IMM_BITS)
#define RISCV_IMM_REACH (1LL << RISCV_IMM_BITS)
#define RISCV_BIGIMM_REACH (1LL << RISCV_BIGIMM_BITS)
#define RISCV_RVC_IMM_REACH (1LL << 6)
#define RISCV_BRANCH_BITS RISCV_IMM_BITS
#define RISCV_BRANCH_ALIGN_BITS RISCV_JUMP_ALIGN_BITS
#define RISCV_BRANCH_ALIGN (1 << RISCV_BRANCH_ALIGN_BITS)
#define RISCV_BRANCH_REACH (RISCV_IMM_REACH * RISCV_BRANCH_ALIGN)

/* RV fields.  */

#define OP_MASK_OP		0x7f
#define OP_SH_OP		0
#define OP_MASK_RS2		0x1f
#define OP_SH_RS2		20
#define OP_MASK_RS1		0x1f
#define OP_SH_RS1		15
#define OP_MASK_RS3		0x1fU
#define OP_SH_RS3		27
#define OP_MASK_RD		0x1f
#define OP_SH_RD		7
#define OP_MASK_SHAMT		0x3f
#define OP_SH_SHAMT		20
#define OP_MASK_SHAMTW		0x1f
#define OP_SH_SHAMTW		20
#define OP_MASK_RM		0x7
#define OP_SH_RM		12
#define OP_MASK_PRED		0xf
#define OP_SH_PRED		24
#define OP_MASK_SUCC		0xf
#define OP_SH_SUCC		20
#define OP_MASK_AQ		0x1
#define OP_SH_AQ		26
#define OP_MASK_RL		0x1
#define OP_SH_RL		25

#define OP_MASK_CSR		0xfffU
#define OP_SH_CSR		20

#define OP_MASK_FUNCT3		0x7
#define OP_SH_FUNCT3		12
#define OP_MASK_FUNCT7		0x7fU
#define OP_SH_FUNCT7		25
#define OP_MASK_FUNCT2		0x3
#define OP_SH_FUNCT2		25

/* RVC fields.  */

#define OP_MASK_OP2		0x3
#define OP_SH_OP2		0

#define OP_MASK_CRS2		0x1f
#define OP_SH_CRS2		2
#define OP_MASK_CRS1S		0x7
#define OP_SH_CRS1S		7
#define OP_MASK_CRS2S		0x7
#define OP_SH_CRS2S		2

#define OP_MASK_CFUNCT6		0x3f
#define OP_SH_CFUNCT6		10
#define OP_MASK_CFUNCT4		0xf
#define OP_SH_CFUNCT4		12
#define OP_MASK_CFUNCT3		0x7
#define OP_SH_CFUNCT3		13
#define OP_MASK_CFUNCT2		0x3
#define OP_SH_CFUNCT2		5

/* Scalar crypto fields. */

#define OP_SH_BS        30
#define OP_MASK_BS      3
#define OP_SH_RNUM      20
#define OP_MASK_RNUM    0xf

/* RVV fields.  */

#define OP_MASK_VD		0x1f
#define OP_SH_VD		7
#define OP_MASK_VS1		0x1f
#define OP_SH_VS1		15
#define OP_MASK_VS2		0x1f
#define OP_SH_VS2		20
#define OP_MASK_VIMM		0x1f
#define OP_SH_VIMM		15
#define OP_MASK_VMASK		0x1
#define OP_SH_VMASK		25
#define OP_MASK_VFUNCT6		0x3f
#define OP_SH_VFUNCT6		26
#define OP_MASK_VLMUL		0x7
#define OP_SH_VLMUL		0
#define OP_MASK_VSEW		0x7
#define OP_SH_VSEW		3
#define OP_MASK_VTA		0x1
#define OP_SH_VTA		6
#define OP_MASK_VMA		0x1
#define OP_SH_VMA		7
#define OP_MASK_VWD		0x1
#define OP_SH_VWD		26

#define NVECR 32
#define NVECM 1

/* ABI names for selected x-registers.  */

#define X_RA 1
#define X_SP 2
#define X_GP 3
#define X_TP 4
#define X_T0 5
#define X_T1 6
#define X_T2 7
#define X_T3 28

#define NGPR 32
#define NFPR 32

/* These fake label defines are use by both the assembler, and
   libopcodes.  The assembler uses this when it needs to generate a fake
   label, and libopcodes uses it to hide the fake labels in its output.  */
#define RISCV_FAKE_LABEL_NAME ".L0 "
#define RISCV_FAKE_LABEL_CHAR ' '

/* Replace bits MASK << SHIFT of STRUCT with the equivalent bits in
   VALUE << SHIFT.  VALUE is evaluated exactly once.  */
#define INSERT_BITS(STRUCT, VALUE, MASK, SHIFT) \
  (STRUCT) = (((STRUCT) & ~((insn_t)(MASK) << (SHIFT))) \
	      | ((insn_t)((VALUE) & (MASK)) << (SHIFT)))

/* Extract bits MASK << SHIFT from STRUCT and shift them right
   SHIFT places.  */
#define EXTRACT_BITS(STRUCT, MASK, SHIFT) \
  (((STRUCT) >> (SHIFT)) & (MASK))

/* Extract the operand given by FIELD from integer INSN.  */
#define EXTRACT_OPERAND(FIELD, INSN) \
  EXTRACT_BITS ((INSN), OP_MASK_##FIELD, OP_SH_##FIELD)

/* Extract an unsigned immediate operand on position s with n bits.  */
#define EXTRACT_U_IMM(n, s, l) \
  RV_X (l, s, n)

/* Extract an signed immediate operand on position s with n bits.  */
#define EXTRACT_S_IMM(n, s, l) \
  RV_X_SIGNED (l, s, n)

/* Validate that unsigned n-bit immediate is within bounds.  */
#define VALIDATE_U_IMM(v, n) \
  ((unsigned long) v < (1UL << n))

/* Validate that signed n-bit immediate is within bounds.  */
#define VALIDATE_S_IMM(v, n) \
  (v < (long) (1UL << (n-1)) && v >= -(offsetT) (1UL << (n-1)))

/* The maximal number of subset can be required.  */
#define MAX_SUBSET_NUM 4

/* All RISC-V instructions belong to at least one of these classes.  */
enum riscv_insn_class
{
  INSN_CLASS_NONE,

  INSN_CLASS_I,
  INSN_CLASS_C,
  INSN_CLASS_A,
  INSN_CLASS_M,
  INSN_CLASS_F,
  INSN_CLASS_D,
  INSN_CLASS_Q,
  INSN_CLASS_F_AND_C,
  INSN_CLASS_D_AND_C,
  INSN_CLASS_ZICSR,
  INSN_CLASS_ZIFENCEI,
  INSN_CLASS_ZIHINTPAUSE,
  INSN_CLASS_ZMMUL,
  INSN_CLASS_ZAWRS,
  INSN_CLASS_F_INX,
  INSN_CLASS_D_INX,
  INSN_CLASS_Q_INX,
  INSN_CLASS_ZFH_INX,
  INSN_CLASS_ZFHMIN,
  INSN_CLASS_ZFHMIN_INX,
  INSN_CLASS_ZFHMIN_AND_D_INX,
  INSN_CLASS_ZFHMIN_AND_Q_INX,
  INSN_CLASS_ZBA,
  INSN_CLASS_ZBB,
  INSN_CLASS_ZBC,
  INSN_CLASS_ZBS,
  INSN_CLASS_ZBKB,
  INSN_CLASS_ZBKC,
  INSN_CLASS_ZBKX,
  INSN_CLASS_ZKND,
  INSN_CLASS_ZKNE,
  INSN_CLASS_ZKNH,
  INSN_CLASS_ZKSED,
  INSN_CLASS_ZKSH,
  INSN_CLASS_ZBB_OR_ZBKB,
  INSN_CLASS_ZBC_OR_ZBKC,
  INSN_CLASS_ZKND_OR_ZKNE,
  INSN_CLASS_V,
  INSN_CLASS_ZVEF,
  INSN_CLASS_SVINVAL,
  INSN_CLASS_ZICBOM,
  INSN_CLASS_ZICBOP,
  INSN_CLASS_ZICBOZ,
  INSN_CLASS_H,
  INSN_CLASS_XTHEADBA,
  INSN_CLASS_XTHEADBB,
  INSN_CLASS_XTHEADBS,
  INSN_CLASS_XTHEADCMO,
  INSN_CLASS_XTHEADCONDMOV,
  INSN_CLASS_XTHEADFMEMIDX,
  INSN_CLASS_XTHEADFMV,
  INSN_CLASS_XTHEADINT,
  INSN_CLASS_XTHEADMAC,
  INSN_CLASS_XTHEADMEMIDX,
  INSN_CLASS_XTHEADMEMPAIR,
  INSN_CLASS_XTHEADSYNC,
  INSN_CLASS_XVENTANACONDOPS,
};

/* This structure holds information for a particular instruction.  */
struct riscv_opcode
{
  /* The name of the instruction.  */
  const char *name;

  /* The requirement of xlen for the instruction, 0 if no requirement.  */
  unsigned xlen_requirement;

  /* Class to which this instruction belongs.  Used to decide whether or
     not this instruction is legal in the current -march context.  */
  enum riscv_insn_class insn_class;

  /* A string describing the arguments for this instruction.  */
  const char *args;

  /* The basic opcode for the instruction.  When assembling, this
     opcode is modified by the arguments to produce the actual opcode
     that is used.  If pinfo is INSN_MACRO, then this is 0.  */
  insn_t match;

  /* If pinfo is not INSN_MACRO, then this is a bit mask for the
     relevant portions of the opcode when disassembling.  If the
     actual opcode anded with the match field equals the opcode field,
     then we have found the correct instruction.  If pinfo is
     INSN_MACRO, then this field is the macro identifier.  */
  insn_t mask;

  /* A function to determine if a word corresponds to this instruction.
     Usually, this computes ((word & mask) == match).  */
  int (*match_func) (const struct riscv_opcode *op, insn_t word);

  /* For a macro, this is INSN_MACRO.  Otherwise, it is a collection
     of bits describing the instruction, notably any relevant hazard
     information.  */
  unsigned long pinfo;
};

/* Instruction is a simple alias (e.g. "mv" for "addi").  */
#define	INSN_ALIAS		0x00000001

/* These are for setting insn_info fields.

   Nonbranch is the default.  Noninsn is used only if there is no match.
   There are no condjsr or dref2 instructions.  So that leaves condbranch,
   branch, jsr, and dref that we need to handle here, encoded in 3 bits.  */
#define INSN_TYPE		0x0000000e

/* Instruction is an unconditional branch.  */
#define INSN_BRANCH		0x00000002
/* Instruction is a conditional branch.  */
#define INSN_CONDBRANCH		0x00000004
/* Instruction is a jump to subroutine.  */
#define INSN_JSR		0x00000006
/* Instruction is a data reference.  */
#define INSN_DREF		0x00000008
/* Instruction is allowed when eew >= 64.  */
#define INSN_V_EEW64		0x10000000

/* We have 5 data reference sizes, which we can encode in 3 bits.  */
#define INSN_DATA_SIZE		0x00000070
#define INSN_DATA_SIZE_SHIFT	4
#define INSN_1_BYTE		0x00000010
#define INSN_2_BYTE		0x00000020
#define INSN_4_BYTE		0x00000030
#define INSN_8_BYTE		0x00000040
#define INSN_16_BYTE		0x00000050

/* Instruction is actually a macro.  It should be ignored by the
   disassembler, and requires special treatment by the assembler.  */
#define INSN_MACRO		0xffffffff

/* This is a list of macro expanded instructions.  */
enum
{
  M_LA,
  M_LLA,
  M_LA_TLS_GD,
  M_LA_TLS_IE,
  M_LB,
  M_LBU,
  M_LH,
  M_LHU,
  M_LW,
  M_LWU,
  M_LD,
  M_SB,
  M_SH,
  M_SW,
  M_SD,
  M_FLW,
  M_FLD,
  M_FLQ,
  M_FSW,
  M_FSD,
  M_FSQ,
  M_CALL,
  M_J,
  M_LI,
  M_ZEXTH,
  M_ZEXTW,
  M_SEXTB,
  M_SEXTH,
  M_VMSGE,
  M_VMSGEU,
  M_FLH,
  M_FSH,
  M_NUM_MACROS
};

/* The mapping symbol states.  */
enum riscv_seg_mstate
{
  MAP_NONE = 0,		/* Must be zero, for seginfo in new sections.  */
  MAP_DATA,		/* Data.  */
  MAP_INSN,		/* Instructions.  */
};

static const char * const riscv_gpr_names_numeric[NGPR];
static const char * const riscv_gpr_names_abi[NGPR];
static const char * const riscv_fpr_names_numeric[NFPR];
static const char * const riscv_fpr_names_abi[NFPR];
static const char * const riscv_rm[8];
static const char * const riscv_pred_succ[16];
static const char * const riscv_vecr_names_numeric[NVECR];
static const char * const riscv_vecm_names_numeric[NVECM];
static const char * const riscv_vsew[8];
static const char * const riscv_vlmul[8];
static const char * const riscv_vta[2];
static const char * const riscv_vma[2];

static const struct riscv_opcode riscv_opcodes[];
static const struct riscv_opcode riscv_insn_types[];

#endif /* _RISCV_H_ */

struct frag;
struct expressionS;

#ifndef TARGET_BYTES_BIG_ENDIAN
#define TARGET_BYTES_BIG_ENDIAN 0
#endif

#define TARGET_ARCH bfd_arch_riscv

#define WORKING_DOT_WORD	1
#define LOCAL_LABELS_FB 	1

/* Symbols named FAKE_LABEL_NAME are emitted when generating DWARF, so make
   sure FAKE_LABEL_NAME is printable.  It still must be distinct from any
   real label name.  So, append a space, which other labels can't contain.  */
#define FAKE_LABEL_NAME RISCV_FAKE_LABEL_NAME
/* Changing the special character in FAKE_LABEL_NAME requires changing
   FAKE_LABEL_CHAR too.  */
#define FAKE_LABEL_CHAR RISCV_FAKE_LABEL_CHAR

#define md_relax_frag(segment, fragp, stretch) \
  riscv_relax_frag (segment, fragp, stretch)
static int riscv_relax_frag (asection *, struct frag *, long);

#define md_section_align(seg,size)	(size)
#define md_undefined_symbol(name)	(0)
#define md_operand(x)

static bool riscv_frag_align_code (int);
#define md_do_align(N, FILL, LEN, MAX, LABEL)				\
  if ((N) != 0 && !(FILL) && !need_pass_2 && subseg_text_p (now_seg))	\
    {									\
      if (riscv_frag_align_code (N))					\
	goto LABEL;							\
    }

static void riscv_handle_align (fragS *);
#define HANDLE_ALIGN riscv_handle_align

#define MAX_MEM_FOR_RS_ALIGN_CODE (3 + 4)

/* The ISA of the target may change based on command-line arguments.  */
#define TARGET_FORMAT riscv_target_format ()
static const char * riscv_target_format (void);

#define md_after_parse_args() riscv_after_parse_args ()
static void riscv_after_parse_args (void);

#define md_pre_output_hook riscv_pre_output_hook ()
static void riscv_pre_output_hook (void);
#define GAS_SORT_RELOCS 1

/* Let the linker resolve all the relocs due to relaxation.  */
#define tc_fix_adjustable(fixp) 0
#define md_allow_local_subtract(l,r,s) 0

/* Values passed to md_apply_fix don't include symbol values.  */
#define MD_APPLY_SYM_VALUE(FIX) 0

/* Global syms must not be resolved, to support ELF shared libraries.  */
#define EXTERN_FORCE_RELOC			\
  (OUTPUT_FLAVOR == bfd_target_elf_flavour)

/* Postpone text-section label subtraction calculation until linking, since
   linker relaxations might change the deltas.  */
#define TC_FORCE_RELOCATION_SUB_SAME(FIX, SEG)	\
  (GENERIC_FORCE_RELOCATION_SUB_SAME (FIX, SEG)	\
   || ((SEG)->flags & SEC_CODE) != 0)
#define TC_FORCE_RELOCATION_SUB_LOCAL(FIX, SEG) 1
#define TC_VALIDATE_FIX_SUB(FIX, SEG) 1
#define TC_FORCE_RELOCATION_LOCAL(FIX) 1
#define DIFF_EXPR_OK 1

static void riscv_pop_insert (void);
#define md_pop_insert()		riscv_pop_insert ()

#define TARGET_USE_CFIPOP 1

#define tc_cfi_frame_initial_instructions riscv_cfi_frame_initial_instructions
static void riscv_cfi_frame_initial_instructions (void);

#define tc_regname_to_dw2regnum tc_riscv_regname_to_dw2regnum
static int tc_riscv_regname_to_dw2regnum (char *);

#define DWARF2_DEFAULT_RETURN_COLUMN X_RA

/* Even on RV64, use 4-byte alignment, as F registers may be only 32 bits.  */
#define DWARF2_CIE_DATA_ALIGNMENT -4

#define elf_tc_final_processing riscv_elf_final_processing
static void riscv_elf_final_processing (void);

/* Adjust debug_line after relaxation.  */
#define DWARF2_USE_FIXED_ADVANCE_PC 1

static bool riscv_parse_name (const char *, struct expressionS *, enum expr_mode);

#define CONVERT_SYMBOLIC_ATTRIBUTE riscv_convert_symbolic_attribute

static void riscv_md_finish (void);
static int riscv_convert_symbolic_attribute (const char *);

/* Set mapping symbol states.  */
#define md_cons_align(nbytes) riscv_mapping_state (MAP_DATA, 0, 0)
static void riscv_mapping_state (enum riscv_seg_mstate, int, bool);

/* Define target segment type.  */
#define TC_SEGMENT_INFO_TYPE struct riscv_segment_info_type
struct riscv_segment_info_type
{
  enum riscv_seg_mstate map_state;
  /* The current mapping symbol with architecture string.  */
  symbolS *arch_map_symbol;
};

/* Define target fragment type.  */
#define TC_FRAG_TYPE struct riscv_frag_type
struct riscv_frag_type
{
  symbolS *first_map_symbol, *last_map_symbol;
};

#define TC_FRAG_INIT(fragp, max_bytes) riscv_init_frag (fragp, max_bytes)
static void riscv_init_frag (struct frag *, int);
static void riscv_adjust_symtab (void);

static void riscv_elf_copy_symbol_attributes (symbolS *, symbolS *);
#define OBJ_COPY_SYMBOL_ATTRIBUTES(DEST, SRC)  \
  riscv_elf_copy_symbol_attributes (DEST, SRC)

#endif /* TC_RISCV */

enum elf_visibility {
  visibility_unchanged = 0, visibility_local, visibility_hidden,
  visibility_remove
};

struct elf_versioned_name_list {
  char *name;
  struct elf_versioned_name_list *next;
};

/* Additional information we keep for each symbol.  */
struct elf_obj_sy {
  /* Whether the symbol has been marked as local.  */
  unsigned int local : 1;

  /* Whether the symbol has been marked for rename with @@@.  */
  unsigned int rename : 1;

  /* Whether the symbol has a bad version name.  */
  unsigned int bad_version : 1;

  /* Whether visibility of the symbol should be changed.  */
  ENUM_BITFIELD (elf_visibility) visibility : 2;

  /* Use this to keep track of .size expressions that involve
     differences that we can't compute yet.  */
  expressionS *size;

  /* The list of names specified by the .symver directive.  */
  struct elf_versioned_name_list *versioned_name;

};

/* Match section group name, the sh_info field and the section_id
   field.  */
struct elf_section_match {
  const char *   group_name;
  const char *   linked_to_symbol_name;
  unsigned int   section_id;
  unsigned int   sh_info;		/* ELF section information.  */
  bfd_vma        sh_flags;		/* ELF section flags.  */
  flagword       flags;
};

#define OBJ_SYMFIELD_TYPE struct elf_obj_sy

#ifndef obj_begin
#define obj_begin() elf_begin ()
#endif
static void elf_begin (void);

#ifndef obj_end
#define obj_end() elf_end ()
#endif
static void elf_end (void);

#ifndef LOCAL_LABEL_PREFIX
#define LOCAL_LABEL_PREFIX '.'
#endif

/* should be conditional on address size! */
#define elf_symbol(asymbol) ((elf_symbol_type *) (&(asymbol)->the_bfd))

#ifndef S_GET_SIZE
#define S_GET_SIZE(S) \
  (elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_size)
#endif
#ifndef S_SET_SIZE
#define S_SET_SIZE(S,V) \
  (elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_size = (V))
#endif

#ifndef S_GET_ALIGN
#define S_GET_ALIGN(S) \
  (elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_value)
#endif
#ifndef S_SET_ALIGN
#define S_SET_ALIGN(S,V) \
  (elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_value = (V))
#endif

static int elf_s_get_other (symbolS *);
#ifndef S_GET_OTHER
#define S_GET_OTHER(S)	(elf_s_get_other (S))
#endif
#ifndef S_SET_OTHER
#define S_SET_OTHER(S,V) \
  (elf_symbol (symbol_get_bfdsym (S))->internal_elf_sym.st_other = (V))
#endif
static void elf_frob_file (void);

#ifndef obj_frob_file_before_adjust
#define obj_frob_file_before_adjust  elf_frob_file_before_adjust
#endif
static void elf_frob_file_before_adjust (void);
static void elf_frob_file_after_relocs (void);

/* If the target doesn't have special processing for labels, take care of
   dwarf2 output at the object file level.  */
/* dwarf2dbg.h - DWARF2 debug support */
#ifndef AS_DWARF2DBG_H
#define AS_DWARF2DBG_H

#define DWARF2_FLAG_IS_STMT		(1 << 0)
#define DWARF2_FLAG_BASIC_BLOCK		(1 << 1)
#define DWARF2_FLAG_PROLOGUE_END	(1 << 2)
#define DWARF2_FLAG_EPILOGUE_BEGIN	(1 << 3)

struct dwarf2_line_info {
  unsigned int filenum;
  unsigned int line;
  unsigned int column;
  unsigned int isa;
  unsigned int flags;
  unsigned int discriminator;
  /* filenum == -1u chooses filename, otherwise view.  */
  union
  {
    symbolS *view;
    const char *filename;
  } u;
};

/* Implements the .file FILENO "FILENAME" directive.  FILENO can be 0
   to indicate that no file number has been assigned.  All real file
   number must be >0.  The second form returns the filename extracted
   from the input stream.  */
static void   dwarf2_directive_file (int);
static char * dwarf2_directive_filename (void);

/* Implements the .loc FILENO LINENO [COLUMN] directive.  FILENO is
   the file number, LINENO the line number and the (optional) COLUMN
   the column of the source code that the following instruction
   corresponds to.  FILENO can be 0 to indicate that the filename
   specified by the textually most recent .file directive should be
   used.  */
static void dwarf2_directive_loc (int);

/* Implements the .loc_mark_labels {0,1} directive.  */
static void dwarf2_directive_loc_mark_labels (int);

/* Returns the current source information.  If .file directives have
   been encountered, the info for the corresponding source file is
   returned.  Otherwise, the info for the assembly source file is
   returned.  */
static void dwarf2_where (struct dwarf2_line_info *);

/* This function generates .debug_line info based on the address and
   source information passed in the arguments.  ADDR should be the
   frag-relative offset of the instruction the information is for and
   L is the source information that should be associated with that
   address.  */
static void dwarf2_gen_line_info (addressT, struct dwarf2_line_info *);

/* Must be called for each generated instruction.  */
static void dwarf2_emit_insn (int);

/* Reset the state of the line number information to reflect that
   it has been used.  */
static void dwarf2_consume_line_info (void);

/* Should be called for each code label.  */
static void dwarf2_emit_label (symbolS *);

/* True when we've seen a .loc directive recently.  Used to avoid
   doing work when there's nothing to do.  */
static bool dwarf2_loc_directive_seen;

/* True when we're supposed to set the basic block mark whenever a label
   is seen.  Unless the target is doing Something Weird, just call
   dwarf2_emit_label.  */
static bool dwarf2_loc_mark_labels;

static void dwarf2_init (void);

static void dwarf2_finish (void);

static int dwarf2dbg_estimate_size_before_relax (fragS *);
static int dwarf2dbg_relax_frag (fragS *);
static void dwarf2dbg_convert_frag (fragS *);

static void dwarf2dbg_final_check (void);

/* An enumeration which describes the sizes of offsets (to DWARF sections)
   and the mechanism by which the size is indicated.  */
enum dwarf2_format
{
  /* 32-bit format: the initial length field is 4 bytes long.  */
  dwarf2_format_32bit,
  /* DWARF3 64-bit format: the representation of the initial length
     (of a DWARF section) is 0xffffffff (4 bytes) followed by eight
     bytes indicating the actual length.  */
  dwarf2_format_64bit,
  /* SGI extension to DWARF2: The initial length is eight bytes.  */
  dwarf2_format_64bit_irix
};

#endif /* AS_DWARF2DBG_H */
#define obj_frob_label  dwarf2_emit_label

#ifndef obj_app_file
#define obj_app_file elf_file_symbol
#endif
static void elf_file_symbol (const char *);

static void obj_elf_section_change_hook (void);

static void obj_elf_section (int);
static const char * obj_elf_section_name (void);
static void obj_elf_previous (int);
static void obj_elf_version (int);
static void obj_elf_common (int);
static void obj_elf_bss (int);
static void obj_elf_data (int);
static void obj_elf_text (int);
static void obj_elf_change_section
  (const char *, unsigned int, bfd_vma, int, struct elf_section_match *,
   int, int);
static void obj_elf_vtable_inherit (int);
static void obj_elf_vtable_entry (int);
static struct fix * obj_elf_get_vtable_inherit (void);
static struct fix * obj_elf_get_vtable_entry (void);

/* BFD wants to write the udata field, which is a no-no for the
   predefined section symbols in bfd/section.c.  They are read-only.  */
#ifndef obj_sec_sym_ok_for_reloc
#define obj_sec_sym_ok_for_reloc(SEC)	((SEC)->owner != 0)
#endif

static void elf_obj_read_begin_hook (void);
#ifndef obj_read_begin_hook
#define obj_read_begin_hook	elf_obj_read_begin_hook
#endif

static void elf_obj_symbol_new_hook (symbolS *);
#ifndef obj_symbol_new_hook
#define obj_symbol_new_hook	elf_obj_symbol_new_hook
#endif

static void elf_obj_symbol_clone_hook (symbolS *, symbolS *);
#ifndef obj_symbol_clone_hook
#define obj_symbol_clone_hook	elf_obj_symbol_clone_hook
#endif

static void elf_adjust_symtab (void);
#ifndef obj_adjust_symtab
#define obj_adjust_symtab	elf_adjust_symtab
#endif

#ifndef SEPARATE_STAB_SECTIONS
/* Avoid ifndef each separate macro setting by wrapping the whole of the
   stab group on the assumption that whoever sets SEPARATE_STAB_SECTIONS
   caters to ECOFF_DEBUGGING and the right setting of INIT_STAB_SECTIONS
   and OBJ_PROCESS_STAB too, without needing the tweaks below.  */

/* Stabs go in a separate section.  */
#define SEPARATE_STAB_SECTIONS 1

/* We need 12 bytes at the start of the section to hold some initial
   information.  */
static void obj_elf_init_stab_section (segT);
#define INIT_STAB_SECTION(seg) obj_elf_init_stab_section (seg)

#ifdef ECOFF_DEBUGGING
/* We smuggle stabs in ECOFF rather than using a separate section.
   The Irix linker can not handle a separate stabs section.  */

#undef  SEPARATE_STAB_SECTIONS
#define SEPARATE_STAB_SECTIONS (!ECOFF_DEBUGGING)

#undef  INIT_STAB_SECTION
#define INIT_STAB_SECTION(seg) \
  ((void) (ECOFF_DEBUGGING ? 0 : (obj_elf_init_stab_section (seg), 0)))

#undef OBJ_PROCESS_STAB
#define OBJ_PROCESS_STAB(seg, what, string, type, other, desc)		\
  if (ECOFF_DEBUGGING)							\
    ecoff_stab ((seg), (what), (string), (type), (other), (desc))
#endif /* ECOFF_DEBUGGING */

#endif /* SEPARATE_STAB_SECTIONS not defined.  */

static  void elf_frob_symbol (symbolS *, int *);
static void elf_fixup_removed_symbol (symbolS **);
#ifndef obj_fixup_removed_symbol
#define obj_fixup_removed_symbol(sympp) elf_fixup_removed_symbol (sympp)
#endif

static void elf_pop_insert (void);
#ifndef obj_pop_insert
#define obj_pop_insert()	elf_pop_insert()
#endif

#ifndef OBJ_MAYBE_ELF
/* If OBJ_MAYBE_ELF then obj-multi.h will define obj_ecoff_set_ext.  */
#endif
static asection *elf_com_section_ptr;
static symbolS * elf_common_parse (int ignore ATTRIBUTE_UNUSED, symbolS *symbolP,
				   addressT size);

#endif /* _OBJ_ELF_H */

#ifdef OBJ_MAYBE_ELF
#define IS_ELF (OUTPUT_FLAVOR == bfd_target_elf_flavour)
#else
#ifdef OBJ_ELF
#define IS_ELF 1
#else
#define IS_ELF 0
#endif
#endif

/* write.h */
#ifndef __write_h__
#define __write_h__

/* This is the name of a fake symbol which will never appear in the
   assembler output.  S_IS_LOCAL detects it because of the \001.  */
#ifndef FAKE_LABEL_NAME
#define FAKE_LABEL_NAME "L0\001"
#endif

/* This is a special character that is used to indicate a fake label.
   It must be present in FAKE_LABEL_NAME, although it does not have to
   be the first character.  It must not be a character that would be
   found in a valid symbol name.

   Also be aware that the function _bfd_elf_is_local_label_name in
   bfd/elf.c has an implicit assumption that FAKE_LABEL_CHAR is '\001'.
   If this is not the case then FAKE_LABEL_NAME must start with ".L" in
   order for the function to continue working.  */
#ifndef FAKE_LABEL_CHAR
#define FAKE_LABEL_CHAR '\001'
#endif

/*
 * FixSs may be built up in any order.
 */

struct fix {
  /* Next fixS in linked list, or NULL.  */
  struct fix *fx_next;

  /* These small fields are grouped together for compactness of
     this structure, and efficiency of access on some architectures.  */

  /* pc-relative offset adjust (only used by some CPU specific code).
     A 4-bit field would be sufficient for most uses, except for ppc
     which pokes an operand table index here.  Bits may be stolen
     from here should that be necessary, provided PPC_OPINDEX_MAX is
     adjusted suitably.  */
  int fx_pcrel_adjust : 16;

  /* How many bytes are involved? */
  unsigned fx_size : 8;

  /* Is this a pc-relative relocation?  */
  unsigned fx_pcrel : 1;

  /* Has this relocation already been applied?  */
  unsigned fx_done : 1;

  /* Suppress overflow complaints on large addends.  This is used
     in the PowerPC ELF config to allow large addends on the
     BFD_RELOC_{LO16,HI16,HI16_S} relocations.

     @@ Can this be determined from BFD?  */
  unsigned fx_no_overflow : 1;

  /* The value is signed when checking for overflow.  */
  unsigned fx_signed : 1;

  /* Some bits for the CPU specific code.  */
  unsigned fx_tcbit : 1;
  unsigned fx_tcbit2 : 1;

  /* Spare bits.  */
  unsigned fx_unused : 2;

  bfd_reloc_code_real_type fx_r_type;

  /* Which frag does this fix apply to?  */
  fragS *fx_frag;

  /* The location within the frag where the fixup occurs.  */
  unsigned long fx_where;

  /* NULL or Symbol whose value we add in.  */
  symbolS *fx_addsy;

  /* NULL or Symbol whose value we subtract.  */
  symbolS *fx_subsy;

  /* Absolute number we add in.  */
  valueT fx_offset;

  /* The value of dot when the fixup expression was parsed.  */
  addressT fx_dot_value;

  /* The frag fx_dot_value is based on.  */
  fragS *fx_dot_frag;

  /* This field is sort of misnamed.  It appears to be a sort of random
     scratch field, for use by the back ends.  The main gas code doesn't
     do anything but initialize it to zero.  The use of it does need to
     be coordinated between the cpu and format files, though.  E.g., some
     coff targets pass the `addend' field from the cpu file via this
     field.  I don't know why the `fx_offset' field above can't be used
     for that; investigate later and document. KR  */
  valueT fx_addnumber;

  /* The location of the instruction which created the reloc, used
     in error messages.  */
  const char *fx_file;
  unsigned fx_line;

#ifdef USING_CGEN
  struct {
    /* CGEN_INSN entry for this instruction.  */
    const struct cgen_insn *insn;
    /* Target specific data, usually reloc number.  */
    int opinfo;
    /* Which ifield this fixup applies to. */
    struct cgen_maybe_multi_ifield * field;
    /* is this field is the MSB field in a set? */
    int msb_field_p;
  } fx_cgen;
#endif

#ifdef TC_FIX_TYPE
  /* Location where a backend can attach additional data
     needed to perform fixups.  */
  TC_FIX_TYPE tc_fix_data;
#endif
};

typedef struct fix fixS;

struct reloc_list
{
  struct reloc_list *next;
  union
  {
    struct
    {
      symbolS *offset_sym;
      reloc_howto_type *howto;
      symbolS *sym;
      bfd_vma addend;
    } a;
    struct
    {
      asection *sec;
      asymbol *s;
      arelent r;
    } b;
  } u;
  const char *file;
  unsigned int line;
};

static int finalize_syms;
static symbolS *abs_section_sym;
static addressT dot_value;
static fragS *dot_frag;
static struct reloc_list* reloc_list;

static void record_alignment (segT, unsigned);
static int get_recorded_alignment (segT);
static void write_object_file (void);
static int relax_segment (struct frag *, segT, int);
static void number_to_chars_littleendian (char *, valueT, int);
static fixS *fix_new (fragS *, unsigned long, unsigned long, symbolS *,
		      offsetT, int, bfd_reloc_code_real_type);
static fixS *fix_new_exp (fragS *, unsigned long, unsigned long,
			  expressionS *, int, bfd_reloc_code_real_type);
static void write_print_statistics (FILE *);
static void as_bad_subtract (fixS *);
#endif /* __write_h__ */
/* frags.h - Header file for the frag concept. */
#ifndef FRAGS_H
#define FRAGS_H

/* A code fragment (frag) is some known number of chars, followed by some
   unknown number of chars. Typically the unknown number of chars is an
   instruction address whose size is yet unknown. We always know the greatest
   possible size the unknown number of chars may become, and reserve that
   much room at the end of the frag.
   Once created, frags do not change address during assembly.
   We chain the frags in (a) forward-linked list(s). The object-file address
   of the 1st char of a frag is generally not known until after relax().
   Many things at assembly time describe an address by {object-file-address
   of a particular frag}+offset.

   BUG: it may be smarter to have a single pointer off to various different
   notes for different frag kinds.  See how code pans.  */

struct frag {
  /* Object file address (as an octet offset).  */
  addressT fr_address;
  /* When relaxing multiple times, remember the address the frag had
     in the last relax pass.  */
  addressT last_fr_address;

  /* (Fixed) number of octets we know we have.  May be 0.  */
  valueT fr_fix;
  /* May be used for (Variable) number of octets after above.
     The generic frag handling code no longer makes any use of fr_var.  */
  offsetT fr_var;
  /* For variable-length tail.  */
  offsetT fr_offset;
  /* For variable-length tail.  */
  symbolS *fr_symbol;
  /* Points to opcode low addr byte, for relaxation.  */
  char *fr_opcode;

  /* Chain forward; ascending address order.  Rooted in frch_root.  */
  struct frag *fr_next;

  /* Where the frag was created, or where it became a variant frag.  */
  const char *fr_file;
  unsigned int fr_line;

#ifndef NO_LISTING
  struct list_info_struct *line;
#endif

  /* A serial number for a sequence of frags having at most one alignment
     or org frag, and that at the tail of the sequence.  */
  unsigned int region:16;

  /* Flipped each relax pass so we can easily determine whether
     fr_address has been adjusted.  */
  unsigned int relax_marker:1;

  /* Used to ensure that all insns are emitted on proper address
     boundaries.  */
  unsigned int has_code:1;
  unsigned int insn_addr:6;

  /* What state is my tail in? */
  relax_stateT fr_type;
  relax_substateT fr_subtype;

#ifdef USING_CGEN
  /* Don't include this unless using CGEN to keep frag size down.  */
  struct {
    /* CGEN_INSN entry for this instruction.  */
    const struct cgen_insn *insn;
    /* Index into operand table.  */
    int opindex;
    /* Target specific data, usually reloc number.  */
    int opinfo;
  } fr_cgen;
#endif

#ifdef TC_FRAG_TYPE
  TC_FRAG_TYPE tc_frag_data;
#endif
#ifdef OBJ_FRAG_TYPE
  OBJ_FRAG_TYPE obj_frag_data;
#endif

  /* Data begins here.  */
  char fr_literal[1];
};

#define SIZEOF_STRUCT_FRAG \
((char *) zero_address_frag.fr_literal - (char *) &zero_address_frag)
/* We want to say fr_literal[0] above.  */

/* Current frag we are building.  This frag is incomplete.  It is,
   however, included in frchain_now.  The fr_fix field is bogus;
   instead, use frag_now_fix ().  */
static fragS *frag_now;
static addressT frag_now_fix (void);
static addressT frag_now_fix_octets (void);

/* For foreign-segment symbol fixups.  */
static fragS zero_address_frag;
static fragS predefined_address_frag;

static void frag_append_1_char (int);
#define FRAG_APPEND_1_CHAR(X) frag_append_1_char (X)

static void frag_init (void);
static fragS *frag_alloc (struct obstack *);
static void frag_grow (size_t nchars);
static char *frag_more (size_t nchars);
static void frag_align (int alignment, int fill_character, int max);
static void frag_align_pattern (int alignment, const char *fill_pattern, size_t n_fill, int max);
static void frag_align_code (int alignment, int max);
static void frag_new (size_t old_frags_var_max_size);
static void frag_wane (fragS * fragP);

static char *frag_var (relax_stateT type, size_t max_chars, size_t var,
		relax_substateT subtype, symbolS * symbol, offsetT offset, char *opcode);

static bool frag_offset_fixed_p (const fragS *, const fragS *, offsetT *);
static bool frag_offset_ignore_align_p (const fragS *, const fragS *, offsetT *);
static bool frag_gtoffset_p (valueT, const fragS *, valueT, const fragS *, offsetT *);
#endif /* FRAGS_H */
/* read.h - of read.c USA.  */

static char *input_line_pointer;	/* -> char we are parsing now.  */
static bool input_from_string;

/* Define to make whitespace be allowed in many syntactically
   unnecessary places.  Normally undefined.  For compatibility with
   ancient GNU cc.  */
/* #undef PERMIT_WHITESPACE */
#define PERMIT_WHITESPACE

#ifdef PERMIT_WHITESPACE
#define SKIP_WHITESPACE()			\
  ((*input_line_pointer == ' ') ? ++input_line_pointer : 0)
#define SKIP_ALL_WHITESPACE()			\
  while (*input_line_pointer == ' ') ++input_line_pointer
#else
#define SKIP_WHITESPACE() know (*input_line_pointer != ' ' )
#define SKIP_ALL_WHITESPACE() SKIP_WHITESPACE()
#endif

#define SKIP_WHITESPACE_AFTER_NAME()		\
  do						\
    {						\
      if (* input_line_pointer == '"')		\
	++ input_line_pointer;			\
      if (* input_line_pointer == ' ')		\
	++ input_line_pointer;			\
    }						\
  while (0)

#define	LEX_NAME	(1)	/* may continue a name */
#define LEX_BEGIN_NAME	(2)	/* may begin a name */
#define LEX_END_NAME	(4)	/* ends a name */

#define is_name_beginner(c) \
  ( lex_type[(unsigned char) (c)] & LEX_BEGIN_NAME )
#define is_part_of_name(c) \
  ( lex_type[(unsigned char) (c)] & LEX_NAME       )
#define is_name_ender(c) \
  ( lex_type[(unsigned char) (c)] & LEX_END_NAME   )

#ifndef is_a_char
#define CHAR_MASK	(0xff)
#define NOT_A_CHAR	(CHAR_MASK+1)
#define is_a_char(c)	(((unsigned) (c)) <= CHAR_MASK)
#endif /* is_a_char() */

static char lex_type[];
static char is_end_of_line[];

static int is_it_end_of_statement (void);

static int target_big_endian;

/* These are initialized by the CPU specific target files (tc-*.c).  */
static const char comment_chars[];
static const char line_comment_chars[];
static const char line_separator_chars[];

/* Table of -I directories.  */
static size_t include_dir_maxlen;

/* The offset in the absolute section.  */
static addressT abs_section_offset;

/* True if a stabs line debug statement is currently being emitted.  */
static int outputting_stabs_line_debug;

#ifndef TC_PARSE_CONS_RETURN_TYPE
#define TC_PARSE_CONS_RETURN_TYPE bfd_reloc_code_real_type
#define TC_PARSE_CONS_RETURN_NONE BFD_RELOC_NONE
#endif

static void pop_insert (const pseudo_typeS *);
static unsigned int get_stab_string_offset
  (const char *, const char *, bool);
static char *demand_copy_string (int *lenP);
static char *demand_copy_C_string (int *len_pointer);
static char get_absolute_expression_and_terminator (long *val_pointer);
static offsetT get_absolute_expression (void);
static unsigned int next_char_of_string (void);
static FILE *search_and_open (const char *, char *);
static void cons (int nbytes);
static void demand_empty_rest_of_line (void);
static void emit_expr (expressionS *exp, unsigned int nbytes);
static void emit_expr_with_reloc (expressionS *exp, unsigned int nbytes,
				  TC_PARSE_CONS_RETURN_TYPE);
static void emit_expr_fix (expressionS *, unsigned int, fragS *, char *,
			   TC_PARSE_CONS_RETURN_TYPE);
static void emit_leb128_expr (expressionS *, int);
static void equals (char *, int);
static void float_cons (int);
static void ignore_rest_of_line (void);
#define discard_rest_of_line ignore_rest_of_line
static unsigned output_leb128 (char *, valueT, int);
static void pseudo_set (symbolS * symbolP);
static void read_a_source_file (const char *name);
static void read_begin (void);
static void read_end (void);
static void read_print_statistics (FILE *);
static void print_binary (FILE *file, const char *name, expressionS *exp);
static char *read_symbol_name (void);
static unsigned sizeof_leb128 (valueT, int);
static void stabs_generate_asm_file (void);
static void stabs_generate_asm_lineno (void);
static void stabs_generate_asm_func (const char *, const char *);
static void stabs_generate_asm_endfunc (const char *, const char *);
static void stabs_begin (void);
static void stabs_end (void);
static void do_parse_cons_expression (expressionS *, int);

static void generate_lineno_debug (void);

static void s_align_bytes (int arg);
static void s_align_ptwo (int);
static void do_align (unsigned int align, char *fill, unsigned int length,
		      unsigned int max);
static void bss_alloc (symbolS *, addressT, unsigned);
static offsetT parse_align (int);
static symbolS *s_comm_internal (int, symbolS *(*) (int, symbolS *, addressT));
static symbolS *s_lcomm_internal (int, symbolS *, addressT);
static void s_file_string (char *);
static void s_file (int);
static void s_linefile (int);
static void s_comm (int);
static void s_data (int);
static void s_fill (int);
static void s_float_space (int mult);
static void s_func (int);
static void s_globl (int arg);
static void s_ignore (int arg);
static void s_lcomm (int needs_align);
static void s_leb128 (int sign);
static void s_linkonce (int);
static void s_lsym (int);
static void s_org (int);
static void s_set (int);
static void s_space (int mult);
static void s_nop (int);
static void s_nops (int);
static void s_stab (int what);
static void s_struct (int);
static void s_text (int);
static void stringer (int append_zero);
static void s_xstab (int what);
static void s_rva (int);
static void s_incbin (int);
static void s_weakref (int);
static void temp_ilp (char *);
static void restore_ilp (void);
/* symbols.h - */

static symbolS *symbol_rootP;	/* all the symbol nodes */
static symbolS *symbol_lastP;	/* last struct symbol we made, or NULL */

static int symbol_table_frozen;

/* This is non-zero if symbols are case sensitive, which is the
   default.  */
static int symbols_case_sensitive = 1;

static void *notes_alloc (size_t);
static void *notes_calloc (size_t, size_t);
static void *notes_memdup (const void *, size_t, size_t);
static char *notes_strdup (const char *);
static char *notes_concat (const char *, ...);
static void notes_free (void *);

static symbolS *symbol_find (const char *name);
static symbolS *symbol_find_noref (const char *name, int noref);
static symbolS *symbol_find_exact (const char *name);
static symbolS *symbol_find_exact_noref (const char *name, int noref);
static symbolS *symbol_find_or_make (const char *name);
static symbolS *symbol_make (const char *name);
static symbolS *symbol_new (const char *, segT, fragS *, valueT);

static symbolS *symbol_create (const char *, segT, fragS *, valueT);
static struct local_symbol *local_symbol_make (const char *, segT, fragS *, valueT);
static symbolS *symbol_clone (symbolS *, int);
#undef symbol_clone_if_forward_ref
static symbolS *symbol_clone_if_forward_ref (symbolS *, int);
#define symbol_clone_if_forward_ref(s) symbol_clone_if_forward_ref (s, 0)
static symbolS *symbol_temp_new (segT, fragS *, valueT);
static symbolS *symbol_temp_new_now (void);
static symbolS *symbol_temp_new_now_octets (void);
static symbolS *symbol_temp_make (void);

static symbolS *colon (const char *sym_name);
static void symbol_begin (void);
static void symbol_end (void);
static void dot_symbol_init (void);
static void symbol_print_statistics (FILE *);
static void symbol_table_insert (symbolS * symbolP);
static valueT resolve_symbol_value (symbolS *);
static void resolve_local_symbol_values (void);
static int snapshot_symbol (symbolS **, valueT *, segT *, fragS **);

static void print_symbol_value_1 (FILE *, symbolS *);
static void fb_label_instance_inc (unsigned int);
static char *fb_label_name (unsigned int, unsigned int);

static void copy_symbol_attributes (symbolS *, symbolS *);

/* Get and set the values of symbols.  These used to be macros.  */
static valueT S_GET_VALUE (symbolS *);
static valueT S_GET_VALUE_WHERE (symbolS *, const char *, unsigned int);
static void S_SET_VALUE (symbolS *, valueT);

static int S_IS_FUNCTION (symbolS *);
static int S_IS_EXTERNAL (symbolS *);
static int S_IS_WEAK (symbolS *);
static int S_IS_WEAKREFR (symbolS *);
static int S_IS_WEAKREFD (symbolS *);
static int S_IS_COMMON (symbolS *);
static int S_IS_DEFINED (symbolS *);
static int S_FORCE_RELOC (symbolS *, int);
static int S_IS_DEBUG (symbolS *);
static int S_IS_LOCAL (symbolS *);
static int S_CAN_BE_REDEFINED (const symbolS *);
static int S_IS_VOLATILE (const symbolS *);
static int S_IS_FORWARD_REF (const symbolS *);
static const char *S_GET_NAME (symbolS *);
static segT S_GET_SEGMENT (symbolS *);
static void S_SET_SEGMENT (symbolS *, segT);
static void S_SET_EXTERNAL (symbolS *);
static void S_SET_NAME (symbolS *, const char *);
static void S_CLEAR_EXTERNAL (symbolS *);
static void S_SET_WEAK (symbolS *);
static void S_SET_WEAKREFR (symbolS *);
static void S_CLEAR_WEAKREFR (symbolS *);
static void S_SET_WEAKREFD (symbolS *);
static void S_CLEAR_WEAKREFD (symbolS *);
static void S_SET_THREAD_LOCAL (symbolS *);
static void S_SET_VOLATILE (symbolS *);
static void S_CLEAR_VOLATILE (symbolS *);
static void S_SET_FORWARD_REF (symbolS *);

/*
 * Current means for getting from symbols to segments and vice verse.
 * This will change for infinite-segments support (e.g. COFF).
 */

#define	SEGMENT_TO_SYMBOL_TYPE(seg)  ( seg_N_TYPE [(int) (seg)] )

#define	N_REGISTER	30	/* Fake N_TYPE value for SEG_REGISTER */
static void symbol_clear_list_pointers (symbolS * symbolP);
static void symbol_insert (symbolS * addme, symbolS * target,
		    symbolS ** rootP, symbolS ** lastP);
static void symbol_remove (symbolS * symbolP, symbolS ** rootP,
		    symbolS ** lastP);
static int symbol_on_chain (symbolS *s, symbolS *rootPP, symbolS *lastPP);

#ifdef DEBUG
static void verify_symbol_chain (symbolS * rootP, symbolS * lastP);
#endif
static void symbol_append (symbolS * addme, symbolS * target,
		    symbolS ** rootP, symbolS ** lastP);
static symbolS *symbol_next (symbolS *);
static expressionS *symbol_get_value_expression (symbolS *);
static void symbol_set_value_expression (symbolS *, const expressionS *);
static offsetT *symbol_X_add_number (symbolS *);
static void symbol_set_value_now (symbolS *);
static void symbol_set_frag (symbolS *, fragS *);
static fragS *symbol_get_frag (symbolS *);
static void symbol_mark_used (symbolS *);
static int symbol_used_p (symbolS *);
static void symbol_mark_used_in_reloc (symbolS *);
static int symbol_used_in_reloc_p (symbolS *);
static void symbol_mark_written (symbolS *);
static void symbol_mark_removed (symbolS *);
static int symbol_removed_p (symbolS *);
static void symbol_mark_resolved (symbolS *);
static int symbol_resolved_p (symbolS *);
static int symbol_section_p (symbolS *);
static int symbol_equated_p (symbolS *);
static int symbol_equated_reloc_p (symbolS *);
static int symbol_constant_p (symbolS *);
static int symbol_shadow_p (symbolS *);
static symbolS *symbol_symbolS (symbolS *);
static asymbol *symbol_get_bfdsym (symbolS *);
static void symbol_set_bfdsym (symbolS *, asymbol *);
static int symbol_same_p (symbolS *, symbolS *);

#ifdef OBJ_SYMFIELD_TYPE
static OBJ_SYMFIELD_TYPE *symbol_get_obj (symbolS *);
#endif

#ifdef TC_SYMFIELD_TYPE
TC_SYMFIELD_TYPE *symbol_get_tc (symbolS *);
static void symbol_set_tc (symbolS *, TC_SYMFIELD_TYPE *);
#endif
/* An expandable hash tables datatype.  */
/* This package implements basic hash table functionality.  It is possible
   to search for an entry, create an entry and destroy an entry.

   Elements in the table are generic pointers.

   The size of the table is not fixed; if the occupancy of the table
   grows too high the hash table will be expanded.

   The abstract data implementation is based on generalized Algorithm D
   from Knuth's book "The art of computer programming".  Hash table is
   expanded by creation of new hash table and transferring elements from
   the old table to the new table.  */

#ifndef __HASHTAB_H__
#define __HASHTAB_H__

/* The type for a hash code.  */
typedef unsigned int hashval_t;

/* Callback function pointer types.  */

/* Calculate hash of a table entry.  */
typedef hashval_t (*htab_hash) (const void *);

/* Compare a table entry with a possible entry.  The entry already in
   the table always comes first, so the second element can be of a
   different type (but in this case htab_find and htab_find_slot
   cannot be used; instead the variants that accept a hash value
   must be used).  */
typedef int (*htab_eq) (const void *, const void *);

/* Cleanup function called whenever a live element is removed from
   the hash table.  */
typedef void (*htab_del) (void *);
  
/* Function called by htab_traverse for each live element.  The first
   arg is the slot of the element (which can be passed to htab_clear_slot
   if desired), the second arg is the auxiliary pointer handed to
   htab_traverse.  Return 1 to continue scan, 0 to stop.  */
typedef int (*htab_trav) (void **, void *);

/* Memory-allocation function, with the same functionality as calloc().
   Iff it returns NULL, the hash table implementation will pass an error
   code back to the user, so if your code doesn't handle errors,
   best if you use xcalloc instead.  */
typedef void *(*htab_alloc) (size_t, size_t);

/* We also need a free() routine.  */
typedef void (*htab_free) (void *);

/* Memory allocation and deallocation; variants which take an extra
   argument.  */
typedef void *(*htab_alloc_with_arg) (void *, size_t, size_t);
typedef void (*htab_free_with_arg) (void *, void *);

/* This macro defines reserved value for empty table entry.  */

#define HTAB_EMPTY_ENTRY    ((void *) 0)

/* This macro defines reserved value for table entry which contained
   a deleted element. */

#define HTAB_DELETED_ENTRY  ((void *) 1)

/* Hash tables are of the following type.  The structure
   (implementation) of this type is not needed for using the hash
   tables.  All work with hash table should be executed only through
   functions mentioned below.  The size of this structure is subject to
   change.  */

struct htab {
  /* Pointer to hash function.  */
  htab_hash hash_f;

  /* Pointer to comparison function.  */
  htab_eq eq_f;

  /* Pointer to cleanup function.  */
  htab_del del_f;

  /* Table itself.  */
  void **entries;

  /* Current size (in entries) of the hash table.  */
  size_t size;

  /* Current number of elements including also deleted elements.  */
  size_t n_elements;

  /* Current number of deleted elements in the table.  */
  size_t n_deleted;

  /* The following member is used for debugging. Its value is number
     of all calls of `htab_find_slot' for the hash table. */
  unsigned int searches;

  /* The following member is used for debugging.  Its value is number
     of collisions fixed for time of work with the hash table. */
  unsigned int collisions;

  /* Pointers to allocate/free functions.  */
  htab_alloc alloc_f;
  htab_free free_f;

  /* Alternate allocate/free functions, which take an extra argument.  */
  void *alloc_arg;
  htab_alloc_with_arg alloc_with_arg_f;
  htab_free_with_arg free_with_arg_f;

  /* Current size (in entries) of the hash table, as an index into the
     table of primes.  */
  unsigned int size_prime_index;
};

typedef struct htab *htab_t;

/* An enum saying whether we insert into the hash table or not.  */
enum insert_option {NO_INSERT, INSERT};

/* The prototypes of the package functions. */

static htab_t	htab_create_alloc  (size_t, htab_hash,
                                    htab_eq, htab_del,
                                    htab_alloc, htab_free);

static htab_t  htab_create_typed_alloc (size_t, htab_hash, htab_eq, htab_del,
					htab_alloc, htab_alloc, htab_free);

static void	htab_delete (htab_t);
static void *	htab_find (htab_t, const void *);
static void **	htab_find_slot (htab_t, const void *, enum insert_option);
static void *	htab_find_with_hash (htab_t, const void *, hashval_t);
static void **	htab_find_slot_with_hash (htab_t, const void *,
					  hashval_t, enum insert_option);
static void	htab_remove_elt	(htab_t, const void *);
static void	htab_remove_elt_with_hash (htab_t, const void *, hashval_t);

static size_t	htab_size (htab_t);
static size_t	htab_elements (htab_t);

/* A hash function for null-terminated strings.  */
static hashval_t htab_hash_string (const void *);

/* Shorthand for hashing something with an intrinsic size.  */
#define iterative_hash_object(OB,INIT) iterative_hash (&OB, sizeof (OB), INIT)

#endif /* __HASHTAB_H */
/* hash.h -- header file for gas hash table routines */
#ifndef HASH_H
#define HASH_H

struct string_tuple {
  const char *key;
  const void *value;
};
typedef struct string_tuple string_tuple_t;
/* Hash function for a string_tuple.  */
static hashval_t hash_string_tuple (const void *);
/* Equality function for a string_tuple.  */
static int eq_string_tuple (const void *, const void *);
/* Insert ELEMENT into HTAB.  If REPLACE is non-zero existing elements
   are overwritten.  If ELEMENT already exists, a pointer to the slot
   is returned.  Otherwise NULL is returned.  */
static void **htab_insert (htab_t, void * /* element */, int /* replace */);
/* Print statistics about a hash table.  */
static void htab_print_statistics (FILE *f, const char *name, htab_t table);
/* Inline string hash table functions.  */
static inline string_tuple_t *
string_tuple_alloc (htab_t table, const char *key, const void *value)
{
  string_tuple_t *tuple = table->alloc_f (1, sizeof (*tuple));
  tuple->key = key;
  tuple->value = value;
  return tuple;
}

static inline void * str_hash_find (htab_t table, const char *key)
{
  string_tuple_t needle = { key, NULL };
  string_tuple_t *tuple = htab_find (table, &needle);
  return tuple != NULL ? (void *) tuple->value : NULL;
}

static inline void * str_hash_find_n (htab_t table, const char *key, size_t n)
{
  char *tmp = XNEWVEC (char, n + 1);
  memcpy (tmp, key, n);
  tmp[n] = '\0';
  string_tuple_t needle = { tmp, NULL };
  string_tuple_t *tuple = htab_find (table, &needle);
  free (tmp);
  return tuple != NULL ? (void *) tuple->value : NULL;
}

static inline void str_hash_delete (htab_t table, const char *key)
{
  string_tuple_t needle = { key, NULL };
  htab_remove_elt (table, &needle);
}

static inline void ** str_hash_insert (htab_t table, const char *key, const void *value, int replace)
{
  string_tuple_t *elt = string_tuple_alloc (table, key, value);
  void **slot = htab_insert (table, elt, replace);
  if (slot && !replace && table->free_f)
    table->free_f (elt);
  return slot;
}

static inline htab_t str_htab_create (void)
{
  return htab_create_alloc (16, hash_string_tuple, eq_string_tuple,
			    NULL, notes_calloc, NULL);
}
#endif /* HASH_H */

/* tc.h - target cpu dependent */
/* In theory (mine, at least!) the machine dependent part of the assembler
   should only have to include one file.  This one.  -- JF */
static int    md_parse_option (int, const char *);
static void   md_assemble (char *);
static void   md_begin (void);
#ifndef md_number_to_chars
static void   md_number_to_chars (char *, valueT, int);
#endif
static void   md_apply_fix (fixS *, valueT *, segT);

static long    md_pcrel_from (fixS *);
#ifndef md_operand
static void    md_operand (expressionS *);
#endif
#ifndef md_estimate_size_before_relax
static int     md_estimate_size_before_relax (fragS * fragP, segT);
#endif
#ifndef md_section_align
static valueT  md_section_align (segT, valueT);
#endif
#ifndef  md_undefined_symbol
static symbolS *md_undefined_symbol (char *);
#endif

#ifndef md_convert_frag
static void    md_convert_frag (bfd *, segT, fragS *);
#endif
#ifndef RELOC_EXPANSION_POSSIBLE
static arelent *tc_gen_reloc (asection *, fixS *);
#else
static arelent **tc_gen_reloc (asection *, fixS *);
#endif

static const char FLT_CHARS[];
static const char EXP_CHARS[];

#ifdef H_TICK_HEX
static int enable_h_tick_hex;
#endif

#ifndef TC_STRING_ESCAPES
#define TC_STRING_ESCAPES 1
#endif

#if defined OBJ_ELF || defined OBJ_MAYBE_ELF
/* If .size directive failure should be error or warning.  */
static int flag_allow_nonconst_size;

/* TRUE iff GNU Build attribute notes should
   be generated if none are in the input files.  */
static bool flag_generate_build_notes;

/* If section name substitution sequences should be honored */
static int flag_sectname_subst;
#endif

#ifndef LOCAL_LABELS_FB
#define LOCAL_LABELS_FB 0
#endif

#ifndef LABELS_WITHOUT_COLONS
#define LABELS_WITHOUT_COLONS 0
#endif

#define TEXT_SECTION_NAME	".text"
#define DATA_SECTION_NAME	".data"
#define BSS_SECTION_NAME	".bss"

#ifndef OCTETS_PER_BYTE_POWER
#define OCTETS_PER_BYTE_POWER 0
#endif
#ifndef OCTETS_PER_BYTE
#define OCTETS_PER_BYTE (1<<OCTETS_PER_BYTE_POWER)
#endif
#if OCTETS_PER_BYTE != (1<<OCTETS_PER_BYTE_POWER)
 #error "Octets per byte conflicts with its power-of-two definition!"
#endif

#if defined OBJ_ELF || defined OBJ_MAYBE_ELF
/* On ELF platforms, mark debug sections with SEC_ELF_OCTETS */
#define SEC_OCTETS (IS_ELF ? SEC_ELF_OCTETS : 0)
#else
#define SEC_OCTETS 0
#endif

/* sb.h - header file for string buffer manipulation routines */
#ifndef SB_H
#define SB_H

/* String blocks
   Obstacks provide all the functionality needed, but are too
   complicated, hence the sb.
   An sb is allocated by the caller.  */

typedef struct sb {
  char *ptr;			/* Points to the current block.  */
  size_t len;			/* How much is used.  */
  size_t max;			/* The maximum length.  */
}
sb;

/* Actually in input-scrub.c.  */
enum expansion { expanding_none, expanding_repeat, expanding_macro, };
#endif /* SB_H */

/* Don't do the contents of this file more than once.  */

#ifndef _OBSTACK_H
#define _OBSTACK_H 1
/* Version 2 with sane types, especially for 64-bit hosts.  */

/* If B is the base of an object addressed by P, return the result of
   aligning P to the next multiple of A + 1.  B and P must be of type
   char *.  A + 1 must be a power of 2.  */

#define __BPTR_ALIGN(B, P, A) ((B) + (((P) - (B) + (A)) & ~(A)))

/* Similar to __BPTR_ALIGN (B, P, A), except optimize the common case
   where pointers can be converted to integers, aligned as integers,
   and converted back again.  If ptrdiff_t is narrower than a
   pointer (e.g., the AS/400), play it safe and compute the alignment
   relative to B.  Otherwise, use the faster strategy of computing the
   alignment relative to 0.  */

#define __PTR_ALIGN(B, P, A)						\
  (sizeof (ptrdiff_t) < sizeof (void *) ? __BPTR_ALIGN (B, P, A)	\
   : (char *) (((ptrdiff_t) (P) + (A)) & ~(A)))

#ifndef __attribute_pure__
# if defined __GNUC_MINOR__ && __GNUC__ * 1000 + __GNUC_MINOR__ >= 2096
#  define __attribute_pure__ __attribute__ ((__pure__))
# else
#  define __attribute_pure__
# endif
#endif

struct _obstack_chunk           /* Lives at front of each chunk. */
{
  char *limit;                  /* 1 past end of this chunk */
  struct _obstack_chunk *prev;  /* address of prior chunk or NULL */
  char contents[4];             /* objects begin here */
};

struct obstack          /* control current object in current chunk */
{
  size_t chunk_size;     /* preferred size to allocate chunks in */
  struct _obstack_chunk *chunk; /* address of current struct obstack_chunk */
  char *object_base;            /* address of object we are building */
  char *next_free;              /* where to add next char to current object */
  char *chunk_limit;            /* address of char after current chunk */
  union
  {
    size_t i;
    void *p;
  } temp;                       /* Temporary for some macros.  */
  size_t alignment_mask;  /* Mask of alignment for each object. */

  /* These prototypes vary based on 'use_extra_arg'.  */
  union
  {
    void *(*plain) (size_t);
    void *(*extra) (void *, size_t);
  } chunkfun;
  union
  {
    void (*plain) (void *);
    void (*extra) (void *, void *);
  } freefun;

  void *extra_arg;              /* first arg for chunk alloc/dealloc funcs */
  unsigned use_extra_arg : 1;     /* chunk alloc/dealloc funcs take extra arg */
  unsigned maybe_empty_object : 1; /* There is a possibility that the current
                                      chunk contains a zero-length object.  This
                                      prevents freeing the chunk if we allocate
                                      a bigger chunk to replace it. */
  unsigned alloc_failed : 1;      /* No longer used, as we now call the failed
                                     handler on error, but retained for binary
                                     compatibility.  */
};

static struct obstack notes;	/* eg FixS live here.  */
/* Declare the external functions we use; they are in in the libc.  */
extern int _obstack_begin (struct obstack *,
                           size_t, size_t,
                           void *(*) (size_t), void (*) (void *));
extern void _obstack_free (struct obstack *,void *);
extern void _obstack_newchunk (struct obstack *,size_t);

/* Error handler called when 'obstack_chunk_alloc' failed to allocate
   more memory.  This can be set to a user defined function which
   should either abort gracefully or use longjump - but shouldn't
   return.  The default action is to print a message and abort.  */
static void (*obstack_alloc_failed_handler) (void);

/* Pointer to beginning of object being allocated or to be allocated next.
   Note that this might not be the final address of the object
   because a new chunk might be needed to hold the final size.  */

#define obstack_base(h) ((void *) (h)->object_base)

/* Size for allocating ordinary chunks.  */
#define obstack_chunk_size(h) ((h)->chunk_size)

/* Pointer to next byte not yet allocated in current chunk.  */
#define obstack_next_free(h) ((void *) (h)->next_free)

/* Mask specifying low bits that should be clear in address of an object.  */
#define obstack_alignment_mask(h) ((h)->alignment_mask)

/* To prevent prototype warnings provide complete argument list.  */
#define obstack_init(h)							      \
  _obstack_begin((h),0,0,obstack_chunk_alloc, obstack_chunk_free)

#define obstack_begin(h, size)						      \
  _obstack_begin ((h), (size), 0, obstack_chunk_alloc, obstack_chunk_free)

#define obstack_specify_allocation(h, size, alignment, chunkfun, freefun)     \
  _obstack_begin ((h), (size), (alignment), chunkfun, freefun)

#define obstack_specify_allocation_with_arg(h, size, alignment, chunkfun, freefun, arg) \
  _obstack_begin_1 ((h), (size), (alignment),freefun, arg)

#define obstack_chunkfun(h, newchunkfun)				      \
  ((void) ((h)->chunkfun.extra = (void *(*) (void *, size_t)) (newchunkfun)))

#define obstack_freefun(h, newfreefun)					      \
  ((void) ((h)->freefun.extra = (void *(*) (void *, void *)) (newfreefun)))

#define obstack_1grow_fast(h, achar) ((void) (*((h)->next_free)++ = (achar)))

#define obstack_blank_fast(h, n) ((void) ((h)->next_free += (n)))

#define obstack_memory_used(h) _obstack_memory_used (h)

#if defined __GNUC__
# if !defined __GNUC_MINOR__ || __GNUC__ * 1000 + __GNUC_MINOR__ < 2008
#  define __extension__
# endif

/* For GNU C, if not -traditional,
   we can define these macros to compute all args only once
   without using a global variable.
   Also, we can avoid using the 'temp' slot, to make faster code.  */

# define obstack_object_size(OBSTACK)					      \
  __extension__								      \
    ({ struct obstack const *__o = (OBSTACK);				      \
       (size_t) (__o->next_free - __o->object_base); })

/* The local variable is named __o1 to avoid a shadowed variable
   warning when invoked from other obstack macros.  */
# define obstack_room(OBSTACK)						      \
  __extension__								      \
    ({ struct obstack const *__o1 = (OBSTACK);				      \
       (size_t) (__o1->chunk_limit - __o1->next_free); })

# define obstack_empty_p(OBSTACK)					      \
  __extension__								      \
    ({ struct obstack const *__o = (OBSTACK);				      \
       (__o->chunk->prev == 0						      \
        && __o->next_free == __PTR_ALIGN ((char *) __o->chunk,		      \
                                          __o->chunk->contents,		      \
                                          __o->alignment_mask)); })

# define obstack_grow(OBSTACK, where, length)				      \
  __extension__								      \
    ({ struct obstack *__o = (OBSTACK);					      \
       size_t __len = (length);				      \
       if (obstack_room (__o) < __len)					      \
         _obstack_newchunk (__o, __len);				      \
       memcpy (__o->next_free, where, __len);				      \
       __o->next_free += __len;						      \
       (void) 0; })

# define obstack_grow0(OBSTACK, where, length)				      \
  __extension__								      \
    ({ struct obstack *__o = (OBSTACK);					      \
       size_t __len = (length);				      \
       if (obstack_room (__o) < __len + 1)				      \
         _obstack_newchunk (__o, __len + 1);				      \
       memcpy (__o->next_free, where, __len);				      \
       __o->next_free += __len;						      \
       *(__o->next_free)++ = 0;						      \
       (void) 0; })

# define obstack_1grow(OBSTACK, datum)					      \
  __extension__								      \
    ({ struct obstack *__o = (OBSTACK);					      \
       if (obstack_room (__o) < 1)					      \
         _obstack_newchunk (__o, 1);					      \
       obstack_1grow_fast (__o, datum); })

/* These assume that the obstack alignment is good enough for pointers
   or ints, and that the data added so far to the current object
   shares that much alignment.  */

# define obstack_ptr_grow(OBSTACK, datum)				      \
  __extension__								      \
    ({ struct obstack *__o = (OBSTACK);					      \
       if (obstack_room (__o) < sizeof (void *))			      \
         _obstack_newchunk (__o, sizeof (void *));			      \
       obstack_ptr_grow_fast (__o, datum); })

# define obstack_int_grow(OBSTACK, datum)				      \
  __extension__								      \
    ({ struct obstack *__o = (OBSTACK);					      \
       if (obstack_room (__o) < sizeof (int))				      \
         _obstack_newchunk (__o, sizeof (int));				      \
       obstack_int_grow_fast (__o, datum); })

# define obstack_ptr_grow_fast(OBSTACK, aptr)				      \
  __extension__								      \
    ({ struct obstack *__o1 = (OBSTACK);				      \
       void *__p1 = __o1->next_free;					      \
       *(const void **) __p1 = (aptr);					      \
       __o1->next_free += sizeof (const void *);			      \
       (void) 0; })

# define obstack_int_grow_fast(OBSTACK, aint)				      \
  __extension__								      \
    ({ struct obstack *__o1 = (OBSTACK);				      \
       void *__p1 = __o1->next_free;					      \
       *(int *) __p1 = (aint);						      \
       __o1->next_free += sizeof (int);					      \
       (void) 0; })

# define obstack_blank(OBSTACK, length)					      \
  __extension__								      \
    ({ struct obstack *__o = (OBSTACK);					      \
       size_t __len = (length);				      \
       if (obstack_room (__o) < __len)					      \
         _obstack_newchunk (__o, __len);				      \
       obstack_blank_fast (__o, __len); })

# define obstack_alloc(OBSTACK, length)					      \
  __extension__								      \
    ({ struct obstack *__h = (OBSTACK);					      \
       obstack_blank (__h, (length));					      \
       obstack_finish (__h); })

# define obstack_copy(OBSTACK, where, length)				      \
  __extension__								      \
    ({ struct obstack *__h = (OBSTACK);					      \
       obstack_grow (__h, (where), (length));				      \
       obstack_finish (__h); })

# define obstack_copy0(OBSTACK, where, length)				      \
  __extension__								      \
    ({ struct obstack *__h = (OBSTACK);					      \
       obstack_grow0 (__h, (where), (length));				      \
       obstack_finish (__h); })

/* The local variable is named __o1 to avoid a shadowed variable
   warning when invoked from other obstack macros, typically obstack_free.  */
# define obstack_finish(OBSTACK)					      \
  __extension__								      \
    ({ struct obstack *__o1 = (OBSTACK);				      \
       void *__value = (void *) __o1->object_base;			      \
       if (__o1->next_free == __value)					      \
         __o1->maybe_empty_object = 1;					      \
       __o1->next_free							      \
         = __PTR_ALIGN (__o1->object_base, __o1->next_free,		      \
                        __o1->alignment_mask);				      \
       if ((size_t) (__o1->next_free - (char *) __o1->chunk)		      \
           > (size_t) (__o1->chunk_limit - (char *) __o1->chunk))	      \
         __o1->next_free = __o1->chunk_limit;				      \
       __o1->object_base = __o1->next_free;				      \
       __value; })

# define obstack_free(OBSTACK, OBJ)					      \
  __extension__								      \
    ({ struct obstack *__o = (OBSTACK);					      \
       void *__obj = (void *) (OBJ);					      \
       if (__obj > (void *) __o->chunk && __obj < (void *) __o->chunk_limit)  \
         __o->next_free = __o->object_base = (char *) __obj;		      \
       else								      \
         _obstack_free (__o, __obj); })

#else /* not __GNUC__ */

# define obstack_object_size(h)						      \
  ((size_t) ((h)->next_free - (h)->object_base))

# define obstack_room(h)						      \
  ((size_t) ((h)->chunk_limit - (h)->next_free))

# define obstack_empty_p(h)						      \
  ((h)->chunk->prev == 0						      \
   && (h)->next_free == __PTR_ALIGN ((char *) (h)->chunk,		      \
                                     (h)->chunk->contents,		      \
                                     (h)->alignment_mask))

/* Note that the call to _obstack_newchunk is enclosed in (..., 0)
   so that we can avoid having void expressions
   in the arms of the conditional expression.
   Casting the third operand to void was tried before,
   but some compilers won't accept it.  */

# define obstack_grow(h, where, length)					      \
  ((h)->temp.i = (length),						      \
   ((obstack_room (h) < (h)->temp.i)					      \
   ? (_obstack_newchunk ((h), (h)->temp.i), 0) : 0),			      \
   memcpy ((h)->next_free, where, (h)->temp.i),				      \
   (h)->next_free += (h)->temp.i,					      \
   (void) 0)

# define obstack_grow0(h, where, length)				      \
  ((h)->temp.i = (length),						      \
   ((obstack_room (h) < (h)->temp.i + 1)				      \
   ? (_obstack_newchunk ((h), (h)->temp.i + 1), 0) : 0),		      \
   memcpy ((h)->next_free, where, (h)->temp.i),				      \
   (h)->next_free += (h)->temp.i,					      \
   *((h)->next_free)++ = 0,						      \
   (void) 0)

# define obstack_1grow(h, datum)					      \
  (((obstack_room (h) < 1)						      \
    ? (_obstack_newchunk ((h), 1), 0) : 0),				      \
   obstack_1grow_fast (h, datum))

# define obstack_ptr_grow(h, datum)					      \
  (((obstack_room (h) < sizeof (char *))				      \
    ? (_obstack_newchunk ((h), sizeof (char *)), 0) : 0),		      \
   obstack_ptr_grow_fast (h, datum))

# define obstack_int_grow(h, datum)					      \
  (((obstack_room (h) < sizeof (int))					      \
    ? (_obstack_newchunk ((h), sizeof (int)), 0) : 0),			      \
   obstack_int_grow_fast (h, datum))

# define obstack_ptr_grow_fast(h, aptr)					      \
  (((const void **) ((h)->next_free += sizeof (void *)))[-1] = (aptr),	      \
   (void) 0)

# define obstack_int_grow_fast(h, aint)					      \
  (((int *) ((h)->next_free += sizeof (int)))[-1] = (aint),		      \
   (void) 0)

# define obstack_blank(h, length)					      \
  ((h)->temp.i = (length),						      \
   ((obstack_room (h) < (h)->temp.i)					      \
   ? (_obstack_newchunk ((h), (h)->temp.i), 0) : 0),			      \
   obstack_blank_fast (h, (h)->temp.i))

# define obstack_alloc(h, length)					      \
  (obstack_blank ((h), (length)), obstack_finish ((h)))

# define obstack_copy(h, where, length)					      \
  (obstack_grow ((h), (where), (length)), obstack_finish ((h)))

# define obstack_copy0(h, where, length)				      \
  (obstack_grow0 ((h), (where), (length)), obstack_finish ((h)))

# define obstack_finish(h)						      \
  (((h)->next_free == (h)->object_base					      \
    ? (((h)->maybe_empty_object = 1), 0)				      \
    : 0),								      \
   (h)->temp.p = (h)->object_base,					      \
   (h)->next_free							      \
     = __PTR_ALIGN ((h)->object_base, (h)->next_free,			      \
                    (h)->alignment_mask),				      \
   (((size_t) ((h)->next_free - (char *) (h)->chunk)			      \
     > (size_t) ((h)->chunk_limit - (char *) (h)->chunk))		      \
   ? ((h)->next_free = (h)->chunk_limit) : 0),				      \
   (h)->object_base = (h)->next_free,					      \
   (h)->temp.p)

# define obstack_free(h, obj)						      \
  ((h)->temp.p = (void *) (obj),					      \
   (((h)->temp.p > (void *) (h)->chunk					      \
     && (h)->temp.p < (void *) (h)->chunk_limit)			      \
    ? (void) ((h)->next_free = (h)->object_base = (char *) (h)->temp.p)       \
    : _obstack_free ((h), (h)->temp.p)))

#endif /* not __GNUC__ */

#endif /* _OBSTACK_H */
struct frch_cfi_data;

typedef struct frchain			/* control building of a frag chain */
{				/* FRCH = FRagment CHain control */
  struct frag *frch_root;	/* 1st struct frag in chain, or NULL */
  struct frag *frch_last;	/* last struct frag in chain, or NULL */
  struct frchain *frch_next;	/* next in chain of struct frchain-s */
  subsegT frch_subseg;		/* subsegment number of this chain */
  fixS *fix_root;		/* Root of fixups for this subsegment.  */
  fixS *fix_tail;		/* Last fixup for this subsegment.  */
  struct obstack frch_obstack;	/* for objects in this frag chain */
  fragS *frch_frag_now;		/* frag_now for this subsegment */
  struct frch_cfi_data *frch_cfi_data;
} frchainS;

/* Frchain we are assembling into now.  That is, the current segment's
   frag chain, even if it contains no (complete) frags.  */
static frchainS *frchain_now;

typedef struct segment_info_struct {
  frchainS *frchainP;
  unsigned int hadone : 1;

  /* This field is set if this is a .bss section which does not really
     have any contents.  Once upon a time a .bss section did not have
     any frags, but that is no longer true.  This field prevent the
     SEC_HAS_CONTENTS flag from being set for the section even if
     there are frags.  */
  unsigned int bss : 1;

  int user_stuff;

  /* Fixups for this segment.  This is only valid after the frchains
     are run together.  */
  fixS *fix_root;
  fixS *fix_tail;

  symbolS *dot;

  struct lineno_list *lineno_list_head;
  struct lineno_list *lineno_list_tail;

  /* Which BFD section does this gas segment correspond to?  */
  asection *bfd_section;

  /* NULL, or pointer to the gas symbol that is the section symbol for
     this section.  sym->bsym and bfd_section->symbol should be the same.  */
  symbolS *sym;

  /* Used by dwarf2dbg.c for this section's line table entries.  */
  void *dwarf2_line_seg;

  union {
    /* Current size of section h holding stabs strings.  */
    unsigned long stab_string_size;
    /* Initial frag for ELF.  */
    char *p;
  }
  stabu;

  TC_SEGMENT_INFO_TYPE tc_segment_info_data;
} segment_info_type;


#define seg_info(sec) \
  ((segment_info_type *) bfd_section_userdata (sec))

static symbolS *section_symbol (segT);
static void subsegs_print_statistics (FILE *);
static void print_expr_1 (FILE *file, expressionS *exp);
static void output_file_close (void);
static void output_file_create (const char *name);

#define BFD_VERSION_DATE 20230531
#define BFD_VERSION 240500000
#define BFD_VERSION_STRING  "(GNU Binutils) " "2.40.50.20230531"
#define REPORT_BUGS_TO "<https://sourceware.org/bugzilla/>"
static void delete_bfd(bfd *);
struct section_hash_entry {
  struct bfd_hash_entry root;
  asection section;
};
static void * bfd_arch_default_fill (size_t count,
		       bool is_bigendian ATTRIBUTE_UNUSED,
		       bool code ATTRIBUTE_UNUSED);
static bool bfd_default_scan (const bfd_arch_info_type *info ATTRIBUTE_UNUSED,
				const char *string ATTRIBUTE_UNUSED);
static void * bfd_realloc (void *ptr, size_t size);
static void *bfd_realloc_or_free (void *, size_t) ;
static unsigned int bfd_log2 (bfd_vma x) ;
#if GCC_VERSION >= 7000
#define _bfd_mul_overflow(a, b, res) __builtin_mul_overflow (a, b, res)
#else
/* Assumes unsigned values.  Careful!  Args evaluated multiple times.  */
#define _bfd_mul_overflow(a, b, res) \
  ((*res) = (a), (*res) *= (b), (b) != 0 && (*res) / (b) != (a))
#endif

/* Extracted from bfd.c.  */
bfd_error_handler_type _bfd_set_error_handler_caching (bfd *);

const char *_bfd_get_error_program_name (void);

/* Extracted from bfdio.c.  */
struct bfd_iovec
{
  /* To avoid problems with macros, a "b" rather than "f"
     prefix is prepended to each method name.  */
  /* Attempt to read/write NBYTES on ABFD's IOSTREAM storing/fetching
     bytes starting at PTR.  Return the number of bytes actually
     transfered (a read past end-of-file returns less than NBYTES),
     or -1 (setting <<bfd_error>>) if an error occurs.  */
  file_ptr (*bread) (struct bfd *abfd, void *ptr, file_ptr nbytes);
  file_ptr (*bwrite) (struct bfd *abfd, const void *ptr,
		      file_ptr nbytes);
  /* Return the current IOSTREAM file offset, or -1 (setting <<bfd_error>>
     if an error occurs.  */
  file_ptr (*btell) (struct bfd *abfd);
  /* For the following, on successful completion a value of 0 is returned.
     Otherwise, a value of -1 is returned (and <<bfd_error>> is set).  */
  int (*bseek) (struct bfd *abfd, file_ptr offset, int whence);
  int (*bclose) (struct bfd *abfd);
  int (*bflush) (struct bfd *abfd);
  int (*bstat) (struct bfd *abfd, struct stat *sb);
  /* Mmap a part of the files. ADDR, LEN, PROT, FLAGS and OFFSET are the usual
     mmap parameter, except that LEN and OFFSET do not need to be page
     aligned.  Returns (void *)-1 on failure, mmapped address on success.
     Also write in MAP_ADDR the address of the page aligned buffer and in
     MAP_LEN the size mapped (a page multiple).  Use unmap with MAP_ADDR and
     MAP_LEN to unmap.  */
  void *(*bmmap) (struct bfd *abfd, void *addr, size_t len,
		  int prot, int flags, file_ptr offset,
		  void **map_addr, size_t *map_len);
};
extern const struct bfd_iovec _bfd_memory_iovec;

/* Extracted from archive.c.  */
/* Used in generating armaps (archive tables of contents).  */
struct orl             /* Output ranlib.  */
{
  char **name;         /* Symbol name.  */
  union
  {
    file_ptr pos;
    bfd *abfd;
  } u;                 /* bfd* or file position.  */
  int namidx;          /* Index into string table.  */
};

/* Extracted from archures.c.  */
static const bfd_arch_info_type bfd_default_arch_struct;
static bool bfd_default_scan
   (const struct bfd_arch_info *info, const char *string);

static void *bfd_arch_default_fill (size_t count,
    bool is_bigendian,
    bool code);

/* Extracted from bfdwin.c.  */
typedef struct _bfd_window_internal
{
  struct _bfd_window_internal *next;
  void *data;
  size_t size;
  int refcount : 31;           /* should be enough...  */
  unsigned mapped : 1;         /* 1 = mmap, 0 = malloc */
} bfd_window_internal;
#define IS_DIR_SEPARATOR(c) (c == '/')
static int filename_cmp (const char *s1, const char *s2);
#define FILENAME_CMP(s1, s2)	filename_cmp(s1, s2)
static int filename_ncmp (const char *s1, const char *s2, size_t n);

/* gnu_stab.h  Definitions for GNU extensions to STABS */
#ifndef __GNU_STAB__
/* Indicate the GNU stab.h is in use.  */
#define __GNU_STAB__
#define __define_stab(NAME, CODE, STRING) NAME=CODE,
#define __define_stab_duplicate(NAME, CODE, STRING) NAME=CODE,
enum __stab_debug_code {
/* Table of DBX symbol codes for the GNU system.
   New stab from Solaris 2.  This uses an n_type of 0, which in a.out files
   overlaps the N_UNDF used for ordinary symbols.  In ELF files, the
   debug information is in a different file section, so there is no conflict.
   This symbol's n_value gives the size of the string section associated
   with this file.  The symbol's n_strx (relative to the just-updated
   string section start address) gives the name of the source file,
   e.g. "foo.c", without any path information.  The symbol's n_desc gives
   the count of upcoming symbols associated with this file (not including
   this one).  */
/* __define_stab (N_UNDF, 0x00, "UNDF")  */

/* Global variable.  Only the name is significant.
   To find the address, look in the corresponding external symbol.  */
__define_stab (N_GSYM, 0x20, "GSYM")

/* Function name for BSD Fortran.  Only the name is significant.
   To find the address, look in the corresponding external symbol.  */
__define_stab (N_FNAME, 0x22, "FNAME")

/* Function name or text-segment variable for C.  Value is its address.
   Desc is supposedly starting line number, but GCC doesn't set it
   and DBX seems not to miss it.  */
__define_stab (N_FUN, 0x24, "FUN")

/* Data-segment variable with internal linkage.  Value is its address.
   "Static Sym".  */
__define_stab (N_STSYM, 0x26, "STSYM")

/* BSS-segment variable with internal linkage.  Value is its address.  */
__define_stab (N_LCSYM, 0x28, "LCSYM")

/* Name of main routine.  Only the name is significant.  */
__define_stab (N_MAIN, 0x2a, "MAIN")

/* Solaris2:  Read-only data symbols.  */
__define_stab (N_ROSYM, 0x2c, "ROSYM")

/* MacOS X:
   The beginning of a relocatable function block - including stabs.  */
__define_stab (N_BNSYM, 0x2e, "BNSYM")

/* Global symbol in Pascal.
   Supposedly the value is its line number; I'm skeptical.  */
__define_stab (N_PC, 0x30, "PC")

/* Number of symbols:  0, files,,funcs,lines according to Ultrix V4.0. */
__define_stab (N_NSYMS, 0x32, "NSYMS")

/* "No DST map for sym: name, ,0,type,ignored"  according to Ultrix V4.0. */
__define_stab (N_NOMAP, 0x34, "NOMAP")

/* New stab from Solaris 2.  Like N_SO, but for the object file.  Two in
   a row provide the build directory and the relative path of the .o from it.
   Solaris2 uses this to avoid putting the stabs info into the linked
   executable; this stab goes into the ".stab.index" section, and the debugger
   reads the real stabs directly from the .o files instead.  */
__define_stab (N_OBJ, 0x38, "OBJ")

/* New stab from Solaris 2.  Options for the debugger, related to the
   source language for this module.  E.g. whether to use ANSI
   integral promotions or traditional integral promotions.  */
__define_stab (N_OPT, 0x3c, "OPT")

/* Register variable.  Value is number of register.  */
__define_stab (N_RSYM, 0x40, "RSYM")

/* Modula-2 compilation unit.  Can someone say what info it contains?  */
__define_stab (N_M2C, 0x42, "M2C")

/* Line number in text segment.  Desc is the line number;
   value is corresponding address.  On Solaris2, the line number is
   relative to the start of the current function.  */
__define_stab (N_SLINE, 0x44, "SLINE")

/* Similar, for data segment.  */
__define_stab (N_DSLINE, 0x46, "DSLINE")

/* Similar, for bss segment.  */
__define_stab (N_BSLINE, 0x48, "BSLINE")

/* Sun's source-code browser stabs.  ?? Don't know what the fields are.
   Supposedly the field is "path to associated .cb file".  THIS VALUE
   OVERLAPS WITH N_BSLINE!  */
__define_stab_duplicate (N_BROWS, 0x48, "BROWS")

/* GNU Modula-2 definition module dependency.  Value is the modification time
   of the definition file.  Other is non-zero if it is imported with the
   GNU M2 keyword %INITIALIZE.  Perhaps N_M2C can be used if there
   are enough empty fields? */
__define_stab(N_DEFD, 0x4a, "DEFD")

/* New in Solaris2.  Function start/body/end line numbers.  */
__define_stab(N_FLINE, 0x4C, "FLINE")

/* MacOS X: This tells the end of a relocatable function + debugging info.  */
__define_stab(N_ENSYM, 0x4E, "ENSYM")

/* THE FOLLOWING TWO STAB VALUES CONFLICT.  Happily, one is for Modula-2
   and one is for C++.   Still,... */
/* GNU C++ exception variable.  Name is variable name.  */
__define_stab (N_EHDECL, 0x50, "EHDECL")
/* Modula2 info "for imc":  name,,0,0,0  according to Ultrix V4.0.  */
__define_stab_duplicate (N_MOD2, 0x50, "MOD2")

/* GNU C++ `catch' clause.  Value is its address.  Desc is nonzero if
   this entry is immediately followed by a CAUGHT stab saying what exception
   was caught.  Multiple CAUGHT stabs means that multiple exceptions
   can be caught here.  If Desc is 0, it means all exceptions are caught
   here.  */
__define_stab (N_CATCH, 0x54, "CATCH")

/* Structure or union element.  Value is offset in the structure.  */
__define_stab (N_SSYM, 0x60, "SSYM")

/* Solaris2:  Last stab emitted for module.  */
__define_stab (N_ENDM, 0x62, "ENDM")

/* Name of main source file.
   Value is starting text address of the compilation.
   If multiple N_SO's appear, the first to contain a trailing / is the
   compilation directory.  The first to not contain a trailing / is the
   source file name, relative to the compilation directory.  Others (perhaps
   resulting from cfront) are ignored.
   On Solaris2, value is undefined, but desc is a source-language code.  */

__define_stab (N_SO, 0x64, "SO")

/* Apple:  This is the stab that associated the .o file with the
   N_SO stab, in the case where debug info is mostly stored in the .o file.  */
__define_stab (N_OSO, 0x66, "OSO")

/* SunPro F77:  Name of alias.  */
__define_stab (N_ALIAS, 0x6c, "ALIAS")

/* Automatic variable in the stack.  Value is offset from frame pointer.
   Also used for type descriptions.  */
__define_stab (N_LSYM, 0x80, "LSYM")

/* Beginning of an include file.  Only Sun uses this.
   In an object file, only the name is significant.
   The Sun linker puts data into some of the other fields.  */
__define_stab (N_BINCL, 0x82, "BINCL")

/* Name of sub-source file ( include file).
   Value is starting text address of the compilation.  */
__define_stab (N_SOL, 0x84, "SOL")

/* Parameter variable.  Value is offset from argument pointer.
   (On most machines the argument pointer is the same as the frame pointer.  */
__define_stab (N_PSYM, 0xa0, "PSYM")

/* End of an include file.  No name.
   This and N_BINCL act as brackets around the file's output.
   In an object file, there is no significant data in this entry.
   The Sun linker puts data into some of the fields.  */
__define_stab (N_EINCL, 0xa2, "EINCL")

/* Alternate entry point.  Value is its address.  */
__define_stab (N_ENTRY, 0xa4, "ENTRY")

/* Beginning of lexical block.
   The desc is the nesting level in lexical blocks.
   The value is the address of the start of the text for the block.
   The variables declared inside the block *precede* the N_LBRAC symbol.
   On Solaris2, the value is relative to the start of the current function.  */
__define_stab (N_LBRAC, 0xc0, "LBRAC")

/* Place holder for deleted include file.  Replaces a N_BINCL and everything
   up to the corresponding N_EINCL.  The Sun linker generates these when
   it finds multiple identical copies of the symbols from an include file.
   This appears only in output from the Sun linker.  */
__define_stab (N_EXCL, 0xc2, "EXCL")

/* Modula-2 scope information.  Can someone say what info it contains?  */
__define_stab (N_SCOPE, 0xc4, "SCOPE")

/* Solaris2: Patch Run Time Checker.  */
__define_stab (N_PATCH, 0xd0, "PATCH")

/* End of a lexical block.  Desc matches the N_LBRAC's desc.
   The value is the address of the end of the text for the block.
   On Solaris2, the value is relative to the start of the current function.  */
__define_stab (N_RBRAC, 0xe0, "RBRAC")

/* Begin named common block.  Only the name is significant.  */
__define_stab (N_BCOMM, 0xe2, "BCOMM")

/* End named common block.  Only the name is significant
   (and it should match the N_BCOMM).  */
__define_stab (N_ECOMM, 0xe4, "ECOMM")

/* Member of a common block; value is offset within the common block.
   This should occur within a BCOMM/ECOMM pair.  */
__define_stab (N_ECOML, 0xe8, "ECOML")

/* Solaris2: Pascal "with" statement: type,,0,0,offset */
__define_stab (N_WITH, 0xea, "WITH")

/* These STAB's are used on Gould systems for Non-Base register symbols
   or something like that.  FIXME.  I have assigned the values at random
   since I don't have a Gould here.  Fixups from Gould folk welcome... */
__define_stab (N_NBTEXT, 0xF0, "NBTEXT")
__define_stab (N_NBDATA, 0xF2, "NBDATA")
__define_stab (N_NBBSS,  0xF4, "NBBSS")
__define_stab (N_NBSTS,  0xF6, "NBSTS")
__define_stab (N_NBLCS,  0xF8, "NBLCS")
/* Second symbol entry containing a length-value for the preceding entry.
   The value is the length.  */
__define_stab (N_LENG, 0xfe, "LENG")

/* The above information, in matrix format.

			STAB MATRIX
	_________________________________________________
	| 00 - 1F are not dbx stab symbols		|
	| In most cases, the low bit is the EXTernal bit|

	| 00 UNDEF  | 02 ABS	| 04 TEXT   | 06 DATA	|
	| 01  |EXT  | 03  |EXT	| 05  |EXT  | 07  |EXT	|

	| 08 BSS    | 0A INDR	| 0C FN_SEQ | 0E WEAKA	|
	| 09  |EXT  | 0B 	| 0D WEAKU  | 0F WEAKT	|

	| 10 WEAKD  | 12 COMM	| 14 SETA   | 16 SETT	|
	| 11 WEAKB  | 13	| 15 	    | 17	|

	| 18 SETD   | 1A SETB	| 1C SETV   | 1E WARNING|
	| 19	    | 1B	| 1D 	    | 1F FN	|

	|_______________________________________________|
	| Debug entries with bit 01 set are unused.	|
	| 20 GSYM   | 22 FNAME	| 24 FUN    | 26 STSYM	|
	| 28 LCSYM  | 2A MAIN	| 2C ROSYM  | 2E	|
	| 30 PC	    | 32 NSYMS	| 34 NOMAP  | 36	|
	| 38 OBJ    | 3A	| 3C OPT    | 3E	|
	| 40 RSYM   | 42 M2C	| 44 SLINE  | 46 DSLINE |
	| 48 BSLINE*| 4A DEFD	| 4C FLINE  | 4E	|
	| 50 EHDECL*| 52	| 54 CATCH  | 56        |
	| 58        | 5A        | 5C        | 5E	|
	| 60 SSYM   | 62 ENDM	| 64 SO	    | 66 	|
	| 68 	    | 6A	| 6C ALIAS  | 6E	|
	| 70	    | 72	| 74	    | 76	|
	| 78	    | 7A	| 7C	    | 7E	|
	| 80 LSYM   | 82 BINCL	| 84 SOL    | 86	|
	| 88	    | 8A	| 8C	    | 8E	|
	| 90	    | 92	| 94	    | 96	|
	| 98	    | 9A	| 9C	    | 9E	|
	| A0 PSYM   | A2 EINCL	| A4 ENTRY  | A6	|
	| A8	    | AA	| AC	    | AE	|
	| B0	    | B2	| B4	    | B6	|
	| B8	    | BA	| BC	    | BE	|
	| C0 LBRAC  | C2 EXCL	| C4 SCOPE  | C6	|
	| C8	    | CA	| CC	    | CE	|
	| D0 PATCH  | D2	| D4	    | D6	|
	| D8	    | DA	| DC	    | DE	|
	| E0 RBRAC  | E2 BCOMM	| E4 ECOMM  | E6	|
	| E8 ECOML  | EA WITH	| EC	    | EE	|
	| F0	    | F2	| F4	    | F6	|
	| F8	    | FA	| FC	    | FE LENG	|
	+-----------------------------------------------+
 * 50 EHDECL is also MOD2.
 * 48 BSLINE is also BROWS.
 */
LAST_UNUSED_STAB_CODE
};

#undef __define_stab

/* Definitions of "desc" field for N_SO stabs in Solaris2.  */
#define	N_SO_AS		1
#define	N_SO_C		2
#define	N_SO_ANSI_C	3
#define	N_SO_CC		4	/* C++ */
#define	N_SO_FORTRAN	5
#define	N_SO_PASCAL	6

/* Solaris2: Floating point type values in basic types.  */
#define	NF_NONE		0
#define	NF_SINGLE	1	/* IEEE 32-bit */
#define	NF_DOUBLE	2	/* IEEE 64-bit */
#define	NF_COMPLEX	3	/* Fortran complex */
#define	NF_COMPLEX16	4	/* Fortran double complex */
#define	NF_COMPLEX32	5	/* Fortran complex*16 */
#define	NF_LDOUBLE	6	/* Long double (whatever that is) */
#endif /* __GNU_STAB_ */
//----------------------------------------------------include "safe-ctype.h"
/* <ctype.h> replacement macros. */
/* This is a compatible replacement of the standard C library's <ctype.h>
   with the following properties:

   - Implements all isxxx() macros required by C99.
   - Also implements some character classes useful when
     parsing C-like languages.
   - Does not change behavior depending on the current locale.
   - Behaves properly for all values in the range of a signed or
     unsigned char.

   To avoid conflicts, this header defines the isxxx functions in upper
   case, e.g. ISALPHA not isalpha.  */

#ifndef SAFE_CTYPE_H
#define SAFE_CTYPE_H

/* Determine host character set.  */
#define HOST_CHARSET_UNKNOWN 0
#define HOST_CHARSET_ASCII   1
#define HOST_CHARSET_EBCDIC  2

#if  '\n' == 0x0A && ' ' == 0x20 && '0' == 0x30 \
   && 'A' == 0x41 && 'a' == 0x61 && '!' == 0x21
#  define HOST_CHARSET HOST_CHARSET_ASCII
#else
# if '\n' == 0x15 && ' ' == 0x40 && '0' == 0xF0 \
   && 'A' == 0xC1 && 'a' == 0x81 && '!' == 0x5A
#  define HOST_CHARSET HOST_CHARSET_EBCDIC
# else
#  define HOST_CHARSET HOST_CHARSET_UNKNOWN
# endif
#endif

/* Categories.  */

enum {
  /* In C99 */
  _sch_isblank  = 0x0001,	/* space \t */
  _sch_iscntrl  = 0x0002,	/* nonprinting characters */
  _sch_isdigit  = 0x0004,	/* 0-9 */
  _sch_islower  = 0x0008,	/* a-z */
  _sch_isprint  = 0x0010,	/* any printing character including ' ' */
  _sch_ispunct  = 0x0020,	/* all punctuation */
  _sch_isspace  = 0x0040,	/* space \t \n \r \f \v */
  _sch_isupper  = 0x0080,	/* A-Z */
  _sch_isxdigit = 0x0100,	/* 0-9A-Fa-f */

  /* Extra categories useful to cpplib.  */
  _sch_isidst	= 0x0200,	/* A-Za-z_ */
  _sch_isvsp    = 0x0400,	/* \n \r */
  _sch_isnvsp   = 0x0800,	/* space \t \f \v \0 */

  /* Combinations of the above.  */
  _sch_isalpha  = _sch_isupper|_sch_islower,	/* A-Za-z */
  _sch_isalnum  = _sch_isalpha|_sch_isdigit,	/* A-Za-z0-9 */
  _sch_isidnum  = _sch_isidst|_sch_isdigit,	/* A-Za-z0-9_ */
  _sch_isgraph  = _sch_isalnum|_sch_ispunct,	/* isprint and not space */
  _sch_iscppsp  = _sch_isvsp|_sch_isnvsp,	/* isspace + \0 */
  _sch_isbasic  = _sch_isprint|_sch_iscppsp     /* basic charset of ISO C
						   (plus ` and @)  */
};
/* <ctype.h> replacement macros. */

/* Shorthand */
#define bl _sch_isblank
#define cn _sch_iscntrl
#define di _sch_isdigit
#define is _sch_isidst
#define lo _sch_islower
#define nv _sch_isnvsp
#define pn _sch_ispunct
#define pr _sch_isprint
#define Sp _sch_isspace
#define up _sch_isupper
#define vs _sch_isvsp
#define xd _sch_isxdigit

/* Masks.  */
#define L  (const unsigned short) (lo|is   |pr)	/* lower case letter */
#define XL (const unsigned short) (lo|is|xd|pr)	/* lowercase hex digit */
#define U  (const unsigned short) (up|is   |pr)	/* upper case letter */
#define XU (const unsigned short) (up|is|xd|pr)	/* uppercase hex digit */
#define D  (const unsigned short) (di   |xd|pr)	/* decimal digit */
#define P  (const unsigned short) (pn      |pr)	/* punctuation */
#define _U  (const unsigned short) (pn|is   |pr)	/* underscore */

#define C  (const unsigned short) (         cn)	/* control character */
#define Z  (const unsigned short) (nv      |cn)	/* NUL */
#define M  (const unsigned short) (nv|Sp   |cn)	/* cursor movement: \f \v */
#define V  (const unsigned short) (vs|Sp   |cn)	/* vertical space: \r \n */
#define T  (const unsigned short) (nv|Sp|bl|cn)	/* tab */
#define S  (const unsigned short) (nv|Sp|bl|pr)	/* space */

/* Character classification.  */
static const unsigned short _sch_istable[256] = {
  Z,  C,  C,  C,   C,  C,  C,  C,   /* NUL SOH STX ETX  EOT ENQ ACK BEL */
  C,  T,  V,  M,   M,  V,  C,  C,   /* BS  HT  LF  VT   FF  CR  SO  SI  */
  C,  C,  C,  C,   C,  C,  C,  C,   /* DLE DC1 DC2 DC3  DC4 NAK SYN ETB */
  C,  C,  C,  C,   C,  C,  C,  C,   /* CAN EM  SUB ESC  FS  GS  RS  US  */
  S,  P,  P,  P,   P,  P,  P,  P,   /* SP  !   "   #    $   %   &   '   */
  P,  P,  P,  P,   P,  P,  P,  P,   /* (   )   *   +    ,   -   .   /   */
  D,  D,  D,  D,   D,  D,  D,  D,   /* 0   1   2   3    4   5   6   7   */
  D,  D,  P,  P,   P,  P,  P,  P,   /* 8   9   :   ;    <   =   >   ?   */
  P, XU, XU, XU,  XU, XU, XU,  U,   /* @   A   B   C    D   E   F   G   */
  U,  U,  U,  U,   U,  U,  U,  U,   /* H   I   J   K    L   M   N   O   */
  U,  U,  U,  U,   U,  U,  U,  U,   /* P   Q   R   S    T   U   V   W   */
  U,  U,  U,  P,   P,  P,  P,  _U,  /* X   Y   Z   [    \   ]   ^   _   */
  P, XL, XL, XL,  XL, XL, XL,  L,   /* `   a   b   c    d   e   f   g   */
  L,  L,  L,  L,   L,  L,  L,  L,   /* h   i   j   k    l   m   n   o   */
  L,  L,  L,  L,   L,  L,  L,  L,   /* p   q   r   s    t   u   v   w   */
  L,  L,  L,  P,   P,  P,  P,  C,   /* x   y   z   {    |   }   ~   DEL */

  /* high half of unsigned char is locale-specific, so all tests are
     false in "C" locale */
  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,

  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
};

const unsigned char _sch_tolower[256] = {
   0,  1,  2,  3,   4,  5,  6,  7,   8,  9, 10, 11,  12, 13, 14, 15,
  16, 17, 18, 19,  20, 21, 22, 23,  24, 25, 26, 27,  28, 29, 30, 31,
  32, 33, 34, 35,  36, 37, 38, 39,  40, 41, 42, 43,  44, 45, 46, 47,
  48, 49, 50, 51,  52, 53, 54, 55,  56, 57, 58, 59,  60, 61, 62, 63,
  64,

  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

  91, 92, 93, 94, 95, 96,

  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

 123,124,125,126,127,

 128,129,130,131, 132,133,134,135, 136,137,138,139, 140,141,142,143,
 144,145,146,147, 148,149,150,151, 152,153,154,155, 156,157,158,159,
 160,161,162,163, 164,165,166,167, 168,169,170,171, 172,173,174,175,
 176,177,178,179, 180,181,182,183, 184,185,186,187, 188,189,190,191,

 192,193,194,195, 196,197,198,199, 200,201,202,203, 204,205,206,207,
 208,209,210,211, 212,213,214,215, 216,217,218,219, 220,221,222,223,
 224,225,226,227, 228,229,230,231, 232,233,234,235, 236,237,238,239,
 240,241,242,243, 244,245,246,247, 248,249,250,251, 252,253,254,255,
};

const unsigned char _sch_toupper[256] = {
   0,  1,  2,  3,   4,  5,  6,  7,   8,  9, 10, 11,  12, 13, 14, 15,
  16, 17, 18, 19,  20, 21, 22, 23,  24, 25, 26, 27,  28, 29, 30, 31,
  32, 33, 34, 35,  36, 37, 38, 39,  40, 41, 42, 43,  44, 45, 46, 47,
  48, 49, 50, 51,  52, 53, 54, 55,  56, 57, 58, 59,  60, 61, 62, 63,
  64,

  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

  91, 92, 93, 94, 95, 96,

  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

 123,124,125,126,127,

 128,129,130,131, 132,133,134,135, 136,137,138,139, 140,141,142,143,
 144,145,146,147, 148,149,150,151, 152,153,154,155, 156,157,158,159,
 160,161,162,163, 164,165,166,167, 168,169,170,171, 172,173,174,175,
 176,177,178,179, 180,181,182,183, 184,185,186,187, 188,189,190,191,

 192,193,194,195, 196,197,198,199, 200,201,202,203, 204,205,206,207,
 208,209,210,211, 212,213,214,215, 216,217,218,219, 220,221,222,223,
 224,225,226,227, 228,229,230,231, 232,233,234,235, 236,237,238,239,
 240,241,242,243, 244,245,246,247, 248,249,250,251, 252,253,254,255,
};

#define _sch_test(c, bit) (_sch_istable[(c) & 0xff] & (unsigned short)(bit))

#define ISALPHA(c)  _sch_test(c, _sch_isalpha)
#define ISALNUM(c)  _sch_test(c, _sch_isalnum)
#define ISBLANK(c)  _sch_test(c, _sch_isblank)
#define ISCNTRL(c)  _sch_test(c, _sch_iscntrl)
#define ISDIGIT(c)  _sch_test(c, _sch_isdigit)
#define ISGRAPH(c)  _sch_test(c, _sch_isgraph)
#define ISLOWER(c)  _sch_test(c, _sch_islower)
#define ISPRINT(c)  _sch_test(c, _sch_isprint)
#define ISPUNCT(c)  _sch_test(c, _sch_ispunct)
#define ISSPACE(c)  _sch_test(c, _sch_isspace)
#define ISUPPER(c)  _sch_test(c, _sch_isupper)
#define ISXDIGIT(c) _sch_test(c, _sch_isxdigit)

#define ISIDNUM(c)	_sch_test(c, _sch_isidnum)
#define ISIDST(c)	_sch_test(c, _sch_isidst)
#define IS_ISOBASIC(c)	_sch_test(c, _sch_isbasic)
#define IS_VSPACE(c)	_sch_test(c, _sch_isvsp)
#define IS_NVSPACE(c)	_sch_test(c, _sch_isnvsp)
#define IS_SPACE_OR_NUL(c)	_sch_test(c, _sch_iscppsp)

/* Character transformation.  */
extern const unsigned char  _sch_toupper[256];
extern const unsigned char  _sch_tolower[256];
#define TOUPPER(c) _sch_toupper[(c) & 0xff]
#define TOLOWER(c) _sch_tolower[(c) & 0xff]

/* Prevent the users of safe-ctype.h from accidently using the routines
   from ctype.h.  Initially, the approach was to produce an error when
   detecting that ctype.h has been included.  But this was causing
   trouble as ctype.h might get indirectly included as a result of
   including another system header (for instance gnulib's stdint.h).
   So we include ctype.h here and then immediately redefine its macros.  */

#include <ctype.h>
#undef isalpha
#define isalpha(c) do_not_use_isalpha_with_safe_ctype
#undef isalnum
#define isalnum(c) do_not_use_isalnum_with_safe_ctype
#undef iscntrl
#define iscntrl(c) do_not_use_iscntrl_with_safe_ctype
#undef isdigit
#define isdigit(c) do_not_use_isdigit_with_safe_ctype
#undef isgraph
#define isgraph(c) do_not_use_isgraph_with_safe_ctype
#undef islower
#define islower(c) do_not_use_islower_with_safe_ctype
#undef isprint
#define isprint(c) do_not_use_isprint_with_safe_ctype
#undef ispunct
#define ispunct(c) do_not_use_ispunct_with_safe_ctype
#undef isspace
#define isspace(c) do_not_use_isspace_with_safe_ctype
#undef isupper
#define isupper(c) do_not_use_isupper_with_safe_ctype
#undef isxdigit
#define isxdigit(c) do_not_use_isxdigit_with_safe_ctype
#undef toupper
#define toupper(c) do_not_use_toupper_with_safe_ctype
#undef tolower
#define tolower(c) do_not_use_tolower_with_safe_ctype

#undef L  
#undef XL 
#undef U  
#undef XU 
#undef D  
#undef P  
#undef _U  

#undef C  
#undef Z  
#undef M  
#undef V  
#undef T  
#undef S  
#undef bl 
#undef cn 
#undef di 
#undef is 
#undef lo 
#undef nv 
#undef pn 
#undef pr 
#undef Sp 
#undef up 
#undef vs 
#undef xd 
#endif /* SAFE_CTYPE_H */

/* objalloc.h -- routines to allocate memory for objects */
#ifndef OBJALLOC_H
#define OBJALLOC_H

/* These routines allocate space for an object.  The assumption is
   that the object will want to allocate space as it goes along, but
   will never want to free any particular block.  There is a function
   to free a block, which also frees all more recently allocated
   blocks.  There is also a function to free all the allocated space.

   This is essentially a specialization of obstacks.  The main
   difference is that a block may not be allocated a bit at a time.
   Another difference is that these routines are always built on top
   of malloc, and always pass an malloc failure back to the caller,
   unlike more recent versions of obstacks.  */

/* This is what an objalloc structure looks like.  Callers should not
   refer to these fields, nor should they allocate these structure
   themselves.  Instead, they should only create them via
   objalloc_init, and only access them via the functions and macros
   listed below.  The structure is only defined here so that we can
   access it via macros.  */

struct objalloc {
  char *current_ptr;
  unsigned int current_space;
  void *chunks;
};

/* Work out the required alignment.  */
struct objalloc_align { char x; double d; };

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((unsigned long) &((TYPE *)0)->MEMBER)
#endif
#define OBJALLOC_ALIGN offsetof (struct objalloc_align, d)

/* Create an objalloc structure.  Returns NULL if malloc fails.  */
static struct objalloc *objalloc_create (void);

/* Allocate space from an objalloc structure.  Returns NULL if malloc
   fails.  */

static void *_objalloc_alloc (struct objalloc *, unsigned long);

/* The macro version of objalloc_alloc.  We only define this if using
   gcc, because otherwise we would have to evaluate the arguments
   multiple times, or use a temporary field as obstack.h does.  */

#if defined (__GNUC__) && defined (__STDC__) && __STDC__

/* NextStep 2.0 cc is really gcc 1.93 but it defines __GNUC__ = 2 and
   does not implement __extension__.  But that compiler doesn't define
   __GNUC_MINOR__.  */
#if __GNUC__ < 2 || (__NeXT__ && !__GNUC_MINOR__)
#define __extension__
#endif

#define objalloc_alloc(o, l)						\
  __extension__								\
  ({ struct objalloc *__o = (o);					\
     unsigned long __len = (l);						\
     if (__len == 0)							\
       __len = 1;							\
     __len = (__len + OBJALLOC_ALIGN - 1) &~ (OBJALLOC_ALIGN - 1);	\
     (__len != 0 && __len <= __o->current_space				\
      ? (__o->current_ptr += __len,					\
	 __o->current_space -= __len,					\
	 (void *) (__o->current_ptr - __len))				\
      : _objalloc_alloc (__o, __len)); })

#else /* ! __GNUC__ */

#define objalloc_alloc(o, l) _objalloc_alloc ((o), (l))

#endif /* ! __GNUC__ */

/* Free an entire objalloc structure.  */
static void objalloc_free (struct objalloc *);

/* Free a block allocated by objalloc_alloc.  This also frees all more
   recently allocated blocks.  */
static void objalloc_free_block (struct objalloc *, void *);
#endif /* OBJALLOC_H */
static const struct bfd_elf_special_section special_sections_b[] =
{
  { STRING_COMMA_LEN (".bss"), -2, SHT_NOBITS,   SHF_ALLOC + SHF_WRITE },
  { NULL,		    0,	0, 0,		 0 }
};

static const struct bfd_elf_special_section special_sections_c[] =
{
  { STRING_COMMA_LEN (".comment"), 0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".ctf"),	0, SHT_PROGBITS,    0 },
  { NULL,			0, 0, 0,	    0 }
};

static const struct bfd_elf_special_section special_sections_d[] =
{
  { STRING_COMMA_LEN (".data"),		-2, SHT_PROGBITS, SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".data1"),	 0, SHT_PROGBITS, SHF_ALLOC + SHF_WRITE },
  /* There are more DWARF sections than these, but they needn't be added here
     unless you have to cope with broken compilers that don't emit section
     attributes or you want to help the user writing assembler.  */
  { STRING_COMMA_LEN (".debug"),	 0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".debug_line"),	 0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".debug_info"),	 0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".debug_abbrev"),	 0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".debug_aranges"), 0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".dynamic"),	 0, SHT_DYNAMIC,  SHF_ALLOC },
  { STRING_COMMA_LEN (".dynstr"),	 0, SHT_STRTAB,	  SHF_ALLOC },
  { STRING_COMMA_LEN (".dynsym"),	 0, SHT_DYNSYM,	  SHF_ALLOC },
  { NULL,		       0,	 0, 0,		  0 }
};

static const struct bfd_elf_special_section special_sections_f[] =
{
  { STRING_COMMA_LEN (".fini"),	       0, SHT_PROGBITS,	  SHF_ALLOC + SHF_EXECINSTR },
  { STRING_COMMA_LEN (".fini_array"), -2, SHT_FINI_ARRAY, SHF_ALLOC + SHF_WRITE },
  { NULL,			   0 , 0, 0,		  0 }
};

static const struct bfd_elf_special_section special_sections_g[] =
{
  { STRING_COMMA_LEN (".gnu.linkonce.b"), -2, SHT_NOBITS,      SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".gnu.linkonce.n"), -2, SHT_NOBITS,      SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".gnu.linkonce.p"), -2, SHT_PROGBITS,    SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".gnu.lto_"),	  -1, SHT_PROGBITS,    SHF_EXCLUDE },
  { STRING_COMMA_LEN (".got"),		   0, SHT_PROGBITS,    SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".gnu.version"),	   0, SHT_GNU_versym,  0 },
  { STRING_COMMA_LEN (".gnu.version_d"),   0, SHT_GNU_verdef,  0 },
  { STRING_COMMA_LEN (".gnu.version_r"),   0, SHT_GNU_verneed, 0 },
  { STRING_COMMA_LEN (".gnu.liblist"),	   0, SHT_GNU_LIBLIST, SHF_ALLOC },
  { STRING_COMMA_LEN (".gnu.conflict"),	   0, SHT_RELA,	       SHF_ALLOC },
  { STRING_COMMA_LEN (".gnu.hash"),	   0, SHT_GNU_HASH,    SHF_ALLOC },
  { NULL,			 0,	   0, 0,	       0 }
};

static const struct bfd_elf_special_section special_sections_h[] =
{
  { STRING_COMMA_LEN (".hash"), 0, SHT_HASH,	 SHF_ALLOC },
  { NULL,		     0, 0, 0,		 0 }
};

static const struct bfd_elf_special_section special_sections_i[] =
{
  { STRING_COMMA_LEN (".init"),	       0, SHT_PROGBITS,	  SHF_ALLOC + SHF_EXECINSTR },
  { STRING_COMMA_LEN (".init_array"), -2, SHT_INIT_ARRAY, SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".interp"),      0, SHT_PROGBITS,	  0 },
  { NULL,		       0,      0, 0,		  0 }
};

static const struct bfd_elf_special_section special_sections_l[] =
{
  { STRING_COMMA_LEN (".line"), 0, SHT_PROGBITS, 0 },
  { NULL,		     0, 0, 0,		 0 }
};

static const struct bfd_elf_special_section special_sections_n[] =
{
  { STRING_COMMA_LEN (".noinit"),	 -2, SHT_NOBITS,   SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".note.GNU-stack"), 0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".note"),		 -1, SHT_NOTE,	   0 },
  { NULL,		     0,		  0, 0,		   0 }
};

static const struct bfd_elf_special_section special_sections_p[] =
{
  { STRING_COMMA_LEN (".persistent.bss"), 0, SHT_NOBITS,	SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".persistent"),	 -2, SHT_PROGBITS,	SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".preinit_array"), -2, SHT_PREINIT_ARRAY, SHF_ALLOC + SHF_WRITE },
  { STRING_COMMA_LEN (".plt"),		  0, SHT_PROGBITS,	SHF_ALLOC + SHF_EXECINSTR },
  { NULL,		    0,		  0, 0,			0 }
};

static const struct bfd_elf_special_section special_sections_r[] =
{
  { STRING_COMMA_LEN (".rodata"), -2, SHT_PROGBITS, SHF_ALLOC },
  { STRING_COMMA_LEN (".rodata1"), 0, SHT_PROGBITS, SHF_ALLOC },
  { STRING_COMMA_LEN (".relr.dyn"), 0, SHT_RELR, SHF_ALLOC },
  { STRING_COMMA_LEN (".rela"),	  -1, SHT_RELA,	    0 },
  { STRING_COMMA_LEN (".rel"),	  -1, SHT_REL,	    0 },
  { NULL,		    0,	   0, 0,	    0 }
};

static const struct bfd_elf_special_section special_sections_s[] =
{
  { STRING_COMMA_LEN (".shstrtab"), 0, SHT_STRTAB, 0 },
  { STRING_COMMA_LEN (".strtab"),   0, SHT_STRTAB, 0 },
  { STRING_COMMA_LEN (".symtab"),   0, SHT_SYMTAB, 0 },
  /* See struct bfd_elf_special_section declaration for the semantics of
     this special case where .prefix_length != strlen (.prefix).  */
  { ".stabstr",			5,  3, SHT_STRTAB, 0 },
  { NULL,			0,  0, 0,	   0 }
};

static const struct bfd_elf_special_section special_sections_t[] =
{
  { STRING_COMMA_LEN (".text"),	 -2, SHT_PROGBITS, SHF_ALLOC + SHF_EXECINSTR },
  { STRING_COMMA_LEN (".tbss"),	 -2, SHT_NOBITS,   SHF_ALLOC + SHF_WRITE + SHF_TLS },
  { STRING_COMMA_LEN (".tdata"), -2, SHT_PROGBITS, SHF_ALLOC + SHF_WRITE + SHF_TLS },
  { NULL,		      0,  0, 0,		   0 }
};

static const struct bfd_elf_special_section special_sections_z[] =
{
  { STRING_COMMA_LEN (".zdebug_line"),	  0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".zdebug_info"),	  0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".zdebug_abbrev"),  0, SHT_PROGBITS, 0 },
  { STRING_COMMA_LEN (".zdebug_aranges"), 0, SHT_PROGBITS, 0 },
  { NULL,		      0,  0, 0,		   0 }
};

static const struct bfd_elf_special_section * const special_sections[] = {
  special_sections_b,		/* 'b' */
  special_sections_c,		/* 'c' */
  special_sections_d,		/* 'd' */
  NULL,				/* 'e' */
  special_sections_f,		/* 'f' */
  special_sections_g,		/* 'g' */
  special_sections_h,		/* 'h' */
  special_sections_i,		/* 'i' */
  NULL,				/* 'j' */
  NULL,				/* 'k' */
  special_sections_l,		/* 'l' */
  NULL,				/* 'm' */
  special_sections_n,		/* 'n' */
  NULL,				/* 'o' */
  special_sections_p,		/* 'p' */
  NULL,				/* 'q' */
  special_sections_r,		/* 'r' */
  special_sections_s,		/* 's' */
  special_sections_t,		/* 't' */
  NULL,				/* 'u' */
  NULL,				/* 'v' */
  NULL,				/* 'w' */
  NULL,				/* 'x' */
  NULL,				/* 'y' */
  special_sections_z		/* 'z' */
};
struct fake_section_arg { struct bfd_link_info *link_info; bool failed; };

static bool elf_init_file_header (bfd *abfd,
			   struct bfd_link_info *info ATTRIBUTE_UNUSED);

/* An entry in the strtab hash table.  */
struct elf_strtab_hash_entry {
  struct bfd_hash_entry root;
  /* Length of this entry.  This includes the zero terminator.  */
  int len;
  unsigned int refcount;
  union {
    /* Index within the merged section.  */
    size_t index;
    /* Entry this is a suffix of (if len < 0).  */
    struct elf_strtab_hash_entry *suffix;
  } u;
};

/* The strtab hash table.  */
struct elf_strtab_hash {
  struct bfd_hash_table table;
  /* Next available index.  */
  size_t size;
  /* Number of array entries alloced.  */
  size_t alloced;
  /* Final strtab size.  */
  size_t sec_size;
  /* Array of pointers to strtab entries.  */
  struct elf_strtab_hash_entry **array;
};
static const char *vendor_obj_attr_name(bfd *abfd,int vendor);
static bool is_default_attr(obj_attribute *attr);
static bfd_vma obj_attr_size(unsigned,obj_attribute *);
static int uleb128_size(unsigned);
#undef abort
/* A pointer to this structure is stored in *pinfo.  */
struct stab_find_info {
  /* The .stab section.  */
  asection *stabsec;
  /* The .stabstr section.  */
  asection *strsec;
  /* The contents of the .stab section.  */
  bfd_byte *stabs;
  /* The contents of the .stabstr section.  */
  bfd_byte *strs;

  /* A table that indexes stabs by memory address.  */
  struct indexentry *indextable;
  /* The number of entries in indextable.  */
  int indextablesize;

  /* Saved ptr to malloc'ed filename.  */
  char *filename;
};

static const struct bfd_elf_special_section * get_sec_type_attr (bfd *abfd, asection *sec);
#define DW_EH_PE_omit 0xff
enum dwarf1 {
	DW_LANG_Mips_Assembler = 0x8001, DW_AT_name=0x03, DW_AT_comp_dir=0x1b, DW_AT_external=0x3f,
	DW_AT_stmt_list=0x10, DW_AT_producer=0x25, DW_AT_language=0x13, DW_AT_type=0x49,
	DW_FORM_strp=0x0e, DW_FORM_udata=0x0F, DW_AT_low_pc=0x11, DW_AT_high_pc=0x12,
	DW_AT_ranges=0x55, DW_FORM_addr = 0x01, DW_FORM_flag=0x0c, DW_FORM_flag_present=0x19,
	DW_FORM_line_strp=0x1f, DW_FORM_data2=0x05, DW_FORM_data4=0x06, DW_FORM_data8=0x07,
	DW_FORM_data16=0x1e, DW_FORM_block=0x09, DW_TAG_subprogram=0x2e, DW_TAG_unspecified_type=0x3b,
	DW_TAG_compile_unit=0x11,
};
enum dwarf_call_frame_info { DW_CFA_advance_loc = 0x40 , DW_CFA_offset = 0x80
, DW_CFA_restore = 0xc0 , DW_CFA_nop = 0x00 , DW_CFA_set_loc = 0x01
, DW_CFA_advance_loc1 = 0x02 , DW_CFA_advance_loc2 = 0x03 , DW_CFA_advance_loc4 = 0x04
, DW_CFA_offset_extended = 0x05 , DW_CFA_restore_extended = 0x06 , DW_CFA_undefined = 0x07
, DW_CFA_same_value = 0x08 , DW_CFA_register = 0x09 , DW_CFA_remember_state = 0x0a
, DW_CFA_restore_state = 0x0b , DW_CFA_def_cfa = 0x0c , DW_CFA_def_cfa_register = 0x0d
, DW_CFA_def_cfa_offset = 0x0e , DW_CFA_def_cfa_expression = 0x0f
, DW_CFA_expression = 0x10 , DW_CFA_offset_extended_sf = 0x11 , DW_CFA_def_cfa_sf = 0x12
, DW_CFA_def_cfa_offset_sf = 0x13 , DW_CFA_val_offset = 0x14 , DW_CFA_val_offset_sf = 0x15
, DW_CFA_val_expression = 0x16 , DW_CFA_lo_user = 0x1c , DW_CFA_hi_user = 0x3f
, DW_CFA_MIPS_advance_loc8 = 0x1d , DW_CFA_GNU_window_save = 0x2d
, DW_CFA_AARCH64_negate_ra_state = 0x2d , DW_CFA_GNU_args_size = 0x2e
, DW_CFA_GNU_negative_offset_extended = 0x2f

};
enum dwarf3 {
	DW_LNCT_directory_index=0x02,
	DW_LNCT_timestamp=0x3,
	DW_LNCT_size=0x04,
	DW_LNCT_MD5=0x5,
	DW_RLE_start_length = 0x07,
};
#define DW_EH_PE_absptr		0x00
#define DW_EH_PE_omit		0xff
#define DW_EH_PE_uleb128	0x01
#define DW_EH_PE_udata2		0x02
#define DW_EH_PE_udata4		0x03
#define DW_EH_PE_udata8		0x04
#define DW_EH_PE_sleb128	0x09
#define DW_EH_PE_sdata2		0x0A
#define DW_EH_PE_sdata4		0x0B
#define DW_EH_PE_sdata8		0x0C
#define DW_EH_PE_signed		0x08
#define DW_EH_PE_pcrel		0x10
#define DW_EH_PE_textrel	0x20
#define DW_EH_PE_datarel	0x30
#define DW_EH_PE_funcrel	0x40
#define DW_EH_PE_aligned	0x50
#define DW_EH_PE_indirect	0x80
enum dwarf_line_number_ops { DW_LNS_extended_op = 0, DW_LNS_copy = 1, DW_LNS_advance_pc = 2, DW_LNS_advance_line = 3,
 DW_LNS_set_file = 4, DW_LNS_set_column = 5, DW_LNS_negate_stmt = 6, DW_LNS_set_basic_block = 7,
 DW_LNS_const_add_pc = 8, DW_LNS_fixed_advance_pc = 9, DW_LNS_set_prologue_end = 10,
 DW_LNS_set_epilogue_begin = 11, DW_LNS_set_isa = 12
};
enum dwarf_line_number_x_ops { DW_LNE_end_sequence = 1, DW_LNE_set_address = 2, DW_LNE_define_file = 3,
 DW_LNE_set_discriminator = 4, /* HP extensions. */ DW_LNE_HP_negate_is_UV_update = 0x11,
 DW_LNE_HP_push_context = 0x12, DW_LNE_HP_pop_context = 0x13, DW_LNE_HP_set_file_line_column = 0x14,
 DW_LNE_HP_set_routine_name = 0x15,DW_LNE_HP_set_sequence = 0x16,DW_LNE_HP_negate_post_semantics = 0x17,
 DW_LNE_HP_negate_function_exit = 0x18,DW_LNE_HP_negate_front_end_logical = 0x19,
 DW_LNE_HP_define_proc = 0x20,DW_LNE_HP_source_file_correlation = 0x80,
 DW_LNE_lo_user = 0x80, DW_LNE_hi_user = 0xff
 };

/* Sub-opcodes for DW_LNE_HP_source_file_correlation. */
enum dwarf_line_number_hp_sfc_ops
 {
  DW_LNE_HP_SFC_formfeed = 1, DW_LNE_HP_SFC_set_listing_line = 2, DW_LNE_HP_SFC_associate = 3
 };
enum dwarf_location_atom { DW_OP_addr = 0x03 , DW_OP_GNU_encoded_addr = 0xf1,DW_LNCT_path=0x1,
DW_RLE_end_of_list=0,DW_FORM_sec_offset=0x17,DW_FORM_ref_udata=0x15,DW_UT_compile=1};
#define DW_CHILDREN_no   0
#define	DW_CHILDREN_yes  1
#endif /* GAS */

