#include <iostream>
#include <bitset>

std::bitset<8> Hamming84_encode(std::bitset<4> data) {
	std::bitset<8> code;
	
	code[2] = data[3]; //d1
	code[4] = data[2]; //d2
	code[5] = data[1]; //d3
	code[6] = data[0]; //d4
	
	
	code[0] = (1 + code[2] + code[5] + code[6]) % 2; // p1
	code[1] = (1 + code[2] + code[4] + code[6]) % 2; // p2
	code[3] = (1 + code[2] + code[4] + code[5]) % 2; // p3
	code[7] = (1 + code[0] + code[1] + code[2] + code[3] + code[4] + code[5] + code[6]) % 2; // p4
	
	return code;
}

std::bitset<4> Hamming84_decode(std::bitset<8> code) {
	
	bool A = (1 + code[0] + code[2] + code[4] + code[6]) % 2;
	bool B = (1 + code[1] + code[2] + code[5] + code[6]) % 2;
	bool C = (1 + code[3] + code[4] + code[5] + code[6]) % 2;
	bool D = (1 + code[0] + code[1] + code[2] + code[3] + code[4] + code[5] + code[6] + code[7]) % 2;
	
	
	int error_position = A * 1 + B * 2 + C * 4 + D * 8;
	
	if (!A && !B && !C && !D) {
		std::cout << "There is no error. Code is accepted." << std::endl;
	}
	
	else if (D && !A && !B && !C)  {
		std::cout << "There is an error in p4. Code is accepted.";
	}
	
	else if (!D && (A+B+C) != 0) {
		std::cout << "Double error. Rejected.";
	}
	
	else if (error_position != 0) {
		code.flip(error_position - 1);
	}
	
	std::bitset<4> data;
	data[3] = code[2];
	data[2] = code[4];
	data[1] = code[5];
	data[0] = code[6];
	
	return data;
}

int main() {
	std::bitset<4> data(std::string("1001"));
	std::bitset<8> encoded = Hamming84_encode(data);
	std::cout << "Hamming code (8,4) for " << data << " is " << encoded << "." << std::endl;
	
	std::bitset<4> decoded = Hamming84_decode(encoded);
	std::cout << "Decoded data is " << decoded << "." << std::endl;
	
	return 0;
}
