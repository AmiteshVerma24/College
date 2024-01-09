import java.sql.*;
import  java.util.*;
import javax.swing.*;
import java.awt.*;
import  java.awt.event.*;

public class Main {
    private static String SQL_URL = "jdbc:mysql://localhost:3306/java";
    private static String USERNAME = "root";
    private static String PASSWORD = "your_password";
    public static void createGUI(){
    }
    private static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(SQL_URL, USERNAME, PASSWORD);
    }
    public static void insertRepresentativeData(String name, String state, String commission, int rate, JPanel panel){
        try{
            Connection connection = getConnection();
            String sql = "INSERT INTO representative (repName, state, comission, rate) VALUES " + "('" + name + "', '" + state + "', '" + commission + "', " + rate + ")";
            PreparedStatement statement = connection.prepareStatement(sql);
            int rows = statement.executeUpdate();
            if (rows > 0){
                System.out.println("A new user was inserted successfully!");
                JOptionPane.showMessageDialog(panel,"A new user was inserted successfully!");
            }else{
                System.out.println("A new user was inserted successfully!");
                JOptionPane.showMessageDialog(panel,"A new user was inserted successfully!");
            }
        }catch (Exception e){
            System.out.println("Error inserting data!");
        }
    }
    public static void insertCustomerData(String name, String state , int credit, int repNo, JPanel panel){
        try{
            Connection connection = getConnection();
            String sql = "INSERT INTO customer (custName, state, creditLimit, repNo) VALUES " + "('" + name + "', '" + state + "', " + credit + ", " + repNo + ")";
            PreparedStatement statement = connection.prepareStatement(sql);
            int rows = statement.executeUpdate();
            if (rows > 0){
                System.out.println("A new user was inserted successfully!");
                JOptionPane.showMessageDialog(panel,"A new user was inserted successfully!");
            }else{
                System.out.println("A new user was inserted successfully!");
                JOptionPane.showMessageDialog(panel,"A new user was inserted successfully!");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    public static void createRepresentativePanel(JPanel representative_panel){
        representative_panel.setLayout(new GridLayout(5,2));
        JLabel repNameLabel = new JLabel("Enter name");
        JTextField repNameTextField = new JTextField();
        JLabel repStateLabel = new JLabel("Enter state");
        JTextField repStateTextField = new JTextField();
        JLabel repCommissionLabel = new JLabel("Enter commission");
        JTextField repCommissionTextField = new JTextField();
        JLabel repRateLabel = new JLabel("Enter rate");
        JTextField repRateTextField = new JTextField();
        JButton submitRepDetailsButton = new JButton("Submit");
        submitRepDetailsButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = repNameTextField.getText();
                String state = repStateTextField.getText();
                String commission = repCommissionTextField.getText();
                int rate = Integer.parseInt(repRateTextField.getText());
                insertRepresentativeData(name, state, commission, rate, representative_panel);
                repNameTextField.setText("");
                repStateTextField.setText("");
                repCommissionTextField.setText("");
                repRateTextField.setText("");
            }
        });
        representative_panel.add(repNameLabel);
        representative_panel.add(repNameTextField);
        representative_panel.add(repStateLabel);
        representative_panel.add(repStateTextField);
        representative_panel.add(repCommissionLabel);
        representative_panel.add(repCommissionTextField);
        representative_panel.add(repRateLabel);
        representative_panel.add(repRateTextField);
        representative_panel.add(submitRepDetailsButton);
    }

    public static void createCustomerPanel(JPanel customer_panel){
        JLabel custNameLabel = new JLabel("Enter name");
        JTextField custNameTextField = new JTextField();
        JLabel custStateLabel = new JLabel("Enter state");
        JTextField custStateTextField = new JTextField();
        JLabel repCreditLabel = new JLabel("Enter credit");
        JTextField repCreditTextField = new JTextField();
        JLabel custRepNoLabel = new JLabel("Enter representative number");
        JTextField custRepNoTextField = new JTextField();
        JButton submitCustDetailsButton = new JButton("Submit");
        submitCustDetailsButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = custNameTextField.getText();
                String state = custStateTextField.getText();
                int credit = Integer.parseInt(repCreditTextField.getText());
                int repNo = Integer.parseInt(custRepNoTextField.getText());
                insertCustomerData(name, state, credit , repNo, customer_panel);
                custNameTextField.setText("");
                custStateTextField.setText("");
                repCreditTextField.setText("");
                custRepNoTextField.setText("");
            }
        });
        customer_panel.add(custNameLabel);
        customer_panel.add(custNameTextField);
        customer_panel.add(custStateLabel);
        customer_panel.add(custStateTextField);
        customer_panel.add(repCreditLabel);
        customer_panel.add(repCreditTextField);
        customer_panel.add(custRepNoLabel);
        customer_panel.add(custRepNoTextField);
        customer_panel.add(submitCustDetailsButton);
    }
    public static String fetchData(String state){
        try{
            Connection connection = getConnection();
            String sql1 = "Select repName from representative where state = " + "'" + state + "'";
            String sql2 = "Select custName from customer where state = " + "'" + state + "'";
            System.out.println(sql2);
            PreparedStatement statement1 = connection.prepareStatement(sql1);
            PreparedStatement statement2 = connection.prepareStatement(sql2);
            ResultSet set1 = statement1.executeQuery();
            ResultSet set2 = statement2.executeQuery();
            String representative_string = "";
            String customer_string = "";
            System.out.println(set1);
            System.out.println(set2);
            while (set1.next()){
                String name = set1.getString("repName");
                System.out.println(name);
                representative_string = representative_string + name + "\n";
            }
            while (set2.next()){
                String name = set2.getString("custName");
                customer_string = customer_string + name + "\n";
            }
            return "Representative list:\n" + representative_string + "Customer list:\n" + customer_string;
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
        return "Default";
    }
    public static void createDisplayPanel(JPanel detailPanel){
        detailPanel.setLayout(new GridLayout(3,2));
        JLabel enterStateLabel = new JLabel("Enter state");
        JTextField enterStateTextField = new JTextField();
        JLabel dataLabel = new JLabel("Representative and Customer list");
        JTextArea dataTextArea = new JTextArea();
        JLabel submitLabel = new JLabel("Submit");
        JButton submitButton = new JButton();
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String res = fetchData(enterStateTextField.getText());
                dataTextArea.setText(res);
            }
        });
        detailPanel.add(enterStateLabel);
        detailPanel.add(enterStateTextField);
        detailPanel.add(submitLabel);
        detailPanel.add(submitButton);
        detailPanel.add(dataLabel);
        detailPanel.add(dataTextArea);
    }
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        JTabbedPane tabbedPane = new JTabbedPane();
        JPanel representative_panel = new JPanel();
        JPanel customer_panel = new JPanel();
        JPanel detail_panel = new JPanel();
        createRepresentativePanel(representative_panel);
        createCustomerPanel(customer_panel);
        createDisplayPanel(detail_panel);
        tabbedPane.add("Representative panel", representative_panel);
        tabbedPane.add("Customer panel", customer_panel);
        tabbedPane.add("Display panel", detail_panel);
        frame.add(tabbedPane);
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

    }
}