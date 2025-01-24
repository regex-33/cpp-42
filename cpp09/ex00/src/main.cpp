#include "../Includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
  (void)argv;
  std::string line;
  Btc data;
  if (argc != 2)
    return (std::cerr << "Error: could not open file." << std::endl, 1);
  data.processFileAndStoreInMap(DB_PATH, ',');
  data.processFileAndStoreInMap(argv[1], '|');
  // std::cout << "argv[1] :: " << argv[1] << std::endl;

  // data.PrintMap();
  // Output the map contents

  return 0;
}
