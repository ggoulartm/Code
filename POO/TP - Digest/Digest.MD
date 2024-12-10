### **1. Classes and Objects**
- **Core Elements of an Object**:
  - **State**: Attributes (e.g., `int x`).
  - **Behavior**: Methods (e.g., `void print()`).
  - **Identity**: Memory reference.

#### **Constructors**
- Initialize attributes at object creation.
- Multiple constructors are allowed (overloading).
- Use `this()` to call another constructor in the same class.
- Use `super()` to call a superclass constructor.

| **Visibility** | **Access Within Class** | **Access by Subclasses** | **Access by Same Package** | **Access by Other Classes** |
|----------------|--------------------------|---------------------------|----------------------------|-----------------------------|
| `public`       | ✅                       | ✅                        | ✅                         | ✅                          |
| `protected`    | ✅                       | ✅                        | ✅                         | ❌                          |
| *(default)*    | ✅                       | ❌                        | ✅                         | ❌                          |
| `private`      | ✅                       | ❌                        | ❌                         | ❌                          |

---

### **2. Encapsulation**
- **Principle**: Internal representation of a class is hidden using `private` attributes and accessed via:
  - **Getters** (e.g., `getAttribute()`).
  - **Setters** (e.g., `setAttribute(value)`).

#### **Example**:
```java
class Example {
    private int value;

    public int getValue() { return value; }
    public void setValue(int value) { 
        if (value >= 0) this.value = value; 
    }
}
```

---

### **3. Inheritance**
- Allows a class to inherit attributes and methods from another.
- **Key Elements**:
  - `extends`: Used for inheritance.
  - `super`: Calls the parent class's constructor or method.
  - Overriding: Modify inherited method behavior.

#### **Example**:
```java
class Parent {
    public void show() { System.out.println("Parent Method"); }
}

class Child extends Parent {
    @Override
    public void show() { System.out.println("Child Method"); }
}
```

---

### **4. Polymorphism**
- **Compile-time**: Method overloading.
- **Runtime**: Method overriding (with dynamic dispatch).

---

### **5. Exception Handling**
- **Purpose**: Manage errors at runtime.
- **Syntax**:
  ```java
  try {
      // Code that may throw exception
  } catch (ExceptionType e) {
      // Handle exception
  } finally {
      // Code that runs regardless of exceptions
  }
  ```

| **Exception Type**      | **Checked** | **Unchecked** | **Description**                                  |
|--------------------------|-------------|---------------|------------------------------------------------|
| `IOException`           | ✅          | ❌            | File handling errors.                          |
| `ArithmeticException`   | ❌          | ✅            | Errors like division by zero.                  |
| `NullPointerException`  | ❌          | ✅            | Accessing methods on a `null` reference.       |

---

### **6. Collections Framework**
- **List**: Ordered, allows duplicates (e.g., `ArrayList`, `LinkedList`).
- **Set**: Unordered, no duplicates (e.g., `HashSet`, `TreeSet`).
- **Map**: Key-value pairs (e.g., `HashMap`, `TreeMap`).

| **Class**         | **Ordered?** | **Duplicates Allowed?** | **Implementation**         |
|-------------------|--------------|--------------------------|----------------------------|
| `ArrayList`       | ✅           | ✅                       | Array-backed dynamic list. |
| `HashSet`         | ❌           | ❌                       | Hash table.                |
| `TreeMap`         | ✅           | ✅ (keys unique)         | Sorted map.                |

---

### **7. UML and Design Principles**
#### **Common Symbols**:
- **Inheritance**: Hollow arrow.
- **Composition**: Filled diamond.
- **Aggregation**: Hollow diamond.
- **Dependency**: Dashed arrow.

---

### **8. Key Methods in `Object` Class**
- **`toString()`**: Returns a string representation of an object.
- **`equals()`**: Checks object equality based on state, not reference.
- **`hashCode()`**: Generates an integer for hashing purposes.

#### **Override Example**:
```java
@Override
public String toString() {
    return "Object details";
}

@Override
public boolean equals(Object o) {
    if (o instanceof ClassName) {
        return this.attribute.equals(((ClassName) o).attribute);
    }
    return false;
}
```

---