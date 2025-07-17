#pragma once

#include <vector>
#include <functional> 
#include <string>
#include <bitset>

#include "../Component/ComponentType.h"

class BitMask {
public:
	BitMask();
	BitMask(size_t size);
	std::string toString();
	int get(size_t index);
	void set(size_t index);
	void clear(size_t index);

	bool operator==(const BitMask& bitMask) const;
	bool operator!=(const BitMask& bitMask) const;


private:
	size_t size;
	std::vector<uint64_t> bitMask;

	static constexpr size_t BITS_BLOCK_SIZE = 64;

};