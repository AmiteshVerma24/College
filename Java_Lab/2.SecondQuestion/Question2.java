import java.util.*;

// Write a Program that simulates a telephone that records missed incoming calls in
// lists. Maintain the phone callers list in hashmap . For each missed call , telephone
// number of origin, and name of the caller if the name is available. For unlisted
// numbers, set the name to “private caller”. Missed calls have to be maintained in the
// order they arrive. User goes through the missed call list and can decide to delete the
// call or display the call details.

public class Question2 {
    public static void main(String[] args) {
        // First entry = Ph.no, Second entry = Name
        HashMap<String, String> call_log = new HashMap<>();
        // Adding missed calls
        addMissedCall(call_log, "123", "Amitesh");
        addMissedCall(call_log, "456", "Aditya");
        addMissedCall(call_log, "46", "Binod");
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
        System.out.println("Displaying details of people whose name start with A");
        call_log.forEach((number, name) -> {
            if(name.startsWith("A") || name.startsWith("a")){
                System.out.format("Name:- %s and Number:- %s\n",name,number);
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
