//Vehicle Parking management system using heirarchical inheritance
#include <iostream>
using namespace std;

const int MaxSlots = 20;

// Base class Vehicle------------------------------------------------------------------------
class Vehicle {
   public:
      int vehicleID;
      string vehicleType;

      Vehicle(int id, string type) : vehicleID(id), vehicleType(type) {} // Constructor

      void park() {
          cout << vehicleType << " " << vehicleID << " parked." << endl;
      }

      void unpark() {
          cout << vehicleType << " " << vehicleID << " unparked." << endl;
      }

      void display() {
          cout << vehicleType << " " << vehicleID << endl;
      }
};

// Derived classes-------------------------------------------------------------------
class Car : public Vehicle {
   public:
      Car(int id) : Vehicle(id, "Car") {}//contructor
};

class Truck : public Vehicle {
    public:
       Truck(int id) : Vehicle(id, "Truck") {}//contructor
};

class Motorcycle : public Vehicle {
    public:
       Motorcycle(int id) : Vehicle(id, "Motorcycle") {}//contructor
};

// ParkingLot class to manage parking and unparking----------------------------------------------
class ParkingLot {
    Vehicle* slots[MaxSlots];

    public:
       ParkingLot() {
           for (int i = 0; i < MaxSlots; i++) {
               slots[i] = NULL;
            }
        }

       void park(Vehicle* vehicle);
       void unpark(Vehicle* vehicle);
       Vehicle* findVehicleById(int id);
       void showAllParkedVehicles();
};

void ParkingLot::park(Vehicle* vehicle) {
    // Check if the vehicle is already parked
    if (findVehicleById(vehicle->vehicleID)) {
        cout << "Vehicle with ID " << vehicle->vehicleID << " is already parked!" << endl;
        return;
    }

    for (int i = 0; i < MaxSlots; i++) {
        if (slots[i] == NULL) {
            slots[i] = vehicle;
            vehicle->park();
            return;
        }
    }
    cout << "Parking lot is full! Could not park " << vehicle->vehicleType << " with ID " << vehicle->vehicleID << endl;
}

void ParkingLot::unpark(Vehicle* vehicle) {
    for (int i = 0; i < MaxSlots; i++) {
        if (slots[i] == vehicle) {
            slots[i] = NULL;
            vehicle->unpark();
            delete vehicle; // Free memory when vehicle is unparked
            return;
        }
    }
    cout << "Vehicle not found in the parking lot!" << endl;
}

Vehicle* ParkingLot::findVehicleById(int id) {
    for (int i = 0; i < MaxSlots; i++) {
        if (slots[i] && slots[i]->vehicleID == id) {
            return slots[i];
        }
    }
    return NULL;
}

void ParkingLot::showAllParkedVehicles() {
    bool isEmpty = true;
    cout << "\n--- All Parked Vehicles ---" << endl;
    for (int i = 0; i < MaxSlots; i++) {
        if (slots[i] != NULL) {
            slots[i]->display();
            isEmpty = false;
        }
    }
    if (isEmpty) {
        cout << "No vehicles parked." << endl;
    }
}


int main() {
    ParkingLot lot;
    int choice;
    int id;
    Vehicle* vehicle = NULL;

    do {
        cout << "\n--- Vehicle Parking Management System ---" << endl;
        cout << "1. Park a Car" << endl;
        cout << "2. Park a Truck" << endl;
        cout << "3. Park a Motorcycle" << endl;
        cout << "4. Unpark a Vehicle" << endl;
        cout << "5. Show All Parked Vehicles" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;  // This line is important to capture the user's choice

        switch(choice) {
            case 1:
                cout << "Enter Car ID: ";
                cin >> id;
                vehicle = new Car(id);
                lot.park(vehicle);
                break;
            case 2:
                cout << "Enter Truck ID: ";
                cin >> id;
                vehicle = new Truck(id);
                lot.park(vehicle);
                break;
            case 3:
                cout << "Enter Motorcycle ID: ";
                cin >> id;
                vehicle = new Motorcycle(id);
                lot.park(vehicle);
                break;
            case 4:
                cout << "Enter Vehicle ID to unpark: ";
                cin >> id;
                vehicle = lot.findVehicleById(id);
                if (vehicle) {
                    lot.unpark(vehicle);
                } else {
                    cout << "Vehicle with ID " << id << " not found!" << endl;
                }
                break;
            case 5:
                lot.showAllParkedVehicles();  // Call the new function to show parked vehicles
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
