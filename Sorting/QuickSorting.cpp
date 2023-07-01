#include <cstddef>
#include <iostream>
#include <vector>

void quick_sorting(std::vector<int>& vector, const std::size_t begin, const std::size_t end) noexcept
{
    std::size_t local_begin = begin, local_end = end;
    int pivot = vector[(begin + end) / 2];
    while (local_begin <= local_end)
    {
      while (vector[local_begin] < pivot)  {
        local_begin++;
      }
      while (vector[local_end] > pivot)  {
        local_end--;
      }
      if (local_begin <= local_end) {
        std::swap(vector[local_begin++], vector[local_end--]);
      }
    }

    if (local_begin < end)  {
      quick_sorting(vector, local_begin, end);
    }
    if (local_end > begin)  {
      quick_sorting(vector, begin, local_end);
    }
}

int main(int argc, const char** argv)
{
    std::vector<int> vector = {8, 44, 21, 2, 34, 5, 6, 90, 121, 888};
    std::cout<<"Not sorted vector: ";
    for (const auto& val : vector)  {
        std::cout<<val<<"  ";
    }

    quick_sorting(vector, 0, vector.size() - 1);
    
    std::cout<<"\nSorted vector: ";
    for (const auto& val : vector)  {
        std::cout<<val<<"  ";
    }
    return EXIT_SUCCESS;
}
