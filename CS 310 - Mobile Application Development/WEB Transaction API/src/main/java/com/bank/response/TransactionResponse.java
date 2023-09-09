package com.bank.response;

import com.bank.model.Transaction;


public class TransactionResponse {

	private String message;
	private Transaction data;
	
	// Constructor for error cases
	public TransactionResponse(String message) {
		this.message = message;
	}
	
	public TransactionResponse(Transaction transaction) {
		this.message = "SUCCESS";
		this.data = transaction;
	}

	
	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public Transaction getData() {
		return data;
	}

	public void setData(Transaction data) {
		this.data = data;
	}

	
}
