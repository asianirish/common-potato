#include <iostream>
#include "Console.h"

inline Console::Console()
{
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
}

void Console::run()
{
    std::cout << "First message" << std::endl;
    std::cout << "> " << std::flush;
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
}

void Console::readCommand()
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof() || line == "quit") {
        std::cout << "Good bye!" << std::endl;
        emit quit();
    } else {
        std::cout << "Echo: " << line << std::endl;
        std::cout << "> " << std::flush;
    }
}
