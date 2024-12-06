#include "all.hpp"

#include <vector>
#include <iostream>

int main(){
	std::vector<long long> v = {5,3,1};	

	cout << contains(v,5) << endl;
	cout << contains(v,1) << endl;
	cout << contains(v,6) << endl;
	
	for (int i=0; i<v.size(); i++){
		std::cout << v[i];
	}
	return 0;
}
