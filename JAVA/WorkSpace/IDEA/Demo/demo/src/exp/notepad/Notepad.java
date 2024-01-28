package exp.notepad;

import java.util.ArrayList;
public class Notepad {
    public ArrayList<String> records = new ArrayList<>();
    public static void printMenu() {
        System.out.println("---------------------");
        System.out.println("1.添加记录");
        System.out.println("2.查看记录");
        System.out.println("3.查看全部记录");
        System.out.println("4.删除记录");
        System.out.println("5.删除全部记录");
        System.out.println("0.退出程序");
        System.out.println("---------------------");
        System.out.println("输入序号选择：");
    }
    public void addRecord(String record) {
        records.add(record);
    }
    public void removeRecord(int index) {
        records.remove(index);
    }
    public void removeAllRecords() {
        records.clear();
    }
    public void showRecord(int index) {
        System.out.println(index + 1 + ":" + records.get(index));
    }
    public void showAllRecords() {
        for(int i = 0; i < records.size(); i++) {
            System.out.println(i + 1 + ":" + records.get(i));
        }
    }
}

