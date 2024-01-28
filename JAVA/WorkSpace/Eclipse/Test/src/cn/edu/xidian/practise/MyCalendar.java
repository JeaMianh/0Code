package cn.edu.xidian.practise;

import java.util.Scanner;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class MyCalendar {
	public static void main (String[] args) {
		MyCalendar c = new MyCalendar();
		c.start();
	}
	
	public void start() {
		System.out.println("请选择功能：\n1.打印某年日历\n2.查看某天星期\n3.退出程序\n输入序号选择");
		Scanner input = new Scanner(System.in);
		int choice = input.nextInt();
		Calendar cal = Calendar.getInstance();
		MyCalendar calendar = new MyCalendar();
		if(choice == 1) {
			calendar.printCalendar(cal);;
		}else if(choice == 2) {
			calendar.printDayOfWeek(cal);
		}else if(choice == 3) {
			System.out.println("已退出");
			System.exit(1);
		}
		input.close();
	}
	
	public void printCalendar(Calendar cal) {
		System.out.println("请输入年份：");
		Scanner input = new Scanner(System.in);
		int year = input.nextInt();
		input.close();
		for(int month = 0; month < 12; month++) {
			cal.set(year,month,1);
			int space = cal.get(Calendar.DAY_OF_WEEK) - 1;
			System.out.println("\n" + "====================================================");	
			System.out.println(month + 1 + "月");
			System.out.println("\n" + "日\t一\t二\t三\t四\t五\t六");	
			for(int i = 0; i < space; i++) {
				System.out.print("\t");
			}
			for(int day = 1; day <= cal.getActualMaximum(Calendar.DAY_OF_MONTH); day++) {
				System.out.print(day + "\t");
				if((day + space) % 7 == 0){
					System.out.println();
				}
			}
		}
	}
	
	public void printDayOfWeek(Calendar cal) {
		
		System.out.println("请输入日期（例：1900-1-1）：");
		SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd"); 
        boolean flag = true;  
        Scanner input = new Scanner(System.in); 
        while(flag) {  
             
            String dateTime = input.next();  
            
            try {  
                Date date = dateFormat.parse(dateTime); 
                cal.setTime(date);
                flag = false;  
            } catch (ParseException e) {  
                System.out.println("格式错误，请重新输入：");  
            } 
    	}
        input.close();
		
		int week = cal.get(Calendar.DAY_OF_WEEK);
		switch(week){
			case 1: System.out.println("星期日"); break;
			case 2: System.out.println("星期一"); break;
			case 3:	System.out.println("星期二"); break;
			case 4:	System.out.println("星期三"); break;
			case 5:	System.out.println("星期四"); break;
			case 6:	System.out.println("星期五"); break;
			case 7:	System.out.println("星期六"); break;
		}
	}
}
