#include "filecreator.h"
#include "inputargreader.h"
#include "utils.h"
#include <string>
#include <functional>
#include <iostream>

//using namespace std;

int main(int argc, char *argv[])
{
    //Filecreator creator{1, "Logout.log"};
    bool continue_running = true;
    Utils::Queue<std::string> queue;
    Producer<std::string> producer;
    Consumer<std::string> consumer(&continue_running);
    int count = 0;
    std::string file;
    auto args = Tools::input_arg_reader<1>(argc, argv);
    try
    {
        count = std::stoi(args.at(1));
    }
    catch(std::invalid_argument &e)
    {
        std::cout << "Error: " << std::endl;
        std::cout << "Invalid argument ..., please enter a number" <<std::endl;
        exit(EXIT_FAILURE);
    }
    std::thread consumer_thread{consumer, std::ref(queue)};

    while(count != 0)
    {
        std::cout << "Count : " << count << std::endl;
        count--;
        std::cout << "Please enter a filename " ;
        std::cin >> file;
        std::cout << std::endl;
        std::cout.flush();
        std::thread thr{producer, std::ref(queue), std::ref(file)};
        thr.detach();

    }
    continue_running = false;
    consumer_thread.join();
    std::cout << "Main terminated "<< std::endl;
    return 0;
} //

