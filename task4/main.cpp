#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label firstName_label;
  Gtk::Entry firstName;
  Gtk::Label lastName_label;
  Gtk::Entry lastName;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
    set_title("Task 4");

    firstName_label.set_label("First name");
    lastName_label.set_label("Last name");
    button.set_label("Combine names");
    button.set_sensitive(false);

    vbox.pack_start(firstName_label);  //Add the widget entry to vbox
    vbox.pack_start(firstName);  //Add the widget entry to vbox
    vbox.pack_start(lastName_label);  //Add the widget entry to vbox
    vbox.pack_start(lastName);  //Add the widget entry to vbox
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(label);  //Add the widget label to vbox

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets

    button.signal_clicked().connect([this]() {
      label.set_text("Names combined: " + firstName.get_text() + " " + lastName.get_text());
    });

    firstName.signal_changed().connect([this]() {
      button.set_sensitive(firstName.get_text() != "" && lastName.get_text() != "");
    });

    lastName.signal_changed().connect([this]() {
      button.set_sensitive(firstName.get_text() != "" && lastName.get_text() != "");
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}

