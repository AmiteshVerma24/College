### 1. `for` Loop:
The `for` loop in Swift is used to iterate over a sequence, such as a range of numbers or an array.

**Example:**
```swift
// Iterate over a range of numbers
for i in 1...5 {
    print(i)
}

// Iterate over an array
let fruits = ["Apple", "Banana", "Orange"]
for fruit in fruits {
    print(fruit)
}
```

In the first loop, it prints numbers from 1 to 5, inclusive. In the second loop, it prints each element of the `fruits` array.

### 2. `while` Loop:
The `while` loop repeats a block of code as long as a certain condition is true.

**Example:**
```swift
var counter = 0

while counter < 5 {
    print("Counting: \(counter)")
    counter += 1
}

// Repeat while
var count = 0
var roll = 0
repeat {
 roll = Int.random(in: 0...5)
 count += 1
 print("After rolls \(count), roll is \(roll)")
} while roll > 0 
```

This loop prints the counting values from 0 to 4 because it stops when the condition `counter < 5` becomes false.

### 3. `if`-`else` Statement:
The `if` statement is used to perform conditional execution of code based on a certain condition. Optionally, it can be followed by an `else` statement to handle the opposite case.

**Example:**
```swift
let temperature = 25

if temperature > 30 {
    print("It's a hot day!")
} else if temperature >= 20 {
    print("It's a nice day.")
} else {
    print("It's a bit chilly.")
}
```

This example prints different messages based on the value of the `temperature` variable.

### 4. `switch` Statement:
The `switch` statement is used to select one of many possible code blocks to execute based on the value of an expression.

**Example:**
```swift
let dayOfWeek = "Wednesday"

switch dayOfWeek {
case "Monday", "Tuesday", "Wednesday", "Thursday", "Friday":
    print("It's a weekday.")
case "Saturday", "Sunday":
    print("It's a weekend.")
default:
    print("Invalid day.")
}
```

This switch statement checks the value of `dayOfWeek` and prints whether it's a weekday, weekend, or an invalid day.

### 5. Arrays in Swift:

An array in Swift is an ordered collection of values of the same type. You can use arrays to store and retrieve a sequence of values efficiently.

#### Declaring an Array:
```swift
// Array of integers
var numbers: [Int] = [1, 2, 3, 4, 5]

// Array of strings using shorthand syntax
var fruits = ["Apple", "Banana", "Orange"]
```

#### Accessing Elements:
```swift
let firstNumber = numbers[0] // Accessing the first element
let secondFruit = fruits[1] // Accessing the second element
```

#### Modifying Arrays:
```swift
numbers.append(6) // Adding an element to the end
fruits += ["Grapes", "Mango"] // Concatenating arrays

numbers[2] = 10 // Modifying an element at a specific index
fruits[0] = "Kiwi" // Modifying an element at a specific index

numbers.remove(at: 3) // Removing the element at index 3
fruits.removeLast() // Removing the last element
```

#### Iterating Over Arrays:
```swift
for number in numbers {
    print(number)
}

for fruit in fruits {
    print(fruit)
}
```

#### Array Indexing and Ranges:
```swift
let firstThreeNumbers = numbers[0..<3] // Subarray containing elements at index 0, 1, and 2

let lastTwoFruits = fruits[3...] // Subarray containing elements from index 3 to the end

let reversedNumbers = numbers.reversed() // Reversed array
```

### Array Indexing:

In Swift, array indexing starts from 0. The first element is at index 0, the second at index 1, and so on.

```swift
let firstElement = numbers[0] // Accessing the first element
let secondElement = numbers[1] // Accessing the second element
```

Remember that attempting to access an element at an index that is out of bounds will result in a runtime error. You can check the array's `count` property to ensure you don't go beyond its bounds.

```swift
if index < numbers.count {
    let value = numbers[index]
    // Do something with the value
} else {
    print("Index out of bounds")
}
```

