/*************************************************************************
    > File Name: test.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Tue 06 Dec 2016 11:57:52 AM
 ************************************************************************/

#include<iostream>
#include "macros.h"
using namespace std;

// #define LOG(format, ...) do {                                                                          \
//                              fprintf(stderr, "[%s %s][%s:%d %s]" format,                             \
//                              __TIME__,__DATE__,                                                        \
//                              __FILE__,__LINE__,__func__,                                               \
//                              __VA_ARGS__);                                                             \
//                              fprintf(stderr,"\n");                                                     \
//                            } while (0)

// #define LOG_LEVEL_DEBUG
// #define LOG_LEVEL_TRACE
// #define LOG_LEVEL_ERROR

// #ifdef LOG_LEVEL_DEBUG
//     #define DBG_LOG(format, ...) LOG("<DEBUG>:" format, __VA_ARGS__)
// #else
//     #define DBG_LOG(format, ...) do{ } while(0)
// #endif

// #ifdef LOG_LEVEL_TRACE
//     #define TRACE_LOG(format, ...) LOG("<TRACE>:" format, __VA_ARGS__)
// #else
//     #define TRACE_LOG(format, ...) do{ } while(0)
// #endif

// #ifdef LOG_LEVEL_ERROR
//     #define ERR_LOG(format, ...) LOG("<ERROR>:" format, __VA_ARGS__)
// #else
//     #define ERR_LOG(format, ...) do{ } while(0)
// #endif

int main(){
    DBG_LOG("%s", "1234567");
    TRACE_LOG("%s", "1234567");
    ERR_LOG("%s", "1234567");
    return 0;
}
