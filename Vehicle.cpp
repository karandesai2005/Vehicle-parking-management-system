//Using heirarchical inheritance to make a parking system. 
#include <iostream>
using namespace std;

const int MaxSlots = 20;
//class vehicle ------------------------------
class Vehicle {
   public:
      int vehicleID;
      string vehicleType;

      Vehicle(int id, string type) : vehicleID(id), vehicleType(type) {} //constructor 

      void park(){
          cout << vehicleType << " " << vehicleID << " parked." << endl;
       }

      void unpark() {
        cout << vehicleType << " " << vehicleID << " unparked." << endl;
      }
};

// Derived class car inherited from vheicle ----------------------
class Car : public Vehicle{
   public:
      Car(int id) : Vehicle(id, "Car") {} //constructor
};

//Derived class truck inherited from vehicle ---------------------------------
class Truck : public Vehicle {
    public:
       Truck(int id) : Vehicle(id, "Truck") {}
};

//derived class motorcycle inherited from vehicle--------
class Motorcycle : public Vehicle {
    public:
       Motorcycle(int id) : Vehicle(id, "Motorcycle") {}
};

// class parking lot-------------------------------------
class ParkingLot {
    Vehicle* slots[MaxSlots]; // array of pointers to parking slots

    public:
       ParkingLot() {  //default constructor to initialize all slots as empty
           for (int i = 0; i < MaxSlots; i++) {
               slots[i] = NULL;  
            }
        }
        // methods
       void park(Vehicle* vehicle); 
       void unpark(Vehicle* vehicle); 
};

void ParkingLot :: park(Vehicle* vehicle){
    for (int i = 0; i < MaxSlots; i++) {
        if (slots[i] == NULL) { // Find an empty slot
            slots[i] = vehicle;
            vehicle->park();
            return;
        }
    }
    cout << "Parking lot is full!!!" << endl;
}
void ParkingLot :: unpark(Vehicle* vehicle){
    for (int i = 0; i < 10; ++i) {
        if (slots[i] == vehicle) {
            slots[i] = NULL;
            vehicle->unpark();
            return;
        }
    }
    cout << "Vehicle moved out of the parking lot!" << endl;
} 
int main() {
    ParkingLot lot;

    Car car1(1);
    Truck truck1(2);
    Motorcycle bike1(3);

    lot.park(&car1);
    lot.unpark(&car1);

    lot.park(&truck1);
    lot.unpark(&truck1);

    lot.park(&bike1);
    lot.unpark(&bike1);

    return 0;
}
