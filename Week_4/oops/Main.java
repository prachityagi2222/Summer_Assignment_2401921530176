package oops;

// Rest of your code here...
// ====== Problem 1: Interface and Implementation ======
interface Test {
    int square(int num);
}

class Arithmetic implements Test {
    @Override
    public int square(int num) {
        return num * num;
    }
}

// ====== Problem 2: Outer and Inner Class ======
class Outer {
    public void display() {
        System.out.println("Display from Outer");
    }
    
    class Inner {
        public void display() {
            System.out.println("Display from Inner");
        }
    }
}

// ====== Problem 3: Point Class ======
class Point {
    private int x, y;
    
    public Point() {
        this(0, 0);
    }
    
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    public void setX(int x) { this.x = x; }
    public void setY(int y) { this.y = y; }
    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

// ====== Problem 4: Box and Box3D ======
class Box {
    protected double length, breadth, height;
    
    public Box() {
        this(0, 0, 0);
    }
    
    public Box(double length, double breadth, double height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }
    
    public double area() {
        return 2 * (length * breadth + breadth * height + height * length);
    }
    
    public double volume() {
        return length * breadth * height;
    }
}

class Box3D extends Box {
    public Box3D() {
        super();
    }
    
    public Box3D(double length, double breadth, double height) {
        super(length, breadth, height);
    }
}

// ====== Main class (must match filename) ======
public class Main {
    public static void main(String[] args) {
        // Test Problem 1
        System.out.println("=== Problem 1 ===");
        Arithmetic arith = new Arithmetic();
        System.out.println("Square of 5: " + arith.square(5));
        
        // Test Problem 2
        System.out.println("\n=== Problem 2 ===");
        Outer outer = new Outer();
        outer.display();
        Outer.Inner inner = outer.new Inner();
        inner.display();
        
        // Test Problem 3
        System.out.println("\n=== Problem 3 ===");
        Point p1 = new Point();
        p1.setXY(3, 7);
        // Add getters to display or use System.out.println
        
        // Test Problem 4
        System.out.println("\n=== Problem 4 ===");
        Box box = new Box(5, 3, 4);
        System.out.println("Box Area: " + box.area());
        System.out.println("Box Volume: " + box.volume());
        
        Box3D box3d = new Box3D(6, 4, 5);
        System.out.println("Box3D Area: " + box3d.area());
        System.out.println("Box3D Volume: " + box3d.volume());
    }
}