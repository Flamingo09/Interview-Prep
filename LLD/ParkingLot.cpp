enum SLOT_TYPE {WHEELER_2=10, WHEELER_4=20};
enum SLOT_STATUS {FREE=1, OCCUPIED=2};

class Slot {
    private:
        int id;
        SLOT_STATUS status;
        int timeStampOfBooking;
    public:
        Slot(int id) {
            this->id=id;
            this->timeStampOfBooking=0;
            this->status=SLOT_STATUS::FREE;
        }
        int getId() {
            return id;
        }
        
        SLOT_STATUS getStatus() {
            return this->status;
        }
        void bookSlot() {
            cout<<"Booking"<<endl;
            this->status=SLOT_STATUS::OCCUPIED;
        }
        void freeSlot() {
            this->status=SLOT_STATUS::FREE;
            this->timeStampOfBooking=0;
        }
};

class MotorcyleSlot : public Slot {
    private:
        int id;
    public:
        MotorcyleSlot(int id) : Slot(id) {
        }
};

class CarSlot : public Slot {
    private:
        int id;
    public:
        CarSlot(int id) : Slot(id) {
        }
};
class ParkingLot {

    private:
        int capacity, two_whlr_cnt, four_whlr_cnt;
        vector<Slot> freeSlots2, freeSlots4;
        vector<Slot> bookedSlots;
    public:
        ParkingLot(int two_whlr_cnt, int four_whlr_cnt) {
            this->capacity=two_whlr_cnt+four_whlr_cnt;
            int i=0;
            for(i=0; i<two_whlr_cnt; i++) this->freeSlots2.push_back(MotorcyleSlot(i));
            for(; i<this->capacity; i++) this->freeSlots4.push_back(CarSlot(i));
        }
        
        vector<Slot> getFreeSlots() {
            return this->freeSlots2;
        }
};

bool bookSlot(SLOT_TYPE type) {
    return true;
}
int main() {
    std::cout << "Parking Lot!\n";
    ParkingLot p(10, 5);
    
    p.getFreeSlots()[0].bookSlot();
    cout<<p.getFreeSlots()[0].getStatus();
}
