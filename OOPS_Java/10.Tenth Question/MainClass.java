import java.util.*;
import ISE.ise_department;
public class MainClass {
    public static void main(String[] args) {
        // Defining the scanner object
        Scanner sc = new Scanner(System.in);
        // Creating a ise department object
        ise_department department = new ise_department();
        // Calling the method to take input of the faculties of ise department
        department.readdata();
        // Printing the details
        department.printdata();
        sc.close();
    }
}
