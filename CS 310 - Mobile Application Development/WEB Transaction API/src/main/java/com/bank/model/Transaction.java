package com.bank.model;

import java.time.LocalDateTime;

import org.springframework.data.mongodb.core.mapping.DBRef;
import org.springframework.data.mongodb.core.mapping.Document;

@Document
public class Transaction {

	private String id;
	@DBRef
	private Account from;
	@DBRef
	private Account to;
	
	private LocalDateTime createDate;
	private double amount;
	
	public Transaction(Account from, Account to, double amount) {
		this.from = from;
		this.to = to;
		this.amount = amount;
		this.createDate = LocalDateTime.now();
	}


	public Account getFrom() {
		return from;
	}

	public void setFrom(Account from) {
		this.from = from;
	}

	public Account getTo() {
		return to;
	}

	public void setTo(Account to) {
		this.to = to;
	}

	public LocalDateTime getCreateDate() {
		return createDate;
	}

	public void setCreateDate(LocalDateTime createDate) {
		this.createDate = createDate;
	}

	public double getAmount() {
		return amount;
	}

	public void setAmount(double amount) {
		this.amount = amount;
	}


	public String getId() {
		return id;
	}


	public void setId(String id) {
		this.id = id;
	}
	
	
	
}
