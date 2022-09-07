#include<memory>
#include<iostream>

void foo(std::shared_ptr<int> i){
    (*i)++;
}

int main(){
    // auto pointer = new int(10);
    auto pointer = std::make_shared<int>(10);
    foo(pointer);

    std::cout << *pointer << std::endl;  // 11

    return 0;
}