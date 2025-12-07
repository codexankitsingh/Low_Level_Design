
#include <iostream>
using namespace std;

class Orders {
private:
  int orderId;
  string orderDetails;
  string orderStatus;
  int orderAmount;
  string deliveryAddress;
  string paymentStatus;

public:
  Orders(int id, string details, int orderAmount, string deliveryAddress) {
    this->orderId = id;
    this->orderDetails = details;
    this->orderStatus = "Pending"; // Default status

    // Basic validation in constructor
    if (orderAmount > 0) {
      this->orderAmount = orderAmount;
    } else {
      this->orderAmount = 0;
      cout << "Warning: Invalid order amount, set to 0." << endl;
    }

    this->deliveryAddress = deliveryAddress;
    this->paymentStatus = "Unpaid";
  }

  // Getters (Read-Only access)
  int getOrderId() const { return orderId; }
  string getStatus() const { return orderStatus; }
  int getAmount() const { return orderAmount; }

  // Setters with VALIDATION (The core of Encapsulation)
  void updateOrderAmount(int amount) {
    if (amount <= 0) {
      cout << "Error: Amount must be positive. Update failed." << endl;
      return;
    }
    orderAmount = amount;
    cout << "Amount updated to: " << orderAmount << endl;
  }

  // Business Logic Methods (Better than raw setters)
  void markAsPaid() {
    if (paymentStatus == "Paid") {
      cout << "Order is already paid!" << endl;
      return;
    }
    paymentStatus = "Paid";
    cout << "Payment processed successfully." << endl;
  }

  void shipOrder() {
    if (paymentStatus != "Paid") {
      cout << "Cannot ship unpaid order!" << endl;
      return;
    }
    orderStatus = "Shipped";
    cout << "Order shipped to " << deliveryAddress << endl;
  }

  void updateDeliveryAddress(string address) {
    if (orderStatus == "Shipped") {
      cout << "Cannot change address, order already shipped!" << endl;
      return;
    }
    deliveryAddress = address;
    cout << "Address updated." << endl;
  }

  void PrintStatus() const {
    cout << "--- Order Summary ---" << endl;
    cout << "Order ID: " << orderId << endl;
    cout << "Details: " << orderDetails << endl;
    cout << "Status: " << orderStatus << endl;
    cout << "Amount: " << orderAmount << endl;
    cout << "Address: " << deliveryAddress << endl;
    cout << "Payment: " << paymentStatus << endl;
    cout << "---------------------" << endl;
  }
};

int main() {
  Orders *order1 = new Orders(1, "Laptop", 10000, "123 Main St");
  order1->PrintStatus();
}