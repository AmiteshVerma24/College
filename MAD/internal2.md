# Swift basics
1. Variable declaration
2. Variable shadowing
3. Guard statement
4. Optionals
5. Structs
6. Structures vs Classes
7. Typecasting

## Variable declaration
In Swift, `var` and `let` are used for variable and constant declarations, respectively. Here are some additional details:

### `var` (Variable Declaration):

- **Mutable**: Variables declared with `var` are mutable, meaning their values can be changed after the initial assignment.

    ```swift
    var myVariable = 42
    myVariable = 100 // This is allowed
    ```

- **Scope**: Variables have scope, and their values are accessible within the block or function where they are declared.

    ```swift
    if true {
        var localVar = "Inside if block"
        print(localVar)
    }

    // Error: localVar is not accessible here
    // print(localVar)
    ```

### `let` (Constant Declaration):

- **Immutable**: Constants declared with `let` are immutable, and their values cannot be changed after the initial assignment.

    ```swift
    let myConstant = 42
    // Error: Cannot assign to 'myConstant' because it is a constant
    // myConstant = 100
    ```

- **Scope**: Constants also have scope, and their values are accessible within the block or function where they are declared.

    ```swift
    if true {
        let localConstant = "Inside if block"
        print(localConstant)
    }

    // Error: localConstant is not accessible here
    // print(localConstant)
    ```

### When to Use `var` and `let`:

- Use `var` when the value may change during the execution of your code.

- Use `let` when the value should remain constant throughout its scope, providing clarity and preventing accidental modifications.

### Type Inference:

Swift supports type inference, which means you don't always need to explicitly mention the data type when declaring a variable or constant. The compiler can often infer the type based on the initial value.

```swift
var name = "John" // Swift infers 'name' as String
let pi = 3.14 // Swift infers 'pi' as Double
```



### Variable Shadowing in Swift:

- **Example Function:**
  ```swift
  func printComplexScope() {
      let points = 100
      print(points)
      for index in 1...3 {
          let points = 200
          print("Loop \(index): \(points + index)")
      }
      print(points)
  }
  printComplexScope()
  ```

- **Output Explanation:**
  ```
  100
  Loop 1: 201
  Loop 2: 202
  Loop 3: 203
  100
  ```
- **Variable Shadowing:**
  - Variable `points` is declared at two different locations: within the function's local scope and within the for-in loop's local scope.
  - This leads to variable shadowing, where the inner variable completely shadows the outer one, making it inaccessible.
  - Variable shadowing is useful for simplifying code, such as reusing the same identifier within optional binding or guard statements.

### Constant and Variable Scope in Swift:

- **Global and Local Scope:**
  - Swift has two levels of scope: global and local.
  - Global variables are accessible from anywhere in the program.
  - Local variables are declared within a specific scope defined by curly braces `{}` and are not accessible outside that scope.

- **Example:**
  ```swift
  var age = 40
  
  func printAge() {
      print("My age: \(age)")
  }
  ```

- **Scope Example:**
  - `age` is in global scope and can be accessed within the `printAge()` method without passing it as an argument.
  - The method itself is in global scope.
  - Variables declared within functions, loops, or conditionals have local scope.

### Variable Shadowing in Initializers:

- **Example Class:**
  ```swift
  class Movie {
      var name: String
      var genre: String
  
      init(name: String, genre: String) {
          self.name = name
          self.genre = genre
      }
  }
  ```

- **Variable Shadowing in Initializers:**
  - Variable shadowing can be used in initializers by making parameters with the same names as properties.
  - The `self` keyword is used to differentiate between the parameters and the properties with the same names.
  - This practice helps avoid confusion and makes it clear that properties are being set to the values passed in as parameters.
  



## Guard statement in Swift

Guard statements in Swift are used for early exit from a function, method, or loop if certain conditions are not met. They enhance code readability and prevent the "pyramid of doom" or excessive nesting seen in some code structures. Guard statements are particularly useful for handling invalid or exceptional cases upfront.

