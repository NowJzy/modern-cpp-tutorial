#include<iostream>

class A{
public:
    int *pointer;
    A():pointer(new int(1)){
        std::cout << " ����" << pointer << std::endl;
    }

    A(A& a):pointer(new int(*a.pointer)){
        std::cout << " ����" << pointer << std::endl;
    }   //������Ķ��󿽱�
    
    A(A&& a):pointer(a.pointer){
        a.pointer = nullptr;
        std::cout << " �ƶ�" << pointer << std::endl;
    }

    ~A(){
        std::cout << " ����" << pointer << std::endl;
        delete pointer;
    }
};

//��ֹ�������Ż�
A return_rvalue(bool test){
    A a, b;
    if(test)
        return a;  //�ȼ���static_cast<A&&>(a)
    else
        return b;  //�ȼ���static_cast<A&&>(b)
}

int main(){
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;

    return 0;
}