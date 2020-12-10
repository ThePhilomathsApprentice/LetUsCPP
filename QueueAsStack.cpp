#include <stack>
#include <iostream>

using namespace std;

class Q{
    public: 
    
    std::stack<int> S1;

    std::stack<int> S2;

void enQueue( int x ){
	    	std::cout << "pushed " << x << "\n"; 

	    if( S1.empty() ){
		while( !S2.empty() ){
		    
		    S1.push( S2.top());
		    S2.pop();
		    }
		S1.push(x);		

		while( !S1.empty() ){
		    
		    S2.push( S1.top());
		    S1.pop();
		    }

		}else if( S2.empty() ){
		while( !S1.empty() ){
		    
		    S2.push( S1.top());
		    S1.pop();
		    }
		S2.push(x);		

		while( !S2.empty() ){
		    
		    S1.push( S2.top());
		    S2.pop();
		    }

		}
		
    }    
    
    
int deQueue( ){
    
    int ret = -1;

	    if( !S1.empty() ){
		 ret = S1.top();
	 	std::cout << "S1.Top is:" << ret << "\n"; 

		 S1.pop();
		return ret;
		
		}else if( !S2.empty() ){
			ret =  S2.top();
		 	std::cout << "S2.Top is:" << ret << "\n"; 
			 S2.pop();
			return ret;
		    }else{
			
		 	std::cout << "Top is: NULL (both empty)\n"; 
			return ret;
			
			}
		
			return ret;
	}
    
    };
    
    
    int main(){
	
	Q q1;
	std::cout << " Starting enQueue\n";
	
	q1.enQueue(1);
	q1.enQueue(2);
	q1.enQueue(3);
	q1.enQueue(4);
	q1.enQueue(11);
	
	std::cout << q1.deQueue() << "\n"; // 1
	std::cout << q1.deQueue() << "\n"; // 2
	std::cout << q1.deQueue() << "\n"; // 3
	
	q1.enQueue(5);
	q1.enQueue(6);
	q1.enQueue(7);
	q1.enQueue(10);
	
	std::cout << q1.deQueue() << "\n"; // 4
	std::cout << q1.deQueue() << "\n"; // 11
	std::cout << q1.deQueue() << "\n"; // 5
	std::cout << q1.deQueue() << "\n"; // 6
	std::cout << q1.deQueue() << "\n"; // 7
	std::cout << q1.deQueue() << "\n"; // 11
	
	std::cout << q1.deQueue() << "\n"; // -1
	
	std::cout << " Exiting enQueue\n";
//	std::cin.get();
	
	
	return 0;
	
    }
