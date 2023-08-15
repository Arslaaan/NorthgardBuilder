#include "NgbConfig.h"

NgbConfig::NgbConfig(std::string path) {
    std::string line;

    std::ifstream in(path);
    if (in.is_open()) {
        std::cout << "Configuration reading" << std::endl;
        std::getline(in, line);
        version = std::stoi(line.substr(1));
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            
            std::string key;
            double value;
            iss >> key;
            iss >> value;
            
            configRawValues[key] = value;
            std::cout << key << " " << value << std::endl;
        }
        std::cout << "Configuration read completed" << std::endl;
    } else {
        std::cout << "Configuration file not found" << std::endl;
    }
    in.close();
}

double NgbConfig::getDouble(const std::string &key) {
    if (!configRawValues.count(key)) {
        std::cout << "Config key not found: " << key << std::endl;
        throw std::invalid_argument(key);
    }
    return configRawValues.at(key);
}
int NgbConfig::getInt(const std::string &key) {
    if (!configRawValues.count(key)) {
        std::cout << "Config key not found: " << key << std::endl;
        throw std::invalid_argument(key);
    }
    return static_cast<int>(configRawValues.at(key));
}