#include <gtest/gtest.h>
#include <bitset>
#include "Hamming8-4.cpp"


std::bitset<8> Hamming84_encode(std::bitset<4> data);
std::bitset<4> Hamming84_decode(std::bitset<8> code);


TEST(Hamming84Test, EncodeDecodeWithValidData) {

std::bitset<4> original_data(std::string("1001"));


std::bitset<8> encoded = Hamming84_encode(original_data);


std::bitset<4> decoded = Hamming84_decode(encoded);


EXPECT_EQ(decoded, original_data);
}

TEST(Hamming84Test, ErrorDetectionSingleError) {

std::bitset<8> test_code(std::string("11001111"));


std::bitset<4> decoded = Hamming84_decode(test_code);


EXPECT_NE(decoded, std::bitset<4>(std::string("1100")));
}

TEST(Hamming84Test, ErrorDetectionMultipleErrors) {

std::bitset<8> test_code(std::string("11001100"));


std::bitset<4> decoded = Hamming84_decode(test_code);


EXPECT_NE(decoded, std::bitset<4>(std::string("1100")));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
