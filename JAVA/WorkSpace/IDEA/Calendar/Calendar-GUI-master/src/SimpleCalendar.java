import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

import javax.swing.*;

public class SimpleCalendar {

	public static void main(String[] args) {
		DataModel model = null;
		File stuff = new File("Events.ser");

		try {
			if (stuff.exists() ) {

				FileInputStream fileIn = new FileInputStream(stuff);
				if(fileIn.read()!=-1){
					ObjectInputStream in = new ObjectInputStream(fileIn);
					model = (DataModel) in.readObject();
					in.close();
					fileIn.close();
				}
				else{
					model = new DataModel();
				}
			} else {
				stuff.createNewFile();
				model = new DataModel();
			}
		} catch (IOException i) {
			i.printStackTrace();
			return;
		} catch (ClassNotFoundException c) {
			System.out.println("Employee class not found");
			c.printStackTrace();
			return;
		}
			new MyCalendar(model);

		}	
}
