#include "header.hpp"
#include <vector>



std::vector<int> jacobstahlSeq(int size)
{
	std::vector<int> jsNum;
	jsNum.reserve(10);

	jsNum.push_back(0);
	jsNum.push_back(1);
	if (size == 2)
		return jsNum;
	if (size == 3) {
		jsNum.insert(jsNum.begin() + 1, 2);
		return jsNum;
	}

	jsNum.push_back(3);

	while (jsNum.back() < size - 1 )
	{
		int size = jsNum.size();
		int next = jsNum[size - 1] + 2 * jsNum[size - 2];
		jsNum.push_back(next);
	}

	if (jsNum.back() > size )
		jsNum.pop_back();
	if (jsNum.back() < size )
		jsNum.push_back(size );

	std::vector<int> filled;
	filled.reserve(size);

	for (size_t i = 1; i < jsNum.size(); ++i)
	{
		filled.push_back(jsNum[i]);
		if (i > 0)
		{
			int prev = jsNum[i - 1];
			int curr = jsNum[i];
			
			for (int x = curr - 1; x > prev ; --x)
				filled.push_back(x);
		}
	}
	for (size_t i = 0; i < filled.size(); ++i)
		filled[i] -= 1;

	return filled;
}