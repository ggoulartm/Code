Once Java hasn't Multiple Inheritance, we have to find another ways to combine classes and there is at least two things we can do: composition and aggregation. They are two core concepts in Object-Oriented Programming (OOP) that define relationships between classes.

---

### **1. Inheritance**

#### **Definition**:
- Inheritance establishes an **"is-a" relationship** between two classes.
- A subclass inherits the fields and methods of a superclass, enabling reuse and specialization.

#### **Key Features**:
- **Single Inheritance**: In Java, a class can inherit from only one superclass.
- Subclasses can override or add functionality.
- Defined using the `extends` keyword.

#### **Example**:
```java
class Vehicle {
    String brand;

    void drive() {
        System.out.println("Driving a vehicle.");
    }
}

class Car extends Vehicle {
    int doors;

    @Override
    void drive() {
        System.out.println("Driving a car.");
    }
}
```

#### **Use Cases**:
- Use inheritance when the subclass **is a type of** the superclass (e.g., a Car *is a* Vehicle).

---

### **2. Composition**

#### **Definition**:
- Composition establishes a **"has-a" relationship**, where a class contains an instance of another class as part of its state.
- This is a **strong relationship**, meaning the composed objects' lifetimes are tied to the containing object.

#### **Key Features**:
- Achieved by including an object as an instance variable in another class.
- Composed objects are typically created and destroyed along with the containing object.
- Promotes code reusability and encapsulation.

#### **Example**:
```java
class Engine {
    void start() {
        System.out.println("Engine started.");
    }
}

class Car {
    private Engine engine;

    Car() {
        engine = new Engine();
    }

    void drive() {
        engine.start();
        System.out.println("Car is driving.");
    }
}
```

#### **Use Cases**:
- Use composition when an object **"has-a"** another object as a part of its structure (e.g., a Car *has an* Engine).

---

### **3. Aggregation**

#### **Definition**:
- Aggregation is a **"has-a" relationship**, like composition, but with a **weaker association**.
- The aggregated objects' lifetimes are **independent** of the containing object's lifetime.

#### **Key Features**:
- Aggregated objects are passed into the class rather than being created within it.
- If the containing object is destroyed, the aggregated objects can still exist.

#### **Example**:
```java
class Employee {
    String name;

    Employee(String name) {
        this.name = name;
    }
}

class Department {
    private List<Employee> employees;

    Department(List<Employee> employees) {
        this.employees = employees;
    }

    void printEmployees() {
        employees.forEach(e -> System.out.println(e.name));
    }
}
```

#### **Use Cases**:
- Use aggregation when an object **"has-a"** relationship, but the associated objects do not depend on the container's lifecycle (e.g., a Department *has Employees*, but employees exist independently of the department).

---

### **Comparison**

| **Aspect**               | **Inheritance**                  | **Composition**                  | **Aggregation**                  |
|--------------------------|-----------------------------------|-----------------------------------|-----------------------------------|
| **Relationship**         | "is-a"                          | "has-a"                          | "has-a"                          |
| **Dependency**           | Strong                          | Strong                           | Weak                             |
| **Lifetime**             | Subclass depends on superclass. | Contained object depends on container. | Aggregated object has independent lifecycle. |
| **Reusability**          | Reuses behavior of superclass.  | Reuses behavior of contained class. | Reuses external objects.         |
| **Implementation**       | `extends` keyword.              | Object as an instance variable.  | Objects passed via constructor/setter. |
| **Tight Coupling**       | Tight coupling (more dependent).| Moderate coupling.               | Loose coupling.                  |

---

### **Which One to Use?**

- **Inheritance**:
  - Use when there is a clear "is-a" relationship.
  - Example: A Car *is-a* Vehicle.
- **Composition**:
  - Use when a class is composed of parts that cannot exist independently.
  - Example: A Car *has-an* Engine (engine is part of the car).
- **Aggregation**:
  - Use when a class uses or owns objects that can exist independently.
  - Example: A Department *has Employees* (employees can exist without the department).

---

### **Practical Example of All Three**

```java
class Engine {
    void start() {
        System.out.println("Engine started.");
    }
}

class Vehicle {
    void drive() {
        System.out.println("Vehicle is driving.");
    }
}

class Car extends Vehicle { // Inheritance (is-a)
    private Engine engine;  // Composition (has-a)

    Car(Engine engine) {
        this.engine = engine;
    }

    @Override
    void drive() {
        engine.start();
        System.out.println("Car is driving.");
    }
}

class ParkingLot { // Aggregation (has-a)
    private List<Vehicle> vehicles;

    ParkingLot(List<Vehicle> vehicles) {
        this.vehicles = vehicles;
    }

    void parkAll() {
        vehicles.forEach(Vehicle::drive);
    }
}
```

---