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
    DBG_LOG(LOG_LEVEL_TRACE, "%s", "1");
    DBG_LOG(LOG_LEVEL_DEBUG, "%s", "2");
    DBG_LOG(LOG_LEVEL_ERROR, "%s", "3");

    TRACE_LOG(LOG_LEVEL_TRACE, "%s", "1");
    TRACE_LOG(LOG_LEVEL_DEBUG, "%s", "2");
    TRACE_LOG(LOG_LEVEL_ERROR, "%s", "3");

    ERR_LOG(LOG_LEVEL_TRACE, "%s", "1");
    ERR_LOG(LOG_LEVEL_DEBUG, "%s", "2");
    ERR_LOG(LOG_LEVEL_ERROR, "%s", "3");



    int x = 100;
    cout<<VAR_NAME_STR(x)<<endl;

    cout<<DATE_STR<<endl;
    cout<<TIME_STR<<endl;
    return 0;
}
