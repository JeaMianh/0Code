package cn.edu.xidian.practise;

public class Comutil {
	public static Object max(MyComparable[] objs) {
		if(objs == null || objs.length == 0) {
			return null;
		}
		MyComparable max = objs[0];
		for(int i = 1; i < objs.length; i++) {
			if(max.compareTo(objs[i] )< 0) {
				max = objs[i];
			}
		}
		return max;
	}
}
