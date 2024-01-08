package com.fifthquestion;

import java.util.HashMap;

class Item {
    String name, itemId;
    int price;
    public Item(String name, String itemId, int price){
        this.name = name;
        this.itemId = itemId;
        this.price = price;
    }
    public String getName() {
        return name;
    }
    public String getItemId() {
        return itemId;
    }
    public int getPrice() {
        return price;
    }
}

public class ItemDatabase {
    HashMap<String, Item> item_database = new HashMap<>();
    public ItemDatabase(){
        item_database.put("1", new Item("Item 1", "1", 100));
        item_database.put("2", new Item("Item 2", "1", 200));
        item_database.put("3", new Item("Item 3", "1", 300));
        item_database.put("4", new Item("Item 4", "1", 400));
        item_database.put("5", new Item("Item 5", "1", 240));
    }
    public void displayItems(){
        item_database.forEach((key, value) -> {
            System.out.print("Key: " + key + " Name: " + value.getName() + " Item ID: " + value.getItemId() + " Price: " + value.getPrice() + "\n");
        });
    }
    public Item getItemDetails(String key){
        return item_database.get(key);
    }
}
