#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

// Abstract base class: defines what every notification must do.
class Notification {
private:
    // Encapsulation: other code cannot modify this directly.
    std::string recipient;

public:
    // Constructor: initialises and validates the object.
    explicit Notification(const std::string& recipientName)
        : recipient(recipientName) {
        if (recipient.empty()) {
            throw std::invalid_argument("Recipient cannot be empty.");
        }
    }

    // Necessary when deleting derived objects through base pointers.
    virtual ~Notification() = default;

    // const means this function does not modify the object.
    const std::string& getRecipient() const {
        return recipient;
    }

    // Pure virtual function: derived classes must implement this.
    virtual void send(const std::string& message) const = 0;
};

// Inheritance: EmailNotification is a type of Notification.
class EmailNotification : public Notification {
public:
    explicit EmailNotification(const std::string& recipient)
        : Notification(recipient) {}

    // override lets the compiler check that we override correctly.
    void send(const std::string& message) const override {
        std::cout << "[Email] To " << getRecipient()
                  << ": " << message << '\n';
    }
};

// Another implementation of the same interface.
class SmsNotification : public Notification {
public:
    explicit SmsNotification(const std::string& recipient)
        : Notification(recipient) {}

    void send(const std::string& message) const override {
        std::cout << "[SMS] To " << getRecipient()
                  << ": " << message << '\n';
    }
};

// Composition: the service owns a collection of notifications.
class NotificationService {
private:
    std::vector<std::unique_ptr<Notification>> notifications;

public:
    void add(std::unique_ptr<Notification> notification) {
        if (!notification) {
            throw std::invalid_argument("Notification cannot be null.");
        }

        // Transfer ownership into the vector.
        notifications.push_back(std::move(notification));
    }

    void sendAll(const std::string& message) const {
        if (message.empty()) {
            throw std::invalid_argument("Message cannot be empty.");
        }

        // Range-based loop: process each stored notification.
        for (const auto& notification : notifications) {
            // Polymorphism: calls the appropriate send() implementation.
            notification->send(message);
        }
    }
};

int main() {
    try {
        NotificationService service;

        service.add(
            std::make_unique<EmailNotification>("john@example.com")
        );

        service.add(
            std::make_unique<SmsNotification>("0123456789")
        );

        service.sendAll("Your account has been created.");
    }
    catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1; // Non-zero exit code indicates failure.
    }

    return 0; // Zero indicates success.
}