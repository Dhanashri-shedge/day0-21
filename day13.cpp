#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Structure to store an order
struct Order {
    string orderID;
    string customerID;
    vector<std::string> products;
};

// Function to store orders
void storeOrders(vector<Order>& orders) {
    // Sample orders (In practice, this would come from user input or a file)
    orders.push_back({"ORD001", "CUST001", {"P001", "P002", "P003"}});
    orders.push_back({"ORD002", "CUST002", {"P003", "P004", "P005"}});
    orders.push_back({"ORD003", "CUST001", {"P001", "P005"}});
    orders.push_back({"ORD004", "CUST003", {"P002", "P003", "P001", "P006"}});
}

// Function to identify unique products
void identifyUniqueProducts(vector<Order>& orders,set<string>& uniqueProducts) {
    for (const auto& order : orders) {
        for (const auto& product : order.products) {
            uniqueProducts.insert(product);
        }
    }
}

// Function to compute product sales count
void computeProductSalesCount(const vector<Order>& orders,unordered_map<string, int>& salesCount) {
    for (const auto& order : orders) {
        for (const auto& product : order.products) {
            salesCount[product]++;
        }
    }
}

// Function to determine the top customer (customer with the most distinct products)
void determineTopCustomer(const vector<Order>& orders, unordered_map<string,set<string>>& customerProducts) {
    for (const auto& order : orders) {
        customerProducts[order.customerID].insert(order.products.begin(), order.products.end());
    }

    // Find the customer with the largest number of distinct products
    string topCustomer;
    size_t maxDistinctProducts = 0;

    for (const auto& entry : customerProducts) {
        size_t distinctCount = entry.second.size();
        if (distinctCount > maxDistinctProducts) {
            maxDistinctProducts = distinctCount;
            topCustomer = entry.first;
        }
    }

    cout << "Top Customer: " << topCustomer << " with " << maxDistinctProducts << " distinct products.\n";
}

int main() {
    vector<Order> orders;
    storeOrders(orders);

    // Task 2: Identify unique products
    set<string> uniqueProducts;
    identifyUniqueProducts(orders, uniqueProducts);

    cout << "Unique Products:\n";
    for (const auto& product : uniqueProducts) {
        cout << product << "\n";
    }

    // Task 3: Compute product sales count
    unordered_map<string, int> salesCount;
    computeProductSalesCount(orders, salesCount);

    cout << "\nProduct Sales Count:\n";
    for (const auto& entry : salesCount) {
        cout << "Product: " << entry.first << ", Sales: " << entry.second << "\n";
    }

    // Task 4: Determine the top customer
    unordered_map<string, set<string>> customerProducts;
    determineTopCustomer(orders, customerProducts);

    return 0;
}
