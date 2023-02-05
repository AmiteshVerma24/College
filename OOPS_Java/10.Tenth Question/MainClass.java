import java.util.*;
import ISE.ise_department;
public class MainClass {
    public static void main(String[] args) {
        // Creating variables
        int choice;
        // Defining the scanner object
        Scanner sc = new Scanner(System.in);
        // Creating a ise department object
        ise_department department = new ise_department();
        // Calling the method to take input of the faculties of ise department
        department.readdata();
        // Printing the details
        department.printdata();
        // Now presenting a menu driven program as for what to do
        // System.out.print("What would you like to do?\n 1. Print details of all faculties.\n 2. Print total number of designations.\n 3.Print total number of research consultancy.\nEnter your choice:- ");
        // choice = sc.nextInt();
        // switch(choice){
        //     case 1:
        //         department.printdata();
        //         break;
        //     case 2:
        //         department.print_number_designations();
        //         break;
        //     case 3:
        //         department.number_research_consultancy_projs();
        //         break;
        //     default:
        //     System.out.println("INVAILD!");
        // }
        // sc.close();
    }
}
