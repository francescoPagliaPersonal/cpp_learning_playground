#include "header.hpp"



std::deque<int> getJacobSequence(int count)
{
	std::deque<int> jsNum;

	jsNum.push_back(0);
	jsNum.push_back(1);
	if (count == 2)
		return jsNum;
	if (count == 3) {
		jsNum.insert(jsNum.begin() + 1, 2);
		return jsNum;
	}

	jsNum.push_back(3);

	while (jsNum.back() < count - 1 )
	{
		int size = jsNum.size();
		int next = jsNum[size - 1] + 2 * jsNum[size - 2];
		jsNum.push_back(next);
	}

	if (jsNum.back() > count )
		jsNum.pop_back();
	if (jsNum.back() < count )
		jsNum.push_back(count );

	std::deque<int> filled;

	for (size_t i = 0; i < jsNum.size(); ++i)
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
	filled.pop_front();
	for (size_t i = 0; i < filled.size(); ++i)
		filled[i] -= 1;

	jsNum = filled;
	return jsNum;
}