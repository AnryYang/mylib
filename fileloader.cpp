/*************************************************************************
    > File Name: fileloader.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Tue 06 Dec 2016 05:13:05 PM
 ************************************************************************/

#include "fileloader.h"
// #include "timer.h"

void handle_error(const char* msg) {
    perror(msg); 
    exit(255);
}

BigFileLoader::BigFileLoader(std::string file_path):
    m_file_path(file_path){
    load();
}

BigFileLoader::~BigFileLoader(){}

void BigFileLoader::load(){
    auto f = map_file();
    auto l = f + m_length;

    m_line_num = 0;
    while (f && f!=l){
        auto e = f;
        if ((f = static_cast<const char*>(memchr(f, '\n', l-f)))){
            Line line = std::make_pair(e, f-e);
            m_lines.push_back(line);
            m_line_num++;
            f++;
        }
    }
 }

const char* BigFileLoader::map_file(){
    int fd = open(m_file_path.c_str(), O_RDONLY);
    if (fd == -1)
        handle_error("open");

    posix_fadvise(fd, 0, 0, 1);  // FDADVICE_SEQUENTIAL

    // obtain file size
    struct stat sb;
    if (fstat(fd, &sb) == -1)
        handle_error("fstat");

    m_length = sb.st_size;

    const char* addr = static_cast<const char*>(mmap(NULL, m_length, PROT_READ, MAP_PRIVATE, fd, 0u));
    if (addr == MAP_FAILED)
        handle_error("mmap");

    // TODO close fd at some point in time, call munmap(...)
    return addr;
}

uintmax_t BigFileLoader::line_num(){
    return m_line_num;
}

std::size_t BigFileLoader::size(){
    return m_length;
}

std::string BigFileLoader::get_line(uintmax_t line_num){
    std::string str(m_lines[line_num].first, m_lines[line_num].second);
    return str;
}

// int main(){
//     Timer timer;
//     timer.start();
//     BigFileLoader loader("graph.txt");
//     timer.stop();
//     std::cout << " line number:" << loader.line_num()
//               << " file size:" << loader.size()
//               << " time:" << timer.elapsed()
//               << std::endl;
//     for(int i=0;i<10;i++){
//         std::cout << "line" << i << " :" << loader.get_line(i) << std::endl;
//     }
// }