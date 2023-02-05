#include <iostream>
#include <vector>
#include <windows.h>

class A {
public:
	virtual void foo(std::vector<int>& vec) = 0;
	virtual void print_vec(std::vector<int>& vec) = 0;
	virtual ~A(){}//добавила деструктор
};
class B : public A {
public:
	B(std::vector<int>& vec): _vec(vec){}//добавила конструктор
	void foo(std::vector<int>& vec) override {
		std::cout << "foo function" << std::endl;
//for (auto it = vec.begin(); it != vec.end(); it++)//можно добавить цикл с итератором, согласно которого будут удалены все элементы вектора
		//vec.erase(vec.begin()); здесь удалитс€ элемент с индексом 0, потому что мы как бы делаем vec.erase(vec.begin()+ 0)
		vec.erase(vec.begin()+ 1);//но € добавила +1 и теперь удалитс€ элемент с индексом 1
	}
	void print_vec(std::vector<int>& vec)override {//добавила функцию принт, чтоб отследить изменени€ в векторе нагл€дно
		std::cout << "ћассив\n" << std::endl;
		for (int i = 0; i < vec.size(); i++) {
			std::cout << "{ " << vec[i] << " }" << std::endl;
		}
			
	}
private:
	std::vector<int>& _vec;//добавила модификатор приват и добавила туда вектор как поле
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<int> v = { 1,2,3 };
	A* b = new B(v);//добавила в скобки() вектор	
	b->print_vec(v);
	b->foo(v);
	b->print_vec(v);


	delete b;//добавила удаление объекта
}