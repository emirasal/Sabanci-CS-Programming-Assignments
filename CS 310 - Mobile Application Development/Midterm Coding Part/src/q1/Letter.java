package q1;

public class Letter implements Printable {

	
	private String sender;
	private String reciever;
	private String textContent;
	
	
	public Letter(String sender, String reciever, String textContent) {
		super();
		this.sender = sender;
		this.reciever = reciever;
		this.textContent = textContent;
	}


	@Override
	public String getContent() {
		return "Letter [sender=" + sender + ", reciever=" + reciever + ", textContent=" + textContent + "]";
	}

}
