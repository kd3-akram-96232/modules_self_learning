package org.example.package1;

public class Square {

    double val;

    public Square(){
        this.val = 0;
    }
    public Square(double val){
        this.val = val;
    }

    public double getArea(){
        return val * val;
    }

}
