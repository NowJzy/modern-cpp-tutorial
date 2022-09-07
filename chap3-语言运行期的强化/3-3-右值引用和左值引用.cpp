#include<iostream>
#include<string>

void reference(std::string& str){
    std::cout << " 左值" << std::endl;
}

void reference(std::string&& str){
    std::cout << " 右值" << std::endl;
}

int main(){
    std::string lv1 = "string,";  //lv1是一个左值
    // std::string&& r1 = lv1;  //非法，右值引用不能引用左值
    std::string&& rv1 = std::move(lv1);  //合法，std::move可以将左值转移为右值
    std::cout << rv1 << std::endl;  //string,

    const std::string& lv2 = lv1 + lv1;  //合法，常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test";  //非法，常量引用无法被修改
    std::cout << lv2 << std::endl;  //string,string,

    std::string&& rv2 = lv1 + lv2;  //合法，右值引用延长临时变量生命周期
    rv2 += "Test";  //合法，非常量引用能够修改临时变量
    std::cout << rv2 << std::endl;

    reference(rv2);  //rv2虽然引用了一个右值，但由于它是一个引用，所以rv2依然是一个左值

    return 0;
}