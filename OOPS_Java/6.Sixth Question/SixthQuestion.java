// package OOPS_Java;
import java.util.*;

public class SixthQuestion {
    // Variable to hold the string
    public String myString;
    // Scanner object
    public static Scanner sc = new Scanner(System.in);
    //
    public char[] arr;
    // Constructor
    public SixthQuestion(){
        System.out.println("Enter the String");
        myString = sc.nextLine();
        System.out.println(myString);
        // Creating array of string length to store it as an array
        // char[] arr = new char[myString.length()];
        // Copy character by character into array
        for (int i = 0; i < myString.length(); i++) {
            arr[i] = myString.charAt(i);
        }
        
    }
    // Extracting a portion of string
    public void takePortion(int m , int n){
        // Printing the string
        for (int i = n - 1; i <= m+n-2 ; i++){
            System.out.print(arr[i]);
        }
    }

    public static void main(String[] args) {
        // Creating object of class
        SixthQuestion myStr = new SixthQuestion();
        // Asking the user for choices
        System.out.println("What would you like to do? \n 1. Extract a portion \n 2. Count occurences of a particular word \n 3. Replace a substring with a given string \n 4. Rearrange the string in alphabetical order \n 5. Compare two strings \n 6. Concatenate two strings");
        System.out.print("\n Enter your choise: ");
        int option = sc.nextInt();
        // Switching based on entered choice
        switch (option){
            case 1:
                int m,n;
                System.out.print("Enter the nth position of above string: ");
                n = sc.nextInt();
                System.out.format("Enter how many characters to extrace from %d th position: ",n);
                m = sc.nextInt();
                myStr.takePortion(m, n);
                break;
            default:
                System.out.println("INVALID CHOICE!");
        }
    }
}
