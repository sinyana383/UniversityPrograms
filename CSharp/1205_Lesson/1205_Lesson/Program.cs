using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1205_Lesson
{
    abstract class BankAccount
    {
        protected string accountNumber;               // — номер счёта
        protected string ownerName;                   // — имя владельца
        protected decimal balance;
        public decimal Balance 
        {
            get { return balance; }
            set 
            {
                if (value != balance)
                    return;
                if (balance < value)
                    LogTransaction($"+{value - balance}");
                else if (balance > value)
                    LogTransaction($"-{balance - value}");
                balance = value;
            }
        }                    // — текущий баланс
        protected bool isLocked;                      // — статус блокировки(true — заблокирован)
        protected List<string> transactionHistory;    // — история транзакций

        public BankAccount(string accountNumber = "88005553535", string ownerName = "Ibragim", decimal balance = 1000, bool isLocked = false) 
        {
            this.accountNumber = accountNumber;
            this.ownerName = ownerName;
            this.Balance = balance;
            this.isLocked = isLocked;
            this.transactionHistory = new List<string>();
        }
        public BankAccount(string accountNumber, string ownerName, decimal balance, bool isLocked, List<string> transactionHistory)
        {
            this.accountNumber = accountNumber;
            this.ownerName = ownerName;
            this.Balance = balance;
            this.isLocked = isLocked;
            this.transactionHistory = transactionHistory;
        }
        public virtual void DisplayInfo() //— вывод информации о счёте
        {
            Console.WriteLine($"number: {accountNumber}\nname: {ownerName}\nbalance: {Balance}\n" +
                $"isLocked: {isLocked}");
            foreach (var item in transactionHistory) 
            {
                Console.WriteLine(item);
            }
        }

        void Deposit(decimal amount) //— пополнение счёта
        { 
            Balance += amount;
        }
        public virtual bool Withdraw(decimal amount) //— снятие средств
        {
            if (Balance - amount < 0) 
            {
                Console.WriteLine($"Сумма для снятия превышает баланс");
                return false;
            }
            Balance -= amount;
            return true;
        }
        public List<string> GetTransactionHistory() //— получить всю историю
        {
            return transactionHistory;
        }
        public List<string> GetDeposits() //— получить только пополнения
        {
            List<string> result = new List<string>();

            foreach (var transaction in transactionHistory) 
            {
                if (transaction.StartsWith("+"))
                    result.Add(transaction);
            }
            return result;
        }
        public List<string> GetWithdrawals() //— получить только списания
        {
            List<string> result = new List<string>();

            foreach (var transaction in transactionHistory)
            {
                if (transaction.StartsWith("-"))
                    result.Add(transaction);
            }
            return result;
        }
        void LockAccount() //— блокировать счёт
        {
            isLocked = true;
        }
        void UnlockAccount() //— разблокировать счёт
        {
            isLocked = false;
        }
        protected void LogTransaction(string message) //— запись транзакции в лог
        {
            transactionHistory.Add(message);
        }
    }

    class SavingsAccount : BankAccount 
    {
        double interestRate;
        public double InterestRate 
        {  
            get { return interestRate; }
            set 
            {
                if (value < 0) 
                {
                    Console.WriteLine("Ставка не может быть отрицательной");
                    return;
                }
                interestRate = value;
            }
        }

        public SavingsAccount(string accountNumber = "88005553535", string ownerName = "Ibragim", decimal balance = 1000, bool isLocked = false, double interestRate = 0.10) : base(accountNumber, ownerName, balance, isLocked)
        {
            this.InterestRate = interestRate;
        }
        public SavingsAccount(string accountNumber, string ownerName, decimal balance, bool isLocked, List<string> transactionHistory, double interestRate) : base(accountNumber, ownerName, balance, isLocked)
        {
            this.InterestRate = interestRate;
        }

        public void ApplyInterest() //— начисление процентов
        {
            Balance += (decimal)((double)Balance * this.InterestRate);
        }
        public void ChangeInterestRate(double newRate) //— изменить процентную ставку
        {
            InterestRate = newRate;
        }
        public override void DisplayInfo() //— вывод дополнительной информации
        {
            base.DisplayInfo();
            Console.WriteLine($"Interest rate: {InterestRate}");
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            SavingsAccount account = new SavingsAccount();
            account.DisplayInfo();
        }
    }
}
