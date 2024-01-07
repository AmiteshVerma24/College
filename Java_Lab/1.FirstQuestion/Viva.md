1. Java ArrayList is a part of the Java collection framework and it is a class of java.util package.
2. It provides us with dynamic arrays in Java. 
3. Main advantage is that we don't need to define the size it resizes itself automatically. It happens in the following steps
```ArrayList<Integer> list = new ArrayList();```
4. It allows duplicates
    - Creates a bigger-sized memory on heap memory (for example memory of double size).
    - Copies the current memory elements to the new memory.
    - The new item is added now as there is bigger memory available now.
    - Delete the old memory.
5. Basic operations
    - add(Object), add(int index, Object): Used to add an element
    - set(int index, Object): Used to update the array list
    - remove(Object), remove(int index): Used to remove an object
    - get(int index): Used to retrive an Object from array list
    - size(): Used to get length of array list
6. Using iterator
```
ArrayList<String> arrayList = new ArrayList<>();
// Add elements to the ArrayList
arrayList.add("Apple");
arrayList.add("Orange");
arrayList.add("Banana");
arrayList.add("Grapes");
// Obtain an Iterator from the ArrayList
Iterator<String> iterator = arrayList.iterator();
// Iterate through the ArrayList using the Iterator
System.out.println("Iterating through the ArrayList using Iterator:");
while (iterator.hasNext()) {
    String element = iterator.next();
    System.out.println(element);
}
```