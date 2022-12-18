package OOPS_Java.Miscellaneous;
import java.util.Scanner;

// Write a java program to do the following: 
// Create a "Student " class that stores the name, age and height of a student.
// Define a member function to accept the details of the data members of "Student".
// Define a member function to display the details of the data members of “Student”.
// Define a static integer Variable in "Student" called 'count' which is used to count the number of student objects created

class Student{
    // Variables
    int age, height;
    String name;
    static int count;
    // Function to accept details
    void takeInput(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the age of the student: ");
        this.age = sc.nextInt();
        System.out.print("Enter the height of the student: ");
        this.height = sc.nextInt();
        System.out.print("Enter the name of the student: ");
        this.name = sc.next();
    }
    // Function to display the details
    void display(){
        System.out.format("The age of the student: %d \n", this.age);
        System.out.format("The height of the student: %d \n", this.height);
        System.out.format("The name of the student: %d \n", this.name);
    }

}
class studentDetails{
    public static void main(String[] args) {
        // Scanner to take input
        Scanner sc = new Scanner(System.in);
        // Taking input of the number of students whose entries is to be made
        System.out.print("Enter the number of students:- ");
        Student.count = sc.nextInt();
        // Creating a student array to store them
        Student studentArray[] = new Student[Student.count];
        // Taking input
        for (int i = 0 ; i < Student.count ; i++){
            System.out.format("\nEnter details of student %d :- \n", i+1);
            studentArray[i] = new Student();
            studentArray[i].takeInput();
        }
        // Showing the results
        for (int i = 0 ; i < Student.count ; i++){
            System.out.format("\nThe details of student %d is:- \n", i+1);
            studentArray[i].display();
        }
        
    }
}