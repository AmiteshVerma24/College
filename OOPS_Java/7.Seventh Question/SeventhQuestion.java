
package OOPS_Java;

/* Create a Personal class to hold the personal details of a person such as name, age, education,salary- (basic, da, hra), years of experience, number of loans and loan amount. Write constructors to assign values to the data members. Include an
a. isEligible () method to indicate whether the person is eligible for loan,
b. taxPay () method to indicate the amount of tax to be paid,
c. isEligiblePromotion () to indicate whether the person is eligible for a promotion.
d. Display () method to display the details.
Enter the details of n employees and indicate their eligibility and the tax to be paid.
 */
import java.util.*;

class SeventhQuestion {
    public String name;
    public String education;
    public int salary, experience, numLoans, loanAmt, age;

    // Constructor
    public SeventhQuestion(String name, String education, int salary, int experience, int numLoans, int loanAmt,
            int age) {
        this.name = name;
        this.education = education;
        this.salary = salary;
        this.experience = experience;
        this.numLoans = numLoans;
        this.loanAmt = loanAmt;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    // Loan eligibility
    public void isEligible() {
        if (age > 18) {
            System.out.println("The person is eligible for loan.");
        } else {
            System.out.println("The person is not eligible for loan.");
        }
    }

    // Amount of tax to be paid
    public void taxPay() {
        // Rules for tax pay
        // 0 <= Salary < 10,00,000 ==> 20%
        // 1,000,000 <= Salary < 50,00,000 ==> 30%
        // >= 50,00,000 ==> 40%
        double amountToPay;
        if (salary * 12 < 1000000) {
            amountToPay = salary * 0.2;
        } else if (salary * 12 < 5000000) {
            amountToPay = salary * 0.3;
        } else {
            amountToPay = salary * 0.4;
        }

        System.out.println("The tax amount is " + amountToPay);
    }

    // Eligibility for promotion
    public void isEligiblePromotion() {
        // Rules
        // If work experience > 2 ==> Eligible
        if (experience > 2) {
            System.out.println("Eligible for promotion");
        } else {
            System.out.println("Not eligible for promotion");
        }
    }

    // Main function
    public static void main(String args[]) {
        SeventhQuestion person = new SeventhQuestion("Amitesh", "Btech", 100000, 1, 0, 1000, 19);
        System.out.println(person.getName());
        System.out.println(
                "What would you like to do \n 1. Check eligiblity for loan \n 2. Check amount of tax to be paid \n 3. Check eligiblity for promotion");
        Scanner sc = new Scanner(System.in);
        int opt = sc.nextInt();
        switch (opt) {
            case 1:
                person.isEligible();
                break;
            case 2:
                person.taxPay();
                break;
            case 3:
                person.isEligiblePromotion();
                break;
            default:
                System.out.println("INVALID CHOICE!");
        }
    }
}