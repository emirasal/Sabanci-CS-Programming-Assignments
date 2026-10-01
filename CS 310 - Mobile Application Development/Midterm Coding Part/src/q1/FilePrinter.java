package q1;

public class FilePrinter extends Printer {

	private String filename;
	
	public FilePrinter(String filename) {
		super();
		this.filename = filename;
	}
	
	
	@Override
	public void printOut(Printable p) {
		System.out.println("Data printed to the file: " + filename);
		System.out.println(p.getContent());
	}
	
}
