package com.bank.response;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import com.bank.model.Account;
import com.bank.model.Transaction;

public class AccountData {

	private String id;
	private String owner;
	private LocalDateTime createDate;
	private List<Transaction> transactionsOut = new ArrayList<>();
	private List<Transaction> transactionsIn = new ArrayList<>();
	private double balance = 0;
	
	
	public AccountData(Account account) {
		this.id = account.getId();
		this.owner = account.getOwner();
		this.createDate = account.getCreateDate();
	}
	
	public void calculateBalance() {
		for (Transaction transaction : transactionsIn) {
			balance += transaction.getAmount();
		}
		for (Transaction transaction : transactionsOut) {
			balance -= transaction.getAmount();
		}
	}
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getOwner() {
		return owner;
	}
	public void setOwner(String owner) {
		this.owner = owner;
	}
	public LocalDateTime getCreateDate() {
		return createDate;
	}
	public void setCreateDate(LocalDateTime createDate) {
		this.createDate = createDate;
	}
	public List<Transaction> getTransactionsOut() {
		return transactionsOut;
	}
	public void setTransactionsOut(List<Transaction> transactionsOut) {
		this.transactionsOut = transactionsOut;
	}
	public List<Transaction> getTransactionsIn() {
		return transactionsIn;
	}
	public void setTransactionsIn(List<Transaction> transactionsIn) {
		this.transactionsIn = transactionsIn;
	}
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
			
	
	
	
}
