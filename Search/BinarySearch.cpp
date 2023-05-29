#include <iostream>	
#include <vector>

int binary_search_non_recursive(const std::vector<int>& vector, const int& target) noexcept
{
	int begin = 0;
	int end = vector.size() - 1;

	while (begin <= end)
	{
		const int mid = (end + begin) / 2;

		if (vector[mid] == target)	{
			return mid;
		}
		else if (vector[mid] > target)	{
			end = mid - 1;
		}
		else	{
			begin = mid + 1;
		}
	}
	return -1;
}

int binary_search_recursive(const std::vector<int>& vector, const int& target, const int begin, const int end) noexcept
{
	const int middle_index = (begin + end) / 2;

	if (vector.at(middle_index) == target)	{
		return middle_index;
	}
	else if (vector.at(middle_index) > target)	{
		return binary_search_recursive(vector, target, begin, middle_index - 1);
	}
	else {
		return binary_search_recursive(vector, target, middle_index + 1, end);
	}
}

int main()
{
	const std::vector<int> vector = { 2, 8, 10, 23, 45, 67, 88, 89, 90, 100, 122, 144, 150, 888 };
	std::cout <<"Non-recursive: "<<binary_search_non_recursive(vector, 67);
	std::cout<<"\nRecursive: "<<binary_search_recursive(vector, 88, 0, vector.size() - 1);
	return EXIT_SUCCESS;
}