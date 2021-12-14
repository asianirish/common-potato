#include "Console.h"

#include "LineCommandTranslator.h"
#include "JsonCommandTranslator.h"

#include <uniq/UuidValue.h>
#include <uniq/CompactUuidValue.h>
#include <uniq/TimeQStringValue.h>

#include <util/Factory.h>

#include <iostream>
#include <QTextStream>

namespace menu {


Console::Console(const ThisAppClassRegistry *registry, QObject *parent) : QObject(parent),
    _menu(new Menu(this))
{
    registry->registerAllClasses();

    qRegisterMetaType<menu::Result>();
    qRegisterMetaType<menu::Error>();

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

    connect(_menu, &Menu::ready, this, &Console::onReady);
    connect(_menu, &Menu::error, this, &Console::onError);
}

Console::~Console()
{
    std::cout << "destruct Console\n";

}

void Console::run()
{
    std::cout << "Console menu:" << std::endl;
//    std::cout << "> " << std::flush;

    showMenu();
}

void Console::readCommand()
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof() || line == "quit" || line.empty()) { //TODO: just eof doesn't work to quit on Enter. Why?
        std::cout << "Good bye!" << std::endl;

        delete m_notifier;

        emit quit();
    } else if(line == "menu") {
        showMenu();
    } else if (line == "uniq") {
        std::cout << "Unique value: " << Menu::newTaskId().toStdString() << std::endl;
        std::cout << "> " << std::flush;
    } else {
        _menu->exec(QString(line.data()));
    }
}

void Console::onReady(const QVariant &result)
{
    std::cout << result.toString().toStdString() << std::endl;
    std::cout << "> " << std::flush;
}

void Console::onError(const menu::Error &err)
{
    std::cout << "Error: " << err.description().toStdString() << std::endl; //TODO: use error context
    auto keys = err.context().keys();
    for (auto &key : keys) {
        std::cout << key.toStdString() << ": " << err.context().value(key).toString().toStdString() << std::endl;
    }
    std::cout << "> " << std::flush;
}

void Console::addMenuItem(const QString &command, ActionPtr action)
{
    _menu->addItem(command, action);
}

void Console::showMenu() const
{
    auto itemKeys = _menu->itemKeys();

    for (auto &key : itemKeys) {
        std::cout << key.toStdString() << std::endl;
    }

    std::cout << "menu" << std::endl;
    std::cout << "quit" << std::endl;
//TODO:     std::cout << "quit" << std::endl;

    std::cout << "> " << std::flush;
}

int Console::readInt()
{
    QTextStream qtin(stdin);
    QString line = qtin.readLine();
    return line.toInt();
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
    REGISTER_CLASS_FOR_UTIL_FACTORY(menu::CommandTranslator, menu::JsonCommandTranslator)
}


//_taskIdGenerator =




} // namespace menu
