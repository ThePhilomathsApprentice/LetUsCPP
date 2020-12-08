#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Positions {
    public: 
    int _x, _y;

    Positions():
    _x(0),_y(0)
    {
	}
    
    Positions(int x, int y ):
    _x(abs(x)),_y(abs(y))
    {
	}
    
    Positions operator -( const Positions& a){
	
	if( abs(this->_x) > abs(a._x) ) (this->_x) = abs(this->_x) - abs(a._x);
	else (this->_x) = abs(a._x) - abs(this->_x) ;

	if( abs(this->_y) > abs(a._y) )(this->_y) = abs(this->_y) - abs(a._y);
	else (this->_y) = abs(a._y) - abs(this->_y) ;
		
	return *this;

	}
	
    Positions operator =( const Positions& a){
	
	if (this == &a) return *this;

//	Positions diff( abs(a._x) ,  abs(a._y)  );
	this->_x = a._x;
	this->_y = a._y;
	
	return *this;

	}
	
    };

int diffPositions ( Positions a, Positions b ) {

    Positions distance = a-b;
    return (distance._x + distance._y);

    }


Positions ClosestCoin ( Positions myPos, std::vector<Positions> coinPos)
{
    Positions closestCoin;
    int diffClosestPosition=-1;
    
    for( unsigned int i=0 ;  i < coinPos.size() ;  i++  ){
	
	if( i == 0 ){
	    closestCoin = coinPos[i] ;
	    diffClosestPosition = diffPositions(myPos, closestCoin);

	    }
	    else if( diffPositions(myPos, coinPos[i] ) < diffClosestPosition ){
		    closestCoin = coinPos[i] ;
		    diffClosestPosition = diffPositions(myPos, closestCoin);

		    }else{
			//DO Nothing;

		    }

	}

    return closestCoin;
}
    
int main(){
    Positions myPos(14,16);
    Positions oneCoin(1,0);
    Positions twoCoin(3,4);
    Positions threeCoin(6,7);
    Positions fourCoin(10,10);
    Positions fiveCoin(20,20);

    std::vector<Positions> coinsPos;
    coinsPos.push_back(oneCoin);
    coinsPos.push_back(twoCoin);
    coinsPos.push_back(threeCoin);
    coinsPos.push_back(fiveCoin);
    coinsPos.push_back(fourCoin);
    
    Positions closestCoin = ClosestCoin(myPos, coinsPos );
    
    std::cout << "Closest Coin is : (" << closestCoin._x << "," <<  closestCoin._y << ")" <<"\n";
    std::cout << "And Distance is: " << diffPositions(myPos,closestCoin) << "\n";
    
    return 0;
    
    }
