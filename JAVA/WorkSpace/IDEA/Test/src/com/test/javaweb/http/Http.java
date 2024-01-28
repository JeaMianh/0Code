package com.test.javaweb.http;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Handler;

public class Http {
    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(8080);
        System.out.println("Server is running");
        while(true) {
            Socket socket = ss.accept();
            System.out.println("connect from " + socket.getRemoteSocketAddress());
            Thread t = new Handler(socket);
            t.start();
        }
    }
}

class Handler extends Thread {
    Socket socket;
    public Handler(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try(InputStream input = this.socket.getInputStream()) {
            try(OutputStream output = this.socket.getOutputStream()) {
                handle(input,output);
            }
        } catch(Exception e) {
        } finally {
            try {
                this.socket.close();
            } catch (IOException ioe) {
            }
            System.out.println("Client disconneted.");
        }
    }
    private void handle(InputStream input, OutputStream output) throws IOException {

    }
}
