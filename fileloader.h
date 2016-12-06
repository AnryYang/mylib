/*************************************************************************
    > File Name: fileloader.h
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Tue 06 Dec 2016 05:13:05 PM
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>

// for mmap:
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define Line std::pair<const char*, int>

class BigFileLoader{
public:
    BigFileLoader(std::string file_path);
    ~BigFileLoader();
    uintmax_t line_num();
    std::size_t size();
    std::string get_line(uintmax_t line_num);

protected:
    void load();
    const char* map_file();

private:
    std::string m_file_path;
    std::size_t m_length;
    uintmax_t m_line_num;
    std::vector<Line> m_lines;
};

// #undef Line