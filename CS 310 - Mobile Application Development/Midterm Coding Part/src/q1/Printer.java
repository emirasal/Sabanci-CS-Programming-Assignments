package q1;

import java.util.ArrayList;
import java.util.List;

public abstract class Printer {

	public List<Printable> docs = new ArrayList<Printable>(); 
	
	
	public abstract void printOut(Printable printable);
	
	
	public void printAllDocuments() {
		docs.forEach(d -> printOut(d));
	}
	
	public void addDocument(Printable printable) {
		docs.add(printable);
	}
}
