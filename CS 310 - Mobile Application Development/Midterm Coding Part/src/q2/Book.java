package q2;

public class Book {

	
	private String title;
	private String foreWord;
	private Chapter [] chapters;
	
	
	
	public Book(String title, String foreWord, Chapter[] chapters) {
		super();
		this.title = title;
		this.foreWord = foreWord;
		this.chapters = chapters;
	}


	public String getInfo() {
		String returnString = "Book: title: " + title + ", foreword:" + foreWord + "\n";
		returnString += "Total Number Of Pages:" + getNumberOfPages() + "\n";
		for (Chapter chapter : chapters) {
			returnString += chapter.getInfo();
		}
		return returnString;
	}
	
	
	public int getNumberOfPages() {
		int count = 0;
		for (Chapter chapter : chapters) {
			count += chapter.getPages().length;
		}
		return count;
	}
	
	
	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getForeWord() {
		return foreWord;
	}

	public void setForeWord(String foreWord) {
		this.foreWord = foreWord;
	}

	public Chapter[] getChapters() {
		return chapters;
	}

	public void setChapters(Chapter[] chapters) {
		this.chapters = chapters;
	}
	
	
	
	
}
