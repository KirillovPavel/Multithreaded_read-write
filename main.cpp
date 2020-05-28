#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <shared_mutex>

template<typename T>
struct Page{
    std::vector<T> data;
    std::string name;
    mutable std::shared_mutex mtx;

    Page(const std::string& name):
    name(name)
    {}
};

template<typename T>
void read(const Page<T>& page){
    std::shared_lock lck(page.mtx);

    std::cout << "Page name: " << page.name << std::endl;
    std::cout << "Reader id: " << std::this_thread::get_id() << std::endl;
    std::cout << "Writers id: " << std::endl;
    for(auto val : page.data){
        std::cout << val;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void write(Page<T>& page){
    std::unique_lock lck(page.mtx);
    
    page.data.push_back(std::this_thread::get_id());
    //you can write here whatever you want
}


int main(){
    using T = std::thread::id;
    Page<T> page("Page1");
    // Tests
    // std::thread write1(write<T>, std::ref(page));
    // std::thread read1 (read<T> , std::ref(page));
    // std::thread read2 (read<T> , std::ref(page));
    // std::thread write2(write<T>, std::ref(page));
    // std::thread read3 (read<T> , std::ref(page));

    // write1.join();
    // read1.join();
    // read2.join();
    // write2.join();
    // read3.join();
    // return 0;
}
