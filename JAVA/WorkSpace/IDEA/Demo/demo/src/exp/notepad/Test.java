package exp.notepad;

import java.util.Scanner;
public class Test {
    public static void main (String[] args) {
        Notepad notepad = new Notepad();
        Scanner input = new Scanner(System.in);
        while (true) {
            Notepad.printMenu();
            int choice = input.nextInt();
            switch (choice) {
                case 0 -> { // 退出程序
                    System.out.println("退出成功");
                    return;
                }
                case 1 -> { // 添加记录
                    System.out.println("请输入内容：");
                    input.nextLine();
                    String record = input.nextLine();
                    notepad.addRecord(record);
                    System.out.println("储存成功，序号为" + notepad.records.size());
                }
                case 2 -> { // 查看记录
                    if (notepad.records.size() == 0) {
                        System.out.println("当前暂无记录");
                        break;
                    }
                    System.out.println("请输入序号：");
                    int number = input.nextInt();
                    if (notepad.records.size() < number) {
                        System.out.println("当前最大序号为" + notepad.records.size());
                        System.out.println("请重新输入：");
                        number = input.nextInt();
                        notepad.showRecord(number - 1);
                        break;
                    }
                    notepad.showRecord(number - 1 );
                }
                case 3 -> { // 查看所有记录
                    if (notepad.records.size() == 0) {
                        System.out.println("当前暂无记录");
                        break;
                    }
                    notepad.showAllRecords();
                }
                case 4 -> { // 删除记录
                    if (notepad.records.size() == 0) {
                        System.out.println("当前暂无记录");
                        break;
                    }
                    System.out.println("请输入序号：");
                    int number = input.nextInt();
                    if (notepad.records.size() < number) {
                        System.out.println("该项不存在");
                        break;
                    }
                    System.out.println("确认要删除吗（y/n）：");
                    String choose = input.next();
                    if (choose.equals("y")) {
                        notepad.removeRecord(number - 1);
                        System.out.println("删除成功");
                    }
                }
                case 5 -> { // 删除全部记录
                    if (notepad.records.size() == 0) {
                        System.out.println("当前暂无记录");
                        break;
                    }
                    System.out.println("确认要全部删除吗（y/n）：");
                    String choose = input.next();
                    if (choose.equals("y")) {
                        notepad.removeAllRecords();
                        System.out.println("删除成功");
                    }
                }
                default -> System.out.println("输入错误，请重新选择");
            }
        }
    }
}
