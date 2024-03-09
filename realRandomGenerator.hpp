// Real random C++ generator for windows and linux
#include <iostream>
#include <ctime>
long long int generateRealRandomInt(long long int from, long long int upto) { // generateRealRandomInt(minimum, maximum);
	std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
	char buffer[128];
    strftime(buffer, sizeof(buffer), "%m%d%Y%S", now);
	signed long long int bufToInt = std::stoi(buffer);
	int gen = 11;
	int* getPtr = &gen; // random based on system virtual memory allocate
	signed long long int generator1 = reinterpret_cast<signed long long int>(getPtr);
	int agen = generator1 % gen;
	long long int result = from * agen * generator1 * bufToInt;
	result = std::abs(result);
	while (result % 2 == 0 || result % 3 == 0 || result % 5 == 0 || result % 7 == 0) {
		result++;
	}
	result = result % upto;
	while (result < from) {
		result = result * from * generator1 * bufToInt % upto;
	}
	return std::abs(result);
}