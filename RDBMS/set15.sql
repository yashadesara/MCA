create table DEPT
(
    deptno int PRIMARY KEY,
    deptnm VARCHAR(10)
);

create table EMP
(
    empno int,
    empnm VARCHAR(8),
    empadd VARCHAR(10),
    salary number(6),
    date_birth date,
    joindt date,
    deptno int REFERENCES deptno(DEPT)
);


/*
EMP (empno, empnm, empadd, salary, date_birth, joindt, deptno)
DEPT (deptno, deptnm)
Write a PL/SQL block (table above EMP-DEPT table) which takes as input Department name and displays all the employees of this department who has been working since last five years
*/

Declare
	cursor c1 is 
	select empno,ename,sal,job,(sysdate-hiredate)/365 as nYears 
	from emp,dept where emp.deptno=dept.deptno and dept.name='&dept_name';
begin		
	 
	dbms_output.put_line(rpad('-',50,'-'));
	dbms_output.put_line(upper(
			rpad('empno',10)|| rpad('ename',10)||
			rpad('job',10)|| rpad('sal',10)|| rpad('nYears',10)
		));
	dbms_output.put_line(rpad('-',50,'-'));
	for r in c1 loop
		if r.nYears>5 then
			dbms_output.put_line(upper(
				rpad(r.empno,10)|| rpad(r.ename,10)||
				rpad(r.job,10)|| rpad(r.sal,10)|| rpad(r.nYears,10)
			)); 
		end if;			 
	end loop;
	dbms_output.put_line(rpad('-',50,'-'));
end;
/