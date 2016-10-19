#ifndef FILECREATOR_H
#define FILECREATOR_H

#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>
#include <fstream>
#include <vector>
#include <iostream>

class Filecreator
{
public:
    Filecreator() = delete;
    Filecreator(int taskNumber, const std::string &configFile);
    ~Filecreator();
    void read();
    void write(const std::string &str);
    void create(const std::string &filename);



private:
    int taskNumber;
    std::string config_filename;
    std::ofstream file;
    std::ifstream input;
    std::ofstream output;
    std::mutex file_lock_mux;
    std::mutex config_mux;
    std::mutex create_mux;
};

#endif // FILECREATOR_H
