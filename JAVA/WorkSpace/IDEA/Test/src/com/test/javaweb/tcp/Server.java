package com.test.javaweb.tcp;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class Server {
    public static void main (String[] args) throws IOException {
        ServerSocket ss = new ServerSocket (6666);
        System.out.println ("server is running");
        for (;;) {
            Socket sock = ss.accept ();
            System.out.println ("connect from " + sock.getRemoteSocketAddress ());
            Thread t = new Handler (sock);
            t.start ();
        }
    }
}

class Handler extends Thread {
    Socket sock;
    public Handler (Socket sock) {
        this.sock = sock;
    }
    @Override
    public void run() {
        try (InputStream input = this.sock.getInputStream()) {
            try (OutputStream output = this.sock.getOutputStream()) {
                handle (input, output);
            }
        } catch (Exception e) {
            try {
                this.sock.close();
            } catch (IOException ioe) {
            }
            System.out.println("Client disconnected.");
        }
    }
    private void handle(InputStream input, OutputStream output) throws IOException {
        var write = new BufferedWriter(new OutputStreamWriter(output, StandardCharsets.UTF_8));
        var reader = new BufferedReader(new InputStreamReader(input, StandardCharsets.UTF_8));
        write.write("hello\n");
        write.flush();
        for (;;) {
            String s =  reader.readLine();
            if (s.equals("bye")) {
                write.write("bye\n");
                write.flush();
                break;
            }
            write.write("ok:" + s + "\n");
            write.flush();
        }
    }
}
