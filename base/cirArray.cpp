/*
TODO comments

*/



#include "cirArray.h"

//default constructor takes only one stored value as argument
template<typename T>
cirArray<T>::cirArray(){
	lenght = 20;
	lconst = 20;
	expand_rule = 'd';
	carrier = new T[lenght];
}

//full constructor takes 3 argument, and will store the input value in the first place
template<typename T>
cirArray<T>::cirArray(const int l, const char r, T* val){
	this->lenght = l;
	lconst = l;
	if (r == 'd' | r == 'c'){ this->expand_rule = r; }
	else{ }
	this->carrier =new T[lenght];
	carrier[0] = val;
}
template<typename T>
 int cirArray<T>::grow(){
	 
	int oldL = lenght;
	if (expand_rule == 'd'){

		lenght= lenght* 2;
	}
	else{
		lenght = lconst + lenght;
	}

	T* otherc = new T[lenght];
	T* de = carrier;

	for (int i = 0; i < oldL; ++i){
		otherc[i] = de[i];
	}
	carrier = otherc;
	//otherc = nullptr;
	return lenght;
}
 template<typename T>
T* cirArray<T>::valueAt(const int i){
	 if (i < lenght-1){
		 return &carrier[i];
	 }
	 else{
		 while (i >= lenght-1){
			 this->grow();
		 }
		 return &carrier[i];
	 }
 }

template<typename T>
void cirArray<T>::assign(int i, T val){
		while (i >= lenght - 1){
			this->grow();
		}
		this->carrier[i] = val;
	
}

//template<typename T>
//void cirArray<T>::assign(int i, T val){
//	this->carrier[i] = val;
//}