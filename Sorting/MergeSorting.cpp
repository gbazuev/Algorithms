#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

void merge_sort(std::vector<int>& vec, std::size_t begin, std::size_t end)
{
    if (end - begin < 2) return;

    std::size_t const mid = (begin + end) / 2;
    merge_sort(vec, begin, mid);
    merge_sort(vec, mid, end);

    std::vector<int> buf;
    buf.reserve(end - begin);

    std::size_t left = begin, right = mid;
    while (left < mid && right < end)   {
        if (vec[left] < vec[right])  {
            buf.push_back(vec[left++]);
        }
        if (vec[left] > vec[right])  {
            buf.push_back(vec[right++]);
        }
    }

    while (left < mid)  {
        buf.push_back(vec[left++]);
    }

    while (right < end) {
        buf.push_back(vec[right++]);
    }

    std::copy(buf.begin(), buf.end(), vec.begin() + begin);
}

int main(int argc, const char** const argv)
{
    std::vector<int> vec = { 38, 27, 43, 10 };
    
    std::cout << "Unsorted vector: ";
    for (auto const &i : vec)   {
        std::cout << i << " ";
    }

    merge_sort(vec, 0, vec.size());

    std::cout << "\nSorted vector: ";
    for (auto const &i : vec)   {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}
