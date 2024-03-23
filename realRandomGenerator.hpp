// Real random C++ generator for windows and linux
#include <string>
#include <thread>
#include "BigInt.hpp"

int pid = 0;

std::string readPiece(std::string inputString, int start, int end = -1) {
	if (end == -1) {end = inputString.length();}
	std::string result="";
	for (int i = start; i<end; i++) {
		result = result + inputString[i];
	}
	return result;
}

void genThread() {
	std::thread::id threadId = std::this_thread::get_id();
	std::hash<std::thread::id> hasher;
	pid = hasher(threadId);
}

template <typename T>
std::string generateRealRandomInt(T from, T upto) { // generateRealRandomInt(minimum, maximum);
	std::string result = "";
	
	std::string buf="";
	long long int* generatorOne = new long long int;
	long long int randomIntOne = reinterpret_cast<long long int>(generatorOne);
	buf = std::to_string(randomIntOne);
	int i = 1;
	long long int cf = randomIntOne%8128;
	while (buf.length() < upto) {
		void* generator = malloc(cf*i*21);
		buf += std::to_string(reinterpret_cast<long long int>(&generator));
		i++;
	}
	buf = readPiece(buf, from, upto);
	BigInt bigCalc = std::string(buf);
	std::thread t(genThread);
	t.join();
	BigInt prime = bigCalc + pid;
	bigCalc = prime % (upto+1);
	if (bigCalc < 0) {bigCalc = bigCalc * -1;}
	result = bigCalc.to_string();
	return result;
}
