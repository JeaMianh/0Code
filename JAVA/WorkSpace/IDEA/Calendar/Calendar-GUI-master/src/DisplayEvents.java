import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.xml.crypto.Data;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.*;

public class DisplayEvents extends JPanel implements ChangeListener {
	
	private DataModel model;
	private JLabel date;
	private JTextArea agenda;
	private ArrayList<Event> scheduale;
	private String day; 
	
	/**
	 * creates the object for the class
	 * using a given data model
	 * @param d
	 */
	public DisplayEvents(DataModel d) {
		model=d;
		setBounds(550, 10, 250, 100);
		date= new JLabel(model.getCurrentDate());
		agenda= new JTextArea();
		agenda.setEditable(false);
		agenda.setPreferredSize(new Dimension(100, 100));
		setLayout(new BorderLayout());
		add(date,BorderLayout.NORTH);
		add(agenda,BorderLayout.CENTER);
		
		setSize(new Dimension(300, 350));
		setVisible(true);
	}
	
	/**
	 * Adds the messages to the
	 * test area
	 */
	public void printToTextArea(){
		Collections.sort(scheduale);
		agenda.setText("");
		for(Event s: scheduale){
			if(s.getDate().equals(day))
			agenda.append(s.getEvent()+"\n");
		}
		agenda.selectAll();
		
	}
	
	/**
	 * state of the changes that happen
	 * in the calendar component.
	 */
	@Override
	public void stateChanged(ChangeEvent e) {
		scheduale=model.getData();
		day=model.getCurrentDate();
		printToTextArea();
		date.setText(model.getCurrentDate());
	}
}
