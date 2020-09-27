#include <iostream>
using std::cout;
using std::endl;

class A{
	public: 
	A(int a){
		_a = a;
	}
	
	int _a;
	void print(){
		cout<<"a:"<<_a<<endl;
		
		}
	
	
	};

class B: A{
	public: 
	B(int b=0,int a=0): 
		A{a}{
		_b = b;

	}
	
	int _b;
	void print(){
		cout<<"a:"<<_a<<endl;
		cout<<"b:"<<_b<<endl;
		
		}
	
	
	};

int main(){
	
	//~ A a_obj(5);
	//~ a_obj.print();
	
	B b_obj(10,15);
	b_obj.print();


	cout<< "Hello World Test"<<endl;


}
