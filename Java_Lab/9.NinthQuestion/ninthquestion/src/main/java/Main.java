import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class Main {
    private static String URL = "jdbc:mysql://localhost:3306/java";
    private static String USERNAME = "root";
    private static String PASSWORD = "your_password";

    public static Connection getConnection() throws SQLException{
        return DriverManager.getConnection(URL,USERNAME,PASSWORD);
    }
    public static String displayPatientDetails() {
        try{
            Connection connection = getConnection();
            String str = "select * from patient";
            PreparedStatement statement = connection.prepareStatement(str);
            ResultSet set = statement.executeQuery();
            StringBuilder builder = new StringBuilder();
            while (set.next()){
                String row = "Name: " + set.getString("name") + " ,Medicine: " + set.getString("medicine") + " ,Treatment: " + set.getString("medicine") + "\n";
                builder.append(row);
            }
            System.out.println(builder);
            return builder.toString();

        }catch(Exception e){
            System.out.println("Error: " + e);
        }
        return "Fetch done";
    }
    public static String insertIntoPatient(String name, String medicine, String treatment) {
        try {
            Connection connection = getConnection();
            String str = "INSERT INTO patient (name,medicine,treatment) values" + "('" + name + "', '" + medicine + "','" + treatment + "')";
            PreparedStatement query = connection.prepareStatement(str);
            int rows = query.executeUpdate();
            if(rows > 0) {
                System.out.println("New patient added");

            }else{
                System.out.println("Failed to add new user");
                return "Failed to add new user";
            }
            return "New patient added";

        }catch (Exception e){
            System.out.println("Error: " + e);
        }
        return "Insertion attempted";
    }
    public static void main(String[] args)  {
//        insertIntoPatient("Amitesh","Vitamin D", "Sunlight");
        displayPatientDetails();
    }
}
