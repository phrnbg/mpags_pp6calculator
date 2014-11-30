#include "PP6Day1.hpp"
#include "PP6Day2.hpp"
#include "PP6Day3.hpp"
#include "PP6Day4.hpp"

#include <iostream>
#include <limits>

int main() {
    char day_op('\0');
    
    while(true){
       // Ask for the day
       std::cout << "Enter the operation you would like to perform:" << std::endl;
       std::cout << "1) 1st day" << std::endl;
       std::cout << "2) 2nd day" << std::endl;
       std::cout << "3) 3rd day" << std::endl;
       std::cout << "4) 4th day" << std::endl;
       //std::cout << "5) 5th day" << std::endl;
       std::cout << "q) Quit" << std::endl;
       std::cout << ">> ";
       std::cin >> day_op;
    if(!std::cin){
       std::cerr << "[error] Error in input" << std::endl;
       // clear the buffer
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       continue;
    }
    if (day_op == 'q'){
       break;
    }
    else if(day_op == '1'){
       do_day1();
    }

    else if(day_op == '2'){  
       do_day2();
    }

    else if(day_op == '3'){  
       do_day3();
    }
    else if(day_op == '4'){  
       do_day4();
    }
    else{
        std::cerr << "[error] Operation '" << day_op << "' not recognised." << std::endl;
        continue;
    }
    }
    return 0;
}
