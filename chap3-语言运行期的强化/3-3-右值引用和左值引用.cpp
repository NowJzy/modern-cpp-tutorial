#include<iostream>
#include<string>

void reference(std::string& str){
    std::cout << " ��ֵ" << std::endl;
}

void reference(std::string&& str){
    std::cout << " ��ֵ" << std::endl;
}

int main(){
    std::string lv1 = "string,";  //lv1��һ����ֵ
    // std::string&& r1 = lv1;  //�Ƿ�����ֵ���ò���������ֵ
    std::string&& rv1 = std::move(lv1);  //�Ϸ���std::move���Խ���ֵת��Ϊ��ֵ
    std::cout << rv1 << std::endl;  //string,

    const std::string& lv2 = lv1 + lv1;  //�Ϸ���������ֵ�����ܹ��ӳ���ʱ��������������
    // lv2 += "Test";  //�Ƿ������������޷����޸�
    std::cout << lv2 << std::endl;  //string,string,

    std::string&& rv2 = lv1 + lv2;  //�Ϸ�����ֵ�����ӳ���ʱ������������
    rv2 += "Test";  //�Ϸ����ǳ��������ܹ��޸���ʱ����
    std::cout << rv2 << std::endl;

    reference(rv2);  //rv2��Ȼ������һ����ֵ������������һ�����ã�����rv2��Ȼ��һ����ֵ

    return 0;
}