#include<iostream>

using foo = void(int);  //定义函数类型

void functional(foo f){  //定义在参数列表中的函数类型foo被视为退化后的函数指针类型foo*
    f(1);  //通过函数指针调用函数
}

int main(){
    auto f = [](int value){
        std::cout << value << std::endl;
    };
    functional(f);  //传递闭包对象，隐式转换为foo*类型的函数指针值
    f(1);  //lambda表达式调用

    return 0;
}