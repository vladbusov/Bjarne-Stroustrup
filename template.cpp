#include <cstddef>
#include <iostream>



template <typename T>
class Array
{
	T* data_;
	size_t size_;
public:
	// Ñïèñîê îïåðàöèé:
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
	//   êîíñòðóêòîð êëàññà, êîòîðûé ñîçäàåò
	//   Array ðàçìåðà size, çàïîëíåííûé çíà÷åíèÿìè
	//   value òèïà T. Ñ÷èòàéòå ÷òî ó òèïà T åñòü
	//   êîíñòðóêòîð, êîòîðûé ìîæíî âûçâàòü áåç
	//   áåç ïàðàìåòðîâ, ëèáî îí åìó íå íóæåí.
	//
	Array(){
		data_ = NULL;
		size_ = 0;
	}
	//   êîíñòðóêòîð êëàññà, êîòîðûé ìîæíî âûçâàòü
	//   áåç ïàðàìåòðîâ. Äîëæåí ñîçäàâàòü ïóñòîé
	//   Array.
	//
	Array(const Array &a){
		size_ = a.size();
		char *p = new char[size_ * sizeof(T)];
		for (int i = (size_ - 1); i > -1; i--){
			data_ = new (p + (i*(sizeof(T))))  T(a[0]);
		}
	}
	//   êîíñòðóêòîð êîïèðîâàíèÿ, êîòîðûé ñîçäàåò
	//   êîïèþ ïàðàìåòðà. Äëÿ òèïà T îïåðàòîð
	//   ïðèñâàèâàíèÿ íå îïðåäåëåí.
	//
	~Array(){
		for (int i = (size_ - 1); i > -1; i--){
			T * p = data_ + i*(sizeof(T));
			std::cout << p[0] << std::endl;
			p->~T();
			
		}
		delete[](char *) data_;
		
	}
	//   äåñòðóêòîð, åñëè îí âàì íåîáõîäèì.
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
	//   îïåðàòîð ïðèñâàèâàíèÿ.
	//
	size_t size() const{
		return size_;
	}
	//   âîçâðàùàåò ðàçìåð ìàññèâà (êîëè÷åñòâî 
	//                              ýëåìåíòîâ).
	//
	T& operator[](size_t k){
		return data_[k];
	}
	const T& operator[](size_t k) const{
		return data_[k];
	}
	//   äâå âåðñèè îïåðàòîðà äîñòóïà ïî èíäåêñó.
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
