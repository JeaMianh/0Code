import java.io.Serializable;
import java.util.ArrayList;

import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class DataModel implements Serializable {
	
	ArrayList<ChangeListener> listeners;
	ArrayList<Event> data;
	private String currentDate;

	/**
	 * constructs the model object
	 */
	public DataModel() {
		this.listeners = new ArrayList<>();
		this.data = new ArrayList<>();
	}

	/**
	 * Constructs a DataModel object
	 * 
	 * @return the data in an ArrayList
	 */
	public ArrayList<Event> getData() {
		return (ArrayList<Event>) (data.clone());
	}

	/**
	 * sets the current date of the calendar
	 */
	public void setCurrentDate(String d) {
		currentDate = d;
	}

	/**
	 * returns the current date from the calendar class
	 * 
	 * @return currentDate
	 */
	public String getCurrentDate() {
		return currentDate;
	}

	/**
	 * Attach a listener to the Model
	 * 
	 * @param c
	 *            the listner
	 */
	public void attach(ChangeListener c) {
		listeners.add(c);
	}

	/**
	 * adds a message to the string Arraylist
	 * 
	 * @param message
	 */
	public void update(Event message) {
		data.add(message);
		for (ChangeListener l : listeners) {
			l.stateChanged(new ChangeEvent(this));
		}
	}
	/**
	 * updates the current date for the views
	 */
	public void updateDate(){
		for (ChangeListener l : listeners) {
			l.stateChanged(new ChangeEvent(this));
		}
	}

}
