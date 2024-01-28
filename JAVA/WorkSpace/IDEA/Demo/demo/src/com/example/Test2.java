package com.example;

public class Test2 {
    public static void main(String[] args) {
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < a.length/2; i++) {
            System.out.print(a[i] + a[a.length - i - 1] + ".");
            if(i%2 == 0)System.out.println();
        }
    }
}
