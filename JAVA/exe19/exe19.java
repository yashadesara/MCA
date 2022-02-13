class Account
{
	int accountNo,balance;
	
	void checkbalance()
	{
		accountNo=124345;
		balance=10000;
		System.out.println("acc: "+ accountNo + " bal: "+balance);
	}
}

class Savings extends Account
{
	int interestRate;
	
	void withdraw()
	{
		interestRate=balance+interestRate;
		System.out.println("withdraw is: "+interestRate);
	}
	
	void deposit()
	{
		interestRate=(balance*4)/100;
		System.out.println("deposit is: "+interestRate);
	}
	
}

class Current extends Account
{
	int overdraftLimit;
	
	void withdraw()
	{
		overdraftLimit=overdraftLimit;
		if(overdraftLimit<1000)
		{
			System.out.println("current withdraw ammount is: "+overdraftLimit);
		}
		else{
		System.out.println("sorry ");
		}
	}
	
	void deposit()
	{
	overdraftLimit=1000;
	if(overdraftLimit<10000)
	{
		System.out.println("current deposit ammount is less than 10000: "+overdraftLimit);
	}
	else
	{
		System.out.println("current deposit ammount is greater than 10000: "+overdraftLimit);
	}
	}
}

class exe19
{
	public static void main(String args[])
	{
		Savings s = new Savings();
		Current c = new Current();
		
		s.checkbalance();
		s.deposit();
		s.withdraw();
		
		c.checkbalance();
		c.deposit();
		c.withdraw();
	}
}