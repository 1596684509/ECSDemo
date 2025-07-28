#include "BitMask.h"


BitMask::BitMask(size_t size) : size(size) {

	//位掩码数组长度
	size_t length = (size + BITS_BLOCK_SIZE - 1) / BITS_BLOCK_SIZE;
	bitMask.resize(length, 0);

}

int BitMask::get(size_t index) {

	if (index >= size) {
		return -1;
	}

	size_t blockIndex = index / BITS_BLOCK_SIZE;
	size_t bitMaskIndex = index % BITS_BLOCK_SIZE;

	uint64_t block = bitMask[blockIndex];
	return (block >> bitMaskIndex) & 1ULL;

}

void BitMask::set(size_t index) {

	if (index >= size) {
		return;
	}

	size_t blockIndex = index / BITS_BLOCK_SIZE;
	size_t bitMaskIndex = index % BITS_BLOCK_SIZE;

	uint64_t& block = bitMask[blockIndex];
	block |= (1ULL << bitMaskIndex);

}

void BitMask::clear(size_t index) {

	if (index >= size) {
		return;
	}

	size_t blockIndex = index / BITS_BLOCK_SIZE;
	size_t bitMaskIndex = index % BITS_BLOCK_SIZE;

	uint64_t& block = bitMask[blockIndex];
	block &= ~(1ULL << bitMaskIndex);

}

bool BitMask::operator==(const BitMask& bitMask) const{

	if (size != bitMask.size) {
		return false;
	}

	for (size_t i = 0; i < this->bitMask.size(); i++) {
	
		if (bitMask.bitMask[i] != this->bitMask[i]) {
		
			return false;

		}

	}

	return true;

}

bool BitMask::operator!=(const BitMask& bitMask) const {

	return !(*this == bitMask);

}

std::string BitMask::toString() {
	std::string result;
	for (uint64_t block : bitMask) {
		// 用 bitset<64> 转成64位二进制字符串，补齐0
		std::bitset<64> bits(block);
		// 直接拼接
		result += bits.to_string();
	}
	return result;

}

BitMask* BitMask::createComponentBitMask() {

	return new BitMask(static_cast<size_t>(ComponentType::Count));

}