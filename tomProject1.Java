// Создаем абстрактный класс, который будет описывать геометрическую фигуру
abstract class Shape {
    // Абстрактный метод для вычисления площади фигуры
    public abstract double getArea();
}

// Класс для описания цилиндра, наследуется от класса Shape
class Cylinder extends Shape {
    private double radius;
    private double height;
    
    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }
    
    // Переопределяем метод getArea для вычисления площади цилиндра
    @Override
    public double getArea() {
        return 2 * Math.PI * radius * (radius + height);
    }
}

// Класс для описания куба, наследуется от класса Shape
class Cube extends Shape {
    private double side;
    
    public Cube(double side) {
        this.side = side;
    }
    
    // Переопределяем метод getArea для вычисления площади куба
    @Override
    public double getArea() {
        return 6 * side * side;
    }
}

// Класс для описания пирамиды, наследуется от класса Shape
class Pyramid extends Shape {
    private double baseLength;
    private double height;
    
    public Pyramid(double baseLength, double height) {
        this.baseLength = baseLength;
        this.height = height;
    }
    
    // Переопределяем метод getArea для вычисления площади пирамиды
    @Override
    public double getArea() {
        return baseLength * baseLength + 2 * baseLength * Math.sqrt((baseLength/2) * (baseLength/2) + height * height);
    }
}

public class Main {
    public static void main(String[] args) {
        // Создаем объекты различных фигур
        Shape cylinder = new Cylinder(3, 5);
        Shape cube = new Cube(4);
        Shape pyramid = new Pyramid(6, 8);
        
        // Выводим результат вычисления площади различных фигур
        System.out.println("Площадь цилиндра: " + cylinder.getArea());
        System.out.println("Площадь куба: " + cube.getArea());
        System.out.println("Площадь пирамиды: " + pyramid.getArea());
    }
}
