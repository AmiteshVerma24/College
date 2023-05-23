package ISE;

// Faculty class
public class faculty{
    // The variables of the faculty class
    public String name, designation, joining_date;
    public int age, years_of_experience, number_of_subjects_handled,number_designations,number_research_consultancy_projs;
    public String[] subjects_handled;

    // Variables for the ise department
    public int number_of_faculty;
    // Declaring an array of type faculty to store the details if the various faculties of ise department
    public faculty [] faculty_list;
    // Method to set data
    public void set_data(String name,String designation,String joining_data,String [] subjects_handled,int age,int years_of_experience,int number_of_subjects_handled,int number_designations,int number_research_consultancy_projs){
        this.name = name;
        this.designation = designation;
        this.joining_date = joining_data;
        this.subjects_handled = subjects_handled;
        this.age = age;
        this.years_of_experience = years_of_experience;
        this.number_of_subjects_handled = number_of_subjects_handled;
        this.number_designations = number_designations;
        this.number_research_consultancy_projs = number_research_consultancy_projs;
    }
}
