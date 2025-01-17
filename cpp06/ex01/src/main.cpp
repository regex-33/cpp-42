#include "../Includes/Serializer.hpp"
#include <iostream>

int main() {
  // Create a Data object and initialize its members using the parameterized
  // constructor
  Data originalData(42, "Test Serialization", 3.14f);

  // Print the original Data object
  std::cout << "\nOriginal Data:\n";
  std::cout << "ID: " << originalData.getId() << "\n";
  std::cout << "Name: " << originalData.getName() << "\n";
  std::cout << "Value: " << originalData.getValue() << "\n";

  // Serialize the Data object
  uintptr_t raw = Serializer::serialize(&originalData);
  std::cout << "\nSerialized uintptr_t: " << raw << "\n";

  // Deserialize the uintptr_t back to a Data pointer
  Data *deserializedData = Serializer::deserialize(raw);

  // Print the deserialized Data object
  std::cout << "\nDeserialized Data:\n";
  std::cout << "ID: " << deserializedData->getId() << "\n";
  std::cout << "Name: " << deserializedData->getName() << "\n";
  std::cout << "Value: " << deserializedData->getValue() << "\n";

  // Verify that the original and deserialized pointers are the same
  if (&originalData == deserializedData) {
    std::cout << "\nThe original and deserialized pointers are equal.\n";
  } else {
    std::cout << "\nThe original and deserialized pointers are NOT equal.\n";
  }

  return 0;
}
