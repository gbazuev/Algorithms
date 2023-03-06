#include <iostream>
#include <vector>

void quick_sort(std::vector<int> *vector, int begin, int end)
{
    int local_begin = begin;
    int local_end = end;
    int pivot = vector->at((begin + end) / 2);
    while (local_begin <= local_end)
    {
      while (vector->at(local_begin) < pivot)  {
        local_begin++;
      }
      while (vector->at(local_end) > pivot)  {
        local_end--;
      }
      if (local_begin <= local_end) {
        std::swap(vector->at(local_begin++), vector->at(local_end--));
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

    quick_sort(&vector, 0, vector.size() - 1);
    
    std::cout<<"\nSorted vector: ";
    for (const auto& val : vector)  {
        std::cout<<val<<"  ";
    }
    return EXIT_SUCCESS;
}
