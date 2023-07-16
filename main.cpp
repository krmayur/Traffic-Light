#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

enum class SignalState {
    Red,
    Yellow,
    Green
};

void printSignalState(SignalState state) {
    switch (state) {
    case SignalState::Red:
        cout << "Red" << endl;
        break;
    case SignalState::Yellow:
        cout << "Yellow" << endl;
        break;
    case SignalState::Green:
        cout << "Green" << endl;
        break;
    }
}

int main() {
    int redDuration = 5; // seconds
    int yellowDuration = 2; // seconds
    int greenDuration = 5; // seconds

    SignalState currentState = SignalState::Red;

    while (true) {
        printSignalState(currentState);

        switch (currentState) {
        case SignalState::Red:
            this_thread::sleep_for(chrono::seconds(redDuration));
            currentState = SignalState::Green;
            break;
        case SignalState::Yellow:
            this_thread::sleep_for(chrono::seconds(yellowDuration));
            currentState = SignalState::Red;
            break;
        case SignalState::Green:
            this_thread::sleep_for(chrono::seconds(greenDuration));
            currentState = SignalState::Yellow;
            break;
        }
    }

    return 0;
}