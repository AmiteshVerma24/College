import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        // First entry = Ph.no, Second entry = Name
        HashMap<String, String> call_log = new HashMap<>();
        // Adding missed calls
        addMissedCall(call_log, "123", "Amitesh");
        addMissedCall(call_log, "456", "Aditya");
        addMissedCall(call_log, "789", null);
        // Display names that start with A
        System.out.println(call_log);
        nameStartWithA(call_log);
        deletePhoneCall(call_log, "456");
        System.out.println(call_log);
        displayPhoneCall(call_log, "123");
    }
    private static void addMissedCall(HashMap<String, String> call_log, String number, String name){
        name = (name == null) ? "Private caller" : name;
        call_log.put(number, name);
    }
    private static void nameStartWithA(HashMap<String, String> call_log){
        System.out.println("Names of caller starting with A are: ");
        call_log.forEach((key, value) -> {
            if(value.startsWith("A") || value.startsWith("a")){
                System.out.println("Name: " + value + ", Number: " + key);
            }
        });
    }
    private static void deletePhoneCall(HashMap<String, String> call_log, String key){
        System.out.format("Deleting details of call with:\n Name: %s\n Number: %s\n",call_log.get(key),key);
        call_log.remove(key);
    }
    private static void displayPhoneCall(HashMap<String, String> call_log, String key){
        System.out.format("Displaying details of call with:\n Name: %s\n Number: %s\n",call_log.get(key),key);
    }
}
