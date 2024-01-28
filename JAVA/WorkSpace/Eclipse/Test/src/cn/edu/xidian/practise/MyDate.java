package cn.edu.xidian.practise;
class UseMyDate{
	private int day;
	private int month;
	private int year;
 
	public String getdate(){
		return day +"/"+month+"/"+year;
	}


	public int setDate(int a,int b,int c) {
		if((a>0&&a<=31)&&(b>0&&b<=12)) {
			day = a;
			month = b;
			year = c;
			return 0;
		}
		else {
			return -1;
		}
	}
}

public class MyDate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		UseMyDate d =new UseMyDate();
		if(d.setDate(22, 5, 2009)==0) {
			System.out.print(d.getdate());
		}
	}
}
