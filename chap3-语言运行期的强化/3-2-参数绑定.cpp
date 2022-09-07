#include<iostream>
#include<functional>

int foo(int a, int b, int c){
    return a + b + c;
}

int main(){
    //将参数1，2绑定到函数foo上，但是使用std::placeholders::_1来对第一个参数进行占位
    auto bindFoo = std::bind(foo, std::placeholders::_1, 1, 2);
    //这时调用bindFoo时，只需要提供第一个参数即可
    std::cout << bindFoo(1);

    return 0;
}