/*************************************************************************
    > File Name: macros.h
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Tue 06 Dec 2016 10:57:46 AM
 ************************************************************************/
#ifndef MACROS_H
#define MACROS_H 1

#include <iostream>
#include <cstdlib>

/*------------------memory--------------------*/
//get the byte at address x
#define   MEM_B( x )   ( *( (byte *) (x) ) ) 
//get the word at address x
#define   MEM_W( x )   ( *( (word *) (x) ) ) 
//get the address of a variable (byte width)
#define   B_PTR( var )   ( (byte *) (void *) &(var) ) 
//get the address of a variable (word width)
#define   W_PTR( var )   ( (word *) (void *) &(var) ) 
//get the high and low positions of a word
#define   WORD_LO(xxx)   ((byte) ((word)(xxx) & 255)) 
#define   WORD_HI(xxx)   ((byte) ((word)(xxx) >> 8))

/*------------------data structure--------------------*/
//get the size of an array
#define   ARR_SIZE( a )   ( sizeof( (a) ) / sizeof( (a[0]) ) )

/*------------------mathematics--------------------*/
#define PI        3.14159265358979323846264338327950288
#define CIRCLE_AREA(R) (PI*R*R)

#define MAX(x, y) y&((x-y)>>31)|x&~((x-y)>>31)

#define AVG(x, y) (x & y) + ((x ^ y) >> 1)

#define ABS(x) (x + x >> 31)^(x >> 31)

#define __NSX_PASTE__(A,B) A##B
#define __NSMIN_IMPL__(A,B,L) ({ __typeof__(A) __NSX_PASTE__(__a,L) = (A); \
                                    __typeof__(B) __NSX_PASTE__(__b,L) = (B); \
                                        (__NSX_PASTE__(__a,L) < __NSX_PASTE__(__b,L)) ? __NSX_PASTE__(__a,L) : __NSX_PASTE__(__b,L); \
                                })
#define MIN(A,B) __NSMIN_IMPL__(A,B,__COUNTER__)


/*------------------class--------------------*/
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    void operator=(const TypeName&)


/*------------------assertion--------------------*/
#define ASSERT_FAIL(msg) do { \
  std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") " \
            << msg << std::endl; ::exit(10); } while(0)

#define ASSERT(expr) \
  do { if (!(expr)) MY_ASSERT_FAIL("Assertion failed: " << #expr); } while(0)


/*------------------string--------------------*/
#define VAR_NAME_STR(x) #x    //convert symbol x to a string x
// #define VAR_VALUE_STR(x)
//concatenate two variables
#define GLUE(x,y)  x##y 
//date & time
#define DATE_STR __DATE__
#define TIME_STR __TIME__
//convert a letter to upper case
#define   UPCASE( c ) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) ) 

/*------------------log--------------------*/
#define LOG_ON

#ifdef LOG_ON
#define LOG(format, ...) do {\
            fprintf(stderr, "[%s %s][%s:%d %s]" format,\
            __TIME__,__DATE__,\
            __FILE__,__LINE__,__func__,\
            __VA_ARGS__);\
            fprintf(stderr,"\n");\
        } while (0)

#else
    #define LOG(format, ...) do{ } while(0)
#endif

#define LOG_LEVEL_DEBUG
#define LOG_LEVEL_TRACE
#define LOG_LEVEL_ERROR

#ifdef LOG_LEVEL_DEBUG
    #define DBG_LOG(format, ...) LOG("<DEBUG>:" format, __VA_ARGS__)
#else
    #define DBG_LOG(format, ...) do{ } while(0)
#endif

#ifdef LOG_LEVEL_TRACE
    #define TRACE_LOG(format, ...) LOG("<TRACE>:" format, __VA_ARGS__)
#else
    #define TRACE_LOG(format, ...) do{ } while(0)
#endif

#ifdef LOG_LEVEL_ERROR
    #define ERR_LOG(format, ...) LOG("<ERROR>:" format, __VA_ARGS__)
#else
    #define ERR_LOG(format, ...) do{ } while(0)
#endif



/*------------------type definition--------------------*/
//redefine some types, in case of the differences of bytes 
//that the type takes on different platforms or compilers
typedef   unsigned char       boolean;      /* Boolean value type. */ 
typedef   unsigned long long  uint64;       /* Unsigned 64 bit value */ 
typedef   unsigned long int   uint32;       /* Unsigned 32 bit value */ 
typedef   unsigned short      uint16;       /* Unsigned 16 bit value */ 
typedef   unsigned char       uint8;        /* Unsigned 8   bit value */
typedef   signed long long    int64         /* Signed 64 bit value */ 
typedef   signed long int     int32;        /* Signed 32 bit value */ 
typedef   signed short        int16;        /* Signed 16 bit value */ 
typedef   signed char         int8;         /* Signed 8   bit value */ 
#endif

