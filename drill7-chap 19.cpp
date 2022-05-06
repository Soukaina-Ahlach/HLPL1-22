#include "std_lib_facilities.h"
// part 1
template <typename T>
struct S
{
private:
	T val;
public :
	//part 2
	S()
	{
		val = 0;
	}
	S(T val2)
	{
		val=val2;
	}
	
	T get();
	/*
	* // part 5
	{
	return val;
	}
	*/ 
	const T get() const;
	void operator=(const T&);
	/*
	 // part 9
	void set(T val3)
	{
		val = val3;
	}
	*/

};
// part 6
template<typename T>
 T S<T>::get()
	{
		return val;
	}
 //part 11
 template<typename T>
 const T S<T>::get() const
 {
	 return val;
 }
 // part 10
template <typename T>
void S<T>:: operator=(const T& val3)
{
	val = val3;
}
// part 12
 template<typename T>
 void read_val(T& v)
 {
	 cin >> v;
}
int main()
{
	// part 3 initializing
	 S<int> intS(1);
	 S<char> charS('A');
	 S<double> doubS(1.1);
	 S<string> strS("String A");
	 S<vector<int>> vecS ({ 1, 2, 3 });
	 /*
	 // printing old method {part 4 }
	  cout << intS.val<<endl;
	 cout << charS.val << endl;
	 cout << doubS.val << endl;
	 cout << strS.val << endl;
	 for(int i : vecS.val)
	 cout << i <<" ";
	 */ 
	 // printing part 8
	 cout << intS.get()<<endl;
	 cout << charS.get() << endl;
	 cout << doubS.get() << endl;
	 cout << strS.get() << endl;
	 for(int i : vecS.get())
	 cout << i <<" ";
	 cout << endl;
	 //part 13
	 int i1; read_val(i1); S<int> i1S(i1);

	double d1; read_val(d1); S<double> d1S(d1);

	 char c1; read_val(c1); S<char> c1S(c1);
	 cout << i1S.get() << endl;
	 cout << d1S.get() << endl;
	 cout << c1S.get() << endl;
	 
	return 0;
}
