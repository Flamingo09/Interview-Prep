class User {
    int id;
    string userName;
    Address address;
    
    User(int id, string userName, Address address) {
        this->id=id;
        this->userName=userName;
        this->address=address;
    }
};

class Seller {
    int id;
    list<Item> items;
};

class Item {
    int itemId;
    int qty;
};

class Monitor : public Item {
    
};

class Catalogue {
    list<Item> items;
};

class Cart {
    int cartId, userId;
    unordered_map<int, int> itemsQty;
    
    Cart(int cartId, int userI) {
        this->cartId=cartId;
        this->userId=userId;
    }
    
    void addItem(Item itemId, int qty) {
        itemsQty[itemId]=qty;
    }
    
    void updateItem(Item itemId, int qty) {
        addItem(itemId, qty);
    }
    
    void removeItem(Item itemId, int qty) {
        itemsQty.erase(itemId);
    }
};

class PaymentMethod {
    
};

class CreditCard : public PaymentMethod {
    int creditCardNumber;
    Date expiry;
}

class Address {
    
};


int main() {
    std::cout << "Hello World!\n";
}