**Syntax of a Guard Statement:**
```swift
guard condition else {
    // Code to be executed if condition is not met
    return // or throw, break, continue, etc.
}
// Code to be executed if condition is met
```

**Example - Birthday Celebration:**
Consider the example of a birthday celebration with nested if-else statements:

```swift
func singHappyBirthday() {
    if birthdayIsToday {
        if !invitedGuests.isEmpty {
            if cakeCandlesLit {
                print("Happy Birthday to you!")
            } else {
                print("The cake’s candles haven’t been lit.")
            }
        } else {
            print("It’s just a family party.")
        }
    } else {
        print("No one has a birthday today.")
    }
}
```

The equivalent code using guard statements:

```swift
func singHappyBirthday() {
    guard birthdayIsToday else {
        print("No one has a birthday today.")
        return
    }

    guard !invitedGuests.isEmpty else {
        print("It’s just a family party.")
        return
    }

    guard cakeCandlesLit else {
        print("The cake’s candles haven’t been lit.")
        return
    }

    print("Happy Birthday to you!")
}



// Another example
func validateAge(age: Int?) {
    // Using guard to check if age is nil
    guard let age = age else {
        print("Age is nil.")
        return // Exit the function if age is nil
    }
    
    // Using guard to check if age is greater than or equal to 18
    guard age >= 18 else {
        print("You must be at least 18 years old.")
        return // Exit the function if age is less than 18
    }
    
    // If age passes both guard conditions, print a success message
    print("Welcome! You are \(age) years old.")
}

// Example usage:
validateAge(age: 25) // Output: "Welcome! You are 25 years old."
validateAge(age: nil) // Output: "Age is nil."
validateAge(age: 15) // Output: "You must be at least 18 years old."

```

**Advantages of Guard Statements:**

1. **Readability:**
   - Guard statements improve code readability by avoiding the "pyramid of doom" and ensuring that the expected code is not buried within nested conditions.

2. **Early Exit:**
   - Guard statements allow for early exit from a function or method, making it clear when certain conditions are not met, and avoiding unnecessary execution of the remaining code.

3. **Intent Clarity:**
   - Guards clearly communicate the developer's intent by stating conditions that should be met for the code to proceed.

4. **Avoiding Nesting:**
   - Guard statements help avoid excessive nesting, reducing indentation levels and making the code more maintainable.

**Equivalent Guard Statement for a Given If Statement:**

```swift
func divide(_ number: Double, by divisor: Double) {
    guard divisor != 0.0 else {
        return
    }
    let result = number / divisor
    print(result)
}
```

In this example, the guard statement ensures that the divisor is not zero before proceeding with the division. If the condition is not met, the function exits early, preventing a division by zero error.


## **Optionals in Swift:**

Optionals in Swift are a powerful feature that allows variables to have either a value or no value (nil). They are used to handle the potential absence of a value and prevent runtime errors.

### Example 1: Basic Usage

```swift
struct Book {
    var name: String
    var publicationYear: Int? //Optional
}

let book1 = Book(name: "A Wild Sheep Chase", publicationYear: 1982)
let book2 = Book(name: "Norwegian Wood", publicationYear: 1987)
let book3 = Book(name: "1Q84", publicationYear: nil)
```

In this example, `publicationYear` is declared as an optional (`Int?`) to represent the fact that the publication year may or may not be known.

### Example 2: Optional Function Parameters and Return Types

```swift
func divide(_ number: Double, by divisor: Double) -> Double? {
    guard divisor != 0.0 else {
        return nil
    }kmlmmmmm
    let result = number / divisor
    return result
}

let result = divide(10.0, by: 2.0)
if let unwrappedResult = result {
    print("Result: \(unwrappedResult)")
} else {
    print("Cannot divide by zero.")
}

Struct Book {
var name:String
var publicationYear:Int?
}
if book3.publicationYear != nil {
actualPublicationYear = book3.publicationYear!
print(“Publication year of \(book3.name) is \(actualPublicationYear)”)
}
if let publicationYear = book3.publicationYear {
 print(“Publication year of \(book3.name) is \(publicationYear)”)
}
```

