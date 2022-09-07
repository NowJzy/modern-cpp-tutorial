#include<initializer_list>
#include<vector>
#include<iostream>

class MagicFoo{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list){
        for(std::initializer_list<int>::iterator iter = list.begin();
            iter != list.end(); ++iter)
            vec.push_back(*iter);
    }
};

int main(){
    MagicFoo magicfoo = {1,2,3,4,5};

    std::cout << "magicfoo: " << std::endl;
    for(std::vector<int>::iterator it = magicfoo.vec.begin();
        it != magicfoo.vec.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}