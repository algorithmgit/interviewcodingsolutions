#include <iostream>
#include <vector>
#include <algorithm>

// Forward declaration of Observer interface
class Observer;

// Notifier class
class Notifier {
public:
    // Attach an observer
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    // Detach an observer
    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notify all observers
    void notify();

private:
    std::vector<Observer*> observers;
};

// Observer interface
class Observer {
public:
    virtual void update() = 0;
};

// Concrete Observer class
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(int id) : id(id) {}

    // Update method
    void update() override {
        std::cout << "Observer " << id << " has been notified!" << std::endl;
    }

private:
    int id;
};

// Notify method definition
void Notifier::notify() {
    for (Observer* observer : observers) {
        observer->update();
    }
}

int main() {
    Notifier notifier;
    ConcreteObserver observer1(1);
    ConcreteObserver observer2(2);

    // Attach observers to the notifier
    notifier.attach(&observer1);
    notifier.attach(&observer2);

    // Notify all observers
    notifier.notify();

    // Detach an observer
    notifier.detach(&observer1);

    // Notify remaining observers
    notifier.notify();

    return 0;
}
/* Output:

Observer 1 has been notified!
Observer 2 has been notified!
Observer 2 has been notified!

*/
