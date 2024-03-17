// 
// Author        : summer
// Description   : vector
// 
// Revision      :
// Rev.    Date        Designer    Description
// 1.0     2024-03-16  summer      Initial version
// 

#include "summer_vector.h"
#include <iostream>

int main() {
  Summer::vector<int> v;
  v.push_back(9);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v[3] = 33;
  v.pop_back();
  v.reserve(30);
  v.reserve(5);
  v.print();
  v.resize(10);
  v.print();
  std::cout << std::endl;
  std::cout << "size: " << v.size() << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  std::cout << "empty: " << v.empty() << std::endl;
  std::cout << "3: " << v.at(3) << std::endl;
  std::cout << "front: " << v.front() << std::endl;
  std::cout << "back: " << v.back() << std::endl;

  std::cout << std::endl;
  std::cout << "v" << std::endl;
  v.print();
  std::cout << std::endl;
  Summer::vector<int>v2;
  v2.swap(v);
  std::cout << "v" << std::endl;
  v.print();
  std::cout << std::endl;
  std::cout << "v2" << std::endl;
  v2.print();
  std::cout << std::endl;


  v.clear();
  v.print();

  return 0;
}
