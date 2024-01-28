package com.example;

class Animal1 {
    { System.out.print("感谢大家");}
    Animal1(int id) {
        System.out.println();
        System.out.print("ID" + id);
    }
    Animal1(){
        this(10);
        System.out.print("继续加油");
    }

    static {
        System.out.print("本学期的努力");
    }
}
public class Cat extends Animal1 {
    Cat() {
        System.out.println();
        System.out.print("I am a cat");
    }
    public static void main(String[] args) {
        new Cat();
    }
}
