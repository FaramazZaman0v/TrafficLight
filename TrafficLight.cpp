#include <iostream>
#include <vector>
#include <map>

int main(){
	std::vector<int> cars={1,3,5,2,4}, D={2,1,2,4,3}, T={10,20,30,40,40};
	int tmp=0;
	std::map<int, int> d1, d2, d3, d4;
	
	for(int i=0; i<(int)cars.size(); i++){
		if( (D[i]==1 || D[i]==2) && tmp==1) {
			tmp=0;
			std::cout << "Traffic Light on road A is green\n";
			d1.clear();
			d2.clear();
		}
		else if( (D[i]==3 || D[i]==4) && tmp==0) {
			tmp=1;
			std::cout << "Traffic Light on road B is green\n";
			d3.clear();
			d4.clear();
		}
//------------------------------------------------------------		
		if(D[i]==1) {
			d1[T[i]]++;
			if( d1[T[i]]>2){
				std::cout << "road A in direction 1 is full!\n IMPOSIBLE!!!\n";
				return -1;
			}
		}
		else if(D[i]==2) {
			d2[T[i]]++;
			if( d2[T[i]]>2){
				std::cout << "road A in direction 2 is full!\n IMPOSIBLE!!!\n";
				return -2;
			}
		}
		else if(D[i]==3) {
			d3[T[i]]++;
			if( d3[T[i]]>1){
				std::cout << "road B in direction 3 is full!\n IMPOSIBLE!!!\n";
				return -3;
			}
		}
		else if(D[i]==4) {
			d4[T[i]]++;
			if( d4[T[i]]>1){
				std::cout << "road B in direction 4 is full!\n IMPOSIBLE!!!\n";
				return -3;
			}
		}
//---------------------------------------------------------------------------------		
		std::cout << "Car " << cars[i] << " passed in direction " << D[i] << "\n";
	}
	return 0;
}
