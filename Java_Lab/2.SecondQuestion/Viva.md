1. HashMap in Java stores the data in (Key, Value) pairs, and you can access them by an index of another type (e.g. an Integer). One object is used as a key (index) to another object (value).
2. If you try to insert the duplicate key in HashMap, it will replace the element of the corresponding key. 
```
HashMap<String, Integer> map = new HashMap<>();
// Adding elements to the Map
map.put("vishal", 10);
map.put("sachin", 30);
map.put("vaibhav", 20);
```
3. It takes two parameters namely as follows:
    - The type of keys maintained by this map
    - The type of mapped values
4. A HashMap is a data structure that is used to store and retrieve values based on keys.
5. Basic operations
    - put(key,value): Add an element / To update the value of same key
    - remove(key): Used to remove an element with the specified key
6. Traversal
    - Using iterator
    ```
        HashMap<String, Integer> hashMap = new HashMap<>();
        // Add elements to the hashmap...
        Iterator<Map.Entry<String, Integer>> iterator = hashMap.entrySet().iterator();
        while (iterator.hasNext()) {
        Map.Entry<String, Integer> entry = iterator.next();
        String key = entry.getKey();
        Integer value = entry.getValue();
        // Process key and value here...
        }
    ```
    - Using foreach
    ```
        HashMap<String, Integer> hashMap = new HashMap<>();
        // Add elements to the hashmap...
        hashMap.forEach((key, value) -> {
            // Process key and value here...
        });
    ```


