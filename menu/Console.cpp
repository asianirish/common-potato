#include "Console.h"

#include "LineCommandTranslator.h"

#include <uniq/UuidValue.h>
#include <uniq/CompactUuidValue.h>
#include <uniq/TimeQStringValue.h>

#include <util/Factory.h>

#include <iostream>

namespace menu {


Console::Console() : Console(Menu::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME, Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME)
{

}

Console::Console(const QString &taskIdGenClassName) : Console(taskIdGenClassName,
                                                              Menu::DEFAULT_COMMAND_TRANSLATOR_CLASS_NAME)
{

}

Console::Console(const QString &taskIdGenClassName, const QString &commandTranslatorClassName) :
    _menu(new Menu(taskIdGenClassName, commandTranslatorClassName, this))
{
#ifdef Q_OS_WIN
    m_notifier = new QWinEventNotifier(GetStdHandle(STD_INPUT_HANDLE));
    connect(m_notifier, &QWinEventNotifier::activated
#else
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    connect(m_notifier, &QSocketNotifier::activated
#endif
            , this, &Console::readCommand);

    registerUniqValueClasses();
    registerCommandTranslatorClasses();
}

Console::~Console()
{
    std::cout << "destruct Console\n";

}

void Console::run()
{
    std::cout << "First message" << std::endl;
    std::cout << "> " << std::flush;
}

void Console::readCommand()
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof() || line == "quit") {
        std::cout << "Good bye!" << std::endl;

        delete m_notifier;

        emit quit();
    } else if (line == "uniq") {
        std::cout << "Unique value: " << _menu->newTaskId().toStdString() << std::endl;
        std::cout << "> " << std::flush;
    } else {
        std::cout << "Echo: " << line << std::endl;
        std::cout << "> " << std::flush;
    }
}

void Console::addMenuItem(const QString &command, ActionPtr action)
{
    _menu->addItem(command, action);
}



void Console::registerUniqValueClasses() const
{
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::UuidValue)
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::CompactUuidValue)
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::TimeQStringValue)
}

void Console::registerCommandTranslatorClasses() const
{
    REGISTER_CLASS_FOR_UTIL_FACTORY(menu::CommandTranslator, menu::LineCommandTranslator)
}


//_taskIdGenerator =




} // namespace menu
