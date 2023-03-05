#include <iostream>
#include <vector>

std::vector<int> quick_sort(std::vector<int>& vector, size_t begin, size_t end)
{
    size_t local_begin = begin;
    size_t local_end = end;
    int pivot = vector.at((local_begin + local_end) / 2);

    while (local_begin < local_end)
    {
      while (vector.at(local_begin) < pivot)  {
        local_begin++;
      }
      while (vector.at(local_end) > pivot)  {
        local_end--;
      }
      if (local_begin <= end) {
        std::swap(vector.at(local_begin++), vector.at(local_end--));
      }
    }

    if (local_begin < end)  {
      quick_sort(vector, local_begin, end);
    }
    if (local_end > begin)  {
      quick_sort(vector, begin, local_end);
    }
}

int main()
{
    std::vector<int> vector = {8, 44, 21, 2, 34, 5, 6, 90, 121, 888};
    std::cout<<"Not sorted vector: ";
    for (const auto& val : vector)  {
        std::cout<<val<<"  ";
    }

    vector = quick_sort(vector);
    
    std::cout<<"\nSorted vector: ";
    for (const auto& val : vector)  {
        std::cout<<val<<"  ";
    }
    return EXIT_SUCCESS;
}