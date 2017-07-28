#include <cstddef>
#include <iostream>



template <typename T>
class Array
{
	T* data_;
	size_t size_;
public:
	// ������ ��������:
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
	//   ����������� ������, ������� �������
	//   Array ������� size, ����������� ����������
	//   value ���� T. �������� ��� � ���� T ����
	//   �����������, ������� ����� ������� ���
	//   ��� ����������, ���� �� ��� �� �����.
	//
	Array(){
		data_ = NULL;
		size_ = 0;
	}
	//   ����������� ������, ������� ����� �������
	//   ��� ����������. ������ ��������� ������
	//   Array.
	//
	Array(const Array &a){
		size_ = a.size();
		char *p = new char[size_ * sizeof(T)];
		for (int i = (size_ - 1); i > -1; i--){
			data_ = new (p + (i*(sizeof(T))))  T(a[0]);
		}
	}
	//   ����������� �����������, ������� �������
	//   ����� ���������. ��� ���� T ��������
	//   ������������ �� ���������.
	//
	~Array(){
		for (int i = (size_ - 1); i > -1; i--){
			T * p = data_ + i*(sizeof(T));
			std::cout << p[0] << std::endl;
			p->~T();
			
		}
		delete[](char *) data_;
		
	}
	//   ����������, ���� �� ��� ���������.
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
	//   �������� ������������.
	//
	size_t size() const{
		return size_;
	}
	//   ���������� ������ ������� (���������� 
	//                              ���������).
	//
	T& operator[](size_t k){
		return data_[k];
	}
	const T& operator[](size_t k) const{
		return data_[k];
	}
	//   ��� ������ ��������� ������� �� �������.
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