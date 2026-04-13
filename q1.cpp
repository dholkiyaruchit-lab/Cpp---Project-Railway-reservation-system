#include <iostream>
using namespace std;
#include <vector>

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

    static int trainCount;

public:
    Train()
    {
        trainNumber = 0;
        trainName = "Not set";
        source = "Not set";
        destination = "Not set";
        trainTime = "Not set";
        trainCount++;
    }
    Train(int num, string name, string sour, string desti, string time)
    {
        trainNumber = num;
        trainName = name;
        source = sour;
        destination = desti;
        trainTime = time;
        trainCount++;
    }
    Train(const Train &obj)
    {
        trainNumber = obj.trainNumber;
        trainName = obj.trainName;
        source = obj.source;
        destination = obj.destination;
        trainTime = obj.trainTime;
        trainCount++;
    }
    ~Train()
    {
        trainCount--;
    }
    void inputTrain()
    {
        cout << "Enter Train Number" << endl;
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name" << endl;
        getline(cin, trainName);

        cout << "Enter Source Name" << endl;
        getline(cin, source);

        cout << "Enter Destination Name" << endl;
        getline(cin, destination);

        cout << "Enter Train Time" << endl;
        getline(cin, trainTime);
    }
    int getTrainNumber() const
    {
        return trainNumber;
    }
    void displayTrain() const
    {
        cout << "\n Train Number   :" << trainNumber << endl;
        cout << "Train Name        :" << trainName << endl;
        cout << "Train Source      :" << source << endl;
        cout << "Train destination :" << destination << endl;
        cout << "Train Time        :" << trainTime << endl;
    }
    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    vector<Train> trains;

public:
    void addTrain()
    {
        Train t;
        t.inputTrain();
        trains.push_back(t);
        cout << "Train Add Successfully" << endl;
    }
    void displayAll()
    {
        if (trains.empty())
        {
            cout << "No train Data Found" << endl;
            return;
        }
        for (int i = 0; i < trains.size(); i++)
        {
            cout << "\n === Trains ===  " << i + 1 << endl;
            trains[i].displayTrain();
        }
        cout << "\nTotal Trains: " << Train::getTrainCount() << endl;
    }
    void searchTrain(int num)
    {
        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getTrainNumber() == num)
            {
                cout << "Train found" << endl;
                trains[i].displayTrain();
                return;
            }
        }
        cout << "Train not Found" << endl;
    }
};
int main()
{
    RailwaySystem sys;
    int choice = 0, numb;
    while (choice != 4)
    {
        cout << "\nRailway Reservation System" << endl;
        cout << "1. Add train" << endl;
        cout << "2. Display All Trains" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            sys.addTrain();
            break;
        case 2:
            sys.displayAll();
            break;
        case 3:
            cout << "Enter Train Number" << endl;
            cin >> numb;
            sys.searchTrain(numb);
            break;
        case 4:
            cout << "Exiting....." << endl;
            break;
        default:
            cout << "invalid input" << endl;
            break;
        }
    }
    return 0;
}