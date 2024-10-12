#include <iostream>

using namespace std;

class Receiver
{
public:
    void action() { cout << "ִ������" << endl; }
};

class Command
{
public:
    Command(const Receiver& receiver): receiver(receiver) {}
    virtual void excuteCommand() = 0;
    virtual ~Command() = default;
protected:
    Receiver receiver;
};

class ConcreteCommand: public Command
{
public:
    ConcreteCommand(const Receiver& receiver): Command(receiver) {}
    void excuteCommand() override { receiver.action(); }
};

class Invoker
{
public:
    Invoker(): command(nullptr) {}
    ~Invoker() { command = nullptr; }
    void setCommand(Command* command)  { this->command = command; }
    void excuteCommand() { command->excuteCommand(); }
private:
    Command* command;
};

int main()
{
    Receiver receiver;
    ConcreteCommand command(receiver);
    Invoker invoker;
    
    invoker.setCommand(&command);
    invoker.excuteCommand();

    return 0;
}