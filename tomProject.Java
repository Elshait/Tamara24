// Создаем абстрактный класс для геометрических фигур
abstract class Shape {
    abstract double area();
}

// Создаем класс для вычисления объема цилиндра с наследованием от класса Shape
class Cylinder extends Shape {
    double radius;
    double height;

    Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }


    double area() {
        return 2 * Math.PI * radius * radius + 2 * Math.PI * radius * height;
    }
}

// Создаем класс для вычисления объема конуса с наследованием от класса Shape
class Cone extends Shape {
    double radius;
    double height;

    Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }


    double area() {
        return Math.PI * radius * (radius + Math.sqrt(Math.pow(height, 2) + Math.pow(radius, 2)));
    }
}

// Создаем класс для вычисления объема пирамиды с наследованием от класса Shape
class Pyramid extends Shape {
    double baseLength;
    double baseWidth;
    double height;

    Pyramid(double baseLength, double baseWidth, double height) {
        this.baseLength = baseLength;
        this.baseWidth = baseWidth;
        this.height = height;
    }

 
    double area() {
        return baseLength * baseWidth + baseLength * Math.sqrt(Math.pow(baseWidth / 2, 2) + Math.pow(height, 2))
                + baseWidth * Math.sqrt(Math.pow(baseLength / 2, 2) + Math.pow(height, 2));
    }
}

public class Main {
    public static void main(String[] args) {
        Shape shape1 = new Cylinder(3, 4);
        Shape shape2 = new Cone(2, 5);
        Shape shape3 = new Pyramid(4, 6, 3);
        
        System.out.println("Объем цилиндра " + shape1.area());
        System.out.println("Объем конуса: " + shape2.area());
        System.out.println("Объем пирамиды: " + shape3.area());
    }
}
