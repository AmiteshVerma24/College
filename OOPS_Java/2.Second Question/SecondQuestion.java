package OOPS_Java;
import java.util.*;
/* Create a class called account with the data members (Accno – integer, name String, Phone_No: integer, balance_amt: float), and following methods:
a. getinput () to get input from the user
b. Deposit () method which takes the amount to be deposited in to his/her account and
do the calculation.
c. Withdraw () method which gets the amount to be withdrawn from his/her account. 
d. Print the appropriate results. */
class Account{
    // Declaring Variables
    private int accNum;
    private long phoneNum;
    private float balance;
    private String name;
    
    // Constructors
    Account(){
        this.accNum = 0;
        this.phoneNum = 0;
        this.balance = 0;
    }
    // getInput() to take input from the user
    public void getInput(){
        // Scanner object
        Scanner sc = new Scanner(System.in);
        // Taking input from the user
        System.out.print("Enter the name of Acoount holder: ");
        this.name = sc.nextLine();
        System.out.print("Enter the account number: ");
        this.accNum = sc.nextInt();
        System.out.print("Enter the phone number: ");
        this.phoneNum = sc.nextInt();
        System.out.print("Enter the balance: ");
        this.balance = sc.nextInt();
    }
    // Deposit() to deposite a given amount to the account
    public void deposite(float depositAmount){
        System.out.format("The old balance was: %f \n",this.balance);
        this.balance += depositAmount;
        System.out.format("The new balance was: %f \n",this.balance);
    }
    // Withdraw() to withdraw amount from bank account
    public void withdraw(float withdrawAmount){
        if (withdrawAmount <= this.balance){
            System.out.format("The old balance was: %f \n",this.balance);
            this.balance -= withdrawAmount;
            System.out.format("The new balance was: %f \n",this.balance);
        } else{
            System.out.println("INSUFFICIENT BALANCE!");
        }
    }
    // ViewDetails() to view the details of account
    public void viewDetails(){
        System.out.format("\n Account holder name: %s \n",this.name);
        System.out.format("Account number: %s \n",this.accNum);
        System.out.format("Account balance: %s \n",this.balance);
        System.out.format("Holder's phone number: %s \n",this.phoneNum);
    }
}
public class SecondQuestion {
    public static void main(String[] args) {
        // New scanner object
        Scanner sc = new Scanner(System.in);
        // Variables
        int choice;
        float amt;
        // Creating new account object
        Account myAccount = new Account();
        // Taking input from the user
        myAccount.getInput();
        // Asking user for input
        System.out.println("What would you like to do: \n 1. Deposit \n 2. Withdraw \n 3. View details");
        System.out.print("Enter your choice: ");
        choice = sc.nextInt();
        // Using switch to present a menu drive program
        switch (choice) {
            case 1:     
                System.out.print("Enter the amount you want to deposit to bank: ");
                amt = sc.nextInt();
                myAccount.deposite(amt);
                break;
            case 2:
                System.out.print("Enter the amount you want to withdraw from bank: ");
                amt = sc.nextInt();
                myAccount.withdraw(amt);
                break;
            case 3:
                myAccount.viewDetails();
                break;
            default:
                System.out.println("INVALID CHOICE");
        }   
    }
}
