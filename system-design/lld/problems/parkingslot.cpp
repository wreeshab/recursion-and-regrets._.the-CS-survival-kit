#include <iostream>
#include <bits/stdc++.h>
using namespace std;

enum VehicleType
{
    CAR,
    BIKE,
    BUS
};

class ParkingSlot
{
private:
    int slotNumber;
    VehicleType vehicleType;
    bool isOccupied;

public:
    ParkingSlot(int number, VehicleType type)
    {
        slotNumber = number;
        vehicleType = type;
        isOccupied = false;
    }
    int getSlotNumber() const
    {
        return slotNumber;
    }
    VehicleType getVehicleType() const
    {
        return vehicleType;
    }
    bool getIsOccupied() const
    {
        return isOccupied;
    }
    void occupySlot()
    {
        if (!isOccupied)
        {
            isOccupied = true;
        }
        else
        {
            cout << "Slot " << slotNumber << " is already occupied." << endl;
        }
    }
    void releaseSlot()
    {
        if (isOccupied)
        {
            isOccupied = false;
        }
        else
        {
            cout << "Slot " << slotNumber << " is already free." << endl;
        }
    }
};

class ParkingTicket
{
private:
    int ticketNumber;
    int slotNumber;
    string vehicleNumber;
    VehicleType vehicleType;
    time_t issueTime;

public:
    ParkingTicket(int ticketNum, int slotNum, string vehicleNum, VehicleType vehicleType)
    {
        ticketNumber = ticketNum;
        slotNumber = slotNum;
        vehicleNumber = vehicleNum;
        this->vehicleType = vehicleType;
        issueTime = time(0); // current time
    }
    int getTicketNumber() const
    {
        return ticketNumber;
    }
    int getSlotNumber() const
    {
        return slotNumber;
    }
    string getVehicleNumber() const
    {
        return vehicleNumber;
    }
    time_t getIssueTime() const
    {
        return issueTime;
    }
    VehicleType getVehicleType() const
    {
        return vehicleType;
    }
};

class ParkingFloor
{
private:
    int floorNumber;
    unordered_map<VehicleType, vector<shared_ptr<ParkingSlot>>> slots;
    unordered_map<string, ParkingTicket> tickets;
    int nextSlotNumber = 1;
    int nextTicketNumber = 1;
    const double basePrice = 5.0; // base price for parking
    const unordered_map<VehicleType, double> pricePerHour = {
        {CAR, 2.0},   // price per hour for car
        {BIKE, 1.0},  // price per hour for bike
        {BUS, 3.0}    // price per hour for bus
    };  

public:
    int getFloorNumber() const
    {
        return floorNumber;
    }
    ParkingFloor(int number) : floorNumber(number) {}
    void addParkingSlot(VehicleType vehicleType)
    {
        auto parkingSlot = make_shared<ParkingSlot>(nextSlotNumber++, vehicleType);
        if (slots.find(vehicleType) == slots.end())
        {
            slots[vehicleType] = vector<shared_ptr<ParkingSlot>>();
        }
        slots[vehicleType].push_back(parkingSlot);
    }

    void parkVehicle(string vehicleNumber, VehicleType vehicleType)
    {
        for (auto &parkingSlot : slots[vehicleType])
        {
            if (!parkingSlot->getIsOccupied())
            {
                parkingSlot->occupySlot();
                ParkingTicket ticket(nextTicketNumber++, parkingSlot->getSlotNumber(), vehicleNumber, vehicleType);
                tickets[vehicleNumber] = ticket;
                cout << "Vehicle " << vehicleNumber << " parked in slot " << parkingSlot->getSlotNumber() << endl;
                return;
            }
        }
        cout << "No available slot for vehicle type " << vehicleType << endl;
    }

    void releaseVehicle(string vehicleNumber)
    {
        if (tickets.find(vehicleNumber) == tickets.end())
        {
            cout << "No ticket found for vehicle number " << vehicleNumber << endl;
            return;
        }
        ParkingTicket ticket = tickets[vehicleNumber];
        int slotNumber = ticket.getSlotNumber();
        VehicleType vehicleType = ticket.getVehicleType();
        for (auto &parkingSlot : slots[vehicleType])
        {
            if (parkingSlot->getSlotNumber() == slotNumber)
            {
                parkingSlot->releaseSlot();
                tickets.erase(vehicleNumber);
                time_t currentTime = time(0);
                double parkedHours = difftime(currentTime, ticket.getIssueTime()) / 3600.0;
                double price = basePrice + (parkedHours * pricePerHour.at(vehicleType));
                cout << "Vehicle " << vehicleNumber << " released from slot " << slotNumber
                     << ". Total price: $" << fixed << setprecision(2) << price << endl;
                return;
            }
        }
    }
};

class ParkingLot {
private:
    vector<ParkingFloor> floors;
public:
    ParkingLot() {}
    void addFloor(int floorNumber) {
        ParkingFloor floor(floorNumber);
        floors.push_back(floor);
    }
    void addParkingSlot(int floorNumber, VehicleType vehicleType) {
        for (auto &floor : floors) {
            if (floor.getFloorNumber() == floorNumber) {
                floor.addParkingSlot(vehicleType);
                return;
            }
        }
        cout << "Floor " << floorNumber << " not found." << endl;
    }
    void parkVehicle(int floorNumber, string vehicleNumber, VehicleType vehicleType) {
        for (auto &floor : floors) {
            if (floor.getFloorNumber() == floorNumber) {
                floor.parkVehicle(vehicleNumber, vehicleType);
                return;
            }
        }
        cout << "Floor " << floorNumber << " not found." << endl;
    }
    void releaseVehicle(int floorNumber, string vehicleNumber) {
        for (auto &floor : floors) {            
            if (floor.getFloorNumber() == floorNumber) {
                floor.releaseVehicle(vehicleNumber);
                return;
            }
        }
        cout << "Floor " << floorNumber << " not found." << endl;
    }
    int getFloorCount() const {
        return floors.size();
    }
};
