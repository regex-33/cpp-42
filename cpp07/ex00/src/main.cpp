#include "../Includes/whatever.hpp"

// int main() {
//   int First = 9;
//   int Second = 9;
//   std::cout << "Befor :\n First : " << First << " Second : " << Second
//             << std::endl;
//   ::swap<int>(First, Second);
//   std::cout << "After:\n First : " << First << " Second : " << Second
//             << std::endl;
//
//   std::cout << "---------------------------------------" << std::endl;
//   std::cout << "max : " << ::max(First, Second) << std::endl;
//   std::cout << "---------------------------------------" << std::endl;
//   std::cout << "min : " << ::min(First, Second) << std::endl;
//   return 0;
// }

int main(void) {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  return 0;
}
