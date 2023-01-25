#include <iostream>

using std::cout;
using std::endl;

class A{
    public:
    int _a;
    int _b;
    int* _aptr;

    A(int a,int b):_a(a), _b(b){

	_aptr = new int;

	}

    ~A(){

	if(_aptr){
	     delete _aptr;
	     _aptr = nullptr;
	}

	}

    int setA(int a_val){
	(*_aptr) = a_val;

	return 0;
    }

    void print(){
	    cout<<"_a:"<<_a<<endl;
	    cout<<"_aptr:"<<_aptr<<endl;
	    cout<<"(*_aptr):"<<(*_aptr)<<endl;
	    cout<<"&_aptr:"<<(&_aptr)<<endl;
	    cout<<"_b:"<<_b<<endl;

    }

    };

int main(){

	A obj_1(10,15);
	obj_1.setA(100);
	cout<<"++++_START_obj_1++++"<<endl;
	obj_1.print();
	cout<<"++++_END_obj_1++++"<<endl;


	/*This calls copy constructor. */
	A obj_2 = obj_1;
	cout<<"++++_START_obj_2++++"<<endl;
	obj_2.print();
	cout<<"++++_END_obj_2++++"<<endl;


	obj_1.setA(150);

	/*This calls assignment operator function. */
	obj_2 = obj_1;

	cout<<"++++_START_obj_1++++"<<endl;
	obj_1.print();
	cout<<"++++_END_obj_1++++"<<endl;
	cout<<"++++_START_obj_2++++"<<endl;
	obj_2.print();
	cout<<"++++_END_obj_2++++"<<endl;


	cout<<"Notice the value of _aptr of both objects, they are Same. Indicating they are pointing to Same memory locations."<<endl<<"The values are getting updated, but the memory locations are same, meaning if one object 'deletes' the memory location, the other object won't be able to access it again.'"<<endl;;

	return 0;

}
