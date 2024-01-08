package com.thirdquestion;
import com.thirdquestion.BookDatabase;
import java.awt.event.*;
import java.awt.*;
import javax.swing.*;


public class Main {
    public static void setup_layout(BookDatabase db){
        // Outer most parent is JFrame
        JFrame frame = new JFrame("Third Question");
        // To have multiple panels
        JTabbedPane tabbedPane = new JTabbedPane();
        // Think of it as div which can hold other components
        JPanel panel = new JPanel();
        // Set layout type
        panel.setLayout(new GridLayout(7,2));
        JLabel bookIdLabel = new JLabel("Enter the book ID: ");
        JTextField bookIdTextField = new JTextField();
        JLabel titleLabel = new JLabel("Enter the title: ");
        JTextField titleTextField = new JTextField();
        JLabel authorNameLabel = new JLabel("Enter the author ");
        JTextField authorNameTextField = new JTextField();
        JLabel publisherLabel = new JLabel("Enter publisher: ");
        JTextField publisherTextField = new JTextField();
        JLabel priceLabel = new JLabel("Enter the price: ");
        JTextField priceTextField = new JTextField();
        // Button to add new book
        JButton addNewBookBtn = new JButton("Add new books");
        addNewBookBtn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) { 
                int id = Integer.parseInt(bookIdTextField.getText());
                String title = titleTextField.getText();
                String author = authorNameTextField.getText();
                String publisher = publisherTextField.getText();
                Double price = Double.parseDouble(priceTextField.getText());
                db.add_book(id, title, author, publisher, price);
                System.out.println("New book added");
                bookIdTextField.setText("");
                titleTextField.setText("");
                authorNameTextField.setText("");
                publisherTextField.setText("");
                priceTextField.setText("");
                db.display_books();
              }    
        });
        // Button to display books
        JButton displayBookBtn = new JButton("Display books");
        displayBookBtn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                // New panel to display books
                JPanel newPanel = new JPanel();
                // Adding list of books
                String books = db.display_books();
                // Text area to display books
                JTextArea displayBooksTextArea = new JTextArea();
                displayBooksTextArea.setEditable(false);
                displayBooksTextArea.setText(books);
                newPanel.add(displayBooksTextArea);
                // Adding the new panel to our frame
                tabbedPane.addTab("Display books", newPanel);
            }
        });
        // Button to search books of an author
        JButton searchAuthorBooksBtn = new JButton("Search books of author");
        searchAuthorBooksBtn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                // New panel to display books
                JPanel newPanel = new JPanel();
                newPanel.setLayout(new GridLayout(3,2));
                // Asking user to give the author name
                JLabel label = new JLabel("Enter author name");
                JLabel dummy_label = new JLabel("Press to search author books");
                JLabel author_books_label = new JLabel("Author books");
                JTextField authorNameField = new JTextField();
                JButton askAuthorNameBtn = new JButton("Search author books");
                JTextArea displayBooksTextArea = new JTextArea();
                askAuthorNameBtn.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                       String author_books = db.get_books_by_author_name(authorNameField.getText());
                        displayBooksTextArea.setEditable(false);
                        displayBooksTextArea.setText(author_books);
                    }
                });
                newPanel.add(label);
                newPanel.add(authorNameField);
                newPanel.add(dummy_label);
                newPanel.add(askAuthorNameBtn);
                newPanel.add(author_books_label);
                newPanel.add(displayBooksTextArea);
                // Adding the new panel to our frame
                tabbedPane.addTab("Author books", newPanel);
            }
        });
        // Button to find books with price greater than a amount
        JButton searchBooksWithPrice = new JButton("Search books with price greater than");
        searchBooksWithPrice.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                // New panel to display books
                JPanel newPanel = new JPanel();
                newPanel.setLayout(new GridLayout(3,2));
                // Asking user to give the author name
                JLabel label = new JLabel("Enter the price");
                JLabel dummy_label = new JLabel("Press to search books");
                JLabel books_label = new JLabel("Book list");
                JTextField askPrice = new JTextField();
                JButton searchPriceBtn = new JButton("Search books");
                JTextArea displayBooksTextArea = new JTextArea();
                searchPriceBtn.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                       String author_books = db.new_list_with_price_greater_than(Integer.parseInt(askPrice.getText()));
                        displayBooksTextArea.setEditable(false);
                        displayBooksTextArea.setText(author_books);
                    }
                });
                newPanel.add(label);
                newPanel.add(askPrice);
                newPanel.add(dummy_label);
                newPanel.add(searchPriceBtn);
                newPanel.add(books_label);
                newPanel.add(displayBooksTextArea);
                // Adding the new panel to our frame
                tabbedPane.addTab("Book list", newPanel);
            }
        });
        panel.add(bookIdLabel);
        panel.add(bookIdTextField);
        panel.add(titleLabel);
        panel.add(titleTextField);
        panel.add(authorNameLabel);
        panel.add(authorNameTextField);
        panel.add(publisherLabel);
        panel.add(publisherTextField);
        panel.add(priceLabel);
        panel.add(priceTextField);
        panel.add(addNewBookBtn);
        panel.add(displayBookBtn);
        panel.add(searchAuthorBooksBtn);
        panel.add(searchBooksWithPrice);
        frame.add(panel);
        frame.add(tabbedPane);
        tabbedPane.addTab("Initial tab", panel);
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        BookDatabase db = new BookDatabase();
        setup_layout(db);
        
    } 

}