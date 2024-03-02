#include <iostream>
#include <sys/types.h>
#include <vector>

void insertion_sorting(std::vector<int> &arr) noexcept
{
    if (arr.size() < 2) return;

    for (std::size_t i = 1; i < arr.size(); ++i)   {
        int const current_elem = arr[i];

        if (current_elem < arr[i - 1]) {
            for (ssize_t j = i - 1; j >= 0; --j)    {
                if (j == 0 && arr[j] > current_elem)    {
                    arr.insert(arr.begin(), current_elem);
                    arr.erase(arr.begin() + i + 1);
                }

                else if (arr[j] <= current_elem) {
                    arr.insert(arr.begin() + j + 1, current_elem);
                    arr.erase(arr.begin() + i + 1);
                    break;
                }
            }
        }
    }
}

int main(int argc, const char** const argv)
{
    std::vector<int> vec = { 9, 7, 8, 6, 4, 5, 2, 3, 1};
    insertion_sorting(vec);

    for (const int &elem : vec) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;

    return 0;
}
