package com.fourthquestion;
import java.util.HashMap;

class Student {
    String name, usn, address, category;
    int age;
    float sgpa;
    public Student(String name, String usn, String address, String category, int age, float sgpa){
        this.name = name;
        this.usn = usn;
        this.address = address;
        this.category = category;
        this.age = age;
        this.sgpa = sgpa;
    }
    public String getName(){
        return name;
    }
    public String getUsn(){
        return usn;
    }
    public String getAddress(){
        return address;
    }
    public String getCategory(){
        return category;
    }
    public int getAge(){
        return age;
    }
    public float getSgpa(){
        return sgpa;
    }
    public String getDetails(){
        return "Name: " + name + ", USN: " + usn + ", Address: " + address + ", Category: " + category
                + ", Age: " + age + ", SGPA: " + sgpa +"\n";
    }
}
public class StudentDatabase {
    HashMap<Integer, Student> db = new HashMap<>();
    int uid = 0;

    public String insertStudent(String name, String usn, String address, String category, int age, float sgpa){
        if(!(age > 18 && age <= 30)){
            return "Invalid age!";
        }
        if(!(sgpa >= 0 && sgpa <= 10)){
            return "Invalid SGPA!";
        }
        Student new_student = new Student(name, usn, address, category, age, sgpa);
        db.put(uid, new_student);
        uid = uid + 1;
        return "Student details updated";
    }
    public String displayStudents(){
        String  str_to_return;
        StringBuilder strBuilder = new StringBuilder();
        db.forEach((key, value) -> {
            System.out.println(key);
            System.out.println(value.getDetails());
            strBuilder.append(value.getDetails());
        });
        str_to_return = strBuilder.toString();
        return str_to_return;
    }
}
