#include "header.hpp"

std::vector<int> getJacobSequence(int count)
{
	std::vector<int> jsNum;

	jsNum.push_back(1);
	if (count == 1)
		return jsNum;
	if (count == 2) {
		jsNum.push_back(2);
		return jsNum;
	}

	jsNum.push_back(3);

	while (jsNum.back() < count)
	{
		int size = jsNum.size();
		int next = jsNum[size - 1] + 2 * jsNum[size - 2];
		jsNum.push_back(next);
	}

	if (jsNum.back() > count)
		jsNum.pop_back();
	if (jsNum.back() < count)
		jsNum.push_back(count);

	std::vector<int> filled;

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

	jsNum = filled;
	return jsNum;
}