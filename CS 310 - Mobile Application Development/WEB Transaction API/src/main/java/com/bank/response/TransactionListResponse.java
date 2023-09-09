package com.bank.response;

import java.util.ArrayList;
import java.util.List;

import com.bank.model.Transaction;

public class TransactionListResponse {

	private String message;
	private List<Transaction> data;
	
	
	
	// Constructor for error cases
	public TransactionListResponse(String message) {
		this.message = message;
	}
	
	public TransactionListResponse(List<Transaction> transaction) {
		this.message = "SUCCESS";
		
		data = new ArrayList<>();
		this.data = transaction;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public List<Transaction> getData() {
		return data;
	}

	public void setData(List<Transaction> data) {
		this.data = data;
	}
	
	
}
