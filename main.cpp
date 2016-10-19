#include "filecreator.h"
#include "inputargreader.h"
#include <string>
#include <functional>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Filecreator creator{1, "Logout.log"};
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


    while(count != 0)
    {
        std::cout << "Count : " << count << std::endl;
        count--;
        std::cout << "Please enter a filename " ;
        std::cin >> file;
        std::cout << std::endl;
        std::cout.flush();
        std::thread thr{&Filecreator::create, &creator, std::ref(file)};
        thr.detach();

    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    creator.read();
    std::cout << "Main terminated "<< std::endl;
    return 0;
} //

