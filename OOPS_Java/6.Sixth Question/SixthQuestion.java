// Write a java program to work with strings.
// a. Extract a portion of the string and print it. Variable m indicates the amount
// of characters to be extracted from the string starting from the nth position.
// b. Read a text and count all the occurrences of a particular word.
// c. Replace a substring in the given string.
// d. Rearrange the string and rewrite in alphabetical order.
// e. Compare two strings ignoring case.
// f. Concatenate two strings.
import java.util.*;

// Class to handle all the strings functions

class MyStrings{
    String myStr;
    public MyStrings(String str){
        // Taking and setting up the string to work with
        this.myStr = str;
    }
    public void extractPart(int m , int n){
        System.out.format("The string obtained by extracting %d characters from %d position from %s is: ",m,n,this.myStr);
        System.out.format("%s\n",this.myStr.substring(m, m+n));
    }
    public void count_occurrences_word(String word){
        int count = 0;
        String [] arrString = this.myStr.split(" ");
        for (int i = 0 ; i < arrString.length; i++){
            if (arrString[i].equals(word)){
                count++;
            }    
        }
        System.out.format("The count of %s is: %d\n",word,count);
    }
    public void replace_substring(String word, String new_word){
        String[] arrString = this.myStr.split(" ");
        for (int i = 0 ; i < arrString.length ; i++){
            if (arrString[i].equals(word)){
                arrString[i] = new_word;
            }
        }
        for (int i = 0 ; i < arrString.length ; i++){
            System.out.format("%s ",arrString[i]);
        }
        System.out.println();
    }
    public void rearrange_alphabetical_order(){
        int len = this.myStr.length();
        char[] charArr = this.myStr.toCharArray();
        for (int i = 0 ; i < len ; i++){
            for (int j = i+1 ; j < len ; j++){
                if(charArr[i] > charArr[j]){
                    char temp = charArr[i];
                    charArr[i] = charArr[j];
                    charArr[j] = temp;
                }
            }
        }
        System.out.print("The rearranged string is: ");
        for(int i = 0 ; i < charArr.length ; i++){
            System.out.format("%c",charArr[i]);
        }
        System.out.println();
    }
    public void compare_two_strings(String str1 , String str2){
        if(str1.toLowerCase().equals(str2.toLowerCase())){
            System.out.println("The two strings are identical.");
        }else{
            System.out.println("The two strings are not identical.");
        }
    }
    public void concatenate_two_strings(String str1, String str2){
        String newString = new String();
        newString = str1 + str2;
        System.out.format("The string after concatenation is %s.",newString);
    }
    public static void main(String[] args) {
        // Scanner to take the input
        Scanner sc = new Scanner(System.in);
        // To hold the input
        String str = new String();
        System.out.print("Enter the string: ");
        str = sc.nextLine();
        System.out.println(str);
        // Creating the object
        MyStrings myStr = new MyStrings(str);
        myStr.extractPart(1, 5);
        myStr.count_occurrences_word("is");
        myStr.replace_substring("is", "it");
        myStr.compare_two_strings("str", "sTr");
        myStr.concatenate_two_strings("str", "asmfl");
        myStr.rearrange_alphabetical_order();
        sc.close();
    }
}
