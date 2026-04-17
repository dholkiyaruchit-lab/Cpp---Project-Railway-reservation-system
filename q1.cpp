#include <iostream>
#include <vector>
using namespace std;

class Train {
public:
    int number;
    string name;
    string source;
    string destination;
    string time;
};

int main() {
    vector<Train> trains;
    int choice;

    while (cin >> choice) {
        if (choice == 1) {
            Train t;
            cin >> t.number >> t.name >> t.source >> t.destination >> t.time;
            trains.push_back(t);

            cout << "Train Added Successfully" << endl;
        }
        else if (choice == 2) {
            cout << "=== Trains === " << trains.size() << endl;

            for (int i = 0; i < trains.size(); i++) {
                cout << "Train Number: " << trains[i].number << endl;
                cout << "Train Name: " << trains[i].name << endl;
                cout << "Train Source: " << trains[i].source << endl;
                cout << "Train Destination: " << trains[i].destination << endl;
                cout << "Train Time: " << trains[i].time << endl;
            }
        }
        else if (choice == 3) {
            int searchNum;
            cin >> searchNum;

            bool found = false;

            for (int i = 0; i < trains.size(); i++) {
                if (trains[i].number == searchNum) {
                    cout << "Train Found" << endl;
                    cout << "Train Number: " << trains[i].number << endl;
                    cout << "Train Name: " << trains[i].name << endl;
                    cout << "Train Source: " << trains[i].source << endl;
                    cout << "Train Destination: " << trains[i].destination << endl;
                    cout << "Train Time: " << trains[i].time << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Train Not Found" << endl;
            }
        }
        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
