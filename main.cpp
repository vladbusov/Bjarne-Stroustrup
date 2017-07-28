#include <cstddef>
#include <iostream>



template <typename T>
class Array
{
	T* data_;
	size_t size_;
public:
	// Список операций:
	//
	void prnt()
	{
		for (size_t i = 0; i < size_; ++i)
			cout << *(data_ + i);
		cout << endl;
	}

	Array(size_t size, const T& value = T()) :size_(size)
	{
		char *p = new char[size_ * sizeof(T)];
		for (int i = size_; i > 0; i--){
			data_ = new (p + (i*(sizeof(T))))  T(value);
		}
	}
	//   конструктор класса, который создает
	//   Array размера size, заполненный значениями
	//   value типа T. Считайте что у типа T есть
	//   конструктор, который можно вызвать без
	//   без параметров, либо он ему не нужен.
	//
	Array(){
		data_ = NULL;
		size_ = 0;
	}
	//   конструктор класса, который можно вызвать
	//   без параметров. Должен создавать пустой
	//   Array.
	//
	Array(const Array &a){
		size_ = a.size();
		char *p = new char[size_ * sizeof(T)];
		for (int i = (size_ - 1); i > -1; i--){
			data_ = new (p + (i*(sizeof(T))))  T(a[0]);
		}
	}
	//   конструктор копирования, который создает
	//   копию параметра. Для типа T оператор
	//   присваивания не определен.
	//
	~Array(){
		for (int i = (size_ - 1); i > -1; i--){
			T * p = data_ + i*(sizeof(T));
			std::cout << p[0] << std::endl;
			p->~T();
			
		}
		delete[](char *) data_;
		
	}
	//   деструктор, если он вам необходим.
	//
	Array& operator=(const Array &a){
		this->~Array();
		size_ = a.size();
		char *p = new char[size_ * sizeof(T)];
		for (int i = (size_ - 1); i > -1; i--){
			data_ = new (p + (i*(sizeof(T))))  T(a[0]);
		}
		return *this;
	}
	//   оператор присваивания.
	//
	size_t size() const{
		return size_;
	}
	//   возвращает размер массива (количество 
	//                              элементов).
	//
	T& operator[](size_t k){
		return data_[k];
	}
	const T& operator[](size_t k) const{
		return data_[k];
	}
	//   две версии оператора доступа по индексу.
};

void func(Array<char>  k){
	std::cout << k[0] << k[1] << std::endl;
}

int main(){
	Array<char> f(4,'l');
	std::cout << f[0] << f[1] << std::endl;
	Array<char> t(6, 'k');
	//func(t);
	f = t;
	
	std::cout << f.size() << std::endl;
	f.~Array();

	std::cout << t.size() << std::endl;
	t.~Array();
	

	std::cout << "Free memory"<< std::endl;

	std::cout <<f.size() << f[0] << f[1] << std::endl;
	std::cout << t.size() << t[0] << t[1] << std::endl;

	system("PAUSE");
	return 0;
}