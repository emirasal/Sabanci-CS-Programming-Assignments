package q1;

public class ConsolePrinter extends Printer {

	@Override
	public void printOut(Printable p) {
		System.out.println("Data is Printed to console:");
		System.out.println(p.getContent());		
	}
	
}
