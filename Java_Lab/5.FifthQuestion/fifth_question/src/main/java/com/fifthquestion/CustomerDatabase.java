package com.fifthquestion;

import java.util.HashMap;

class Customer{
    String customerID;
    String customerPhone;
    public Customer(String customerID, String customerPhone){
        this.customerID = customerID;
        this.customerPhone = customerPhone;
    }
    public String getCustomerID(){
        return customerID;
    }
    public String getCustomerPhone(){
        return customerPhone;
    }
    public String getDetails(){
        return "ID: " + customerID + ", Phone no: " + customerPhone + "\n";
    }
}

public class CustomerDatabase {
    // We will use phone number as the unique key
    HashMap<String, Customer> customer_database = new HashMap<>();

    public String addCustomer(String customerPhone, String customerID){
        if (customer_database.get(customerPhone) == null) {
            Customer new_customer = new Customer(customerID, customerPhone);
            customer_database.put(customerPhone, new_customer);
            return "New customer added successfully";
        }
        return "Customer already exist\n" + customer_database.get(customerPhone).getDetails();
    }
    public void showCustomers(){
        customer_database.forEach((key, value) -> {
            System.out.print(key + " " + value.getDetails());
        });
    }
}
