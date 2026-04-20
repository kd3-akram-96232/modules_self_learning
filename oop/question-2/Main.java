class Shape {
}

class Shape2D extends Shape {
    double area() { return 0; }
}

class Shape3D extends Shape {
    double volume() { return 0; }
}

class Circle extends Shape2D {
    double r;

    Circle(double r) { this.r = r; }

    double area() {
        return Math.PI * r * r;
    }
}

class Rectangle extends Shape2D {
    double l, w;

    Rectangle(double l, double w) {
        this.l = l;
        this.w = w;
    }

    double area() {
        return l * w;
    }
}

class Sphere extends Shape3D {
    double r;

    Sphere(double r) { this.r = r; }

    double volume() {
        return (4.0 / 3) * Math.PI * r * r * r;
    }
}

class Cube extends Shape3D {
    double a;

    Cube(double a) { this.a = a; }

    double volume() {
        return a * a * a;
    }
}