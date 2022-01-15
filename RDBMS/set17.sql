create table ACCOUNT
(
    AC_NO int PRIMARY KEY,
    NAME VARCHAR(10),
    AC_TYPE VARCHAR(10),
    BALANCE_AMT number(10),
    BALANCE_DATE date
);

create table TRANSACTION
(
    AC_NO int REFERENCES AC_NO(ACCOUNT),
    DATE date,
    TR_TYPE VARCHAR(10),
    AMOUNT number(10),
    PREV_BALANCE number(10),
    REMARK VARCHAR(10)
);



-- a. Write a procedure to print the Bank Transaction details by passing from and to dates.
create or replace procedure Bank_Transaction(sd date,ed date)
is
	cursor c1 is 
	select tr_id,ac_no,tr_date,tr_type,amount,prev_balance 
	from transection where tr_date between sd and ed;
begin	
	dbms_output.put_line(rpad('-',65,'-'));
	  dbms_output.put_line(upper(
				rpad('tr_id',10) ||
				rpad('ac_no',10) ||
				rpad('tr_date',10) ||
				rpad('tr_type',10) ||
				rpad('amount',10) ||
				rpad('prev_balance',10) 
			));
	dbms_output.put_line(rpad('-',65,'-'));
	for r in c1 loop
		
			dbms_output.put_line(upper(
				rpad(r.tr_id,10) ||
				rpad(r.ac_no,10) ||
				rpad(r.tr_date,10) ||
				rpad(r.tr_type,10) ||
				rpad(r.amount,10) ||
				rpad(r.prev_balance,10) 
			)); 
		
	end loop;
	dbms_output.put_line(rpad('-',65,'-'));
end;
/

exec Bank_Transaction('1-jan-2021', '3-mar-2021');