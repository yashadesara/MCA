create table EEmployee
(
    eid int PRIMARY KEY,
    fname VARCHAR(8),
    lname VARCHAR(8),
    salary number(6)
);

insert into EEmployee values(1,'MR.SHAH','BHAI',10000);
insert into EEmployee values(2,'MR.VIRA','BHAIJAAN',20000);
insert into EEmployee values(3,'MR.MEHTA','BRO',30000);


--Employee (eid, fname, lname, salary)
/* 1. Use a Cursor for Loop inside a function to calculate and return total paid salary to all employees by the company. */

create or replace function total_paid_salary
return number
is
	tot_sal number(8);	
	cursor c1 is 
	select eid,fname,lname,salary from EEmployee;	
begin	
	tot_sal:=0;
	 for r in c1 loop
			tot_sal:=tot_sal+r.salary;			 
	end loop;
	return(tot_sal);
end;
/

declare
	ans number(8);
begin
	ans:=total_paid_salary;
	dbms_output.put_line('number of items : '||ans );
end;
/

-- 2. Modify the function created above to become a procedure and display the total paid salary
-- from the procedure itself. Instead of calculating for all employees, calculate only for those
-- employees whose name starts from a character passed as parameter to the procedure and
-- hence to the cursor.

create or replace procedure total_paid_salary_of_emp(ch varchar2)
is
	tot_sal number(8);	
	cursor c1 is 
	select eid,fname,lname,salary from EEmployee where fname like ch||'%';	
begin	
	tot_sal:=0;
	 for r in c1 loop
			tot_sal:=tot_sal+r.salary;			 
	end loop;
	dbms_output.put_line('Total Salary : '||tot_sal );
end;
/

exec total_paid_salary_of_emp('M');