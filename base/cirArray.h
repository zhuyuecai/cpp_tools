#ifndef BASE_CIRARRAY_H
#define BASE_CIRARRAY_H

template<typename T>
class cirArray
{
public:
	//default constructor

	cirArray();
	//full constructor;

	cirArray(const int l, const char r, T* val);


	//destructor
	~cirArray(){
		delete[] carrier;
	};

	//TODO throw error
	
	int capasity(){ return lenght; }
	T* valueAt(const int i);
	void assign(int i, T val);
	int grow();
	


protected:
	
private:
	int lconst;
	int lenght;
	T* carrier;
	char expand_rule;
	
};


#endif