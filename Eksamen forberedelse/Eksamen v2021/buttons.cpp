#include <cmath>
#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

class Button {
public:
    std::string description;
    function<void()> func;

    Button(std::string description, function<void()> func) : description(std::move(description)), func(std::move(func)) {}
    virtual ~Button() {}

    virtual void activate() {
        if (func) {
            func();
        }
    }

    friend ostream &operator<<(ostream &stream, const Button button) {
        return stream << button.string();
    }

    virtual std::string string() const = 0;

};

class ToggleButton : Button {
public:

    bool toggled;

    ToggleButton(std::string description, bool toggled, function<void()> func): Button(std::move(description), std::move(func)), toggled(toggled) {}

    std::string string() const override {
        return "ToggleButton, label: " + description + ", value: " + check_toggled();
    }

    std::string check_toggled() const {
        if (toggled) {
            return "toggled";
        } else {
            return "not toggled";
        }
    }

    void activate() override {
        toggled = !toggled;
        Button::activate();
    }
};

class LinkButton : Button {
public:

    std::string link;

    LinkButton(std::string description, const std::string &link, function<void()> func) :  Button(std::move(description), std::move(func)), link(link) {}

    std::string string() const override {
        return "LinkButton, label: " + description + ", link: " + link;
    }

    void activate() override {
        Button::activate();
    }
};

int main() {
    std::vector<std::unique_ptr<Button>> buttons;
    buttons.emplace_back(make_unique<ToggleButton>("Toggle
    something", true, [] {
        cout << "Toggled something" << endl;
    }));
    buttons.emplace_back(std::make_unique<LinkButton>("Link to somewhere",
    "https://ntnu.no", [] {
        cout << "Opened link" << endl;
    }));
    for (auto &button : buttons) {
        cout << *button << endl;
        button->activate();
        cout << *button << endl;
    }

}