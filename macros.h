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

//mathematics
#define PI        3.14159265358979323846264338327950288

#define __NSX_PASTE__(A,B) A##B
#define __NSMIN_IMPL__(A,B,L) ({ __typeof__(A) __NSX_PASTE__(__a,L) = (A); \
                                    __typeof__(B) __NSX_PASTE__(__b,L) = (B); \
                                        (__NSX_PASTE__(__a,L) < __NSX_PASTE__(__b,L)) ? __NSX_PASTE__(__a,L) : __NSX_PASTE__(__b,L); \
                                })
#define MIN(A,B) __NSMIN_IMPL__(A,B,__COUNTER__)

//private func for class definition
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    void operator=(const TypeName&)


//assertion
#define ASSERT_FAIL(msg) do { \
  std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") " \
            << msg << std::endl; ::exit(10); } while(0)

#define ASSERT(expr) \
  do { if (!(expr)) MY_ASSERT_FAIL("Assertion failed: " << #expr); } while(0)


//string
#define STR(x) #x    //convert symbol x to a string x

//date & time
#define DATE_STR 

//log
// put the following line in your code, if you wanna log sth.
// #define NEED_LOG

#ifdef NEED_LOG
#define LOG(format, ...) do {                                                        \
            fprintf(stderr, "[%s %s][%s:%d %s]" format,                             \
            __TIME__,__DATE__,                                                       \
            __FILE__,__LINE__,__func__,                                              \
            __VA_ARGS__);                                                            \
            fprintf(stderr,"\n");                                                    \
        } while (0)

#else
    #define LOG(format, ...) do{ } while(0)
#endif

//put the following lines in your code if you wanna use these log func
// #define LOG_LEVEL_DEBUG
// #define LOG_LEVEL_TRACE
// #define LOG_LEVEL_ERROR

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


#endif

