#pragma once
#include <stdint.h>

class RandomFunctions
{
private:
	
	uint32_t mSeedGeneration = 0;

public:

	void SetSeed(uint32_t newSeed) 
	{
		this->mSeedGeneration = newSeed;
	}
	uint32_t rnd()
	{
		mSeedGeneration += 0xe120fc15;
		uint64_t tmp;
		tmp = (uint64_t)mSeedGeneration * 0x4a39b70d;
		uint32_t m1 = (tmp >> 32) ^ tmp;
		tmp = (uint64_t)m1 * 0x12fad5c9;
		uint32_t m2 = (tmp >> 32) ^ tmp;
		return m2;
	}

	int randomInt(int min, int max)
	{
		return (rnd() % (max - min)) + min;
	}

	float randomFloat(float min, float max)
	{
		return ((float)rnd() / (float)(0x7FFFFFFF)) * (max - min) + min;
	}
};

