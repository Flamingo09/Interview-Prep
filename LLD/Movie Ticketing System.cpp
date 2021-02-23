class Movie {
    
};

class Audi {
    int audiId;
    int capacity;
    
    bool bookSeats();
};

public enum SEAT_TYPE {PREMIUM, NORMAL};
public enum SEAT_STATUS {VACANT, BOOKED, BLOCKED};

class Seat {
    int seatId;
    SEAT_TYPE seatType;
    SEAT_STATUS seatStatus;
    
    Seat(int seatId, SEAT_TYPE seatType) {
        this->seatId=seatId;
        this->seatType=seatType;
        this->seatStatus=seatStatus;
    }
};

class Ticket {
    int ticketId, userId, movieId, audiId, amountPaid;
    Date showTime;
    list<Seat> seatsAlloted;
};

class User {
    int userId, ticketId;
    
    int ticketId=placeOrder;
    Ticket ticket = Ticket.getTicket(ticketId);
};

class Theatre {
    int theatreId;
    Address address;
    list<Audi> audis;
};

class Order {
    int orderId;
    
    int placeOrder(Theatre theatreId, int audiId, int showTime, int seatCounts, SEAT_TYPE seatType) {
        
    }
};

int main() {
    std::cout << "Movie Ticketing!\n";
}
