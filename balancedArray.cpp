#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
 * @return: index of the element around which array is balanced, 
 *  -1: if not balanced.
 * */
int balancedArrayIndex(vector<int> arr){
    
    int left = 0;
    int right = accumulate(arr.begin(), arr.end(), 0);
    
    
    for( unsigned  int i =0 ; i<arr.size() ; i++ ){
	
	right -= arr[i];
	
	if( left == right){
	    return i;
	    
	    }else{
		
		left += arr[i];

		}

	}
	return -1;

    }



int main(){
    vector<int> vec_0;
    
    vec_0.push_back(1); // 0
    vec_0.push_back(200); // 1
    vec_0.push_back(3); // 2
    vec_0.push_back(201); // 3
    
    cout << balancedArrayIndex(vec_0) << "\n";
    
    
    
    }
