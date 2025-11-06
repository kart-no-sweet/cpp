#include <iostream>
#include <vector>

void passByRef(const std::vector<int> &arr) {
  std::cout << "passByRef: " << arr[0] << '\n';
}

template <typename T>
void passByTemplateRef(const T &arr) // will accept any type of object that has
                                     // an overloaded operator[]
{
  std::cout << "passByTemplateRef: " << arr[1] << '\n';
}

// For C++20
// void passByRef(const auto& arr) // abbreviated function template
// {
//     std::cout << arr[0] << '\n';
// }

int main() {

  int myArray[] = {1, 2, 3, 4, 5};
  std::vector<int> my_vector(myArray, myArray + 5);

  // Using vector::size_type
  std::vector<int>::size_type vector_size = my_vector.size();
  std::cout << "Vector size: " << vector_size << std::endl;

  // Iterating with size_type
  for (std::vector<int>::size_type i = 0; i < my_vector.size(); ++i) {
    std::cout << my_vector[i] << " ";
  }
  std::cout << "\n";

  passByRef(my_vector);
  passByTemplateRef(my_vector);

  return 0;
}