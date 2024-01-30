import java.util.*;
// Create an array list of Students (with fields such as name, USN, Dept, section, CGPA). Search for the students with
// CGPA > 8.5. Print the student details belonging to ‘ISE’ department. Print students belonging to ‘C’ section. Use
// Iterator to iterate through the list.

public class Question1 {
    private static class Student{
        String name, usn, department, section;
        float cgpa;
        public Student(String name, String usn, String department, String section, float cgpa){
            this.name = name;
            this.usn = usn;
            this.department = department;
            this.section = section;
            this.cgpa = cgpa;
        }
    }
    public static void CGPA(ArrayList<Student> arr){
        Iterator<Student> itr = arr.iterator();
        System.out.println("Students with CGPA greater than 8.5:- ");
        while (itr.hasNext()) {
            Student element = itr.next();
            if(element.cgpa > 8.5){
                System.out.format("Name:- %s\nUSN:- %s\nDepartment:- %s\nSection:- %s\nCGPA:- %f\n____________________________________________________\n",
                        element.name, element.usn, element.department, element.section, element.cgpa);
            }
        }
    }
    public static void CSection(ArrayList<Student> arr){
        Iterator<Student> itr = arr.iterator();
        System.out.println("Students in C section:- ");
        itr = arr.iterator();
        while (itr.hasNext()) {
            Student element = itr.next();
            if(element.section.equalsIgnoreCase("C")){
                System.out.format("____________________________________________________\nName:- %s\nUSN:- %s\nDepartment:- %s\nSection:- %s\nCGPA:- %f\n____________________________________________________\n",
                        element.name, element.usn, element.department, element.section, element.cgpa);
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> arr = new ArrayList<>();
        boolean isContinue = true;
        while(isContinue){
            System.out.print("Do you want to add details?\n 1. Yes\n 2. No\nYour choice: ");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter name of student: ");
                    sc.nextLine(); // Consume the newline character
                    String name = sc.nextLine();
                    System.out.print("Enter USN of student: ");
                    String usn = sc.nextLine();
                    System.out.print("Enter department of student: ");
                    String department = sc.nextLine();
                    System.out.print("Enter section of student: ");
                    String section = sc.nextLine();
                    System.out.print("Enter CGPA of student: ");
                    float cgpa = sc.nextFloat();
                    Student st = new Student(name, usn, department, section, cgpa);
                    arr.add(st);
                    break;
                case 2:
                    isContinue = false;
                    break;
                default:
                System.out.println("Not valid input");
                    break;
            }
        }

        CGPA(arr);
        CSection(arr);
        sc.close();
    }

}
