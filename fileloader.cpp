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

BigFileLoader::~BigFileLoader(){
    free();
}

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
    m_fd = open(m_file_path.c_str(), O_RDONLY);
    if (-1 == m_fd)
        handle_error("open");

    posix_fadvise(m_fd, 0, 0, 1);  // FDADVICE_SEQUENTIAL

    // obtain file size
    struct stat sb;
    if (-1 == fstat(m_fd, &sb))
        handle_error("fstat");

    m_length = sb.st_size;

    // const char* addr = static_cast<const char*>(mmap(NULL, m_length, PROT_READ, MAP_PRIVATE, m_fd, 0u));
    m_file_ptr = static_cast<char*>(mmap(NULL, m_length, PROT_READ, MAP_PRIVATE, m_fd, 0u));
    const char* addr = m_file_ptr;
    if (addr == MAP_FAILED)
        handle_error("mmap");
    
    // TODO close fd at some point in time, call munmap(...)
    // close(m_fd);
    // munmap(m_file_ptr, m_length);

    return addr;
}

uintmax_t BigFileLoader::line_num(){
    return m_line_num;
}

std::size_t BigFileLoader::size(){
    return m_length;
}

std::string BigFileLoader::get_line(uintmax_t line_num){
    if(line_num >= m_line_num) return "";
    std::string str(m_lines[line_num].first, m_lines[line_num].second);
    return str;
}

void BigFileLoader::free(){
    m_lines.clear();
    if(m_file_ptr!=NULL){
        if( -1 == munmap( m_file_ptr, m_length ) ){
            handle_error("munmap");
        }
    }
    if(m_fd>0) close(m_fd);
    m_file_ptr = NULL;
    m_length = 0;
    m_line_num = 0;
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

//     loader.free();    
// }