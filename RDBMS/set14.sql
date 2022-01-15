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


create table JOB
(
    jobid int PRIMARY KEY, 
    type_of_job VARCHAR2(10), 
    status VARCHAR2(10)
);


create table ITEM
(
    itemno int PRIMARY KEY, 
    name VARCHAR2(10), 
    color VARCHAR2(10), 
    weight number(5)
)

create table WORKER
(
    workerid int PRIMARY KEY,  
    name VARCHAR2(10), 
    wage_per_hour , 
    specialized_in VARCHAR2(10), 
    manager_id int
);


--1. Write a PLSQL block which will print Employee list (Empno and Name)
--EMP (empno, empnm, empadd, salary, date_birth, joindt, deptno)

Declare
	cursor c1 is  select empno,ename from emp ;
begin	
	dbms_output.put_line(rpad('-',50,'-'));
	dbms_output.put_line(upper(rpad('emp no',20)|| rpad('emp name',20)));	
	dbms_output.put_line(rpad('-',50,'-'));
	for r in c1 loop
		dbms_output.put_line(upper(rpad(r.empno,20)|| rpad(r.ename,20)));
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
	select count(*) into ic_job from job where job_status='incomplete';
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
	select count(*) into icount from item14 where itemcolor=c and itemweight between l and h;
	return(icount);
	
end;
/

declare
	ans number(4);
begin
	ans:=display_item_count('green',10 ,600);
	dbms_output.put_line('number of items : '||ans );
end;
/

-- 4. Write a procedure to display top five highest paid workers who are specialized in ‘PAINTING" using table 
-- WORKER (workerid, name, wage_per_hour, specialized_in,manager_id)
 
Declare
	cursor c1 is 
	select WORKERID, WORKERNAME, WAGE_PER_HOUR, SPECIALIZED_IN,MANAGER_ID 
	from worker  where SPECIALIZED_IN='php' order by wage_per_hour desc;
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
			rpad(r.WORKERID,10)|| rpad(r.WORKERNAME,10)||
			rpad(r.WAGE_PER_HOUR,10)|| rpad(r.SPECIALIZED_IN,10)|| rpad(r.MANAGER_ID,10)
		));
		n:=n+1;
	end loop;
	dbms_output.put_line(rpad('-',50,'-'));
end;
/