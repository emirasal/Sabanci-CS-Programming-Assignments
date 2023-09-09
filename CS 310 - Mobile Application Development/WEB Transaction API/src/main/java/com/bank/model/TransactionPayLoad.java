package com.bank.model;


public class TransactionPayLoad {

	private String fromAccountId;
	private String toAccountId;
	private double amount = 0; // means null at first
	
	public TransactionPayLoad(String fromId, String toId, double amount) {
		this.fromAccountId = fromId;
		this.toAccountId = toId;
		this.amount = amount;
	}

	public String getFromAccountId() {
		return fromAccountId;
	}

	public void setFromAccountId(String fromAccountId) {
		this.fromAccountId = fromAccountId;
	}

	public String getToAccountId() {
		return toAccountId;
	}

	public void setToAccountId(String toAccountId) {
		this.toAccountId = toAccountId;
	}

	public double getAmount() {
		return amount;
	}

	public void setAmount(double amount) {
		this.amount = amount;
	}
	
}
