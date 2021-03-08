#include <iostream>

using std::cout;
using std::endl;

class A{
    public:
    int _a;
    int _b;
    int* _aptr;
    
    
    A(int a,int b):_a(a), _b(b){
	cout<<"entered  constructor"<<endl;
	
	_aptr = nullptr;

	}

    A(const A& obj_a):_aptr(nullptr){
	cout<<"entered  copy constructor"<<endl;
	deepCopy(obj_a);

	}

    A operator=(const A& obj_a){
	cout<<"entered operator=:"<<endl;
	
	// check for self-assignment
	if (this == &obj_a) return *this;
 
 	deepCopy(obj_a);
 
	return *this;
	
	}
    
    ~A(){
	cout<<"entered  destructor"<<endl;
	
	if(_aptr){
	     delete _aptr ;
	     _aptr = nullptr;
	}

	}
	
	
	void deepCopy(const A& obj_a){
	    if(_aptr){
		delete _aptr;
		}
		
	   _a = obj_a._a;
	   _b = obj_a._b;
	   
	   if( obj_a._aptr ){
	       
	       _aptr = new int(*( obj_a._aptr ));
	    }else{
	    	_aptr = nullptr;
	    }
	   
	    
	}

    int setA(int a_val){
	cout<<"entered  seetA"<<endl;

	if(_aptr == nullptr){
		_aptr = new int(a_val);

	}else{
	    
	    (*_aptr) = a_val;
	    
	}
	
	return 0;
    }
	
    void print(){
	    cout<<"_a:"<<_a<<"\t_b:"<<_b<<endl;

	    cout<<"&_aptr:"<<(&_aptr)<<"\t_aptr:"<<_aptr<<"\t(*_aptr):"<<(*_aptr)<<"\n";
	    
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


	cout<<"Notice the value of _aptr, they both are different, indicating they are pointing to different memory locations."<<endl;


	return 0;

    }
