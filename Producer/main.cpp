#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

int item_buffer[20];
int pos=0;
void product_item() {
    // P(S)
    mtx.lock();

    // 执行生产操作
    std::cout << "producing" << std::endl;
    item_buffer[pos] = 666;
    pos++;
    // V(mutes)
    mtx.unlock();
}

void consume_item() {
    // P(S)
    mtx.lock();

    // 执行生产操作
    std::cout << "consuming" << std::endl;
    for(int i = 0; i <20; i++){//轮询数组，看可消费产物
        if(item_buffer[i]!=0){
            std::cout<<i<<std::endl;
        }else{
            continue;
        }
    }
    // V(mutes)
    mtx.unlock();
}

void Producer_thread(int i) {
    // producing
    while(i--){
        product_item();
    }
}

void Consumer_thread(int j) {
    // ..
    while(j--){
        consume_item();
    }
}

int main() {
    int product,consume;//cin
    std::cin>>product>>consume;
    std::thread thread1(Producer_thread, product);
    std::thread thread2(Consumer_thread, consume);
    thread1.join();
    thread2.join();
    return 0;
}
