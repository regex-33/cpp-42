#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define DB_PATH "./Files/data.csv"

#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class Btc {
private:
  std::map<std::string, float> dataMap;

public:
  Btc() {}
  ~Btc() {}

  Btc(const Btc &other) { *this = other; }

  Btc &operator=(const Btc &other) {
    (void)other;
    return *this;
  }
  void processFileAndStoreInMap(const std::string &filename, const char &del);
  // void FindClosest(const std::string date, const float value);
  void FindClosest(const std::string date, const float value);

  void addToMap(const std::string &date, const float &value) {
    this->dataMap[date] = value;
  }

  void PrintMap() {
    std::cout << "Contents of the map:" << std::endl;
    for (std::map<std::string, float>::iterator it = dataMap.begin();
         it != dataMap.end(); ++it) {
      std::cout << "Date: " << it->first << ", Value: " << it->second
                << std::endl;
    }
  }
};

#endif // !BitcoinExchange
