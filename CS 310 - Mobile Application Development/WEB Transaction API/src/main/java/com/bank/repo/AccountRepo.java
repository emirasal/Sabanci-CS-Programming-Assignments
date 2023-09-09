package com.bank.repo;

import java.util.Optional;

import org.springframework.data.mongodb.repository.MongoRepository;

import com.bank.model.Account;

public interface AccountRepo extends MongoRepository<Account, String>{

	public Optional<Account> findById(String id);
}
