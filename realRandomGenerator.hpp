// Real random C++ generator for windows and linux
#include <iostream>
#include <ctime>
long long int genFY(long long int from, long long int upto) {
	int gen = 1;
	int* getPtr = &gen; // random based on system virtual memory allocate
	long long int generator1 = reinterpret_cast<long long int>(getPtr);
	long long int result = 0;
	std::string resStr = std::to_string(generator1);
	char x = resStr[resStr[0]];
	if (x-'0' < 5 && (x-'0')%2==0) {
		generator1++;
	}
	if (upto == 1) {result = generator1 % (upto+1);}
	else {result = generator1 % upto;}
	return std::abs(result);
}

long long int generateRealRandomInt(long long int from, long long int upto) { // generateRealRandomInt(minimum, maximum);
	long long int result = from-1;
	while (result < from) {
		result = genFY(from,upto);
	}
	return std::abs(result);
}
