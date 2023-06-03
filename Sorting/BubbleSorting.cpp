#include <iostream>
#include <vector>

void bubble_sorting(std::vector<int>& vector) noexcept 
{
    bool is_sorted = true;
    for (size_t i = 0; i < vector.size(); i++)      
    {
        for (size_t j = 0; j < vector.size() - 1; j++)  
        {
            if (vector.at(j) > vector.at(j + 1))    
            {
                std::swap(vector.at(j), vector.at(j + 1)); 
                is_sorted = false;
            }
        }
        if (is_sorted)  return;
    }
}

int main(int argc, const char** argv)
{
    std::vector<int> vector = {88, 11, 4, 6, 8, 12, 34, 56, 67};

    std::cout<<"Not sorted: ";
    for (const int& elem : vector)  {
        std::cout<<elem<<"  ";
    }

    bubble_sorting(vector);

    std::cout<<"\nSorted: ";
    for (const int& elem : vector)  {
        std::cout<<elem<<"  ";
    }

    std::cout<<std::endl;

    return EXIT_SUCCESS;
}