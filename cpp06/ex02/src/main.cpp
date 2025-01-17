#include "../Includes/Identify.hpp"

int main() {
  Base *obj = generate();

  // -> Identify using a pointer
  identify(obj);

  // -> Identify using a reference
  if (obj) {
    identify(*obj);
  }

  delete obj;

  return 0;
}
