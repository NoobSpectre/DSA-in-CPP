#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Vehicle {
    string _type;
    int _reg_no;
    public:
    Vehicle(string _type, int _reg_no)
        : _type{_type}, _reg_no{_reg_no} {}
    string type() {
        return _type;
    }
};

class Parking_lot {
    queue<bool> carlane;
    queue<bool> sctrlane;
    int _lsize, _num_lanes;
    public:
    Parking_lot()
    : _lsize{10}, _num_lanes{2} {}
    void park_vehicle(Vehicle);
    void depart_vehicle(string);
    void availableSlot(string);
};

void Parking_lot::park_vehicle(Vehicle v) {
    if(v.type() == "car") {
        if(carlane.size() == _lsize*_num_lanes) {
            cout << "All car parking lanes are full !!!" << endl;
        }
        else {
            carlane.push(1);
        }
    }
    else if(v.type() == "scooter") {
        if(sctrlane.size() == _lsize*_num_lanes) {
            cout << "All scooter parking lanes are full !!!" << endl;
        }
        else {
            sctrlane.push(1);
        }
    }
}

void Parking_lot::depart_vehicle(string _section) {
    if(_section == "car") {
        if(carlane.empty()) {
            cout << "There is no car in the parking lot of the car section !!!" << endl;
        }
        else {
            carlane.pop();
        }
    }
    else if(_section == "scooter") {
        if(sctrlane.empty()) {
            cout << "There is no scooter in the parking lot of the scooter section !!!" << endl;
        }
        else {
            sctrlane.pop();
        }
    }
}

void Parking_lot::availableSlot(string _section) {
    if(_section == "car") {
        if(carlane.size() != _lsize*_num_lanes) {
            cout << "Available slot for your car: slot " << (carlane.size() % _lsize) + 1 << " in lane " << (carlane.size() / _lsize) + 1 << endl;
        }
        else {
            cout << "No more slots available to park car !!!" << endl;
        }
    }
    else if(_section == "scooter") {
        if(sctrlane.size() != _lsize*_num_lanes) {
            cout << "Available slot for your scooter: slot " << (sctrlane.size() % _lsize) + 1 << " in lane " << (sctrlane.size() / _lsize) + 1 << endl;
        }
        else {
            cout << "No more slots available to park scooter !!!" << endl;
        }
    }
}

int main() {
    Parking_lot parkingArea;

    // CAR MANAGEMENT
    for(int i=0; i<10; i++) {
        Vehicle vc("car", i+1);
        if(i == 5 || i == 8)  {
            parkingArea.availableSlot("car");   //prompting availabe slot in car section
        }
        parkingArea.park_vehicle(vc);   //10 cars parked in the parking area
    }
    Vehicle vc1("car", 11);
    parkingArea.availableSlot("car");
    parkingArea.park_vehicle(vc1);   //11th car is here to be parked
    for(int i=1; i<10; i++) {
        Vehicle vc("car", i+11);
        if(i == 2 || i == 6)  {
            parkingArea.availableSlot("car");   //prompting availabe slot if any in the CAR section
        }
        parkingArea.park_vehicle(vc);   //9 more cars parked in the parking area
    }
    Vehicle vc2("car", 21);
    parkingArea.availableSlot("car");   //prompting available slot if any in the CAR section
    parkingArea.park_vehicle(vc2);  //21st car is here to be parked
    parkingArea.depart_vehicle("car");  //one vehicle departs from the car section
    for(int i=0; i<10; i++) {
        parkingArea.depart_vehicle("car");  //10 cars are departed from the car section
    }

    cout << '\n';

    // SCOOTER MANAGEMENT
    for(int i=0; i<10; i++) {
        Vehicle vc("scooter", i+1);
        if(i == 3 || i == 7)  {
            parkingArea.availableSlot("scooter");   //prompting available slot if any in the SCOOTER  section
        }
        parkingArea.park_vehicle(vc);  //10 scooters parked in the parking area. Parking area is full
    }
    Vehicle vc3("scooter", 11);
    parkingArea.availableSlot("scooter");
    parkingArea.park_vehicle(vc3);   //11th scooter is here to be parked
    for(int i=1; i<10; i++) {
        Vehicle vc("scooter", i+1);
        if(i == 5 || i == 9)  {
            parkingArea.availableSlot("scooter");   //prompting available slot if any in the SCOOTER  section
        }
        parkingArea.park_vehicle(vc);  //9 more scooters parked in the parking area. Parking area is full
    }
    Vehicle vc4("scooter", 21);
    parkingArea.availableSlot("scooter");
    parkingArea.park_vehicle(vc4);   //21st scooter is here to be parked
    parkingArea.depart_vehicle("scooter");  //one vehicle departs from the scooter section
    for(int i=0; i<10; i++) {
        parkingArea.depart_vehicle("scooter");  //10 scooters are departed from the scooter section
    }

    return 0;
}