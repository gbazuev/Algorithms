#include <iostream>
#include <vector>

std::vector<int> selection_sorting_non_recursive(std::vector<int>& vector) noexcept 
{
	for (size_t i = 0; i < vector.size() - 1; ++i) 
	{
		size_t smallest_index = i;
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

std::vector<int> selection_sorting_recursive(std::vector<int>& vector, size_t begin) noexcept
{
	size_t min_index = begin;
	for (size_t i = begin + 1; i < vector.size(); i++)	{
		if (vector[i] < vector[min_index])	{
			min_index = i;
		}
	}

	if (min_index != begin)	{
		std::swap(vector[min_index], vector[begin]);
	}	
	if (begin < vector.size() - 1)	{
		return selection_sorting_recursive(vector, begin + 1);
	}	

	return vector;
}


int main(int argc, char** argv)
{
	std::vector<int> first_vector = { 13, 12, 23, 98, 8, 99, 100 };
	std::vector<int> second_vector = {99, 87, 23, 1, 12, 88, 100, 74};

	std::cout << "Unsorted (non-recursive): ";
	for (const int& loop_value : first_vector) {
		std::cout << loop_value << "  ";
	}

	std::cout<<"\nUnsorted (recursive): ";
	for (const int& loop_value : second_vector)	{
		std::cout<<loop_value<<"  ";
	}

	first_vector = selection_sorting_non_recursive(first_vector);
	second_vector = selection_sorting_recursive(second_vector, 0);

	std::cout << "\n\nSorted (non-recursive): ";
	for (const int& loop_value : first_vector) {
		std::cout << loop_value << "  ";
	}

	std::cout<<"\nSorted (recursive): ";
	for (const int& loop_value : second_vector)	{
		std::cout<<loop_value<<"  ";
	}

	return EXIT_SUCCESS;
}
