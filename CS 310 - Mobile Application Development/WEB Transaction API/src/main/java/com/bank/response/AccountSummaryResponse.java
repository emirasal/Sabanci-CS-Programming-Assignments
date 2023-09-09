package com.bank.response;

public class AccountSummaryResponse {

	private String message;
	private AccountData data;
	
	public AccountSummaryResponse(String message) {
		this.message = message;
	}
	
	public AccountSummaryResponse(AccountData data) {
		this.message = "SUCCESS";
		this.data = data;
	}
	
	

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public AccountData getData() {
		return data;
	}

	public void setData(AccountData data) {
		this.data = data;
	}
	
}
