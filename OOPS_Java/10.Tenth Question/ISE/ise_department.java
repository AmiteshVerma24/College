package ISE;
import java.util.Scanner;

public class ISE_department extends faculty implements department {
    @Override
    public void readdata() {
        // Defining the scanner object to take input
        Scanner sc = new Scanner(System.in);
        // Taking number of faculties of the department as input
        System.out.print("Enter the number of faculties in ISE department:- ");
        this.number_of_faculty = sc.nextInt();
        // Creating an array to store their details
        this.faculty_list = new faculty[this.number_of_faculty];
        for (int i = 0 ; i < this.number_of_faculty ; i++){
            this.faculty_list[i] = new faculty();
        }
        // Taking user input
        for (int i = 0 ; i < this.number_of_faculty ; i++){
            // Variables to hold the data
            System.out.format("\nEnter the details of faculty number %d:- \n",i+1);
            System.out.format("Name:- ");
            name = sc.next();
            System.out.format("Designation:- ");
            designation = sc.next();
            System.out.format("Joining date:- ");
            joining_date = sc.next();
            System.out.format("Age:- ");
            age = sc.nextInt();
            System.out.format("Years of experience:- ");
            years_of_experience = sc.nextInt();
            System.out.format("Number of subjects handled:- ");
            number_of_subjects_handled = sc.nextInt();
            System.out.format("Number of Designations:- ");
            number_designations = sc.nextInt();
            System.out.format("Number of research consultancy projects:- ");
            number_research_consultancy_projs = sc.nextInt();
            System.out.println("Enter the Subjects handled by the faculty in order");
            // Initializing the array to store the names of subjects handled
            subjects_handled = new String[number_of_subjects_handled];
            for (int j = 0 ; j < number_of_subjects_handled ; j++){
                System.out.format("     Subject %d:- ",j+1);
                subjects_handled[j] = sc.next();
            }
        faculty_list[i].set_data(name, designation, joining_date, subjects_handled, age, years_of_experience, number_of_subjects_handled, number_designations, number_research_consultancy_projs);
        }
        sc.close();
    }
    @Override
    public void printdata() {
        for (int i = 0 ; i < this.number_of_faculty ; i++){
            System.out.format("\n********* FACULTY - %d *********\n",i+1);
            System.out.format("Name:- %s\n",this.faculty_list[i].name);
            System.out.format("Designation:- %s\n",this.faculty_list[i].designation);
            System.out.format("Joining date:- %s\n",this.faculty_list[i].joining_date);
            System.out.format("Age:- %d\n",this.faculty_list[i].age);
            System.out.format("Years of experience:- %d\n",this.faculty_list[i].years_of_experience);
            System.out.format("Number of subjects handled:- %d\n",this.faculty_list[i].number_of_subjects_handled);
            System.out.format("Number of Designations:- %d\n",this.faculty_list[i].number_designations);
            System.out.format("Number of research consultancy projects:- %d\n",this.faculty_list[i].number_research_consultancy_projs);
            System.out.println("The Subjects handled by the faculty in order are:-");
            for (int j = 0 ; j < number_of_subjects_handled ; j++){
                System.out.format(" Subject %d:- %s\n",j+1,subjects_handled[j]);
            }
            System.out.print("========================================\n");
        }
    }
    @Override
    public void print_number_designations() {
        int total = 0;
        for(int i = 0 ; i < this.number_of_faculty ; i++){
            total += this.faculty_list[i].number_designations;
        }
        System.out.format("\nThe number of designations is:- %d\n",total);
    }
    @Override
    public void number_research_consultancy_projs() {
        int total = 0;
        for(int i = 0 ; i < this.number_of_faculty ; i++){
            total += this.faculty_list[i].number_research_consultancy_projs;
        }
        System.out.format("\nThe number of research consultancy projects is:- %d\n",total);
        
    }
}