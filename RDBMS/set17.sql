create table ACCOUNT
(
    AC_NO int PRIMARY KEY,
    NAME VARCHAR(10),
    AC_TYPE VARCHAR(10),
    BALANCE_AMT number(10),
    BALANCE_DATE date
);

insert into ACCOUNT values(1,'NEW ACC','SAVING',10000,'12-AUG-2021');
insert into ACCOUNT values(2,'MID ACC','SAVING',20000,'22-AUG-2021');
insert into ACCOUNT values(3,'OLD ACC','SAVING',30000,'02-AUG-2021');

create table TRANSACTION
(
    AC_NO int REFERENCES ACCOUNT(AC_NO),
    TDATE date,
    TR_TYPE VARCHAR(10),
    AMOUNT number(10),
    PREV_BALANCE number(10),
    REMARK VARCHAR(10)
);

insert into TRANSACTION values(1,'12-SEP-2021','NEW',300,10000,'DONE');
insert into TRANSACTION values(2,'22-SEP-2021','MID',300,20000,'DONE');
insert into TRANSACTION values(3,'02-SEP-2021','OLD',300,30000,'DONE');


-- a. Write a procedure to print the Bank Transaction details by passing from and to dates.
create or replace procedure Bank_Transaction(sd date,ed date)
is
	cursor c1 is 
	select AC_NO,TDATE,TR_TYPE,AMOUNT,PREV_BALANCE 
	from TRANSACTION where TDATE between sd and ed;
begin	
	dbms_output.put_line(rpad('-',65,'-'));
	  dbms_output.put_line(upper(
				rpad('ac_no',10) ||
				rpad('tr_date',10) ||
				rpad('tr_type',10) ||
				rpad('amount',10) ||
				rpad('prev_balance',10) 
			));
	dbms_output.put_line(rpad('-',65,'-'));
	for r in c1 loop
			dbms_output.put_line(upper(
				rpad(r.ac_no,10) ||
				rpad(r.TDATE,10) ||
				rpad(r.tr_type,10) ||
				rpad(r.amount,10) ||
				rpad(r.prev_balance,10) 
			)); 
	end loop;
	dbms_output.put_line(rpad('-',65,'-'));
end;
/

exec Bank_Transaction('12-SEP-2021', '22-SEP-2021');