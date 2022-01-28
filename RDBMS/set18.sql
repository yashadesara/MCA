create table BRANCH
(
    branch_no int PRIMARY KEY,
    area VARCHAR(10),
    city VARCHAR(10)
);

insert into BRANCH values(1,'PATEL COLONY','JAM');
insert into BRANCH values(2,'BAAG','RJKT');
insert into BRANCH values(3,'M.G ROAD','RJKT');

create table MEMBERS
(
    mno int PRIMARY KEY,
    name VARCHAR(10),
    branch_no int REFERENCES BRANCH(branch_no),
    salary number(6),
    manager_no int
);

insert into MEMBERS values(1,'SHAH',1,10000,1);
insert into MEMBERS values(2,'VIRANI',2,20000,2);
insert into MEMBERS values(3,'MEHTA',3,30000,3);
insert into MEMBERS values(4,'MRMEHTA',3,10000,3);



--1. Write a procedure which list the name of members who earns more than that of his managers.
create or replace procedure members_erans_higher
is
	cursor c1 is 
	select a.mno, a.name, a.salary as mem_salary, b.manager_no, b.salary as mgr_salary 
	from members a,members b 
	where a.mno=b.manager_no and a.salary > b.salary;
begin	
	dbms_output.put_line(rpad('-',65,'-'));
	  dbms_output.put_line(upper(	 
				rpad('mname',10) ||
				rpad('salary',10) 
			));
	dbms_output.put_line(rpad('-',65,'-'));
	for r in c1 loop
			dbms_output.put_line(upper(
				rpad(r.name,10) ||
				rpad(r.mem_salary,10) 
			)); 
	end loop;
	dbms_output.put_line(rpad('-',65,'-'));
end;
/
exec members_erans_higher


--2. Write a procedure which gives details of employee having maximum salary branch wise.
create or replace procedure emp_grp_max_sal
is
	cursor c1 is 
	select branch_no,max(salary) as mx_salary from members group by branch_no;
begin	
	dbms_output.put_line(rpad('-',65,'-'));
	  dbms_output.put_line(upper( 
				rpad('branch_no',10) ||
				rpad('mx_salary',10)
			));
	dbms_output.put_line(rpad('-',65,'-'));
	for r in c1 loop
			dbms_output.put_line(upper(
				rpad(r.branch_no,10) ||
				rpad(r.mx_salary,10) 
			)); 
	end loop;
	dbms_output.put_line(rpad('-',65,'-'));
end;
/

exec emp_grp_max_sal
