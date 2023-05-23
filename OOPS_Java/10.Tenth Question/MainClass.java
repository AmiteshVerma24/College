import java.util.*;

import ISE.ISE_department;
public class MainClass {
    public static void main(String[] args) {
        // Defining the scanner object
        Scanner sc = new Scanner(System.in);
        // Creating a ise department object
        ISE_department department = new ISE_department();
        // Calling the method to take input of the faculties of ise department
        department.readdata();
        // Printing the details
        department.printdata();
        sc.close();
    }
}