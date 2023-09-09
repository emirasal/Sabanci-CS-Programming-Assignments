package com.bank.response;

import com.bank.model.Account;

public class AccountReponse {

	private String message;
	private Account data;
	
	// For failed response
	public AccountReponse() {
		this.message = "ERROR:missing fields";
		this.data = null;
	}
	
	// For successful response
	public AccountReponse(Account data) {
		this.message = "SUCCESS";
		this.data = data;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public Account getData() {
		return data;
	}

	public void setData(Account data) {
		this.data = data;
	}
	
}
