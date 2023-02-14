#include <iostream>	
#include <vector>

int binary_search(const std::vector<int> vector, int findable)
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

int main()
{
	const std::vector<int> vector = { 2, 8, 10, 23, 45, 67, 88, 89, 90, 100, 122, 144, 150, 888 };
	std::cout << binary_search(vector, 67);
	return EXIT_SUCCESS;
}