#include <iostream>
#include <vector>
#include <algorithm>

// Forward declaration of Subscriber interface
class Subscriber;

// Publisher class
class Publisher {
public:
    // Attach a subscriber
    void attach(Subscriber* subscriber) {
        subscribers.push_back(subscriber);
    }

    // Detach a subscriber
    void detach(Subscriber* subscriber) {
        subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
    }
    
    // Publish a message
    void publish(const std::string& message);

private:
    std::vector<Subscriber*> subscribers;
};

// Subscriber interface
class Subscriber {
public:
    virtual void receiveMessage(const std::string& message) = 0;
};

// Concrete Subscriber class
class ConcreteSubscriber : public Subscriber {
public:
    ConcreteSubscriber(int id) : id(id) {}

    // Receive message method
    void receiveMessage(const std::string& message) override {
        std::cout << "Subscriber " << id << " received message: " << message << std::endl;
    }

private:
    int id;
};

// Publish a message
void Publisher::publish(const std::string& message) {
    for (Subscriber* subscriber : subscribers) {
        subscriber->receiveMessage(message);
    }
}
    
int main() {
    Publisher publisher;
    ConcreteSubscriber subscriber1(1);
    ConcreteSubscriber subscriber2(2);

    // Attach subscribers to the publisher
    publisher.attach(&subscriber1);
    publisher.attach(&subscriber2);

    // Publish a message
    publisher.publish("Hello, world!");

    // Detach a subscriber
    publisher.detach(&subscriber1);

    // Publish another message
    publisher.publish("Goodbye!");

    return 0;
}
/* Output:

Subscriber 1 received message: Hello, world!
Subscriber 2 received message: Hello, world!
Subscriber 2 received message: Goodbye!

*/

