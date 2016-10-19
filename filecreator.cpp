#include "filecreator.h"

Filecreator::Filecreator(int taskNumber, const std::string &configFile)
{
    this->taskNumber = taskNumber;
    this->config_filename = configFile;
}


Filecreator::~Filecreator()
{
    if(file.is_open())
        file.close();
    if(input.is_open())
        input.close();
    if(output.is_open())
        output.close();

}


void Filecreator::read()
{
    std::lock_guard<std::mutex> lock(config_mux);
    input.open(config_filename);
    if(input.is_open())
    {
        std::cout << "Reading file content ... done ! "  << std::endl;
        std::cout << input.rdbuf()<< std::endl;
        input.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }
    else
    {
        std::cout << __FUNCTION__ << ": Error on reading. "
                  << config_filename << " is not opened"
                  << std::endl;
    }
}

void Filecreator::write(const std::string &str)
{
    std::lock_guard<std::mutex> lock(config_mux);
    output.open(config_filename, std::ios::out|std::ios::app);
    if(output.is_open())
    {
       output << str << std::endl;
       output.close();
       std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    else
    {
        std::cout << __FUNCTION__ << ": Error on writing. "
                  << config_filename << " is not opened"
                  << std::endl;
    }
}

void Filecreator::create(const std::string &filename)
{
    std::lock_guard<std::mutex> lock(create_mux);
    file.open(filename);

    if(file.is_open())
    {
       file << "File created by Thread "
            << std::this_thread::get_id()
            << std::endl;
       file.close();
       write(filename);
       std::cout << "File " << filename << " created" << std::endl;
    }
    else
    {
        std::cout << __FUNCTION__
                  << ": Error on creating. "
                  << filename << " is not opened"
                  << std::endl;
    }
}
