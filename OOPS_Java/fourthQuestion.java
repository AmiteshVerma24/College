package OOPS_Java;
import java.util.Scanner;
import java.math.*;
/* Define a class Complex with data members as two real numbers, constructors for initialization these numbers, methods to add, subtract and multiply 2 complex numbers. */
class Complex{
    // Declaring Variables
    private double r1, r2, c1, c2;
    // Constrctors
    Complex(double r1, double r2, double c1, double c2){
        this.r1 = r1;
        this.r2 = r2;
        this.c1 = c1;
        this.c2 = c2;
    }
    // Addition
    public void Add(){
        System.out.format("The sum of (%f + %fi) and (%f + %fi) is: (%f + %fi)",r1,c1,r2,c2,r1+r2,c1+c2);
    }
    // Subtraction
    public void Subtract(){
        System.out.format("The sum of (%f + %fi) and (%f + %fi) is: (%f + %fi)",r1,c1,r2,c2,r1-r2,c1-c2);
    }
    // Multiply
    public void Multiply(){
        System.out.format("The sum of (%f + %fi) and (%f + %fi) is: (%f + %fi)",r1,c1,r2,c2,(r1*c1-r2*c2),(r1*c2+c1*r2));
    }
    // Divide
    public void Divide(){
        System.out.format("The sum of (%f + %fi) and (%f + %fi) is: (%f + %fi)",r1,c1,r2,c2,(r1*r2+c1*c2)/((r2*r2)+(c2*c2)),((c1*r2-r1*c2)/((r2*r2)+(c2*c2))));
    }


}
public class FourthQuestion {
    public static void main(String[] args) {
        // Declaration
        double r1 , r2 , c1 , c2;
        int choice;
        // New scanner object
        Scanner sc = new Scanner(System.in);
        // Asking the user for input
        System.out.print("Enter the real part of first Complex Number: ");
        r1 = sc.nextDouble();
        System.out.print("Enter the imaginary part of first Complex Number: ");
        c1 = sc.nextDouble();
        System.out.print("Enter the real part of second Complex Number: ");
        r2 = sc.nextDouble();
        System.out.print("Enter the imaginary part of second Complex Number: ");
        c2 = sc.nextDouble();
        // Creating complex object
        Complex myComplexObject = new Complex(r1, r2, c1, c2);
        // Asking the user for his/her choice
        System.out.println("What would you like to do? \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division");
        System.out.print("Enter your choice: ");
        choice = sc.nextInt();
        // Using switch to present a menu driven program
        switch (choice){
            case 1:
                myComplexObject.Add();
                break;
            case 2:
                myComplexObject.Subtract();
                break;
            case 3:
                myComplexObject.Multiply();
                break;
            case 4:
                myComplexObject.Divide();
                break;
            default:
                System.out.println("INVALID INPUT!");

        }
        

    }
}
