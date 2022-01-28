create table EMP
(
    empno int PRIMARY KEY, 
    empnm VARCHAR2(10), 
    empadd VARCHAR2(10), 
    salary number(6), 
    date_birth date, 
    joindt date, 
    deptno number(5)
);

insert into EMP values(1,'ABC','DUBAI',30000,'10-AUG-2000','12-AUG-2021',1);
insert into EMP values(2,'PQR','US',40000,'12-AUG-2000','14-AUG-2021',2);
insert into EMP values(3,'XYZ','UK',50000,'14-AUG-2000','16-AUG-2021',3);


create table JOB
(
    jobid int PRIMARY KEY, 
    type_of_job VARCHAR2(10), 
    status VARCHAR2(10)
);

insert into JOB values(1,'DEVELOPER','Running');
insert into JOB values(2,'CODER','Running');
insert into JOB values(3,'TESER','Running');
insert into JOB values(4,'NEWTESER','incomplete');

create table IITEM
(
    itemno int PRIMARY KEY, 
    name VARCHAR2(10), 
    color VARCHAR2(10), 
    weight number(5)
);

insert into IITEM values(1,'MOUSE','BLACK',50);
insert into IITEM values(2,'KEYBOARD','BLACK',150);
insert into IITEM values(3,'WIRE','BLACK',20);

create table WORKER
(
    workerid int PRIMARY KEY,  
    name VARCHAR2(10), 
    wage_per_hour VARCHAR2(10), 
    specialized_in VARCHAR2(10), 
    manager_id int
);

insert into WORKER values(1,'SHAH','10','CODING',1);
insert into WORKER values(2,'MEHTA','20','TESTING',2);
insert into WORKER values(3,'VIRANI','30','DEVELOPING',3);


--1. Write a PLSQL block which will print Employee list (Empno and Name)
--EMP (empno, empnm, empadd, salary, date_birth, joindt, deptno)

Declare
	cursor c1 is  select empno,empnm from emp;
begin	
	dbms_output.put_line(rpad('-',50,'-'));
	dbms_output.put_line(upper(rpad('emp no',20)|| rpad('emp name',20)));	
	dbms_output.put_line(rpad('-',50,'-'));
	for r in c1 loop
		dbms_output.put_line(upper(rpad(r.empno,20)|| rpad(r.empnm,20)));
	end loop;
	dbms_output.put_line(rpad('-',50,'-'));
end;
/

--2. Write a function that returns total number of incomplete jobs, using table JOB (jobid, type_of_job, status)

create or replace function incomplete_job_count
return number
is
	ic_job number(4);	 
begin	
	select count(*) into ic_job from job where status='incomplete';
	return(ic_job);
end;
/

declare
	ans number(4);
begin
	ans:=incomplete_job_count;
	dbms_output.put_line('total number of incomplete jobs : '||ans );
end;
/


-- 3. Write a function which displays the number of items whose weight fall between a
-- given ranges for a particular color using table ITEM (itemno, name, color, weight)

create or replace function display_item_count(c varchar2,l number,h number)
return number
is
	icount number(4);	 
begin	
	select count(*) into icount from IITEM where color=c and weight between l and h;
	return(icount);
end;
/

declare
	ans number(4);
begin
	ans:=display_item_count('BLACK',10 ,600);
	dbms_output.put_line('number of items : '||ans );
end;
/

-- 4. Write a procedure to display top five highest paid workers who are specialized in ‘PAINTING" using table 
-- WORKER (workerid, name, wage_per_hour, specialized_in,manager_id)
 
Declare
	cursor c1 is 
	select WORKERID, name, WAGE_PER_HOUR, SPECIALIZED_IN, MANAGER_ID 
	from worker  where SPECIALIZED_IN='CODING' order by wage_per_hour desc;
	n number;
begin		
	n:=1;
	dbms_output.put_line(rpad('-',50,'-'));
	dbms_output.put_line(upper(
			rpad('ID',10)|| rpad('NAME',10)||
			rpad('WPH',10)|| rpad('SP_IN',10)|| rpad('MGR_ID',10)
		));
	dbms_output.put_line(rpad('-',50,'-'));
	for r in c1 loop
		if n>5 then
			EXIT ;
		end if;	
		dbms_output.put_line(upper(
			rpad(r.WORKERID,10)|| rpad(r.name,10)||
			rpad(r.WAGE_PER_HOUR,10)|| rpad(r.SPECIALIZED_IN,10)|| rpad(r.MANAGER_ID,10)
		));
		n:=n+1;
	end loop;
	dbms_output.put_line(rpad('-',50,'-'));
end;
/