package com.example;

import java.awt.*;

public class SwingTest {
    public static void main(String[] argc) {
        Frame frame = new Frame("Test");
//        frame.setLocation(100,100);
//        frame.setSize(500,300);
        //frame.setTitle("This is a test window");
        frame.setVisible(true);
        frame.setBounds(100,100,500,300);

//        Panel panel = new Panel();
//        panel.add(new TextField("this is a test text"));
//        panel.add(new Button("Button"));
//        frame.add(panel);

        ScrollPane scrollPane = new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);
        scrollPane.add(new TextField("Text"));
        scrollPane.add(new Button("Button1"));

        frame.add(scrollPane);


    }
}