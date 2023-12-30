#pragma once
#include <iostream>
#include <string>
#include <vector>

class Colleague;

class Mediator {
public:
    virtual void receiveMessage(Colleague* sender, const std::string& message) = 0;
    virtual void sendMessage(std::string receiver, const std::string& message) = 0;
    virtual void addColleague(Colleague* colleague) = 0;
    virtual std::string getName() = 0;
};

class Colleague {
public:
    Colleague(Mediator* mediator, const std::string& name) : mediator(mediator), name(name) {}

    virtual void sendMessage(const std::string& message) = 0;
    virtual void receiveMessage(const std::string& message) = 0;
    virtual std::string getName() = 0;

protected:
    Mediator* mediator;
    std::string name;
};

class ConcreteMediator : public Mediator {
public:
    ConcreteMediator(const std::string& name) : name(name) {}

    void receiveMessage(Colleague* sender, const std::string& message) override {
        std::cout << name << " receives message from " << sender->getName() << ": " << message << std::endl;
    }

    void sendMessage(std::string receiver, const std::string& message) override {
        std::cout << name << " sends message: " << message << std::endl;
        for (Colleague* colleague : colleagues) {
            if (colleague->getName() == receiver)
                colleague->receiveMessage(message);
        }
    }

    void addColleague(Colleague* colleague) override {
        colleagues.push_back(colleague);
    }

    std::string getName() override {
        return this->name;
    }

private:
    std::vector<Colleague*> colleagues;
    std::string name;
};



class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* mediator, const std::string& name) : Colleague(mediator, name) {}

    void sendMessage(const std::string& message) override {
        std::cout << name << " sends message: " << message << std::endl;
        mediator->receiveMessage(this, message);
    }

    void receiveMessage(const std::string& message) override {
        std::cout << name << " receives message from " << mediator->getName() << ": " << message << std::endl;
        sendMessage(name + " is available.");
    }

    std::string getName() override {
        return this->name;
    }
};