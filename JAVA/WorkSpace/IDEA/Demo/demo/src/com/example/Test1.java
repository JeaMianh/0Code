package com.example;

interface Flyable {
    public void fly();
}

abstract class Animal {
    protected int id;
    double weight;
    public Animal (int id, double weight) {
        this.id = id;
        this.weight = weight;
    }
    abstract public void eat();
}
class Bird extends Animal implements Flyable {
    String name;
    public Bird (int id, String name, double weight) {
        super(id, weight);
        this.name = name;
    }
    @Override
    public void eat() {
        weight++;
    }
    @Override
    public void fly() {
        System.out.println("flying");
    }
}
public class Test1 {
}
