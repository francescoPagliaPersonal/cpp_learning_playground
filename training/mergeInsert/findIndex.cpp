#include "header.hpp"
#include <ostream>

ptr_id findIndex(std::vector<node_s *> & arr, int value) {
	ptr_id low = 0;
	ptr_id high = arr.size(); 
	while (low < high) {
		ptr_id mid = low + (high - low) / 2;
		__counter++;
		if (arr[mid]->value < value) low = mid + 1;
		else high = mid;
	}
	return low;
}