In this example, the `divide` function takes two parameters and returns an optional `Double`. If the divisor is zero, the function returns nil to indicate an invalid operation.

### Failable Initializers:

```swift
struct Toddler {
    var name: String
    var monthsOld: Int
    
    init?(name: String, monthsOld: Int) {
        if monthsOld < 12 || monthsOld > 36 {
            return nil
        } else {
            self.name = name
            self.monthsOld = monthsOld
        }
    }
}

let toddler = Toddler(name: "Joanna", monthsOld: 14)
if let myToddler = toddler {
    print("\(myToddler.name) is \(myToddler.monthsOld) months old")
} else {
    print("The age you specified for the toddler is not between 1 and 3 years of age")
}
```

Here, the `init?` is a failable initializer for the `Toddler` struct. It returns nil if the provided age is not within the valid range.

### Nested Optionals and Optional Chaining:

```swift
struct Person {
    var name: String
    var age: Int
    var residence: Residence?
}

struct Residence {
    var address: Address?
}

struct Address {
    var buildingNumber: String
    var buildingName: String?
    var street: String
}

let person = Person(name: "John", age: 30, residence: Residence(address: Address(buildingNumber: "123", buildingName: "Sunset Towers", street: "Main St.")))

if let buildingName = person.residence?.address?.buildingName {
    print("\(person.name) resides in \(buildingName)")
} else {
    print("Building name not available.")
}
```

Here, we have nested optionals (`Residence?`, `Address?`, `String?`). Optional chaining allows us to safely unwrap these nested optionals.



## Structs

In Swift, initializers are special methods that are used to create and configure instances of a type. They ensure that all properties of the type have a valid initial value before the instance is ready for use.

### Default Initializer:

The default initializer is a special kind of initializer provided by Swift if you don't define any initializers yourself. It initializes all properties of the struct with their default values.

```swift
struct Odometer {
    var count: Int = 0
}

let newOdometer = Odometer()
print(newOdometer.count) // 0
```

In this example, the `Odometer` struct has a property `count` with a default value of 0. The default initializer is used to create a new instance, and the `count` property is initialized with its default value.

### Memberwise Initializer:

The memberwise initializer is automatically generated by Swift for structs. It takes parameters for each property in the struct and allows you to initialize the struct by providing values for those parameters.

```swift
struct Person {
    var name: String
}

let person = Person(name: "Natalie Rushman")
```

In this example, the `Person` struct has a single property `name`. The memberwise initializer is provided by Swift, allowing you to create an instance of `Person` by specifying a value for the `name` parameter.

### Key Differences:

1. **Default Initializer:**
   - Automatically provided by Swift if no initializers are defined.
   - Initializes all properties with their default values.
   - Useful when all instances should have consistent initial values.

2. **Memberwise Initializer:**
   - Automatically generated by Swift for structs.
   - Takes parameters for each property, allowing customization during initialization.
   - Useful when you need to provide specific values for certain properties.

### Examples with Predefined Types:

```swift
// Using default initializers for predefined types
let defaultString = String() // ""
let defaultInteger = Int() // 0
let defaultBool = Bool() // false

// Using memberwise initializer for predefined types
let customString = String("Hello")
let customInteger = Int(42)
let customBool = Bool(true)
```



**Custom Initializers in Structs:**

Custom initializers in Swift allow you to define your own methods for creating instances of a struct with specific parameters and logic. They provide more flexibility than the default and memberwise initializers generated by Swift.

### Example: Temperature Struct

Consider the `Temperature` struct with custom initializers for creating instances based on different temperature scales.

```swift
struct Temperature {
    var celsius: Double

    // Custom initializer for Celsius
    init(celsius: Double) {
        self.celsius = celsius
    }

    // Custom initializer for Fahrenheit
    init(fahrenheit: Double) {
        celsius = (fahrenheit - 32) / 1.8
    }

    // Custom initializer for Kelvin
    init(kelvin: Double) {
        celsius = kelvin - 273.15
    }
}
```

In this example, we have three custom initializers:

