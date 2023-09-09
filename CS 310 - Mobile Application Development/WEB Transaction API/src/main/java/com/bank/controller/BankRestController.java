package com.bank.controller;

import java.util.List;
import java.util.Optional;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.bank.model.Account;
import com.bank.model.Transaction;
import com.bank.model.TransactionPayLoad;
import com.bank.repo.AccountRepo;
import com.bank.repo.TransactionRepo;
import com.bank.response.AccountData;
import com.bank.response.AccountReponse;
import com.bank.response.AccountSummaryResponse;
import com.bank.response.TransactionListResponse;
import com.bank.response.TransactionResponse;

@RestController
@RequestMapping("/")
public class BankRestController {

	@Autowired private AccountRepo accountRepository;
	@Autowired private TransactionRepo transactionRepository; 
	
	@PostConstruct
	public void init() {
		if(accountRepository.count() == 0 && transactionRepository.count() == 0) {
			Account user1 = new Account("1111", "Emir Asal");
			Account user2 = new Account("2222", "Mahmut Kaya");
			
			accountRepository.save(user1);
			accountRepository.save(user2);
			
			// Transactions
			Transaction transfer1 = new Transaction(user1, user2, 1500);
			Transaction transfer2 = new Transaction(user2, user1, 2500);
			
			transactionRepository.save(transfer1);
			transactionRepository.save(transfer2);
		}
	}
	
	@PostMapping("account/save")
	public AccountReponse saveAccount(@RequestBody Account account) {
		
		if(account.getId() == null || account.getOwner() == null) {
			return new AccountReponse();
		}
		
		Account savedAccount = accountRepository.save(account);
		return new AccountReponse(savedAccount);		
	}
	
	@PostMapping("transaction/save")
	public TransactionResponse saveTransaction(@RequestBody TransactionPayLoad transaction) {
		
		if (transaction.getFromAccountId() == null || transaction.getToAccountId() == null 
				|| transaction.getAmount() == 0) {
			return new TransactionResponse("ERROR:missing fields");
		}
		
		
		Optional<Account> from = accountRepository.findById(transaction.getFromAccountId());
	    Optional<Account> to = accountRepository.findById(transaction.getToAccountId());
		
		
		if(from.isEmpty() || to.isEmpty()) {
			return new TransactionResponse("ERROR: account id");
		}
		
	    Transaction newTransaction = new Transaction(from.get(), to.get(), transaction.getAmount());
	    
	    Transaction sendTransaction = transactionRepository.save(newTransaction);
	    return new TransactionResponse(sendTransaction);
	}
	
	
	@GetMapping("/account/{accountId}")
	public AccountSummaryResponse accountInfo(@PathVariable String accountId) {
		Optional<Account> account = accountRepository.findById(accountId);
		
		// Input check
		if(account.isEmpty()) {
			return new AccountSummaryResponse("ERROR:account doesnt exist!");
		}
		
		AccountData data = new AccountData(account.get());
		List<Transaction> inTransaction = transactionRepository.findByTo(account.get());
		List<Transaction> outTransaction = transactionRepository.findByFrom(account.get());
		data.setTransactionsIn(inTransaction);
		data.setTransactionsOut(outTransaction);
		data.calculateBalance();
		return new AccountSummaryResponse(data);
	}
	
	
	
	@GetMapping("/transaction/to/{accountId}")
	public TransactionListResponse transactionsTo(@PathVariable String accountId) {
		Optional<Account> account = accountRepository.findById(accountId);
		
		// Input check
		if (account.isEmpty()) {
			return new TransactionListResponse("ERROR:account doesn’t exist");
		}
		
		List<Transaction> transactionList = transactionRepository.findByTo(account.get());
		return new TransactionListResponse(transactionList);
	}
	
	@GetMapping("/transaction/from/{accountId}")
	public TransactionListResponse transactionsFrom(@PathVariable String accountId) {
		Optional<Account> account = accountRepository.findById(accountId);
		
		
		// Input check
		if (account.isEmpty()) {
			return new TransactionListResponse("ERROR:account doesn’t exist");
		}
		
		List<Transaction> transactionList = transactionRepository.findByFrom(account.get());
		return new TransactionListResponse(transactionList);
	}
	
}
