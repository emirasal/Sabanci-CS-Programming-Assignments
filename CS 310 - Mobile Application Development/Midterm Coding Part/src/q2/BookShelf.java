package q2;

public class BookShelf {

	private Book books [];
	
	
	public BookShelf(Book[] books) {
		super();
		this.books = books;
	}


	public String getInfo() {
		String returnString = "BookShelf: \n" + "Total number of books:" + books.length + "\n";
		for (Book book : books) {
			returnString +=  book.getInfo() + "\n";
		}
		return returnString; 
		
	}
	
	
	public Book getBook(int index) {
		return books[index];
	}
	
	public int getTotalNumberOfBooks() {
		return books.length;
	}

	
	
	public Book[] getBooks() {
		return books;
	}

	public void setBooks(Book[] books) {
		this.books = books;
	}
	
	
}
