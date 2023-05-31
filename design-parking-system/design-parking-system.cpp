class ParkingSystem {
public:
        int big;
        int medium;
        int small;

    ParkingSystem(int big, int medium, int small) {
        this->small = small;
        this->medium = medium;
        this->big = big;
    }
    
    bool addCar(int carType) {
        if((carType == 3 && small == 0) || (carType == 2 && medium == 0) || (carType == 1 && big == 0)) return false;

        if(carType == 1) big--;
        if(carType == 3) small--;
        if(carType == 2) medium--;
        return true;
         
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */