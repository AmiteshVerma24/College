// a. Write a java program to implement queues of Strings using an ArrayList
// class of the Collection framework.
// b. Create a linked list of names (String type). Use an Iterator to traverse through
// the list and print those names whose length is < 5
import java.util.*;

class queue {
    ArrayList<String> queue = new ArrayList<String>(100);
    int rear,front;
    public void enqueue(){
        Scanner sc = new Scanner(System.in);
        String str = new String();
        System.out.print("Enter the string to enter:- ");
        str = sc.nextLine();
        if(queue.isEmpty()){
            System.out.format("The queue was empty.Inserting:- %s.\n",str);
            rear++;
            front++;
            queue.add(rear, str);
        }else{
            System.out.format("Inserting:- %s.\n",str);
            rear++;
            queue.add(rear, str);
        }
    }
    public void dequeue(){
        if(queue.isEmpty()){
            System.out.println("Can't remove the list is empty!\n");
        }else if(rear == front){
            System.out.format("Removing %s\n",queue.remove(front));
            front = -1;
            rear = -1;
        }else{
            System.out.format("Removing %s\n",queue.remove(front));
            front++;
        }
    }
    public void display(){
        for(int i = front ; i <= rear ; i++){
            System.out.format("%s--->",queue.get(i));
        }
    }
    public static void main(String[] args) {
        queue q = new queue();
        q.enqueue();
        q.enqueue();
        q.enqueue();
        q.display();
        q.dequeue();
        q.display();
    }
}
