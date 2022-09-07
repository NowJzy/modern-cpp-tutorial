#include<iostream>


//值捕获
void lambda_value_capture(){
    int value = 1;
    auto copy_value = [value]{  //创建时拷贝，而非调用时拷贝，所以value=1
        return value;
    };

    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
}


//引用捕获
void lambda_reference_capture(){
    int value = 1;
    auto copy_value = [&value]{
        return value;
    };

    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
}


int main(){
    lambda_value_capture();
    lambda_reference_capture();
    return 0;
}

/*捕获提供了lambda表达式对外部值进行使用的功能，捕获列表最常用的四种形式可以是：
- [] 空捕获列表
- [name1, name2, ...] 捕获一系列变量
- [&] 引用捕获，让编译器自行推导引用列表
- [=] 值捕获，让编译器自行推导值捕获列表
*/