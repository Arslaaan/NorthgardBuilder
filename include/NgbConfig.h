#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
// Some patches of game can change constants, so they incapsulated here
class NgbConfig {
   private:
    // NgbConfig() {} delete ?
    NgbConfig(std::string path);
    NgbConfig(const NgbConfig&);
    NgbConfig& operator=(NgbConfig&) = delete;

    std::string path;
    std::map<std::string, double> configRawValues;
    int version;

   public:
    static NgbConfig& getInstance() {
        static NgbConfig instance("ngb.config");
        return instance;
    }
    double getDouble(const std::string& key);
    int getInt(const std::string& key);
};