1. **Celsius Initializer:**
   - Takes a value in Celsius and directly sets the `celsius` property.

2. **Fahrenheit Initializer:**
   - Takes a value in Fahrenheit, converts it to Celsius, and sets the `celsius` property.

3. **Kelvin Initializer:**
   - Takes a value in Kelvin, converts it to Celsius, and sets the `celsius` property.

### Usage of Custom Initializers:

```swift
let currentTemperature = Temperature(celsius: 21.0)
let boilingTemperature = Temperature(fahrenheit: 212.0)
let absoluteZero = Temperature(kelvin: 0.0)
```

In these examples, we use the custom initializers to create instances of `Temperature` with values in different temperature scales. The custom initializers allow us to encapsulate the conversion logic within the struct, providing a more convenient and readable way to create instances.

### Need for Custom Initializers:

1. **Specialized Initialization:**
   - Custom initializers allow you to create instances with specific values or perform complex initialization logic.

2. **Conversion Logic:**
   - When you need to convert values from one scale to another (e.g., Fahrenheit to Celsius), custom initializers provide a clean way to encapsulate that logic.

3. **Additional Initialization Logic:**
   - You might need to perform additional setup or validation during initialization, which can be achieved through custom initializers.

4. **Encapsulation of Initialization Details:**
   - Custom initializers encapsulate the details of how an instance is initialized, providing a clear interface for creating instances.

**I. Using Custom Initializers:**

```swift
struct Temperature {
    var celsius: Double
    var fahrenheit: Double
    var kelvin: Double

    init(celsius: Double) {
        self.celsius = celsius
        self.fahrenheit = celsius * 1.8 + 32
        self.kelvin = celsius + 273.15
    }

    init(fahrenheit: Double) {
        self.fahrenheit = fahrenheit
        self.celsius = (fahrenheit - 32) / 1.8
        self.kelvin = celsius + 273.15
    }

    init(kelvin: Double) {
        self.kelvin = kelvin
        self.celsius = kelvin - 273.15
        self.fahrenheit = celsius * 1.8 + 32
    }
}

let currentTemperature = Temperature(celsius: 18.5)
let boiling = Temperature(fahrenheit: 212.0)
let freezing = Temperature(kelvin: 273.15)
```

In this implementation, custom initializers are defined to initialize the struct's properties based on the provided values in Celsius, Fahrenheit, or Kelvin.

**II. Using Computed Properties:**

```swift
struct Temperature {
    var celsius: Double

    var fahrenheit: Double {
        return celsius * 1.8 + 32
    }

    var kelvin: Double {
        return celsius + 273.15
    }
}

let currentTemperature = Temperature(celsius: 0.0)
print(currentTemperature.fahrenheit) // Output: 32.0
```

In this version, computed properties `fahrenheit` and `kelvin` are used to calculate their values based on the `celsius` property. Computed properties provide a concise way to derive values based on existing properties or perform calculations when accessing a property.


**I. Property Observers:**

Property observers in Swift allow you to observe and respond to changes in a property's value. There are two types of property observers:

1. **willSet:** Called just before the value of the property is set.
2. **didSet:** Called immediately after the value of the property is set.

Here's an example using a `StepCounter` struct with a `totalSteps` property:

```swift
struct StepCounter {
    var totalSteps: Int = 0 {
        willSet {
            print("About to set totalSteps to \(newValue)")
        }
        didSet {
            if totalSteps > oldValue {
                print("Added \(totalSteps - oldValue) steps")
            }
        }
    }
}

var myStepCounter = StepCounter()
myStepCounter.totalSteps = 10
// Output:
// About to set totalSteps to 10
// Added 10 steps
```

In this example, when `totalSteps` is set to a new value, the `willSet` observer is called first, providing access to the new value. After the property is updated, the `didSet` observer is called, allowing access to the previous value.

**II. Type Properties and Methods:**

Type properties and methods in Swift are associated with the type itself rather than instances of the type. They are defined using the `static` keyword.

**Type Property Example:**

```swift
struct Temperature {
    static var boilingPoint = 100
}

let boilingPoint = Temperature.boilingPoint
print(boilingPoint) // Output: 100
```

