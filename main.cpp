#include "app.hpp"

int main() {
    App app;

    while (true) {
        app.run();
        app.showMainMenu();
    }
}