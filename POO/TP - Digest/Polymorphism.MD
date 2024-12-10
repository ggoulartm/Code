### **Polymorphism in Java**

Polymorphism is one of the core principles of Object-Oriented Programming (OOP) and allows methods to perform differently based on the object calling them. It can be classified into two main types:

---

### **1. Compile-Time Polymorphism (Method Overloading)**

This occurs when two or more methods in the same class have the same name but differ in:
- Number of parameters.
- Type of parameters.
- Order of parameters.

#### **Key Points**:
- Decided by the compiler during compilation.
- Overloaded methods are differentiated by their **method signature**.

#### **Example**:
```java
class Calculator {
    // Overloaded methods
    public int add(int a, int b) {
        return a + b;
    }

    public double add(double a, double b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b + c;
    }
}

public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        System.out.println(calc.add(1, 2));         // Calls the int version
        System.out.println(calc.add(1.5, 2.5));     // Calls the double version
        System.out.println(calc.add(1, 2, 3));      // Calls the three-argument version
    }
}
```

#### **Notes**:
- Overloading **cannot** differ only by return type.
- **Example of invalid overload**:
  ```java
  public int add(int a, int b);
  public double add(int a, int b); // Error: ambiguous methods
  ```

---

### **2. Runtime Polymorphism (Method Overriding)**

This occurs when a subclass provides its own implementation for a method that is already defined in the parent class.

#### **Key Points**:
- Achieved through **inheritance**.
- The method signature (name, parameters, return type) must match exactly.
- Decided at runtime using **dynamic method dispatch**.

#### **Example**:
```java
class Animal {
    public void speak() {
        System.out.println("The animal makes a sound.");
    }
}

class Dog extends Animal {
    @Override
    public void speak() {
        System.out.println("The dog barks.");
    }
}

class Cat extends Animal {
    @Override
    public void speak() {
        System.out.println("The cat meows.");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal animal;  // Reference of type Animal
        animal = new Dog(); // Object of type Dog
        animal.speak();  // Output: The dog barks.

        animal = new Cat(); // Object of type Cat
        animal.speak();  // Output: The cat meows.
    }
}
```

#### **Dynamic Method Dispatch**:
When a parent class reference points to a child class object, the **child class's method** is executed.

---

### **Polymorphism with Interfaces**
An interface can be implemented by multiple classes, and the same method can behave differently depending on the implementation.

#### **Example**:
```java
interface Shape {
    void draw();
}

class Circle implements Shape {
    public void draw() {
        System.out.println("Drawing a Circle.");
    }
}

class Rectangle implements Shape {
    public void draw() {
        System.out.println("Drawing a Rectangle.");
    }
}

public class Main {
    public static void main(String[] args) {
        Shape shape;
        shape = new Circle();
        shape.draw();  // Output: Drawing a Circle.

        shape = new Rectangle();
        shape.draw();  // Output: Drawing a Rectangle.
    }
}
```

---

### **3. Polymorphism with Abstract Classes**

Abstract classes can also achieve polymorphism by defining methods that are implemented differently in their subclasses.

#### **Example**:
```java
abstract class Animal {
    abstract void makeSound();

    void sleep() {
        System.out.println("This animal sleeps.");
    }
}

class Lion extends Animal {
    @Override
    void makeSound() {
        System.out.println("Roar!");
    }
}

class Snake extends Animal {
    @Override
    void makeSound() {
        System.out.println("Hiss!");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal lion = new Lion();
        Animal snake = new Snake();

        lion.makeSound(); // Output: Roar!
        snake.makeSound(); // Output: Hiss!
        lion.sleep();      // Output: This animal sleeps.
    }
}
```

---

### **Advantages of Polymorphism**
1. **Code Reusability**: Shared methods in parent classes reduce redundancy.
2. **Scalability**: Easily extend existing code by adding new subclasses.
3. **Flexibility**: Behavior can change dynamically at runtime.

---

### **Important Notes**
- **Overriding vs Overloading**:
  - Overloading is compile-time; overriding is runtime.
  - Overloading allows multiple methods with the same name in the same class.
  - Overriding replaces the inherited method with a subclass's implementation.

| Feature                 | Overloading                          | Overriding                          |
|-------------------------|---------------------------------------|--------------------------------------|
| **Definition**          | Same method name, different parameters. | Same method name and parameters.     |
| **Binding**             | Compile-time binding.                | Runtime binding.                    |
| **Inheritance Needed**  | No                                   | Yes                                 |
| **Access Modifiers**    | Can have different modifiers.        | Modifier cannot be more restrictive.|
---