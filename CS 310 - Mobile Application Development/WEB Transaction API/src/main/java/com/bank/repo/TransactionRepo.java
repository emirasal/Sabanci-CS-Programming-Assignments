package com.bank.repo;

import java.util.List;

import org.springframework.data.mongodb.repository.MongoRepository;

import com.bank.model.Account;
import com.bank.model.Transaction;

public interface TransactionRepo extends MongoRepository<Transaction, String> {

	public List<Transaction> findByTo(Account account);
	public List<Transaction> findByFrom(Account account);
}
