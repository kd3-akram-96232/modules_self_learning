package org.example;

import org.example.package1.Square;
import org.example.package2.Cube;

public class Main {
    public static void main(String[] args) {
        System.out.println("Org example");

        Square square = new Square(10);
        double area = square.getArea();

        Cube cube = new Cube(10);
        double cubeArea = cube.getArea();

        System.out.println("Square area: "  + area);
        System.out.println("Cube area: "  + cubeArea);

    }
}