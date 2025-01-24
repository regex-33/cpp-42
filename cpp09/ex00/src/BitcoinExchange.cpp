#include "../Includes/BitcoinExchange.hpp"
#include <climits>
#include <string>

bool isValidDate(const std::string &date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  int year, month, day;
  char dash1, dash2;
  std::istringstream ss(date);

  if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' ||
      dash2 != '-')
    return false;

  // Validate ranges
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  static const int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};
  if (month == 2) { // Check for leap year in February
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    return day <= (isLeap ? 29 : 28);
  }
  return day <= daysInMonth[month - 1];
}

void Btc::FindClosest(const std::string date, const float value) {
  std::map<std::string, float>::iterator it;
  it = this->dataMap.lower_bound(date);

  if (it == this->dataMap.end()) {
    --it; // Last key in the map
  } else if (it == this->dataMap.begin() && it->first != date) {
    std::cerr << "No lower key exists for date: " << date << std::endl;
    return;
  } else if (it->first != date) {
    --it; // Move to the previous key
  }

  std::cout << date << " => " << value << " = " << value * (it->second)
            << std::endl;
}

void Btc::processFileAndStoreInMap(const std::string &filename,
                                   const char &del) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::size_t separatorPos = line.find(del);
    if (separatorPos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string date = line.substr(0, separatorPos);
    std::string value = line.substr(separatorPos + 1);
    if (value.find(del) != std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    if (!date.empty()) { // Trim spaces
      date.erase(0, date.find_first_not_of(" \t"));
      date.erase(date.find_last_not_of(" \t") + 1);
      value.erase(0, value.find_first_not_of(" \t"));
      value.erase(value.find_last_not_of(" \t") + 1);
    }

    float num;
    std::stringstream ss(value);
    ss >> num;
    if (ss.fail()) {
      std::cerr << "Conversion failed!" << std::endl;
    }

    if (!isValidDate(date)) {
      std::cerr << "Invalid date: " << date << std::endl;
      continue;
    }

    if (del == '|') {
      // if (num < 0 || num > 1000) {
      //   if (num >= static_cast<float>(INT_MAX) ||
      //       num <= static_cast<float>(INT_MIN)) {
      //     std::cerr << "Error: too large a number." << std::endl;
      //   } else {
      //     std::cerr << "Error: not a positive number" << std::endl;
      //   }
      //   continue;
      // }

      if (num < 0 || num > 1000) {
        std::cerr << (num >= static_cast<float>(INT_MAX) ||
                              num <= static_cast<float>(INT_MIN)
                          ? "Error: too large a number."
                          : "Error: not a positive number")
                  << std::endl;
        continue;
      }
      this->FindClosest(date, num);
    } else {
      this->addToMap(date, num);
    }
  }
  file.close();
}
