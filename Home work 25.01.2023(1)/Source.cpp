#include <iostream>
#include <vector>
#include <windows.h>

class A {
public:
	virtual void foo(std::vector<int>& vec) = 0;
	virtual void print_vec(std::vector<int>& vec) = 0;
	virtual ~A(){}//�������� ����������
};
class B : public A {
public:
	B(std::vector<int>& vec): _vec(vec){}//�������� �����������
	void foo(std::vector<int>& vec) override {
		std::cout << "foo function" << std::endl;
//for (auto it = vec.begin(); it != vec.end(); it++)//����� �������� ���� � ����������, �������� �������� ����� ������� ��� �������� �������
		//vec.erase(vec.begin()); ����� �������� ������� � �������� 0, ������ ��� �� ��� �� ������ vec.erase(vec.begin()+ 0)
		vec.erase(vec.begin()+ 1);//�� � �������� +1 � ������ �������� ������� � �������� 1
	}
	void print_vec(std::vector<int>& vec)override {//�������� ������� �����, ���� ��������� ��������� � ������� ��������
		std::cout << "������\n" << std::endl;
		for (int i = 0; i < vec.size(); i++) {
			std::cout << "{ " << vec[i] << " }" << std::endl;
		}
			
	}
private:
	std::vector<int>& _vec;//�������� ����������� ������ � �������� ���� ������ ��� ����
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<int> v = { 1,2,3 };
	A* b = new B(v);//�������� � ������() ������	
	b->print_vec(v);
	b->foo(v);
	b->print_vec(v);


	delete b;//�������� �������� �������
}