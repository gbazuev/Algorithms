#include <iostream>
#include <vector>

std::size_t linear_search_non_recursive(const std::vector<int>& vector, const int target) noexcept {
  for (std::size_t i = 0u; i < vector.size(); i++)    {
    if (vector[i] == target)   return i;
  }
  return -1;
}

std::size_t linear_search_recursive(const std::vector<int>& vector, const int target, const int index) noexcept {
  if (vector.size() == index) {
    return -1;
  }
  else if (vector[index] == target) {
    return index;
  }
  return linear_search_recursive(vector, target, index + 1);
}
    
int main(int argc, const char** argv)
{
  const std::vector<int> vector = {12, 14, 16, 24, 27, 28, 35, 38, 90, 450, 888, 1024};
  std::cout<<"Non-recursive: "<<linear_search_non_recursive(vector, 28)<<std::endl;
  std::cout<<"Recursive: "<<linear_search_recursive(vector, 888, 0)<<std::endl;
  return EXIT_SUCCESS;
} 