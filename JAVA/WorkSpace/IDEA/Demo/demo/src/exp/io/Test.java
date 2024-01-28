package exp.io;

import java.io.*;
import java.util.*;

class Statistics {

    private String inputFileName;
    private String outputFileName;
    private int charCount;
    private int wordCount;

    // 定义构造方法，接收输入文件名和输出文件名
    public Statistics(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName;
        this.outputFileName = outputFileName;
        this.charCount = 0;
        this.wordCount = 0;
    }

    // 定义统计方法，实现对输入文件中的英文字符和单词的计数
    public void count() {
        try {
            BufferedReader br = new BufferedReader(new FileReader(inputFileName));
            String line = null;

            while ((line = br.readLine()) != null) {
                line = line.trim().toLowerCase();

                if (!line.isEmpty()) {

                    String[] words = line.split("\\s+");
                    for (String word : words) {
                        if (word.matches("[a-z]+")) {
                            wordCount++;
                        }
                        char[] chars = word.toCharArray();
                        for (char c : chars) {
                            if (c >= 'a' && c <= 'z') {
                                charCount++;
                            }
                        }
                    }
                }
            }

            br.close();
        } catch (IOException e) {
            // 捕获并打印异常信息
            e.printStackTrace();
        }
    }

    // 定义输出方法，实现将统计结果输出到结果文件或屏幕
    public void output(int choice) {
        try {

            BufferedWriter bw = new BufferedWriter(new FileWriter(outputFileName));

            switch (choice) {
                case 1:
                    bw.write("The number of English characters is: " + charCount + "\n");
                    bw.write("The number of English words is: " + wordCount + "\n");
                    bw.flush();
                    bw.close();
                    System.out.println("The statistics result has been written to the file: " + outputFileName);
                    break;
                case 2:
                    System.out.println("The number of English characters is: " + charCount);
                    System.out.println("The number of English words is: " + wordCount);
                    bw.close();
                    break;
                default:
                    System.out.println("Invalid choice!");
                    bw.close();
                    break;
            }
        } catch (IOException e) {
            // 捕获并打印异常信息
            e.printStackTrace();
        }
    }
}

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Please enter the name of the input file: ");
        String inputFileName = sc.nextLine();

        System.out.println("Please enter the name of the output file: ");
        String outputFileName = sc.nextLine();

        Statistics st = new Statistics(inputFileName, outputFileName); // 创建统计对象，传入输入文件名和输出文件名

        st.count(); // 调用统计方法，进行统计

        System.out.println("Please choose where to output the statistics result: "); // 提示用户选择输出位置
        System.out.println("1. Output to the result file");
        System.out.println("2. Output to the screen");
        int choice = sc.nextInt();

        st.output(choice);

        sc.close();

        System.out.println("The program ends.");

    }
}