In this example, `boilingPoint` is a type property of the `Temperature` struct, and it can be accessed using dot syntax on the type name.

**Type Method Example:**

```swift
struct MyMath {
    static func square(_ number: Double) -> Double {
        return number * number
    }
}

let result = MyMath.square(4.0)
print(result) // Output: 16.0
```

Here, `square` is a type method of the `MyMath` struct. It is called on the type itself, not on an instance of the type.

Type properties and methods are useful when you want to associate a property or method with the type rather than with individual instances.


## **Structures vs. Classes in Swift:**

**Structures:**
- Value types.
- Cannot be subclassed.
- Allocated on the stack.
- Copying a structure creates an independent copy.

**Classes:**
- Reference types.
- Can be subclassed.
- Allocated on the heap.
- Multiple references can point to the same instance.
**Difference between Struct and Class Types:**

**I. Value Type vs. Reference Type:**
- **Structures (Value Types):**
  - Values are copied when assigned or passed.
  - Modifying one instance doesn't affect the other.
  ```swift
  struct Size {
      var width: Int
      var height: Int
  }
  
  var someSize = Size(width: 250, height: 1000)
  var anotherSize = someSize
  someSize.width = 500
  print(someSize.width)    // Output: 250
  print(anotherSize.width) // Output: 500
  ```
- **Classes (Reference Types):**
  - Reference to the same instance in memory is shared when assigned or passed.
  - Modifying one instance affects all references to that instance.
  ```swift
  class Person {
      let name: String
      var age: Int
      init(name: String, age: Int) {
          self.name = name
          self.age = age
      }
  }
  
  var jack = Person(name: "Jack", age: 24)
  var myFriend = jack
  jack.age += 1
  print(jack.age)      // Output: 25
  print(myFriend.age)  // Output: 25
  ```

**II. Memberwise Initializers:**
- **Structures:**
  - Automatically provided by Swift compiler.
  ```swift
  struct Size {
      var width: Int
      var height: Int
  }
  
  let size = Size(width: 10, height: 20)
  ```
- **Classes:**
  - Not provided by default; custom initializers need to be defined.
  ```swift
  class Person {
      let name: String
      var age: Int
      init(name: String, age: Int) {
          self.name = name
          self.age = age
      }
  }
  
  let person = Person(name: "John", age: 30)
  ```

**III. Inheritance:**
- **Structures:**
  - No inheritance concept.
- **Classes:**
  - Can have superclass and subclass hierarchy.
  ```swift
  class Animal { /* ... */ }
  class Dog: Animal { /* ... */ }
  ```

In summary, structures are value types, meaning they are copied when assigned or passed. Classes are reference types, sharing the same instance in memory. Structures have automatic memberwise initializers, whereas classes require custom initializers. Classes can participate in inheritance, forming superclass and subclass relationships.

## **Example Differentiating Base, Super, and Subclasses:**

```swift
// Base Class
class Vehicle {
    var currentSpeed = 0.0
    var description: String {
        return "traveling at \(currentSpeed) miles per hour"
    }
    func makeNoise() {
        // do nothing - an arbitrary vehicle doesn’t necessarily make a noise
    }
}

// Subclass 1
class Bicycle: Vehicle {
    var hasBasket = false
}

// Subclass 2
class Tandem: Bicycle {
    var currentNumberOfPassengers = 0
}

// Instances
let car = Vehicle()
let bike = Bicycle()
let tandem = Tandem()

// Using Base Class
print(car.description) // Output: traveling at 0.0 miles per hour
car.makeNoise() // Output: Does nothing

// Using Subclass 1
bike.currentSpeed = 15.0
bike.hasBasket = true
print(bike.description) // Output: traveling at 15.0 miles per hour
bike.makeNoise() // Output: Does nothing (inherits from base class)

// Using Subclass 2
tandem.currentSpeed = 20.0
tandem.hasBasket = true
tandem.currentNumberOfPassengers = 2
print(tandem.description) // Output: traveling at 20.0 miles per hour
tandem.makeNoise() // Output: Does nothing (inherits from base class)
```

