#include "Console.h"
#include "Menu.h"

#include <iostream>

namespace menu {

QString Console::DEFAULT_TASK_ID_GENERATOR_CLASS_NAME("uniq::TimeQStringValue");

Console::Console() : _menu(new Menu(this)),
    _taskIdGenerator(nullptr),
    _uniqValueClassName(DEFAULT_TASK_ID_GENERATOR_CLASS_NAME)
{
#ifdef Q_OS_WIN
    m_notifier = new QWinEventNotifier(GetStdHandle(STD_INPUT_HANDLE));
    connect(m_notifier, &QWinEventNotifier::activated
#else
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    connect(m_notifier, &QSocketNotifier::activated
#endif
            , this, &Console::readCommand);

    registerUniqValue();
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
    } else {
        std::cout << "Echo: " << line << std::endl;
        std::cout << "> " << std::flush;
    }
}

uniq::Value<QString> *Console::taskIdGenerator() const
{
    if (_taskIdGenerator == nullptr) {
        _taskIdGenerator = createTaskIdGenerator();
    }

    return _taskIdGenerator;
}

QString Console::uniqValueClassName() const
{
    return _uniqValueClassName;
}

void Console::setUniqValueClassName(const QString &uniqValueClassName)
{
    _uniqValueClassName = uniqValueClassName;
}

void Console::registerUniqValue() const
{
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::UuidValue)
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::CompactUuidValue)
    REGISTER_CLASS_FOR_UTIL_FACTORY(uniq::Value<QString>, uniq::TimeQStringValue)
}

uniq::Value<QString> *Console::createTaskIdGenerator() const
{
    return util::Factory<uniq::Value<QString>>::create(_uniqValueClassName.toStdString());
}

//_taskIdGenerator =




} // namespace menu
