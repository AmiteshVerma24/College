import java.util.*;

class Employee {
    private String name, payscale, address, gender;
    private int age, number_of_family_members;
    public Employee(String name, String payscale, String address, String gender, int age, int number_of_family_members) {
        this.name = name;
        this.payscale = payscale;
        this.address = address;
        this.gender = gender;
        this.age = age;
        this.number_of_family_members = number_of_family_members;
    }
    public String getName(){
        return name;
    }
    public String getPayscale(){
        return payscale;
    }
    public String getAddress(){
        return address;
    }
    public String getGender(){
        return gender;
    }
    public int getAge(){
        return age;
    }
    public int getNumberOfFamilyMembers(){
        return number_of_family_members;
    }
    public String getDetails(){
        return "Name: " + name + " Payscale: " + payscale + " Address: " + address + " Gender: " + gender + " Age: " + age + " Family Members: " + number_of_family_members + "\n";
    }
}

public class EmployeeDatabase {
    private int uid = 0;
    private HashMap<Integer, Employee> db = new HashMap<>();

    public String addEmployee(String name, String payscale, String address, String gender, int age, int number_of_family_members) {
        if (age > 60 || age < 22) return "Invalid age!";
        Employee emp = new Employee(name, payscale, address, gender, age, number_of_family_members);
        db.put(uid, emp);
        uid++;
        return "New employee added successfull!";
    }
    public String getEmployeeDetails(){
        StringBuilder strbuilder = new StringBuilder();
        db.forEach((key, value) -> {
            strbuilder.append(value.getDetails());
        });
        return strbuilder.toString();
    }
}
