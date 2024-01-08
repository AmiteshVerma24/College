package com.fifthquestion;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import com.fifthquestion.CustomerDatabase;
import com.fifthquestion.ItemDatabase;

public class Main {
    public static int uid = 0;
    public static int total_price = 0;
    public static Double discounted_price = 0.0;
    public static int discount = 0;
    public static void setUpSecondPanel(JPanel second_panel, ItemDatabase itemDatabase){
        second_panel.setLayout(new GridLayout(6, 2));
        
        // Enter the ID of item to fetch its details
        JLabel enterItemIdLabel = new JLabel("Enter the item ID");
        JTextField enterItemIdTextField = new JTextField();
        // Enter the quantity of item entered
        JLabel enterItemIdQty = new JLabel("Enter item quantity");
        JTextField enterItemIdQtyTextField = new JTextField();
        // Item list
        JLabel itemListLabel = new JLabel("Item list");
        JTextArea itemDetails = new JTextArea();
        // Discount
        JButton enterDiscountButton = new JButton("Enter discount");
        JTextField enterDiscountTextField = new JTextField();  
        // Total
        JButton calculateTotalButton = new JButton("Calculate total");
        JTextArea totalTextArea = new JTextArea();  
        // Button which will handel add item event
        JLabel addItemLabel = new JLabel("Add item");
        JButton addItemButton = new JButton("Submit");
        addItemButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                System.out.println(enterItemIdTextField.getText());
                Item item = itemDatabase.getItemDetails(enterItemIdTextField.getText());
                total_price += item.getPrice() * Integer.parseInt( enterItemIdQtyTextField.getText());
                String data = "Name: " + item.getName() + " Quantity: " + enterItemIdQtyTextField.getText() + " Total: " + item.getPrice() * Integer.parseInt( enterItemIdQtyTextField.getText()) + "\n";
                itemDetails.append(data);
                enterItemIdTextField.setText("");
                enterItemIdQtyTextField.setText("");
                enterDiscountTextField.setText("");
            }
        });
        enterDiscountButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                discount = Integer.parseInt(enterDiscountTextField.getText());
                enterDiscountTextField.setText("");
            }
        });
        calculateTotalButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                System.out.println("Discount: "+discount);
                discounted_price = total_price - (total_price * discount * 0.01);
                String final_text = "Total price: " + total_price + "\nDiscounted price: " + discounted_price + "\n";
                totalTextArea.setText(final_text);
            }
        });

        second_panel.add(enterItemIdLabel);
        second_panel.add(enterItemIdTextField);
        second_panel.add(enterItemIdQty);
        second_panel.add(enterItemIdQtyTextField);
        second_panel.add(addItemLabel);
        second_panel.add(addItemButton);
        second_panel.add(itemListLabel);
        second_panel.add(itemDetails);
        second_panel.add(enterDiscountButton);
        second_panel.add(enterDiscountTextField);
        second_panel.add(calculateTotalButton);
        second_panel.add(totalTextArea);

    }
    public static void generateGUI(CustomerDatabase customerDatabase, ItemDatabase itemDatabase){
        JFrame frame = new JFrame();
        JTabbedPane tabbedPane = new JTabbedPane();
        JPanel first_panel = new JPanel();
        JPanel second_panel = new JPanel();
        first_panel.setLayout(new GridLayout(3,2));
        JLabel enterPhoneNumberLabel = new JLabel("Enter the phone number");
        JTextField phoneNumberTextField = new JTextField();
        JLabel submitPhoneNumberLabel = new JLabel("Submit phone number");
        JButton submitPhoneNumberButton = new JButton("Submit");
        submitPhoneNumberButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String res = customerDatabase.addCustomer(phoneNumberTextField.getText(), Integer.toString(uid));
                uid++;
                phoneNumberTextField.setText("");
                JOptionPane.showMessageDialog(first_panel, res);
                setUpSecondPanel(second_panel, itemDatabase);
                tabbedPane.addTab("Checkout", second_panel);
            }
        });
        first_panel.add(enterPhoneNumberLabel);
        first_panel.add(phoneNumberTextField);
        first_panel.add(submitPhoneNumberLabel);
        first_panel.add(submitPhoneNumberButton);
        tabbedPane.addTab("Customer details", first_panel);
        frame.add(tabbedPane);
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        CustomerDatabase db = new CustomerDatabase();
        System.out.println(db.addCustomer("123", "1"));
        System.out.println(db.addCustomer("456", "2"));
        System.out.println(db.addCustomer("123", "3"));
        db.showCustomers();
        ItemDatabase itemDatabase = new ItemDatabase();
        itemDatabase.displayItems();
        generateGUI(db, itemDatabase);
    }
}