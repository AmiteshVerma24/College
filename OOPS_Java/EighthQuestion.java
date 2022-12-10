package OOPS_Java;
/* 
8. Create a Circle class with following members.
A data member that stores the radius of a circle.
A constructor function with an argument that initializes the radius
A function that computes and returns area of a circle
Create two derived classes Sector and Segment that inherit the Circle class. Both classes inherit radius and the function that returns the circle’s area from Circle.
In addition to the members inherited from Circle, Sector and Segment have some specific members as follows:
Sector
1. A data member that stores the control angle of a sector (in radians) 2. A constructor function with arguments that initialize radius and angle 3. A function that computes and returns the area of a sector
Segment
1. A data member that stores the length of a segment in a circle
2. A constructor function with arguments that initialize radius and length 3. A function that computes and returns the area of a segment
Create the main () function to instantiate an object of each class and then call appropriate member functions to compute and return the area of a circle, sector and segment.
Note: Area_of_circle = pi * r 2
Area_of_Sector= (1/2) r 2 *θ
Area_of_segment= r2 *((r-h)/r) – (r-h) (2rh-h2)1/2 Where r is the radius of a circle, θ is the central angle of a sector in radians, h is the length of a segment and ((r-h)/r) is in radians. */

// Imports
import java.util.Scanner;
import java.lang.Math;

// Circle class
class Circle{
    // Variables
    public double radius;
    // Constructor
    public Circle(double radius){
        this.radius = radius;
    }
    // Function to compute the area
    public double findArea(){
        return (3.14 * radius * radius);
    }

}
// Sub-class Sector
class Sector extends Circle{
    // Variables
    double angle;
    // Constructor
    public Sector(double angle, double radius){
        // Super class constructor
        super(radius);
        // Sub-class constructor
        this.angle = angle;
    }
    // Area of sector
    public double areaOfSector(){
        return (0.5*super.radius*super.radius*angle);
    }
}
// Sub-class Segment
class Segment extends Circle{
    // Variables
    double length;
    // Constructors
    public Segment(double length , double radius){
        super(radius);
        this.length = length;
    }
    // Area of segment
    public double areaOfSegment(){
        double theta = (radius - length) / radius;
        return (radius*radius*theta) - (radius-length)*Math.sqrt(2*radius*length-length*length);
    }
}
public class EighthQuestion {
    public static void main(String[] args) {
        // Scanner object and variables
        Scanner sc = new Scanner(System.in);
        double radius, angle, length;
        // Asking the user for the radius and othe inputs
        System.out.print("Enter the radius of the circle: ");
        radius = sc.nextDouble();
        System.out.print("Enter the angle of sector: ");
        angle = sc.nextDouble();
        System.out.print("Enter the length of segment: ");
        length = sc.nextDouble();
        // Creating new Circle object
        Circle myCircle = new Circle(radius);
        System.out.print("The area of circle is: ");
        System.out.println(myCircle.findArea());
        // Creating sector object
        Sector mySector = new Sector(angle, radius);
        System.out.print("The area of sector is: ");
        System.out.println(mySector.areaOfSector());
        // Creating segment object
        Segment mySegment = new Segment(length, radius);
        System.out.print("The area of segment is: ");
        System.out.println(mySegment.areaOfSegment());
    }
}
