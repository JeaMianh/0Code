package com.example;

//import java.net.HttpURLConnection;
//
//import java.net.URL;
//
//import java.io.BufferedReader;
//
//import java.io.InputStreamReader;
//
//public class Demo {

//    public static void main(String[] args) {
//
//        try {
//
//            // 创建 URL 对象
//
//            URL url = new URL("http://gldexp.top");
//
//            // 创建 HttpURLConnection 对象，并设置请求方法和请求头信息
//
//            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
//
//            connection.setRequestMethod("GET");
//
//            connection.setRequestProperty("User-Agent", "Java/1.8");
//
//            // 发送请求并获取响应状态码
//
//            int responseCode = connection.getResponseCode();
//
//            System.out.println("Response Code: " + responseCode);
//
//            // 读取响应内容
//
//            BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
//
//            String inputLine;
//
//            StringBuffer response = new StringBuffer();
//
//            while ((inputLine = reader.readLine()) != null) {
//
//                response.append(inputLine);
//
//            }
//
//            reader.close();
//
//            // 打印响应结果
//
//            System.out.println(response.toString());
//
//        } catch (Exception e) {
//
//            e.printStackTrace();
//
//        }
//
//    }
//
//}exp.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

    public class Demo {
        public static void main(String[] args) {
            try {
                URL url = new URL("https://gldexp.top");
                HttpURLConnection con = (HttpURLConnection) url.openConnection();
                con.setRequestMethod("GET");

                BufferedReader in = new BufferedReader(
                        new InputStreamReader(con.getInputStream()));
                String inputLine;
                StringBuffer content = new StringBuffer();
                while ((inputLine = in.readLine()) != null) {
                    content.append(inputLine);
                }
                in.close();

                System.out.println(content.toString());
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }