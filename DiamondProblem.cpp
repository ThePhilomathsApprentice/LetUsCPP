
#define useVirtualInheritance 0

#if useVirtualInheritance

	#include <iostream>
	using std::cout;
	using std::endl;

	class A{
	public: 
	A(int a){
	cout<<"Class_A: Constructor called "<<endl;
	_a = a;
	}
	~A(){
	cout<<"Class_A: Destructor called "<<endl;
	}

	int _a;
	void print(){
	cout<<"a:"<<_a<<endl;

	}


	};

	class B:  virtual  public A{
	public: 
	B(int b=0,int a=0): 
	A{a}{
	cout<<"Class_B: Constructor called "<<endl;
	_b = b;
	}
	~B(){
	cout<<"Class_B: Destructor called "<<endl;
	}

	int _b;
	void print(){
	cout<<"a:"<<_a<<endl;
	cout<<"b:"<<_b<<endl;

	}


	};

	class C: virtual public  A{
	public: 
	C(int c=0,int a=0): 
	A{a}{
	cout<<"Class_C: Constructor called "<<endl;
	_c = c;

	}
	~C(){
	cout<<"Class_C: Destructor called "<<endl;

	}

	int _c;
	void print(){
	cout<<"a:"<<_a<<endl;
	cout<<"c:"<<_c<<endl;

	}


	};

	class D: public C, public B {
	public:
	D(int d=0,int c=0,int b=0,int a=0): 
	C{b},B{c},A{a}{
	cout<<"Class_D: Constructor called "<<endl;
	_d =d;

	}
	~D(){
	cout<<"Class_D: Destructor called "<<endl;

	}

	int _d;
	void print(){
	cout<<"C::a:"<<C::_a<<endl;
	cout<<"B::a:"<<B::_a<<endl;
	cout<<"b:"<<_b<<endl;
	cout<<"c:"<<_c<<endl;
	cout<<"d:"<<_d<<endl;

	}

	};
	
	
	int main(){

	cout<<"Using Virtual Inheritance for the Classes."<<endl;

	//~ A a_obj(5);
	//~ a_obj.print();

	// B b_obj(10,15);
	// b_obj.print();

	// C c_obj(10,15);
	// c_obj.print();

	D d_obj(10,15,20,50);
	d_obj.print();

	}


#else

	#include <iostream>
	using std::cout;
	using std::endl;

	class A{
	public: 
	A(int a){
	cout<<"Class_A: Constructor called "<<endl;
	_a = a;
	}
	~A(){
	cout<<"Class_A: Destructor called "<<endl;
	}

	int _a;
	void print(){
	cout<<"a:"<<_a<<endl;

	}


	};

	class B: public A{
	public: 
	B(int b=0,int a=0): 
	A{a}{
	cout<<"Class_B: Constructor called "<<endl;
	_b = b;
	}
	~B(){
	cout<<"Class_B: Destructor called "<<endl;
	}

	int _b;
	void print(){
	cout<<"a:"<<_a<<endl;
	cout<<"b:"<<_b<<endl;

	}


	};

	class C: public  A{
	public: 
	C(int c=0,int a=0): 
	A{a}{
	cout<<"Class_C: Constructor called "<<endl;
	_c = c;

	}
	~C(){
	cout<<"Class_C: Destructor called "<<endl;

	}

	int _c;
	void print(){
	cout<<"a:"<<_a<<endl;
	cout<<"c:"<<_c<<endl;

	}


	};

	class D: public C, public B {
	public:
	D(int d=0,int c=0,int b=0,int a=0): 
	C{b,a},B{c,(a+2)}{
	cout<<"Class_D: Constructor called "<<endl;
	_d =d;

	}
	~D(){
	cout<<"Class_D: Destructor called "<<endl;

	}

	int _d;
	void print(){
	cout<<"C::a:"<<C::_a<<endl;
	cout<<"B::a:"<<B::_a<<endl;
	cout<<"b:"<<_b<<endl;
	cout<<"c:"<<_c<<endl;
	cout<<"d:"<<_d<<endl;

	}

	};
	
	
	int main(){
	cout<<"NOT Using Virtual Inheritance for the Classes."<<endl;

	//~ A a_obj(5);
	//~ a_obj.print();

	// B b_obj(10,15);
	// b_obj.print();

	// C c_obj(10,15);
	// c_obj.print();

	D d_obj(10,15,20,50);
	d_obj.print();

	}



#endif
