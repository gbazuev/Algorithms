#include <iostream>	
#include <vector>

int binary_search_non_recursive(const std::vector<int> vector, int findable)
{
	int begin = 0;
	int end = vector.size() - 1;

	while (begin <= end)
	{
		int mid = (end + begin) / 2;
		int current_element = vector[mid];

		if (current_element == findable)
		{
			return mid;
		}

		else if (current_element > findable)
		{
			end = mid - 1;
		}
		else
		{
			begin = mid + 1;
		}
	}
	return -1;
}

int binary_search_recursive(const std::vector<int> vector, int findable, int begin, int end)
{
	if (vector.at((begin + end) / 2) == findable)	{
		return (begin + end) / 2;
	}
	
	if (vector.at((end + begin) / 2) > findable)	{
		return binary_search_recursive(vector, findable, begin, --end);
	}
	else {
		return binary_search_recursive(vector, findable, --begin, end);
	}
}

int main()
{
	const std::vector<int> vector = { 2, 8, 10, 23, 45, 67, 88, 89, 90, 100, 122, 144, 150, 888 };
	std::cout <<"Non-recursive: "<<binary_search_non_recursive(vector, 67);
	std::cout<<"\nRecursive: "<<binary_search_recursive(vector, 88, 0, vector.size() - 1);
	return EXIT_SUCCESS;
}