#include "quicksort.h"

#include <vector>
#include <iostream>

int main(){
	std::vector<long long> v = {5,3,1};	
	quicksort(v);
	for (int i=0; i<v.size(); i++){
		std::cout << v[i];
	}
	return 0;
}