In this example, we have a base class `Vehicle` with properties and methods. The `Bicycle` class is a subclass of `Vehicle`, inheriting its properties and methods. Similarly, the `Tandem` class is a subclass of `Bicycle`, inheriting properties and methods from both `Vehicle` and `Bicycle`. Each class can have additional properties or methods. Instances of these classes demonstrate the inheritance hierarchy and usage of base, super, and subclasses.

## Typecasting
**Typecasting in Swift:**

Type casting in Swift is the process of checking the type of an instance and treating it as a different type in the class hierarchy. This is useful when working with a hierarchy of classes and you need to perform operations specific to a certain subclass or superclass.

**Class Hierarchy:**
```swift
class MediaItem {
    var name: String
    
    init(name: String) {
        self.name = name
    }
}

class Movie: MediaItem {
    var director: String
    
    init(name: String, director: String) {
        self.director = director
        super.init(name: name)
    }
}

class Song: MediaItem {
    var artist: String
    
    init(name: String, artist: String) {
        self.artist = artist
        super.init(name: name)
    }
}
```

**Typecasting and Using `is`, `as?`, and `as!` Operators:**
```swift
let library: [MediaItem] = [
    Movie(name: "Shadow of a doubt", director: "Alfred Hitchcock"),
    Song(name: "Drive home", artist: "Steven Wilson"),
    Song(name: "Hotel California", artist: "Eagles"),
    Movie(name: "The dark knight", director: "Christopher Nolan"),
    Song(name: "Kashmir", artist: "Led Zeppelin")
]

for item in library {
    if item is Movie {
        print("Movie: \(item.name)")
        if let movie = item as? Movie {
            print("Director: \(movie.director)")
        }
    } else if item is Song {
        print("Song: \(item.name)")
        if let song = item as? Song {
            print("Artist: \(song.artist)")
        }
    }
}
```

- The `is` operator checks whether an instance is of a certain subclass type.
- The `as?` operator performs a conditional type cast and returns an optional.
- The `as!` operator performs a forced type cast and assumes that the cast is always successful (use with caution).

Certainly! Let's delve into the details of each of these type-casting operators in Swift:

### 1. `is` Operator:
The `is` operator is used to check whether an instance is of a certain type (including subclasses). It returns a Boolean value indicating whether the instance on the left conforms to the type on the right.

**Example:**
```swift
let someItem: MediaItem = Movie(name: "Inception", director: "Christopher Nolan")

if someItem is Movie {
    print("It's a movie!")
} else {
    print("It's not a movie.")
}
```

In this example, the `is` operator checks if `someItem` is an instance of the `Movie` class.

### 2. `as?` Operator (Conditional Type Cast):
The `as?` operator performs a conditional type cast. It attempts to cast the instance on the left to the specified type on the right. If the cast is successful, it returns an optional of the target type; otherwise, it returns `nil`.

**Example:**
```swift
let someItem: MediaItem = Song(name: "Bohemian Rhapsody", artist: "Queen")

if let song = someItem as? Song {
    print("It's a song by \(song.artist).")
} else {
    print("It's not a song.")
}
```

Here, we use `as?` to try casting `someItem` to a `Song`. If successful, we can safely use the `song` constant within the conditional scope.

### 3. `as!` Operator (Forced Type Cast):
The `as!` operator performs a forced type cast. It forcefully assumes that the cast will always succeed. If the cast is unsuccessful (e.g., if the instance is not of the specified type), a runtime error will occur.

**Example:**
```swift
let someItem: MediaItem = Movie(name: "The Matrix", director: "The Wachowskis")

let movie = someItem as! Movie
print("Director: \(movie.director)")
```

In this example, we use `as!` to forcefully cast `someItem` to a `Movie` because we are confident that it is indeed a movie.

**Caution:** Using `as!` without ensuring the type compatibility can lead to runtime crashes, so it should be used carefully.

These type-casting operators are essential for working with class hierarchies and ensuring that you can safely interact with instances of different types within the hierarchy.



