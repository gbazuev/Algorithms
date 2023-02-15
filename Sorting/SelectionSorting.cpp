#include <iostream>
#include <vector>

std::vector<int> selection_sort(std::vector<int> vector) noexcept 
{
	for (size_t i = 0; i < vector.size() - 1; ++i) 
	{
		int smallest_index = i;
		for (size_t j = i + 1; j < vector.size(); ++j) {
			if (vector.at(j) < vector.at(smallest_index)) {
				smallest_index = j;
			}
			if (smallest_index != i) {
				std::swap(vector.at(i), vector.at(smallest_index));
			}
		}
	}
	return vector;
} 


int main(int argc, char** argv)
{
	std::vector<int> vector = selection_sort( { 13, 12, 23, 98, 8, 99, 100 });
	
	std::cout << "Unsorted: ";
	for (const auto& loop_value : vector) {
		std::cout << loop_value << "  ";
	}

	vector = selection_sort(vector);

	std::cout << "\nSorted: ";
	for (const auto& loop_value : vector) {
		std::cout << loop_value << "  ";
	}

	return EXIT_SUCCESS;
}
