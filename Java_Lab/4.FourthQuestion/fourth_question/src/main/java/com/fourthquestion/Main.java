package com.fourthquestion;
import com.fourthquestion.StudentDatabase;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class Main {
    public static void create_gui(StudentDatabase db){
        JFrame frame = new JFrame();
        JTabbedPane tabbedPane = new JTabbedPane();
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(8,2));
        JLabel nameLabel = new JLabel("Enter name: ");
        JTextField nameTextField = new JTextField();
        JLabel usnLabel = new JLabel("Enter usn: ");
        JTextField usnTextField = new JTextField();
        JLabel addressLabel = new JLabel("Enter address: ");
        JTextField addressTextField = new JTextField();
        JLabel categoryLabel = new JLabel("Enter category: ");
        JTextField categoryTextField = new JTextField();
        JLabel ageLabel = new JLabel("Enter age: ");
        JTextField ageTextField = new JTextField();
        JLabel sgpaLabel = new JLabel("Enter sgpa: ");
        JTextField sgpaTextField = new JTextField();
        JLabel submitButtonLabel = new JLabel("Click to add student: ");
        JButton submitButton = new JButton("Add student details");
        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                String name = nameTextField.getText();
                String usn = usnTextField.getText();
                String address = addressTextField.getText();
                String category = categoryTextField.getText();
                int age = Integer.parseInt(ageTextField.getText());
                float sgpa = Float.parseFloat(sgpaTextField.getText());
                String res = db.insertStudent(name,usn,address,category,age,sgpa);
                System.out.println(res);
                db.displayStudents();
                nameTextField.setText("");
                usnTextField.setText("");
                addressTextField.setText("");
                categoryTextField.setText("");
                ageTextField.setText("");
                sgpaTextField.setText("");
                JOptionPane.showMessageDialog(panel, res);
            }
        });
        JLabel displayLabel = new JLabel("Display students");
        JButton displayButton = new JButton("Display students");
        displayButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                JPanel display_panel = new JPanel();
                display_panel.setLayout(new GridLayout(0, 1));
                JTextArea textArea = new JTextArea();
                textArea.setEditable(false);
                textArea.setText(db.displayStudents());
                display_panel.add(textArea);
                tabbedPane.addTab("Student details", display_panel);
            }
        });
        panel.add(nameLabel);
        panel.add(nameTextField);
        panel.add(usnLabel);
        panel.add(usnTextField);
        panel.add(addressLabel);
        panel.add(addressTextField);
        panel.add(categoryLabel);
        panel.add(categoryTextField);
        panel.add(ageLabel);
        panel.add(ageTextField);
        panel.add(sgpaLabel);
        panel.add(sgpaTextField);
        panel.add(submitButtonLabel);
        panel.add(submitButton);
        panel.add(displayLabel);
        panel.add(displayButton);
        frame.add(tabbedPane);
        tabbedPane.addTab("Main tab", panel);
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        StudentDatabase student_database = new StudentDatabase();
        create_gui(student_database);
    }
}