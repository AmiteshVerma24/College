import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main {
    public static void createGUI(EmployeeDatabase db){
        JFrame frame = new JFrame();
        JTabbedPane tabbedPane = new JTabbedPane();
        JPanel firstPanel = new JPanel();
        firstPanel.setLayout(new GridLayout(9, 2));
        String [] options = {"0 - 10000", "10000 - 30000", "30000 - 60000", "60000 - 100000"};
        JLabel nameLabel = new JLabel("Enter the name");
        JTextField nameTextField = new JTextField();
        JLabel addressLabel = new JLabel("Enter the Address");
        JTextField addressTextField = new JTextField();
        JLabel genderLabel = new JLabel("Enter the gender");
        JTextField genderTextField = new JTextField();
        JLabel ageLabel = new JLabel("Enter the age");
        JTextField ageTextField = new JTextField();
        JLabel familyMembersLabel = new JLabel("Enter the number of family members");
        JTextField familyMembersTextField = new JTextField(); 
        JLabel payscaleLabel = new JLabel("Select the payscale");
        JComboBox<String> payscale = new JComboBox<>(options);
        JButton addEmployeeButton = new JButton("Add employee");
        addEmployeeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                String name = nameTextField.getText();
                String address = addressTextField.getText();
                String gender = genderTextField.getText();
                String payScale = (String) payscale.getSelectedItem();
                int age = Integer.parseInt(ageTextField.getText());
                int familyMembers = Integer.parseInt(familyMembersTextField.getText());
                String res = db.addEmployee(name, payScale, address, gender, age, familyMembers);
                JOptionPane.showMessageDialog(firstPanel, res);
                nameTextField.setText("");
                addressTextField.setText("");
                genderTextField.setText("");
                ageTextField.setText("");
                familyMembersTextField.setText("");
            }
        });
        JButton displayEmployeeButton = new JButton("Display employee");
        displayEmployeeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                if(tabbedPane.getTabCount() > 1) {
                    tabbedPane.remove(1);
                }
                JPanel secPanel = new JPanel();
                JTextArea detailsTextArea = new JTextArea();
                String details = db.getEmployeeDetails();
                System.out.println(details);
                detailsTextArea.setText(details);
                secPanel.add(detailsTextArea);
                tabbedPane.add("Second panel", secPanel);
            }
        });

        firstPanel.add(nameLabel);
        firstPanel.add(nameTextField);
        firstPanel.add(addressLabel);
        firstPanel.add(addressTextField);
        firstPanel.add(genderLabel);
        firstPanel.add(genderTextField);
        firstPanel.add(ageLabel);
        firstPanel.add(ageTextField);
        firstPanel.add(familyMembersLabel);
        firstPanel.add(familyMembersTextField);
        firstPanel.add(payscaleLabel);
        firstPanel.add(payscale);
        firstPanel.add(addEmployeeButton);
        firstPanel.add(displayEmployeeButton);
        tabbedPane.add("First panel", firstPanel);
        frame.add(tabbedPane);
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        EmployeeDatabase db = new EmployeeDatabase();
        createGUI(db);
    }
}
