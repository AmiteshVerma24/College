package com.thirdquestion;
import java.util.*;

class Book {
    private int bookId;
    private String title;
    private String author;
    private String publisher;
    private double price;
    
    public Book(int bookId, String title, String author, String publisher, double price) {
        this.bookId = bookId;
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.price = price;
    }

    public int getBookId() {
        return bookId;
    }

    public String getAuthor() {
        return author;
    }

    public double getPrice() {
        return price;
    }

    public String toString() {
        return "Book ID: " + bookId + ", Title: " + title + ", Author: " + author + ", Publisher: " + publisher
                + ", Price: " + price + "\n";
    }
}

public class BookDatabase{
    ArrayList<Book> book_database = new ArrayList<>();
    
    public void add_book(int bookId, String title, String author, String publisher, double price){
        Book new_book = new Book(bookId, title, author, publisher, price);
        book_database.add(new_book);
    }

    public String display_books(){
        String str_to_return = "";
        for (Book book : book_database) {
            str_to_return += book.toString();
            System.out.println(book);
        }
        return str_to_return;
    }

    public void sort_books(){
        Collections.sort(book_database, (book1, book2) -> Double.compare(book1.getPrice(), book2.getPrice()));
        System.out.println("Books in sorted order of their prices are:- ");
        display_books();
    }

    public String get_books_by_author_name(String author){
        String str_to_return = "";
        System.out.format("Books of the author %s are:- \n", author);
        for (Book book : book_database) {
            String author_name = book.getAuthor();
            if(author_name.equals(author)){
                str_to_return += book.toString();
                System.out.println(book);
            }
        }
        return str_to_return;
    }
    
    public String new_list_with_price_greater_than(int price){
        ArrayList<Book> new_arr = new ArrayList<>();
        for (Book book : book_database) {
            if(book.getPrice() > price){
                new_arr.add(book);
            }
        }
        System.out.format("New books with prices greater than %d are:- \n", price);
        String str_to_return = "";
        for (Book book : new_arr) {
            str_to_return += book.toString();
        }
        return str_to_return;
    }
}
