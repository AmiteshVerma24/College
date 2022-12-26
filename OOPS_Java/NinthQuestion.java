package OOPS_Java;

/*
Write a Java Program that does the following related to Inheritance:
a. Create an abstract class called Vehicle which contains the
‘year_of_manufacture’ data member and two abstract methods ‘getData ()’ and
‘putData ()’ with a constructor.
b. Create two derived classes “TwoWheeler” and “FourWheeler” and implement
the abstract methods. Make “FourWheeler” as final class.
c. Create class ‘MyTwoWheeler’ which is a sub-class of “TwoWheeler” and
demonstrate the use of super keyword to initialize data members of “MyTwoWheeler”. 
*/

// Base class
abstract class Vehicle{
    // Data members
    int year_of_manufacture;
    // Abstract methods
    abstract int getData();
    abstract void putData(int yr);
}
// Child class
class TwoWheeler extends Vehicle{
    int year;
    String name;
    // Constructor
    TwoWheeler(int yr){
        super.year_of_manufacture = yr;
    }
    // Implementation of abstract classes
    @Override
    public void putData(int yr){
        super.year_of_manufacture = this.year;
        System.out.format("The year of manufacture of Super class is %d", super.year_of_manufacture);
    }
    @Override
    public int getData(){
        return super.year_of_manufacture;
    }
}

final class FourWheeler extends Vehicle{
    int year;
    // Constructor
    FourWheeler(int yr){
        super.year_of_manufacture = yr;
    }
    // Implementation of abstract classes
    @Override
    public void putData(int yr){
        super.year_of_manufacture = this.year;
        System.out.format("The year of manufacture of Super class is %d", super.year_of_manufacture);
    }
    @Override
    public int getData(){
        return super.year_of_manufacture;
    }
}

// Grandchild class
class MyTwoWheeler extends TwoWheeler{
    // Data members
    int yr;
    // Constructors
    MyTwoWheeler(int yr, String name){
        super(yr);
        super.name = name;
    }
    // Methods
    public String printName(){
        return super.name;
    }

}
public class NinthQuestion {
    public static void main(String[] args) {
        // Creating objects
        TwoWheeler tw = new TwoWheeler(1990);
        FourWheeler fw = new FourWheeler(1996);
        MyTwoWheeler myScooty = new MyTwoWheeler(1960,  "Activa");
        // Calling the functions

        // Using the getData() to fetch year of manufacture of two wheeler and four wheeler
        System.out.format("Year of manufacture of two wheeler is %d\n", tw.getData());
        System.out.format("Year of manufacture of four wheeler is %d\n", fw.getData());

        // Getting details of my two wheeler
        System.out.format("Year of manufacture of my two wheeler is %d\n", myScooty.getData());
        System.out.format("Name of my two wheeler is %s\n",myScooty.printName());
    }
}
