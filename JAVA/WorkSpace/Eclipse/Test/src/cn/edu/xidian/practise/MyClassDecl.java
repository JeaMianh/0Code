package cn.edu.xidian.practise;

import java.awt.*;
import static java.lang.Math.PI;
public class MyClassDecl {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        Circle yuan = new Circle(new Point(2,1),3);
        yuan.draw();
        System.out.println(yuan.area());
    }
}
abstract class Shape{
    private String color;
    public abstract void draw();
    public void setColor( String color ){
        this.color = color;
    }
    public String getColor(){
        return color;
    }
//    public abstract void erase();
//    public abstract void move();

}

class Square extends Shape{
    private Point northeastPoint;
    private double width;
    private double height;
    public Square(Point northeastPoint,double width,double height){
        this.northeastPoint = northeastPoint;
        this.width = width;
        this.height = height;
    }
    public double area(){
        return width*height;
    }
	@Override
	public void draw() {
		System.out.println("draw a Square");
		
	}
}

class Circle extends Shape{
    private Point center;
    double radius;
    public Circle(Point center,double radius){
        this.center = center;
        this.radius = radius;
    }
    public double area(){
        return PI*radius*radius;
    }
    @Override
	public void draw() {
		System.out.println("draw a Circle");
		
	}
}
final class Triangle extends Shape {
    private Point[] point = new Point[3];

    public Triangle(Point[] point1, Point[] point2, Point[] point3) {
        this.point[0] = point[0];
        this.point[1] = point[1];
        this.point[2] = point[2];
    }
    @Override
	public void draw() {
		System.out.println("draw a Triangle");
		
	}
}