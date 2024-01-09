package com.seventhquestion;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class Main {
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/java";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "your_password";
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(JDBC_URL, USERNAME, PASSWORD);
    }
    public static String  fetchData() {
        try {
            Connection connection = getConnection();
            PreparedStatement statement = connection.prepareStatement("SELECT * FROM users");
            ResultSet resultSet = statement.executeQuery();
            StringBuilder str = new StringBuilder();
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                String username = resultSet.getString("username");
                String password = resultSet.getString("password");
                String line = "ID: " + id + ", Name: " + name + ", Username: " + username + ", Password: " + password + "\n";
                System.out.println(line);
                str.append(line);
            }

            resultSet.close();
            statement.close();
            connection.close();
            return str.toString();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return "Default string";
    }
    public static void insertUser(JPanel panel, String name, String username, String password){
        try {
            Connection connection = getConnection();
            String sql = "INSERT INTO users (username, name, password) VALUES " +
                    "('" + username + "', '" + name + "', '" + password + "')";
            PreparedStatement query = connection.prepareStatement(sql);
            int rows = query.executeUpdate();
            if (rows > 0) {
                System.out.println("A new user was inserted successfully!");
                JOptionPane.showMessageDialog(panel,"A new user was inserted successfully!");
            } else {
                System.out.println("Failed to insert a new user.");
                JOptionPane.showMessageDialog(panel,"Failed to insert a new user.");
            }
            query.close();
            connection.close();
        }catch(Exception e){
            System.out.println("Exception occurred: " + e.getMessage());
        }
    }
    public static void createGUI(){
        JFrame frame = new JFrame();
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5,2));
        JLabel nameLabel = new JLabel("Enter the name");
        JTextField nameField = new JTextField();
        JLabel usernameLabel = new JLabel("Enter the username");
        JTextField usernameField = new JTextField();
        JLabel passwordLabel = new JLabel("Enter the password");
        JTextField passwordField = new JTextField();
        JButton submitButton = new JButton("Submit");
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                String username = usernameField.getText();
                String password = passwordField.getText();
                insertUser(panel, name, username, password);
                nameField.setText("");
                usernameField.setText("");
                passwordField.setText("");
            }
        });
        JButton displayButton = new JButton("Display");
        displayButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String str = fetchData();
                JOptionPane.showMessageDialog(panel, str);
            }
        });
        panel.add(nameLabel);
        panel.add(nameField);
        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(submitButton);
        panel.add(displayButton);
        frame.add(panel);
        frame.setSize(800, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        createGUI();
//        fetchData();
    }
}