package q1;

import java.time.LocalDateTime;

public class MainClass {

	
	public static void main(String[] args) {
		
		Report report = new Report("Final Exam", "I am trying to complete the question, yeah still!", LocalDateTime.now());
		Letter letter = new Letter("Jack", "Henry", "Letter content");
		SpreadSheet spreadsheet = new SpreadSheet("Budget", 10, 10);
		
		
		FilePrinter fileprinter = new FilePrinter("output1.txt");
		fileprinter.docs.add(report);
		fileprinter.docs.add(spreadsheet);
		fileprinter.docs.add(letter);
		
		
		ConsolePrinter consoleprinter = new ConsolePrinter();
		consoleprinter.docs.add(report);
		consoleprinter.docs.add(spreadsheet);
		consoleprinter.docs.add(letter);
		
		
		fileprinter.printAllDocuments();
		consoleprinter.printAllDocuments();
	}
}
