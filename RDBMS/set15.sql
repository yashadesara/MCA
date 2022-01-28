create table DEPTT
(
    deptno int PRIMARY KEY,
    deptnm VARCHAR(10)
);

insert into DEPTT values(1,'DEP1');
insert into DEPTT values(2,'DEP2');
insert into DEPTT values(3,'DEP3');

create table EEMP
(
    empno int,
    empnm VARCHAR(8),
    empadd VARCHAR(10),
    salary number(6),
    date_birth date,
    joindt date,
    deptno int REFERENCES DEPTT(deptno)
);

insert into EEMP values(1,'ABC','DUBAI',30000,'10-AUG-2000','12-AUG-2021',1);
insert into EEMP values(2,'PQR','US',40000,'12-AUG-2000','14-AUG-2021',2);
insert into EEMP values(3,'XYZ','UK',50000,'14-AUG-2000','16-AUG-2021',3);

/*
EMP (empno, empnm, empadd, salary, date_birth, joindt, deptno)
DEPT (deptno, deptnm)
Write a PL/SQL block (table above EMP-DEPT table) which takes as input Department name and displays all the employees of this department who has been working since last five years
*/

Declare
	cursor c1 is 
	select empno,empnm,salary,date_birth,(sysdate-joindt)/365 as nYears 
	from EEMP,DEPTT where EEMP.deptno=DEPTT.deptno and DEPTT.deptnm='&dept_name';
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
				rpad(r.empno,10)|| rpad(r.empnm,10)||
				rpad(r.date_birth,10)|| rpad(r.salary,10)|| rpad(r.nYears,10)
			)); 
		end if;			 
	end loop;
	dbms_output.put_line(rpad('-',50,'-'));
end;
/