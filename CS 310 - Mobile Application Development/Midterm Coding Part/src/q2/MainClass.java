package q2;

public class MainClass {

	public static void main(String[] args) {
		
		Page page1 = new Page(1, "Page 1 Content");
		Page page2 = new Page(2, "Page 2 Content");
		
		Page page3 = new Page(1, "Page 1 Content");
		Page page4 = new Page(2, "Page 2 Content");
		
		
		Page[] chapterPages1 = {page1, page2};
		Page[] chapterPages2 = {page3, page4};
		
		Chapter chapter1 = new Chapter(1, "First Chapter", chapterPages1);
		Chapter chapter2 = new Chapter(1, "First Chapter", chapterPages2);
		
		Chapter[] bookChapters1 = {chapter1};
		Chapter[] bookChapters2 = {chapter2};
		
		Book book1 = new Book("Grapes of Wrath", "Fore word of Grapes Of Wrath", bookChapters1);
		Book book2 = new Book("Introduction to Java", "Fore word of Intro to Java", bookChapters2);
		
		Book[] shelfBooks = {book1, book2};
		
		BookShelf shelf = new BookShelf(shelfBooks);
		
		
		System.out.println(shelf.getInfo());
		Book pickUpBook = shelf.getBook(1);
		System.out.println("Pick up book: " + pickUpBook.getInfo());
	}
}
