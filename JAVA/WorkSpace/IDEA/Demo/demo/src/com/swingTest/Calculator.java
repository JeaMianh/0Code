package com.swingTest;

import java.awt.*;
public class Calculator {
    public static void main (String[] argc) {
        Frame frame = new Frame("Calculator Test");

//        frame.setBounds(100, 200, 500, 300);
        Panel p = new Panel();
        p.add(new TextField(30));
        frame.add(p, BorderLayout.NORTH);

        Panel p1 = new Panel();
        p1.setLayout(new GridLayout(3, 5, 4, 4));
        for (int i = 0; i < 10; i++) {
            p1.add(new Button(i + ""));
        }
        p1.add(new Button("+"));
        p1.add(new Button("-"));
        p1.add(new Button("*"));
        p1.add(new Button("/"));
        p1.add(new Button("="));
        frame.add(p1);

        frame.setVisible(true);
        frame.pack();
    }
}
