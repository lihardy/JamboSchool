//
// Created by HardyLi2007 on 3/22/2024.
//
#include <iostream>
#include <thread>
#include <mutex>

std::mutex rw;
std::mutex mtx;
std::mutex w;
int item_buffer[20];
int cnt = 0;
int pos=0;
int Input;
int Output;
void Read(){
    while(1){
        w.lock();
        mtx.lock();
        if(cnt==0){
            rw.lock();
        }cnt++;
        mtx.unlock();
        w.unlock();
        for(int i = 0;i<20;i++){
            std::cout<<item_buffer[i]<<" ";
        }
        mtx.lock();
        cnt--;
        if(cnt==0){
            rw.unlock();
        }
        mtx.unlock();
    }
}

void Write(){
    while(1){
        w.lock();
        rw.lock();
        std::cin>>Input;
        item_buffer[pos] = Input;
        pos++;
        rw.unlock();
        w.unlock();
    }
}

void Reader_thread(int i) {
    // producing
    while(i--){
        Read();
    }
}

void Writer_thread(int j) {
    // ..
    while(j--){
        Write();
    }
}

int main(){
    int read,write;//cin
    std::cin>>write>>read;
    std::thread thread1(Writer_thread, write);
    std::thread thread2(Reader_thread, read);
    thread1.join();
    thread2.join();
    return 0;
}